#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

struct DatosCliente {
    int NumeroC;
    string NombreC;
    int EdadC;
    int DPIC;
};

struct DatosProducto {
    int L;
    string NombreP;
    float Precio;
    int Cantidad;
};

struct DatosFactura {
    int NumeroFactura;
    string Fecha;
    string ClienteProveedor;
    string DPIDireccion;
    string Producto;
    float Precio;
    int Cantidad;
    float Subtotal;
    float Impuesto;
    float Total;
};

struct DatosProveedor {
    int NumeroProveedor;
    string NombreProveedor;
    string ProductoSuministrado;
    string Contacto;
};

struct DatosVenta {
    int NumeroVenta;
    string Fecha;
    string Cliente;
    string Producto;
    float Precio;
    int Cantidad;
    float Subtotal;
    float Impuesto;
    float Total;
};

struct DatosCompra {
    int NumeroCompra;
    string FechaCompra;
    string FechaIngreso;
    float TotalCompra;
};

void MostrarClientes() {
    system("cls");
    ifstream archivoClientes("Clientes.txt");
    DatosCliente cliente;

    while (archivoClientes >> cliente.NumeroC >> cliente.NombreC >> cliente.EdadC >> cliente.DPIC) {
        cout << "NumeroC: " << cliente.NumeroC << "\tNombre: " << cliente.NombreC << "\tEdad: " << cliente.EdadC << "\tDPI: " << cliente.DPIC << endl;
    }

    archivoClientes.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void IncluirCliente() {
    system("cls");
    ofstream archivoClientes("Clientes.txt", ios::app);
    DatosCliente nuevoCliente;

    cout << "Ingrese el numero del cliente: "<<endl,
    cin >> nuevoCliente.NumeroC;
    cout << "Ingrese el nombre del cliente: "<<endl;
    cin >> nuevoCliente.NombreC;
    cout << "Ingrese la edad del cliente: " <<endl;
    cin >> nuevoCliente.EdadC;
    cout << "Ingrese el DPI del cliente: "<<endl;
    cin >> nuevoCliente.DPIC;

    archivoClientes << nuevoCliente.NumeroC << "  " << nuevoCliente.NombreC << "  " << nuevoCliente.EdadC << "  " << nuevoCliente.DPIC << endl;
    archivoClientes.close();

    cout << "Cliente incluido correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void EliminarCliente() {
    system("cls");
    MostrarClientes();

    int NumeroEliminar;
    cout << "Ingrese el numero del cliente a eliminar: ";
    cin >> NumeroEliminar;

    ifstream archivoEntrada("Clientes.txt");
    ofstream archivoSalida("temp.txt");

    DatosCliente cliente;
    while (archivoEntrada >> cliente.NumeroC >> cliente.NombreC >> cliente.EdadC >> cliente.DPIC) {
        if (cliente.NumeroC != NumeroEliminar) {
            archivoSalida << cliente.NumeroC << " " << cliente.NombreC << " " << cliente.EdadC << " " << cliente.DPIC << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("Clientes.txt");
    rename("temp.txt", "Clientes.txt");

    cout << "Cliente eliminado correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void ModificarCliente() {
    system("cls");
    MostrarClientes();

    int NumeroModificar, opcionModificar;
    cout << "Ingrese el numero del cliente a modificar: ";
    cin >> NumeroModificar;

    ifstream archivoEntrada("Clientes.txt");
    ofstream archivoSalida("temp.txt");

    DatosCliente cliente;
    while (archivoEntrada >> cliente.NumeroC >> cliente.NombreC >> cliente.EdadC >> cliente.DPIC) {
        if (cliente.NumeroC == NumeroModificar) {
            cout << "Opciones de modificacion:" << endl;
            cout << "1. Nombre del cliente" << endl;
            cout << "2. Edad del cliente" << endl;
            cout << "3. DPI del cliente" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcionModificar;

            if (opcionModificar == 1) {
                cout << "Ingrese el nuevo nombre: ";
                cin >> cliente.NombreC;
            } else if (opcionModificar == 2) {
                cout << "Ingrese la nueva edad: ";
                cin >> cliente.EdadC;
            } else if (opcionModificar == 3) {
                cout << "Ingrese el nuevo DPI: ";
                cin >> cliente.DPIC;
            }
        }

        archivoSalida << cliente.NumeroC << " " << cliente.NombreC << " " << cliente.EdadC << " " << cliente.DPIC << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("Clientes.txt");
    rename("temp.txt", "Clientes.txt");

    cout << "Cliente modificado correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarFacturas() {
    system("cls");
    ifstream archivoFacturas("Facturas.txt");
    DatosFactura factura;

    cout << left << setw(15) << "Numero Factura" << setw(15) << "Fecha" << setw(20) << "Cliente/Proveedor"
         << setw(15) << "DPI/Direccion" << setw(15) << "Producto" << setw(10) << "Precio" << setw(10) << "Cantidad"
         << setw(10) << "Subtotal" << setw(10) << "Impuesto" << setw(10) << "Total" << endl;

    while (archivoFacturas >> factura.NumeroFactura >> factura.Fecha >> factura.ClienteProveedor
           >> factura.DPIDireccion >> factura.Producto >> factura.Precio >> factura.Cantidad
           >> factura.Subtotal >> factura.Impuesto >> factura.Total) {
        cout << left << setw(15) << factura.NumeroFactura << setw(15) << factura.Fecha << setw(20) << factura.ClienteProveedor
             << setw(15) << factura.DPIDireccion << setw(15) << factura.Producto << setw(10) << factura.Precio
             << setw(10) << factura.Cantidad << setw(10) << factura.Subtotal << setw(10) << factura.Impuesto
             << setw(10) << factura.Total << endl;
    }

    archivoFacturas.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void IncluirFactura() {
    system("cls");
    ofstream archivoFacturas("Facturas.txt", ios::app);
    DatosFactura nuevaFactura;

    cout << "Ingrese el numero de la factura: "<<endl;
    cin >> nuevaFactura.NumeroFactura;
    cout << "Ingrese la fecha de la factura: "<<endl;
    cin >> nuevaFactura.Fecha;
    cout << "Ingrese el cliente/proveedor: "<<endl;
    cin.ignore();
    getline(cin, nuevaFactura.ClienteProveedor);
    cout << "Ingrese el DPI/Direccion: "<<endl;
    getline(cin, nuevaFactura.DPIDireccion);
    cout << "Ingrese el producto: "<<endl;
    getline(cin, nuevaFactura.Producto);
    cout << "Ingrese el precio del producto: "<<endl;
    cin >> nuevaFactura.Precio;
    cout << "Ingrese la cantidad: "<<endl;
    cin >> nuevaFactura.Cantidad;

    nuevaFactura.Subtotal = nuevaFactura.Precio * nuevaFactura.Cantidad;
    nuevaFactura.Impuesto = nuevaFactura.Subtotal * 0.12;  
    nuevaFactura.Total = nuevaFactura.Subtotal + nuevaFactura.Impuesto;

    archivoFacturas << nuevaFactura.NumeroFactura << " " << nuevaFactura.Fecha << " " << nuevaFactura.ClienteProveedor
                    << " " << nuevaFactura.DPIDireccion << " " << nuevaFactura.Producto << " " << nuevaFactura.Precio
                    << " " << nuevaFactura.Cantidad << " " << nuevaFactura.Subtotal << " " << nuevaFactura.Impuesto
                    << " " << nuevaFactura.Total << endl;
    archivoFacturas.close();

    cout << "Factura incluida correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarProductos() {
    system("cls");
    ifstream archivoProductos("Productos.txt");
    DatosProducto producto;

    cout << left << setw(5) << "L" << setw(20) << "Nombre" << setw(10) << "Precio"
         << setw(10) << "Cantidad" << endl;

    while (archivoProductos >> producto.L >> producto.NombreP >> producto.Precio >> producto.Cantidad) {
        cout << left << setw(5) << producto.L << setw(20) << producto.NombreP << setw(10) << producto.Precio
             << setw(10) << producto.Cantidad << endl;
    }

    archivoProductos.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void IncluirProducto() {
    system("cls");
    ofstream archivoProductos("Productos.txt", ios::app);
    DatosProducto nuevoProducto;

    cout << "Ingrese el numero del producto: "<<endl;
    cin >> nuevoProducto.L;
    cout << "Ingrese el nombre del producto: "<<endl;
    cin.ignore();
    getline(cin, nuevoProducto.NombreP);
    cout << "Ingrese el precio del producto: "<<endl;
    cin >> nuevoProducto.Precio;
    cout << "Ingrese la cantidad: "<<endl;
    cin >> nuevoProducto.Cantidad;

    archivoProductos << nuevoProducto.L << " " << nuevoProducto.NombreP << " " << nuevoProducto.Precio
                    << " " << nuevoProducto.Cantidad << endl;
    archivoProductos.close();

    cout << "Producto incluido correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarInventario() {
    system("cls");
    ifstream archivoInventario("Productos.txt");
    DatosProducto producto;

    cout << left << setw(5) << "L" << setw(20) << "Nombre" << setw(10) << "Precio"
         << setw(10) << "Cantidad" << endl;

    while (archivoInventario >> producto.L >> producto.NombreP >> producto.Precio >> producto.Cantidad) {
        cout << left << setw(5) << producto.L << setw(20) << producto.NombreP << setw(10) << producto.Precio
             << setw(10) << producto.Cantidad << endl;
    }

    archivoInventario.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void AjustarInventario() {
    system("cls");

    int NumeroAjustar, nuevaCantidad;
    cout << "Ingrese el numero del producto a ajustar: ";
    cin >> NumeroAjustar;

    ifstream archivoEntrada("Productos.txt");
    ofstream archivoSalida("temp.txt");

    DatosProducto producto;
    while (archivoEntrada >> producto.L >> producto.NombreP >> producto.Precio >> producto.Cantidad) {
        if (producto.L == NumeroAjustar) {
            cout << "Cantidad actual: " << producto.Cantidad << endl;
            cout << "Ingrese la nueva cantidad: ";
            cin >> nuevaCantidad;
            producto.Cantidad = nuevaCantidad;
        }
        archivoSalida << producto.L << " " << producto.NombreP << " " << producto.Precio << " " << producto.Cantidad << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("Productos.txt");
    rename("temp.txt", "Productos.txt");

    cout << "Inventario ajustado correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menú principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarProveedores() {
    system("cls");
    ifstream archivoProveedores("Proveedores.txt");
    DatosProveedor proveedor;

    while (archivoProveedores >> proveedor.NumeroProveedor >> proveedor.NombreProveedor
                              >> proveedor.ProductoSuministrado >> proveedor.Contacto) {
        cout << "Numero: " << proveedor.NumeroProveedor << "\tNombre: " << proveedor.NombreProveedor
             << "\tProducto: " << proveedor.ProductoSuministrado << "\tContacto: " << proveedor.Contacto << endl;
    }

    archivoProveedores.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void IncluirProveedor() {
    system("cls");
    ofstream archivoProveedores("Proveedores.txt", ios::app);
    DatosProveedor nuevoProveedor;

    cout << "Ingrese el numero del proveedor: "<<endl;
    cin >> nuevoProveedor.NumeroProveedor;
    cout << "Ingrese el nombre del proveedor: "<<endl;
    cin.ignore();
    getline(cin, nuevoProveedor.NombreProveedor);
    cout << "Ingrese el producto suministrado: "<<endl;
    getline(cin, nuevoProveedor.ProductoSuministrado);
    cout << "Ingrese el contacto del proveedor: "<<endl;
    getline(cin, nuevoProveedor.Contacto);

    archivoProveedores << nuevoProveedor.NumeroProveedor << " " << nuevoProveedor.NombreProveedor
                       << " " << nuevoProveedor.ProductoSuministrado << " " << nuevoProveedor.Contacto << endl;
    archivoProveedores.close();

    cout << "Proveedor incluido correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void EliminarProveedor() {
    system("cls");
    MostrarProveedores();

    int NumeroEliminar;
    cout << "Ingrese el numero del proveedor a eliminar: ";
    cin >> NumeroEliminar;

    ifstream archivoEntrada("Proveedores.txt");
    ofstream archivoSalida("temp.txt");

    DatosProveedor proveedor;
    while (archivoEntrada >> proveedor.NumeroProveedor >> proveedor.NombreProveedor
                          >> proveedor.ProductoSuministrado >> proveedor.Contacto) {
        if (proveedor.NumeroProveedor != NumeroEliminar) {
            archivoSalida << proveedor.NumeroProveedor << " " << proveedor.NombreProveedor
                           << " " << proveedor.ProductoSuministrado << " " << proveedor.Contacto << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("Proveedores.txt");
    rename("temp.txt", "Proveedores.txt");

    cout << "Proveedor eliminado correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void ModificarProveedor() {
    system("cls");
    MostrarProveedores();

    int NumeroModificar;
    cout << "Ingrese el numero del proveedor a modificar: ";
    cin >> NumeroModificar;

    ifstream archivoEntrada("Proveedores.txt");
    ofstream archivoSalida("temp.txt");

    DatosProveedor proveedor;
    while (archivoEntrada >> proveedor.NumeroProveedor >> proveedor.NombreProveedor
                          >> proveedor.ProductoSuministrado >> proveedor.Contacto) {
        if (proveedor.NumeroProveedor == NumeroModificar) {
            cout << "Opciones de modificacion:" << endl;
            cout << "1. Nombre del proveedor" << endl;
            cout << "2. Producto suministrado" << endl;
            cout << "3. Contacto del proveedor" << endl;
            cout << "Seleccione una opcion: ";
            int opcionModificar;
            cin >> opcionModificar;

            if (opcionModificar == 1) {
                cout << "Ingrese el nuevo nombre: ";
                cin.ignore();
                getline(cin, proveedor.NombreProveedor);
            } else if (opcionModificar == 2) {
                cout << "Ingrese el nuevo producto suministrado: ";
                cin.ignore();
                getline(cin, proveedor.ProductoSuministrado);
            } else if (opcionModificar == 3) {
                cout << "Ingrese el nuevo contacto: ";
                cin.ignore();
                getline(cin, proveedor.Contacto);
            }
        }

        archivoSalida << proveedor.NumeroProveedor << " " << proveedor.NombreProveedor
                       << " " << proveedor.ProductoSuministrado << " " << proveedor.Contacto << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("Proveedores.txt");
    rename("temp.txt", "Proveedores.txt");

    cout << "Proveedor modificado correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarVentas() {
    system("cls");
    ifstream archivoVentas("Ventas.txt");
    DatosVenta venta;

    cout << left << setw(15) << "Numero Venta " << setw(15) << "Fecha"  << setw(20) << "Cliente "
         << setw(15) << "Producto " << setw(10) << "Precio " << setw(10) << "Cantidad "
         << setw(10) << "Subtotal " << setw(10) << "Impuesto " << setw(10) << "Total " << endl;

    while (archivoVentas >> venta.NumeroVenta >> venta.Fecha >> venta.Cliente
           >> venta.Producto >> venta.Precio >> venta.Cantidad
           >> venta.Subtotal >> venta.Impuesto >> venta.Total) {
        cout << left << setw(15) << venta.NumeroVenta << setw(15) << venta.Fecha << setw(20) << venta.Cliente
             << setw(15) << venta.Producto << setw(10) << venta.Precio
             << setw(10) << venta.Cantidad << setw(10) << venta.Subtotal << setw(10) << venta.Impuesto
             << setw(10) << venta.Total << endl;
    }

    archivoVentas.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void RealizarVenta() {
    system("cls");
    ofstream archivoVentas("Ventas.txt", ios::app);
    DatosVenta nuevaVenta;

    cout << "Ingrese el numero de la venta: "<<endl;
    cin >> nuevaVenta.NumeroVenta;
    cout << "Ingrese la fecha de la venta: "<<endl;
    cin >> nuevaVenta.Fecha;
    cout << "Ingrese el cliente: "<<endl;
    cin.ignore();
    getline(cin, nuevaVenta.Cliente);
    cout << "Ingrese el producto: "<<endl;
    getline(cin, nuevaVenta.Producto);
    cout << "Ingrese el precio del producto: "<<endl;
    cin >> nuevaVenta.Precio;
    cout << "Ingrese la cantidad: "<<endl;
    cin >> nuevaVenta.Cantidad;


    nuevaVenta.Subtotal = nuevaVenta.Precio * nuevaVenta.Cantidad;
    nuevaVenta.Impuesto = nuevaVenta.Subtotal * 0.12;  
    nuevaVenta.Total = nuevaVenta.Subtotal + nuevaVenta.Impuesto;

    archivoVentas << nuevaVenta.NumeroVenta << " " << nuevaVenta.Fecha << " " << nuevaVenta.Cliente
                   << " " << nuevaVenta.Producto << " " << nuevaVenta.Precio
                   << " " << nuevaVenta.Cantidad << " " << nuevaVenta.Subtotal << " " << nuevaVenta.Impuesto
                   << " " << nuevaVenta.Total << endl;
    archivoVentas.close();

    cout << "Venta realizada correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void MostrarCompras() {
    system("cls");
    ifstream archivoCompras("Compras.txt");
    DatosCompra compra;

    cout << left << setw(15) << "Numero Compra" << setw(15) << "Fecha Compra" << setw(15) << "Fecha Ingreso"
         << setw(15) << "Total" << endl;

    while (archivoCompras >> compra.NumeroCompra >> compra.FechaCompra >> compra.FechaIngreso >> compra.TotalCompra) {
        cout << left << setw(15) << compra.NumeroCompra << setw(15) << compra.FechaCompra << setw(15) << compra.FechaIngreso
             << setw(15) << compra.TotalCompra << endl;
    }

    archivoCompras.close();
    cout << "\nPresiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}

void RealizarCompra() {
    system("cls");
    ofstream archivoCompras("Compras.txt", ios::app);
    DatosCompra nuevaCompra;

    srand(time(0));
    nuevaCompra.NumeroCompra = rand();

    cout << "Ingrese la fecha de compra (DD/MM/AAAA): " <<endl,
    cin >> nuevaCompra.FechaCompra;
    cout << "Ingrese la fecha de ingreso (DD/MM/AAAA): " <<endl;
    cin >> nuevaCompra.FechaIngreso;
    cout << "Ingrese el total de la compra: " <<endl;
    cin >> nuevaCompra.TotalCompra;

    archivoCompras << nuevaCompra.NumeroCompra << "  " << nuevaCompra.FechaCompra << "  " << nuevaCompra.FechaIngreso
                   << "  " << nuevaCompra.TotalCompra << endl;
    archivoCompras.close();

    cout << "Compra registrada correctamente.\n";
    cout << "Presiona cualquier tecla para volver al menu principal." << endl;
    cin.ignore();
    cin.get();
}


int main() {
    while (1) {
        system("cls");

        cout << " ----      Facturadora       ---- " << endl;
        cout << " ----      1. Clientes       ---- " << endl;
        cout << " ----      2. Facturas       ---- " << endl;
        cout << " ----      3. Productos      ---- " << endl;
        cout << " ----      4. Inventario     ---- " << endl;
        cout << " ----      5. Proveedores    ---- " << endl;
        cout << " ----      6. Ventas         ---- " << endl;
        cout << " ----      7. compras        ---- " << endl;
        cout << " ----      8. Salir          ---- " << endl;

        int opcionMenu;
        cin >> opcionMenu;

        switch (opcionMenu) {
            case 1:
                system("cls");

                cout << " ----      Clientes      ---- " << endl;
                cout << " ----    1. Consulta     ---- " << endl;
                cout << " ----    2. Incluir      ---- " << endl;
                cout << " ----    3. Borrar       ---- " << endl;
                cout << " ----    4. Editar       ---- " << endl;
                cout << " ----    5. Regresar     ---- " << endl;

                int opcionClientes;
                cin >> opcionClientes;

                switch (opcionClientes) {
                    case 1:
                        MostrarClientes();
                        break;
                    case 2:
                        IncluirCliente();
                        break;
                    case 3:
                        EliminarCliente();
                        break;
                    case 4:
                        ModificarCliente();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break;
            case 2:
                system("cls");

                cout << " ----      Facturas      ---- " << endl;
                cout << " ----    1. Consulta      ---- " << endl;
                cout << " ----    2. Incluir      ---- " << endl;
                cout << " ----    3. Regresar     ---- " << endl;

                int opcionFacturas;
                cin >> opcionFacturas;

                switch (opcionFacturas) {
                    case 1:
                        MostrarFacturas();
                        break;
                    case 2:
                        IncluirFactura();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break;
            case 3:
                system("cls");

                cout << " ----      Productos      ---- " << endl;
                cout << " ----    1. Consulta      ---- " << endl;
                cout << " ----    2. Incluir      ---- " << endl;
                cout << " ----    3. Regresar     ---- " << endl;

                int opcionProductos;
                cin >> opcionProductos;

                switch (opcionProductos) {
                    case 1:
                        MostrarProductos();
                        break;
                    case 2:
                        IncluirProducto();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break;
            case 4:
            	system("cls");

                cout << " ----          inventarios          ---- " << endl;
                cout << " ----    1. Mostrar Inventario      ---- " << endl;
                cout << " ----    2. Ajustar inventario      ---- " << endl;
                cout << " ----         3. Regresar           ---- " << endl;

                int opcioninventarios;
                cin >> opcioninventarios;

                switch (opcioninventarios) {
                    case 1:
                        MostrarInventario();
                        break;
                    case 2:
                         AjustarInventario();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break;
            case 5:
                system("cls");

                cout << " ----     Proveedores    ---- " << endl;
                cout << " ----    1. Mostrar      ---- " << endl;
                cout << " ----    2. Incluir      ---- " << endl;
                cout << " ----    3. Borrar       ---- " << endl;
                cout << " ----    4. Editar       ---- " << endl;
                cout << " ----    5. Regresar     ---- " << endl;

                int opcionProveedores;
                cin >> opcionProveedores;

                switch (opcionProveedores) {
                    case 1:
                        MostrarProveedores();
                        break;
                    case 2:
                        IncluirProveedor();
                        break;
                    case 3:
                        EliminarProveedor();
                        break;
                    case 4:
                        ModificarProveedor();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break;
            case 6:
                system("cls");

                cout << " ----           Ventas        ---- " << endl;
                cout << " ----        1. Mostrar       ---- " << endl;
                cout << " ----    2. Realizar venta    ---- " << endl;
                cout << " ----        3. Regresar      ---- " << endl;

                int opcionVentas;
                cin >> opcionVentas;

                switch (opcionVentas) {
                    case 1:
                        MostrarVentas();
                        break;
                    case 2:
                        RealizarVenta();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
                break; 
                break;
            case 7:
            	 system("cls");

                cout << " ----          Compras          ---- " << endl;
                cout << " ----        1. Mostrar        ---- " << endl;
                cout << " ----    2. Realizar compra    ---- " << endl;
                cout << " ----        3. Regresar       ---- " << endl;

                int opcionCompras;
                cin >> opcionCompras;

                switch (opcionCompras) {
                    case 1:
                        MostrarCompras();
                        break;
                    case 2:
                        RealizarCompra();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opcion incorrecta." << endl;
                        break;
                }
            	break;
            case 8:
                return 0;
            default:
                cout << "Opcion incorrecta." << endl;
                break;
        }
    }

    return 0;
}

