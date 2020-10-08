
struct Dato {
    public:
        friend ostream& operator<<(ostream& os, const Dato& dt);
        string mes, IP, falla; //caracteristicas string del dato
        int dia, hh, mm, ss, month, key; //características del dato
        
        Dato();
        Dato(int dia, int hh, int mm, int ss, string mes, string IP, string falla);
        Dato(int dia, int hh, int mm, int ss, string mes);
        void createKey(string mes);
        int traduceMes(string mes);

        bool operator > (Dato dato2){ //sobrecarga del operador >
            if (key > dato2.key){
                return true;
            }else{
                return false;
            }
        }

        bool operator < (Dato dato2){ //sobrecarga del operador <
            if (key < dato2.key){
                return true;
            }else{
                return false;
            }
        }

        bool operator >= (Dato dato2){ //sobrecarga del operador >=
            if (key >= dato2.key){
                return true;
            }else{
                return false;
            }
        }

        bool operator <= (Dato dato2){ //sobrecarga del operador <=
            if (key <= dato2.key){
                return true;
            }else{
                return false;
            }
        }

        bool operator == (Dato dato2){ //sobrecarga del operador ==
            if (key == dato2.key){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator != (Dato dato2){ //sobrecarga del operador !=
            if (key != dato2.key){
                return true;
            }else{
                return false;
            }
        }
};
Dato::Dato(){
    month = 0;
    dia = 0;
    hh=0;
    mm=0;
    ss=0;
    key =0;
    mes = " ";
    IP = " ";
    falla = " ";
}

Dato::Dato(int dia, int hh, int mm, int ss, string mes, string IP, string falla){
     this -> dia = dia;
     this -> hh = hh;
     this -> mm = mm;
     this -> ss = ss;
     this -> IP = IP;
     this -> falla = falla;
     this -> mes = mes;
     createKey(mes);
}

 Dato::Dato(int dia, int hh, int mm, int ss, string mes){
     this -> dia = dia;
     this -> hh = hh;
     this -> mm = mm;
     this -> ss = ss;
     this -> mes = mes;
    IP = " ";
    falla = " ";
    createKey(mes);
 }

int Dato::traduceMes(string mes){//expresar el mes en numero
    int result;
    if((mes == "Jun") || (mes == "JUN")){
        result = 6;
    }else if ((mes == "Jul") || (mes == "JUL")){
        result = 7;
    }else if ((mes == "Aug") || (mes == "AUG")){
        result = 8;
    }else if ((mes == "Sep" || (mes == "SEP"))){
        result = 9;
    }else if ((mes == "Oct") || (mes == "OCT")){
        result = 10;
    }
    return result;//retorna el numero del mes
}

void Dato::createKey(string mes){
    month = traduceMes(mes); //convertir el mes a un numero
    key = (month * 100000000) + (dia * 1000000) + (hh * 10000) + (mm * 100) + ss; //crear una clave númerica que indique la magnitud de cada dato.
}

ostream& operator<<(ostream& os, const Dato& dat){
    os << dat.mes << " " << dat.dia << " " << dat.hh 
    << ":" << dat.mm << ":" << dat.ss << " " << dat.IP << " " << dat.falla <<endl;
    return os;
}