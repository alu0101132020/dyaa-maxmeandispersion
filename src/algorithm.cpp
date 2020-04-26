#include "../include/algorithm.hpp"

MaxMeanAlgorithm::MaxMeanAlgorithm(Graph workingGraph) : _workingGraph(workingGraph) {}

Graph MaxMeanAlgorithm::getGraph() {
  return _workingGraph;
}

void MaxMeanAlgorithm::setGraph(Graph workingGraph) {
  _workingGraph = workingGraph;
}
