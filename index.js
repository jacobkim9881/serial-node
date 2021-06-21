const SerialPort = require('serialport')
SerialPort.list().then(ports => {
  ports.forEach(function(onePort) {
      console.log(onePort.path)
  })
})

const port1 = new SerialPort('COM3', {
  baudRate: 9600
}).setEncoding('utf-8');

SerialPort.parsers = {
  ByteLength: require('@serialport/parser-byte-length'),
  CCTalk: require('@serialport/parser-cctalk'),
  Delimiter: require('@serialport/parser-delimiter'),
  Readline: require('@serialport/parser-readline'),
  Ready: require('@serialport/parser-ready'),
  Regex: require('@serialport/parser-regex'),
}

const Readline = SerialPort.parsers.Readline

const parser = new Readline()

port1.on('open', () => {

port1.on('data', (data)=> {
  let send = parseInt(data) + 1
  if (parseInt(data) !== 0) {
    //port1.write(send.toString())
    console.log(data)
  }
  
})

})

const express = require('express')
const cors = require('cors');
const exapp = express()
const port = 3100

exapp.use(cors())

exapp.get('/test', async (req, res) => {
  
    
port1.write('i123456');

res.end();
})


exapp.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
  })
  