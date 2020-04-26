/**
  *  Escuela Superior de Ingeniería y Tecnología
  *  Grado en Ingeniería Informática
  *  Asignatura: Diseño y análisis de algoritmos
  *  Curso: 3º
  *  Práctica 8: Max-mean dispersion problem.
  *  @author: Manuel Andrés Carrera Galafate <alu0101132020@ull.edu.es>
  *  @since: 23/04/2020
  *  @desc: Clase problema para la implementación del max-mean problem
  *  @references:
  *               Explicación del problema y la solución:
  *               https://drive.google.com/file/d/1btbyAPJNfy-9oQ9as22bmagi6o1XhHGn/view
  * 
  *
  *  @version:
  *              20/04/2020 - Creación (primera versión) del código.
  */

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Problem {
private:
  bool isMaxProblem;
public:
  // Constructor por defecto
  Problem();
  // Constructor por valor doble
  Problem(double solutionValue);
  // Getter de la solución almacenada
  bool isMaxProblem();
  // Setter del tipo de problema
  void setIsMaxProblem(bool);
};