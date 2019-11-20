// Learn more about F# at http://fsharp.org

open System
open DBConfig
open ProdutoHandler

[<EntryPoint>]
let main argv =

    //Produto.addProduto <| "Garfo" <| 10 <| "Unidade" <| "Estoque Loja"
    //Produto.addProduto <| "Colher" <| 12 <| "Unidade" <| "Estoque Loja"

    //Produto.deleteProduto <| "Garfo"
    //Produto.deleteProduto <| "Colher"

   
    //printfn "%A" <| Produto.readAllProduto

    //Produto.updateProduto <| "Colher" <| "Faca"

    printfn "%A" <| Produto.readProduto "Faca"

    0
