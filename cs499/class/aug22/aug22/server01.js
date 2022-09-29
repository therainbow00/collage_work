
const http = require('http')
const port = process.env.PORT || 3090

console.log(port)

const server = http.createServer((req,res) => {
    res.writeHead(200, {'Content-Type': 'text/plain'})
    res.end('Hello, world.')
})

server.listen(port, () => console.log(`Server listening on port ${port}.`))

