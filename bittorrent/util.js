const crypto = require('crypto')

let id = null

module.exports.getPeerId = () => {
	if (!id) {
		id = crypto.randomBytes(20)
		Buffer.from('-CT0001-').copy(id, 0)
	}
	return id
}

const isUrlSafe = (char) => {
  return /[a-zA-Z0-9\-_~.]+/.test(char)
}

module.exports.urlEncodeBytes = (buf) => {
  let encoded = ''
  for (let i = 0; i < buf.length; i++) {
    const charBuf = Buffer.from('00', 'hex')
    charBuf.writeUInt8(buf[i])
    const char = charBuf.toString()
    // if the character is safe, then just print it, otherwise encode
    if (isUrlSafe(char)) {
      encoded += char
    } else {
      encoded += `%${charBuf.toString('hex').toUpperCase()}`
    }
  }
  return encoded
}

module.exports.urlDecodeBytes = (encoded) => {
  let decoded = Buffer.from('')
  for (let i = 0; i < encoded.length; i++) {
    if (encoded[i] === '%') {
      const charBuf = Buffer.from(`${encoded[i + 1]}${encoded[i + 2]}`, 'hex')
      decoded = Buffer.concat([decoded, charBuf])
      i += 2
    } else {
      const charBuf = Buffer.from(encoded[i])
      decoded = Buffer.concat([decoded, charBuf])
    }
  }
  return decoded
}
