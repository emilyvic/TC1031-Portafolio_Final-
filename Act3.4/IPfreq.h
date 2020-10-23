
struct IPfreq {
    public:
        friend ostream& operator<<(ostream& os, const strIP& dt);//sobrecarga para imprimir
        //atributos propios de la estructura
        string IP;
        int port;
        int count;
        int IPkey;

        IPfreq();//constructor default
        IPfreq(string IP, int port, int count);//constructor con parametros
//sobrecarga de los operadores considerando el numero de accesos
        bool operator > (IPfreq IP2){ //sobrecarga del operador >
            if (count > IP2.count){
                return true;
            }else{
                return false;
            }
        }

        bool operator < (IPfreq IP2){ //sobrecarga del operador <
            if (count < IP2.count){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator == (IPfreq IP2){ //sobrecarga del operador ==
            if (count == IP2.count){
                return true;
            }else{
                return false;
            }
        }

        bool operator >= (IPfreq IP2){ //sobrecarga del operador >=
            if (count >= IP2.count){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator <= (IPfreq IP2){ //sobrecarga del operador <=
            if (count <= IP2.count){
                return true;
            }else{
                return false;
            }
        }

        bool operator != (IPfreq IP2){ //sobrecarga del operador !=
            if (count != IP2.count){
                return true;
            }else{
                return false;
            }
        }
};


IPfreq::IPfreq(){
    IP = " ";
    port = 0;
    IPkey = 0;
    count = 0;
}

IPfreq::IPfreq(string IP, int port, int count){
    this-> IP = IP;
    this-> port = port;
    this-> count = count;
}

ostream& operator<<(ostream& os, const IPfreq& IP0){
    os << IP0.IP << ":" << IP0.port << " " << IP0.count <<endl;
    return os;
}