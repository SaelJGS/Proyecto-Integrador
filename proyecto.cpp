#include <iostream>
using namespace std;

/* Estructura que representa un producto.
   Contiene nombre, precio y cantidad. */
struct Producto
{
    string nombre;
    float precio;
    int cantidad;
};

// Arreglo de 100 productos como máximo
Producto productos[100];
int dimension = 0;

/*------------------------------------------
   Función para registrar productos.
    Solicita nombre, precio y cantidad.
   Incluye validación para precio y cantidad.
-------------------------------------------*/
void registrarProductos()
{
    cout << "¿Cuantos productos desea registrar? ";
    cin >> dimension;
    cout << endl;

    for (int i = 0; i < dimension; i++)
    {
        cout << "Producto " << i + 1 << ":" << endl;

        cout << "Nombre: ";
        cin >> productos[i].nombre;

        // Validación del precio (> 0)
        do
        {
            cout << "Precio: ";
            cin >> productos[i].precio;
            if (productos[i].precio <= 0)
            {
                cout << "ERROR: el precio debe ser mayor a 0.\n";
            }
        } while (productos[i].precio <= 0);

        // Validación de cantidad (> 0)
        do
        {
            cout << "Cantidad: ";
            cin >> productos[i].cantidad;
            if (productos[i].cantidad <= 0)
            {
                cout << "ERROR: la cantidad debe ser mayor a 0.\n";
            }
        } while (productos[i].cantidad <= 0);

        cout << endl;
    }
    cout << "Productos registrados exitosamente." << endl;
}

/*------------------------------------------
   Muestra en pantalla todos los productos
   registrados en formato tabular.
-------------------------------------------*/
void mostrarProductos()
{
    if (dimension == 0)
    {
        cout << "No hay productos registrados..." << endl;
        return;
    }
    cout << "==== LISTA DE PRODUCTOS =====" << endl;
    cout << "Nombre      Precio        Cantidad" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < dimension; i++)
    {
        cout << productos[i].nombre << "        "
             << productos[i].precio << "       "
             << productos[i].cantidad << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << endl;
}

/*------------------------------------------
   Métodos de ordenamiento por precio
   (Burbuja, Selección e Inserción).
   Cada uno ordena el arreglo de forma asc.
-------------------------------------------*/
void ordenarBurbuja()
{
    cout << "###MEDIANTE BUBBLESORT###" << endl;

    for (int i = 0; i < dimension - 1; i++)
    {
        for (int j = 0; j < dimension - i - 1; j++)
        {

            // Intercambia productos si están desordenados
            if (productos[j].precio > productos[j + 1].precio)
            {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

void ordenarSeleccion()
{
    cout << "###MEDIANTE SELECTIONSORT###" << endl;

    for (int i = 0; i < dimension - 1; i++)
    {
        int k = i;

        // Busca el menor elemento
        for (int j = i + 1; j < dimension; j++)
        {
            if (productos[j].precio < productos[k].precio)
            {
                k = j;
            }
        }

        // Intercambia posiciones
        Producto temp = productos[i];
        productos[i] = productos[k];
        productos[k] = temp;
    }
}

void ordenarInsercion()
{
    cout << "###MEDIANTE INSERCIONSORT###" << endl;

    for (int i = 1; i < dimension; i++)
    {
        Producto key = productos[i];
        int j = i - 1;

        // Desplaza elementos mayores hacia la derecha
        while (j >= 0 && key.precio < productos[j].precio)
        {
            productos[j + 1] = productos[j];
            j--;
        }

        productos[j + 1] = key;
    }
}

/*------------------------------------------
  Menú que permite al usuario elegir
  el método de ordenamiento a utilizar.
-------------------------------------------*/
void menuOrdenamiento()
{
    if (dimension == 0)
    {
        cout << "No hay productos registrados..." << endl;
        return;
    }

    int op;
    cout << "=== ORDENAR POR PRECIO ===\n";
    cout << "1. Burbuja\n";
    cout << "2. Seleccion\n";
    cout << "3. Insercion\n";
    cout << "Seleccione una opcion: ";
    cin >> op;
    cout << endl;

    switch (op)
    {
    case 1:
        ordenarBurbuja();
        break;
    case 2:
        ordenarSeleccion();
        break;
    case 3:
        ordenarInsercion();
        break;
    default:
        cout << "Opcion invalida.\n";
        return;
    }

    mostrarProductos(); // Mostrar lista ordenada
}

/*------------------------------------------
   Busca un producto ingresado por nombre
   e imprime sus datos si se encuentra.
-------------------------------------------*/
void buscarProducto()
{
    string buscar;
    cout << "Ingrese el nombre del producto: ";
    cin >> buscar;

    bool encontrado = false;

    for (int i = 0; i < dimension; i++)
    {

        if (buscar == productos[i].nombre)
        {
            encontrado = true;
            cout << "\nProducto encontrado:\n";
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Cantidad: " << productos[i].cantidad << endl
                 << endl;
        }
    }

    if (!encontrado)
        cout << "No se encontro el producto..." << endl;
}

/*------------------------------------------
   Permite actualizar precio o cantidad
   de un producto seleccionado por índice.
-------------------------------------------*/
void actualizarProducto()
{
    if (dimension == 0)
    {
        cout << "No hay productos registrados..." << endl;
    }

    cout << "==== LISTA DE PRODUCTOS Y SU INDICE =====" << endl;
    cout << "Indice     Nombre" << endl;
    cout << "--------------------------" << endl;

    // Muestra índices con nombres
    for (int i = 0; i < dimension; i++)
    {
        cout << "  " << i << "        " << productos[i].nombre << endl;
    }

    int indice;
    cout << "Ingrese el indice del producto a actualizar: ";
    cin >> indice;

    int opcion;
    cout << "\nProducto seleccionado:\n";
    cout << "Nombre: " << productos[indice].nombre << endl;
    cout << "Precio: " << productos[indice].precio << endl;
    cout << "Cantidad: " << productos[indice].cantidad << endl;

    cout << "\n¿Que desea actualizar?\n1. Precio\n2. Cantidad\nOpcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        // Validación para nuevo precio
        do
        {
            cout << "Nuevo precio: ";
            cin >> productos[indice].precio;
        } while (productos[indice].precio <= 0);
        break;

    case 2:
        // Validación para nueva cantidad
        do
        {
            cout << "Nueva cantidad: ";
            cin >> productos[indice].cantidad;
        } while (productos[indice].cantidad <= 0);
        break;

    default:
        cout << "Opcion invalida\n";
    }
}

/*------------------------------------------
   Calcula valor total del inventario y
   muestra el producto con mayor cantidad.
-------------------------------------------*/
void generarReporte()
{
    float valorTotal = 0;

    // Suma total del inventario
    for (int i = 0; i < dimension; i++)
    {
        valorTotal += productos[i].precio * productos[i].cantidad;
    }

    // Busca producto con mayor cantidad
    int mayor = 0;
    for (int i = 1; i < dimension; i++)
    {
        if (productos[i].cantidad > productos[mayor].cantidad)
        {
            mayor = i;
        }
    }

    cout << "==== REPORTE FINAL ====\n";
    cout << "Total de productos registrados: " << dimension << endl;
    cout << "Valor total en inventario: $" << valorTotal << endl;
    cout << "Producto con mayor cantidad: "
         << productos[mayor].nombre << " ("
         << productos[mayor].cantidad << ")\n\n";
}

/*------------------------------------------
   Función principal.
   Muestra el menú y controla el flujo.
-------------------------------------------*/
int main()
{
    int opcion;

    do
    {
        cout << "==== SISTEMA BASICO DE GESTION DE PRODUCTOS ====\n";
        cout << "1. Registrar productos\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Ordenar productos\n";
        cout << "4. Buscar producto\n";
        cout << "5. Actualizar producto\n";
        cout << "6. Generar reporte final\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
            registrarProductos();
            break;
        case 2:
            mostrarProductos();
            break;
        case 3:
            menuOrdenamiento();
            break;
        case 4:
            buscarProducto();
            break;
        case 5:
            actualizarProducto();
            break;
        case 6:
            generarReporte();
            break;
        case 7:
            cout << "Fin del programa...\n";
            break;
        default:
            cout << "Opcion invalida...\n";
        }

    } while (opcion != 7);

    return 0;
}
