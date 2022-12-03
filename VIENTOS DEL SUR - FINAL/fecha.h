#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia,mes,anio;
    public:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void setDia(int d){if(d>0 && d<=31){dia=d;}}
        void setMes(int m){if(m>0 && m<=12){mes=m;}}
        void setAnio(int a){anio=a;}

        void Cargar();
        void Mostrar();
};

void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"AÑO: ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHA_H_INCLUDED
