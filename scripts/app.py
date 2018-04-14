import requests
import json

GET_ALL_DATA = False

if GET_ALL_DATA:
    r = requests.get("https://omgvamp-hearthstone-v1.p.mashape.com/cards",
      headers={
        "X-Mashape-Key": "BEuUYenmH3mshn88hH1zfqgeNQI2p17h6eUjsnBeKEaeSW1zRn"
      }
    )
    with open("data.json", "w") as f:
        f.write(json.dumps(r.json(), indent=4))
else:
    with open("data.json", "r+") as f:
        data = json.load(f)
        for k in data:
            print(k)
        print('-'*60)
        card_sets = {k:v for k,v in data.items() if len(v) and k.lower() != "credits"}
        print(type(card_sets))
        for k in card_sets:
            print(k)
        f.write(json.dumps(card_sets, indent=4))

#with open("data.json", "w") as f:
#    f.write(json.dumps(r.json(), indent=4))
