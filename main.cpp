//Universidad Estatal a Distancia - Introducción a la programación 00831 //
//Proyecto #2 - Sistema de una farmacia - Diseñado por Héctor Andrés Arrieta Sancho//

#include <iostream> //biblioteca para usar cin y cout
#include <windows.h> //tildes al escribir
#include <fstream> //biblioteca para manejar archivos
#include <iomanip> //setw espacios
#include <limits> //Libreria para el uso de numeric_limits

#include <sstream> // Para utilizar istringstream

using namespace std; //aguiliza el prefijo std

//Prototipeo de funciones
void FuncionIngresoProducto();
void FuncionAsosiaciones();
void FuncionRegReceta();
void FuncionCatalogo();
void FuncionImpresion();
bool FuncionActualizarCantidad(unsigned int codigo, double cantidad);
bool FuncionVerificarCantidad(unsigned int codigo, double cantidad);
string FuncionVerificarAsociacion(unsigned int codigo);
string convertirAminuscula (string texto);


//variable globales
unsigned int codigo;
string producto;
double cantidad;
string asociacion;
unsigned int numReceta;
string paciente;
string indicacion;
string producto2;
bool valorRespuestaS = false;

int main()
{
    setlocale(LC_ALL, "");//agregar tildes
    SetConsoleCP(1252);//modificar la consola tildes ingresa
    SetConsoleOutputCP(1252);// tildes muestra
    char OpcionMenu;
    do
    {
        system("cls");
        cout << "1. Ingresar productos.\n";
        cout << "2. Ingresar asociaciones con productos.\n";
        cout << "3. Registrar una receta.\n";
        cout << "4. Reporte de catálogo de productos.\n";
        cout << "5. Reporte impresión de la receta.\n";
        cout << "6. Salir.\n";
        cin >> OpcionMenu;

        switch (OpcionMenu)
        {
            case '1': //ingresar productos

                FuncionIngresoProducto();
                system("pause");
            break;
            case '2': //ingresar asosiaciones
                FuncionAsosiaciones();
                system("pause");
            break;
            case '3': //Registrar una receta
                FuncionRegReceta();
                system("pause");
            break;
            case '4': //Reporte de productos
                FuncionCatalogo();
                system("pause");
            break;
            case '5': //Impresion de receta
                FuncionImpresion();
                system("pause");
            break;
            case '6':
                cout << "Saliendo del sistema";
            break;
            default :
                cout << "La opción ingresada no está dentro del menú\n";
                system("pause");
            break;
        }
    }
    while (OpcionMenu != '6');
    return 0;
}

//Funciones:
///////////////////////////////case 1/////////////////////////////////////////////////////////////////////////////////////////
void FuncionIngresoProducto()
{
    char respuesta;
    bool verificadorCodigo;
    bool verificadorCantidad;
    cantidad = 0;
    verificadorCodigo = false;
    verificadorCantidad = false;
    string nombreArchivo;
    bool productoEncontrado = true;

    ofstream registro("MEDICAMENTOS.TXT", ios::app); //creamos el archivo y lo abre
    if (!registro)
    {
        cout << "No se puede abrir el archivo MEDICAMENTOS.TXT" << endl;
        exit(1);
    }
    do
    {
        system("CLS");
        cout << "****** Bienvenido al ingreso de productos ******\n";
        cout << "Ingrese el codigo del producto, puede ser un número nada más\n";
        cin >> (codigo);
            if (!cin.good()) //verifica que no se ingresen letras en las variables de tipos numericos, si cin esta mal entra al if
            {
                cout << "Solo se permite el ingreso de números\n";
                cin.clear(); //limpiar el estado erroneo
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
                system("pause");
            }
            else
            {
                verificadorCodigo = true ;
            }
    }
    while (verificadorCodigo == false); //hagalo mientras sea falso
    cin.clear(); //limpiar el estado erroneo
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.

    do
    {
        productoEncontrado = true;
        cout << "Digite el nombre del producto a ingresar\n";
        getline(cin, producto);
        if (producto.empty())
        {
            cout << "La cadena está vacía.\n";
            system("pause");
            system("CLS");
            continue; //lo regresa
        }
        ifstream registroBusqueda("MEDICAMENTOS.TXT", ios::in); //lee y abre
        if (!registro)
        {
            cout << "No se puede abrir el archivo MEDICAMENTOS.TXT" << endl;
            exit(1);
        }
        // Leer cada línea del archivo
        while (getline(registroBusqueda, nombreArchivo))
        {
            // Verificar si encontramos la palabra buscada en la línea
            if (nombreArchivo.find(producto) != string::npos)
            {
                productoEncontrado = false;
                system("cls");
                cout << "El producto : " << producto << " ya existe por favor ingrese uno diferente" << endl;
                break; // Detener la búsqueda después de encontrar la palabra
            }
        }
    }
    while (productoEncontrado == false || producto==""); // Repetir mientras no se encuentre la palabra

    do
    {
        system("CLS");
        cout << "Digite la cantidad\n";
        cin >> (cantidad);
        if (!cin.good()) //verifica que no se ingresen letras en las variables de tipos numericos, si cin esta mal entra al if
        {
            cout << "Solo se permite el ingreso de números\n";
            cin.clear(); //limpiar el estado erroneo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
                system("pause");
        }
        else
        {
            verificadorCantidad = true ;
        }
    }
    while (verificadorCantidad == false); //hagalo mientras sea falso

       do
        {
            system("cls");
            cout << "¿ Desea ingresar el medicamento S/N: ?\n";
            cin >> respuesta;

            // Verificar si la entrada es una letra
            if (!isalpha(respuesta))
            {
                cout << "No se permiten números, " ;
            }
            if (respuesta == 'S' or respuesta == 's')
            {
                registro << codigo << ' ' << producto << ' ' << cantidad << endl;
                registro.close();
                cout << "Producto almacenado correctamente\n";
                valorRespuestaS = true ;
            }
            else if (respuesta == 'N' or respuesta == 'n')
            {
                cout << "Volviendo al menú principal sin guardar el producto\n";
                valorRespuestaS = true ;
            }
            else
            {
                cout << "Por favor, digite únicamente 's' o 'n'." << endl;
                system("pause");
            }
        }
        while (valorRespuestaS == false);
}
//////////////////////////////////case 2//////////////////////////////////////////////////////////////////////////////////////////
void FuncionAsosiaciones()
{
    char respuesta;
    bool verificadorCodigo;
    verificadorCodigo = false;
    bool encontrado = false;
    unsigned int codigoArchivo;
    valorRespuestaS == false;

    ofstream registroAsociaciones("CLAVES.TXT", ios::app); //creamos el archivo y lo abre
    if (!registroAsociaciones)
    {
        cout << "No se puede abrir el archivo CLAVES.TXT" << endl;
        exit(1);
    }

    do
    {
        system("CLS");
        cout << "****** Bienvenido al ingreso de asociaciones con productos. ******\n";
        cout << "Ingrese el codigo del producto, para buscarlo\n";
        cin >> (codigo);
            if (!cin.good()) //verifica que no se ingresen letras en las variables de tipos numericos, si cin esta mal entra al if
            {
                cout << "Solo se permite el ingreso de números\n";
                cin.clear(); //limpiar el estado erroneo
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
                system("pause");
            }
            else
            {
                verificadorCodigo = true ;
            }

        ifstream registro("MEDICAMENTOS.TXT");
        // Buscar el código en el archivo de medicamentos
        while (registro >> codigoArchivo)
            {
                // Leer el nombre del producto
                getline(registro, producto);
                // Verificar si encontramos el producto con el código buscado
                if (codigoArchivo == codigo)
                {
                    encontrado = true;
                    size_t pos = producto.find_last_of(' ');
                    if (pos != string::npos)
                    {
                        producto = producto.substr(1, pos);
                    }
                cout << "Producto encontrado: " << producto << endl;
                }
            }

        // Informar al usuario si el producto no se encontró
        try
        {
            if (!encontrado) throw 404;
        }
        catch (int e)
        {
            cout << "Error: " << e << ", el código " << codigo << " no fue encontrado en el archivo de medicamentos." << endl;
            system("pause");
        }
    }
    while (verificadorCodigo == false || encontrado == false) ; //hagalo mientras sea falso
    cin.clear(); //limpiar el estado erroneo
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
    do
    {
        cout << "Digite la palabra asociativa única\n";
        getline(cin, asociacion);
        if (asociacion.empty())
        {
            cout << "La cadena está vacía.\n";
            system("pause");
            system("CLS");
        }
    }
    while (asociacion=="");

    do
        {
            system("cls");
            cout << "¿ Desea ingresar la asociación S/N: ?\n";
            cin >> respuesta;

            // Verificar si la entrada es una letra
            if (!isalpha(respuesta))
            {
                cout << "No se permiten números, " ;
                //break;
            }
            if (respuesta == 'S' or respuesta == 's')
            {
                registroAsociaciones << codigo <<' ' << asociacion << endl;
                cout << "Asociacion almacenada correctamente\n";
                registroAsociaciones.close();
                valorRespuestaS = true ;
            }
            else if (respuesta == 'N' or respuesta == 'n')
            {
                cout << "Volviendo al menú principal sin guardar la asociación\n";
                valorRespuestaS = true ;
            }
            else
            {
                cout << "Por favor, digite únicamente 's' o 'n'." << endl;
                system("pause");
            }
        }
        while (valorRespuestaS == false);
    registroAsociaciones.close();
}
/////////////////////////////////case 3///////////////////////////////////////////////////////////////////////////////////////
void FuncionRegReceta()
{
    char respuesta;
    bool verificadorNumReceta;
    bool verificadorCantidad;
    cantidad = 0.00;
    numReceta = 0;
    verificadorNumReceta = false;
    verificadorCantidad = false;
    bool verificadorCodigo;
    verificadorCodigo = false;
    unsigned int codigoArchivo;
    bool encontrado;
    encontrado = false;
    string linea;
    int numeroLeido;
    bool encontradoNum;
    encontradoNum = false;
    bool pase;
    bool verificadorAsociativa = false;
    string productoLocal ;
    valorRespuestaS == false;
    char desicion;
    bool valorMenuSalir = false;

    ofstream registroReceta("RECETA.TXT", ios::app); //creamos el archivo y lo abre
    if (!registroReceta)
    {
        cout << "No se puede abrir el archivo RECETA.TXT" << endl;
        exit(1);
    }
   do
    {
        pase = true;
        encontradoNum = false;
        system("CLS");
        cout << "****** Bienvenido al ingreso de recetas ******\n";
        cout << "Ingrese el número de la receta, debe ser mayor o igual a 1000 y no debe repetirse:\n";
        cin.clear(); //limpiar el estado erroneo
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.

        // Leer el número de receta
        cin >> numReceta;

        // Verificar si se ha ingresado un número válido
        if (!cin.good())
        {
            cout << "Error: Solo se permiten números.\n";
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            system("pause");
        }
            else
            {
                // Verificar que el número de receta sea válido
                if (numReceta < 1000)
                {
                    cout << "Debes ingresar un número mayor o igual a 1000.\n";
                    system("pause");
                }
                else
                {
                    verificadorNumReceta = true;

                    // Verificar si el número de receta ya existe en el archivo
                    ifstream archivoReceta("RECETA.TXT");
                    while (getline(archivoReceta, linea))
                    {
                        istringstream iss(linea);
                        int numeroLeido;

                        if (iss >> numeroLeido && numeroLeido == numReceta)
                        {
                            encontradoNum = true;
                            cout << "El número de receta " << numReceta << " ya existe en el archivo.\n";

                             do
                            {
                                cout << "\n¿ Digite 'S' Si desea registrar un número diferente de receta, o digite 'N' para volver al menú principal S/N\n";
                                cin >> desicion;
                                if (desicion == 'S' or desicion == 's')
                                {
                                     valorMenuSalir = true ;
                                     break;
                                }
                                    else if (desicion == 'N' or desicion == 'n')
                                    {
                                        cout << "Volviendo al menú principal\n";
                                        valorMenuSalir = true ;
                                        return;
                                    }
                                else
                                {
                                    cout << "Por favor, digite únicamente 's' o 'n'." << endl;
                                    system("pause");
                                }
                            }
                            while (valorMenuSalir == false);
                        }
                    }
                    archivoReceta.close();

                    if (encontradoNum)
                    {
                        system("pause");
                        pase = false;
                    }
                }
            }
    }
    while (verificadorNumReceta == false || numReceta < 1000 || pase == false);
    cout << "Ingresando nueva receta\n";
    cin.clear(); //limpiar el estado erroneo
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.

    do
    {
        cout << "Digite el nombre del paciente junto con los dos apellidos :\n";
        getline(cin, paciente);
        if (paciente.empty())
        {
            cout << "La cadena está vacía.\n";
            system("pause");
            system("CLS");
        }
    }
    while (paciente=="");

    // Buscar el código en el archivo de medicamentos
    do
    {
        system("CLS");
        cout << "Ingrese el codigo del producto\n";
        cin >> (codigo);
            if (!cin.good()) //verifica que no se ingresen letras en las variables de tipos numericos, si cin esta mal entra al if
            {
                cout << "Solo se permite el ingreso de números\n";
                cin.clear(); //limpiar el estado erroneo
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
                system("pause");
            }
            else
            {
                verificadorCodigo = true ;
            }


        ifstream registro("MEDICAMENTOS.TXT");
        while (registro >> codigoArchivo)
            {
            // Leer el nombre del producto
            getline(registro, producto);

            // Verificar si encontramos el producto con el código buscado
            if (codigoArchivo == codigo)
            {
                encontrado = true;

                // Extraer la cantidad asociada si está presente
                size_t pos = producto.find_last_of(' ');
                if (pos != string::npos)
                {
                    productoLocal = producto.substr(1, pos);
                }
                cout << "Producto encontrado: " << productoLocal << endl;
                break;
            }
            }

        // Informar al usuario si el producto no se encontró

        try
        {
        if (!encontrado) throw 404;
        }
            catch (int e)
            {
                cout << "Error: " << e << ", el código " << codigo << " no fue encontrado en el archivo de medicamentos." << endl;
                system("pause");
            }
    }
    while (verificadorCodigo == false || encontrado == false) ; //hagalo mientras sea falso
    cin.clear(); //limpiar el estado erroneo
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.

    do
    {
        cout << "Digite la indicación :\n";
        getline(cin, indicacion);
        string clave = FuncionVerificarAsociacion (codigo);
        if (indicacion.empty())
        {
            cout << "La cadena está vacía.\n";
            system("pause");
            system("CLS");
        }
        else if((convertirAminuscula(indicacion)).find(convertirAminuscula(clave)) == -1)//.find retorna la pocision donde 'clave' fue econtrado y -1 si no fue encontrado. busca en minuscula.
        {
            cout << "La palabra asociativa no encontrada.\n";
            system("pause");
            system("CLS");
        }
        else
        {
            verificadorAsociativa = true;
        }
    }
    while (verificadorAsociativa == false);

    do
    {
        system("CLS");
        cout << "Digite la cantidad\n";
        cin >> (cantidad);
        if (!cin.good()) //verifica que no se ingresen letras en las variables de tipos numericos, si cin esta mal entra al if
        {
            cout << "Solo se permite el ingreso de números\n";
            cin.clear(); //limpiar el estado erroneo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
            system("pause");
        }
        else if(!FuncionVerificarCantidad(codigo, cantidad))
        {
            cout << "Verifique cantidad en existencias\n";
            cin.clear(); //limpiar el estado erroneo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //borre todos los elementos tantos como sea posible hasta que llegue un salto de linea, osea borre todo lo que haya ingresado en cedula.
            system("pause");
        }
        else
        {
            verificadorCantidad = true ;
        }
    }
    while (verificadorCantidad == false); //hagalo mientras sea falso

    do
        {
            system("cls");
            cout << "¿ Desea ingresar la receta S/N: ?\n";
            cin >> respuesta;

            // Verificar si la entrada es una letra
            if (!isalpha(respuesta))
            {
                cout << "No se permiten números, " ;
            }
            if (respuesta == 'S' or respuesta == 's')
            {
                registroReceta << numReceta << endl << paciente << endl << indicacion << endl << codigo << endl << productoLocal << endl << cantidad <<endl;
                registroReceta.close();
                cout << "Receta almacenada correctamente\n";
                FuncionActualizarCantidad(codigo, cantidad);
                valorRespuestaS = true ;
            }
            else if (respuesta == 'N' or respuesta == 'n')
            {
                cout << "Volviendo al menú principal sin guardar la receta\n";
                valorRespuestaS = true ;
            }
            else
            {
                cout << "Por favor, digite únicamente 's' o 'n'." << endl;
                system("pause");
            }
        }
        while (valorRespuestaS == false);
}
/////////////////////////////////case 4///////////////////////////////////////////////////////////////////////////////////////
void FuncionCatalogo()
{
    cout << setprecision(2) << fixed; //se establece que todas las salidas "cout" que lleven punto flotante las va a mostrar con dos cifras despues de la coma
    system("CLS");
    ifstream registro("MEDICAMENTOS.TXT", ios::in); //lee y abre
    if (!registro)
    {
        cout << "No se puede abrir el archivo MEDICAMENTOS.TXT" << endl;
        exit(1);
    }
    cout << "Los productos almacenados son los siguientes\n\n";
    cout << left << setw(15) << "Código" << setw(15) << "Producto" << setw(15) << "Cantidad" << endl;

    while (registro >> codigo >> producto >> cantidad )
    {
        cout << left << setw(15) << codigo << setw(15) << producto << setw(15) << cantidad << endl;
    }
}
///////////////////////////// Case 5 imprimir la receta/////////////////////////////////////////////////////////////////////////////////////////////////////////
void FuncionImpresion()
{
    string numReceta, paciente, indicacion, codigo, producto, cantidad;
    cout << setprecision(2) << fixed; //se establece que todas las salidas "cout" que lleven punto flotante las va a mostrar con dos cifras despues de la coma
    system("CLS");

    ifstream registroReceta("RECETA.TXT");

    if (!registroReceta)
    {
        cout << "Error al abrir uno o ambos archivos." << endl;
        exit(1);
    }
    cout << "*** Reporte de impresion de recetas ***\n\n";

    while (getline(registroReceta, numReceta))
    {
        getline(registroReceta, paciente);
        getline(registroReceta, indicacion);

        getline(registroReceta, codigo);
        getline(registroReceta, producto);
        getline(registroReceta, cantidad);

        // Mostrar la información de la receta
        cout << "Número de receta: " << numReceta << endl;

        // Procesar nombre del paciente y la indicacion
        cout << "Paciente: " << paciente << endl;
        cout << "Indicación: " << indicacion << endl;


        // Mostrar la información del medicamento
        cout << "Código de producto: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;

        cout << "-------------------------\n";
    }

    registroReceta.close();
}
///////////////////////////// Funcion verifica la cantidad /////////////////////////////////////////////////////////////////////////////////////////////////////////
bool FuncionVerificarCantidad(unsigned int codigo, double cantidadReceta)
{
    unsigned int codigoArchivo;
    bool encontrado = false;

    ifstream registro("MEDICAMENTOS.TXT");

    while (registro >> codigoArchivo)
    {
        // Leer el nombre del producto
        getline(registro, producto);

        // Verificar si encontramos el producto con el código buscado
        if (codigoArchivo == codigo)
        {
            encontrado = true;

            // Extraer la cantidad asociada si está presente
            size_t pos = producto.find_last_of(' ');
            int cantidad = 0;
            if (pos != string::npos)
            {
                //producto = producto.substr(1, pos);
                string cantStr = producto.substr(pos);
                cantidad = atoi(cantStr.c_str()); //c_str() cinvierte el string a un array de caracteres, Parece que atoi espera un objecto Char*
                if(cantidad < cantidadReceta)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
///////////////////////////// Funcion actualiza la cantidad /////////////////////////////////////////////////////////////////////////////////////////////////////////
bool FuncionActualizarCantidad(unsigned int codigo, double cantidadReceta)
{
    unsigned int codigoArchivo;
    bool encontrado = false;
    string medicamentosTodo;

    ifstream registro("MEDICAMENTOS.TXT", ios::in); //lo abrimos en modo lectura

    while (registro >> codigoArchivo)
    {
        // Leer el nombre del producto
        getline(registro, producto);
        medicamentosTodo = medicamentosTodo + to_string(codigoArchivo);
        // Verificar si encontramos el producto con el código buscado
        if (codigoArchivo == codigo)
        {
            encontrado = true;

            // Extraer la cantidad asociada si está presente
            size_t pos = producto.find_last_of(' ');
            int cantidad = 0;
            if (pos != string::npos)
            {
                string cantStr = producto.substr(pos);
                cantidad = atoi(cantStr.c_str()); //c_str() cinvierte el string a un array de caracteres, Parece que atoi espera un objecto Char*
                if(cantidad < cantidadReceta)
                {
                    return false;
                }
                else
                {
                    int cantidadNueva = cantidad - cantidadReceta;
                    medicamentosTodo = medicamentosTodo + " " + producto.substr(1, pos) + to_string(cantidadNueva) + "\n";
                }
            }
        }
        else
        {
            medicamentosTodo = medicamentosTodo + producto + "\n";
        }
    }
    registro.close();
    ofstream registroEscribir("MEDICAMENTOS.TXT", ios::out); //creamos el archivo y lo abre
    if (!registroEscribir)
    {
        cout << "No se puede abrir el archivo MEDICAMENTOS.TXT" << endl;
        exit(1);
    }
    registroEscribir << medicamentosTodo;
    registroEscribir.close();
    return true;
}
///////////////////////////// Funcion busca asociativa /////////////////////////////////////////////////////////////////////////////////////////////////////////
string FuncionVerificarAsociacion(unsigned int codigo)
{
    unsigned int codigoArchivo;
    ifstream registro("CLAVES.TXT", ios::in);//solo lectura

    while (registro >> codigoArchivo)
    {

        // Leer el nombre del producto
        getline(registro, producto);

        // Verificar si encontramos el producto con el código buscado
        if (codigoArchivo == codigo)
        {

            // Extraer la cantidad asociada si está presente
            size_t pos = producto.find_last_of(' ');

            if (pos != string::npos)
            {
                //producto = producto.substr(1, pos);
                string clave = producto.substr(pos+1);

                    return clave;
            }
        }
    }
    return "";

}
///////////////////////////// Funcion conv minuscula /////////////////////////////////////////////////////////////////////////////////////////////////////////
string convertirAminuscula (string texto)
{
    for (int i =0; i < texto.length(); i++)
{
    //tolower convierte cualquier texto a minuscula
    texto[i] = tolower(texto[i]);
}
return texto;
}
/*

Bibliografía
primer apellido, letra del nombre, letra del segundo apellido:
Baeza, D. A. (14 mar 2024). Sesión Virtual Nº2 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=z5hIyUro1Js

Molina, I. G. (18 mar 2024). Sesión Virtual Nº2 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=HNpre-05kXU

Picado, K. R. (18 mar 2024). Sesión Virtual Nº2 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=eu7OBbHHdjw

Baeza, D. A. (14 mar 2024). Sesión Virtual Nº3 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=KMIvygL56QI

Molina, I. G. (18 mar 2024). Sesión Virtual Nº3 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=kmrGdE-j0y4

Picado, K. R. (18 mar 2024). Sesión Virtual Nº3 - Introducción a la programación - I Cuatrimestre 2024.
    Youtube. Obtenido de Obtenido de Universidad Estatal a
    Distancia: https://www.youtube.com/watch?v=e1noC_b7zkY

Alejandro A. C. (28 dic 2016). Programación en C++ || Archivos || Escribir en un archivo de texto.
    Youtube. Obtenido de Programación ATS: https://www.youtube.com/watch?v=GaqgqQL3wnQ&t=3s

Deitel, P. J., Deitel, H.  (2021). Cómo programar en C++. [[VitalSource Bookshelf version]].
    Recuperado de vbk://9786073255424

*/
