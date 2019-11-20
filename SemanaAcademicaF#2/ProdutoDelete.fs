module ProdutoDelete

open DBConfig
open MongoDB.Driver

let delete (nome :string) =
    let produtoFilter = Builders<ProdutoData>.Filter.Eq((fun item -> item.Nome), nome)
    collection.DeleteOne(produtoFilter)