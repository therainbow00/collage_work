
const http = require('http')
const port = process.env.PORT || 3090

console.log(port)

const server = http.createServer((req,res) => {
    res.writeHead(200, {'Content-Type': 'text/html'})
    res.end('<h1>Hello, world.</h1>')
})

server.listen(port, () => console.log(`Server listening on port ${port}.`))

