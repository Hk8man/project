#pragma once
#include "UserCheck.h"

class RecommendationSystem 
{
public:
    RecommendationSystem(vector<Food>& foodVector, vector<UserAccount> accounts) : foodVector(foodVector), accounts(accounts)
    {}

    void Starting();
    void Member_login();
    void Non_member_login();
    void Non_member_register();

    void Best_Choice_Recommendation();
    void Random_Recommendation();
    
    void Non_member_main_menu();
    void Member_main_menu(UserAccount& host);

    void Normal_Menu_Recommendation();

private:
    vector<Food>& foodVector;
    vector<UserAccount>& accounts; //관련해서 host를 구분짓는 함수가 필요함
};

void RecommendationSystem::Starting()
{
    int selection;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │       Welcome to Recommendation System for GISTIANS           ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "                   For Member, Please Press 1. " << endl;
    cout << "                   For Non-Member, Please Press 2. " << endl;
    cout << "                   >>> ", cin >> selection;
    if (selection == 1) { Member_login(); } //숫자 1이 입력되면 Member login 부분 밑에 출력 (ID, 비밀번호 입력)
    else if (selection == 2) { Non_member_login(); } //숫자 2가 입력되면 Non member login 부분 밑에 출력 (그대로 진행 or 회원가입)
    else
    {
        throw SelectionInvalid(" Input is wrong, Please rewrite number.");
    } //1이나 2가 아닌 숫자가 selection에 입력되면 오류 실행
}

void RecommendationSystem::Member_login()
{
    string ID;
    string password;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │        Member Log In Page : Write Your ID And Password        ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "                        If you want to UNDO, Press 0. " << endl;
    cout << "                            ID : ", cin >> ID;
    if (ID == "0")
    {
        cout << " UNDOING..." << endl;
        Starting();
    } //재시작
    else
    {
        cout << "                      Password : ", cin >> password;
        for (int i = 0; i < int(this->accounts.size()); i++)
        {
            if (this->accounts[i].get_ID().compare(ID) == 0 && this->accounts[i].get_Password().compare(password) == 0) // ID와 비밀번호 모두 확인
            {
                Member_main_menu(this->accounts[i]); // 수정된 부분: 함수 호출 시 매개변수로 객체를 전달
                return;
            }
        }
        // 로그인 실패 시에만 재귀적으로 호출합니다.
        cout << "ID and Password are incorrect. Please try again." << endl;
        Member_login();
    }
}


void RecommendationSystem::Non_member_login()
{
    int selection;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │        For Non-Members : Do you want to register to us?       ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "                YES for 1, NO for 2, UNDO for 3 : ", cin >> selection;
    if (selection == 1) { Non_member_register(); } //회원 등록으로 넘어감
    else if (selection == 2) { Non_member_main_menu(); } //Non-member 상태로 진행 ->
    else
    {
        throw SelectionInvalid(" UNDOING...");
    } //이상한 숫자 입력시 시작 페이지로 넘어감
}

void RecommendationSystem::Non_member_register()
{
    string ID;
    string password;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │      For Non-Members : Please write your ID and Password      ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "                        If you want to UNDO, Press 0. " << endl;
    cout << "                            ID : ", cin >> ID;
    if (ID == "0") { Non_member_login(); } //비회원 로그인으로 돌아감
    else
    {
        cout << "                      Password : ", cin >> password;
        //"여기 이후로 로그인 절차를 완료시킬 코드 입력"
        //"여기 이후로 로그인 절차를 완료시킬 코드 입력"
        //"여기 이후로 로그인 절차를 완료시킬 코드 입력"
        //"여기 이후로 로그인 절차를 완료시킬 코드 입력"

    } //ID를 입력받았으므로, 새로운 UserAccount 객체(새로운 계정) 생성 작업을 완료해야함
}

void RecommendationSystem::Best_Choice_Recommendation()
{

    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │              Best_Choice_Recommendatioin System               ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "               According to the Yesterday's Rcording..." << endl;
    cout << "                   Today's Choice is : " << endl;
    cout << "                         Have a nice meal!" << endl;
}

void RecommendationSystem::Random_Recommendation()
{
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │                 Random Recommendation System                  ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    srand(time(NULL));
    int num_of_food = int(this->foodVector.size()); //foodCount 음식 개수
    int index = int(rand() % num_of_food);
    cout << "              Today's Choice : " << this->foodVector[index].getName() << endl;
    cout << "              Have a nice meal!" << endl;
}

void RecommendationSystem::Non_member_main_menu()
{
    int selection;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │         Non-Member Main Menu : What do you want to do?        ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    cout << "                 Best Choice Recommendation for 1" << endl;
    cout << "   ※ Best Choice Recommendation : Recommend from our member data" << endl;
    cout << "                 Random Menu Recommendation for 2" << endl;
    cout << "                                    Restart for 3" << endl;
    cout << "                                      Selection :", cin >> selection;
    if (selection == 1) { Best_Choice_Recommendation(); } //회원들의 데이터를 바탕으로 한 추천 제시
    else if (selection == 2) { Random_Recommendation(); } // 수정된 부분: 함수 호출 시 매개변수 없이 호출
    else if (selection == 3) { Starting(); }
    else
    {
        cout << "Nothing happened. Please rewrite." << endl;
        Non_member_main_menu();
    }
}

void RecommendationSystem::Member_main_menu(UserAccount& host)
{
    cout << "  [" << host.get_ID() << ", Welcome! ]" << endl;
    cout << " ┌---------------------------------------------------------------┐" << endl;
    cout << " │             Member Main Menu : What do you want to do?        ㅣ" << endl;
    cout << " └---------------------------------------------------------------┘" << endl;
    int selection;
    cout << "                 Normal Menu Recommendation for 1" << endl;
    cout << "                 Random Menu Recommendation for 2" << endl;
    cout << "                                    Restart for 3" << endl;
    cout << "                                      Selection :", cin >> selection;
    if (selection == 1) { Normal_Menu_Recommendation(); } //유사도를 이용한 추천 제시
    else if (selection == 2) { Random_Recommendation(); } //랜덤 추천 제시
    else if (selection == 3) { Starting(); }
    else
    {
        cout << "Nothing happened. Please rewrite." << endl;
        //Non_member_main_menu(, foodVector); -> 여기에서 본인의 객체를 다시 넣어서 Restart 해야함
    }
}

void RecommendationSystem::Normal_Menu_Recommendation()
{
    cout << "미완성" << endl;
}