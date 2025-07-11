/*Consumo de Combustible en Flota de Transporte de Pasajeros

Una empresa de transporte urbano necesita desarrollar un sistema para evaluar el rendimiento de combustible de su flota, con el objetivo de optimizar costos y detectar conductores o vehículos con baja eficiencia.

La empresa dispone de información de sus vehículos y viajes realizados.

Datos
Vehículos (ordenado por ID de vehículo):

De cada vehículo se conoce:

Id del vehículo (entero)

Tipo de vehículo (1: Mini, 2: Mediano, 3: Grande)

Patente (string)

Consumo por kilómetro (litros/km)

Zona asignada (1: Centro, 2: Norte, 3: Sur)

Viajes (ordenado por ID de vehículo):

De cada viaje se conoce:

Id del vehículo (entero)

Fecha (formato DDMMAAAA)

Hora de inicio (formato 24hs)

Origen (string)

Destino (string)

Distancia recorrida (float)

Litros reales consumidos (float)

Objetivos
1. Definir las estructuras necesarias para representar vehículos y viajes.

2. Desarrollar la función buscarVehiculo que, dado un ID de vehículo, devuelva su posición en el vector de vehículos.

3. Implementar una función generarRendimientos que genere un nuevo vector con el siguiente resumen por vehículo:

Id del vehículo

Tipo de vehículo

Patente

Total de kilómetros recorridos

Total de litros consumidos

Rendimiento real = Km recorridos / Litros consumidos

Rendimiento esperado = 1 / consumo por km

Zona

4. Ordenar por zona de forma ascendente el vector de resumen obtenido en el punto anterior usando una función ordenarPorZona.

5. Generar un reporte por zona, utilizando el vector ordenado:

Nombre de la zona

Total de kilómetros recorridos en la zona

Promedio del rendimiento real en la zona

Diferencia promedio entre rendimiento real y esperado

Consideraciones
Los vectores están previamente cargados.

Todos los vehículos realizaron al menos un viaje.

No hay viajes con 0 km o 0 litros consumidos.

Los tipos de vehículo deben representarse como un enum o const.

Restricciones
Para el punto 4 se debe usar el vector generado en el punto 3.

Para el punto 5 se debe usar el vector ordenado por zona del punto 4.

Deben aplicarse estructuras de datos estáticas (vectores fijos) con un tamaño máximo de 100 elementos.*/


