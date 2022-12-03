#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

///CLIENTE
class Usuario{
    private:
        int dni;
        int tipo; /// 1: admin; 2: empleado; 3: cliente
        char nombre[30];
        char apellido[30];
        char contrasenia[9];
        char telefono[15];
        bool estado;
    public:
        int getDNI(){return dni;}
        int getTipo(){return tipo;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getContrasenia(){return contrasenia;}
        const char *getTelefono(){return telefono;}
        bool getEstado(){return estado;}

        void setDNI(int d){dni=d;}
        void setTipo(int tp){tipo=tp;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setApellido(const char *a){strcpy(apellido,a);}
        void setContrasenia(const char *c){strcpy(contrasenia,c);}
        void setTelefono(const char *t){strcpy(telefono,t);}
        void setEstado(bool e){estado=e;}

        void Cargar(int);
        void Mostrar();
        void MostrarLogeado();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void Usuario::Cargar(int tp){
    tipo=tp;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    cout<<"CONTRASEÑA: ";
    cargarCadena(contrasenia,14);
    cout<<"TELÉFONO: ";
    cargarCadena(telefono,14);
    estado=true;
}

void Usuario::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"TIPO: "<<tipo<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"CONTRASEÑA: "<<contrasenia<<endl;
    cout<<"TELÉFONO: "<<telefono<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

void Usuario::MostrarLogeado(){
    cout<<"       "<<nombre<<" "<<apellido<<endl;
}

int Usuario::leerDeDisco(int pos){
    FILE *p;
    p=fopen("usuario.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(Usuario)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int Usuario::grabarEnDisco(){
    FILE *p;
    p=fopen("usuario.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

int Usuario::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("usuario.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(Usuario)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}
#endif // PERSONA_H_INCLUDED
