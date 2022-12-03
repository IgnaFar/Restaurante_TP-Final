#ifndef PLATO_H_INCLUDED
#define PLATO_H_INCLUDED

class Plato{
    private:
        char codigoPlato[6];
        char nombre[30];
        char descripcion[30];
        float precio;
        int stock;
        bool estado;
    public:
        const char *getCodigoPlato(){return codigoPlato;}
        const char *getNombre(){return nombre;}
        const char *getDescripcion(){return descripcion;}
        float getPrecio(){return precio;}
        int getStock(){return stock;}
        bool getEstado(){return estado;}

        void setCodigoPlato(const char *cod){strcpy(codigoPlato,cod);}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setDescripcion(const char *d){strcpy(descripcion,d);}
        void setPrecio(float p){precio=p;}
        void setStock(int s){stock=s;}
        void setEstado(bool e){estado=e;}

        void Cargar();
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void Plato::Cargar(){
    cout<<"NOMBRE DEL PLATO: ";
    cargarCadena(nombre,29);
    cout<<"DESCRIPCION DEL PLATO: ";
    cargarCadena(descripcion,29);
    cout<<"PRECIO DEL PLATO: $";
    cin>>precio;
    cout<<"CANTIDAD DE STOCK: ";
    cin>>stock;
    estado=true;
}

void Plato::Mostrar(){
    cout<<"CóDIGO DE PLATO: "<<codigoPlato<<endl;
    cout<<"NOMBRE DEL PLATO: "<<nombre<<endl;
    cout<<"DESCRIPCIóN DEL PLATO: "<<descripcion<<endl;
    cout<<"PRECIO DEL PLATO: $"<<precio<<endl;
    cout<<"CANTIDAD DE STOCK: "<<stock<<endl;;
    cout<<"ESTADO: "<<estado<<endl;
}

int Plato::leerDeDisco(int pos){
    FILE *p;
    p=fopen("plato.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(Plato)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int Plato::grabarEnDisco(){
    FILE *p;
    p=fopen("plato.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

int Plato::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("plato.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(Plato)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}
#endif // PLATO_H_INCLUDED
