# Análisis de Complejidad - PC2

Este proyecto implementa la búsqueda de palabras en un tablero (Boggle) utilizando una estructura de datos **Trie** y algoritmos de **Backtracking**.

## 1. Estructuras de Datos Utilizadas
- **Trie (Árbol Prefijo):** Se utiliza para almacenar el diccionario de palabras. Permite descartar rutas en el tablero de forma temprana si el prefijo no existe en el diccionario.
- **std::list:** Utilizada para almacenar temporalmente las palabras encontradas, permitiendo inserciones de tiempo constante $O(1)$.
- **std::vector:** Utilizado para la salida final y el manejo del tablero.

## 2. Complejidad Temporal
La complejidad total del algoritmo se divide en dos fases:

### A. Construcción del Trie
- **Complejidad:** $O(N \cdot L)$
- Donde $N$ es el número de palabras y $L$ es la longitud promedio de las palabras. Insertar cada carácter toma tiempo constante.

### B. Búsqueda con Backtracking
- **Complejidad:** $O(M \cdot (4 \cdot 3^{L-1}))$
- Donde $M$ es el número de celdas en el tablero ($filas \times columnas$) y $L$ es la longitud máxima de las palabras. 
- Desde cada celda, exploramos 4 direcciones inicialmente, y luego 3 direcciones (evitando regresar a la celda anterior).

## 3. Complejidad Espacial
- **Complejidad:** $O(N \cdot L)$
- El espacio principal es consumido por el Trie, que en el peor de los casos almacena todos los caracteres de todas las palabras si no comparten prefijos.
- La pila de llamadas del backtracking consume $O(L)$ en profundidad.