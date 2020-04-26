#include "../include/graph.hpp"

Graph::Graph(std::vector<Node> nodes) : _nodes(nodes), _numberOfNodes(nodes.size()) {}

Graph::Graph(std::string inputFileName) {
  std::ifstream inputFile;
  inputFile.open(inputFileName);
  if (!inputFile) {
    std::cout << "Unable to open file\n";
    exit(1); // terminate with error
  } else {
    // Obtenemos el número de nodos e inicializamos el grafo sin aristas.
    inputFile >> _numberOfNodes;
    for (int currentNodeIndex = 0; currentNodeIndex < _numberOfNodes; currentNodeIndex++) {
      std::vector<Edge> emptyEdges;
      _nodes.push_back(Node(emptyEdges, currentNodeIndex));
    }
    // Recorremos el fichero. Cada línea del fichero indica la distancia desde el nodo actual
    // al nodo de índice índice del primer nodo + número de línea desplazado desde el primero.
    // Es decir, para 3 nodos, la primera línea es la distancia del nodo 1 al 2, la segunda del
    // 1 al 3, y la tercera del 2 al 3. (Esto es así porque la distancia de un nodo al otro es
    // la misma que del segundo al primero).
    for (int firstNodeOfEdge = 0; firstNodeOfEdge < _numberOfNodes; firstNodeOfEdge++) {
      double costFromEdge;
      for (int secondNodeOfEdge = firstNodeOfEdge; secondNodeOfEdge < _numberOfNodes; secondNodeOfEdge++) {
        std::vector<Edge> copyOfNodeOneEdges = _nodes[firstNodeOfEdge].getEdges();
        if (firstNodeOfEdge == secondNodeOfEdge) {
          copyOfNodeOneEdges.push_back(Edge(firstNodeOfEdge, 0));
          _nodes[firstNodeOfEdge].setEdges(copyOfNodeOneEdges);
        } else {
          inputFile >> costFromEdge;
          copyOfNodeOneEdges.push_back(Edge(secondNodeOfEdge, costFromEdge));
          _nodes[firstNodeOfEdge].setEdges(copyOfNodeOneEdges);
          std::vector<Edge> copyOfNodeTwoEdges = _nodes[secondNodeOfEdge].getEdges();
          copyOfNodeTwoEdges.push_back(Edge(firstNodeOfEdge, costFromEdge));
          _nodes[secondNodeOfEdge].setEdges(copyOfNodeTwoEdges);
        }
      }
    }
  }  
  inputFile.close();
}

int Graph::getNumberOfNodes() {
  return _numberOfNodes;
}

const std::vector<Node>& Graph::getNodes() const {
  return _nodes;
}

const Node& Graph::getNode(int nodeIndex) const {
  return _nodes[nodeIndex];
}

void Graph::setNodes(std::vector<Node> nodes) {
  _nodes = nodes;
}

void Graph::setNode(int nodeIndex, Node node) {
  _nodes[nodeIndex] = node;
}

void Graph::printGraph() {
  for (int currentNode = 0; currentNode < _nodes.size(); currentNode++) {
    for (int currentEdge = 0; currentEdge < _nodes[currentNode].getEdges().size(); currentEdge++) {
      std::cout << _nodes[currentNode].getCostOfEdge(currentEdge) << "\t";
    }
    std::cout << "\n";
  }
}