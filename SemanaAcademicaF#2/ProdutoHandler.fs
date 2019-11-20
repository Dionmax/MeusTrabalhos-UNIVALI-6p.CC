module ProdutoHandler

open DBConfig
open ProdutoCreate
open ProdutoDelete
open ProdutoRead
open ProdutoUpdate
open MongoDB.Bson

module Produto =
    let addProduto (nome) (quantidadeEstoque) (unidade) (localEstoque) =
        let produto = {Id = BsonObjectId.Create(ObjectId.GenerateNewId());
                       Nome = nome;
                       QuantidadeEstoque = quantidadeEstoque;
                       Unidade = unidade;
                       LocalEstoque = localEstoque
                       }
        create(produto)

    let deleteProduto nome =
        delete(nome)

    let readProduto nome =
        read nome

    let readAllProduto =
        readAll

    let updateProduto nomeAntigo nomeNovo =
        update <| nomeAntigo <| nomeNovo