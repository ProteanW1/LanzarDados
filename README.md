# Simulación de Lanzamiento de Dados

Programa que simula el lanzamiento de un dado n número de veces

## Tabla de Contenido

- [Introducción](#introducción)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)

- [Licencia](#licencia)

## Introducción

El programa es capaz de recibir el número de veces que se lanzara el dado, dando como resultado el número de caras que salió en cada lanzamiento de los dados.

## Características

- Se pregunta si se quiere lanzar los dados.
- Lanza el primer y segundo dado
- Suma el resultado de ambos dados lanzados

## Instalación

El codigo se hizo en C++ en Embarcadero DEV C++, el link de descarga es el siguiente: https://www.embarcadero.com/free-tools/dev-cpp

## Uso
A continuación dejo el codigo para poderlo copiar y pegar en el IDE
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
	
char sino;
int tirada1, tirada2, avances{};
    
      do 
       {   
		 cout<< "Desea lanzar los dados: S/N?"<<endl;
         cin>> sino;
		   
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

![image](https://github.com/ProteanW1/LanzarDados/assets/144411242/e792cc6c-00ae-47bc-885e-c8fd4f2777cf)

![image](https://github.com/ProteanW1/LanzarDados/assets/144411242/252d7a36-3201-4c1e-a7d1-89d1a4c1541a)


## Licencia
 "Este proyecto está bajo la Licencia MIT. Consulta el archivo [LICENSE](LICENSE) para más detalles."
