class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.root = {}

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        p = self.root
        for c in word:
            if c not in p:
                p[c] = {}
            p = p[c]
        p[True] = True

    def search(self, word, root=None):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        p = self.root if root is None else root
        for i, c in enumerate(word):
            if c == '.':
                for pc in p.values():
                    if pc != True and self.search(word[i+1:], pc):
                        return True
                return False
            else:
                if c not in p:
                    return False
                p = p[c]
        return True in p

# Your WordDictionary object will be instantiated and called as such:
wordDictionary = WordDictionary()
wordDictionary.addWord("word")
print(wordDictionary.search("word"))
print(wordDictionary.search("w.rd"))
print(wordDictionary.search("pattern"))
