#include "UserCheck.h"
#include "FoodMenu.h"
#include "Error.h"
#include "InterfaceCheck.h"

int main()
{
    //Admin 계정 설정
    UserAccount Admin("admin", "admin");

    //음식 객체 설정
    Baedalgeek baedal1("Chicken", "Seoul", 11, 23);
    Baedalgeek baedal2("Pizza", "Busan", 12, 22);
    Baedalgeek baedal3("Burger", "Incheon", 10, 21);

    Hak_sik haksik1("Rice", "Dormitory", Hak_sik::GENERAL_MENU, 7, 9);
    Hak_sik haksik2("Noodles", "Main Building", Hak_sik::SPECIFIC_MENU, 12, 14);
    Hak_sik haksik3("Soup", "Science Hall", Hak_sik::GENERAL_MENU, 18, 20);

    Cafe cafe1("Latte", "Library");
    Cafe cafe2("Espresso", "Gym");
    Cafe cafe3("Cappuccino", "Art Building");

    //음식 담은 벡터 설정
    vector<Food> foodVector = { baedal1, baedal2, baedal3, haksik1, haksik2, haksik3, cafe1, cafe2, cafe3 };

    //User 객체 설정
    UserAccount user1("User1", "password1");
    user1.push_back_foodCount(1);
    user1.push_back_foodCount(2);
    user1.push_back_foodCount(3);

    UserAccount user2("User2", "password2");
    user2.push_back_foodCount(2);
    user2.push_back_foodCount(3);
    user2.push_back_foodCount(4);

    UserAccount user3("User3", "password3");
    user3.push_back_foodCount(3);
    user3.push_back_foodCount(4);
    user3.push_back_foodCount(5);

    vector<UserAccount> accounts = { user1, user2, user3 };
    Similarity similarity(accounts);

    //total foodCount를 instance로 가지는 벡터 생성
    UserAccount totalAccount = UserAccount::calculateTotal(accounts);

    //similarity.calculate_cosine_similarity();
    //similarity.generate_recommendations();

    //similarity.print_recommendations();

    /* 특정 User에 대해서 recommendation을 받을 수 있음
    vector<double> user1_recommendations = similarity.get_recommendations_for_user(user1);
    cout << "User1's Recommendations: ";
    for (double rec : user1_recommendations) {
        cout << rec << " ";
    }
    cout << endl;
    */
    string a = "0000";
    string b = "0000";
    cout << a.compare(b) << endl;
    RecommendationSystem system(foodVector, accounts);
    system.Starting();  
}