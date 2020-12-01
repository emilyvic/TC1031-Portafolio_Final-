
struct Dato {
    public:
        friend ostream& operator<<(ostream& os, const Dato& dt);
        string IP;
        int IPkey; //características del dato
        int hashKey;
        
        Dato();
        Dato(string IP);
        void createKey(string IP);
        int createHashKey();

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
    acum = acum.substr(0,9);
    IPkey = stoi(acum);
}
//Complejidad: O(n)

int Dato::createHashKey(){
    string str_aux = to_string(IPkey);
    int suma =0;
    for(int i = 0; i<3; i++){
        char ch_aux = str_aux[i];
        string s(1, ch_aux);
        suma += stoi(s);
    }
    return suma;//regresa el valor de la suma de los 3 primeros digitos
}
//Complejidad: O(n)

ostream& operator<<(ostream& os, const Dato& dat){
    os << dat.IP;
    return os;
}