from lxml import etree, html

filename = "./some.html"

with open(filename) as file:
    document = html.fromstring(file.read())
    target_file = f'{filename.removesuffix(".html")}_.html'

    with open(target_file, "w") as file_:
        file_.write(etree.tostring(document, encoding='unicode', pretty_print=True))