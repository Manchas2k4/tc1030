![Tec de Monterrey](images/logotecmty.png)
# Situación problema: Simulación de un mercado de valores

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás una serie de carpetas y archivos que necesitarás para el desarrollo del proyecto.
* *test_cases*: En este directorio encontrarás los archivos de entrada (*input0.txt*, *input1.txt*, *input2.txt*, *input3.txt*, *input4.txt*) que utilizaremos para probar el sistema completo. Adicionalmente están las salida esperadas para cada uno de los archivos de entrada (*output0.txt*, *output1.txt*, *output2.txt*, *output3.txt*, *output4.txt*).
* *unit_test*: En este directorio se encuentran los archivos de pruebas de unidad para cada una de las clases que tienes que desarrollar. Estos archivos de prueba te permiten verificar si tu implementación es correcta.
* *archivos cabecera (o header)*: Archivos en los que se realiza la implementación de cada clase.
* *main.cpp*: Archivo que contiene la función *main*. En este archivo se realiza la lectura/escritura de archivos.

En estos archivos deberás desarrollar la implementación de cada una de las clases que integran la solución del problema presentado en esta actividad. En la parte superior de cada archivo coloca deberás, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: one_header.h
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// Description: This file implements some functions.
// =========================================================
```

## <span style="color: rgb(26, 99, 169);">Introducción</span>
La economía es un hecho indispensable de nuestras vidas. En la vida real, para comprar y vender cosas, usamos algunos activos impresos o virtuales, llamados dinero. Sin embargo, los billetes en tu bolsillo no tiene ninguna diferencia con un pedazo de papel. Obtiene su valor sólo en un mercado.

En este proyecto, implementarás un modelo de mercado básico. Este modelo consta de *comerciantes*, *billeteras*, *transacciones*, *divisas* y un *mercado*. Para simplificar, tenemos dos monedas en el mercado: *dólar* y *PQoin* (Priority Queue Coin). Los comerciantes pueden dar órdenes de compra o venta al mercado si pueden pagarlas.

En nuestro modelo de mercado, hay dos filas ordenadas por prioridad para almacenar pedidos. En una fila de prioridad, los elementos que tienen la prioridad más alta estarán al frente. Las reglas de prioridad se escriben en las siguientes secciones. Con estas reglas, su implementación de mercado debería realizar transacciones si los primeros elementos de estas files de prioridad se superponen.

Ten en cuenta que no hay ninguna interacción con el usuario durante la ejecución. Tu solución tomará la entrada de un archivo de texto, realizará las operaciones e imprimirá la información necesario en un archivo de texto de salida. El nombre de ambos archivos, los tomará como argumento del programa. En otras palabras, **no habrá ninguna entrada dada con el teclado mientras se ejecuta el programa**.

Ten en cuenta que habrá varias clases. Por lo tanto, trabajarás con varios archivos cabecera (o header). Los nombres de las variables de instancia y métodos se proporcionarán en este documento, así como en el encabezado de la clase que se encuentra en cada archivo cabecera. Aunque esto no significa que no puedas agregar métodos o campos adicionales.

### <span style="color: rgb(26, 99, 169);">**Clases**</span>
Existen 6 clases interactuando entre sí en este proyecto:
* `Order`.
* `SellingOrder` (derivado de `Order`)
* `BuyingOrder` (derivado de `Order`)
* `Transaction`
* `Wallet`
* `Trader`
* `Market`.

Ten en cuenta que será necesario hacer los cálculos necesarios mediante el uso de los métodos correspondiente en las clases `Order` (o derivados), `Wallet`, `Trader` o `Market`, no en el programa principal.

#### <span style="color: rgb(26, 99, 169);">**Order**</span>
La clase `Order` cuenta con las siguientes variables de estado:
* `traderId`: Identificador del comerciante que generó la orden.
* `amount`: Cantidad a comprar.
* `price`: Precio al que se quiere comprar.
* `type`: Tipo de order (venta, compra).

La clase cuenta con los siguientes métodos:
* Constructor con cuatro parámetro (identificador, cantidad, precio, tipo de orden).
* Constructor de copia.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `double getDollar() const`: El costo, en dólares, de la orden. Se calcula multiplicando el precio por la cantidad a comprar.
* `bool operator==(const Order *right)`: Regresa `true`, si el tipo, identificador, cantidad y precio son los mismos.
* `bool operator==(const Order &right)`: Regresa `true`, si el tipo, identificador, cantidad y precio son los mismos.
* `virtual bool operator<(const Container *right) = 0`: Función abstracta. Se implementará en clases derivadas.
* `virtual bool operator<(const Container &right) = 0`: Función abstracta. Se implementará en clases derivadas.

#### <span style="color: rgb(26, 99, 169);">**SellingOrder**</span>
La clase `SellingOrder`, derivada de `Order`, no tiene ninguna variable de instancia propia. Sin embargo, cuenta con los siguientes métodos:
* Constructor con tres parámetro (identificador, cantidad y precio). Invoca al constructor de la clase superior, indicando el tipo de contenedor correcto.
* Constructor de copia. Invoca al constructor de la clase superior.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `bool operator<(const Container *right)`: Si el tipo de nuestra orden es diferente a la de `right`, regresa si nuestro tipo es **menor** o no. Si el precio de nuestra orden es diferente al de `right`, regresa si nuestro precio es **menor** o no. Si la cantidad de nuestra orden es diferente a la de `right`, regresa si nuestra cantidad es **mayor** o no. Si no fue ninguno de los casos previos, regres si nuestro identificador es **menor** o no.
* `bool operator<(const Container &right)`: Emplea la misma lógica que el método anterior.

#### <span style="color: rgb(26, 99, 169);">**BuyingOrder**</span>
La clase `BuyingOrder`, derivada de `Order`, no tiene ninguna variable de instancia propia. Sin embargo, cuenta con los siguientes métodos:
* Constructor con tres parámetro (identificador, cantidad y precio). Invoca al constructor de la clase superior, indicando el tipo de contenedor correcto.
* Constructor de copia. Invoca al constructor de la clase superior.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `bool operator<(const Container *right)`: Si el tipo de nuestra orden es diferente a la de `right`, regresa si nuestro tipo es **menor** o no. Si el precio de nuestra orden es diferente al de `right`, regresa si nuestro precio es **mayor** o no. Si la cantidad de nuestra orden es diferente a la de `right`, regresa si nuestra cantidad es **mayor** o no. Si no fue ninguno de los casos previos, regres si nuestro identificador es **menor** o no.
* `bool operator<(const Container &right)`: Emplea la misma lógica que el método anterior.

#### <span style="color: rgb(26, 99, 169);">**Transaction**</span>
La clase `Transaction` cuenta con las siguientes variables de estado:
* `sellingOrder`: Apuntador a un objeto de la clase `SellingOrder`.
* `buyingOrder`: Apuntador a un objeto de la clase `BuyingOrder`.

La clase cuenta con los siguientes métodos:
* Constructor con dos parámetros (apuntador a `SellingOrder` y apuntador a `BuyingOrder`).
* Constructor de copia.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).

#### <span style="color: rgb(26, 99, 169);">**Wallet**</span>
La clase `Wallet` cuenta con las siguientes variables de estado:
* `dollars`: Dólares disponibles.
* `coins`: PQCoins disponibles.
* `blockedDollars`: Dólares bloqueados por transacciones que no se han procesado.
* `blockedCoins`: PQCoins bloqueadas por transacciones que no se han procesado.

La clase cuenta con los siguientes métodos:
* Constructor con dos parámetros (dólares y monedas).
* Constructor de copia.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `void depositDollars(double amount)`: Si la cantidad recibida es positiva, la agrega a la cantidad de dólares disponibles.
* `void depositCoins(double amount)`: Si la cantidad recibida es positiva, la agrega a la cantidad de PQCoins disponibles.
* `void withdrawDollars(double amount)`: Si la cantidad recibida es positiva, resta esa cantidad de los dólares disponibles.
* `void blockDollars(double amount)`: Si la cantidad recibida es positiva, elimina esa cantidad de los dólares disponibles y la agrega a los bloqueados.
* `void blockCoins(double amount)`: Si la cantidad recibida es positiva, elimina esa cantidad de las PQCoins disponibles y la agrega a las bloqueadas.
* `void returnDollars(double amount)`: Si la cantidad recibida es positiva, elimina esa cantidad de los dólares bloquedos y la agrega a los disponibles.
* `void payFromBlockedDollars(double amount)`: Si la cantidad recibida es positiva, elimina esa cantidad de los dólares bloquedos.
* `void payFromBlockedCoins(double amount)`: Si la cantidad recibida es positiva, elimina esa cantidad de las PQCoins bloquedas.
* `bool checkWithDraw(double amount)`: Si la cantidad recibida es positiva, regresa verdadero si la cantidad es menor a la cantidad de dólares disponibles.
* `bool checkSelling(double amount)`: Si la cantidad recibida es positiva, regresa verdadero si la cantidad es menor a la cantidad de PQCoins disponibles.
* `bool checkBlockedDollars(double amount)`: Si la cantidad recibida es positiva, regresa verdadero si la cantidad es menor a la cantidad de dólares bloqueados.
* `bool checkBlockedCoins(double amount)`: Si la cantidad recibida es positiva, regresa verdadero si la cantidad es menor a la cantidad de PQCoins bloquedas.
* `std::string toString() const`: Regresa un string con el siguiente formato: `<amount1>$ <amount2>PQ`, donde `amount1` es la cantida total de dólares (disponibles y bloquedos) y `amount2` es la cantidad total de PQCoins (disponibles y bloquedas).

#### <span style="color: rgb(26, 99, 169);">**Trader**</span>
La clase `Trader` cuenta con las siguientes variables de estado:
* `id`: Identificador del comerciantes.
* `waller`: Un apuntador a la cartera de ese comerciante.

**IMPORTANTE**: Existe un comerciante `0` que representa el mercado.

La clase cuenta con los siguientes métodos:
* Constructor con tres parámetros (identificador, dólares y monedas).
* Constructor de copia.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `bool sell(double amount, double price, int marketFee)`: Este método verifica si un comerciante puede vender PCoins. Se dice que pude vender, si la cantidad recibida es menor a la cantidad de PCoins bloquedadas o si el identificador es igual a 0. Si el comerciante puede vender, deberá pagar esa cantidad con PCoins bloqueadas y transferir los dólares que resultan de vender cantidad de PCoins al precio indicado, menos el porcentaje que retiene el mercado. Regresa si el comerciante pudo vender o no.
* `bool buy(double amount, double price, int marketFee)`: Este método verifica si un comerciante puede comprar PCoins. Se dice que pude comprar, si los dólares bloquedos es menor a la cantidad de PCoins que quiere comprar en el precio indicado o si el identificador es 0. Si el comerciante pueden comrar, deberá pagar esa cantidad con los dólares bloqueados y depositar la cantidad de PCoins a su cartera. Regresa si el comerciante pudo comprar o no.
* `bool Trader::operator==(const Trader *left)`: Regresa verdadero si nuestro identificador y el del apuntador `left` son iguales.
* `bool Trader::operator==(const Trader &left)`: Regresa verdadero si nuestro identificador y el del objeto `left` son iguales.
* `std::string toString() const`: Regresa un string con el siguiente formato: `Trader <id>: <walletString>`, donde `walletString` es la cadena que regresa el `toString` de wallet.

#### <span style="color: rgb(26, 99, 169);">**Market**</span>
La clase `Market` cuenta con las siguientes variables de estado:
* `sellingOrders`: Una fila priorizada de órdenes de venta.
* `buyingOrders`: Una fila priorizada de órdenes de compra.
* `transactions`: Una lista de transacciones realizadas.
* `fee`: El porcentaje que cobra el mercado al vendedor por transacción realizada.
* `noOfSuccessfulTransactions`: Número de transacciones existosas.

La clase cuenta con los siguientes métodos:
* Constructor con un parámetro (porcentaje). Inicialmente consideramos que no existen transacciones exitosas.
* Métodos de acceso para todas las variables de instancia. (Si consideras necesario agregar métodos de modificación, adelante).
* `void addSellingOrder(SellingOrder *s)`: Agrega un nuevo elemento a la fila de órdenes de venta.
* `void addBuyingOrder(BuyingOrder *b))`: Agrega un nuevo elemento a la fila de órdenes de compra.
* `void topBuyingPrice() const`: Si la fila de órdenes de compra no está vacía, regresa el elemento que está al frente. En caso contrario, regresa 0.
* `void topSellingPrice() const`: Si la fila de órdenes de venta no está vacía, regresa el elemento que está al frente. En caso contrario, regresa 0.
* `makeOpenMarketOperation(double price, std::vector<Trader*> &traders)`: Primero, mientras la fila de órdenes de compra no este vacía y el precio de venta sea mayor o igual al precio indicado, adjudica una venta al mercado (Trader 0) por el precio y la cantidad indicada; por último, revisa las transacciones realizada. Posteriormente, mientras la fila de órdenes de venta no este vacía y el precio de venta sea menor o igual  al precio indicado, adjudica una compra al mercado (Trader 0) por el precio y la cantidad indicada; por último, revisa las transacciones realizada.
* `checkTransactions(std::vector<Trader*> &traders)`: Primero, mientras existan ventas y compras pendientes y el precio de compra sea mayor o igual al precio de venta, se obtienen (y remueven) la compra y venta "top" y se determina la cantidad de PCoins en la transacción. Si la cantidad a vender es mayor a la cantidad a compra, sólo se considera la cantidad a comprar y se genera una nueva venta por la cantidad restante. De manera similar, si la cantidad a comprar a mayor a la cantidad a vender, sólo se considera la cantidad a vender y se genera una nueva compra por la cantidad restante. A continuación, se verifica si el comprador y vendedor pueden realizar la acción. Si es así, se determina que hubo una transacción exitosa. En seguido, si edl precio de comprar es myor al precio de venta, se regresa al venderdor la cantidad de dólares que representa la diferencia de precios por la cantidad comerciada. Por último, se agrega una transacción a la lista de transacciones.
* `marketInfo() const`: Regresa un string con el siguiente formato: `Current market size: <totalDollar> <totalPCoins>`, donde `<totalDollar>` es la cantidad de dólares que se obtendrán de todas las órdenes de compra y `<totalPCoins>` es la cantidad de monedas que se negociarán con todas las órdenes de venta.
* `currentPriceInfo() const`: Regresa un string con el siguiente formato: `Current prices: <buyingOrderPrice> <sellingOrderPrice> <averagePrice>`, donde `<buyingOrderPrice>` es el precio más alto ("top") de compra, `<sellingOrderPrice>` es el precio más alto de venta y `<averagePrice>` se determina de la siguiente manera. Si no hay acciones a la venta y compra, `<averagePrice>` es 0. Si no hay órdenes de venta pero si hay a la compra, `<averagePrice>` será el precio de compra más alto. Si no hay órdenes de compra pero si hay a la venta, `<averagePrice>` será el precio de venta más alto. En caso de existir tanto órdenes de compra como de venta, será un promedio de los precios más altos.
* `transactionInfo() const`: Regresa un string con el siguiente formato: `Number of successful transactions:  <noOfSuccessfulTransactions>`, donde `<noOfSuccessfulTransactions>` es el valor actual de noOfSuccessfulTransactions.

#### <span style="color: rgb(26, 99, 169);">**main.cpp**</span>
En el archivo *main.cpp* se realizarán las operaciones generales de entrada y salida. Leerás de un archivo de entrada las operaciones sobre la simulación, las deberás realizar e imprimirás los resultados en el archivo de salida.

Las operaciones se detallan más adelante. El nombre de los archivos de entrada y salida se darán como argumentos del programa a través de la línea de comandos. Si el archivo de entrada no existe, el programa termina.

Deberás manejar un apuntador a un objeto `Market` y un vector de apuntadores a objetos `Trader`. **Adicionalmente, deberás considerar una variablea que indique la cantidad de transacciones inválidas. Por lo mismo, deben ser inicializa a 0.**

#### <span style="color: rgb(26, 99, 169);">**Entrada**</span>
Vas a leer el archivo de entrada elemento por elemento.

La primera línea tiene cuatro números enteros, `A`, `B`, `C` y `D`. El número `A` representa la semilla de los números aleatorios que se utilizarán en la simulación. El segundo número, `B`, indica el porcentaje que cobrará el mercado. El tercer número, `C`, indica el número de de usuarios. Y, por último, `D`, representa el número de eventos a simular.

Las siguientes 'C' línea serán los datos para crear un comerciante: cantidad de dólares y PCoins. Toma en cuenta que el identificador del comerciante será el orden de creación. Por ejemplo, el primer comerciantes creado debe tener Id 0 y debe colocarse en la posición 0 del vector. Recuerda que el comerciante 0 es muy especial, ya que representa al mercado de valores.

A continuación, hay `D` líneas. Éstas indicarán alguna de las siguientes operaciones:
1. Dar orden de compra de precio específico.
2. Dar orden de compra a precio de mercado.
3. Dar orden de venta de precio específico.
4. Dar orden de venta de precio de mercado.
5. Depositar una cierta cantidad de dólares en una cartera.
6. Retirar cierta cantidad de dólares de una cartera.
7. Imprimir el estado de una cartera.
8. Dar recompensas a todos los comerciantes.
9. Hacer una operación de mercado abierto.
10. Imprime el tamaño actual del mercado.
11. Imprimir número de transacciones exitosas.
12. Imprimir el número de consultas no válidas.
13. Imprimir los precios actuales.
14. Imprimir el estado de las carteras de todos los comerciantes.

##### <span style="color: rgb(26, 99, 169);">**1. Dar orden de compra de precio específico**</span>
Esta línea contiene un 10, seguido del identificador del comerciante, el precio y la cantidad.
```
10 <traderId> <price> <amount>
```
Deberás agregar una nueva orden de compra con los valores recibidos.

##### <span style="color: rgb(26, 99, 169);">**2. Dar orden de compra a precio de mercado**</span>
Esta línea contiene un 11, seguido del identificador del comerciante y la cantidad.
```
11 <traderId> <amount>
```
Es similar a la orden anterior, pero deberás tomar como referencia el precio más alto. Si no existen órdenes de compra, deberás indicar esta transacción como inválida.

##### <span style="color: rgb(26, 99, 169);">**3. Dar orden de venta de precio específico**</span>
Esta línea contiene un 20, seguido del identificador del comerciante, el precio y la cantidad.
```
20 <traderId> <price> <amount>
```
Deberás agregar una nueva orden de venta con los valores recibidos.

##### <span style="color: rgb(26, 99, 169);">**4. Dar orden de venta de precio de mercado**</span>
Esta línea contiene un 21, seguido del identificador del comerciante y la cantidad.
```
21 <traderId> <amount>
```
Es similar a la orden anterior, pero deberás tomar como referencia el precio más alto. Si no existen órdenes de venta, deberás indicar esta transacción como inválida.

##### <span style="color: rgb(26, 99, 169);">**5. Depositar una cierta cantidad de dólares en una cartera**</span>
Esta línea contiene un 3, seguido de la posición `x` y `y` del puerto.

```
3 <traderId> <amount>
```

##### <span style="color: rgb(26, 99, 169);">**6. Retirar cierta cantidad de dólares de una cartera**</span>
Esta línea contiene un 4, seguido del id de la nave y el id del contenedor.

```
4 <traderId> <amount>
```

##### <span style="color: rgb(26, 99, 169);">**7. Imprimir el estado de una cartera**</span>
Esta línea contiene un 5, seguido del id de la nave y el id del contenedor.

```
5 <tradeId>
```

##### <span style="color: rgb(26, 99, 169);">**8. Dar recompensas a todos los comerciantes**</span>
Esta línea contiene sólo un 777.

```
777
```
Cuando se ejecuta esta consulta, el sistema crea y distribuye cantidad aleatorias de PCoins a todos los comerciantes. Utiliza la siguiente fórmula para generar los valores aleatorios: `((double) rand() / (double) RAND_MAX) * 100.0`.

##### <span style="color: rgb(26, 99, 169);">**9. Hacer una operación de mercado abierto**</span>
Esta línea contiene sólo un 66.

```
666
```
Se ejecuta una operación de mercado abierto.

##### <span style="color: rgb(26, 99, 169);">**10. Imprime el tamaño actual del mercado**</span>
Esta línea contiene sólo un 500.

```
500
```

##### <span style="color: rgb(26, 99, 169);">**11. Imprimir número de transacciones exitosas**</span>
Esta línea contiene sólo un 501.

```
501
```

##### <span style="color: rgb(26, 99, 169);">**12. Imprimir el número de consultas no válidas**</span>
Esta línea contiene sólo un 502.

```
502
```

##### <span style="color: rgb(26, 99, 169);">**13. Imprimir los precios actuales**</span>
Esta línea contiene sólo un 505.

```
505
```

##### <span style="color: rgb(26, 99, 169);">**14. Imprimir el estado de las carteras de todos los comerciantes**</span>
Esta línea contiene sólo un 555.

```
555
```
