#include <vector>
#include <fstream>
#include "node.hpp"
#include <string>
#include <iostream>
#pragma once

class Graph
{
private:
  // Vector de nodos que conforma el grafo.
  std::vector<Node> _nodes;
  int _numberOfNodes;
public:
  // Constructor mediante un vector de nodos
  Graph(std::vector<Node> nodes);
  // Constructor a partir de un fichero de entrada
  Graph(std::string inputFileName);
  // Retorna el número de nodos
  int getNumberOfNodes();
  // Retorna el vector de nodos
  const std::vector<Node>& getNodes() const;
  // Retorna el vector de aristas completo.
  const Node& getNode(int nodeIndex) const;
  // Cambia el vector de nodos.
  void setNodes(std::vector<Node> nodes);
  // Cambia el coste de una arista concreta.
  void setNode(int nodeIndex, Node node);
  // Imprime el grafo.
  void printGraph();
};