#include <iostream>
#include <random>
using namespace std;
template <int MIN, int MAX>

struct Dado
{
    /*Dado() :
        generador(device()),
        distribucion(MIN, MAX)
    {}*/

    int lanzar()
    {
        /* Generamos un número pseudo-aleatorio con el algoritmo
        mt19937 distribuido uniformemente entre min y max */
        return distribucion(generador);
    }

private:
    // Tenemos control sobre el algoritmo y distribución a usar.
    random_device device;
    mt19937 generador{device()};
    uniform_int_distribution<> distribucion{MIN, MAX};
};

// Alias de dado de 6 caras.
using D6 = Dado<1, 6>;
// Nuestros dados.
D6 dado1, dado2;

int tirada()
{
char lanzar;	
int nVeces, tirada1, tirada2, avances{};
    
      do 
       {   
		 cout<< "Bienvendo, presione 'ok para lanzar los dados "<<endl;
		 cin>> lanzar;
		   
         avances += (tirada1 = dado1.lanzar()) + (tirada2 = dado2.lanzar());
         cout << "Primer dado: " << tirada1
         << "\nSegundo dado: " << tirada2
         << "\n\tAvances: " << avances << endl;  
        } while (tirada1 == tirada2);
return avances;
}

int main()
{
    auto a = tirada();
    cout << "La jugada resulta en " << a << " avances."<<endl;
    
    return 0;
}