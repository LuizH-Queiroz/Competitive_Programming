/*
Monarchy succession can be a tricky topic as it might take into account multiple factors such as descent,
sex, legitimacy, and religion. Usually, the Crown is inherited by a sovereign's child or by a childless
sovereign's nearest collateral line. Not really straightforward, right? And that's one of the reasons why,
all over the world, monarchy is on the edge.

Nlogonia is still ruled by a monarchy though, luckily with simple succession rules. In general,
there are only two aspects to take into account: "children comes before siblings" and
"older comes before younger".

The reign servants maintain a beautiful and enormous tapestry where the bloodline of Constant,
Nlogonia's first ruler, is drawn in the shape of a tree. Whenever a new family member is born a new
branch from the parent to the child is drawn in the tapestry. This is such an important event that
legend says that when Constant's descendants have a child they will never die before watching their
child's name added to the tapestry. When someone dies, a cross is drawn close to that person's name.
Whenever the current monarch dies, the tapestry is used by the servants to determine who the next ruler
should be. In order to determine who that person is, the servants start from Constant and traverse the
tree according to the rules described earlier, "children comes before siblings" and
"older comes before younger". They descend the tree starting from Constant, followed by Constant's
first child, followed by that child's first child, and so on, until reaching the first person alive
or a family member that has no children left to follow, in which case they then go back to that
person's parent and move into that parent's next child, repeating the process until the new monarch
is determined.

After thousands of years in power Constant's bloodline is huge. To maintain the tapestry and,
when the time comes, to determine who the next monarch should be are lengthy processes and Nlogonian
servants decided it's time to modernize. They want to create a program to be used to maintain Constant's
bloodline, which can also point who the next monarch should be after a ruler's tragic death. Given the
importance of this task, the monarchy servants want to test the program by checking that it produces
the correct output for all events that happened so far. There is one issue though, none of them is really
good with programming and that's why they came after you for help.

More technically, each person in Constant's bloodline will be represented by a unique positive integer
identifier. Whenever a new child is born, they take the next lowest unique identifier.
Constant's identifier is equal to 1, and initially he's the only person alive. You will be given many
events to process, in chronological order. Whenever someone dies, you should help the monarchy servants
to figure out who the current monarch is. It's guaranteed that there will always be someone alive to rule.

Input
The first line contains an integer Q (1≤Q≤105), representing how many events should be processed.
The following Q lines contain two integers ti and xi each, representing the i-th event type and
argument. If ti is equal to 1, then it means that person with identifier xi had a new child. If ti
is equal to 2, then it means that person with identifier xi died.

Output
For each event in which someone dies, you should print a line with an integer, representing the identifier
of the current monarch.
*/
#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;


vector<bool> isAlive;
vector<int> parent;
vector<vector<int>> children;
vector<int> nextChild;
int king;
int nextID;


int nextKing(int current) {
    if (isAlive[current])
    {
        return current;
    }

    int next;
    for (int child = nextChild[current]; child < children[current].size(); child++)
    {
        nextChild[current] = child+1;
        if ((next = nextKing(children[current][child])) != -1)
        {
            return next;
        }
    }

    return -1;
}


int main() {
    ios::sync_with_stdio(0);
    ///////////////////////
    int numEvents;
    int event, person;


    cin >> numEvents;

    isAlive = vector<bool>(numEvents+1, true);
    parent = vector<int>(numEvents+1);
    children = vector<vector<int>>(numEvents+1);
    nextChild = vector<int>(numEvents+1, 0);
    king = 1;
    nextID = 2;

    for (int i = 0; i < numEvents; i++)
    {
        cin >> event >> person;

        if (event == 1)
        {
            children[person].push_back(nextID);
            parent[nextID] = person;
            nextID++;
        }
        else
        {
            isAlive[person] = false;

            int temp;
            while((temp = nextKing(king)) == -1)
            {
                king = parent[king];
            }
            king = temp;

            cout << king << endl;
        }
    }


    return 0;
}