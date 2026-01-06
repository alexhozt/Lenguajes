"""
Resolucion de Proyecto 1
by: alex 

¡**Netflix**! Lo que comenzó en 1997 como un servicio de alquiler de DVD ha explotado hasta 
convertirse en una de las mayores empresas de entretenimiento y medios.  

Dada la gran cantidad de películas y series disponibles en la plataforma, es la oportunidad perfecta 
para ejercitar tus habilidades de análisis exploratorio de datos y sumergirte en la industria del entretenimiento.  

Trabajas para una productora especializada en estilos nostálgicos. Quieres investigar sobre películas 
estrenadas en los años 90. Vas a analizar datos de Netflix y realizar un análisis exploratorio para comprender mejor esta increíble década cinematográfica.  

Se te ha proporcionado el conjunto de datos `netflix_data.csv`, junto con 
la siguiente tabla que detalla los nombres y descripciones de las columnas. ¡Siéntete libre de experimentar más después de enviar!

## Los datos
### **netflix_data.csv**
| Columna        | Descripción |
|----------------|-------------|
| `show_id`      | ID del programa |
| `type`         | Tipo de programa |
| `title`        | Título del programa |
| `director`     | Director del programa |
| `cast`         | Reparto del programa |
| `country`      | País de origen |
| `date_added`   | Fecha de incorporación a Netflix |
| `release_year` | Año de lanzamiento original |
| `duration`     | Duración en minutos |
| `description`  | Descripción del programa |
| `genre`        | Género del programa |


Responder:

¿Cuál fue la duración más frecuente de las películas en los años 90? Guarda una respuesta aproximada como un entero llamado (usa 1990 como año de inicio de la década).

Una película se considera corta si dura menos de 90 minutos. Cuenta el número de cortometrajes de acción estrenos en los años 90 y guarda este entero como .

"""

import pandas as pd
import matplotlib.pyplot as plt

# Cargar y preparar datos
netflix_df = pd.read_csv("netflix_data.csv")
peliculas_90s = netflix_df[(netflix_df['type'] == 'Movie') & 
                           (netflix_df['release_year'] >= 1990) & 
                           (netflix_df['release_year'] <= 1999)]

# Asegurarse de que 'duration' es string antes de usar .str
peliculas_90s['duration'] = peliculas_90s['duration'].astype(str)
# astype(str) convierte la columna a tipo string

# Extraer duración
peliculas_90s['duracion'] = peliculas_90s['duration'].str.extract('(\d+)').astype(int)
# str.extract('(\d+)') extrae los dígitos de la cadena y los convierte a int
# astype(int) convierte la columna extraída a tipo entero

# 1. Duración más frecuente
duration = int(peliculas_90s['duracion'].mode()[0])
#mode() devuelve la moda (valor más frecuente) de la columna 'duracion'
# [0] obtiene el primer valor en caso de múltiples modas

# 2. Cortometrajes de acción
cortos_accion = peliculas_90s[
    (peliculas_90s['duracion'] < 90) & 
    (peliculas_90s['genre'].str.contains('Action', na=False))
]
# str.contains('Action', na=False) verifica si 'Action' está en la columna 'genre', manejando NaN
short_movie_count = len(cortos_accion)

# RESULTADOS
print(f"Duración más común en los 90: {duration} minutos")
print(f"Cortometrajes de acción: {short_movie_count}")

# Visualización simple
plt.figure(figsize=(8, 5)) # Tamaño de la figura 
plt.hist(peliculas_90s['duracion'], bins=30, alpha=0.7, color='blue', edgecolor='black') # Histograma

plt.axvline(duration, color='red', linestyle='--', label=f'Moda: {duration} min') # Línea de moda

plt.axvline(90, color='green', linestyle='--', label='Límite cortometraje') # Línea de límite cortometraje

plt.xlabel('Duración (minutos)')
plt.ylabel('Número de películas')
plt.title('Distribución de duración - Películas de los 90')
plt.legend() # leyenda 
plt.grid(alpha=0.3) # cuadrícula
plt.show()


