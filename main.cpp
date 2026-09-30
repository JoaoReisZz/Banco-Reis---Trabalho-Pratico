/******************************************************************************
Trabalho – Implementação de um Sistema de
Registro e Gestão de Contas Bancárias (ETAPA 1)

Aluno: João Lucas Ladeira dos Reis
Matricula: 28509
Valor: 10 pontos
Data: 30/09/2026
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Essa variável vai guardar a opção escolhida pelo usuário no menu
    int opcao;
    
    /*  Aqui coloquei [5] em cada variável pois o sistema pode receber até 5 cadastros difentes, com isso 
    cada variável pode ter 5 valores */
    int numeroConta[5];
    string nomeCliente[5];
    string cpf[5];
    int tipoConta[5];
    double saldo[5];
    bool contaAtiva[5];
    
    // Armazena a quantidade de contas cadastradas
    int quantidadeContas = 0;
    
    /*
    Usei o do-while para que o menu seja mostrado pelo menos uma vez.
    O programa continuará mostrando o menu enquanto a opção escolhida
    for diferente de 6.
    */
    do {
        
    // Aqui estou mostrando o menu principal do banco    
    cout << "***********************" << endl;
    cout << "** MENU - BANCO REIS **" << endl;
    cout << "***********************" << endl;
    cout << "1 - Cadastrar conta" << endl;
    cout << "2 - Consultar conta" << endl;
    cout << "3 - Verificar saldo" << endl;
    cout << "4 - Alterar tipo da conta" << endl;
    cout << "5 - Ativar/Desativar conta" << endl;
    cout << "6 – Sair" << endl; 
        
    // Aqui o usuário informa qual opção deseja executar
    cout << "Digite uma opção: ";
    cin >> opcao;
    
     /*
    Usei o switch para verificar qual opção foi escolhida
    e executar o código correspondente.
    */
    switch(opcao) {
            
        // Caso o usuário escolha a opção 1, será feito o cadastro
        case 1:
            
             /*
            Antes de cadastrar, verifico se o limite de 5 contas
            já foi atingido. Como os vetores possuem 5 posições,
            não posso cadastrar uma sexta conta.
            */
            if (quantidadeContas >= 5) {
            cout << "Limite de 5 contas atingido." << endl;
            break;
            }
            
            // Mostra uma mensagem informando que o cadastro foi selecionado
            cout << "CADASTRO SELECIONADO." << endl;
        
            /*
            Aqui uso um do-while para pedir o número da conta.
            O número precisa ser maior que zero para ser aceito.
            */
            do {
                cout << "Digite o numero da conta: ";
                cin >> numeroConta[quantidadeContas];
                
                // Verifico se o número informado é inválido
                if (numeroConta[quantidadeContas] <= 0) {
                cout << "Erro: o numero deve ser positivo." << endl;
                }
                
            /*
            Enquanto o número for menor ou igual a zero,
            o programa continuará pedindo um novo número.
            */
            } while (numeroConta[quantidadeContas] <= 0);
        
            /*
            O cin.ignore() é usado para limpar o ENTER que ficou
            no teclado depois do cin >>. Isso permite usar o getline()
            corretamente para ler o nome completo.
            */
            cin.ignore();
        
            cout << "Digite o nome do titular: ";
            getline(cin, nomeCliente[quantidadeContas]);
            
            cout << "Digite o CPF do titular: ";
            cin >> cpf[quantidadeContas];
            
            /*
            Aqui uso outro do-while para validar o tipo da conta.
            O usuário só pode escolher 1 para Corrente ou 2 para Poupança.
            */
            do {
                cout << "Digite o tipo da conta: " << endl;
                cout << "1 = Corrente" << endl;
                cout << "2 = Poupança" << endl;
                cin >> tipoConta[quantidadeContas];
                
                /*
                Se o usuário digitar qualquer número diferente de
                1 ou 2, será mostrada uma mensagem de erro.
                */
                if (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                cout << "Erro: Tipo de conta inexistente." << endl;
            }

            /*
            O cadastro do tipo da conta só termina quando o usuário
            informar uma das opções válidas: 1 ou 2.
            */
            } while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2);


            // Aqui estou pedindo o saldo inicial da conta
            cout << "Digite o saldo inicial: ";
            cin >> saldo[quantidadeContas];

            // Aqui estou colocando a conta como ativa no momento do cadastro
            contaAtiva[quantidadeContas] = true;
            
            cout << "CONTA CADASTRADA COM SUCESSO." << endl;
            
            /*
            Depois que todos os dados da conta são cadastrados,
            aumento a quantidade de contas em 1.
                
            Por exemplo:
            se quantidadeContas era 0, passa a ser 1.
            Assim, o próximo cadastro será armazenado na posição 1.
            */
            quantidadeContas++;
            
            
        // Encerra o case 1 e volta para o menu principal
        break;
        
       
       
        // Caso o usuário escolha a opção 2, será feita a consulta da conta
        case 2:
            {
                /*
                Primeiro verifico se existe pelo menos uma conta cadastrada.
                Se não existir, não há nenhuma conta para consultar.
                */
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                int numeroBusca;
                int posicao = -1;

                // O usuário informa o número da conta que deseja consultar
                cout << "Digite o numero da conta: ";
                cin >> numeroBusca;

                /*
                Aqui percorro todas as contas cadastradas procurando
                pelo número informado pelo usuário.
                */
                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroBusca) {
                        posicao = i;
                        break;
                    }
                }

                /*
                Se a posição continuar sendo -1, significa que a conta
                não foi encontrada.
                */
                if (posicao == -1) {
                    cout << "Conta nao encontrada." << endl;
                }
                else {
                    // Mostro todos os dados da conta encontrada
                    cout << "----- DADOS DA CONTA -----" << endl;
                    cout << "Numero da conta: " << numeroConta[posicao] << endl;
                    cout << "Nome do titular: " << nomeCliente[posicao] << endl;
                    cout << "CPF: " << cpf[posicao] << endl;

                    // Verifico qual é o tipo da conta
                    if (tipoConta[posicao] == 1) {
                        cout << "Tipo: Corrente" << endl;
                    }
                    else {
                        cout << "Tipo: Poupanca" << endl;
                    }

                    cout << "Saldo: R$ " << saldo[posicao] << endl;

                    // Verifico se a conta está ativa ou desativada
                    if (contaAtiva[posicao]) {
                        cout << "Status: Ativa" << endl;
                    }
                    else {
                        cout << "Status: Desativada" << endl;
                    }
                }
            }
                break;


        // Caso o usuário escolha a opção 3, será mostrado o saldo da conta
        case 3:
            {
                int numeroBusca;
                int posicao = -1;

                // Aqui peço o número da conta para verificar o saldo
                cout << "Digite o numero da conta: ";
                cin >> numeroBusca;

                // Aqui procuro a conta informada pelo usuário
                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroBusca) {
                        posicao = i;
                        break;
                    }
                }

                // Aqui verifico se a conta foi encontrada
                if (posicao == -1) {
                    cout << "Conta nao encontrada." << endl;
                }
                else {
                    // Aqui mostro o saldo da conta encontrada
                    cout << "Saldo da conta: R$ " << saldo[posicao] << endl;
                }
            }
            break;


        // Caso o usuário escolha a opção 4, será alterado o tipo da conta
        case 4:
            {
                int numeroBusca;
                int posicao = -1;
                int novoTipo;

                // Aqui peço o número da conta que será alterada
                cout << "Digite o numero da conta: ";
                cin >> numeroBusca;

                // Aqui procuro a conta informada pelo usuário
                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroBusca) {
                        posicao = i;
                        break;
                    }
                }

                // Verifico se a conta foi encontrada
                if (posicao == -1) {
                    cout << "Conta nao encontrada." << endl;
                }
                else {

                    // Aqui peço o novo tipo da conta
                    cout << "Digite o novo tipo da conta: " << endl;
                    cout << "1 = Corrente" << endl;
                    cout << "2 = Poupanca" << endl;
                    cin >> novoTipo;

                    // Aqui verifico se o tipo informado é válido
                    if (novoTipo == 1 || novoTipo == 2) {
                        tipoConta[posicao] = novoTipo;
                        cout << "Tipo da conta alterado com sucesso." << endl;
                    }
                    else {
                        cout << "Tipo de conta inexistente." << endl;
                    }
                }
            }
            break;


        // Caso o usuário escolha a opção 5, será alterado o status da conta
        case 5:
            {
                int numeroBusca;
                int posicao = -1;

                // Aqui peço o número da conta que será alterada
                cout << "Digite o numero da conta: ";
                cin >> numeroBusca;

                // Aqui procuro a conta informada pelo usuário
                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroBusca) {
                        posicao = i;
                        break;
                    }
                }

                // Verifico se a conta foi encontrada
                if (posicao == -1) {
                    cout << "Conta nao encontrada." << endl;
                }
                else {

                    // Aqui verifico se a conta está ativa
                    if (contaAtiva[posicao] == true) {
                        contaAtiva[posicao] = false;
                        cout << "Conta desativada com sucesso." << endl;
                    }
                    else {
                        contaAtiva[posicao] = true;
                        cout << "Conta ativada com sucesso." << endl;
                    }
                }
            }
            break;


        // Caso o usuário escolha a opção 6, o sistema será encerrado
        case 6:
            cout << "SAINDO DO SISTEMA..." << endl;
            break;


        // Caso o usuário digite uma opção que não existe no menu
        default:
            cout << "OPCAO INVALIDA." << endl;
            break;
    }

    /*
    O programa continua repetindo o menu enquanto a opção escolhida
    for diferente de 6. Quando o usuário escolher 6, o loop termina.
    */    
    } while (opcao != 6);
    
    return 0;
}
