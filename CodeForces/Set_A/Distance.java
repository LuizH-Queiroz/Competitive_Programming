/*
Let's denote the Manhattan distance between two points p1 (with coordinates (x1,y1)) and
p2 (with coordinates (x2,y2)) as d(p1,p2)=|x1−x2|+|y1−y2|. For example, the distance between two points
with coordinates (1,3) and (4,2) is |1−4|+|3−2|=4.

You are given two points, A and B. The point A has coordinates (0,0), the point B has coordinates (x,y).

Your goal is to find a point C such that:

both coordinates of C are non-negative integers;
d(A,C)=d(A,B)2 (without any rounding);
d(B,C)=d(A,B)2 (without any rounding).
Find any point C that meets these constraints, or report that no such point exists.

Input
The first line contains one integer t (1≤t≤3000) — the number of test cases.

Each test case consists of one line containing two integers x and y (0≤x,y≤50) — the coordinates
of the point B.

Output
For each test case, print the answer on a separate line as follows:

if it is impossible to find a point C meeting the constraints, print "-1 -1" (without quotes);
otherwise, print two non-negative integers not exceeding 106 — the coordinates of point C meeting
the constraints. If there are multiple answers, print any of them. It can be shown that if any
such point exists, it's possible to find a point with coordinates not exceeding 106 that meets the
constraints.
*/


package Set_A;

import java.util.Scanner;


public class Distance {
    static Scanner read = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int tests;
        int coord_x, coord_y;
        int pointC_x, pointC_y;

        tests = read.nextInt();

        for (int i = 0; i < tests; i++)
        {
            coord_x = read.nextInt();
            coord_y = read.nextInt();

            if (IsOdd(coord_x + coord_y)){
                pointC_x = pointC_y = -1;
            }
            else if (IsEven(coord_x) && IsEven(coord_y)){
                pointC_x = coord_x / 2;
                pointC_y = coord_y / 2;
            }
            else { //Both numbers are odd
                pointC_x = coord_x / 2 + 1;
                pointC_y = coord_y / 2;
            }

            System.out.println(pointC_x + " " + pointC_y);
        }
    }

    public static Boolean IsOdd(int num){
        return num % 2 == 1;
    }

    public static Boolean IsEven(int num){
        return num % 2 == 0;
    }
}