import json
import json_flatten

def json_diff(original, new):
  print("[ORIGINAL JSON]: ")
  print(original)
  print("[ORIGINAL JSON] Flattening...")
  original = json_flatten.flatten(json.loads(original))
  print("[ORIGINAL JSON] Convert keys to lowercase...")
  original = {k.lower(): v for k, v in original.items()}
  print("[ORIGINAL JSON]: ")
  print(original)

  print("[NEW JSON]:")
  print(new)
  print("[NEW JSON] Flattening...")
  new = json_flatten.flatten(json.loads(new))
  print("[NEW JSON] Convert keys to lowercase...")
  new = {k.lower(): v for k, v in new.items() if v != ""}
  print("[NEW JSON]:")
  print(new)


  for k in original.keys():
    if k in new:
      del new[k]

  return new

with open('original.json', 'r') as reader:
  original = reader.read()

with open('new.json', 'r') as reader:
  new = reader.read()

diff = json_diff(original, new)

print("Diff: ")
print(diff)