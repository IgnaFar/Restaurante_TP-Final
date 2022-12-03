#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS GLOBALES
bool buscarPlato(const char *);

bool buscarCliente(int);

bool buscarClienteContra(int,const char *);

bool buscarEmpleado(int);

bool buscarEmpleadoContra(int,const char *);
///


///PROTOTIPOS

///MENU ADMIN
bool buscarAdmin(int);

bool buscarAdminContra(int,const char *);

void menuAdmin(int);
void crearEmpleado();
void modificarDatosCliente(int);
void modificarDatosEmpleado(int);
void bajaCliente();
void bajaEmpleado();
void mostrarAdminsRegistrados();
void crearAdmin();
void bajaAdmin();
void darBajaAdmin(int);

///

///MENU PLATOS
void menuPlatos();

void agregarPlato();

void mostrarPorCodigo();

void mostrarPlatos();

void agregarStock();

void modificarNombre();
void cambiarNombre(const char *,const char *);

void modificarDescripcion();
void cambiarDescripcion(const char *,const char *);

void modificarPrecio();
void cambiarPrecio(const char *,float);

void modificarStock();
void cambiarStock(const char *,int);

void eliminarPlato();

void restablecerPlato();
///


///MENU EMPLEADOS
void menuEmpleados(int);

void mostrarEmpleadosRegistrados();

void mostrarClientesRegistrados();

void reportes();
void importeTotalRecaudado();
///


///MENU CLIENTES
void menuCliente(int);

void registrarCliente();

void crearPedido(int);
int generarIDVenta();
int generarIDDetalle();
int traerIDDetalle();
void traerPlato();
int chequearStock(const char *,int);
float importePlato(const char *,int);
void disminuirStock(const char *,int);
void restanteStock(const char *);

void cancelarPedido(int);
void cancelarDetalle(int);
void devolverStock(const char *,int);
///


///MENU VENTAS Y PEDIDOS
void menuVentasPedidos();

void menuVentasCliente(int);
void mostrarPedido(int);
int contarRegistrosPorID(int);
float acumlarPrecio(int);

void mostrarVentas();
bool clienteNoAtendido(int);
int traerCliente(int);
void atenderCliente(int);
bool buscarIDDetalle(int);
void atenderAlCliente(int,int);

void cobrarVentas(int);
bool buscarClienteAtendido(int);
bool buscarDetalle(int);
void buscarVenta(int,int);

void mostrarVentasCobradas();

void mostrarVentasCanceladas();
///


///FUNCIONES GLOBALES
bool buscarPlato(const char *codPlat){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarCliente(int dni){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dni && reg.getTipo()==3 && reg.getEstado()==true){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarClienteContra(int dniCliente,const char *contrasenia){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0 && reg.getDNI()==dniCliente && reg.getTipo()==3){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarEmpleado(int dniEmp){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dniEmp && reg.getTipo()==2 && reg.getEstado()==true){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarEmpleadoContra(int dniEmpleado,const char *contrasenia){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0 && reg.getDNI()==dniEmpleado && reg.getTipo()==2){
            return true;
        }
        pos++;
    }
    return false;
}
///


///MENU ADMIN
bool buscarAdmin(int dni){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dni && reg.getTipo()==1 && reg.getEstado()==true){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarAdminContra(int dniAdmin,const char *contrasenia){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0 && reg.getDNI()==dniAdmin && reg.getTipo()==1){
            return true;
        }
        pos++;
    }
    return false;
}

void mostrarEmpleadosRegistrados(){
    system("cls");
    Usuario reg;
    int pos=0;
    bool cantReg=false;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*   EMPLEADOS REGISTRADOS   *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true && reg.getTipo()==2){
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false){
        cout<<"NO SE ENCONTRÓ NINGÚN EMPLEADO."<<endl;
    }
    else{
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getEstado()==true && reg.getTipo()==2){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
            }
            pos++;
        }
    }
    system("pause");
}

void crearEmpleado(){
    system("cls");
    Usuario reg;
    int dni,tipo=2;
    bool existeEmpleado=false;
    cout<<"**************************"<<endl;
    cout<<"*   REGISTRAR EMPLEADO   *"<<endl;
    cout<<"**************************"<<endl<<endl;
    cout<<"DNI: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    existeEmpleado=buscarEmpleado(dni);
    if(existeEmpleado==false){
        reg.setDNI(dni);
        reg.Cargar(tipo);
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL EMPLEADO YA EXISTE."<<endl;
        system("pause");
    }
}

void modificarDatosCliente(int dniCliente){
    Usuario reg;
    VentaCabecera aux;
    int opc,pos,dniNuevo,dniExtra;
    char nombre[30],apellido[30],contrasenia[9],telefono[15];
    while(true){
        system("cls");
        pos=0;
        cout<<"*************************************"<<endl;
        cout<<"*    MODIFICAR DATOS DEL CLIENTE    *"<<endl;
        cout<<"*************************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MODIFICAR DNI"<<endl;
        cout<<"2) MODIFICAR NOMBRE"<<endl;
        cout<<"3) MODIFICAR APELLIDO"<<endl;
        cout<<"4) MODIFICAR CONTRASEÑA"<<endl;
        cout<<"5) MODIFICAR TELÉFONO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: cout<<endl;
                    cout<<"NUÉVO DNI: ";
                    cin>>dniNuevo;
                    while(aux.leerDeDisco(pos)==1){
                        if(aux.getDNICliente()==dniCliente){
                            aux.setDNICliente(dniNuevo);
                            aux.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    pos=0;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente && reg.getTipo()==3){
                            dniExtra=dniNuevo;
                            reg.setDNI(dniNuevo);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<DNI ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 2: cout<<endl;
                    cout<<"NUÉVO NOMBRE: ";
                    cargarCadena(nombre,29);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniCliente && reg.getTipo()==3) || (reg.getDNI()==dniExtra && reg.getTipo()==3)){
                            reg.setNombre(nombre);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<NOMBRE ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 3: cout<<endl;
                    cout<<"NUÉVO APELLIDO: ";
                    cargarCadena(apellido,29);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniCliente && reg.getTipo()==3) || (reg.getDNI()==dniExtra && reg.getTipo()==3)){
                            reg.setApellido(apellido);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<APELLIDO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 4: cout<<endl;
                    cout<<"NUÉVA CONTRASEÑA: ";
                    cargarCadena(contrasenia,8);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniCliente && reg.getTipo()==3) || (reg.getDNI()==dniExtra && reg.getTipo()==3)){
                            reg.setContrasenia(contrasenia);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<CONTRASEÑA ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 5: cout<<endl;
                    cout<<"NUÉVO NÚMERO DE TELÉFONO (CARACTERES): ";
                    cargarCadena(telefono,14);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniCliente && reg.getTipo()==3) || (reg.getDNI()==dniExtra && reg.getTipo()==3)){
                            reg.setTelefono(telefono);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<TELÉFONO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}

void modificarDatosEmpleado(int dniEmpleado){
    Usuario reg;
    VentaCabecera aux;
    int opc,pos,dniNuevo,dniExtra;
    char nombre[30],apellido[30],contrasenia[9];
    while(true){
        system("cls");
        pos=0;
        cout<<"**************************************"<<endl;
        cout<<"*    MODIFICAR DATOS DEL EMPLEADO    *"<<endl;
        cout<<"**************************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MODIFICAR DNI"<<endl;
        cout<<"2) MODIFICAR NOMBRE"<<endl;
        cout<<"3) MODIFICAR APELLIDO"<<endl;
        cout<<"4) MODIFICAR CONTRASEÑA"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: cout<<endl;
                    cout<<"NUÉVO DNI: ";
                    cin>>dniNuevo;
                    while(aux.leerDeDisco(pos)==1){
                        if(aux.getDNIEmpleado()==dniEmpleado){
                            aux.setDNIEmpleado(dniNuevo);
                            aux.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    pos=0;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniEmpleado && reg.getTipo()==2){
                            dniExtra=dniNuevo;
                            reg.setDNI(dniNuevo);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<DNI ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 2: cout<<endl;
                    cout<<"NUÉVO NOMBRE: ";
                    cargarCadena(nombre,29);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniEmpleado && reg.getTipo()==2) || (reg.getDNI()==dniExtra && reg.getTipo()==2)){
                            reg.setNombre(nombre);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<NOMBRE ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 3: cout<<endl;
                    cout<<"NUÉVO APELLIDO: ";
                    cargarCadena(apellido,29);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniEmpleado && reg.getTipo()==2) || (reg.getDNI()==dniExtra && reg.getTipo()==2)){
                            reg.setApellido(apellido);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<APELLIDO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 4: cout<<endl;
                    cout<<"NUÉVA CONTRASEÑA: ";
                    cargarCadena(contrasenia,8);
                    while(reg.leerDeDisco(pos)==1){
                        if((reg.getDNI()==dniEmpleado && reg.getTipo()==2) || (reg.getDNI()==dniExtra && reg.getTipo()==2)){
                            reg.setContrasenia(contrasenia);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<CONTRASEÑA ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}

void bajaCliente(){
    system("cls");
    Usuario reg;
    int pos=0,dniCliente;
    bool cantReg=false,existeCliente;
    cout<<"*******************************"<<endl;
    cout<<"*    DAR DE BAJA A CLIENTE    *"<<endl;
    cout<<"*******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getTipo()==3 && reg.getEstado()==true){
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getTipo()==3 && reg.getEstado()==true){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"ESCOJA EL DNI DE UN CLIENTE: ";
        cin>>dniCliente;
        if(dniCliente==0){
            return;
        }
        existeCliente=buscarCliente(dniCliente);
        if(existeCliente==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getDNI()==dniCliente && reg.getTipo()==3){
                    reg.setEstado(false);
                    reg.modificarEnDisco(pos);
                    cout<<"<<<SE DIÓ DE BAJA AL CLIENTE.>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<endl;
            cout<<"EL DNI NO EXISTE."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY CLIENTES REGISTRADOS AÚN."<<endl;
        system("pause");
    }
}

void bajaEmpleado(){
    system("cls");
    Usuario reg;
    int pos=0,dniEmpleado;
    bool cantReg=false,existeEmpleado;
    cout<<"********************************"<<endl;
    cout<<"*    DAR DE BAJA A EMPLEADO    *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getTipo()==2 && reg.getEstado()==true){
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getTipo()==2 && reg.getEstado()==true){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"ESCOJA EL DNI DE UN EMPLEADO: ";
        cin>>dniEmpleado;
        if(dniEmpleado==0){
            return;
        }
        existeEmpleado=buscarEmpleado(dniEmpleado);
        if(existeEmpleado==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getDNI()==dniEmpleado && reg.getTipo()==2){
                    reg.setEstado(false);
                    reg.modificarEnDisco(pos);
                    cout<<"<<<SE DIÓ DE BAJA AL EMPLEADO.>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<endl;
            cout<<"EL DNI NO EXISTE."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY EMPLEADOS REGISTRADOS AÚN."<<endl;
        system("pause");
    }
}

void mostrarAdminsRegistrados(){
    system("cls");
    Usuario reg;
    int pos=0;
    cout<<"***********************************"<<endl;
    cout<<"*                                 *"<<endl;
    cout<<"*   ADMINISTRADORES REGISTRADOS   *"<<endl;
    cout<<"*                                 *"<<endl;
    cout<<"***********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getTipo()==1 && reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void crearAdmin(){
    system("cls");
    Usuario reg;
    int dni;
    bool existeAdmin,tipo=1;
    cout<<"*******************************"<<endl;
    cout<<"*    REGISTRAR NUEVO ADMIN    *"<<endl;
    cout<<"*******************************"<<endl<<endl;
    cout<<"DNI: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    existeAdmin=buscarAdmin(dni);
    if(existeAdmin==false){
        reg.setDNI(dni);
        reg.Cargar(tipo);
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL ADMIN YA EXISTE."<<endl;
        system("pause");
    }
}

void bajaAdmin(){
    system("cls");
    Usuario reg;
    int pos=0,cantidad=0,dniAdmin;
    bool existeAdmin;
    cout<<"*****************************"<<endl;
    cout<<"*    DAR DE BAJA A ADMIN    *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getTipo()==1 && reg.getEstado()==true){
            cantidad++;
        }
        pos++;
    }
    if(cantidad==1){
        cout<<"PARA DAR DE BAJA A UN ADMIN ES NECESARIO QUE HAYA MÁS DE UNO."<<endl;
        system("pause");
    }
    else{
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getTipo()==1){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"ESCOJA EL DNI DEL ADMIN: ";
        cin>>dniAdmin;
        if(dniAdmin==0){
            return;
        }
        existeAdmin=buscarAdmin(dniAdmin);
        if(existeAdmin==true){
            darBajaAdmin(dniAdmin);
            cout<<endl;
            cout<<"<<<EL ADMIN SE DIÓ DE BAJA.>>>"<<endl;
            system("pause");
        }
        else{
            cout<<"EL DNI NO EXISTE O NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
}

void darBajaAdmin(int dniAdmin){
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dniAdmin && reg.getTipo()==1){
            reg.setEstado(false);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}
///


///FUNCIONES

///MENU PLATOS
void agregarPlato(){
    system("cls");
    Plato reg;
    char codPlat[6];
    bool existePlato;
    cout<<"*************************"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*     AGREGAR PLATO     *"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*************************"<<endl<<endl;
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==false){
        reg.setCodigoPlato(codPlat);
        reg.Cargar();
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL CÓDIGO DE PLATO YA EXISTE."<<endl;
        system("pause");
    }
}

void mostrarPorCodigo(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6];
    bool existePlato;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*    MOSTRAR POR CÓDIGO    *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    cout<<endl;
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        while(reg.leerDeDisco(pos)==1){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                if(reg.getEstado()==1){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
            }
            pos++;
        }
    }
    if(existePlato==false) cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
    system("pause");
}

void mostrarPlatos(){
    system("cls");
    Plato reg;
    int pos=0;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*      MOSTRAR PLATOS      *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void agregarStock(){
    Plato reg;
    int pos=0,opc=-1,cantidad,totalCantidad=0;
    char codPlat[6];
    bool existePlato,agregar=true;
    while(opc!=0){
        while(agregar==true){
            system("cls");
            cout<<"*****************************"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*       AGREGAR STOCK       *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*****************************"<<endl<<endl;
            cout<<"----------------------------------"<<endl;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getEstado()==true){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
                pos++;
            }
            pos=0;
            cout<<"CÓDIGO DE PLATO: ";
            cargarCadena(codPlat,5);
            existePlato=buscarPlato(codPlat);
            if(existePlato==true){
                cout<<"CANTIDAD: ";
                cin>>cantidad;
                while(cantidad<=0){
                    system("cls");
                    cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                    cout<<"CANTIDAD: ";
                    cin>>cantidad;
                }
                while(reg.leerDeDisco(pos)==1){
                    if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                        totalCantidad=reg.getStock()+cantidad;
                        reg.setStock(totalCantidad);
                        reg.modificarEnDisco(pos);
                        cout<<"<<<STOCK AGREGADO.>>>"<<endl;
                        agregar=false;
                    }
                    pos++;
                }
            }
            else{
                cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
                agregar=false;
                system("pause");
            }
        }
        cout<<"¿QUIÉRE MODIFICAR ALGO MÁS? SI(1)/NO(0)"<<endl;
        cin>>opc;
        switch(opc){
            case 1: pos=0;
                    agregar=true;
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    agregar=false;
                    system("pause");
                break;
        }
    }
}

void modificarNombre(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6],nuevoNombre[30];
    bool existePlato;
    cout<<"******************************"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"*      MODIFICAR NOMBRE      *"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        cout<<"NUEVO NOMBRE PARA EL PLATO: ";
        cargarCadena(nuevoNombre,29);
        cambiarNombre(codPlat,nuevoNombre);
        cout<<endl;
        cout<<"<<<NOMBRE MODIFICADO.>>>"<<endl;
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarNombre(const char *codPlat,const char *nuevoNombre){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setNombre(nuevoNombre);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarDescripcion(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6],nuevaDescrip[30];
    bool existePlato;
    cout<<"*******************************"<<endl;
    cout<<"*                             *"<<endl;
    cout<<"*    MODIFICAR DESCRIPCIÓN    *"<<endl;
    cout<<"*                             *"<<endl;
    cout<<"*******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        cout<<"NUEVA DESCRIPCIÓN PARA EL PLATO: ";
        cargarCadena(nuevaDescrip,29);
        cambiarDescripcion(codPlat,nuevaDescrip);
        cout<<endl;
        cout<<"<<<DESCRIPCIÓN MODIFICADA.>>>"<<endl;
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarDescripcion(const char *codPlat,const char *nuevaDescrip){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setDescripcion(nuevaDescrip);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarPrecio(){
    system("cls");
    Plato reg;
    int pos=0;
    float nuevoPrecio;
    char codPlat[6];
    bool existePlato;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*       MODIFICAR PRECIO       *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        cout<<"NUÉVO PRECIO: ";
        cin>>nuevoPrecio;
        cambiarPrecio(codPlat,nuevoPrecio);
        cout<<endl;
        cout<<"<<<PRECIO ACTUALIZADO>>>"<<endl;
        system("pause");
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarPrecio(const char *codPlat,float nuevoPrecio){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setPrecio(nuevoPrecio);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarStock(){
    system("cls");
    Plato reg;
    int pos=0,nuevoStock;
    char codPlat[6];
    bool existePlato;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*        MODIFICAR STOCK        *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        cout<<"NUÉVA CANTIDAD DE STOCK: ";
        cin>>nuevoStock;
        while(nuevoStock<=0){
            cout<<"LA CANTIDAD DE STOCK TIENE QUE SER MAYOR A 0."<<endl;
            cout<<"NUÉVA CANTIDAD DE STOCK: ";
            cin>>nuevoStock;
        }
        cambiarStock(codPlat,nuevoStock);
        cout<<endl;
        cout<<"<<<STOCK ACTUALIZADO>>>"<<endl;
        system("pause");
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarStock(const char *codPlat,int nuevoStock){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getEstado()==true){
                reg.setStock(nuevoStock);
                reg.modificarEnDisco(pos);
            }
            else{
                reg.setEstado(true);
                reg.setStock(nuevoStock);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
    }
}

void eliminarPlato(){
    system("cls");
    Plato reg;
    int pos=0,cantReg=0;
    char codPlat[6];
    bool existePlato;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*      ELIMINAR PLATO      *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg++;
        }
        pos++;
    }
    if(cantReg>0){
        cout<<"CÓDIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==1){
                    reg.setEstado(0);
                    reg.modificarEnDisco(pos);
                    cout<<"<<<PLATO ELIMINADO>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY PLATOS A ELIMINAR."<<endl;
        system("pause");
    }
}

void restablecerPlato(){
    system("cls");
    Plato reg;
    int pos=0,cantidad;
    char codPlat[6];
    bool existePlato,cantReg=false;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*     RESTABLECER PLATO     *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==false){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        cout<<"CÓDIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==0){
                    if(reg.getStock()==0){
                        cout<<"CANTIDAD DE STOCK: ";
                        cin>>cantidad;
                        while(cantidad<=0){
                            cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl;
                            cout<<"CANTIDAD DE STOCK: ";
                            cin>>cantidad;
                        }
                        reg.setStock(cantidad);
                        reg.setEstado(true);
                        reg.modificarEnDisco(pos);
                    }
                    else{
                        reg.setEstado(true);
                        reg.modificarEnDisco(pos);
                    }
                    cout<<"<<<PLATO RESTABLECIDO>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY PLATOS PARA RESTABLECER."<<endl;
        system("pause");
    }
}

void mostrarClientesRegistrados(){
    system("cls");
    Usuario reg;
    int pos=0;
    bool cantReg=false;
    cout<<"******************************"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"*    CLIENTES REGISTRADOS    *"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true && reg.getTipo()==3){
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        if(reg.getEstado()==true && reg.getTipo()==3){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
    }
    else{
        cout<<"NO HAY CLIENTES REGISTRADOS AÚN."<<endl;
    }
    system("pause");
}

void reportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*        MENÚ REPORTES        *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"1) IMPORTE TOTAL RECAUDADO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: importeTotalRecaudado();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}

void importeTotalRecaudado(){
    VentaCabecera reg;
    int pos=0;
    float acumImporte=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-2){
            acumImporte+=reg.getImporte();
        }
        pos++;
    }
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"       IMPORTE TOTAL: $"<<acumImporte<<endl;
    cout<<"**************************************"<<endl;
    system("pause");
}
///


///MENU CLIENTES
void registrarCliente(){
    system("cls");
    Usuario reg;
    int dni,tipo=3;
    bool existeCliente;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*     REGISTRAR CLIENTE     *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    cout<<"DNI DEL CLIENTE: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    existeCliente=buscarCliente(dni);
    if(existeCliente==false){
        reg.setDNI(dni);
        reg.Cargar(tipo);
        reg.grabarEnDisco();
        cout<<endl;
        cout<<"<<<CLIENTE REGISTRADO>>>"<<endl;
    }
    if(existeCliente==true) cout<<"EL CLIENTE YA EXISTE."<<endl;
    system("pause");
}

void crearPedido(int dniCliente){
    VentaCabecera reg;
    VentaDetalle aux;
    int idventa,otroPedido=1,opc,cantidad,numeroGrande,iddetalle;
    char codPlat[6];
    float importe;
    bool repetir=false,pedido=true,existePlato,sacarStock;
    while(otroPedido==1){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*        CREAR PEDIDO        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        idventa=generarIDVenta();
        sacarStock=false;
        if(repetir==false){
            iddetalle=generarIDDetalle();
            reg.Cargar(idventa,iddetalle,dniCliente);
            cout<<endl;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"CÓDIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    while(sacarStock==false){
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                        if(cantidad<=0){
                            cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                        }
                        else{
                            numeroGrande=chequearStock(codPlat,cantidad);
                            if(numeroGrande<0){
                                cout<<"LA CANTIDAD SOBREPASA EL STOCK."<<endl;
                                system("pause");
                            }
                            else{
                                importe=importePlato(codPlat,cantidad);
                                pedido=false;
                                reg.setImporte(importe);
                                reg.grabarEnDisco();
                                disminuirStock(codPlat,cantidad);
                                aux.Cargar(idventa,iddetalle,codPlat,cantidad,importe);
                                aux.grabarEnDisco();
                                repetir=true;
                                sacarStock=true;
                                restanteStock(codPlat);
                            }
                        }
                    }
                }
                else{
                    cout<<"EL CÓDIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        else{
            pedido=true;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"CÓDIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    while(sacarStock==false){
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                        if(cantidad<=0){
                            cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                        }
                        else{
                            numeroGrande=chequearStock(codPlat,cantidad);
                            if(numeroGrande<0){
                                cout<<"LA CANTIDAD SOBREPASA EL STOCK."<<endl;
                                system("pause");
                            }
                            else{
                                importe=importePlato(codPlat,cantidad);
                                reg.setIDVenta(idventa);
                                reg.setImporte(importe);
                                reg.grabarEnDisco();
                                disminuirStock(codPlat,cantidad);
                                aux.setIDVenta(idventa);
                                aux.setCantidad(cantidad);
                                aux.setImporte(importe);
                                aux.grabarEnDisco();
                                pedido=false;
                                sacarStock=true;
                                restanteStock(codPlat);
                            }
                        }
                    }
                }
                else{
                    cout<<"EL CÓDIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        system("cls");
        cout<<"¿QUIÉRE AGREGAR ALGO MÁS? SI(1)/NO(0)"<<endl;
        cout<<"OPCIÓN -> ";
        cin>>opc;
        switch(opc){
            case 1: repetir=true;
                break;
            case 0: otroPedido=0;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
    cout<<"<<<DETALLE GENERADO>>>"<<endl;
}

int generarIDVenta(){
    VentaCabecera reg;
    int pos=0,idventa=1;
    while(reg.leerDeDisco(pos)==1){
        idventa++;
        pos++;
    }
    return idventa;
}

int generarIDDetalle(){
    VentaCabecera reg;
    int pos=0,cant=1,iddetalle;
    while(reg.leerDeDisco(pos)==1){
        cant++;
        pos++;
    }
    if(cant==1){
        return cant;
    }
    else{
        iddetalle=traerIDDetalle();
        return iddetalle;
    }
}

int traerIDDetalle(){
    VentaCabecera reg;
    int pos=0,iddetalle;
    while(reg.leerDeDisco(pos)==1){
        iddetalle=reg.getIDDetalle();
        pos++;
    }
    return iddetalle+1;
}

void traerPlato(){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
}

int chequearStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0,restarCant;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            restarCant=reg.getStock()-cantidad;
            return restarCant;
        }
        pos++;
    }
    return -1;
}

float importePlato(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0;
    float importe;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            importe=reg.getPrecio()*cantidad;
        }
        pos++;
    }
    return importe;
}

void disminuirStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0,totalStock;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            totalStock=reg.getStock()-cantidad;
            reg.setStock(totalStock);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void restanteStock(const char *codPlat){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getStock()==0){
                reg.setEstado(false);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
    }
}

void cancelarPedido(int dni){
    VentaCabecera reg;
    int pos,iddetalle,opc;
    bool cancelarOtro=true,cantReg,errorDetalle=false;
    while(cancelarOtro==true){
        system("cls");
        pos=0;
        cantReg=false;
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*       CANCELAR PEDIDO       *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"----------------------------------"<<endl;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNICliente()==dni){
                if(reg.getDNIEmpleado()>=0){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                    cantReg=true;
                }
            }
            pos++;
        }
        if(cantReg==false){
            cout<<"EL CLIENTE NO TIENE NINGÚN PEDIDO."<<endl;
            system("pause");
            return;
        }
        else{
            cout<<"ID DE DETALLE: ";
            cin>>iddetalle;
            if(iddetalle==0){
                return;
            }
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getIDDetalle()==iddetalle && reg.getDNICliente()==dni){
                    reg.setDNIEmpleado(-1);
                    reg.modificarEnDisco(pos);
                    cancelarDetalle(iddetalle);
                    errorDetalle=true;
                    cout<<"<<<PEDIDO CANCELADO>>>"<<endl;
                }
                pos++;
            }
            if(errorDetalle==false){
                cout<<"EL ID DE DETALLE INGRESADO NO EXISTE."<<endl;
                system("pause");
            }
            cout<<"¿QUIÉRE CANCELAR ALGO MÁS? SI(1)/NO(0)"<<endl;
            cin>>opc;
            switch(opc){
                case 1: cancelarOtro=true;
                    break;
                case 0: cancelarOtro=false;
                    break;
                default: cout<<"OPCIÓN INCORRECTA."<<endl;
                        system("pause");
                    break;
            }
        }
    }
}

void cancelarDetalle(int iddetalle){
    VentaDetalle reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            devolverStock(reg.getIDPlato(),reg.getCantidad());
            reg.setEstado(false);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void devolverStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getEstado()==true){
                reg.setStock(reg.getStock()+cantidad);
                reg.modificarEnDisco(pos);
            }
            else{
                reg.setEstado(true);
                reg.setStock(reg.getStock()+cantidad);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
    }
}
///


///MENU VENTAS/PEDIDOS

///MENU PEDIDOS CLIENTES
void menuVentasCliente(int dni){
    int opc;
    while(true){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*        MENÚ PEDIDOS        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR PEDIDO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarPedido(dni);
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

void mostrarPedido(int dni){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    float acumPrecio,registrosLeidos,cantRegistros=0;
    bool cantReg=false;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*        MOSTRAR PEDIDO        *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNICliente()==dni && reg.getDNIEmpleado()>=0){
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNICliente()==dni && reg.getDNIEmpleado()>=0){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantRegistros++;
                registrosLeidos=contarRegistrosPorID(reg.getIDDetalle());
                if(registrosLeidos==cantRegistros){
                    acumPrecio=acumlarPrecio(reg.getIDDetalle());
                    cout<<endl;
                    cout<<"**************************************"<<endl;
                    cout<<"    IMPORTE TOTAL DETALLE "<<reg.getIDDetalle()<<" : $"<<acumPrecio<<endl;
                    cout<<"**************************************"<<endl;
                    cout<<endl;
                    cout<<"----------------------------------"<<endl;
                    cantRegistros=0;
                }
            }
            pos++;
        }
    }
    else{
        cout<<"EL CLIENTE NO HA HECHO UN PEDIDO AÚN."<<endl;
    }
    system("pause");
}

int contarRegistrosPorID(int iddetalle){
    VentaCabecera reg;
    int pos=0,cantidad=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            cantidad++;
        }
        pos++;
    }
    return cantidad;
}

float acumlarPrecio(int iddetalle){
    VentaCabecera reg;
    int pos=0;
    float precio=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            precio+=reg.getImporte();
        }
        pos++;
    }
    return precio;
}

///MENU VENTAS EMPLEADOS
void mostrarVentas(){
    system("cls");
    VentaDetalle reg;
    int pos=0,noAtendido;
    bool sinAtender,cantReg=false;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*        MOSTRAR VENTAS        *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            sinAtender=clienteNoAtendido(reg.getIDVenta());
            if(sinAtender==true){
                noAtendido=traerCliente(reg.getIDVenta());
                cout<<"EL CLIENTE CON DNI "<<noAtendido<<" NO ESTÁ ATENDIDO."<<endl;
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
            else{
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO SE HAN REGISTRADO VENTAS AÚN."<<endl;
    system("pause");
}

bool clienteNoAtendido(int idventa){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDVenta()==idventa){
            if(reg.getDNIEmpleado()==0){
                return true;
            }
        }
        pos++;
    }
    return false;
}

int traerCliente(int idventa){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDVenta()==idventa){
            return reg.getDNICliente();
        }
        pos++;
    }
    return -1;
}

void atenderCliente(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,iddetalle;
    bool noAtendido,existeDetalle,cantReg=false;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*        ATENDER CLIENTE        *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        noAtendido=clienteNoAtendido(reg.getIDVenta());
        if(noAtendido==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false){
        cout<<"NO HAY VENTAS REGISTRADAS AÚN."<<endl;
        system("pause");
    }
    else{
        cout<<"ID DE DETALLE A ATENDER: ";
        cin>>iddetalle;
        if(iddetalle==0){
            return;
        }
        existeDetalle=buscarIDDetalle(iddetalle);
        if(existeDetalle==true){
            atenderAlCliente(iddetalle,dniEmp);
        }
        else{
            cout<<endl;
            cout<<"LA VENTA NO EXISTE O EL CLIENTE YA FUE ANTENDIDO."<<endl;
            system("pause");
        }
    }
}

void atenderAlCliente(int iddetalle,int dniEmp){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            reg.setDNIEmpleado(dniEmp);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

bool buscarIDDetalle(int iddetalle){
    VentaDetalle reg;
    VentaCabecera aux;
    int pos1=0,pos2=0;
    while(reg.leerDeDisco(pos1)==1){
        if(reg.getIDDetalle()==iddetalle){
            while(aux.leerDeDisco(pos2)==1){
                if(aux.getIDDetalle()==iddetalle && aux.getDNIEmpleado()==0 && reg.getEstado()==true){
                    return true;
                }
                pos2++;
            }
        }
        pos1++;
    }
    return false;
}

void cobrarVentas(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,iddetalle;
    bool existeDetalle,noAtendido,cantReg=false,clienteAtendido;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*         COBRAR VENTAS         *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"         VENTAS ATENDIDAS         "<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            noAtendido=clienteNoAtendido(reg.getIDVenta());
            if(noAtendido==true){
                cout<<"LA VENTA CON ID DE DETALLE "<<reg.getIDDetalle()<<" NO FUE ATENDIDA."<<endl;
                cout<<"----------------------------------"<<endl;
            }
            else{
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
        }
        pos++;
    }
    if(cantReg==true){
        cout<<"ELIJA EL ID DE DETALLE A COBRAR: ";
        cin>>iddetalle;
        if(iddetalle==0){
            return;
        }
        clienteAtendido=buscarClienteAtendido(iddetalle);
        existeDetalle=buscarDetalle(iddetalle);
        if(existeDetalle==true && clienteAtendido==true){
            cout<<endl;
            buscarVenta(iddetalle,dniEmp);
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getIDDetalle()==iddetalle){
                    reg.setEstado(false);
                    reg.modificarEnDisco(pos);
                }
                pos++;
            }
            cout<<endl;
            cout<<"<<<LA VENTA SE COBRÓ CON ÉXITO>>>"<<endl;
            system("pause");
        }
        else{
            cout<<endl;
            cout<<"LA VENTA NO EXISTE O NO HA SIDO ATENDIDA AÚN."<<endl;
            system("pause");
        }
    }
    else{
        cout<<endl;
        cout<<"NO SE ENCONTRÓ NINGUNA VENTA O ESTA NO FUE ATENDIDA."<<endl;
        system("pause");
        return;
    }
}

bool buscarClienteAtendido(int iddetalle){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            if(reg.getDNIEmpleado()>0){
                return true;
            }
        }
        pos++;
    }
    return false;
}

bool buscarDetalle(int iddetalle){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            return true;
        }
        pos++;
    }
    return false;
}

void buscarVenta(int iddetalle,int dniEmp){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            reg.setDNIEmpleado(-2);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void mostrarVentasCobradas(){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    bool cantReg=false;
    cout<<"*************************"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*    VENTAS COBRADAS    *"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-2){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO HAY VENTAS COBRADAS."<<endl;
    system("pause");
}

void mostrarVentasCanceladas(){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    bool cantReg=false;
    cout<<"***************************"<<endl;
    cout<<"*                         *"<<endl;
    cout<<"*    VENTAS CANCELADAS    *"<<endl;
    cout<<"*                         *"<<endl;
    cout<<"***************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO HAY VENTAS CANCELADAS."<<endl;
    system("pause");
}
///

#endif // FUNCIONES_H_INCLUDED
