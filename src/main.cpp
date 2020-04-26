/**
  *  Escuela Superior de Ingeniería y Tecnología
  *  Grado en Ingeniería Informática
  *  Asignatura: Diseño y análisis de algoritmos
  *  Curso: 3º
  *  Práctica 8: Max-mean dispersion problem.
  *  @author: Manuel Andrés Carrera Galafate <alu0101132020@ull.edu.es>
  *  @since: 23/04/2020
  *  @desc: Programa principal.
  *  @references:
  *               Explicación del problema y la solución:
  *               https://drive.google.com/file/d/1btbyAPJNfy-9oQ9as22bmagi6o1XhHGn/view
  * 
  *
  *  @version:
  *              20/04/2020 - Creación (primera versión) del código.
  */

#include <iostream>
#include <stdio.h>
#include <cstring>
#include "solution.hpp"
#include "../include/edge.hpp"
#include "../include/node.hpp"
#include "../include/graph.hpp"
#include "../include/algorithm.hpp"
#include "../include/greedy-constructive.hpp"
#include "../include/greedy.hpp"
#include "../include/grasp.hpp"

int main(int argc, char* argv[]){
  // if (argc == 3) {
  // } else {
  //   std::cout << "Introduzca 2 y solo 2 cadenas como parámetros.\n";

  // }
  // std::vector<Edge> prueba;
  // for (int i = 1; i <= 10; i++) {
  //   Edge nuevoEdge(i, i * 10);
  //   prueba.push_back(nuevoEdge);
  // }
  // Edge myEdge(8, 2.2);
  // std::cout << myEdge.getCost() << "\t" << myEdge.getDestination() << "\n";
  // Node newNode(prueba, 10);
  // std::cout << newNode.getCostOfEdge(3) << "\t" << newNode.getIdentifier() << "\n";
  // std::vector<Edge> pruebita = newNode.getEdges();
  // for (int i = 0; i < pruebita.size(); i++) {
  //   std::cout << pruebita[i].getCost() << "\t" << pruebita[i].getDestination() << "\n";
  // }
  Graph myGraph("max-mean-div-10.txt");
  // myGraph.printGraph();
  GreedyConstructiveAlgorithm myAlg(myGraph);
  Solution sol1 = myAlg.resolve();
  sol1.print();
  GreedyAlgorithm myAlg2(myGraph);
  Solution sol2 = myAlg2.resolve();
  sol2.print();
  GraspAlgorithm myAlg3(myGraph);
  Solution sol3 = myAlg3.resolve();
  sol3.print();
}

