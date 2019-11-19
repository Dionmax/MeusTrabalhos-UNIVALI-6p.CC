// Learn more about F# at http://fsharp.org

open System

type Pessoa = {Nome :string; Idade :int}

[<EntryPoint>]
let main argv =
    // let nome = "Dion"

    // printfn "%s" <| nome
    // nome |> printfn "%s"

    let imprimirNome nome =
        nome |> printfn "%A"

    // nome |> imprimirNome

    let typeDion = {Nome = "Dion"; Idade= 21}

    // imprimirNome typeDion
        
    // let forTeste =
    //     // for i in [0.. 10] do
    //     //    printf "%d"i
    
    //     let sequencial = seq{for i in 0..10 do i}
    //     printfn "%A" sequencial
    

    // let lista = [0;1;2;3]

    // let rec forTesteRec posicao =
    //     //let array = [|0;1;2;3|]

    //     if posicao = lista.Length-1 then
    //         1
    //     else
    //         printfn "%d" lista.[posicao]
    //         forTesteRec <| posicao + 1

    // forTesteRec 0

    let testeMach numero =
        match numero with
        | 1 -> printf "%s" "Numero 1"
        | 2 -> printf "%s" "Numero 2"
        | _ -> printf "%s" "Nenhum"

    //testeMach 1

    let quadrado valor =
        valor * valor

    let multiplicaElementos =
        let lista = [0;1;2;3;4;5]

        let quadrado = lista|> List.map(fun item -> quadrado <| item)
                            |> List.filter(fun itemMultiplicado -> itemMultiplicado % 2 = 0)
                            //|> List.filter(fun itemMultiplicado -> filterByOdd )

        //let quadrado2 = lista |> List.map(fun Index item -> item)
                              //|> List. (fun item )
        printf "%A" quadrado

    multiplicaElementos
        
    //https://github.com/Bmlla/AulaFSharp

    0 // return an integer exit code