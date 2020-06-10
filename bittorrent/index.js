const fs = require('fs');
const bencode = require('bencode');
const crypto = require('crypto');
const url = require('url')
const util = require('./util')
const torrent = bencode.decode(fs.readFileSync('kafka.torrent'));
const http = require('http');
const os = require('os');

console.log('Host byte order: ' + os.endianness())

/**
 * Get torrent info hash.
 * @param  {Object} torrent
 * @return String   info hash
*/
function getInfoHash(torrent, encoding=null) {
	// sanity check
	ensure(torrent.info, 'info')
	
	let shasum = crypto.createHash('sha1')
  shasum.update(bencode.encode(torrent.info))  
  return encoding ? shasum.digest(encoding) : shasum.digest()	
}

function ensure(bool, fieldName) {
	if (!bool) throw new Error(`Torrent is missing require field: ${fieldName}`)
}

function getTorrentSize() {
	const size = torrent.info.files ?
		torrent.info.files.map(file => file.length).reduce((acc, curVal) => acc + curVal) :
		torrent.length
	return size;
}

// console.log(torrent);

const tracker = new URL(torrent.announce.toString('utf8'))
let infoHash = getInfoHash(torrent)
let peerId = util.getPeerId();
const port = 6681;
const left= getTorrentSize();
const downloaded = 0;
const uploaded = 0;
const event = 'started'

console.log(tracker)

console.log('torrent info hash (hex): ' + getInfoHash(torrent, 'hex'));
console.log(`peer id (hex): ${peerId.toString('hex')}`);
console.log(`port: ${port}`);

infoHash = util.urlEncodeBytes(infoHash);
peerId = util.urlEncodeBytes(peerId);

console.log('torrent info hash (urlEncodeBytes): ' + infoHash);
console.log(`peer id (urlEncodeBytes): ${peerId}`);

// tracker.searchParams.append('info_hash', infoHash);
// tracker.searchParams.append('peer_id', peerId);
// tracker.searchParams.append('port', port);
// tracker.searchParams.append('downloaded', downloaded);
// tracker.searchParams.append('left', left);
// tracker.searchParams.append('uploaded', 0);
// tracker.searchParams.append('event', event);

var options = {
  host: 'bt3.t-ru.org',  
  path: `/ann?info_hash=${infoHash}&peer_id=${peerId}&left=${left}&event=${event}&downloaded=${downloaded}&uploaded=${uploaded}&port=${port}`,
  method: 'GET',
  headers: {
    'User-Agent': 'CristianTorrent/0.0.1'
  }
};

http.get(options, function(resp){
  let data = Buffer.alloc(0);
 
  // A chunk of data has been recieved.
  resp.on('data', (chunk) => {
    console.log("received chunk!")
    console.log("data byte total = " + data.length)
    console.log("received chunk byte total = " + chunk.length)
    const byteTotal = chunk.length + data.length;
    data = Buffer.concat([data, chunk], byteTotal)
    console.log("new data byte total = " + data.length)
  });

  // The whole response has been received. Print out the result.
  resp.on('end', () => {      
    
    data = bencode.decode(data)
    
    console.log(data)

    const dataByteTotal = data.length
    const peersByteTotal = data.peers.length
    console.log('received entire response!');
    console.log('data byte total = ' + dataByteTotal);
    console.log('data peers byte total = ' + peersByteTotal);

    let peers = data.peers

    let count = 0

    while (count < peersByteTotal) {
      let ip = []      
      for (let i = 0; i < 4; i++) {
        let part = peers.readUInt8(count)
        ip.push(part)
        count++
      }    
      let port = peers.readUInt16BE(count)
      // let part = peers.readUInt16BE(count).toString(16)      
      count+=2
      console.log('ip: ' + ip.join('.') + `: ${port}`);
    }

    // data = Buffer.from(data);
    // console.log(data)
    // let i = data.indexOf("peers");
    // while(true) {
    //   if (data[i] === ":") break
    //   i++
    // }
    // let peers = data.slice(++i, data.length - 1)
    // peers = Buffer.from(peers)
    // console.log("peers:" + peers)
    // console.log('peers buffer length: ' + peers.length + ' bytes')

    // console.log(peers.readUInt8(0).toString('16')); // prints first byte value in hex
    // console.log(parseInt(peers.readUInt8(0), 10)); // prints first byte value in dec
    

    // let count = 0;
    // while (peers.length - count >= 6) {
    //   let ip = [];
    //   let port = [];
    //   for (let i = 0; i < 4; i++) {        
    //     let part = peers.readUInt8(count)
    //     // let part = peers.readUInt8(count).toString('16')
    //     count++;                
    //     ip.push(part)
    //   }      
    //   let part = peers.readUInt16BE(count)
    //   // let part = peers.readUInt16BE(count).toString(16)
    //   port.push(part)

    //   count+=2
      
    //   console.log('ip: ' + ip.join('.') + `: ${port.join('')}`);
    // }

  });
}).on("error", function(e){
  console.log("Got error: " + e.message);
});
