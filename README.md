# CPP Module 09 - STL Containers

Este proyecto implementa tres programas diferentes que utilizan contenedores STL de C++. Cada ejercicio se centra en el uso de diferentes contenedores y algoritmos.

## 📋 Tabla de Contenidos

- [Ejercicio 00: Bitcoin Exchange](#ejercicio-00-bitcoin-exchange)
- [Ejercicio 01: Reverse Polish Notation](#ejercicio-01-reverse-polish-notation)
- [Ejercicio 02: PmergeMe](#ejercicio-02-pmergeme)
- [Compilación](#compilación)
- [Uso](#uso)
- [Requisitos](#requisitos)

---

## Ejercicio 00: Bitcoin Exchange

### 📖 Descripción
Programa que calcula el valor de bitcoins en una fecha específica usando una base de datos histórica de precios.

### 🔧 Contenedores Utilizados
- `std::map<std::string, float>` - Para almacenar la base de datos de precios por fecha

### 📁 Archivos
```
ex00/
├── BitcoinExchange.hpp    # Clase principal
├── BitcoinExchange.cpp    # Implementación
├── main.cpp              # Punto de entrada
├── Makefile              # Script de compilación
└── data.csv              # Base de datos de precios (requerido)
```

### ⚙️ Funcionalidades

#### Clase BitcoinExchange
- **Constructor por defecto**: Carga automáticamente la base de datos desde `data.csv`
- **Constructor de copia**: Implementación de Orthodox Canonical Form
- **Operador de asignación**: Copia segura de la base de datos
- **Destructor**: Limpieza automática

#### Métodos Principales
- `void getData()`: Carga datos desde data.csv
- `void calculateBalance(const char *inFile)`: Procesa archivo de entrada
- `bool checkDate(const std::string date)`: Valida formato y rango de fechas

### 📝 Formato de Entrada
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

### 📤 Formato de Salida
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

### 🚫 Validaciones
- **Fechas**: Formato YYYY-MM-DD, rango 2009-01-02 a 2022-03-29
- **Valores**: Entre 0 y 1000
- **Formato**: Debe usar " | " como separador
- **Números**: Validación de formato numérico correcto

### 🏗️ Compilación
```bash
cd ex00
make
```

### 🚀 Uso
```bash
./btc input.txt
```

---

## Ejercicio 01: Reverse Polish Notation

### 📖 Descripción
Calculadora que evalúa expresiones matemáticas en notación polaca inversa (RPN).

### 🔧 Contenedores Utilizados
- `std::stack<int>` - Para manejar operandos en notación RPN

### 📁 Archivos
```
ex01/
├── RPN.hpp        # Clase calculadora RPN
├── RPN.cpp        # Implementación
├── main.cpp       # Punto de entrada
└── Makefile       # Script de compilación
```

### ⚙️ Funcionalidades

#### Clase RPN
- **Constructor por defecto**: Inicializa stack vacío
- **Constructor de copia**: Orthodox Canonical Form
- **Operador de asignación**: Copia segura del stack
- **Destructor**: Limpieza automática

#### Métodos Principales
- `bool parseInput(const std::string& input)`: Valida entrada
- `std::string createTokens(const std::string& input)`: Limpia espacios
- `int performRpnOperation(const std::string& input)`: Evalúa expresión RPN

### 📝 Funcionamiento RPN
La notación polaca inversa coloca los operadores después de los operandos:
- Expresión normal: `(1 + 2) * 3`
- RPN equivalente: `1 2 + 3 *`

### 📤 Ejemplos de Uso
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"    # Resultado: 42
./RPN "7 7 * 7 -"                     # Resultado: 42
./RPN "1 2 * 2 / 2 * 2 4 - +"        # Resultado: 0
./RPN "(1 + 1)"                       # Error
```

### 🚫 Validaciones
- **Números**: Solo dígitos 0-9
- **Operadores**: +, -, *, /
- **Formato**: Elementos separados por espacios
- **Stack**: Debe quedar exactamente un elemento al final

### 🏗️ Compilación
```bash
cd ex01
make
```

### 🚀 Uso
```bash
./RPN "expresión_rpn"
```

---

## Ejercicio 02: PmergeMe

### 📖 Descripción
Programa que ordena secuencias de enteros usando el algoritmo de ordenamiento Ford-Johnson (merge-insertion sort) con dos contenedores diferentes para comparar rendimiento.

### 🔧 Contenedores Utilizados
- `std::vector<int>` - Contenedor de acceso aleatorio
- `std::deque<int>` - Contenedor de doble cola

### 📁 Archivos
```
ex02/
├── PmergeMe.hpp     # Clase de ordenamiento
├── PmergeMe.cpp     # Implementación
├── main.cpp         # Punto de entrada
└── Makefile         # Script de compilación
```

### ⚙️ Funcionalidades

#### Clase PmergeMe
- **Constructor parametrizado**: Acepta argumentos de línea de comandos
- **Constructores privados**: Previene construcción no autorizada
- **Destructor**: Limpieza automática

#### Métodos Principales
- `void algorithm()`: Ejecuta algoritmo en ambos contenedores
- `void mergeVec(std::vector<int> &vec)`: Merge sort para vector
- `void mergeDeq(std::deque<int> &deq)`: Merge sort para deque
- `void insertVec(std::vector<int> &vec)`: Insertion sort para vector
- `void insertDeq(std::deque<int> &deq)`: Insertion sort para deque

### 📊 Algoritmo Ford-Johnson
1. **Umbral pequeño** (≤7 elementos): Insertion sort
2. **Secuencias grandes** (>7 elementos): Merge sort recursivo
3. **Medición de tiempo**: Compara rendimiento entre contenedores

### 📤 Formato de Salida
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 ms
Time to process a range of 5 elements with std::deque : 0.00014 ms
```

### 🚫 Validaciones
- **Números positivos**: Solo enteros > 0
- **Sin duplicados**: Cada número debe ser único
- **Rango válido**: Números dentro del rango de int
- **Formato**: Solo dígitos, sin caracteres especiales

### 🏗️ Compilación
```bash
cd ex02
make
```

### 🚀 Uso
```bash
./PmergeMe 3 5 9 7 4
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

---

## 🔨 Compilación

### Compilar Todo el Proyecto
```bash
# Compilar todos los ejercicios
for ex in ex00 ex01 ex02; do
    cd $ex && make && cd ..
done
```

### Comandos Makefile Disponibles
```bash
make        # Compila el ejercicio
make all    # Alias de make
make clean  # Limpia archivos objeto
make fclean # Limpia todo (objetos + ejecutable)
make re     # Recompila todo (fclean + all)
```

---

## 📋 Requisitos

### Técnicos
- **Compilador**: c++ (g++ o clang++)
- **Standard**: C++98
- **Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Orthodox Canonical Form**: Todos las clases lo implementan

### Contenedores STL Utilizados
- `std::map` - Ejercicio 00
- `std::stack` - Ejercicio 01  
- `std::vector` y `std::deque` - Ejercicio 02

### Características Destacadas
- ✅ **Manejo de errores robusto**
- ✅ **Validación completa de entrada**
- ✅ **Optimización de algoritmos**
- ✅ **Medición de rendimiento**
- ✅ **Cumple normas de 42**

---

## 🧪 Testing

### Ejercicio 00 - Bitcoin Exchange
```bash
# Crear archivo de prueba
echo -e "date | value\n2011-01-03 | 3\n2011-01-03 | 2\n2012-01-11 | 1" > test.txt
./btc test.txt
```

### Ejercicio 01 - RPN Calculator
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
```

### Ejercicio 02 - PmergeMe
```bash
./PmergeMe 3 5 9 7 4
./PmergeMe `seq 1 100 | shuf | tr '\n' ' '`
```

---

## 📝 Notas Importantes

- Todos los ejercicios manejan casos edge correctamente
- La validación de entrada es exhaustiva
- Los algoritmos están optimizados para el tipo de contenedor usado
- El código sigue las normas de 42 School
- Implementación completa de Orthodox Canonical Form

---

**Autor**
Iker Portillo
