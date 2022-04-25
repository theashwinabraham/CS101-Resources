#include <simplecpp>
bool lab_marks(int &total_marks){
    int labmarks, min_1, min_2;
    cin >> min_1 >> min_2;
    total_marks+=(min_1 + min_2);
    if(min_1>min_2){
        int temp = min_1;
        min_1 = min_2;
        min_2 = temp;
    }
    for(int i = 0; i<5; i++){
        cin >> labmarks;
        total_marks+=labmarks;
        if(labmarks<min_1){min_2 = min_1; min_1 = labmarks;}
        else if(labmarks<min_2){min_2 = labmarks;}
    }
    total_marks-=(min_1+min_2);
    int plagiarism;
    cin >> plagiarism;
    return (plagiarism==1);
}
bool quiz_marks(int &total_marks){
    int min_quiz = 2, quizmarks;
    for(int i = 0; i<6; i++){
        cin >> quizmarks;
        total_marks+=quizmarks;
        if(quizmarks<min_quiz){min_quiz = quizmarks;}
    }
    total_marks-=min_quiz;
    int cheated;
    cin >> cheated;
    return (cheated==1);
}
int midsem_marks(){
    int midsemmarks;
    cin >> midsemmarks;
    return midsemmarks;
}
int endsem_marks(){
    int endsemmarks;
    cin >> endsemmarks;
    return endsemmarks;
}
bool project_marks(int &total_marks){
    int projectmarks;
    cin >> projectmarks;
    int plagiarism;
    cin >> plagiarism;
    if(total_marks>80){
        total_marks+=projectmarks;
    }
    return (plagiarism==1);
}
int calculate_grade(int total_marks, bool plag_in_quiz, bool plag_in_lab, bool plag_in_project){
    int grade;
    if(total_marks>=0 && total_marks<=30){grade = 0;}
    else if(total_marks<=40){grade = 4;}
    else if(total_marks<=50){grade = 5;}
    else if(total_marks<=60){grade = 6;}
    else if(total_marks<=70){grade = 7;}
    else if(total_marks<=80){grade = 8;}
    else if(total_marks<=90){grade = 9;}
    else if(total_marks<=100){grade = 10;}
    grade-=(plag_in_quiz+plag_in_lab+plag_in_project);
    if(grade<4){grade = 0;}
    return grade;
}
