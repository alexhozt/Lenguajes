# DataSet generator to project Netflix Retro Investigate
import pandas as pd
import numpy as np

# semilla
np.random.seed(42) # esto asegura que cada vez que se ejecute el codigo se obtenga EXACTAMENTE los mismos datos aleatorios.

# numero de datos
num_records = 1000

# IDs unicos
show_ids = [f's{str(i).zfill(5)}' for i in range(num_records)]
# str(i).zfill(5) convierte cada numero a texto y agrega ceros a la izquierda hasta tener 5 digitos, ej: 5 -> '00005' ; f's{...}' agrega una 's' al inicio. resultado: ['s00000', 's00001', ..., 's00999']

#tipos de programas
types = np.random.choice(['Movie', 'TV Show'], size=num_records, p=[0.7, 0.3])
# np.random.choice elige aleatoriamente entre las opciones dadas, size es la cantidad de elecciones a hacer, p son las probabilidades asociadas a cada opcion.

# titulos de peliculas

movie_titles = [
    'The Last Adventure', 'Moonlight Dreams', 'Cyber Revolution', 'Desert Winds',
    'Ocean Mysteries', 'Mountain Echo', 'Secret Agent X', 'Time Paradox',
    'Echoes of Yesterday', 'Future Shock', 'Neon Nights', 'Silent Forest',
    'Digital Ghost', 'Lost Kingdom', 'Urban Legends', 'Wild Expedition',
    'Starlight Journey', 'Hidden Truth', 'Final Frontier', 'Broken Chains'
]

# titulos de series

series_titles = [
    'Mystery Valley', 'Tech Wars', 'Family Ties', 'Beyond Borders',
    'Undercover', 'Medical Heroes', 'Legal Minds', 'Space Explorers'
]

titles = []

for t in types:
    if t == 'Movie':
        titles.append(np.random.choice(movie_titles) + f' {np.random.randint(1, 2020)}') # escoge un titulo de pelicula y le agrega un año aleatorio entre 1 y 2019 para mayor variedad
    else:
        titles.append(np.random.choice(series_titles))


# directores
directors = np.random.choice(['Christopher Nolan', 'Steven Spielberg', 'Quentin Tarantino', 'James Cameron',
     'Jane Doe', 'John Smith', 'Maria Garcia', 'David Lee', np.nan], size=num_records, p=[0.1, 0.1, 0.1, 0.1, 0.15, 0.15, 0.1, 0.1, 0.1])
# np.nan representa valores faltantes

# elenco
# en este caso cada elenco es independiente, por lo que no es necesario saber en que pelicula/serie aparece cada actor
# para aficionados de python, recordar que el _ bajo en for _ in range(...) es una convención para indicar que no se usará la variable del bucle
casts = []
for _ in range(num_records):
    actors = [ 'Actor A', 'Actor B', 'Actor C', 'Actor D', 'Actor E']
    numero_actores = np.random.randint(1, 5) # entre 1 y 4 actores
    cast = ', '.join(np.random.choice(actors, size=numero_actores, replace=False))
    # ', '.join(...) une los nombres de los actores en una sola cadena separada por comas
    if np.random.rand() < 0.25:
        cast = np.nan  # 25% de probabilidad de que el elenco sea NaN
    casts.append(cast)


# paises

countries = np.random.choice(
    ['United States', 'United Kingdom', 'India', 'Canada', 'Japan',
     'France', 'Spain', 'Germany', 'Australia', 'South Korea', 'Mexico', np.nan],
    size=num_records, p=[0.3, 0.1, 0.15, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05]

)

# fechas de adicion

dates_added = []

for _ in range(num_records):
    year = np.random.randint(2010, 2023) # entre 2010 y 2022
    month = np.random.randint(1, 13) # entre 1 y 12
    day = np.random.randint(1, 29) # entre 1 y 28 para evitar problemas con meses cortos
   
    if np.random.random() < 0.1: # 10% de probabilidad de ser NaN
        dates_added.append(np.nan)
    else:
        dates_added.append(f'{month}/{day}/{year}')


# año de lanzamiento (entre 1980 y 2022, con concentracion en los 90s)

release_years = []

for _ in range(num_records):
     # Distribución: 20% en los 90s, resto distribuido
    if np.random.random() < 0.2:
        release_years.append(np.random.randint(1990, 2000))
    else:
        release_years.append(np.random.randint(1960, 2023))

# duracion
# para peliculas: entre 60 y 180 minutos
# para series: entre 1-8 temporadas

durations = []

for i in range(num_records):
    if types[i] == 'Movie':
        # Concentrar algunas duraciones alrededor de 90 min para el análisis
        if np.random.random() < 0.3:
            durations.append(str(np.random.randint(85, 95)))  # Rango crítico para el proyecto
        else:
            durations.append(str(np.random.randint(60, 180)))
    else:
        durations.append(f'{np.random.randint(1, 9)} Season(s)')


descriptions = [
    'A thrilling adventure about discovery.',
    'A heartwarming story of friendship.',
    'An intense drama about life choices.',
    'A comedy that will make you laugh.',
    'A sci-fi exploration of future technology.',
    'A romantic tale set in a distant land.',
    'A mystery that will keep you guessing.',
    'A documentary about nature.',
    'An action-packed thriller.',
    'A family movie for all ages.'
]

# generos (especialmente accion )

genres = []
for _ in range(num_records):
    all_genres = ['Drama', 'Comedy', 'Action', 'Thriller', 'Romance', 
                  'Documentary', 'Horror', 'Sci-Fi', 'Children & Family']
    # Aumentar probabilidad de 'Action' para el análisis
    weights = [0.15, 0.15, 0.2, 0.1, 0.1, 0.1, 0.05, 0.1, 0.05]
    n_genres = np.random.randint(1, 4) # entre 1 y 3 generos por programa
    selected = np.random.choice(all_genres, size=n_genres, replace=False, p=weights)
    genres.append(', '.join(selected))


# crear el DataFrame

data = {
    'show_id': show_ids,
    'type': types,
    'title': titles,
    'director': directors,
    'cast': casts,
    'country': countries,
    'date_added': dates_added,
    'release_year': release_years,
    'duration': durations,
    'description': np.random.choice(descriptions, size=num_records),
    'genre': genres
}

df = pd.DataFrame(data)


# guardar a CSV
df.to_csv('netflix_data.csv', index=False)

print("Dataset 'netflix_data.csv' generado con éxito.")
print(f'total de registros: {len(df)}')