/*
You are given an array of integers a of length n. The elements of the array can be either
different or the same.

Each element of the array is colored either blue or red. There are no unpainted elements in the array.
One of the two operations described below can be applied to an array in a single step:

either you can select any blue element and decrease its value by 1;
or you can select any red element and increase its value by 1.
Situations in which there are no elements of some color at all are also possible. For example,
if the whole array is colored blue or red, one of the operations becomes unavailable.

Determine whether it is possible to make 0 or more steps such that the resulting array is a permutation of
numbers from 1 to n?

In other words, check whether there exists a sequence of steps (possibly empty) such that after applying it,
the array a contains in some order all numbers from 1 to n (inclusive), each exactly once.

Input
The first line contains an integer t (1≤t≤104) — the number of input data sets in the test.

The description of each set of input data consists of three lines. The first line contains
an integer n (1≤n≤2⋅105) — the length of the original array a. The second line contains n integers
a1, a2, ..., an (−109≤ai≤109) — the array elements themselves.

The third line has length n and consists exclusively of the letters 'B' and/or 'R': ith character is 'B' if
ai is colored blue, and is 'R' if colored red.

It is guaranteed that the sum of n over all input sets does not exceed 2⋅105.

Output
Print t lines, each of which contains the answer to the corresponding test case of the input. Print YES
as an answer if the corresponding array can be transformed into a permutation, and NO otherwise.

You can print the answer in any case (for example, the strings yEs, yes, Yes, and YES will be recognized
as a positive answer).
*/


package Set_D;

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class Blue_Red_Permutation {
    static Scanner read = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        int tests;

        tests = read.nextInt();

        for (int i = 0; i < tests; i++)
        {
            int n_numbers = read.nextInt();
            int[] values = new int[n_numbers];
            Vector<Integer> blue = new Vector<>(); //blue elements may have it's value decreased
            Vector<Integer> red = new Vector<>(); //red elements may have it's value increased
            Boolean possible = true;
            int j;

            for (j = 0; j < n_numbers; j++) values[j] = read.nextInt();

            String colors = read.next();
            for (j = 0; j < n_numbers; j++)
            {
                if (colors.charAt(j) == 'B') blue.add(values[j]);
                else red.add(values[j]);
            }
            Collections.sort(blue);
            Collections.sort(red);

            //Now, let's see if the blue elements - the ones that may be decreasaed -
            //may assume the lower values, while the red ones assume the higher values.
            //If not, we won't have the permutation array
            for (j = 1; j <= blue.size(); j++)
            {
                if (blue.get(j-1) < j){
                    possible = false;
                    break;
                }
            }
            for (j = blue.size()+1; j <= n_numbers; j++)
            {
                if (red.get(j - (blue.size()+1)) > j){
                    possible = false;
                    break;
                }
            }

            if (possible) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}