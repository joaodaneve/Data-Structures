/*
Questão 2

Faça um programa em C++ que sirva para cadastro de turmas em uma universidade;

Crie as seguintes classes: turma, pessoa, aluno e professor;

Solicite então, as seguintes informações

- Codigo da disciplina da turma (int);
- Codigo da turma (int);
- CPF do professor da turma (long);
- telefone do professor (int);
- SIAPE do professor (int);
- Quantidade de alunos na turma;

Para cada aluno, solicitar:

- CPF do aluno (long)
- Telefone do aluno (int)
- matricula do aluno(int)
- CRA do aluno (float)
*/

#include <iostream>
#include <string>
#include <stdio.h>


class pessoa{
    long cpf;
    int telefone;
public:
    pessoa(long c, int t): cpf(c), telefone(t) {
        printf("=-=-=-=-=-=-=-=\n");
        printf("Pessoa %ld criada com sucesso!");
    }
    ~pessoa(){
        printf("Pessoa %ld removida com sucesso!");
    }

    long get_cpf() {
        return cpf;
    }
    void set_cpf(long c) {
        cpf = c;
    }

    int get_telefone() {
        return telefone;
    }
    void set_telefone(int t){
        telefone = t;
    }
};

class aluno: public pessoa { // Aluno herda de pessoa
    int matricula_aluno;
    float cra_aluno;
    int cpf;
public:
    aluno(long c = 0, int t = 0, int ma = 0, float cra = 0): pessoa(c, t), matricula_aluno(ma), cra_aluno(cra) { // To passando o construtor de pessoa pra DEPOIS Passar a parte específica de aluno
        //matricula_aluno = ma;
        //cra_aluno = cra;
        printf("=-=-=-=-=-=-=-=\n");
        printf("Aluno %d criado com sucesso!", ma);

    }
    ~aluno(){
        printf("Aluno %d removido com sucesso!", matricula_aluno);
    }

    int get_matricula(){
        return matricula_aluno;
    }
    void set_matricula(int m){
        matricula_aluno = m;
    }

    int get_cra(){
        return cra_aluno;
    }
    void set_cra(float c){
        cra_aluno = c;
    }

    void print_info(){
        printf("Matricula aluno: %d", matricula_aluno);
        printf("CRA aluno: %f", cra_aluno);
        printf("CPF aluno: %ld\n", get_cpf());
        printf("Telefone aluno: %d", get_telefone());
    }
};

class professor: public pessoa { // Profesor herda de pessoa
    int codigo_professor;
public:
    professor(long c, int t, int cp): pessoa(c, t){
        codigo_professor = cp;

        printf("=-=-=-=-=-=-=-=\n");
        printf("Professor %d criado com sucesso!", cp);
    }
    ~professor(){
        printf("Professor %d removido com sucesso!", codigo_professor);

    }

    int get_codigo_professor(){
        return codigo_professor;
    }
    void set_codigo_professor(int cp){
        codigo_professor = cp;
    }
};

class turma{
    int codigo_disciplina;
    int codigo_turma;
    int quantidade_alunos;
    professor* professor_turma;
    aluno* alunos_turma;
public:
    turma(int cd, int ct, int qa, professor* pt, aluno* at): codigo_disciplina(cd), codigo_turma(ct), quantidade_alunos(qa){
        professor_turma = new professor(pt->get_codigo_professor(), pt->get_cpf(), pt->get_telefone());
        alunos_turma = at;

        printf("=-=-=-=-=-=-=-=\n");
        printf("Turma %d criada com sucesso!", ct);

    }
    ~turma(){
        delete professor_turma;
        delete[] alunos_turma;  
    }

    int get_codigo_disciplina(){
        return codigo_disciplina; 
    }
    void set_codigo_disciplina(int cd){
        codigo_disciplina = cd;
    }

    int get_codigo_turma(){
        return codigo_turma;
    }
    void set_codigo_turma(int ct){
        codigo_turma = ct;
    }

    int get_quantidade_alunos(){
        return quantidade_alunos;
    }
    void set_quantidade_alunos(int qa){
        quantidade_alunos = qa;
    }

    professor* get_professor(){
        return professor_turma;
    }
    void set_professor(professor* p){
        professor_turma = p;
    }

    aluno* get_alunos_turma(){
        return alunos_turma;
    }
    void set_alunos_turma(aluno* a){
        alunos_turma = a;
    }

    void print_info(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Turma %d", codigo_turma);
        printf("Disciplina %d", codigo_disciplina);
        printf("codigo Professor %d", professor_turma->get_codigo_professor());
        printf("CPF Professor %ld", professor_turma->get_cpf());
        printf("Telefone Professor %d", professor_turma->get_telefone());
        printf("Quantidade de alunos %d", quantidade_alunos);

        for (int i = 0; i < quantidade_alunos; i++){
            alunos_turma[i].print_info();
        }
        printf("=-=-=-=-=-=-=-=\n");
    }
};

int main(void){

    // Exibir  todas as informacoes da turma, incluindo a quantidade de alunos
    // cadastrados (usar atributo de classe para implementar esta funcionalidade);
    turma* primeira_turma;
    professor* prof;
    aluno* alunos;
    int codigo_turma;
    int codigo_disciplina;
    int codigo_professor;
    int cpf_professor;
    int telefone_professor;
    int quantidade_alunos;

    printf("Digite o codigo da turma: ");
    scanf("%d", &codigo_turma);

    printf("Digite o codigo da disciplina: ");
    scanf("%d", &codigo_disciplina);

    printf("Digite o codigo do professor da turma: ");
    scanf("%d", &codigo_professor);

    printf("Digite o CPF do professor da turma: ");
    scanf("%d", &cpf_professor);

    printf("Digite o telefone do professor da turma: ");
    scanf("%d", &telefone_professor);

    prof = new professor(cpf_professor, telefone_professor, codigo_professor);

    printf("Digite a quantidade de alunos da turma: ");
    scanf("%d", &quantidade_alunos);

    alunos = new aluno[quantidade_alunos];
    for (int i = 0; i < quantidade_alunos; i++){
        int cpf;
        int telefone;
        int matricula;
        float cra;

        printf("Digite o CPF do aluno %d: ", i);
        scanf("%d", &cpf);

        printf("Digite o telefone do aluno %d: ", i);
        scanf("%d", &telefone);

        printf("Digite a matricula do aluno %d: ", i);
        scanf("%d", &matricula);

        printf("Digite o CRA do aluno %d: ", i);
        scanf("%f", &cra);

        alunos[i].set_cpf(cpf);
        alunos[i].set_telefone(telefone);
        alunos[i].set_matricula(matricula);
        alunos[i].set_cra(cra);
    }

    primeira_turma = new turma(codigo_disciplina, codigo_turma, quantidade_alunos, prof, alunos);
    primeira_turma->print_info();
    delete primeira_turma;

    return 0;
}