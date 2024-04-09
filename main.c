#include <stdio.h>
#include <string.h>

// DEFINICION DE COLORES PARA USAR
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"

#define MAX_CLIENTES 1000
#define MAX_TELEFONOS 1000

// 
// Estructura para representar un cliente
typedef struct {
    int id;
    char nombres[50];
    int dni;
} Cliente;

// Estructura para representar un telefono
typedef struct {
    int id;
    char numero[15];
} Telefono;

// Estructura para relacionar clientes con teléfonos
typedef struct {
    int id_cliente;
    int id_telefono;
} RelacionClienteTelefono;





int menuPrincipal();
int buscarDatos();
int agregarDatos();
int modificarDatos();
int eliminarDatos();
void busquedaSinOConClientesTelefonos();
void agregarClienteSinTelefono();
void agregarTelefonoSinCliente();
void agregarClienteConTelefono();
int obtenerUltimoIDCliente();
int obtenerUltimoIDTelefono();
void eliminarTodo();
void eliminarUsuarioYSuTelefono();


int main()
{	
	menuPrincipal();
	return 0;
}

int menuPrincipal() {
	int opcionPrincipal; 
    
    do {
        printf(YELLOW"Hola bienvenido a tu listador de contacto de clientes");
        printf("\n");
        printf(
        "En este momento vas a poder realizar acciones en la aplicacion\n"
        "\n"
        "OPCIONES DE MENU\n"
        GREEN"PRESIONANDO 1 VAS A BUSCAR DATOS\n"
        GREEN"PRESIONANDO 2 VAS A AGREGARAS DATOS\n"
        GREEN"PRESIONANDO 3 VAS A MODIFICAR DATOS\n"
        GREEN"PRESIONANDO 4 VAS A ELIMINAR DATOS\n"
        "\n"
        RED"PRESIONANDO ESCAPE O ESC SALES DEL PROGRAMA\n"
        YELLOW"\n"
        );
        
        scanf("%d", &opcionPrincipal);
        
         switch(opcionPrincipal) {
            case 1:
                printf(GREEN"Seleccionaste Buscar datos\n");
                buscarDatos();
                break;
            case 2:
                printf(GREEN"Seleccionaste Agregar datos\n");
                agregarDatos();
                break;
            case 3:
                printf(GREEN"Seleccionaste Modificar datos\n");
                modificarDatos();
                break;
            case 4:
                printf(GREEN"Seleccionaste Eliminar datos\n");
                eliminarDatos();
                break;
            case 27:
                printf(RED"Seleccionaste Salir\n");
                break;
            default:
                printf("Opcion no valida, por favor seleccione la opciones que muestra el menu\n");
                printf("\n");
                break;
        }
    } while (opcionPrincipal != 27);
    
    return opcionPrincipal;
}


int buscarDatos() {
	int opcionBuscar;
		
	printf("\n");
	printf(
	YELLOW"En este momento vas a poder realizar acciones de busqueda\n"
	"\n"
	YELLOW"OPCIONES DE MENU\n"
	GREEN"PRESIONANDO 1 SE MOSTRARAN TODOS LOS CLIENTES QUE TENGAN O NO TELEFONOS ASOCIADOS O TELEFONOS SIN ASOCIAR CON CLIENTES\n"
	"\n"
	RED"PRESIONANDO 9 VAS AL MENU PRINCIPAL\n"
	RED"PRESIONANDO ESCAPE O ESC SALES DEL PROGRAMA\n"
	YELLOW"\n"
	);
	
	scanf("%d", &opcionBuscar);
	
	switch(opcionBuscar) {
            case 1:
                busquedaSinOConClientesTelefonos();
                break;
            default:
                printf("Opcion no valida, por favor seleccione la opciones que muestra el menu\n");
                printf("\n");
                break;
        }
	
	return opcionBuscar;
}

int agregarDatos() {
	int opcionAgregar;
	
	printf("\n");
	printf(
	"En este momento vas a poder realizar acciones de agregado\n"
	"\n"
	"OPCIONES DE MENU\n"
	GREEN"PRESIONANDO 1 AGREGARAS UN CLIENTE Y SU TELEFONO ASOCIADO\n"
	GREEN"PRESIONANDO 2 AGREGARAS UN CLIENTE SIN TELEFONO ASOCIADOS\n"
	GREEN"PRESIONANDO 3 AGREGARAS SOLO UN TELEFONO SIN CLIENTE ASOCIADO\n"
	"\n"
	RED"PRESIONANDO 9 VAS AL MENU PRINCIPAL\n"
	RED"PRESIONANDO ESCAPE O ESC SALES DEL PROGRAMA\n"
	YELLOW"\n"
	);
	
	scanf("%d", &opcionAgregar);
	
	switch(opcionAgregar) {
		case 1:
			agregarClienteConTelefono();
		case 2:
			agregarClienteSinTelefono();
			break;
		case 3:
			agregarTelefonoSinCliente();
			break;
		default:
			printf("Opcion no valida, por favor seleccione la opciones que muestra el menu\n");
			printf("\n");
			break;
        }
	
	return opcionAgregar;
}

int modificarDatos() {
	int opcionModificar;
		
	printf("\n");
	printf(
	YELLOW"En este momento vas a poder realizar acciones de modificado\n"
	"\n"
	YELLOW"OPCIONES DE MENU\n"
	GREEN"PRESIONANDO 1 MODIFICAS UN CLIENTE CON TELEFONO ASOCIADO\n"
	GREEN"PRESIONANDO 2 MODIFICAS UN CLIENTE SIN TELEFONO ASOCIADOS\n"
	GREEN"PRESIONANDO 3 MODIFICAS TELEFONO SIN CLIENTE ASOCIADO\n"
	"\n"
	RED"PRESIONANDO 9 VAS AL MENU PRINCIPAL\n"
	RED"PRESIONANDO ESCAPE O ESC SALES DEL PROGRAMA\n"
	YELLOW"\n"
	);
	
	scanf("%d", &opcionModificar);
	
	
	return opcionModificar;
}

int eliminarDatos() {
	int opcionEliminar;
	
	printf("\n");
	printf(
	YELLOW"En este momento vas a poder realizar acciones de eliminacion\n"
	"\n"
	YELLOW"OPCIONES DE MENU\n"
	GREEN"PRESIONANDO 1 ELIMINAR UN CLIENTE Y SU TELEFONO ASOCIADO\n"
	GREEN"PRESIONANDO 2 ELIMINAR UN CLIENTE SIN TELEFONO ASOCIADOS\n"
	GREEN"PRESIONANDO 3 ELIMINAR SOLO UN TELEFONO SIN CLIENTE ASOCIADO\n"
	GREEN"PRESIONANDO 4 ELIMINAR SOLO EL CLIENTE PERO NO SU TELEFONO ASOCIADO\n"
	GREEN"PRESIONANDO 5 ELIMINAR SOLO EL NUMERO PERO NO SU CLIENTE ASOCIADO\n"
	"\n"
	RED"PRESIONANDO 8 ELIMINAS TODO\n"
	RED"PRESIONANDO 9 VAS AL MENU PRINCIPAL\n"
	RED"PRESIONANDO ESCAPE O ESC SALES DEL PROGRAMA\n"
	YELLOW"\n"
	);
	scanf("%d", &opcionEliminar);
	
	switch(opcionEliminar) {
            case 1:
                eliminarUsuarioYSuTelefono();
                break;
            case 8:
                eliminarTodo();
                break;
            default:
                printf("Opcion no valida, por favor seleccione la opciones que muestra el menu\n");
                printf("\n");
                break;
        }

	return opcionEliminar;
}

// BUSQUEDA

void busquedaSinOConClientesTelefonos() {
    FILE *clientesFile = fopen("clientes.bin", "rb");
    if (clientesFile == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }

    FILE *telefonosFile = fopen("telefonos.bin", "rb");
    if (telefonosFile == NULL) {
        printf("Error al abrir el archivo de teléfonos.\n");
        fclose(clientesFile);
        return;
    }

    FILE *relacionesFile = fopen("relaciones.bin", "rb");
    if (relacionesFile == NULL) {
        printf("Error al abrir el archivo de relaciones.\n");
        fclose(clientesFile);
        fclose(telefonosFile);
        return;
    }

    Cliente cliente;
    Telefono telefono;
    RelacionClienteTelefono relacion;

    printf("Clientes con o sin telefono asociado:\n");
    while (fread(&cliente, sizeof(Cliente), 1, clientesFile) == 1) {
        printf("ID Cliente: %d, Nombre: %s, DNI: %d\n", cliente.id, cliente.nombres, cliente.dni);
    }

    printf("\nTelefonos con o sin cliente asociado:\n");
    while (fread(&telefono, sizeof(Telefono), 1, telefonosFile) == 1) {
        printf("ID Telefono: %d, Numero: %s\n", telefono.id, telefono.numero);
    }

    printf("\nRelaciones entre clientes y telefonos:\n");
    while (fread(&relacion, sizeof(RelacionClienteTelefono), 1, relacionesFile) == 1) {
        printf("ID Cliente: %d, ID Telefono: %d\n", relacion.id_cliente, relacion.id_telefono);
    }

    fclose(clientesFile);
    fclose(telefonosFile);
    fclose(relacionesFile);
}


int obtenerUltimoIDCliente() {
    FILE *clientesFile = fopen("clientes.bin", "rb");
    if (clientesFile == NULL) {
        return 0; // Si el archivo no existe o no se puede abrir, se asume que el último ID es 0
    }

    int ultimoID = 0;
    fseek(clientesFile, -sizeof(Cliente), SEEK_END); // Ir al último registro
    Cliente ultimoCliente;
    fread(&ultimoCliente, sizeof(Cliente), 1, clientesFile);
    fclose(clientesFile);

    // Si el último ID es cero, buscar el último ID no cero
    if (ultimoCliente.id == 0) {
        clientesFile = fopen("clientes.bin", "rb");
        while (fread(&ultimoCliente, sizeof(Cliente), 1, clientesFile) == 1) {
            if (ultimoCliente.id != 0) {
                ultimoID = ultimoCliente.id;
            }
        }
        fclose(clientesFile);
    } else {
        ultimoID = ultimoCliente.id;
    }

    return ultimoID;
}

// Función para obtener el último ID de teléfonos
int obtenerUltimoIDTelefono() {
    FILE *telefonosFile = fopen("telefonos.bin", "rb");
    if (telefonosFile == NULL) {
        return 0; // Si el archivo no existe o no se puede abrir, se asume que el último ID es 0
    }

    int ultimoID = 0;
    fseek(telefonosFile, -sizeof(Telefono), SEEK_END); // Ir al último registro
    Telefono ultimoTelefono;
    fread(&ultimoTelefono, sizeof(Telefono), 1, telefonosFile);
    fclose(telefonosFile);

    // Si el último ID es cero, buscar el último ID no cero
    if (ultimoTelefono.id == 0) {
        telefonosFile = fopen("telefonos.bin", "rb");
        while (fread(&ultimoTelefono, sizeof(Telefono), 1, telefonosFile) == 1) {
            if (ultimoTelefono.id != 0) {
                ultimoID = ultimoTelefono.id;
            }
        }
        fclose(telefonosFile);
    } else {
        ultimoID = ultimoTelefono.id;
    }

    return ultimoID;
}

// Función para agregar un cliente sin telefono
void agregarClienteSinTelefono() {
    Cliente nuevoCliente;
    nuevoCliente.id = obtenerUltimoIDCliente() + 1; // Obtener el próximo ID disponible
    printf("Ingrese el nombre del cliente: ");
    scanf(" %[^\n]", nuevoCliente.nombres);
    printf("Ingrese el DNI del cliente: ");
    scanf("%d", &nuevoCliente.dni);

    FILE *clientesFile = fopen("clientes.bin", "ab"); // Abrir el archivo en modo de escritura binaria (agregar al final)
    if (clientesFile == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }

    // Escribir el cliente en el archivo
    fwrite(&nuevoCliente, sizeof(Cliente), 1, clientesFile);
    fclose(clientesFile);

    printf("Cliente agregado correctamente.\n");
    menuPrincipal();
}

// Función para agregar un teléfono sin cliente
void agregarTelefonoSinCliente() {
    Telefono nuevoTelefono;
    nuevoTelefono.id = obtenerUltimoIDTelefono() + 1; // Obtener el próximo ID disponible
    printf("Ingrese el numero de teléfono: ");
    scanf(" %[^\n]", nuevoTelefono.numero);

    FILE *telefonosFile = fopen("telefonos.bin", "ab"); // Abrir el archivo en modo de escritura binaria (agregar al final)
    if (telefonosFile == NULL) {
        printf("Error al abrir el archivo de teléfonos.\n");
        return;
    }

    // Escribir el teléfono en el archivo
    fwrite(&nuevoTelefono, sizeof(Telefono), 1, telefonosFile);
    fclose(telefonosFile);

    printf("Telefono agregado correctamente.\n");
    menuPrincipal();
}


void agregarClienteConTelefono() {
    // Solicitar datos del cliente
    Cliente nuevoCliente;
    nuevoCliente.id = obtenerUltimoIDCliente() + 1; // Asignar el próximo ID disponible
    printf("Ingrese el nombre del cliente: ");
    scanf(" %[^\n]", nuevoCliente.nombres);
    printf("Ingrese el DNI del cliente: ");
    scanf("%d", &nuevoCliente.dni);

    // Verificar si el cliente ya existe
    FILE *clientesFile = fopen("clientes.bin", "rb");
    if (clientesFile != NULL) {
        Cliente clienteExistente;
        while (fread(&clienteExistente, sizeof(Cliente), 1, clientesFile) == 1) {
            if (strcmp(clienteExistente.nombres, nuevoCliente.nombres) == 0 && clienteExistente.dni == nuevoCliente.dni) {
                printf("El cliente ya existe en el sistema.\n");
                fclose(clientesFile);
                return;
            }
        }
        fclose(clientesFile);
    }

    // Solicitar datos del teléfono
    Telefono nuevoTelefono;
    nuevoTelefono.id = obtenerUltimoIDTelefono() + 1; // Asignar el próximo ID disponible
    printf("Ingrese el numero de telefono: ");
    scanf(" %[^\n]", nuevoTelefono.numero);

    // Verificar si el teléfono ya existe
    FILE *telefonosFile = fopen("telefonos.bin", "rb");
    if (telefonosFile != NULL) {
        Telefono telefonoExistente;
        while (fread(&telefonoExistente, sizeof(Telefono), 1, telefonosFile) == 1) {
            if (strcmp(telefonoExistente.numero, nuevoTelefono.numero) == 0) {
                printf("El telefono ya existe en el sistema.\n");
                fclose(telefonosFile);
                return;
            }
        }
        fclose(telefonosFile);
    }

    // Abrir los archivos para escritura
    clientesFile = fopen("clientes.bin", "ab");
    if (clientesFile == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }

    telefonosFile = fopen("telefonos.bin", "ab");
    if (telefonosFile == NULL) {
        printf("Error al abrir el archivo de telefonos.\n");
        fclose(clientesFile);
        return;
    }

    FILE *relacionesFile = fopen("relaciones.bin", "ab");
    if (relacionesFile == NULL) {
        printf("Error al abrir el archivo de relaciones.\n");
        fclose(clientesFile);
        fclose(telefonosFile);
        return;
    }

    // Escribir el cliente en el archivo de clientes
    fwrite(&nuevoCliente, sizeof(Cliente), 1, clientesFile);

    // Escribir el teléfono en el archivo de teléfonos
    fwrite(&nuevoTelefono, sizeof(Telefono), 1, telefonosFile);

    // Escribir la relación en el archivo de relaciones
    RelacionClienteTelefono relacion;
    relacion.id_cliente = nuevoCliente.id;
    relacion.id_telefono = nuevoTelefono.id;
    fwrite(&relacion, sizeof(RelacionClienteTelefono), 1, relacionesFile);

    // Cerrar los archivos
    fclose(clientesFile);
    fclose(telefonosFile);
    fclose(relacionesFile);

    printf("Cliente y telefono agregados correctamente.\n");
     menuPrincipal();
}


void eliminarTodo() {
    if (remove("clientes.bin") != 0) {
        printf("Error al eliminar el archivo de clientes.\n");
    }

    // Eliminar archivo de teléfonos
    if (remove("telefonos.bin") != 0) {
        printf("Error al eliminar el archivo de teléfonos.\n");
    }

    // Eliminar archivo de relaciones
    if (remove("relaciones.bin") != 0) {
        printf("Error al eliminar el archivo de relaciones.\n");
    }

    printf("Todos los archivos de la base de datos han sido eliminados.\n");
}

void eliminarUsuarioYSuTelefono() {
    int dni;
    printf("Ingrese el DNI del usuario a eliminar: ");
    scanf("%d", &dni);

    FILE *clientesFile = fopen("clientes.bin", "r+b");
    FILE *relacionesFile = fopen("relaciones.bin", "r+b");
    FILE *telefonosFile = fopen("telefonos.bin", "r+b");

    if (clientesFile == NULL || relacionesFile == NULL || telefonosFile == NULL) {
        printf("Error al abrir archivos.\n");
        return;
    }

    Cliente cliente;
    RelacionClienteTelefono relacion;

    // Buscar el cliente por DNI
    while (fread(&cliente, sizeof(Cliente), 1, clientesFile) == 1) {
        if (cliente.dni == dni) {
            // Eliminar el cliente del archivo
            fseek(clientesFile, -sizeof(Cliente), SEEK_CUR);
            Cliente clienteEliminado = {0}; // Estructura de cliente vacía
            fwrite(&clienteEliminado, sizeof(Cliente), 1, clientesFile);
            
            // Buscar la relación del cliente con el teléfono
            fseek(relacionesFile, 0, SEEK_SET); // Volver al principio del archivo
            while (fread(&relacion, sizeof(RelacionClienteTelefono), 1, relacionesFile) == 1) {
                if (relacion.id_cliente == cliente.id) {
                    // Eliminar la relación
                    fseek(relacionesFile, -sizeof(RelacionClienteTelefono), SEEK_CUR);
                    RelacionClienteTelefono relacionEliminada = {0}; // Estructura de relación vacía
                    fwrite(&relacionEliminada, sizeof(RelacionClienteTelefono), 1, relacionesFile);
                    
                    // Buscar el teléfono asociado al cliente
                    fseek(telefonosFile, 0, SEEK_SET); // Volver al principio del archivo
                    Telefono telefono;
                    while (fread(&telefono, sizeof(Telefono), 1, telefonosFile) == 1) {
                        if (relacion.id_telefono == telefono.id) {
                            // Eliminar el teléfono
                            fseek(telefonosFile, -sizeof(Telefono), SEEK_CUR);
                            Telefono telefonoEliminado = {0}; // Estructura de teléfono vacía
                            fwrite(&telefonoEliminado, sizeof(Telefono), 1, telefonosFile);
                            break; // Terminar el bucle una vez que se haya eliminado el teléfono
                        }
                    }
                    break; // Terminar el bucle una vez que se haya eliminado la relación
                }
            }
            
            printf("Usuario eliminado correctamente.\n");
            break; // Terminar el bucle una vez que se haya eliminado el usuario
        }
    }

    fclose(clientesFile);
    fclose(relacionesFile);
    fclose(telefonosFile);
}