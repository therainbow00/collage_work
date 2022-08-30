const http = require('http')
const port = process.env.PORT || 49912

console.log(port)

const server = http.createServer((req, res) => {
    res.writeHead(200, {'Content-Type': 'text/plain'})
    res.end('<h1>Hello, World.</h1>')
})

server.listen(port, () => console.log(`Server listening on port ${port}.`))
