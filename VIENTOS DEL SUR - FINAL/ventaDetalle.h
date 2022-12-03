#ifndef VENTADETALLE_H_INCLUDED
#define VENTADETALLE_H_INCLUDED

void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class VentaDetalle{
    private:
        char IDPlato[6];
        int IDVenta;
        int IDDetalle;
        int cantidad;
        float importe;
        bool estado;
    public:
        const char *getIDPlato(){return IDPlato;}
        int getIDVenta(){return IDVenta;}
        int getIDDetalle(){return IDDetalle;}
        int getCantidad(){return cantidad;}
        float getImporte(){return importe;}
        bool getEstado(){return estado;}

        void setIDPlato(const char *idp){strcpy(IDPlato,idp);}
        void setIDVenta(int idv){IDVenta=idv;}
        void setIDDetalle(int idd){IDDetalle=idd;}
        void setCantidad(int c){cantidad=c;}
        void setImporte(float i){importe=i;}
        void setEstado(bool e){estado=e;}

        void Cargar(int,int,const char *,int,float);
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void VentaDetalle::Cargar(int idv,int idd,const char *codPlat,int cant,float imp){
    IDVenta=idv;
    IDDetalle=idd;
    strcpy(IDPlato,codPlat);
    cantidad=cant;
    importe=imp;
    estado=true;
}

void VentaDetalle::Mostrar(){
    cout<<"ID DE VENTA: "<<IDVenta<<endl;
    cout<<"ID DE DETALLE: "<<IDDetalle<<endl;
    cout<<"ID DE PLATO: "<<IDPlato<<endl;
    cout<<"CANTIDAD: "<<cantidad<<endl;
    cout<<"IMPORTE: $"<<importe<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

int VentaDetalle::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventaDetalle.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaDetalle)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int VentaDetalle::grabarEnDisco(){
    FILE *p;
    p=fopen("ventaDetalle.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

int VentaDetalle::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventaDetalle.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaDetalle)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}
#endif // VENTADETALLE_H_INCLUDED
