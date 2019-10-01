const express = require('express')
const port = 8000

var app = express()

app.get('/', (req, res) => {
    return res.send('<h1>Hello Node.js</h1>')
})

app.listen(port, () => {
    console.log('Magic has been casted at PORT ' + port)
})