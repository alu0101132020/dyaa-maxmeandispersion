/**
  *  Escuela Superior de Ingeniería y Tecnología
  *  Grado en Ingeniería Informática
  *  Asignatura: Diseño y análisis de algoritmos
  *  Curso: 3º
  *  Práctica 8: Max-mean dispersion problem.
  *  @author: Manuel Andrés Carrera Galafate <alu0101132020@ull.edu.es>
  *  @since: 23/04/2020
  *  @desc: Clase nodo para la implementación del max-mean problem
  *  @references:
  *               Explicación del problema y la solución:
  *               https://drive.google.com/file/d/1btbyAPJNfy-9oQ9as22bmagi6o1XhHGn/view
  * 
  *
  *  @version:
  *              20/04/2020 - Creación (primera versión) del código.
  */

#include "edge.hpp"
#include <vector>
#pragma once

class Node {
private:
  // Parámetros que definen un nodo, los cuales son el id del nodo y un conjunto
  // de aristas a otros nodos.
  int _identifier;
  std::vector<Edge> _edges;
public:
  // Constructor por defecto.
  Node();
  // Constructor con parámetros.
  Node(std::vector<Edge> edges, int identifier = -1);
  // getters y setters

  // Retorna el id del nodo.
  const int& getIdentifier() const;
  // Retorna el vector de aristas completo.
  const std::vector<Edge>& getEdges() const;
  // getter que devuelve el coste del nodo a el nodo destino pasado por parámetro.
  const double& getCostOfEdge(int edge) const;
  // Cambia el valor del id del nodo.
  void setIdentifier(int identifier);
  // Cambia el vector de aristas completo.
  void setEdges(std::vector<Edge> edges);
  // Cambia el coste de una arista concreta.
  void setCostOnEdge(int edge, int cost);
};