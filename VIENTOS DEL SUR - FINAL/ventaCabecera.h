#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

class VentaCabecera{
    private:
        int IDVenta;
        int IDDetalle;
        int DNICliente;
        int DNIEmpleado;
        Fecha fecha;
        float importe;
    public:
        int getIDVenta(){return IDVenta;}
        int getIDDetalle(){return IDDetalle;}
        int getDNICliente(){return DNICliente;}
        int getDNIEmpleado(){return DNIEmpleado;}
        Fecha getFecha(){return fecha;}
        float getImporte(){return importe;}

        void setIDVenta(int idv){IDVenta=idv;}
        void setIDDetalle(int idd){IDDetalle=idd;}
        void setDNICliente(int dnic){DNICliente=dnic;}
        void setDNIEmpleado(int dnie){DNIEmpleado=dnie;}
        void setFecha(Fecha f){fecha=f;}
        void setImporte(float i){importe=i;}

        void Cargar(int,int,int);
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void VentaCabecera::Cargar(int idv,int idd,int dni){
    cout<<"ID DE VENTA: ";
    IDVenta=idv;
    cout<<IDVenta<<endl;
    cout<<"ID DE DETALLE: ";
    IDDetalle=idd;
    cout<<IDDetalle<<endl;
    cout<<"DNI DEL CLIENTE: ";
    DNICliente=dni;
    cout<<DNICliente<<endl;
    cout<<"DNI DEL EMPLEADO: ";
    DNIEmpleado=0;
    cout<<DNIEmpleado<<endl;
    cout<<"FECHA: ";
    fecha.Cargar();
}

void VentaCabecera::Mostrar(){
    cout<<"ID DE VENTA: "<<IDVenta<<endl;
    cout<<"ID DE DETALLE: "<<IDDetalle<<endl;
    cout<<"DNI DEL CLIENTE: "<<DNICliente<<endl;
    cout<<"DNI DEL EMPLEADO: "<<DNIEmpleado<<endl;
    cout<<"FECHA: ";
    fecha.Mostrar();
    cout<<"IMPORTE: $"<<importe<<endl;
}

int VentaCabecera::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventaCabecera.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaCabecera)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int VentaCabecera::grabarEnDisco(){
    FILE *p;
    p=fopen("ventaCabecera.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

int VentaCabecera::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventaCabecera.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaCabecera)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}
#endif // VENTA_H_INCLUDED
