#include "../include/grasp.hpp"

GraspAlgorithm::GraspAlgorithm(Graph workingGraph) : 
  MaxMeanAlgorithm(workingGraph) {}

Solution GraspAlgorithm::resolve() {
  // Obtenemos todas las parejas de nodos que tienen distancia positiva entre sí.
  std::vector<std::pair<double, std::pair<int, int>>> posibleInitialSolution = preProcess();
  // Escogemos aleatoriamente una de estas parejas.
  srand (time(NULL));
  std::pair<double, std::pair<int, int>> initialSolution = posibleInitialSolution[std::rand() % posibleInitialSolution.size()];
  std::vector<int> solutionArray;
  double currentDistance = initialSolution.first;
  // Incluimos los dos nodos iniciales de la arista en la solución.
  solutionArray.push_back(initialSolution.second.first);
  solutionArray.push_back(initialSolution.second.second);

  std::pair<double, std::vector<int>> solution = construct(solutionArray, currentDistance);
  return Solution(solution.first, solution.second);
}

std::vector<std::pair<double, std::pair<int, int>>> GraspAlgorithm::preProcess() {
  Graph copyOfGraph = getGraph();
  int indexOfFirstNodeOfSolution;
  int indexOfSecondNodeOfSolution;
  std::vector<std::pair<double, std::pair<int, int>>> posibleInitialSolutions;
  for (int currentNodeOfGraph = 0; currentNodeOfGraph < copyOfGraph.getNumberOfNodes(); currentNodeOfGraph++) {
    for (int currentEdgeOfNode = 0; currentEdgeOfNode < copyOfGraph.getNode(currentNodeOfGraph).getEdges().size(); currentEdgeOfNode++) {
      // Si la pareja de nodos tiene un valor positivo lo incluimos como posible solución inicial
      if (0 < copyOfGraph.getNode(currentNodeOfGraph).getCostOfEdge(currentEdgeOfNode)) {
        double currentSolution = copyOfGraph.getNode(currentNodeOfGraph).getCostOfEdge(currentEdgeOfNode);
        indexOfFirstNodeOfSolution = currentNodeOfGraph;
        indexOfSecondNodeOfSolution = copyOfGraph.getNode(currentNodeOfGraph).getEdges()[currentEdgeOfNode].getDestination();
        posibleInitialSolutions.push_back(std::pair<double, std::pair<int, int>> (currentSolution, std::pair<int, int> (indexOfFirstNodeOfSolution, indexOfSecondNodeOfSolution)));
      }
    }
  }
  return posibleInitialSolutions;
}

std::pair<double, std::vector<int>> GraspAlgorithm::construct(std::vector<int> solutionArray, double currentDistance) {
  int numberOfElementsOnSolution = 0;
  // Mientras sigamos incluyendo elementos en las iteraciones seguimos ejecutando el código.
  do {
    // Obtenemos el número de elementos incluidos en la solución y su media.
    numberOfElementsOnSolution = solutionArray.size();
    double md = currentDistance / numberOfElementsOnSolution;
    // Array de elementos que cumplen la distancia de la nueva solución.
    std::vector<int> costToNodesOutOfSolution(getGraph().getNumberOfNodes(), 0);

    // Para cada elemento de la solución actual recorremos sus aristas.
    for (int currentNodeOfCurrentSolution = 0; currentNodeOfCurrentSolution < solutionArray.size(); currentNodeOfCurrentSolution++) {
      std::vector<Edge> edgesToCheck = getGraph().getNode(solutionArray[currentNodeOfCurrentSolution]).getEdges();
      for (int currentEdge = 0; currentEdge < edgesToCheck.size(); currentEdge++) {
        // Comprobamos que el elemento al que va la arista no esté ya en la solución
        if ((std::find(solutionArray.begin(), solutionArray.end(), edgesToCheck[currentEdge].getDestination()) == solutionArray.end())) {
          costToNodesOutOfSolution[edgesToCheck[currentEdge].getDestination()] += edgesToCheck[currentEdge].getCost();
        }
      }
    }
    double maxEdge = -500;
    std::vector<int> indexOfNewNodes;
    for (int currentNodeToCheck = 0; currentNodeToCheck < costToNodesOutOfSolution.size(); currentNodeToCheck++) {
        // Comprobamos si hay una solución mejor que la actual. Si la hay
        // reseteamos el array de soluciones.
      if (maxEdge < costToNodesOutOfSolution[currentNodeToCheck]) {
        indexOfNewNodes.clear();
        maxEdge = costToNodesOutOfSolution[currentNodeToCheck];
      }
      // Si el nuevo elemento cumple la distancia se añade al conjunto
      // de elementos candidatos para añadirse a la solución.
      if (maxEdge == costToNodesOutOfSolution[currentNodeToCheck]) {
        indexOfNewNodes.push_back(currentNodeToCheck);
      }
    }
  // Una vez hemos obtenido la nueva distancia máxima, comprobamos si esta al
  // añadirse mejoraría la solución.
    if (((maxEdge + currentDistance) / (solutionArray.size() + 1)) > md) {
      currentDistance = maxEdge + currentDistance;
      solutionArray.push_back(indexOfNewNodes[std::rand() % indexOfNewNodes.size()]);
    }
  } while (numberOfElementsOnSolution != solutionArray.size());
  return std::pair<double, std::vector<int>> (currentDistance, solutionArray);
}