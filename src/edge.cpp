#include "../include/edge.hpp"

Edge::Edge() : _destination(0), _cost(0) {}
Edge::Edge(int destination, double cost): _destination(destination),
_cost(cost) {}

const int& Edge::getDestination() const {
  return _destination;
}

const double& Edge::getCost() const {
  return _cost;
}

void Edge::setDestination(int destination) {
  _destination = destination;
}

void Edge::setCost(double cost) {
  _cost = cost;
}