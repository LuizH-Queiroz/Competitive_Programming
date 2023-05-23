#include <iostream>
#include <queue>

#define N_JOGADORES 16
#define J1 1
#define J2 9


using namespace std;


int main() {
    queue<int> q;
    int jogador;
    int jogos = 8;

    for (int i = 0; i < N_JOGADORES; i++)
    {
        cin >> jogador;
        q.push(jogador);
    }


    while(true)
    {
        int comp1, comp2;
        bool partidaOcorreu = false;

        for (int i = 0; i < jogos; i++)
        {
            comp1 = q.front();
            q.pop();

            comp2 = q.front();
            q.pop();

            if ((comp1 == J1 && comp2 == J2) || (comp1 == J2 && comp2 == J1))
            {
                partidaOcorreu = true;
                break;
            }

            if (comp1 == J1 || comp1 == J2)
                q.push(comp1);
            else
                q.push(comp2);
        }

        if (partidaOcorreu)
        {
            switch(jogos) {
                case 8:
                    cout << "oitavas" << endl;
                    break;

                case 4:
                    cout << "quartas" << endl;
                    break;
                
                case 2:
                    cout << "semifinal" << endl;
                    break;
                
                case 1:
                    cout << "final" << endl;
                    break;
            }

            break;
        }

        jogos /= 2;
    }



    return 0;
}