# Librería Mundo del Libro

## Historia
Ana es la dueña de una tienda de libros llamada "Librería Mundo de Libro". Ella ha notado que muchos clientes buscan libros por categorías como "Aventuras", "Fantasía", "Ciencia Ficción", "Policíaca"y "Misterio". Para mejorar la experiencia del cliente, Ana decide implementar un sistema de gestión de inventario que permite que cada categoría haga referencia a los libros que pertenecen a ella. Esto se logra mediante apuntadores que conectan categorías con los libros correspondientes. Así, los clientes pueden fácilmente encontrar libros en la categoría deseada.

## Detalles
* **Estructura de libro:** Cada libro cuenta con los siguientes atributos: ID, título, autor y precio. Cada objeto de la clase debe contar con tres constructores: un constructor por defecto, un constructor de copia y un constructor alternativo que reciba los datos de cada objeto. Además, debe incluir métodos de acceso para todas las variables de instancia. Por último, se debe implementar un método llamado toString que devuelva una cadena con toda la información del objeto.
* **Estructura de categoría:** Cada categoría tendrá un nombre y un conjunto de apuntadores a los libros que pertenezcan a ella. Cada objeto de la clase debe tener tres tipos de constructores: un constructor por defecto, un constructor de copia y un constructor alternativo que acepte los datos específicos del objeto. Además, se deben incluir métodos de acceso para todas las variables de instancia. También es necesario implementar un método para añadir una nueva referencia de un libro y otro método para eliminar una referencia que corresponda a un ID determinado. Por último, se debe crear un método llamado toString que devuelva una cadena con toda la información del objeto.
* **Operaciones básicas:**
	* Cargar catálogo. Carga el catálogo desde un archivo de texto. El archivo tiene el siguiente formato: La primera línea contiene un número que indica la cantidad de libros en el archivo. Para cada libro, se proporcionan cuatro líneas: la primera con el título, la segunda con el autor, la tercera con el precio y la cuarta con un número que indica la cantidad de categorías, seguido por los nombres de las categorías correspondientes. Las categorías posibles son: Adventure Fantasy, SciFi, Police y Mystery.
	* Añadir un libro.
	* Mostrar todos los libros.
	* Añadir un nuevo libro identificado por su ID a una categoría específica.
	* Eliminar un libro identificado por su ID de una categoría específica.
	* Mostrar todo los libros de una categoría específica.