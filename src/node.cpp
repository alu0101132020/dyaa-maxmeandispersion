#include "../include/node.hpp"

Node::Node() : _identifier(0), _edges(0) {}

Node::Node(std::vector<Edge> edges, int identifier) : _identifier(identifier),
_edges(edges) {}

const int& Node::getIdentifier() const {
  return _identifier;
}

const std::vector<Edge>& Node::getEdges() const {
  return _edges;
}

const double& Node::getCostOfEdge(int edge) const {
  return _edges[edge].getCost();
}

void Node::setIdentifier(int identifier) {
if (identifier >= 0) {
  _identifier = identifier;
  } else {
    throw "Error at setting an identifier";
  }
}

void Node::setEdges(std::vector<Edge> edges) {
  _edges = edges;
}

void Node::setCostOnEdge(int edge, int cost) {
  return _edges[edge].setCost(cost);
}