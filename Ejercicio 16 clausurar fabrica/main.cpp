#include <iostream>

using namespace std;

int main()
{
    float valorMulta = 0, totalL = 0, totalM = 0 , totalG = 0;
    int tipo = 0, cantidadGraves = 0;
    string motivo;
    char gravedad;

    for (int i = 0; i < 4; i++) {
        cout << "Tipo de infraccion (1, 2, 3, 4): ";
        cin >> tipo;

        cout << "Motivo de la infraccion: ";
        cin >> motivo;

        cout << "Valor de la multa: ";
        cin >> valorMulta;

        cout << "Gravedad de la infraccion ('L', 'M', 'G'): ";
        cin >> gravedad;

        cout << endl;

        switch (gravedad) {
            case 'L':
                totalL += valorMulta;
                break;
            case 'M':
                totalM += valorMulta;
                break;
            case 'G':
                totalG += valorMulta;
                if (tipo == 3 || tipo == 4) {
                    cantidadGraves++;
                }
                break;
        }
    }

    cout << "Total de multas de infracciones 'L': " << totalL << endl;
    cout << "Total de multas de infracciones 'M': " << totalM << endl;
    cout << "Total de multas de infracciones 'G': " << totalG << endl;

    if (cantidadGraves > 3) {
        cout << "Clausurar Fabrica";
    }

    return 0;
}
