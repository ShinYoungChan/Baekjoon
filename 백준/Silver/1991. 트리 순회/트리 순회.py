import sys


class Node:
    def __init__(self,data):
        self.data = data
        self.left = 0
        self.right = 0


class tree:
    def __init__(self, root):
        self.root = root

    def setLeft(self, node, left):
        node.left = left

    def setRight(self, node, right):
        node.right = right

    def preorder(self, node):
        if node != 0:
            print(node.data, end = "")
            self.preorder(node.left)
            self.preorder(node.right)
    def inorder(self, node):
        if node != 0:
            self.inorder(node.left)
            print(node.data, end="")
            self.inorder(node.right)
    def postorder(self, node):
        if node != 0:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.data, end = "")


N = int(input())
alpha = [Node(chr(65+i)) for i in range(N)]
Tree = tree(alpha[0])
for _ in range(N):
    data, left, right = sys.stdin.readline().split()
    if left != ".":
        Tree.setLeft(alpha[ord(data)-65], alpha[ord(left)-65])
    if right != ".":
        Tree.setRight(alpha[ord(data)-65], alpha[ord(right)-65])
Tree.preorder(Tree.root)
print()
Tree.inorder(Tree.root)
print()
Tree.postorder(Tree.root)