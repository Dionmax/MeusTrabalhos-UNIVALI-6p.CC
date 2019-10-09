/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automatoscompiladorgals;

import GalsClass.LexicalError;
import GalsClass.Lexico;
import GalsClass.SemanticError;
import GalsClass.Semantico;
import GalsClass.Sintatico;
import GalsClass.SyntaticError;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
//import java.io.StringReader;

/**
 *
 * @author Dionmax
 */
public class AutomatosCompiladorGals {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Lexico lex = new Lexico("A = 1010; imprimir(A); B = A * 10; imprimir(B);");

            Sintatico sin = new Sintatico();
            Semantico sem = new Semantico();
            sin.parse(lex, sem);

        } catch (LexicalError | SyntaticError | SemanticError ex) {
            System.out.print(ex);
        }
    }

}
