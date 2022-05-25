![Tec de Monterrey](../../images/logotecmty.png)

# implementación de números racionales

## <span style="color: rgb(26, 99, 169);">Introducción</span>
Los números racionales son todos los números que pueden representarse como el cociente de dos números enteros o, más exactamente, un entero y un natural positivo;​ es decir, una fracción común $\frac{a}{b}$ con numerador $a$ y denominador $b$  distinto de cero. El término *racional* alude a una fracción o parte de un todo. ([Wikipedia](https://es.wikipedia.org/wiki/N%C3%BAmero_racional).)

En este ejercicio, implementaremos una clase que nos permita manejar números racionales en C/C++.

Nuestra implementación no tendrá ninguna interacción con el usuario durante la ejecución. La solución tomará la entrada de un archivo de texto, realizará las operaciones e imprimirá la información necesario en un archivo de texto de salida. El nombre de ambos archivos, los tomará como argumento del programa. En otras palabras, **no habrá ninguna entrada dada con el teclado mientras se ejecuta el programa**.

La clase que vamos a desarrollar contará con los elementos básicos esperados: distintos constructores, métodos de acceso y modificación; así como métodos para sumar, restas, multiplicar y dividir números racionales. La clase se implementará en el archivo cabecera (o header) correspondiente.

#### <span style="color: rgb(26, 99, 169);">**main.cpp**</span>
En el archivo *main.cpp* se realizarán las operaciones generales de entrada y salida. Leeremos de un archivo de entrada las operaciones sobre la simulación, las realizaremos e imprimiremos los resultados en el archivo de salida.

Las operaciones se detallan más adelante. El nombre de los archivos de entrada y salida se darán como argumentos del programa a través de la línea de comandos. Si el archivo de entrada no existe, el programa termina.

#### <span style="color: rgb(26, 99, 169);">**Entrada**</span>
Vas a leer el archivo de entrada elemento por elemento.

La primera línea tiene un número entero, `N`. El número `N` representa el número de operaciones a realizar.

A continuación, vendrán `N` líneas. Éstas indicarán alguna de las siguientes operaciones:
1. Sumar dos números racionales.
2. Restar dos números racionales.
3. Multiplicar dos números racionales.
4. Dividir dos números racionales.
5. Comparar si el número racional r1 es igual al número racional r2.
6. Comparar si el número racional r1 es menor al número racional r2.

##### <span style="color: rgb(26, 99, 169);">**1. Sumar dos números racionales.**</span>
Esta línea contiene un 1, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
1 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
num / dem
```

##### <span style="color: rgb(26, 99, 169);">**2. Restar dos números racionales.**</span>
Esta línea contiene un 2, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
2 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
num / dem
```

##### <span style="color: rgb(26, 99, 169);">**3. Multiplicar dos números racionales.**</span>
Esta línea contiene un 3, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
3 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
num / dem
```

##### <span style="color: rgb(26, 99, 169);">**4. Dividir dos números racionales.**</span>
Esta línea contiene un 4, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
4 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
num / dem
```

##### <span style="color: rgb(26, 99, 169);">**5. Comparar si el número racional r1 es igual al número racional r2.**</span>
Esta línea contiene un 5, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
5 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
true / false
```

##### <span style="color: rgb(26, 99, 169);">**6. Comparar si el número racional r1 es menor al número racional r2.**</span>
Esta línea contiene un 5, seguido del numerador y denominador del primer números y, a continuación el numerador y denominador del segundo número.
```
6 <num1> <dem1> <num2> <dem2>
```
Desplegaremos, en el archivo de salida, el resultado de la operación en el siguiente formato:
```
true / false
```
