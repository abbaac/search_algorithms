class BST:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None

def populate_bst(node,value):
    if(node.value ==value):
        return
    if(node.value > value):
        if(node.left):
            populate_bst(node.left, value)
        else:
            node.left = BST(value)
    if (node.value < value):
        if (node.right):
            populate_bst(node.right, value)
        else:
            node.right = BST(value)

l = [5,4,6,7,1,4]

node = BST(5)

for e in l[1:6]:
    populate_bst(node,e)

#print(node)
# spit out tree values in a pre_order fashion
def pre_order(node):

    if(node ==None):
        return []

    return [node.value] + pre_order(node.left) +  pre_order(node.right)

print(pre_order(node))