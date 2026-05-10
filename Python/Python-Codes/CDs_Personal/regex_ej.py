# ejemplo de regex en Python

import pandas as pd
import re

df = pd.DataFrame({
    'Marca de teléfono': ['Manzana', 'Samsung', 'Manzana', 'Samsung', 'Google', 'OnePlus'],
    'Modelo': ['iPhone 13 Pro', 'Galaxy S22', 'iPhone 13', 'Galaxy S22 Pro', 'Pixel 6 Pro', 'OnePlus 10'],
    'Precio': [999, 899, 799, 1099, 899, 749]
})


print("DataFrame original:")
print(df)
print("\n" + "=="*50)


# patron de regex
pattern = r'Pro'

# filtrar usando regex
filtered_df = df[df['Modelo'].str.contains(pattern, regex=True)]

print("modelos que contienen 'Pro':")
print(filtered_df)

# mostrar que esta haciendo internamente

print("\n" + "=="*50)
print("analisis paso a paso:")

for modelo in df['Modelo']:
    resultado = re.search(pattern, modelo)
    if resultado:
        print(f"{modelo} -> contiene 'Pro'")
    else:
        print(f"{modelo} -> no contiene 'Pro'")

