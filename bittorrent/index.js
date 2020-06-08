const fs = require('fs');
const bencode = require('bencode');
const crypto = require('crypto');

const torrent = fs.readFileSync('kafka.torrent');

/**
 * Get torrent info hash.
 * @param  {Buffer} torrent
 * @return String   info hash
*/
function getInfoHash(torrent) {
	if (Buffer.isBuffer(torrent)) {
		torrent = bencode.decode(torrent);
	}

	// sanity check
	ensure(torrent.info, 'info')
	
	let shasum = crypto.createHash('sha1')
	shasum.update(bencode.encode(torrent.info))
	return shasum.digest('hex')
}

function ensure(bool, fieldName) {
	if (!bool) throw new Error(`Torrent is missing require field: ${fieldName}`)
}

console.log(getInfoHash(torrent))

// let shasum = crypto.createHash('sha1');
// shasum.update(torrent.info);
// shasum.digest('hex')
// 
// console.log(shasum);
// 
// Object.keys(torrent).forEach(key => {
// 	console.log(`${key}: ${torrent[key]}`);
// });
