create table agendamento (
	id serial primary key not null,
	cliente varchar(50),
	inicio timestamp,
	termino timestamp
);

-- Ex 06
create or replace function agendaHorario(_inicio timestamp, _duracao int, _cliente varchar) returns boolean as 
$$
declare
	_horas time := _inicio;
	_terminoHoras time := _horas + to_timestamp(ABS(_duracao)::varchar , 'MI')::time AT TIME ZONE 'BRT';
	_diaSemana int := EXTRACT(DOW FROM _inicio);
	_diaMesAno date := _inicio::timestamp::date;
	_interator record;
begin
	-- Primeira Verificações (Horas e datas)
	if _inicio < now() then
		raise notice 'Impossivel cadastrar no passado.';
		return false;
	elsif _duracao < 30::int then
		raise notice 'Horário minímo da consulta 30 min';
		return false;
	elsif not(_horas >= '08:00:00' and _horas < '12:00:00' or _horas >= '13:30:00' and _horas < '17:30:00') then
		raise notice 'Hora inválida';
		return false;
	elsif _terminoHoras > '12:00:00' and _terminoHoras < '13:30:00' or _terminoHoras > '17:30:00' then
		raise notice 'Horário ultrapassa expediente';
		return false;
	elsif _diaSemana = 0 or _diaSemana = 6 then
		raise notice 'Dia inválido';
		return false;
	end if;
	
	-- Segunda Verificação (Horarios disponiveis)
	for _interator in select * from agendamento where inicio >= _inicio - interval '1 hours' and termino::time <= _terminoHoras + interval '1 hours' loop
		if _inicio >= _interator.inicio and _inicio < _interator.termino or 
		_terminoHoras > _interator.inicio::time and _terminoHoras <= _interator.termino::time and
			_interator.inicio::timestamp::date = _diaMesAno	then
			raise notice 'Horario indisponivel para consulta.';
			return false;
		end if;
	end loop;
	
	insert into agendamento(cliente, inicio, termino) values (_cliente, _inicio, _inicio + _duracao::varchar::interval * 60);	
	return true;

end;
$$
language plpgsql;
-- Ex 07
create or replace function proximoHorarioVago(_duracao int) returns timestamp as 
$$
declare
--	_now timestamp := '2019-09-01 13:30:00'; -- substituir depois por now()

	_horaInicial timestamp := (select inicio from agendamento where inicio >= now() order by inicio limit 1);
	_horaFinal timestamp := now();
	_duracaoConsultaTime time := ABS( _duracao)::varchar::interval * 60;
	_interator record;
begin
	if _duracao < 30 then
		raise exception 'Horário da consulta não deve ser menor que 30 min';
	elsif  (now() + _duracaoConsultaTime)::time < 
	(select inicio from agendamento where inicio::date >= now()::date order by inicio limit 1)::time then
		
		if now()::time < '08:00:00'::time then 
			if (EXTRACT(ISODOW FROM now())) = 6 then
				return ('08:00:00'::time + (now()::Date) + '2 day');
			elsif (EXTRACT(ISODOW FROM now())) = 7 then
				return ('08:00:00'::time + (now()::Date) + '1 day');
			else 
				return ('08:00:00'::time + now()::Date);
			end if;
		end if;
			
		return now();
	end if;
	
	for _interator in select * from agendamento where inicio::date >= now()::date order by inicio loop	
		if  (_horaFinal + _duracaoConsultaTime)::time <= _interator.inicio::time then
			raise notice 'Próximo horario: % ', (_horaFinal);
			return _horaFinal;
		end if;
		_horaFinal := _interator.termino;
	end loop;
	
	return (select termino from agendamento where inicio >= now() order by termino desc limit 1);
end;
$$
language plpgsql;