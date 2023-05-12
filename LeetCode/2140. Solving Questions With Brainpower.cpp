/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and
make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve
each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

    For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
        If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
        If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.

Return the maximum points you can earn for the exam.
*/


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> points(questions.size()+1);
        points.back() = 0;

        for (int i = questions.size()-1; i >= 0; i--)
            points[i] = max(points[i+1], questions[i][0] + points[ min(i+(questions[i][1]+1), (int) (points.size()-1)) ]);

        return points[0];
    }
};