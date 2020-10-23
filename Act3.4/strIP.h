
struct strIP {
    public:
        friend ostream& operator<<(ostream& os, const strIP& dt); //sobrecarga para imprimir
        //atributos propios de la estructura
        string IP;
        int port;
        int count;
        int IPkey;

        strIP();//constructor default
        strIP(string IP, int port);//constructor default con 2 parametros
        strIP(string IP, int port, int count);//constructor default con 3 parametros
        void createKey(string IP);//metodo para crear la llave utilizando solamente el IP

//sobrecarga de operadores comparativos considerando la llave del IP de cada dato
        bool operator > (strIP IP2){ //sobrecarga del operador >
            if (IPkey > IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator < (strIP IP2){ //sobrecarga del operador <
            if (IPkey < IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator == (strIP IP2){ //sobrecarga del operador ==
            if (IPkey == IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator >= (strIP IP2){ //sobrecarga del operador >=
            if (IPkey >= IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator <= (strIP IP2){ //sobrecarga del operador <=
            if (IPkey <= IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }

        bool operator != (strIP IP2){ //sobrecarga del operador !=
            if (IPkey != IP2.IPkey){
                return true;
            }else{
                return false;
            }
        }
};


strIP::strIP(){
    IP = " ";
    port = 0;
    IPkey = 0;
    count = 0;
}

strIP::strIP(string IP, int port){
    this-> IP = IP;
    this-> port = port;
    count = 0;
    createKey(IP);
}

strIP::strIP(string IP, int port, int count){
    this-> IP = IP;
    this-> port = port;
    this-> count = count;
}

void strIP::createKey(string IP){
    stringstream ssIP = stringstream(IP);
    string seg, acum;//inicializar variable acumuladora de string y declarar el segmento
    while( getline(ssIP, seg, '.') ){ //separar el IP denotado por los .
        acum = acum + seg;//hacer una acumulacion de las secciones de string IP
    }
    IPkey = stoi(acum);//convertir la cifra a entero y asignarla a key
}

//formato de impresion especifico
ostream& operator<<(ostream& os, const strIP& IP0){
    os << IP0.IP << ":" << IP0.port << " " << IP0.count <<endl;
    return os;
}