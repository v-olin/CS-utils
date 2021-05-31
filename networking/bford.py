import sys

class Graph:
    def __init__(self, nodes, links):
        self.nodes = nodes
        self.links = links
        self.final = True

def evaluate(graph):
    print("u suck 8==D ;D")
    for i in range(0, len(graph.nodes)):
        

def readLinks(nodes):
    weightmap = [[]]
    for i in range(0, len(nodes)):
        weightStr = input("Enter weights for '{}' space-separated (-1 for infinity): ".format(nodes[i]))
        weightInts = [int(j) for j in weightStr.split(' ')]
        weightmap.append(weightInts)
    return weightmap

def nodesSeparated(str):
    print("\"{}\"".format(str))
    return str.split(' ')

def askForNodes():
    arg = input("Enter nodes space-separated (u v w x y z): ")
    nodes = nodesSeparated(arg)
    weights = readLinks(nodes)
    graph = Graph(nodes, weights)
    return graph

def main():
    graph = askForNodes()

if __name__ == "__main__":
    main()