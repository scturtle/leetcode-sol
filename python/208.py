TrieNode = dict

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        p = self.root
        for c in word:
            if c not in p:
                p[c] = {}
            p = p[c]
        p[True] = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        p = self.root
        for c in word:
            if c not in p:
                return False
            p = p[c]
        return True in p

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        p = self.root
        for c in prefix:
            if c not in p:
                return False
            p = p[c]
        return True

# Your Trie object will be instantiated and called as such:
trie = Trie()
trie.insert("somestring")
print(trie.search("key"))
print(trie.search("somestring"))
print(trie.search("somestrin"))
print(trie.startsWith("somestring "))
