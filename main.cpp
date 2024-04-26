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
        cout << "1. Incluir Funcionário\n";
        cout << "2. Excluir Funcionário\n";
        cout << "3. Pesquisar Funcionário\n";
        cout << "4. Listar Funcionários\n";

        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 0:
                {
                    cout << "Você escolheu a opção 0.\n";
                    cout << "Saindo...\n";
                    break;
                }
            case 1:
                {
                    cout << "Você escolheu a opção 1.\n";
                    int prontuario;
                    cout << "Digite o prontuário do novo funcionário: ";
                    cin >> prontuario;

                    bool prontuarioExists = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontuario) {
                            prontuarioExists = true;
                            break;
                        }
                    }

                    if (prontuarioExists) {
                        cout << "Esse prontuário já existe.\n";
                    } else {
                        string nome;
                        cout << "Digite o nome do novo funcionário: ";
                        cin >> nome;

                        double salario;
                        cout << "Digite o salário do novo funcionário: ";
                        cin >> salario;

                        funcionarios.push_back(Funcionario(prontuario, nome, salario));
                        cout << "Novo funcionário adicionado com sucesso.\n";
                    }
                    break;
                }
            case 2:
                {
                    cout << "Você escolheu a opção 2.\n";
                    int prontExcluir;
                    cout << "Digite o prontuário do funcionário a ser excluído: ";
                    cin >> prontExcluir;

                    bool foundExcluir = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontExcluir) {
                            funcionarios.erase(funcionarios.begin() + i);
                            foundExcluir = true;
                            cout << "Funcionário excluído com sucesso.\n";
                            break;
                        }
                    }

                    if (!foundExcluir) {
                        cout << "Funcionário com o prontuário " << prontExcluir << " não encontrado.\n";
                    }
                    break;
                }
            case 3:
                {
                    cout << "Você escolheu a opção 3.\n";
                    int prontSearch;
                    cout << "Digite o prontuário do funcionário a ser pesquisado: ";
                    cin >> prontSearch;

                    bool found = false;

                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        if (funcionarios[i].getProntuario() == prontSearch) {
                            found = true;
                            cout << "Funcionário encontrado:\n";
                            cout << "Prontuário: " << funcionarios[i].getProntuario() << endl;
                            cout << "Nome: " << funcionarios[i].getNome() << endl;
                            cout << "Salário: " << funcionarios[i].getSalario() << endl;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Funcionário com o prontuário " << prontSearch << " não encontrado.\n";
                    }
                    break;
                }
            case 4:
                {
                    cout << "Você escolheu a opção 4.\n";
                    if (funcionarios.empty()) {
                        cout << "Não há funcionários cadastrados.\n";
                    } else {
                        cout << "Lista de funcionários:\n";
                        double totalSalarios = 0.0;
                        for (size_t i = 0; i < funcionarios.size(); ++i) {
                            cout << "Prontuário: " << funcionarios[i].getProntuario() << endl;
                            cout << "Nome: " << funcionarios[i].getNome() << endl;
                            cout << "Salário: " << funcionarios[i].getSalario() << endl;
                            totalSalarios += funcionarios[i].getSalario();
                        }
                        cout << "Total dos salários: " << totalSalarios << endl;
                    }
                    break;
                }
            default:
                {
                    cout << "Opção inválida. Tente novamente.\n";
                    break;
                }
        }

    } while (escolha != 0);

    return 0;
}
