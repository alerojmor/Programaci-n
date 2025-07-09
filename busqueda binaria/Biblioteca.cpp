/*Una biblioteca universitaria cuenta con personal bibliotecario distribuido en tres sedes diferentes. El sistema mantiene un registro completo de todos los préstamos realizados, organizando la información por código de bibliotecario.



    Código del bibliotecario
    Fecha del préstamo
    Material prestado (libro, revista, tesis)
    Valor de multa potencial (si se devuelve tarde)
    Puntos de evaluación obtenidos (por eficiencia en el servicio)





    Código de empleado
    Información personal (nombre y apellido)
    Sede de trabajo: 1=Central, 2=Ingeniería, 3=Medicina
    Categoría: A=Senior, B=Junior





    Información precargada en estructuras de datos estáticas
    Variables auxiliares indican cantidad de registros válidos
    Condición: todos los bibliotecarios registrados tienen al menos un préstamo procesado
    Bonificación: préstamos de material tipo "tesis" en sede Central otorgan 25% adicional en puntos de evaluación


Desarrollo requerido

Diseñar las estructuras de datos necesarias para el manejo eficiente de la información.

Implementar algoritmo de ordenamiento por selección para organizar bibliotecarios según sede de trabajo.

Desarrollar búsqueda binaria que localice bibliotecarios por código y retorne su posición en el arreglo, considerando que los datos están ordenados por código de empleado.

Implementar apareo para generar estructura que registre cada material prestado junto con la sede donde fue prestado (combinando información de préstamos y bibliotecarios).

Generar reporte por sede mediante técnica de corte de control, mostrando: nombre de la sede, cantidad total de préstamos procesados, y el tipo de material más prestado en esa sede.*/