import requests
from lxml import etree
import lxml.html
import csv

api = requests.get("https://en.wikipedia.org/wiki/Schrödinger_equation")
tree = lxml.html.document_fromstring(api.text)
string = tree.xpath('//*[@id="mw-content-text"]/div[1]/p[2]/text()')
print(string)