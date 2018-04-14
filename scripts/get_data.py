import requests
import json

r = requests.get("https://omgvamp-hearthstone-v1.p.mashape.com/cards",
        headers={
            "X-Mashape-Key": "BEuUYenmH3mshn88hH1zfqgeNQI2p17h6eUjsnBeKEaeSW1zRn"
            }
        )
with open("data.json", "r+") as f:
    data = r.json()
    card_sets = {k:v for k,v in data.items() if len(v) and k.lower() != "credits"}
    f.write(json.dumps(card_sets, indent=4))
