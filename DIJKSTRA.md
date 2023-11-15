En el algoritmo de Dijkstra utilizado para la busqueda de combinaciones con menor costo o menor duración, la cola de prioridad se utiliza para manejar los nodos (aeropuertos) de manera eficiente, seleccionando siempre el nodo con el menor costo actual durante la exploración. Aquí hay una explicación de cómo funciona:

1. **Inicialización de la cola de prioridad:**
   ```cpp
   std::priority_queue<std::pair<float, Aeropuerto *>, std::vector<std::pair<float, Aeropuerto *>>, std::greater<>> colaPrioridad;
   ```

   Se crea una cola de prioridad utilizando la plantilla `std::priority_queue` de la biblioteca estándar de C++. Esta cola de prioridad está configurada para contener pares `(float, Aeropuerto *)`, donde el primer elemento del par es el costo acumulado hasta el nodo y el segundo es un puntero al nodo (aeropuerto).

   La plantilla `std::greater<>` se utiliza para asegurar que la cola de prioridad devuelva el elemento mínimo en la parte superior en lugar del máximo.

2. **Agregar el nodo de inicio a la cola de prioridad:**
   ```cpp
   colaPrioridad.push({0, origen.value()});
   ```

   En este paso, el aeropuerto de inicio se agrega a la cola de prioridad con un costo acumulado de 0. Esto marca el inicio del algoritmo.

3. **Proceso de la cola de prioridad en el bucle principal:**
   ```cpp
   while (!colaPrioridad.empty()) {
       Aeropuerto *aeropuertoActual = colaPrioridad.top().second;
       colaPrioridad.pop();
       // Resto del bucle...
   }
   ```

   El bucle principal del algoritmo Dijkstra se ejecuta mientras la cola de prioridad no esté vacía. En cada iteración, se extrae el aeropuerto con el costo acumulado más bajo desde la cola de prioridad.

4. **Exploración de los nodos adyacentes:**
   ```cpp
   for (const Vuelo *vuelo: aeropuertoActual->getVuelos()) {
       // Resto del bucle...
   }
   ```

   Se exploran los vuelos (aristas) que parten del aeropuerto actual. Para cada vuelo, se calcula el nuevo costo acumulado desde el nodo de inicio hasta el nodo destino del vuelo. Si este nuevo costo es menor que el costo actual almacenado para el nodo destino, se actualiza el costo y se coloca el nodo destino en la cola de prioridad.

5. **Actualización de la cola de prioridad:**
   ```cpp
   colaPrioridad.push({costoHastaDestino, aeropuertoDestino});
   ```

   Si se encuentra un camino más corto hasta un nodo destino, se actualiza el costo y se coloca el nodo destino de ese vuelo en la cola de prioridad con el nuevo costo acumulado. Esto garantiza que los nodos se procesen en orden de menor a mayor costo acumulado.

Este proceso se repite hasta que la cola de prioridad esté vacía o se alcance el nodo de destino, momento en el cual se reconstruye la ruta más corta. La cola de prioridad juega un papel crucial al garantizar que los nodos se seleccionen en función de sus costos acumulados, permitiendo que el algoritmo explore de manera eficiente y encuentre la ruta mínima.