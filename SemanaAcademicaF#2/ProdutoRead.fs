module ProdutoRead

open DBConfig
open MongoDB.Driver

let read nome =
    collection.Find(fun tipo -> tipo.Nome = nome).ToEnumerable()

let readAll = 
    collection.Find(Builders.Filter.Empty).ToEnumerable()