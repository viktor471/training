import xml.etree.ElementTree as ElementTree
import xml.dom.minidom

with open("vast.xml") as file:
    VAST = file.read()


class Vast:
    """Планируется как класс содержащий функции для работы c VAST"""

    @staticmethod
    def get_vast_with_creative_id(creative_id: int | str, vast_xml_string: str = None) -> str:
        vast_xml_string_ = vast_xml_string if vast_xml_string else VAST

        parsed = ElementTree.fromstring(vast_xml_string_)
        tag = parsed.find("Ad/InLine/Creatives/Creative")
        tag.set("id", str(creative_id))

        return ElementTree.tostring(parsed).decode("utf-8")

    @staticmethod
    def get_vast_with_creative_ad_id(creative_ad_id: int | str, vast_xml_string: str = None) -> str:
        vast_xml_string_ = vast_xml_string if vast_xml_string else VAST

        parsed = ElementTree.fromstring(vast_xml_string_)
        tag = parsed.find("Ad/InLine/Creatives/Creative")
        tag.set("AdID", str(creative_ad_id))

        return ElementTree.tostring(parsed).decode("utf-8")

    @staticmethod
    def get_vast_with_ad_id(ad_id: int | str, vast_xml_string: str = None) -> str:
        vast_xml_string_ = vast_xml_string if vast_xml_string else VAST

        parsed = ElementTree.fromstring(vast_xml_string_)
        tag = parsed.find("Ad")
        tag.set("id", str(ad_id))

        return ElementTree.tostring(parsed).decode("utf-8")

    @staticmethod
    def get_prettified_vast(vast: str) -> str:
        return xml.dom.minidom.parseString(vast).toprettyxml()


# vast = Vast.get_vast_with_creative_id(44)
# vast = Vast.get_vast_with_creative_ad_id(44)
vast = Vast.get_vast_with_ad_id(44)
with open("output", "w") as file:
    file.write(Vast.get_prettified_vast(vast))