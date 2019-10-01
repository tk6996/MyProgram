from urllib.request import urlopen
from xml.etree import ElementTree

def node_from_url(server_url, site_path):
    with urlopen(server_url + site_path) as conn:
        return TeamCityNode(server_url, ElementTree.parse(conn).getroot())

class TeamCityNode:
    def __init__(self, server_url, xmltree):
        self.server_url = server_url
        self.xmltree = xmltree
    
    def find(self, xpath):
        return TeamCityNode(self.server_url, self.xmltree.find(xpath))
    
    def findall(self, xpath):
        return [TeamCityNode(self.server_url, node) for node in self.xmltree.findall(xpath)]
    
    def follow(self, xpath=None):
        return self.follow_href() if xpath == None else self.find(xpath).follow_href()
    
    def follow_href(self):
        href = self.attribute("href")
        print("Following", href)
        return node_from_url(self.server_url, href)
    
    def attribute(self, name):
        return self.xmltree.attrib.get(name)
    
    def name(self):
        return self.attribute("name")
        
    def number(self):
        return self.attribute("number")
        
    def status(self):
        return self.attribute("status")
    
    def id(self):
        return self.attribute("id")

class TeamCityConnection:
    def __init__(self, server_url):
        self.server_url = server_url
            
    def fetch(self, site_path):
        return node_from_url(self.server_url, "/guestAuth/app/rest/" + site_path)
    
    def get_kotlin_project(self):
        return self.fetch("projects/id:Kotlin")
