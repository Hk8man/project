#include "UserCheck.h"

//UserAccount and Account abstract class

const vector<unsigned int>* Account::getFoodCount() const { return &foodCount; }
size_t Account::size() const { return foodCount.size(); }

void Account::push_back_foodCount(unsigned int foodCount) {
    (this->foodCount).push_back(foodCount);
}

void UserAccount::set_ID(const string& ID) { this->ID = ID; }
void UserAccount::set_password(const string& password) { this->password = password; }

string UserAccount::get_ID() const { return this->ID; }
string UserAccount::get_Password() const { return this->password; }

void UserAccount::print_Info() const
{
    cout << "ID: " << this->ID << endl;
    cout << "Password: " << this->password << endl;
    cout << "foodCount : ";
    for (unsigned int num : foodCount) {
        cout << num << " ";
    }
    cout << endl;
}

//Similarity Class

void Similarity::calculate_cosine_similarity() {
    for (size_t i = 0; i < accounts.size(); ++i) {
        for (size_t j = 0; j < accounts.size(); ++j) {
            if (i != j) {
                cos_similarity[i][j] = cosine_similarity(*accounts[i].getFoodCount(), *accounts[j].getFoodCount());
            }
        }
    }
}

void Similarity::generate_recommendations() {
    for (size_t i = 0; i < accounts.size(); ++i) {
        for (size_t k = 0; k < accounts[i].size(); ++k) {
            double sum_similarity = 0.0;
            double sum_weighted_food = 0.0;

            for (size_t j = 0; j < accounts.size(); ++j) {
                if (j != i && k < accounts[j].size()) {
                    sum_similarity += cos_similarity[i][j];
                    sum_weighted_food += cos_similarity[i][j] * accounts[j].getFoodCount()->at(k);
                }
            }

            recommendations[i][k] = (sum_similarity == 0) ? 0 : (sum_weighted_food / sum_similarity);
        }
    }
}

vector<double> Similarity::get_recommendations_for_user(const UserAccount& user) const {
    auto it = find_if(accounts.begin(), accounts.end(), [&user](const UserAccount& acc) {
        return acc.get_ID() == user.get_ID();
        });
    size_t user_index = distance(accounts.begin(), it);

    if (user_index < recommendations.size()) {
        return recommendations[user_index];
    }
    return {};
}

void Similarity::print_recommendations() const {
    cout << "Recommendations:" << endl;
    for (size_t i = 0; i < accounts.size(); ++i) {
        cout << "User " << accounts[i].get_ID() << ": ";
        for (size_t j = 0; j < recommendations[i].size(); ++j) {
            cout << recommendations[i][j] << " ";
        }
        cout << endl;
    }
}