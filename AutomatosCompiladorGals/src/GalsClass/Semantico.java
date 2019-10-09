package GalsClass;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Semantico implements Constants {
    public static Stack<Integer> BinStack = new Stack<>();
    public static Map<String, Integer> Vars = new HashMap<>();
    public static String LastVar;

    public void executeAction(int action, Token token) throws SemanticError {
        Integer VarA, VarB;
        switch (action) {
            case 1: //push num
                BinStack.push(Integer.parseInt(token.getLexeme(), 2));
                break;
            case 2: //+
                VarB = BinStack.pop();
                VarA = BinStack.pop();
                BinStack.push(Integer.parseInt(Integer.toBinaryString(VarA + VarB)));
                break;
            case 3: //*
                VarB = BinStack.pop();
                VarA = BinStack.pop();
                BinStack.push(Integer.parseInt(Integer.toBinaryString(VarA * VarB)));
                break;
            case 4: //push var
                BinStack.push(Vars.get(token.getLexeme()));
                break;
            case 5://-
                VarB = BinStack.pop();
                VarA = BinStack.pop();
                BinStack.push(Integer.parseInt(Integer.toBinaryString(VarA - VarB)));
                break;
            case 6: //÷
                VarB = BinStack.pop();
                VarA = BinStack.pop();
                BinStack.push(Integer.parseInt(Integer.toBinaryString(VarA / VarB)));
                break;
            case 7: //print
                System.out.print("Último elemento da pilha: " + BinStack.peek() + "\n");
                break;
            case 8: //^
                VarB = BinStack.pop();
                VarA = BinStack.pop();
                Double c = Math.pow(VarA, VarB);
                BinStack.push(Integer.parseInt(Integer.toBinaryString((int) c.intValue())));
                break;
            case 10:
                Vars.put(LastVar, BinStack.pop());
                break;
            case 11:
                LastVar = token.getLexeme();
                break;
            default:
                break;
        }
    }
}
