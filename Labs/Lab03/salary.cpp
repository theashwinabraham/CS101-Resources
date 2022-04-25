#include <simplecpp>
main_program{
    float BS, HRA, DA, GS; //Basic Salary, HRA, DA, Gross Salary
    cin >> BS;
    if(BS<=10000){ //checking if BA<=10000
        HRA = 0.2*BS; //given in problem for BA <= 10000
        DA = 0.8*BS;
    }
    else if(BS<=20000){ //since else if used, executed iff 10000 < BA <= 20000
        HRA = 0.25*BS; //given in problem for 10000 < BA <= 20000
        DA = 0.9*BS;
    }
    else{ //remaining case BA > 20000
        HRA = 0.3*BS; //given in problem for BA > 20000
        DA = 0.95*BS;
    }
    GS = BS+HRA+DA; //Gross salary formula
    cout << GS;
}
