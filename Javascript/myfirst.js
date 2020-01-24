const http = require('http');
const fs = require('fs');
var string = fs.readFileSync('Read.txt');

http.createServer(function(req,res){
    res.writeHead(200,{"Context-Type" : "text/html"});
    res.end(string);
}).listen(8080,'127.0.0.1');