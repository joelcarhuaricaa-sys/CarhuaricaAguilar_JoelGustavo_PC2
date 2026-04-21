# Actividad 2 Semana 2- CC232

### Integrantes
- Joel Gustavo Carhuarica Aguilar

#### Bloque 1 - Núcleo conceptual de Semana2

1.  Expliquen con sus palabras qué significa que un arreglo use **memoria contigua**.

   Se hace referencia a que todos sus elementos están pegados unos a otros, sin huecos, formando un solo bloque físico en la memoria RAM del equipo.Esto nos da una velocidad de lectura increíble, pero nos obliga a hacer mucho trabajo manual **desplazar datos** cuando queremos alterar ese orden.

2.  Expliquen por qué acceder a `A[i]` es una operación de costo `O(1)`.

   *Porque gracias a la memoria contigua, la dirección de cualquier elemento se calcula con una fórmula aritmética simple:
              Direccioˊn=Direccioˊn Base+(i×taman˜o del dato)
 Como el computador solo necesita realizar una multiplicación y una suma para hallar la ubicación exacta, el tiempo de acceso es constante e independiente del tamaño del arreglo.
3. Expliquen la diferencia entre `size` y `capacity`.

  - size: Es el número de elementos reales que el usuario ha guardado en la estructura (la longitud lógica).
  - capacity: Es el tamaño total del bloque de memoria reservado

4. Expliquen por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.

 Porque la memoria que rodea al bloque actual podría estar ocupada por otros datos o variables del programa. No hay garantía de que el "vecindario" esté libre. Por ello, al hacer resize(), se debe buscar un bloque nuevo y vacío lo suficientemente grande, copiar los datos viejos ahí y luego liberar el espacio anterior.

5. Expliquen por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.

 Si duplicamos la capacidad (2×n), las operaciones costosas de resize() ocurren con cada vez menos frecuencia a medida que el arreglo crece. Aunque un resize() específico cuesta O(n), ese costo se reparte (se "amortiza") entre las n/2 inserciones previas que fueron muy baratas.

6. Comparen `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?

 - Comparten: Ambos usan un arreglo de respaldo, gestionan capacidad/tamaño y tienen inserción con desplazamientos.
 - Diferencias: * Interfaz: DengVector es más cercano al std::vector de C++, incluyendo operaciones como find, traverse y sobrecarga de operator[].

    Intención: ArrayStack se enfoca en la eficiencia de la interfaz List y su relación con otras estructuras como DualArrayDeque. DengVector tiene un enfoque más pedagógico sobre el ciclo de vida del objeto.

7. Expliquen qué mejora `FastArrayStack` respecto a `ArrayStack`.

 Mejora el rendimiento práctico (constante) pero no la complejidad asintótica. En lugar de usar bucles for manuales para mover elementos, utiliza funciones optimizadas de sistema como std::copy y std::copy_backward. Esto aprovecha optimizaciones a bajo nivel (como instrucciones vectoriales del CPU) que pueden ser 2 o 3 veces más rápidas que un ciclo manual.

8. Expliquen cuál es la idea espacial central de `RootishArrayStack`.

 Su idea es usar una lista de bloques de tamaños crecientes (1,2,3,4…) en lugar de un solo arreglo que se duplica. Esto permite que los elementos se almacenen en múltiples arreglos pequeños. El objetivo es reducir el desperdicio de memoria (el "overhead" espacial).

9. Expliquen por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.

 En esta progresión aritmética asegura que el desperdicio de memoria sea de solo O(raiz de n​). En un arreglo dinámico tradicional que se duplica, podrías estar desperdiciando hasta el 50% de la memoria. En el RootishArrayStack, el último bloque es el único que puede estar parcialmente vacío, y su tamaño es proporcional a la raíz cuadrada del número total de elementos.

10. Expliquen qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.
  
 **Representación:** Un solo bloque (ArrayStack) da el mejor tiempo de acceso (O(1)), pero puede desperdiciar mucha memoria tras una duplicación.

 **Costo Temporal:** Para reducir el tiempo de redimensionamiento, aceptamos desperdiciar espacio .

 **Desperdicio Espacial:** Si queremos desperdiciar muy poco espacio (como en RootishArrayStack), la estructura se vuelve más compleja y el cálculo de la posición del índice es ligeramente más lento (requiere una raíz cuadrada o aritmética más compleja).

#### Bloque 2 - Demostración y trazado guiado
 
| Archivo | Salida u observable importante | Idea estructural | Argumento de costo o espacio |
|---|---|---|---|
| demo_array_basico.cpp | Muestra `array.length`, contenido del arreglo y luego `b = a` con transferencia de ownership | Un arreglo contiguo con longitud fija y asignación de bloque | Ilustra que el arreglo tiene longitud fija y que copiar/ asignar puede mover el bloque completo |
| demo_arraystack.cpp | Imprime tamaño, elementos, y resultado de `remove(1)` | `ArrayStack` como lista basada en arreglo con desplazamientos en `add`/`remove` | Deja ver que la inserción/remoción en medio implica desplazamientos lineales |
| demo_arraystack_explicado.cpp | Muestra `push_back`, `add(1,15)`, `remove(0)` y el debug de desplazamientos | Estructura didáctica donde se explica el desplazamiento de elementos al insertar/remover | Refuerza que `add(i,x)` y `remove(i)` cuestan `O(n-i)` por mover elementos |
| demo_fastarraystack.cpp | Inserta varios valores y `add(3,99)`, luego imprime el arreglo | `FastArrayStack` mantiene la interfaz de stack/arreglo pero con mejor manejo interno | Indica que la implementación cambia para ser más eficiente en la gestión interna aunque la complejidad asintótica de desplazamiento sigue similar |
| demo_rootisharraystack.cpp | Inserta 8 elementos, imprime todos y remueve `remove(3)` | `RootishArrayStack` almacena elementos en bloques crecientes | Muestra cómo la estructura usa bloques múltiples para reducir desperdicio espacial frente a un arreglo monolítico |
| demo_rootisharraystack_explicado.cpp | Imprime ubicación lógica→bloque/offset, `add(2,99)`, `remove(4)` | Visualiza el mapeo índice lógico → (bloque, offset) en bloques de tamaño `1,2,3,...` | Defiende que el mapeo mantiene acceso correcto y reduce desperdicio con bloques triangulares |
| demo_deng_vector.cpp | Muestra `size`, `capacity`, inserciones, `remove`, copia profunda, `traverse`, `find` | `DengVector` como vector dinámico con `_size`, `_capacity`, `_elem` y expansión | Evidencia el crecimiento de `capacity` y que `insert`/`remove` implican desplazamientos y copia profunda |
| demo_stl_vector_contraste.cpp | Imprime `size` y `capacity` tras `push_back` sucesivos | `std::vector` comparado con un vector dinámico propio | Refuerza la idea de crecimiento amortizado y la relación entre size/capacity |

1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?

 Nos deja claro que el arreglo es una región contigua con una length fija visible, y que la asignación b = a no copia elemento por elemento en el código, sino que transfiere ownership del bloque. Muestra que la longitud es una propiedad del objeto arreglo y que array[i] depende de esa longitud.

2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?

 la operación add(1, 15) es la que mejor muestra el costo por desplazamientos, porque obliga a mover los elementos desde el índice 1 hacia la derecha. También remove(0) muestra el desplazamiento inverso, pero add es más claro para explicar el costo O(n-i).

3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?

 Cambia la implementación interna de la pila de arreglo para mejorar el manejo de redimensionamiento o transferencia de datos, aunque la complejidad asintótica de add(i,x) y remove(i) sigue siendo del mismo orden. Es decir, la interfaz y el costo asintótico permanecen, pero la estructura interna es más eficiente en detalles de implementación.

4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?

 El ejemplo que imprime el mapeo de índice lógico a bloque y offset —la función print_location(s, i) con locate(i)— es el que mejor explica ese mapeo. Ese fragmento muestra explícitamente indice lógico -> bloque, offset.

5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?
 
 El observable que permite defender el crecimiento de capacity es la serie de mensajes tras cada insert: size= y capacity=. Se ve cómo capacity crece por encima de size a medida que se insertan elementos.

6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?

 La similitud conceptual con DengVector es que ambos mantienen size y capacity separadas y crecen en bloques para permitir inserciones amortizadas al final. Ambos son vectores dinámicos basados en arreglo contiguo.

7. ¿Qué demo sirve mejor para defender **amortización** y cuál sirve mejor para defender **uso de espacio**?

 Para defender mejor la **amortizacion** es 
 demo_stl_vector_contraste.cpp, porque muestra directamente push_back con size y capacity y permite hablar de crecimiento amortizado. 
 Y para defender mejor el **uso de espacio** es demo_rootisharraystack_explicado.cpp, porque visualiza cómo los bloques de tamaños 1,2,3,... reducen el desperdicio espacial respecto a un arreglo completo.

#### Bloque 3-Pruebas publicas, stress y correctitud

1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?

 La prueba pública para ArrayStack valida operaciones mínimas como add (al final y en posición específica), get, size y remove en posiciones intermedias, asegurando que el tamaño se actualice correctamente y que los elementos se desplacen apropiadamente.

2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?

 La prueba pública para FastArrayStack valida operaciones mínimas como add (al final y en posición específica), get, size y remove al inicio, verificando que el tamaño y los elementos se mantengan consistentes tras inserciones y remociones.

3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?

 La prueba pública para RootishArrayStack valida operaciones mínimas como add en posiciones específicas, get, set, size y remove, confirmando que el acceso y modificación funcionen correctamente en un arreglo distribuido en bloques.

4. ¿Qué sí demuestra una prueba pública sobre una estructura?

 Una prueba pública demuestra que las operaciones básicas de inserción, lectura, actualización y eliminación funcionan correctamente en casos simples, y que la estructura mantiene invariantes básicos como el tamaño y el acceso a elementos.

5. ¿Qué no demuestra una prueba pública?

 Una prueba pública no demuestra la complejidad temporal de las operaciones, el uso eficiente de espacio, el comportamiento en casos extremos o de borde, ni explica por qué el diseño es óptimo en términos de costo amortizado o invariantes avanzados.

6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?

 En resize_stress_week2.cpp, el comportamiento que intenta estresar es el crecimiento (inserciones masivas al final o inicio), la reducción (remociones masivas desde diferentes posiciones) y la estabilidad (mantener consistencia tras operaciones intensas, como en DengVector con inserciones y remociones alternadas).

7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

 Pasar pruebas no reemplaza una explicación de invariantes y complejidad porque las pruebas verifican correctitud empírica en casos específicos, pero no proporcionan el razonamiento teórico sobre por qué el algoritmo mantiene propiedades globales, qué costo amortizado justifica su eficiencia, o cómo se relacionan representación, tiempo y espacio en general. Se necesita análisis matemático y conceptual además de validación práctica.

#### Bloque 4-Vector como puente entre teoría y código

1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?

 - `_size`: Representa el número actual de elementos válidos en el vector, es decir, cuántos elementos están realmente almacenados.
 - `_capacity`: Indica el espacio total reservado en memoria para el arreglo interno, que puede ser mayor que _size para permitir crecimiento dinámico.
 - `_elem`: Es un puntero al arreglo dinámico que almacena los elementos del vector en memoria contigua.

2. ¿Cuándo debe ejecutarse `expand()`?

 `expand()` debe ejecutarse cuando _size alcanza _capacity, es decir, cuando no hay espacio suficiente para insertar un nuevo elemento sin reasignar memoria.

3. ¿Por qué `insert(r, e)` necesita desplazar elementos?

 Para insertar un elemento en la posición r, los elementos desde r hasta el final deben desplazarse una posición hacia la derecha para liberar espacio en r, manteniendo el orden secuencial.

4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?

 **remove(r)** elimina un solo elemento en la posición específica r.

 **remove(lo, hi)** elimina un rango de elementos desde la posición lo hasta hi-1, permitiendo la eliminación de múltiples elementos consecutivos en una sola operación.

5. ¿Qué evidencia de copia profunda aparece en la demo?

 En la demo, se crea una copia del vector (ods::DengVector<int> copia(v);) y se modifica independientemente (aplicando increaseByOne a la copia), lo que demuestra que la copia tiene su propia memoria y no afecta al vector original, evidenciando copia profunda en el constructor de copia.

6. ¿Por qué `traverse()` es una buena interfaz didáctica?

 `traverse()` permite aplicar una función o functor a cada elemento del vector, ilustrando conceptos de iteración, procesamiento uniforme y polimorfismo sin exponer detalles internos, facilitando el aprendizaje de patrones de visita.

7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?

 Implementar un vector propio permite comprender los mecanismos internos de gestión de memoria dinámica, expansión, reducción y análisis amortizado, proporcionando una base sólida antes de usar la implementación optimizada de std::vector.

#### Bloque 5 - RootishArrayStack: espacio y mapeo







 