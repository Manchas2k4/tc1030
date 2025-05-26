![Tec de Monterrey](../../images/logotecmty.png)
# Actividad: "Friends connected"

# Objetivo
Poner en práctica los conceptos de básicos de objeto, clase y apuntadores.

### "Friends connected"
Carlos es un joven emprendedor que desea crear una red social llamada "Friends connected" donde las personas puedan conectarse con sus amigos. En esta red social, cada persona será un objeto y los apuntadores se utilizarán para gestionar las relaciones de amistad entre usuarios. Carlos quiere que su red social permita añadir nuevos amigos, eliminar amigos y mostrar la lista de amigos de cada usuario fácilmente. Para lograr esto, decide implementar una estructura de datos eficiente basada en listas enlazadas y apuntadores.

### Detalles
* **Estructura de Usuario:** Cada usuario tendrá atributos como id, nombre y una lista de referencias a amigos. Cada objeto de la clase debe contar con tres constructores: un constructor por defecto, un constructor de copia y un constructor alternativo que reciba los datos de cada objeto. Además, debe incluir métodos de acceso para todas las variables de instancia. También es necesario implementar un método para añadir una nueva referencia de amigo y otro método para eliminar una referencia de la lista de amigos. Por último, se debe implementar un método llamado toString que devuelva una cadena con toda la información del objeto.
* **Operaciones básicas:**
	* Cargar catálogo. El formato del archivo es el siguiente: en la primera línea se encuentra un número que indica la cantidad de usuarios en el archivo, representado como n. Las siguientes n líneas contienen el ID y el nombre de cada usuario. Después, en las siguientes n líneas, verás el ID de cada usuario, seguido por la cantidad de amigos a agregar, representada como m, y los IDs de esos m amigos.
	* Añadir un nuevo usuario.
	* Mostrar todos los usuarios.
	* Añadir un nuevo amigo en la lista de amigos de un usuario.
	* Quitar un amigo de la lista de amigos de un usuario.
