#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pergunta {
    char desc[500], opcaoA[100], opcaoB[100], opcaoC[100], opcaoD[100], resposta_final;
};

struct Resultado_Questao {
    
	int pontuacao;
	char nome[100], sobrenome[100]; 
};

int main() {
    struct Pergunta perguntas[4];

    struct Pergunta pergunta1 = 
	{
        "1. Breakdance e um estilo de danca urbana originada no bairro do Bronx Nova Iorque nos anos 70 por afroamericanos Breakdance e uma das principais culturas do hip hop E recentemente foi anunciado pelo COI Comite Olimpico Internacional como nova modalidade para as olimpiadas de Paris 2024 modalidade estreante que promete bastante para os proximos jogos olimpicos.\n\nEm qual pais o breakdance foi criado?",
        "A) EUA",
        "B) Inglaterra",
        "C) Italia",
        "D) Russia",
        'A'
    };
    perguntas[0] = pergunta1;

    struct Pergunta pergunta2 = 
	{
        "2. Os jogos de 2024 tambem serao realizados no Taiti A competicao de surfe sera realizada na famigerada onda de Teahupoo a onda mais amada e a mais temida de todo o mundo.\n\nQual competicao sera realizada fora da Franca?",
        "A) Skate",
        "B) Surfe",
        "C) Salto com vara",
        "D) Natação",
        'B'
    };
    perguntas[1] = pergunta2;

    struct Pergunta pergunta3 = 
	{
        "3. Apos sucesso nas olimpiadas de tokyo 2020 o skate vem pra sua segunda olimpiadas Aurelien Giraud ira competir em casa e conta com apoio de todo povo frances.\n\nQuantos Jogos Olimpicos o Skate participou ate hoje?",
        "A) 1",
        "B) 3",
        "C) 5",
        "D) 4",
        'A'
    };
    perguntas[2] = pergunta3;

    struct Pergunta pergunta4 = 
	{
        "4. Apos 100 anos dos jogos olimpicos de verao de 1924 Paris volta a receber o evento na cidade e isso tambem significa a volta da tocha olimpica para a cidade-berco da era moderna das olimpiadas.\n\nQual o ano da ultima Olimpiada na Franca?",
        "A) 1900",
        "B) 1904",
        "C) 1912",
        "D) 1924",
        'D'
    };
    perguntas[3] = pergunta4;

    int numPerguntas = 4, numeroParticipantes;

    printf("Seja Bem-vindo ao Quiz Olimpico!\n");

    printf("Quantos participantes vao responder o quiz? : ");
    scanf("%d", &numeroParticipantes);

    FILE *arquivoResultado_Questao = fopen("resultados.csv", "a");

    if (arquivoResultado_Questao == NULL) {
        printf("Nao foi possivel abrir o arquivo que contem os resultados.\n");
        return 1;
    }

    for (int x = 0; x < numeroParticipantes; x++) {
        printf("\nDados do Participante %d:\n", x + 1);

        struct Resultado_Questao resultadoAtual;
        	printf("Nome do participante: ");
        	scanf("%s", resultadoAtual.nome);

        printf("Sobrenome do participante: ");
        scanf("%s", resultadoAtual.sobrenome);

        resultadoAtual.pontuacao = 0;

        for (int i = 0; i < numPerguntas; i++) {
            printf("\n%s\n", perguntas[i].desc);
            printf("%s\n%s\n%s\n%s\n", perguntas[i].opcaoA, perguntas[i].opcaoB, perguntas[i].opcaoC, perguntas[i].opcaoD);

            char resposta;
            printf("Responda utilizando em MAIUSCULO (A/B/C/D): ");
            scanf(" %c", &resposta);

            if (resposta == perguntas[i].resposta_final) {
                resultadoAtual.pontuacao++;
                printf("Parabens!! Sua resposta esta certa!\n");
            } else {
                printf("Infelizmente sua resposta esta errada. A resposta correta e: %c\n", perguntas[i].resposta_final);
            }
        }

        fprintf(arquivoResultado_Questao, "Nome do Participante: %s %s, Pontuação do Participante: %d\n", resultadoAtual.nome, resultadoAtual.sobrenome, resultadoAtual.pontuacao);
    }

    fclose(arquivoResultado_Questao);

	system ("pause");
    return 0;
}
