class node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''
        

def printNodes(node, val=''):
    newVal = val + str(node.huff)
    if(node.left):
        printNodes(node.left, newVal)
    if(node.right):
        printNodes(node.right, newVal)
    if(not node.left and not node.right):
        print(f"{node.symbol} -> {newVal}")
    

chars = ['a','b','c','d','e','f','g']
freq = [4,7,12,14,17,43,54]
nodes = []
for i in range(len(chars)):
    nodes.append(node(freq[i], chars[i]))  #imp
    
while len(nodes)>1:
    nodes = sorted(nodes, key=lambda x:x.freq)
    left = nodes[0]
    right = nodes[1]
    left.huff = 0
    right.huff = 1
    newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)
    
printNodes(nodes[0])
    
    
'''
- Huffman coding is a lossless data compression algorithm.

- The most frequent character gets the smallest code 
  and the least frequent character gets the largest code.

Time complexity: O(nlogn)

Applications of Huffman Coding :
# They are used for transmitting fax and text.
# They are used by conventional compression formats like PKZIP, GZIP, etc.
# Multimedia codecs like JPEG, PNG, and MP3 use Huffman encoding(to be more precise the prefix codes).
'''