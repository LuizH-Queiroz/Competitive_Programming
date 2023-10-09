/*
Usain has an online store specializing in selling 3D puzzles made by 3D printers.
One of the best-selling puzzles these days is the Maze in Bolt. This puzzle is composed of two parts:
a screw-shaped piece with an embossed labyrinth engraved on it, and a nut. The inner part of the nut
may contain tips. These tips make the nut slide only through the corridors of the labyrinth.

Initially, the two parts of the puzzle are separated. The challenge is to slide the nut all the way
through the maze until it reaches the head of the bolt. The nut can be moved clockwise, counterclockwise,
down (towards the head of the bolt), and up (away from the head). Each of these movements is only
possible when every tip in the inner part of the nut is not prevented from sliding to the new position
due to some wall of the maze. Besides the mentioned movements, another one is allowed: when the bolt and
the nut are separated, the nut can be flipped. The illustration below shows both parts of the puzzle as well
as all the allowed moves.

		
(a) Screw-shaped piece	(b) Nut piece	(c) Movements of the nut
A customer placed an order for a large quantity of the Maze in Bolt. Each puzzle is designed by Usain himself
in a random and unique way but, due to the size of the order and the tight deadline, he believes he will not
be able to check whether the created puzzles have a solution or not. Usain asked for your help in devising
an algorithm that quickly checks any given pair of nut and bolt. For doing so, the inner part of the nut
will be modeled as a binary circular string. Regarding the bolt, each row of the maze will be modeled the
same way.

Input
The first line contains two integers R (1≤R≤1000) and C (3≤C≤100),
indicating respectively the number of rows and columns of the maze. The second line contains a circular
string S of length C, representing the inner part of the nut. Each character of S
is "1" if the nut has a tip in the corresponding position, while an empty space is indicated by
character "0". Each of the next R lines contains a circular string describing a row of the maze.
In this case, each character of the string is "1" if the maze has a wall in the corresponding position,
while an empty space is indicated by character "0". Rows are given from top (the tip of the bolt) to
bottom (the head).

Output
Output a single line with the uppercase letter "Y" if the puzzle has a solution, and the uppercase
letter "N" otherwise.
*/
#include <bits/stdc++.h>

using namespace std;


int R, C;
string rosca;
vector<string> labirinto;
vector<vector<bool>> matriz;
vector<vector<bool>> visitado;


bool valido(int pulo, int linha) {

    for (int i = 0; i < rosca.size(); i++)
    {
        if (rosca[i] == '1' && labirinto[linha][((i+pulo)%rosca.size())] == '1')
        {
            return false;
        }
    }

    return true;
}


bool posicaoValida(int i, int j) {
    return (i >= 0);
}


bool search(int i, int j) {
    if (i == (R-1))
    {
        return matriz[i][j];
    }
    else if (!posicaoValida(i, j))
    {
        return false;
    }
    else if (matriz[i][j] == false)
    {
        return false;
    }
    else if (visitado[i][j])
    {
        return false;
    }
    visitado[i][j] = true;


    int vj;
    if (search(i-1, j))
        return true;
    if (search(i+1, j))
        return true;
    

    vj = j-1;
    if (vj == -1)
        vj = rosca.size()-1;
    if (search(i, vj))
        return true;
    

    vj = (j+1) % rosca.size();
    if (search(i, vj))
        return true;

    
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    ///////////////////////


    cin >> R >> C;
    cin >> rosca;

    labirinto = vector<string>(R);
    matriz = vector<vector<bool>>(R, vector<bool>(C));
    visitado = vector<vector<bool>>(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        cin >> labirinto[i];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz[i][j] = valido(j, i);
        }
    }




    int possible = false;
    for (int i = 0; i < C; i++)
    {
        if (search(0, i))
        {
            possible = true;
            break;
        }
    }

    if (!possible)
    {
        reverse(rosca.begin(), rosca.end());
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                matriz[i][j] = valido(j, i);
            }
        }

        visitado = vector<vector<bool>>(R, vector<bool>(C, false));
        for (int i = 0; i < C; i++)
        {
            if (search(0, i))
            {
                possible = true;
                break;
            }
        }
    }

    if (possible)
        cout << "Y" << endl;
    else
        cout << "N" << endl;



    return 0;
}