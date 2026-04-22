### Actividad 3 - CC232

### INTEGRANTES
 - Joel Gustavo Carhuarica Aguilar

#### BLOQUE 1 - NUCLEO CONCEPTUAL DE LA SEMANA

1. Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.

 Cuando una estructura pasa de almacenamiento contiguo (como arreglos) a dinámico (como listas enlazadas), los elementos dejan de ocupar posiciones consecutivas en memoria y se distribuyen en nodos conectados por punteros. Esto facilita inserciones y eliminaciones locales al solo ajustar referencias, pero complica el acceso directo por índice, ya que requiere recorrer nodos secuencialmente, y aumenta el uso de memoria por los punteros adicionales.

2. Expliquen la diferencia entre acceso por rango y acceso por posición o enlace.

 El **acceso por rango** (o índice) permite localizar un elemento directamente mediante una posición numérica (ej. get(i)), aprovechando la contigüidad en memoria para cálculos aritméticos rápidos. **El acceso por posición** o enlace navega mediante punteros entre nodos, siendo más flexible para modificaciones locales pero menos eficiente para posiciones arbitrarias, ya que implica recorridos secuenciales.

3. Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.

 En una lista enlazada, las inserciones y eliminaciones locales son eficientes porque solo requieren ajustar punteros de nodos adyacentes, sin desplazar otros elementos. Sin embargo, el acceso por índice empeora porque no hay contigüidad; se debe recorrer la lista desde el inicio hasta la posición deseada, resultando en tiempo lineal en el peor caso.

4. Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.

 **SLList** implementa bien operaciones de **Stack** (LIFO) y **Queue** (FIFO) porque mantiene referencias al head y tail. Para Stack, push y pop operan en head en O(1). Para Queue, add en tail y remove en head también son O(1), aprovechando la estructura simplemente enlazada para acceso directo a extremos.

5. Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.

 `SLList` no implementa naturalmente todas las operaciones de un Deque con el mismo costo porque un `Deque` requiere acceso eficiente a ambos extremos para inserciones y eliminaciones. Aunque add y remove en extremos son O(1), operaciones como removeLast requieren recorrer toda la lista para actualizar tail, resultando en O(n) en el peor caso, en lugar del O(1) deseado.

6. Expliquen qué aporta el nodo centinela `dummy` en `DLList`.

 El nodo centinela dummy en DLList actúa como un marcador ficticio que simplifica el manejo de la lista vacía y evita casos especiales en operaciones. Conecta el inicio y fin de la lista, permitiendonos recorridos bidireccionales uniformes y reduciendo código duplicado para insertar/eliminar en extremos.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

 DLList justifica get(i), set(i,x), add(i,x) y remove(i) en O(1 + min(i, n-i)) porque usa navegación bidireccional desde el extremo más cercano (inicio o fin) hasta la posición i. El min(i, n-i) minimiza el recorrido, y las operaciones locales (ajustar punteros) son O(1) una vez localizada la posición.

8. Expliquen cuál es la idea espacial central de `SEList`.

 La idea espacial central de SEList es agrupar elementos en bloques (usando BDeque) para reducir la sobrecarga de memoria de punteros por elemento. En lugar de un puntero por nodo, múltiples elementos comparten un bloque, mejorando la eficiencia espacial mientras mantiene propiedades de listas enlazadas.

9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

 `SEList` reutiliza `BDeque` (basada en ArrayDeque) porque cada bloque necesita un contenedor dinámico eficiente para almacenar elementos. `ArrayDeque` proporciona inserciones/eliminaciones rápidas en extremos dentro de cada bloque, permitiendo que SEList maneje redistribuciones (spread/gather) de manera eficiente sin reimplementar lógica de arrays.

10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

 DengList sirve como una implementación más simple y didáctica de listas basada en Deng, enfocada en operaciones básicas y algoritmos como ordenamiento. No reemplaza a las estructuras de Morin porque estas ofrecen análisis de complejidad más detallado, optimizaciones específicas (como dummy en DLList o bloques en SEList) y comparación directa con representaciones contiguas, siendo más adecuadas para estudiar trade-offs en el curso.
