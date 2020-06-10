const fs = require('fs');
const bencode = require('bencode');
const crypto = require('crypto');
const url = require('url')
const util = require('./util')
const torrent = bencode.decode(fs.readFileSync('kafka.torrent'));
const http = require('http');

/**
 * Get torrent info hash.
 * @param  {Object} torrent
 * @return String   info hash
*/
function getInfoHash(torrent) {
	// sanity check
	ensure(torrent.info, 'info')
	
	let shasum = crypto.createHash('sha1')
	shasum.update(bencode.encode(torrent.info))
	return shasum.digest()
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

infoHash = util.urlEncodeBytes(infoHash);
peerId = util.urlEncodeBytes(peerId);

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
  let data = '';
 
  // A chunk of data has been recieved.
  resp.on('data', (chunk) => {
    data += chunk;
  });

  // The whole response has been received. Print out the result.
  resp.on('end', () => {
    // console.log(JSON.parse(data).explanation);
    console.log('received entire response! see below:');
    console.log(data);
  });
}).on("error", function(e){
  console.log("Got error: " + e.message);
});
