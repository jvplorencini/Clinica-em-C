#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limitePaciente 20
#define limiteMed 10
#define limiteAgendamento 50

typedef struct{
    int id;
    char nome[100];
    int idade;
    int CPF;
    int plano;
}Paciente;

typedef struct{
    int id;
    char nome[100];
    int CRM;
    char especialidade[100];
    char disponibilidade[6]; //(manhã/tarde)
}Medico;

typedef struct{
    int hora;
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int idConsulta;
    Paciente pacientes;
    Medico medicos;
    Data datas;
}Consulta;

int main (){
    Paciente pacientes[limitePaciente];
    Medico medicos[limiteMed];
    Consulta consultas[limiteAgendamento];
    int opcao;
    int qtdPac = 0;
    int qtdMed = 0;
    int qtdConsult = 0;

    do{ 
        printf("1:Cadastor de Pacientes \n2:Cadastro de Medicos \n3: Lista de Medicos e Pacientes\n4: Agendamento das consultas\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                if(qtdPac == limitePaciente){
                    printf("Limite de pacientes atingidos\n");
                } else{
                    int tempQtd;
                    printf("Digite quantos pacientes quer cadastrar\n");
                    scanf("%d", &tempQtd);

                    while(tempQtd > 20 || tempQtd > (limitePaciente - qtdPac)){
                        printf("A quantidade digitada ultrapassa o limite de cadastro permitido\n");
                        printf("Digite outro valor\n");
                        scanf("%d", &tempQtd);
                    }
                    cadastroPaciente(pacientes, tempQtd, qtdPac);
                    qtdPac += tempQtd;
                }
                    break;
                }
            case 2:{
                if(qtdMed == limiteMed){
                    printf("Limite de medicos atingidos\n");
                } else{
                    int tempQtd;
                    printf("Digite quantos medicos quer cadastrar\n");
                    scanf("%d", &tempQtd);

                    while(tempQtd > 20 || tempQtd > (limiteMed - qtdMed)){
                        printf("A quantidade digitada ultrapassa o limite de cadastro permitido\n");
                        printf("Digite outro valor\n");
                        scanf("%d", &tempQtd);
                    }
                    cadastroMedico(medicos, tempQtd, qtdMed);
                    qtdMed += tempQtd;
                }
                break;
            }
            case 3:
                listaPacMed(medicos, pacientes, qtdMed, qtdPac);
                break;
            case 4:{
                if(qtdConsult == limiteAgendamento){
                    printf("O limite de consultas agendadas foi atingido\n");
                }else{
                    int tempQtd;
                    printf("Quantas consultas quer cadastrar:\n");
                    scanf("%d", &tempQtd);
                    while(tempQtd > 20 || tempQtd > (limiteAgendamento - qtdConsult)){
                        printf("A quantidade digitada ultrapassa o limite de cadastro permitido\n");
                        printf("Digite outro valor\n");
                        scanf("%d", &tempQtd);
                    }
                    agendaConsulta(consultas, tempQtd, qtdConsult, qtdPac, qtdMed);
                    qtdConsult += tempQtd;
                }
                break;
            }
        }
    }while(opcao != 0);
    return 0;

}

int verificaCPF(Paciente pacientes[], int i, int cpf){
    for(int j = 0; j < i; j++){
        if(pacientes[j].CPF == cpf){
            return 1;
        }
    }
    return 0;
}

void cadastroPaciente(Paciente pacientes[], int qtdPac, int totalPac){
    for(int i = totalPac; i < qtdPac + totalPac; i++){
        pacientes[i].id = i+1;
        printf("Nome: \n");
        while (getchar() != '\n'); 
        fgets(pacientes[i].nome, 100, stdin);
        pacientes[i].nome[strcspn(pacientes[i].nome, "\n")] = '\0';
        printf("idade: \n");
        scanf("%d", &pacientes[i].idade);
        printf("CPF: \n");
        int cpf;
        scanf("%d", &cpf);
        while(verificaCPF(pacientes, i, cpf)){
            printf("O CPF ja existe\nDigite novamente\n");
            scanf("%d", &cpf);
        }
        pacientes[i].CPF = cpf;         
        printf("Possui plano(1-sim 0-nao)");
        scanf("%d", &pacientes[i].plano);
    }
}

int verificaCRM(Medico medicos[], int i, int crm){
    for(int j = 0; j < i; j++){
        if(medicos[j].CRM == crm){
            return 1;
        }
    }
    return 0;
}

void cadastroMedico(Medico medicos[], int qtdMed, int totalMed){
    for(int i = totalMed; i < totalMed + qtdMed; i++){
        medicos[i].id = i+1;
        printf("Digite o nome:\n");
        while (getchar() != '\n');
        fgets(medicos[i].nome, 100, stdin);
        medicos[i].nome[strcspn(medicos[i].nome, "\n")] = '\0';
        printf("CRM: \n");
        int crm;
        scanf("%d", &crm);
        while(verificaCRM(medicos, totalMed, crm)){
            printf("O CRM ja existe\nDigite novamente\n");
            scanf("%d", &crm);
        }
        medicos[i].CRM = crm; 
        printf("Digite a especialidade:\n");
        while (getchar() != '\n'); 
        fgets(medicos[i].especialidade, 100, stdin);
        medicos[i].especialidade[strcspn(medicos[i].especialidade, "\n")] = '\0';
        char disp[6];
        printf("Digite a disponibilidade(manha/noite):\n");
        fgets(disp, 6, stdin);
        disp[strcspn(disp, "\n")] = '\0';
        while(strcmp(disp, "manha") != 0 && strcmp(disp, "noite") != 0){
            printf("Opcao invalida\nDigite novamente:\n");
            fgets(disp, 6, stdin);
            disp[strcspn(disp, "\n")] = '\0';
        }
        strcpy(medicos[i].disponibilidade, disp);
    }
}

void listaPacMed(Medico medicos[], Paciente pacientes[], int qtdMed, int qtdPac){
    printf("---Medicos---\n");
    for(int i = 0; i < qtdMed; i++){
        printf("ID: %d\nNome: %s\nCRM: %d\nEspecialidade: %s\nDisponibilidade: %s\n", medicos[i].id, medicos[i].nome, medicos[i].CRM, medicos[i].especialidade, medicos[i].disponibilidade);
    }
    printf("\n---Pacientes---\n");
    for(int i = 0; i < qtdPac; i++){
        printf("ID: %d\nNome: %s\nIdade: %d\nCPF: %d\nPlano de Saude: %d\n", pacientes[i].id, pacientes[i].nome, pacientes[i].idade, pacientes[i].CPF, pacientes[i].plano);
    }
}

int verificaData(Consulta consultas[], int i, int hora, int dia, int mes, int ano, int idMed){
    for(int j = 0; j < i; j++){
        if(consultas[j].medicos.id == idMed && consultas[j].datas.hora == hora && consultas[j].datas.dia == dia && consultas[j].datas.mes == mes && consultas[j].datas.ano == ano){
            return 1;
        }
    }
    return 0;
}

void agendaConsulta(Consulta consultas[], int qtdConsul, int totalConsult, int totalPac, int totalMed){
    for(int i = totalConsult; i < qtdConsul + totalConsult; i++){
        consultas[i].idConsulta = i+1;
        int tempId;
        printf("Digite o ID do paciente\n");
        scanf("%d", &tempId);
        if(totalPac == 0){
            printf("Nenhum paciente foi cadastrado\n");
            return;
        }else{   
            while(tempId > limitePaciente || tempId < 0){
                printf("\nId invalido\nDigite novamente: ");
                scanf("%d", &tempId);
            }
            consultas[i].pacientes.id = tempId;
        }
        
        printf("Digite o ID do medico\n");
        scanf("%d", &tempId);
        if(totalMed == 0){
            printf("Nenhum medico foi cadastrado\n");
            return;
        }else{   
            while(tempId > limiteMed || tempId < 0){
                printf("\nId invalido\nDigite novamente: ");
                scanf("%d", &tempId);
            }
            consultas[i].medicos.id = tempId;
        }

        int hora, dia, mes, ano;
        printf("Digite o dia da consulta\n");
        scanf("%d",&dia);
        printf("Digite o mes da consulta\n");
        scanf("%d",&mes);
        printf("Digite o ano da consulta\n");
        scanf("%d",&ano);
        printf("Digite a hora da consulta\n");
        scanf("%d", &hora);

        while(verificaData(consultas, i, hora, dia, mes, ano, tempId)){
            int opMedHora;
            printf("Data ocupada\nTente outro medico ou outro horario\nDigite 1 para escolher outro medico, mas no mesmo horarrio\nDigite 2 para escolher outro horario, mas com o mesmo medico\nDigite 3 para escolher ouro medico e outro horarrio\n");
            scanf("%d", &opMedHora);
            switch (opMedHora){
                case 1:{
                    printf("Digite o ID do medico\n");
                    scanf("%d", &tempId);
                    break;
                }
                case 2:{
                    printf("Digite o dia da consulta\n");
                    scanf("%d",&dia);
                    printf("Digite o mes da consulta\n");
                    scanf("%d",&mes);
                    printf("Digite o ano da consulta\n");
                    scanf("%d",&ano);
                    printf("Digite a hora da consulta\n");
                    scanf("%d", &hora);
                    break;
                }                
                case 3:{
                    printf("Digite o ID do medico\n");
                    scanf("%d", &tempId);
                    printf("Digite o dia da consulta\n");
                    scanf("%d",&dia);
                    printf("Digite o mes da consulta\n");
                    scanf("%d",&mes);
                    printf("Digite o ano da consulta\n");
                    scanf("%d",&ano);
                    printf("Digite a hora da consulta\n");
                    scanf("%d", &hora);
                    break;
                }
            }
        }

        consultas[i].medicos.id = tempId;
        consultas[i].datas.dia = dia;
        consultas[i].datas.mes = mes;
        consultas[i].datas.ano = ano;
        consultas[i].datas.hora = hora;

    }
}