## PC2 - CC232

### Estudiante
- Nombre: Joel Gustavo Carhuarica Aguilar
- Código: 20222270I
- Problema asignado:Word Search II
- Enlace: https://leetcode.com/problems/word-search-ii/

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal

- Semanas:
   **Semana2**=(Arreglos dinámicos y Deques) 
   **Semana3**=(Memoria enlazada vs Contigua)
   **Semana4**=(Backtracking y Simulación)

- Estructura o técnica principal: 
 Trie (Árbol de prefijos) para optimizar la búsqueda de múltiples palabras y Backtracking para la exploración del tablero de caracteres.

### Resumen de la solución

 - La solución utiliza un Trie para almacenar todas las palabras del diccionario. Al explorar el tablero mediante Backtracking (DFS), el Trie permite verificar en tiempo real si el camino actual forma un prefijo válido. Si un prefijo no existe en el Trie, se poda la búsqueda inmediatamente, optimizando drásticamente el tiempo de ejecución en comparación con una búsqueda exhaustiva por cada palabra.

### Complejidad
- Tiempo:  
 O(M⋅(4⋅3^(L-1))), donde M es el número de celdas y L la longitud máxima de la palabra.

- Espacio:
 O(N ⋅ L), donde N es el número de palabras, debido al almacenamiento en la estructura Trie.

### Invariante o idea clave

 - El uso de un marcador especial (#) durante la recursión garantiza que no se utilice la misma celda del tablero más de una vez para una misma palabra, restaurando el carácter original (Backtracking) al finalizar cada rama de exploración para permitir su uso en otras combinaciones.

### Archivos relevantes
 - include/Solution.h: Definición del TrieNode y la clase Solution.

 - src/Solution.cpp: Implementación de la lógica del Trie y el algoritmo de búsqueda.

 - tests/test_main.cpp: Pruebas unitarias para validar casos de borde.

 - demos/main.cpp: Ejemplo de ejecución con un tablero estándar.

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
#Ejecutar demostracion principal
./build/demo_p2

#Ejecutar pruebas unitarias
./build/tests_p2

#Ejecutar medicion de rendimiento
./build/benchmark_p2

```

### Casos de prueba

1.**Caso Básico:** Busca palabras como "oath" y "eat" en un tablero pequeño. Valida que el algoritmo encuentre palabras conectadas horizontal y verticalmente.

2.**Sin Coincidencias:** Se proporcionan palabras que no existen en el tablero o cuyas letras ni siquiera están presentes. Valida que el sistema retorne una lista vacía sin errores.

3.**Palabra Fuera de Límites:** Intenta buscar palabras más largas que el número total de celdas o que se "salen" de los bordes. Valida la seguridad de los índices y la correcta terminación de la recursión

### Historial de commits
Indica que el historial debe verse en el video.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.