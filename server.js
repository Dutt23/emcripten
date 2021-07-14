const express = require('express')
const app = express()

//Server static files from dir
app.use(express.static('public', {
  setHeaders: (res, path, stat) =>{
    if(path.endsWith('wasm')){
      res.set('Content-Type', 'application/wasm')
    }
  }
}))

app.listen(2222, () => console.log(`Server running on 2222!`))
