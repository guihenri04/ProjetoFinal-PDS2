#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> 

using namespace std;

class Figura 
{
protected:
    int x, y;
public:
    Figura(int _x, int _y) : x(_x), y(_y) {}
    virtual ~Figura() {}
    virtual void Desenha() 
    {
        cout << x << " " << y << " ";
    }
    virtual float CalculaArea() = 0;
};

class Retangulo : public Figura
{
private:
    int lado1, lado2;
public:
    Retangulo(int _x, int _y, int _lado1, int _lado2) : Figura(_x, _y), lado1(_lado1), lado2(_lado2) {}
    void Desenha() override {
        Figura::Desenha();
        cout << "RETANGULO" << endl;
    }
    float CalculaArea() override {
        return lado1 * lado2;
    }
};

class Circulo : public Figura 
{
private:
    int raio;
public:
    Circulo(int _x, int _y, int _raio) : Figura(_x, _y), raio(_raio) {}
    void Desenha() override {
        Figura::Desenha();
        cout << "CIRCULO" << endl;
    }
    float CalculaArea() override {
        return M_PI * raio * raio;
    }
};

class Triangulo : public Figura {
private:
    int base, altura;
public:
    Triangulo(int _x, int _y, int _base, int _altura) : Figura(_x, _y), base(_base), altura(_altura) {}
    void Desenha() override 
    {
        Figura::Desenha();
        cout << "TRIANGULO" << endl;
    }
    float CalculaArea() override 
    {
        return 0.5 * base * altura;
    }
};

int main() 
{
    vector<Figura*> figuras;
    char comando;
    int x, y, lado1, lado2, raio, base, altura;

    while (cin >> comando && comando != 'E') 
    {
        switch (comando) 
        {
            case 'R':
                cin >> x >> y >> lado1 >> lado2;
                figuras.push_back(new Retangulo(x, y, lado1, lado2));
                break;
            case 'C':
                cin >> x >> y >> raio;
                figuras.push_back(new Circulo(x, y, raio));
                break;
            case 'T':
                cin >> x >> y >> base >> altura;
                figuras.push_back(new Triangulo(x, y, base, altura));
                break;
            case 'D':
                for (const auto& figura : figuras) 
                {
                    figura->Desenha();
                }
                break;
            case 'A':
                float areaTotal = 0;
                for (const auto& figura : figuras) 
                {
                    areaTotal += figura->CalculaArea();
                }
                cout << fixed << setprecision(2) << " " << areaTotal << endl;
                break;
        }
    }

    return 0;
}












