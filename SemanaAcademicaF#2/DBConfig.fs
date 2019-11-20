module DBConfig
open MongoDB.Bson
open MongoDB.Driver


let connectionString = "mongodb://admin:12345@cluster0-shard-00-00-bmvfp.gcp.mongodb.net:27017,cluster0-shard-00-01-bmvfp.gcp.mongodb.net:27017,cluster0-shard-00-02-bmvfp.gcp.mongodb.net:27017/test?ssl=true&replicaSet=Cluster0-shard-0&authSource=admin&retryWrites=true&w=majority"

let dbname = "CadastroProduto"

let collectionName = "Produto"

type ProdutoData = {Id: BsonObjectId;
                    Nome: string; 
                    QuantidadeEstoque: int; 
                    Unidade: string; 
                    LocalEstoque: string }

let client = MongoClient(connectionString)
let db =  client.GetDatabase(dbname)
let collection =  db.GetCollection<ProdutoData>(collectionName)