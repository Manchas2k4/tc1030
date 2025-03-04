![Tec de Monterrey](../../images/logotecmty.png)
# Actividad:

## Objetivo:
En esta actividad, comprenderás e implementarás una jerarquía de clases utilizando los conceptos de programación orientada a objetos como herencia, polimorfismo y sobrecarga de operadores.

### La Escuela de Magia
En una tierra mágica lejana, existe una prestigiosa escuela de magia donde los jóvenes brujos y brujas entrenan para convertirse en los más grandes hechiceros del reino. En esta escuela, los estudiantes aprenden a dominar una amplia gama de hechizos que abarcan desde poderosos ataques hasta protecciones impenetrables y curaciones milagrosas.

Cada estudiante comienza su jornada aprendiendo los fundamentos de la magia, pero a medida que avanzan, se les enseña a lanzar hechizos más complejos y efectivos. Para ello, la escuela ha desarrollado un grimorio digital, una especie de libro mágico interactivo, que permite a los estudiantes practicar y perfeccionar sus habilidades con diferentes hechizos.

### Actividades:
1. Desarrolla la Clase Spell:
    * La clase Spell es una clase abstracta que define tres métodos virtuales puros: getPower(), launch(), y toString().
    * Sobrecarga los operadores < y == para comparar objetos de tipo Spell basados en su poder (getPower()).
2. Desarrolla las Clases Derivadas:
    * Hay tres clases derivadas: AttackSpell, DefenseSpell, y HealingSpell, cada una con atributos específicos (daño, defensa, curación, respectivamente).
    * Cada clase derivada implementa los métodos virtuales definidos en la clase base (getPower(), launch(), y toString()).

#### Clase AttackSpell
La clase AttackSpell es una clase derivada de la clase abstracta Spell, que representa un tipo de hechizo de ataque. A continuación, se describe en detalle su estructura y funcionalidad.

Atributos Privados:
* int basicDamage: Este atributo almacena el daño básico que puede causar el hechizo. 
* int realDamage: Este atributo almacena el daño real que se determinará en el método launch() con una variabilidad aleatoria. 

Constructores:
1. Constructor por Defecto:
    * Inicializa basicDamage y realDamage a 1. 
    * Llama a srand(time(0)) para inicializar el generador de números aleatorios. 
2. Constructor de Copia:
    * Copia los valores de basicDamage y realDamage de otro objeto AttackSpell. 
    * También inicializa el generador de números aleatorios. 
3. Constructor con Parámetro:
    * Inicializa basicDamage y realDamage con el valor proporcionado en el parámetro.
    * Inicializa el generador de números aleatorios. 

Métodos Públicos:
1. getPower() const:
    * Retorna el valor de basicDamage, que representa el poder del hechizo de ataque. 
2. launch():
    * Calcula una variación aleatoria entre -10 y 10 utilizando rand(). 
    * Determina el realDamage sumando esta variación a basicDamage. 
3. toString() const:
    * Devuelve una representación en forma de cadena del daño real causado por el hechizo. 

#### Clase DefenseSpell
La clase DefenseSpell es una clase derivada de la clase abstracta Spell, que representa un tipo de hechizo defensivo. A continuación, se describe en detalle su estructura y funcionalidad.

Atributos Privados:
* int basicDefense: Este atributo almacena la defensa básica que puede da este hechizo.
* int realDefense Este atributo almacena la defensa real que se determinará en el método launch() con una variabilidad aleatoria.

Constructores:
1. Constructor por Defecto:
    * Inicializa basicDefense y realDefense a 1. 
    * Llama a srand(time(0)) para inicializar el generador de números aleatorios. 
2. Constructor de Copia:
    * Copia los valores de basicDefense y realDefense de otro objeto DefenseSpell. 
    * También inicializa el generador de números aleatorios.
3. Constructor con Parámetro:
    * Inicializa basicDefense y realDefense con el valor proporcionado en el parámetro.
    * Inicializa el generador de números aleatorios. 

Métodos Públicos:
1. getPower() const:
    * Retorna el valor de basicDamage, que representa el poder del hechizo de ataque. 
2. launch():
    * Calcula una variación aleatoria entre -5 y 5 utilizando rand(). 
    * Determina el realDamage sumando esta variación a basicDamage. 
3. toString() const:
    * Devuelve una cadena que representa la defensa real proporcionada por el hechizo. 

#### Clase HealingSpell
La clase HealingSpell es una clase derivada de la clase abstracta Spell, que representa un tipo de hechizo de curación. A continuación, se describe en detalle su estructura y funcionalidad.

Atributos Privados:
* int basicHealing:  Este atributo almacena los puntos de vida que el hechizo restaura. 
* int realHealing: Este atributo almacena la curación real que se determinará en el método launch() con una variabilidad aleatoria. 

Constructores:
1. Constructor por Defecto:
    * Inicializa basicHealing y realHealing a 1. 
    * Llama a srand(time(0)) para inicializar el generador de números aleatorios. 
2. Constructor de Copia:
    * Copia los valores de basicHealing y realHealing de otro objeto HealingSpell. 
    * También inicializa el generador de números aleatorios. 
3. Constructor con Parámetro:
    * Inicializa basicHealing y realHealing con el valor proporcionado en el parámetro.
    * Inicializa el generador de números aleatorios. 

Métodos Públicos:
1. getPower() const:
    * Retorna el valor de basicHealing, que representa el poder de curación del hechizo.
2. launch():
    * Calcula una variación aleatoria entre -8 y 8 utilizando rand(). 
    * Determina el realHealing sumando esta variación a basicHealing. 
3. toString() const:
    * Devuelve una representación en forma de cadena de los puntos de vida que restaura este hechizo.

# Rúbrica para la Actividad de Hechizos:
1. Correctitud del Código (60 puntos)
    1. Funcionamiento General (30 puntos):
        * El código debe cumplir con todos los requisitos funcionales especificados en la actividad. 
        * Todos los métodos y atributos deben funcionar correctamente y dar resultados esperados. 
    2. Constructores (15 puntos):
        * Los constructores de la clase deben inicializar correctamente los atributos. 
        * Los constructores de copia y con parámetro deben funcionar adecuadamente. 
    3. Métodos Públicos (15 puntos):
        * Los métodos deben realizar las operaciones especificadas. 
        * launch() debe calcular correctamente la variabilidad en el daño. 
        * toString() debe devolver una representación precisa del estado del objeto. 
2. Estilo de Codificación (40 puntos)
    1. Nombres de Variables y Métodos (15 puntos):
        * Los nombres de las variables y métodos deben ser claros, descriptivos y seguir las convenciones de nomenclatura. 
        * Utilizar camelCase para nombres de variables y métodos.
    2. Formateo y Sangría (15 puntos):
        * El código debe estar correctamente formateado con una adecuada indentación. 
        * Uso de espacios y saltos de línea para mejorar la legibilidad. 
    3. Comentarios y Documentación (10 puntos):
        * Cada método y sección del código deben tener comentarios explicativos. 
        * Comentarios de cabecera en cada clase y función deben describir brevemente su propósito. 