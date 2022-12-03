#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

#include "fecha.h"
#include "ventaDetalle.h"
#include "ventaCabecera.h"
#include "usuario.h"
#include "plato.h"
#include "funciones.h"

bool buscarAdmin();
void generarAdmin();

int main(){
    setlocale(LC_ALL, "Spanish");
    int opc,dni,registrar,acceso;
    char contrasenia[9];
    bool existeContra,existeEmpleado,existeAdmin,existeCliente,encontroAdmin;
    encontroAdmin=buscarAdmin();
    if(encontroAdmin==false){
        generarAdmin();
    }
    while(true){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MENÚ PRINCIPAL       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MENÚ ADMIN"<<endl;
        cout<<"2) MENÚ EMPLEADOS"<<endl;
        cout<<"3) MENÚ CLIENTES"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    cout<<"<<<LOGIN ADMIN>>>"<<endl;
                    cout<<"DNI: ";
                    cin>>dni;
                    existeAdmin=buscarAdmin(dni);
                    if(existeAdmin==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(dni,contrasenia);
                        if(existeContra==true){
                            menuAdmin(dni);
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO EXISTE"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE"<<endl;
                        system("pause");
                    }
                break;
            case 2: system("cls");
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dni;
                    existeEmpleado=buscarEmpleado(dni);
                    if(existeEmpleado==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarEmpleadoContra(dni,contrasenia);
                        if(existeContra==true){
                            menuEmpleados(dni);
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA."<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO ES CORRECTO."<<endl;
                        system("pause");
                    }
                break;
            case 3: system("cls");
                    cout<<"¿YA ESTÁ REGISTRADO? SI(1)/NO(0)"<<endl;
                    cin>>acceso;
                    if(acceso==1){
                        system("cls");
                        cout<<"<<<LOGIN CLIENTE>>>"<<endl;
                        cout<<"DNI DEL CLIENTE: ";
                        cin>>dni;
                        if(dni!=0){
                            existeCliente=buscarCliente(dni);
                            if(existeCliente==true){
                                cout<<"CONTRASEÑA: ";
                                cargarCadena(contrasenia,8);
                                existeContra=buscarClienteContra(dni,contrasenia);
                                if(existeContra==true){
                                    menuCliente(dni);
                                }
                                else{
                                    cout<<"LA CONTRASEÑA NO ES CORRECTA."<<endl;
                                    system("pause");
                                }
                            }
                            else{
                                cout<<"EL DNI NO SE ENCUENTRA REGISTRADO."<<endl;
                                system("pause");
                            }
                        }
                    }
                    else{
                        system("cls");
                        cout<<"¿DESEA REGISTRARSE? SI(1)/NO(0)"<<endl;
                        cin>>registrar;
                        if(registrar==1){
                            registrarCliente();
                        }
                    }
                break;
            case 0: system("cls");
                cout<<"HASTA LUEGO."<<endl;
                return 0;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

bool buscarAdmin(){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getTipo()==1){
            return true;
        }
        pos++;
    }
    return false;
}

void generarAdmin(){
    Usuario reg;
    reg.setDNI(9999);
    reg.setTipo(1);
    reg.setNombre("IGNACIO");
    reg.setApellido("FARIAS");
    reg.setContrasenia("2022");
    reg.setTelefono("32654148");
    reg.setEstado(true);
    reg.grabarEnDisco();
}

///MENU CLIENTES
void menuCliente(int dniCliente){
    Usuario reg;
    int opc,pos;
    while(true){
        system("cls");
        pos=0;
        cout<<"*****************************"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*       MENÚ CLIENTES       *"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*****************************"<<endl<<endl;
        cout<<"-------CLIENTE LOGEADO-------"<<endl;
        while(reg.leerDeDisco(pos)){
            if(reg.getDNI()==dniCliente && reg.getTipo()==3){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"------------------------------"<<endl;
        cout<<"1) CREAR PEDIDO"<<endl;
        cout<<"2) CANCELAR PEDIDO"<<endl;
        cout<<"3) MENÚ PEDIDOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: crearPedido(dniCliente);
                break;
            case 2: cancelarPedido(dniCliente);
                break;
            case 3: menuVentasCliente(dniCliente);
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}
///

///MENU EMPLEADOS
void menuEmpleados(int dniEmpleado){
    Usuario reg;
    int opc,pos;
    while(true){
        system("cls");
        pos=0;
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MENÚ EMPLEADOS       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"-------EMPLEADO LOGEADO-------"<<endl;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNI()==dniEmpleado && reg.getTipo()==2){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<endl;
        cout<<"------------------------------"<<endl;
        cout<<endl;
        cout<<"        <<<****PLATOS****>>>        "<<endl;
        cout<<"1) MENÚ PLATOS"<<endl;
        cout<<endl;
        cout<<"        <<<****VENTAS****>>>        "<<endl;
        cout<<"2) MOSTRAR VENTAS"<<endl;
        cout<<"4) COBRAR VENTAS"<<endl;
        cout<<"5) MOSTRAR VENTAS COBRADAS"<<endl;
        cout<<"6) MOSTRAR VENTAS CANCELADAS"<<endl;
        cout<<endl;
        cout<<"        <<<****CLIENTE****>>>        "<<endl;
        cout<<"3) ATENDER CLIENTE"<<endl;
        cout<<"7) MOSTRAR CLIENTES REGISTRADOS"<<endl;
        cout<<endl;
        cout<<"        <<<****REPORTES****>>>        "<<endl;
        cout<<"8) REPORTES"<<endl;
        cout<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: menuPlatos();
                break;
            case 2: mostrarVentas();
                break;
            case 3: cobrarVentas(dniEmpleado);
                break;
            case 4: mostrarVentasCobradas();
                break;
            case 5: mostrarVentasCanceladas();
                break;
            case 6: atenderCliente(dniEmpleado);
                break;
            case 7: mostrarClientesRegistrados();
                break;
            case 8: reportes();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}
///


///MENU ADMIN
void menuAdmin(int dniAdmin){
    Usuario reg;
    int opc,dniCliente,pos,dniEmpleado;
    bool existeCliente,existeEmpleado,cancelarOperacion,cantReg=false;
    while(true){
        system("cls");
        pos=0;
        cancelarOperacion=false;
        cout<<"**************************"<<endl;
        cout<<"*      ACCESO ADMIN      *"<<endl;
        cout<<"**************************"<<endl<<endl;
        cout<<"--------ADMIN LOGEADO--------"<<endl;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNI()==dniAdmin && reg.getTipo()==1){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"------------------------------"<<endl;
        cout<<"     <<<****CLIENTE****>>>    "<<endl;
        cout<<"1) MODIFICAR DATOS DEL CLIENTE"<<endl;
        cout<<"2) DAR DE BAJA AL CLIENTE"<<endl;
        cout<<endl;
        cout<<"     <<<****EMPLEADO****>>>    "<<endl;
        cout<<"3) REGISTRAR NUEVO EMPLEADO"<<endl;
        cout<<"4) MOSTRAR EMPLEADOS REGISTRADOS"<<endl;
        cout<<"5) MODIFICAR DATOS DEL EMPLEADO"<<endl;
        cout<<"6) DAR DE BAJA AL EMPLEADO"<<endl;
        cout<<endl;
        cout<<"     <<<****ADMIN****>>>    "<<endl;
        cout<<"7) REGISTRAR A UN NUEVO ADMINISTRADOR"<<endl;
        cout<<"8) MOSTRAR ADMINISTRADORES REGISTRADOS"<<endl;
        cout<<"9) DAR DE BAJA A UN ADMINISTRADOR"<<endl;
        cout<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        pos=0;
        switch(opc){
            case 1: system("cls");
                    cout<<"    <<<ESCOJER CLIENTE>>>"<<endl;
                    cout<<"------------------------------"<<endl;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getEstado()==true && reg.getTipo()==3){
                            cantReg=true;
                        }
                        pos++;
                    }
                    if(cantReg==true){
                        pos=0;
                        while(reg.leerDeDisco(pos)==1){
                            if(reg.getEstado()==true && reg.getTipo()==3){
                                reg.Mostrar();
                                cout<<"------------------------------"<<endl;
                            }
                            pos++;
                        }
                        cout<<"DNI DEL CLIENTE: ";
                        cin>>dniCliente;
                        if(dniCliente==0){
                            cancelarOperacion=true;
                        }
                        if(cancelarOperacion==false){
                            existeCliente=buscarCliente(dniCliente);
                            if(existeCliente==true){
                                modificarDatosCliente(dniCliente);
                            }
                            else{
                                cout<<endl;
                                cout<<"EL CLIENTE NO EXISTE O EL DNI NO ES CORRECTO."<<endl;
                                system("pause");
                            }
                        }
                    }
                    else{
                        cout<<"NO SE ENCONTRO NINGÚN CLIENTE."<<endl;
                        system("pause");
                    }
                break;
            case 2: bajaCliente();
                break;
            case 3: crearEmpleado();
                break;
            case 4: mostrarEmpleadosRegistrados();
                break;
            case 5: system("cls");
                    cout<<"    <<<ESCOJER EMPLEADO>>>"<<endl;
                    cout<<"------------------------------"<<endl;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getEstado()==true && reg.getTipo()==2){
                            cantReg=true;
                        }
                        pos++;
                    }
                    if(cantReg==true){
                        pos=0;
                        while(reg.leerDeDisco(pos)==1){
                            if(reg.getEstado()==true && reg.getTipo()==2){
                                reg.Mostrar();
                                cout<<"------------------------------"<<endl;
                            }
                            pos++;
                        }
                        cout<<"DNI DEL EMPLEADO: ";
                        cin>>dniEmpleado;
                        if(dniEmpleado==0){
                            cancelarOperacion=true;
                        }
                        if(cancelarOperacion==false){
                            existeEmpleado=buscarEmpleado(dniEmpleado);
                            if(existeEmpleado==true){
                                modificarDatosEmpleado(dniEmpleado);
                            }
                            else{
                                cout<<endl;
                                cout<<"EL EMPLEADO NO EXISTE O EL DNI NO ES CORRECTO."<<endl;
                                system("pause");
                            }
                        }
                    }
                    else{
                        cout<<"NO SE ENCONTRO NINGÚN EMPLEADO."<<endl;
                        system("pause");
                    }
                break;
            case 6: bajaEmpleado();
                break;
            case 7: crearAdmin();
                break;
            case 8: mostrarAdminsRegistrados();
                break;
            case 9: bajaAdmin();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}
///


///MENU PLATOS
void menuPlatos(){
    int opc;
    while(true){
        system("cls");
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*         MENÚ PLATOS         *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) AGREGAR PLATO"<<endl;
        cout<<"2) MOSTRAR PLATO POR CODIGO"<<endl;
        cout<<"3) MOSTRAR TODOS LOS PLATOS"<<endl;
        cout<<"4) AGREGAR STOCK"<<endl;
        cout<<"5) MODIFICAR NOMBRE DEL PLATO"<<endl;
        cout<<"6) MODIFICAR DESCRIPCIÓN DEL PLATO"<<endl;
        cout<<"7) MODIFCAR PRECIO DEL PLATO"<<endl;
        cout<<"8) MODIFICAR STOCK"<<endl;
        cout<<"9) ELIMINAR PLATO"<<endl;
        cout<<"10) RESTABLECER PLATO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: agregarPlato();
                break;
            case 2: mostrarPorCodigo();
                break;
            case 3: mostrarPlatos();
                break;
            case 4: agregarStock();
                break;
            case 5: modificarNombre();
                break;
            case 6: modificarDescripcion();
                break;
            case 7: modificarPrecio();
                break;
            case 8: modificarStock();
                break;
            case 9: eliminarPlato();
                break;
            case 10: restablecerPlato();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                system("pause");
                break;
        }
    }
}
///
