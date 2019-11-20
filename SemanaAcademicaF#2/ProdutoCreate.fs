module ProdutoCreate

open DBConfig

let create (produto: ProdutoData) =
    collection.InsertOne(produto)