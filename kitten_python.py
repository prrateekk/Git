import requests
kitten = requests.get('http://placekitten.com')
v = kitten.text[559:1050]
print(v)
