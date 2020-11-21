// obj = {
//   "foo1": "test",
//   "abc": "sdfg",
//   "bar": "rab",
//   "PayLoad": {
//     "NBHdr": {
//       "lob": "asd",
//       "poi": "zxc",
//       "dudu": {
//         "foobar": "poipoi",
//         "pooi": {
//           "asd": "xcv",
//           "yellow": [
//             {
//               "scoop": "doo"
//             },
//             {
//               "scoopfoop": "yuoo"
//             }
//           ]
//         }
//       }
//     },
//     "pooi": {
//       "asd": "xcv",
//       "yellow": [
//         {
//           "scoop": "doo"
//         },
//         {
//           "scoopfoop": "yuoo"
//         }
//       ]
//     },
//     "googoo": "yooooooyo"
//   }
// }

// treeData = {
//   "name": "root",
//   "children": [
//     {
//       "name": "foo",
//       "children": [
//         {
//           "name": "doodoo"
//         },
//         {
//           "name": "booboo"
//         }
//       ]
//     },
//     {
//       "name": "bar"
//     }
//   ]
// }

function generate(result, data, start){
  if (start) {
    for (key in data) {
      if (Array.isArray(data[key]) || (typeof data[key] === 'object' && data[key] != null)) {
        result = {
          "name": key,
          children: []
        }
        return generate(result, data[key], false)
      }
    }
  } else {
    let primitive = {}
    let complex = {}
    for (key in data) {
      if (typeof data[key] === 'object' && data[key] != null) {
        complex[key] = data[key] // may not need to save data, use list instead
      } else {
        primitive[key] = data[key]
      }
    }
    let i = 0
    for (key in primitive) {
      result.children.push({
        "name": key
      })
      i += 1
    }
    for (key in complex) {
      result.children.push({
        "name": key,
        "children": []
      })
      generate(result.children[i], data[key], false)
      i += 1
    }
  }
  return result;
}

console.log("start")

data = generate(null, obj, true)

console.log(JSON.stringify(data))

// 1. get root level elements
// 2. get all elements whose value is an array or an object