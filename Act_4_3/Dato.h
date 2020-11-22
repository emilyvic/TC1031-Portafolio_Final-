
struct Dato {
    public:
        friend ostream& operator<<(ostream& os, const Dato& dt);
        string IP;
        int IPkey; //características del dato
        
        Dato();
        Dato(string IP);
        void createKey(string IP);

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
    IPkey =0;
    IP = " ";
}

Dato::Dato(string IP){
    this -> IP = IP;
    createKey(IP);
}

void Dato::createKey(string IP){
    stringstream ssIP = stringstream(IP);
    string seg, acum;//inicializar variable acumuladora de string
    while( getline(ssIP, seg, '.') ){
        acum = acum + seg;
    }
   // cout << acum <<endl;
    acum = acum.substr(9,10);
    IPkey = stoi(acum);
}
//Complejidad: O(n)

ostream& operator<<(ostream& os, const Dato& dat){
    os << dat.IP;
    return os;
}