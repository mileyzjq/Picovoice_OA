import collections

class Book(object):
    def __init__(self, ISBN: str, title: str, author: str, language: str):
        super().__init__()
        self.ISBN = ISBN
        self.title = title
        self.author = author
        self.language = language

    def __str__(self):
        return f"{self.title}, {self.author}, {self.language}"

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        super().__init__()
        self.capacity = capacity


    def get(self, key: str) -> str:
        if key not in self:
            return "Not found in cache"
        self.move_to_end(key)
        return self[key]

    def put(self, key: str, value: Book) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)
    

# Your LRUCache object will be instantiated and called as such:
N = 3
obj = LRUCache(3)
obj.put("978-3-16-148410-0", Book("978-3-16-148410-0", "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "English"))
obj.put("9971-5-0210-0", Book("9971-5-0210-0", "The Restaurant at the End of the Universe", "Tom Smith", "English"))
obj.put("85-359-0277-5", Book("85-359-0277-5", "Life, the Universe and Everything", "Elio Gaspari", "English"))
print(obj.get("978-3-16-148410-0"))
print(obj.get("9971-5-0210-0"))