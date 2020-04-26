/**
  *  Escuela Superior de Ingeniería y Tecnología
  *  Grado en Ingeniería Informática
  *  Asignatura: Diseño y análisis de algoritmos
  *  Curso: 3º
  *  Práctica 8: Max-mean dispersion problem.
  *  @author: Manuel Andrés Carrera Galafate <alu0101132020@ull.edu.es>
  *  @since: 23/04/2020
  *  @desc: Clase arista para la implementación del max-mean problem
  *  @references:
  *               Explicación del problema y la solución:
  *               https://drive.google.com/file/d/1btbyAPJNfy-9oQ9as22bmagi6o1XhHGn/view
  * 
  *
  *  @version:
  *              20/04/2020 - Creación (primera versión) del código.
  */
#pragma once

class Edge {
private:
  // Atributos que definen la arista desde un nodo dado mediante el destino
  // y el coste a este.
  int _destination;
  double _cost;
public:
  // Constructor por defecto
  Edge();
  // Constructor que recibe el destino y el coste asociado a este.
  Edge(int destination, double cost = 0);
  // getters y setters convencionales.
  const int& getDestination() const;
  const double& getCost() const;
  void setDestination(int destination);
  void setCost(double cost);
};