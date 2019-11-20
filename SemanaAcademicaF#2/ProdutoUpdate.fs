module ProdutoUpdate

open DBConfig
open MongoDB.Driver

let update (nomeAntigo :string) (nomeNovo :string) =
    let filter =
        Builders<ProdutoData>.Filter.Eq((fun tipo -> tipo.Nome), nomeAntigo)

    let updateEncontrado =
        Builders<ProdutoData>.Update.Set((fun tipo -> tipo.Nome), nomeNovo)

    collection.UpdateOne(filter, updateEncontrado)