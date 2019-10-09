package GalsClass;

import static automatoscompiladorgals.AutomatosCompiladorGals.*;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Semantico implements Constants {

    public void executeAction(int action, Token token) throws SemanticError {
        Integer a, b;
        switch (action) {
            case 1: //push num
                pilha.push(Integer.parseInt(token.getLexeme(), 2));
                break;
            case 2: //+
                b = pilha.pop();
                a = pilha.pop();
                pilha.push(Integer.parseInt(Integer.toBinaryString(a + b)));
                break;
            case 3: //*
                b = pilha.pop();
                a = pilha.pop();
                pilha.push(Integer.parseInt(Integer.toBinaryString(a * b)));
                break;
            case 4: //push var
                pilha.push(vars.get(token.getLexeme()));
                break;
            case 5://-
                b = pilha.pop();
                a = pilha.pop();
                pilha.push(Integer.parseInt(Integer.toBinaryString(a - b)));
                break;
            case 6: //÷
                b = pilha.pop();
                a = pilha.pop();
                pilha.push(Integer.parseInt(Integer.toBinaryString(a / b)));
                break;
            case 7: //print
                System.out.print("Último elemento da pilha: " + pilha.peek() + "\n");
                break;
            case 8: //^
                b = pilha.pop();
                a = pilha.pop();
                Double c = Math.pow(a, b);
                pilha.push(Integer.parseInt(Integer.toBinaryString((int) c.intValue())));

                break;
            case 10:
                vars.put(ultimaVariavel, pilha.pop());
                break;
            case 11:
                ultimaVariavel = token.getLexeme();
                break;
            default:
                break;
        }
    }
}
