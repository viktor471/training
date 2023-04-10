import xml.etree.ElementTree as ET

parsed = ET.parse("./vast.xml")
print(type(parsed))
mediafile = parsed.find(".//MediaFiles/MediaFile")
print(mediafile.set("api", "hello"))

print(mediafile)

ET.dump(mediafile)
parsed.write("./vast_.xml")

