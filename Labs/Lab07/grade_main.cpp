#include <simplecpp>
/*
Marking Scheme:
1: Quizzes  (2x5 = 10)  best 5 of 6
2: Labs     (2x5 = 10)  best 5 of 7
3: Midsem   (30)
4: Endsem   (40)
5: Project  (pass / nopass)
Threshold for project to be considered is 80 marks (AB grade cutoff)
*/
// Function declarations
bool lab_marks(int &total_marks);
bool quiz_marks(int &total_marks);
int midsem_marks();
int endsem_marks();
bool project_marks(int &total_marks);
int calculate_grade(int total_marks, bool plag_in_quiz, bool plag_in_lab, bool plag_in_project);

main_program
{
    int total_marks = 0;
    bool plag_in_lab = lab_marks(total_marks);
    bool plag_in_quiz = quiz_marks(total_marks);
    total_marks += midsem_marks();
    total_marks += endsem_marks();
    bool plag_in_project = project_marks(total_marks);
    int grade = calculate_grade(total_marks, plag_in_quiz, plag_in_lab, plag_in_project);
    cout << grade << endl;
}