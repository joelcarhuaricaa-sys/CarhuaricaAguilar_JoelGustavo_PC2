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

#### BLOQUE2 - DEMOSTRACION Y TRAZADO GUIADO

| Archivo |	Salida u observable importante | Idea estructural |	Argumento de costo, espacio o diseño |
|---|---|---|---|
|`demo_sllist.cpp` | `size = 3`, `peek = 5`, `pop = 5`, `remove = 20` | `SLList` combina operaciones de pila y cola en una sola lista enlazada simple |	`push` / `pop` trabaja como stack en el frente; `add` / `remove` aporta comportamiento de cola en el otro extremo.|
|`demo_dllist.cpp`|	Impresión `10 20 30` tras `add(0,10)`, `add(1,30)`, `add(1,20)` | `DLList` usa doble enlace + dummy para insertar en medio con eficiencia | `add(i,x)` en posición intermedia se justifica por recorrido desde el extremo cercano `O(1 + min(i,n-i))`.|
|`demo_selist.cpp`|	Impresión ordenada `0 10 20 30 40 50 60 70 80 90`| 	`SEList` mantiene el orden lógico de lista aunque internamente use bloques | El acceso lógico `get(i)` sigue devolviendo la secuencia ordenada, mostrando que la fragmentación en bloques es transparente.|
|`demo_deng_list.cpp` | `size`, `front`, `back`, luego lista ordenada tras `sort()` | `DengList` ofrece lista reforzada con operaciones de lista completas | `push_back`, `push_front`, `front`, `back` y `sort()` muestran un ADT de lista más rico que solo un contenedor básico.|
|`demo_morin_deng_bridge.cpp` | Salida con lista ordenada y `removed = ...` tras `stable_sort_with_deng` y `dedup_with_deng` | Algoritmos Deng aplicados sobre `DLList` sin reescribir la estructura base |	El uso de `stable_sort_with_deng(lista)` y `dedup_with_deng(lista)` demuestra reutilizar la estructura `DLList` para nuevos algoritmos.|
|`demo_min_structures.cpp` | `MinStack min=3`, `MinQueue min=2`, `MinDeque min=1` |	Estructuras que guardan elementos y metadata para responder `min()` | La diferencia es entre almacenar solo valores y almacenar información adicional (auxiliar) para responder `min()` en tiempo rápido.|
|`demo_linked_adapters.cpp` | Resultados de `LinkedStack`, `LinkedQueue`, `LinkedDeque` con operaciones adaptadas | Adaptadores que brindan interfaces nuevas sobre estructuras enlazadas |	Reutiliza la estructura enlazada subyacente para implementar interfaces de `Stack`, `Queue` y `Deque` sin reescribir los nodos básicos.|
|`demo_contiguous_vs_linked.cpp` | Comparación `ArrayDeque` vs `DLList`: FIFO, deque e índice |	Contrasta estructura contigua con estructura enlazada |	`ArrayDeque` gana en acceso por índice y localidad de memoria; `DLList` gana en inserción local y flexibilidad de enlaces.|

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?

 `demo_sllist.cpp:` la secuencia `add(10)`, `add(20)`, `push(5)` seguida de `peek()`, `pop()` y `remove()` deja más clara la coexistencia de pila y cola.

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?

 La operación `add(1, 20)` es la que mejor muestra inserción en posición intermedia.

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?
 
 El observable `get(i)` que devuelve valores en orden lógico (`0 10 20 ... 90`) defiende que la lista mantiene orden aunque trabaje por bloques.

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?
  
 La evidencia es que se muestran `front`, `back`, tamaño y luego `sort()` + `to_vector()`, lo que indica operaciones de lista completas.

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?

 La parte de salida que muestra la lista ordenada y el `removed = ...` tras aplicar `stable_sort_with_deng` y `dedup_with_deng` justifica la reutilización de algoritmos sobre la misma estructura base.

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?
  
 La diferencia conceptual es que guardar valores permite solo operaciones normales, mientras que almacenar información adicional permite responder `min()`rápidamente sin recorrer toda la estructura.

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?

 El adaptador `LinkedStack` representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva, aunque `LinkedQueue` y `LinkedDeque` también lo hacen.

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

 El contraste es que el acceso por índice es más directo en la estructura contigua (`ArrayDeque`), la inserción local es más natural en la estructura enlazada (`DLList`/`LinkedDeque`), y la memoria contigua ofrece mejor localidad frente a la dispersión de punteros en la lista enlazada.

#### BLOQUE3 - PRUEBAS PUBLICAS, STRESS Y CORRECTITUD

1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?

 En test_public_week3.cpp:

 - `add(x)` — agregar elemento
 - `push(x)` — operación tipo pila
 - `size()` — contar elementos
 - `peek()` — ver el tope
 - `pop()` — remover tope
 - `remove()` — remover primer elemento

 **Resultado:** Solo operaciones en los extremos (cabeza y cola) sin acceso por posición intermedia.

2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?
 
 En `test_public_week3.cpp`:

 - `add(i, x)` — agregar en posición `i`
 - `get(i)` — acceder en posición `i`
 - `remove(i)` — remover en posición `i`
 - `size()` — contar elementos

  **Resultado:** Acceso aleatorio y modificaciones puntuales en posiciones arbitrarias.

3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?
 
 En test_public_week3.cpp:

 - `add(i, x)` — agregar en posición `i`
 - `get(i)` — acceder en posición `i`
 - `set(i, x)` — reemplazar en posición `i` y devolver anterior
 - `remove(i)` — remover en posición `i`
 - `size()` — contar elementos

 **Resultado:** Operaciones fundamentales por índice, similar a DLList pero sin acceso a nodos interme­dios directamente.

4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?
 
  Nuevas operaciones/métodos:

 - `to_vector()` — convertir a std::vector (SLList, DLList)
 - `secondLast()` — acceder penúltimo elemento (SLList)
 - `reverse()` — invertir orden (SLList, DLList)
 - `checkSize()` — validar consistencia interna (SLList, DLList)
 - `rotate(r)` — rotación circular (DLList)
 - `isPalindrome()` — validar estructura simétrica (DLList)
 - `min()` — operación especializada (MinStack, MinQueue, MinDeque)
 - `addFirst()`, `addLast()`, `removeLast()` — operaciones extremos (MinDeque, XorList)

5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?

 - **LinkedStack**: `push()`, `pop()`, `top()`, `empty()`, `size()`     — comportamiento LIFO correcto
 
 - **LinkedQueue**: `add()`, `remove()`, `front()`, `empty()`, `size()` — comportamiento FIFO correcto

 - **LinkedDeque**: `addFirst()`, `addLast()`, `removeFirst()`, `removeLast()`, `front()`, `back()`, `empty()`, `size()` — todas las operaciones de extremos funcionan.

 **Idea central**: Valida que los adaptadores heredan correctamente el comportamiento de la estructura subyacente sin mutations semánticas.

6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?
- **DengList directo**:  `push_back() `,  `push_front() `,  `add() `,  `front() `,  `back() `,  `get() `,  `find_index() `,  `contains() ` funcionan

- **Algoritmos sobre Morin + Deng**:

   - `stable_sort_with_deng() ` convierte DLList/SEList a DengList, ordena, convierte de vuelta.
   -  `dedup_with_deng() ` elimina duplicados reutilizando el ADT de Deng
   -  `reverse_with_deng() ` invierte sin reimplementar

- **Bridge permite**:
   - Reutilizar **algoritmos de Deng** sin reescribir estructuras Morin
   - Conversión transparente entre representaciones

Los algoritmos son agnósticos a la estructura subyacente si existe un contrato claro.

7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?
  
  1. Crecimiento orgánico de bloques: 500 inserciones consecutivas para forzar subdivisiones internas de celdas B

  2. Borrado frontal sostenido: 250 eliminaciones desde el inicio para validar reorganización de bloques y mantenimiento de invariantes

  3. Mantenimiento del tamaño lógico: Al final, debe cumplir exactamente size() == 350 (500 - 250 + 100), demostrando que nunca se pierde consistencia interno-externa

8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?

    ✅ Contrato funcional cumplido:

       - Las operaciones devuelven valores correctos

       - El tamaño se mantiene consistente
       
       - Las relaciones de orden (FIFO, LIFO) se respetan

       - La estructura no crash en operaciones secuenciales 

    ✅ Correctitud local:

       - Para los casos de uso probados, no hay fallos evidentes

    ✅ No hay memory leaks obvios (si corre sin SIGSEGV)


9. ¿Qué no demuestra una prueba pública por sí sola?

❌ No valida:

   - **Invariantes de punteros**: ¿Todos los nodos han sido visitables desde la cabeza?
   - **Integridad de enlaces**: ¿`next` de nodo i es realmente el nodo i+1?
   - **Complejidad temporal**: Las operaciones cumplen O(1),O(logn),(n)?
   - **Localidad de memoria**: ¿SEList mantiene caché-locality?
   - **Comportamiento en edge cases internos**: Nodos centinela, bloques vacíos, expansiones
   - **Eficiencia espacial**: ¿Hay fragmentación interna, overhead de punteros?
   - **Correctitud semántica profunda**: ¿Por qué get(i) es O(1+min(i,n−i)) en DLList?

10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?

Porque:

  1. **Pruebas son casos finitos, teoría es universal**: Una prueba con n≤500 no garantiza corrección en n=10^6 

  2. **Invariantes son el "por qué"**:

     - Saber que DLList::remove(i) cuesta O(1+min(i,n−i))explica por qué la estructura es válida
     - Una prueba que "pasa" puede ser por suerte de acceso a posiciones balanceadas

  3. **Punteros son el mecanismo**:

     - Ver pasar assertions no explica cómo dummy y enlaces bidireccionales previenen segmentation faults
     - El enlace prev es esencial para rotate(), no opcional

  4. **Complejidad espacial oculta**:

     - Una prueba puede pasar pero el overhead de punteros hace SEList ineficiente en memoria

  5. **Reutilización confiable**: Cuando adaptes la estructura (ejemplo: SEList a BDeque), necesitas entender los invariantes para no romper la abstracción

#### BLOQUE4 - SLLIST, DLLIST Y SELIST: LECTURA CERCANA DEL CODIGO

1. En `SLList`, ¿qué papel cumplen `head`, `tail` y `n`?

 `head`: Puntero al primer nodo de la lista. Permite acceso rápido al inicio para operaciones de pila (`push` / `pop`).

 `tail`: Puntero al último nodo. Permite agregar elementos al final en tiempo constante sin recorrer toda la lista.

 `n`: Contador del número de elementos. Permite responder `size()` sin recorrer la estructura y facilita validaciones.

2. En `SLList::push`, `pop`, `add` y `remove`, ¿qué punteros cambian exactamente?

 | **Operación** | **Punteros que cambian** |
 |---|---|
 | `push(x)` |	`head` (apunta al nuevo nodo), `tail` (solo si `n==0`), `n` |
 | `pop()` | `head` (avanza al siguiente), `tail` (solo si `n==1`), `n` |
 | `add(x)` (al final) | `tail->next` (apunta al nuevo), `tail` (avanza), `n` |
 | `remove()` (frontal) | `head` (avanza), `tail` (solo si `n==1`), `n` |

3. Expliquen cómo funciona `secondLast()` y por qué no puede resolverse directamente con solo mirar `tail`.

     T secondLast() const { 
         assert(n >= 2);
         Node* u = head;
         while (u->next != tail) { // Busca hasta encontrar el penúltimo
             u = u->next;
         }
         return u->x;
     }

- Por qué no funciona con solo `tail`:

    - `tail` solo apunta al último nodo, no al penúltimo.
    - En una lista **simplemente enlazad a**, cada nodo solo conoce al siguiente, no al anterior.
    - Para encontrar el penúltimo, necesariamente hay que recorrer desde `head` hasta llegar a un nodo cuyo `next` sea `tail`.
    - Costo:**O(n)**.

4. Expliquen paso a paso cómo funciona`reverse()` y por qué no necesita estructura auxiliar.

     void reverse() {
         Node* prev = nullptr;    // Nodo "anterior" en el orden nuevo
         Node* curr = head;       // Nodo actual siendo procesado
         tail = head;             // El head será el nuevo tail
    
         while (curr != nullptr) {
             Node* next = curr->next;  // Guarda el siguiente antes de cambiar
             curr->next = prev;         // Invierte: apunta hacia atrás
             prev = curr;               // Avanza prev
             curr = next;               // Avanza curr
         }
         head = prev;              // prev quedó apuntando al último nodo
     }

**Por que no necesita estructura auxiliar:**

  - Solo necesita tres punteros temporales (`prev`, `curr`, `next`).
  - Reutiliza el mismo espacio de nodos sin crear nuevos.
  - Los cambios de referencias se hacen **in-place**.
  - Costo: **O(n)** tiempo, **O(1)** espacio adicional.

5. Expliquen qué verifica `checkSize()` y por qué esta función ayuda a defender correctitud.

     bool checkSize() const {
         int count = 0;
         Node* u = head;
         Node* last = nullptr;
    
         while (u != nullptr) {
             last = u;
             u = u->next;
             ++count;  // Cuenta elementos reales
         }
    
         // Valida que el contador coincida
         if (count != n) return false;
    
         // Valida casos extremos
         if (n == 0) return head == nullptr && tail == nullptr;
    
         // Valida que tail apunte realmente al último
         return head != nullptr && tail == last;
     }

**Ayuda defender correctitud porque:**

   - Detecta corrupción del contador `n`.
   - Verifica que `tail` realmente apunte al último nodo.
   - Identifica invariantes rotos (cabeza y cola inconsistentes).
   - Es esencial para pruebas de estrés y debugging.

6. En `DLList`, expliquen por qué `getNode(i)` puede empezar desde el inicio o desde el final.

     Node* getNode(int i) {
         assert(0 <= i && i <= n);
         Node* p;
    
         if (i < n / 2) {           // Si está en la primera mitad
             p = dummy.next;        // Empieza desde el inicio
             for (int j = 0; j < i; ++j) p = p->next;
         } else {                   // Si está en la segunda mitad
             p = &dummy;            // Empieza desde el final (dummy es circular)
             for (int j = n; j > i; --j) p = p->prev;  // Retrocede
         }
         return p;
     } 

**Ventaja:**

  - Para elementos cercanos al final, retroceder es más rápido que avanzar.
  - Reduce el número de saltos a approximately `min(i, n-i)`.
  - Costo amortizado: **O(1 + min(i, n-i))**.

7. En `DLList::addBefore`, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?

     Node* addBefore(Node* w, const T& x) {
         Node* u = new Node{x, w->prev, w};  // Crear nodo con ambos enlaces
         u->prev->next = u;  // El anterior de w ahora apunta a u
         u->next->prev = u;  // w ahora tiene a u como anterior
         ++n;
         return u;
     }

**Enlaces actualizados:**

   1. `u->prev` y `u->next` (del nodo nuevo)
   2. `(u->prev)->next` (enlace forward del anterior)
   3. `(u->next)->prev` (enlace backward de w)

Por qué `dummy` elimina casos borde:

   - No hay que distinguir inserción al inicio vs. en medio.
   - `dummy` es simultáneamente predecesor del primero y sucesor del último.
   - La lista vacía se trata uniformemente: todos los nodos apuntan a `dummy`.
   - Simplifica la lógica: una sola función para todas las posiciones.

8. Expliquen cómo funciona `rotate(r)` sin mover los datos elemento por elemento.

     void rotate(int r) {
         if (n <= 1) return;
         r %= n;
         if (r == 0) return;
    
         // Identifica dónde cortar
         Node* oldFirst = dummy.next;      // Primer nodo actual
         Node* oldLast = dummy.prev;       // Último nodo actual
         Node* newFirst = getNode(n - r);  // Nuevo primer nodo (r posiciones del final)
         Node* newLast = newFirst->prev;   // Lo que era antes del nuevo primero
    
         // Reorganiza enlaces sin mover datos
         oldLast->next = oldFirst;         // Cierra el ciclo
         oldFirst->prev = oldLast;
         newLast->next = &dummy;           // Nuevo corte
         dummy.prev = newLast;
         dummy.next = newFirst;
         newFirst->prev = &dummy;
     }

**Sin mover datos:**

  - Los valores dentro de los nodos permanecen intactos.
  - Solo se cambian los enlaces de 4-6 punteros.
  - Costo: O(1) después de encontrar `newFirst` (que cuesta `O(min(n-r, r))`).

9. Expliquen cómo `isPalindrome()` aprovecha la naturaleza doblemente enlazada de la estructura.

     bool isPalindrome() const {
         const Node* left = dummy.next;    // Empieza desde el inicio
         const Node* right = dummy.prev;   // Empieza desde el final
    
         for (int i = 0; i < n / 2; ++i) {
              if (!(left->x == right->x)) {  // Compara elementos opuestos
                  return false;
              }
              left = left->next;             // Avanza desde el inicio
              right = right->prev;           // Retrocede desde el final
         }
         return true;
     } 

**Ventaja de ser doblemente enlazada:**

  - Puede recorrer simultáneamente desde ambos extremos.
  - En una lista simple, verificar palíndrome requeriría almacenar valores o invertir.
  - Aquí: solo usa dos punteros y una comparación, costo **O(n/2)**.

10. En `SEList`, expliquen qué representa `Location`.

     struct Location {
         Node* u;  // Puntero al bloque (nodo) que contiene el elemento
         int j;    // Índice dentro del bloque
     };

**Propósito:**

  - Descompone un índice global `i` en dos coordenadas.
  - `i` se traduce a "estar en el bloque `u`, en posición `j` dentro del bloque".
  - Permite acceder directamente a un elemento sin recorrer toda la lista.
  - Ejemplo: si bloques tienen tamaño 3 e `i=7` → bloque 2, posición 1 dentro del bloque.

11. Expliquen qué hacen `spread()` y `gather()` y en qué situaciones aparecen.

`spread(Node* u)` - Expande cuando los bloques están llenos

     void spread(Node* u) {
          // Crea b nodos nuevos
          Node* w = u;
          for (int j = 0; j < b; ++j) w = w->next;
          w = addBefore(w);
    
          // Redistribuye elementos: mueve del penúltimo al nuevo bloque
          while (w != u) {
              while (w->d.size() < b) {
                  w->d.add(0, w->prev->d.remove(w->prev->d.size() - 1));
              }
              w = w->prev;
          }
     }

**Cuándo aparece:** Al insertar en una posición donde hay bloques llenos.

`gather(Node* u)` - Compacta cuando los bloques están vacíos

     void gather(Node* u) {
          // Mueve elementos hacia atrás desde bloques casi vacíos
          Node* w = u;
          for (int j = 0; j < b - 1; ++j) {
              while (w->d.size() < b) {
                  w->d.add(w->next->d.remove(0));
                }
         w = w->next;
         }
         removeNode(w);  // Elimina el bloque ahora vacío
     }

**Cuándo aparece:** Al eliminar, si un bloque cae por debajo del umbral mínimo.

12. Expliquen cómo el tamaño de bloque `b` afecta compromiso entre acceso, actualización y uso de espacio.

| **Aspecto** | **Pequeño** `b` | **Grande** `b` |
|---|---|---|
| **Acceso a índice** | Más saltos entre bloques (peor) | Menos saltos (mejor) |
| **Inserción/eliminación** | `spread`/`gather` menos frecuentes (mejor) |  Más costosos cuando ocurren (peor) |
| **Uso de memoria**| Menos desperdicio por sobrecarga de referencias |	Más bloques subutilizados (peor) |
|**Localidad de caché**| Peor (bloques pequeños) | Mejor (bloques grandes explotan caché) |
| **Costo amortizado** | O(n) peor distribución | O(n) mejor distribución |

Compromiso óptimo: b ≈ sqrt(n) o configuración estática (típicamente 3-5) da buen balance general.