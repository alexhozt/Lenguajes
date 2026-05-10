"""
Metodo Simplex de Dos Fases
Optimizacion Lineal
"""

import numpy as np
from fractions import Fraction

EPS = 1e-9


def formato(x):
    """Convierte un numero flotante a fraccion o entero para mostrar"""
    if abs(x) < EPS:
        return "0"

    f = Fraction(float(x)).limit_denominator(10000)

    if f.denominator == 1:
        return str(f.numerator)

    return f"{f.numerator}/{f.denominator}"


def leer_int(mensaje):
    """Solicita un numero entero al usuario"""
    while True:
        try:
            return int(input(mensaje))
        except ValueError:
            print("Error: debes ingresar un número entero válido.")


def leer_float(mensaje):
    """Solicita un numero flotante al usuario"""
    while True:
        try:
            return float(input(mensaje))
        except ValueError:
            print("Error: debes ingresar un número válido.")


def leer_signo(mensaje):
    """Solicita el signo de la restriccion (<=, >=, =)"""
    while True:
        signo = input(mensaje).strip()
        if signo in ("<=", ">=", "="):
            return signo
        print("Error: tipo inválido. Debes ingresar <=, >= o =.")


def leer_objetivo(mensaje):
    """Solicita el tipo de optimizacion (max/min)"""
    while True:
        objetivo = input(mensaje).strip().lower()

        if objetivo in ("max", "maximizar", "maximo", "máximo"):
            return "max"

        if objetivo in ("min", "minimizar", "minimo", "mínimo"):
            return "min"

        print("Error: debes escribir max o min.")


def mostrar(T, base, cols):
    """Muestra la tabla simplex actual"""
    print("\n" + "-" * (20 + 12 * len(cols)))
    print(f"{'VB':<8}{'Z':>12}" + "".join(f"{c:>12}" for c in cols) + f"{'LD':>12}")
    print("-" * (20 + 12 * len(cols)))

    for i, (b, fila) in enumerate(zip(base, T)):
        z_col = -1 if i == 0 else 0
        print(
            f"{b:<8}{formato(z_col):>12}" +
            "".join(f"{formato(x):>12}" for x in fila)
        )

    print("-" * (20 + 12 * len(cols)))


def pivotear(T, base, cols, mostrar_pasos=True):
    """Realiza las iteraciones del metodo simplex hasta encontrar la solucion optima"""
    paso = 1

    while np.min(T[0, :-1]) < -EPS:
        col = np.argmin(T[0, :-1])

        positivos = T[1:, col] > EPS

        if not np.any(positivos):
            raise ValueError("El problema no tiene solución acotada.")

        razones = np.full(len(T) - 1, np.inf)
        razones[positivos] = T[1:, -1][positivos] / T[1:, col][positivos]
        fila = np.argmin(razones) + 1

        if mostrar_pasos:
            print(f"\nITERACIÓN {paso}")
            mostrar(T, base, cols)
            print(f"Entra: {cols[col]}")
            print(f"Sale : {base[fila]}")
            print(f"Pivote: {formato(T[fila, col])}")

        base[fila] = cols[col]
        T[fila] /= T[fila, col]

        for i in range(len(T)):
            if i != fila:
                T[i] -= T[i, col] * T[fila]

        paso += 1
    return T, base


def simplex_dos_fases():
    """Funcion principal que implementa el metodo simplex de dos fases"""
    print("=== MÉTODO SIMPLEX DOS FASES ===")

    n = leer_int("Número de variables: ")
    m = leer_int("Número de restricciones: ")
    objetivo = leer_objetivo("¿Deseas maximizar o minimizar Z? (max/min): ")

    c = np.array([
        leer_float(f"Coeficiente de x{i+1} en Z: ")
        for i in range(n)
    ])

    restricciones = []

    for r in range(m):
        print(f"\nRestricción {r+1}")

        coef = np.array([
            leer_float(f"Coeficiente de x{i+1}: ")
            for i in range(n)
        ])

        signo = leer_signo("Tipo <=, >=, =: ")
        b = leer_float("LD: ")

        if b < 0:
            coef, b = -coef, -b
            signo = {"<=": ">=", ">=": "<=", "=": "="}[signo]

        restricciones.append((coef, signo, b))

    h = sum(s == "<=" for _, s, _ in restricciones)
    e = sum(s == ">=" for _, s, _ in restricciones)
    a_count = sum(s in (">=", "=") for _, s, _ in restricciones)

    cols = (
        [f"x{i+1}" for i in range(n)] +
        [f"h{i+1}" for i in range(h)] +
        [f"e{i+1}" for i in range(e)] +
        [f"a{i+1}" for i in range(a_count)]
    )

    total = len(cols)
    T = []
    base = ["Z"]

    ih = ie = ia = 0
    artificiales = []

    for coef, signo, b in restricciones:
        fila = np.zeros(total + 1)
        fila[:n] = coef
        fila[-1] = b

        if signo == "<=":
            fila[n + ih] = 1
            base.append(f"h{ih+1}")
            ih += 1

        elif signo == ">=":
            fila[n + h + ie] = -1
            ie += 1

            pos = n + h + e + ia
            fila[pos] = 1
            artificiales.append(pos)

            base.append(f"a{ia+1}")
            ia += 1

        elif signo == "=":
            pos = n + h + e + ia
            fila[pos] = 1
            artificiales.append(pos)

            base.append(f"a{ia+1}")
            ia += 1

        T.append(fila)

    T = np.array(T, dtype=float)

    # FASE 1: Minimizar suma de variables artificiales
    Z = np.zeros(total + 1)
    Z[artificiales] = 1

    T = np.vstack([Z, T])

    for i, b in enumerate(base[1:], start=1):
        if b.startswith("a"):
            T[0] -= T[i]

    print("\nTABLA INICIAL FASE 1")
    mostrar(T, base, cols)

    T, base = pivotear(T, base, cols)

    print("\nFIN FASE 1")
    mostrar(T, base, cols)

    if abs(T[0, -1]) > 1e-6:
        print("\nEl problema no tiene solución factible.")
        return

    # Eliminar columnas artificiales
    T = np.delete(T, artificiales, axis=1)
    cols = [c for i, c in enumerate(cols) if i not in artificiales]

    # Eliminar fila Z/W de fase 1
    T = T[1:]
    base = base[1:]

    # FASE 2: Optimizar funcion objetivo original
    Z = np.zeros(T.shape[1])

    if objetivo == "max":
        Z[:n] = -c
    else:
        Z[:n] = c

    T = np.vstack([Z, T])
    base = ["Z"] + base

    # Canonizar Z segun la base actual
    for i, b in enumerate(base[1:], start=1):
        if b.startswith("x"):
            j = cols.index(b)
            T[0] -= T[0, j] * T[i]

    print("\nTABLA INICIAL FASE 2")
    mostrar(T, base, cols)

    T, base = pivotear(T, base, cols)

    print("\nTABLA FINAL")
    mostrar(T, base, cols)

    valores = {f"x{i+1}": 0 for i in range(n)}

    for i, b in enumerate(base[1:], start=1):
        if b in valores:
            valores[b] = T[i, -1]

    print("\nSOLUCIÓN:")
    for var, val in valores.items():
        print(f"{var} = {formato(val)}")

    if objetivo == "max":
        print(f"Z máximo = {formato(T[0, -1])}")
    else:
        print(f"Z mínimo = {formato(-T[0, -1])}")


if __name__ == "__main__":
    simplex_dos_fases()