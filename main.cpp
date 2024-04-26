#include <iostream>
#include <vector>
#include <string>

//Gabriela Otilia Wandenkolk Monteiro

using namespace std;

class Funcionario {
private:
    int prontuario;
    string nome;
    double salario;

public:
    Funcionario(int pront, string name, double sal) : prontuario(pront), nome(name), salario(sal) {}

    int getProntuario() const { return prontuario; }
    string getNome() const { return nome; }
    double getSalario() const { return salario; }
};

int main() {
    int escolha;
    vector<Funcionario> funcionarios;

    do {
        cout << "Menu:\n";
        cout << "0. Sair \n";
        cout << "1. Incluir Funcion�rio\n";
        cout << "2. Excluir Funcion�rio\n";
        cout << "3. Pesquisar Funcion�rio\n";
        cout << "4. Listar Funcion�rios\n";

        cout << "Escolha uma op��o: ";
        cin >> escolha;

        switch (escolha) {
            case 0:
                {
                    cout << "Voc� escolheu a op��o 0.\n";
                    cout << "Saindo...\n";
                    break;
                }
            case 1:
                {
                    cout << "Voc� escolheu a op��o 1.\n";
                    int prontuario;
                    cout << "Digite o prontu�rio do novo funcion�rio: ";
                    cin >> prontuario;

                    bool prontuarioExists = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontuario) {
                            prontuarioExists = true;
                            break;
                        }
                    }

                    if (prontuarioExists) {
                        cout << "Esse prontu�rio j� existe.\n";
                    } else {
                        string nome;
                        cout << "Digite o nome do novo funcion�rio: ";
                        cin >> nome;

                        double salario;
                        cout << "Digite o sal�rio do novo funcion�rio: ";
                        cin >> salario;

                        funcionarios.push_back(Funcionario(prontuario, nome, salario));
                        cout << "Novo funcion�rio adicionado com sucesso.\n";
                    }
                    break;
                }
            case 2:
                {
                    cout << "Voc� escolheu a op��o 2.\n";
                    int prontExcluir;
                    cout << "Digite o prontu�rio do funcion�rio a ser exclu�do: ";
                    cin >> prontExcluir;

                    bool foundExcluir = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontExcluir) {
                            funcionarios.erase(funcionarios.begin() + i);
                            foundExcluir = true;
                            cout << "Funcion�rio exclu�do com sucesso.\n";
                            break;
                        }
                    }

                    if (!foundExcluir) {
                        cout << "Funcion�rio com o prontu�rio " << prontExcluir << " n�o encontrado.\n";
                    }
                    break;
                }
            case 3:
                {
                    cout << "Voc� escolheu a op��o 3.\n";
                    int prontSearch;
                    cout << "Digite o prontu�rio do funcion�rio a ser pesquisado: ";
                    cin >> prontSearch;

                    bool found = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontSearch) {
                            found = true;
                            cout << "Funcion�rio encontrado:\n";
                            cout << "Prontu�rio: " << funcionarios[i].getProntuario() << endl;
                            cout << "Nome: " << funcionarios[i].getNome() << endl;
                            cout << "Sal�rio: " << funcionarios[i].getSalario() << endl;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Funcion�rio com o prontu�rio " << prontSearch << " n�o encontrado.\n";
                    }
                    break;
                }
            case 4:
                {
                    cout << "Voc� escolheu a op��o 4.\n";
                    if (funcionarios.empty()) {
                        cout << "N�o h� funcion�rios cadastrados.\n";
                    } else {
                        cout << "Lista de funcion�rios:\n";
                        double totalSalarios = 0.0;
                        for (size_t i = 0; i < funcionarios.size(); ++i) {
                            cout << "Prontu�rio: " << funcionarios[i].getProntuario() << endl;
                            cout << "Nome: " << funcionarios[i].getNome() << endl;
                            cout << "Sal�rio: " << funcionarios[i].getSalario() << endl;
                            totalSalarios += funcionarios[i].getSalario();
                        }
                        cout << "Total dos sal�rios: " << totalSalarios << endl;
                    }
                    break;
                }
            default:
                {
                    cout << "Op��o inv�lida. Tente novamente.\n";
                    break;
                }
        }

    } while (escolha != 0);

    return 0;
}
