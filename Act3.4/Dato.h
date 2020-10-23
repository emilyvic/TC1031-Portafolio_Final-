
struct Dato {
    public:
        friend ostream& operator<<(ostream& os, const Dato& dt);
        string falla, mes, IP, port; //caracteristicas string del dato
        int month, dia, hh, mm, ss, IPkey; //características del dato
        
        Dato();
        Dato(string mes, int dia, int hh, int mm, int ss, string IP, string port, string falla);
        void createKey(string IP, string port);

        bool operator > (Dato dato2){ //sobrecarga del operador >
            if (IPkey > dato2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator < (Dato dato2){ //sobrecarga del operador <
            if (IPkey < dato2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator >= (Dato dato2){ //sobrecarga del operador >=
            if (IPkey >= dato2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator <= (Dato dato2){ //sobrecarga del operador <=
            if (IPkey <= dato2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator == (Dato dato2){ //sobrecarga del operador ==
            if (IPkey == dato2.IPkey){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator != (Dato dato2){ //sobrecarga del operador !=
            if (IPkey != dato2.IPkey){
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
    IPkey =0;
    mes = " ";
    IP = " ";
    port = " ";
    falla = " ";
}

Dato::Dato(string mes, int dia, int hh, int mm, int ss, string IP, string port, string falla){
     this -> dia = dia;
     this -> hh = hh;
     this -> mm = mm;
     this -> ss = ss;
     this -> port = port;
     this -> falla = falla;
     this -> IP = IP;
     this -> mes = mes;
     createKey(IP, port);
}

void Dato::createKey(string IP, string port){
    stringstream ssIP = stringstream(IP);
    string seg, acum;//inicializar variable acumuladora de string
    while( getline(ssIP, seg, '.') ){
        acum = acum + seg;
    }
    acum = acum + port;
    acum = acum.substr(5,10);
    IPkey = stoi(acum);
}

ostream& operator<<(ostream& os, const Dato& dat){
    os << dat.mes << " " << dat.dia << " " << dat.hh 
    << ":" << dat.mm << ":" << dat.ss << " " << dat.IP << ":" << dat.port << " " << dat.falla <<endl;
    return os;
}