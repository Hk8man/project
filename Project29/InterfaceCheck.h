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
    vector<UserAccount>& accounts; //�����ؼ� host�� �������� �Լ��� �ʿ���
};

void RecommendationSystem::Starting()
{
    int selection;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��       Welcome to Recommendation System for GISTIANS           ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "                   For Member, Please Press 1. " << endl;
    cout << "                   For Non-Member, Please Press 2. " << endl;
    cout << "                   >>> ", cin >> selection;
    if (selection == 1) { Member_login(); } //���� 1�� �ԷµǸ� Member login �κ� �ؿ� ��� (ID, ��й�ȣ �Է�)
    else if (selection == 2) { Non_member_login(); } //���� 2�� �ԷµǸ� Non member login �κ� �ؿ� ��� (�״�� ���� or ȸ������)
    else
    {
        throw SelectionInvalid(" Input is wrong, Please rewrite number.");
    } //1�̳� 2�� �ƴ� ���ڰ� selection�� �ԷµǸ� ���� ����
}

void RecommendationSystem::Member_login()
{
    string ID;
    string password;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��        Member Log In Page : Write Your ID And Password        ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "                        If you want to UNDO, Press 0. " << endl;
    cout << "                            ID : ", cin >> ID;
    if (ID == "0")
    {
        cout << " UNDOING..." << endl;
        Starting();
    } //�����
    else
    {
        cout << "                      Password : ", cin >> password;
        for (int i = 0; i < int(this->accounts.size()); i++)
        {
            if (this->accounts[i].get_ID().compare(ID) == 0 && this->accounts[i].get_Password().compare(password) == 0) // ID�� ��й�ȣ ��� Ȯ��
            {
                Member_main_menu(this->accounts[i]); // ������ �κ�: �Լ� ȣ�� �� �Ű������� ��ü�� ����
                return;
            }
        }
        // �α��� ���� �ÿ��� ��������� ȣ���մϴ�.
        cout << "ID and Password are incorrect. Please try again." << endl;
        Member_login();
    }
}


void RecommendationSystem::Non_member_login()
{
    int selection;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��        For Non-Members : Do you want to register to us?       ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "                YES for 1, NO for 2, UNDO for 3 : ", cin >> selection;
    if (selection == 1) { Non_member_register(); } //ȸ�� ������� �Ѿ
    else if (selection == 2) { Non_member_main_menu(); } //Non-member ���·� ���� ->
    else
    {
        throw SelectionInvalid(" UNDOING...");
    } //�̻��� ���� �Է½� ���� �������� �Ѿ
}

void RecommendationSystem::Non_member_register()
{
    string ID;
    string password;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��      For Non-Members : Please write your ID and Password      ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "                        If you want to UNDO, Press 0. " << endl;
    cout << "                            ID : ", cin >> ID;
    if (ID == "0") { Non_member_login(); } //��ȸ�� �α������� ���ư�
    else
    {
        cout << "                      Password : ", cin >> password;
        //"���� ���ķ� �α��� ������ �Ϸ��ų �ڵ� �Է�"
        //"���� ���ķ� �α��� ������ �Ϸ��ų �ڵ� �Է�"
        //"���� ���ķ� �α��� ������ �Ϸ��ų �ڵ� �Է�"
        //"���� ���ķ� �α��� ������ �Ϸ��ų �ڵ� �Է�"

    } //ID�� �Է¹޾����Ƿ�, ���ο� UserAccount ��ü(���ο� ����) ���� �۾��� �Ϸ��ؾ���
}

void RecommendationSystem::Best_Choice_Recommendation()
{

    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��              Best_Choice_Recommendatioin System               ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "               According to the Yesterday's Rcording..." << endl;
    cout << "                   Today's Choice is : " << endl;
    cout << "                         Have a nice meal!" << endl;
}

void RecommendationSystem::Random_Recommendation()
{
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��                 Random Recommendation System                  ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    srand(time(NULL));
    int num_of_food = int(this->foodVector.size()); //foodCount ���� ����
    int index = int(rand() % num_of_food);
    cout << "              Today's Choice : " << this->foodVector[index].getName() << endl;
    cout << "              Have a nice meal!" << endl;
}

void RecommendationSystem::Non_member_main_menu()
{
    int selection;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��         Non-Member Main Menu : What do you want to do?        ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << "                 Best Choice Recommendation for 1" << endl;
    cout << "   �� Best Choice Recommendation : Recommend from our member data" << endl;
    cout << "                 Random Menu Recommendation for 2" << endl;
    cout << "                                    Restart for 3" << endl;
    cout << "                                      Selection :", cin >> selection;
    if (selection == 1) { Best_Choice_Recommendation(); } //ȸ������ �����͸� �������� �� ��õ ����
    else if (selection == 2) { Random_Recommendation(); } // ������ �κ�: �Լ� ȣ�� �� �Ű����� ���� ȣ��
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
    cout << " ��---------------------------------------------------------------��" << endl;
    cout << " ��             Member Main Menu : What do you want to do?        ��" << endl;
    cout << " ��---------------------------------------------------------------��" << endl;
    int selection;
    cout << "                 Normal Menu Recommendation for 1" << endl;
    cout << "                 Random Menu Recommendation for 2" << endl;
    cout << "                                    Restart for 3" << endl;
    cout << "                                      Selection :", cin >> selection;
    if (selection == 1) { Normal_Menu_Recommendation(); } //���絵�� �̿��� ��õ ����
    else if (selection == 2) { Random_Recommendation(); } //���� ��õ ����
    else if (selection == 3) { Starting(); }
    else
    {
        cout << "Nothing happened. Please rewrite." << endl;
        //Non_member_main_menu(, foodVector); -> ���⿡�� ������ ��ü�� �ٽ� �־ Restart �ؾ���
    }
}

void RecommendationSystem::Normal_Menu_Recommendation()
{
    cout << "�̿ϼ�" << endl;
}