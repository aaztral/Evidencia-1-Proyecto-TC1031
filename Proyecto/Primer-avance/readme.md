# Proyecto: Los Mejores de la NFL
Este proyecto seleccionará posiciones dentro de el juego de Football Americano, particularmente los pertenecientes a la NFL, se podrá escoger entre una lista de jugadores de esas posiciones y rankearlo según sus atributos como velocidad, fuerza o un overall de todas sus estadisticas con ayuda de mecanismos de sorting.

## Descripción del avance 1
En este avance creamos una lista de 10 _Wide Receivers_ de la NFL, y almacenamos su Overall Rating en el videojuego _Madden 25_, procedemos a utilizar un QuickSort para lograr ordenar estos _Wide Receivers_ del mejor al peor.

https://www.ea.com/games/madden-nfl/ratings?position=WR

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Escribe aquí la descripción de las entradas del proyecto, por ejemplo, si de entrada se requieren varios archivos, hay que indicar el formato de cada uno de ellos, y proporcionar un ejemplo de los datos de cada archivo.

## Descripción de las salidas del avance de proyecto
La salida esperada para este proyecto es una lista de jugadores en desorden junto con sus overall ratings, seguido de la lista ya ordenada del mayor al menor por su calificación. 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Haciendo un análisis de complejidad podemos concluir lo siguiente: 
  - La construcción de la lista wrList es de complejidad **O(n)**, en este caso de **O(10)** ya que es una lista de 10 jugadores.
  - Para mostrar la lista se itera sobre los objetos de la lista y se llama a display() para cada uno. La complejidad de esto es O(n), ya que cada llamada a display() es una operación constante O(1).
Para el QuickSort analizaremos la complejidad paso a paso:
  - La complejidad de la partición es de O(n) para un subarray de tamaño n, ya que recorre una vez todos los elementos entre los índices low y high. Y para el peor caso el pivote será siempre el menor elemento de la sublista, lo que hará que el número de elementos que quedan en una sublista después de la partición sea casi igual al tamaño de la lista original.
  - Para el QuickSort recursivo ya sabemos que el Quicksort en el mejor y promedio de los casos es un O(n log n), por que el pivote dividirá la lista casi a la mitad, excepto en el peor de los casos donde el pivote siempre eleigirá el menor o mayor de la lista y en este caso hará n particiones.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para el sorting simplemente recurrí al algoritmo de ordenamiento más eficiente según lo visto en clase, este es el QuickSort, esto debido a que realmente cualquier algoritmo de ordenamiento sería correcto entonces el más eficiente es la opcíon correcta. Y con ayuda del siguiente video no fue un problema la implementación. 

https://youtu.be/PupaczLYxmA?si=Uk2x71qDHAOkdbTp
