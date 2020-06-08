const fs = require('fs');
const bencode = require('bencode');

// const torrent = bencode.decode(fs.readFileSync('kafka.torrent')));
const torrent = bencode.decode(fs.readFileSync('puppy.torrent'));

console.log(torrent);

Object.keys(torrent).forEach(key => {
	console.log(`${key}: ${torrent[key]}`);
});
