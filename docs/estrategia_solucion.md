#### Estrategia de Resolución: ¿Por qué DFS y no BFS?

En el problema Word Search II, se utiliza DFS (Depth First Search) porque:

 - Memoria: DFS utiliza menos memoria en la pila de llamadas (O(L)) en comparación con el ancho de búsqueda de BFS.

 - Estado del Tablero: DFS facilita el proceso de "marcar y desmarcar" celdas visitadas (Backtracking), algo que en BFS requeriría copiar el estado del tablero por cada nodo de la cola.

 - Poda Temprana: Al combinar DFS con el Trie, podemos detener la exploración apenas el prefijo actual no coincida, ahorrando millones de comparaciones innecesarias.