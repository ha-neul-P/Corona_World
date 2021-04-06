#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct c_info
{
    string m_name = " ";
    int m_infection = 0;
    int m_death = 0;;
    double m_death_rate = 0;
}C_INFO;


class Corona_World
{
public:
    Corona_World() {};
    //Corona_World(const C_INFO& input);
    //Corona_World(const vector<C_INFO>& input_list);

    ~Corona_World() {};

    bool insert_data(const C_INFO& input);
    bool delete_data(string name);

    friend bool cmp_name(const C_INFO& a, const C_INFO& b);
    friend bool cmp_infection(const C_INFO& a, const C_INFO& b);
    friend bool cmp_death(const C_INFO& a, const C_INFO& b);
    friend bool cmp_death_rate(const C_INFO& a, const C_INFO& b);

    void print_info(int option); // option : 1.이름순, 2.감염자순, 3. 사망자순, 4. 사망률순
private:
    vector<C_INFO> m_data;

};

bool Corona_World::insert_data(const C_INFO& input)
{
    m_data.push_back(input);
    return true;
}

bool Corona_World::delete_data(string name)
{
    for (int i = 0; i < m_data.size(); i++)
    {
        if (m_data[i].m_name == name)
        {
            m_data.erase(m_data.begin() + i);
            return true;
        }
    }
    return false;
}

bool cmp_name(const C_INFO& a, const C_INFO& b) {
    return a.m_name < b.m_name;
}
bool cmp_infection(const C_INFO& a, const C_INFO& b) {
    return a.m_infection < b.m_infection;
}
bool cmp_death(const C_INFO& a, const C_INFO& b) {
    return a.m_death < b.m_death;
}
bool cmp_death_rate(const C_INFO& a, const C_INFO& b) {
    return a.m_death_rate < b.m_death_rate;
}

void Corona_World::print_info(int option) {
    switch (option) {
    case 1:
        sort(m_data.begin(), m_data.end(), cmp_name);
        break;
    case 2:
        sort(m_data.begin(), m_data.end(), cmp_infection);
        break;
    case 3:
        sort(m_data.begin(), m_data.end(), cmp_death);
        break;
    case 4:
        sort(m_data.begin(), m_data.end(), cmp_death_rate);
        break;
    }
   
    cout << "\n\n";

    for (int i=0; i < m_data.size(); i++)
    {
        cout << i+1<<". "<< m_data[i].m_name <<"  " <<m_data[i].m_infection << "  " <<
            m_data[i].m_death << "  " << m_data[i].m_death_rate << endl;
    }
    
}
    

int main()
{
    Corona_World corona_info;
    C_INFO x;
    x.m_name = "Korea";
    x.m_infection = 1111;
    x.m_death = 101;
    string nation;


    int option = 0;
    int option2 = 0;
    
    while (1)
    {
        vector<C_INFO> info;
        cout << "\n\n1. 국가정보 추가\n" << "2. 국가정보 제거\n"
            << "3. 국가정보 출력\n" << "4. 종료\n" <<endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "국가명 발병자수 사망자수 순서로 입력하시오." << endl;
            cin >> x.m_name >> x.m_infection >> x.m_death;
            x.m_death_rate = (double)x.m_death / (double)x.m_infection;
            corona_info.insert_data(x);
            break;

        case 2:
            cout << "삭제할 국가명을 적어주십시오." << endl;
            cin >> nation;
            corona_info.delete_data(nation);
            break;

        case 3:
            cout << "출력 방식을 선택하시오.\n" << "1.국가명순, 2.감염자순, 3. 사망자순, 4. 사망률순" << endl;
            cin >> option2;
            corona_info.print_info(option2);
            break;
        case 4:
            break;

        }

        if (option == 4)
            break;
        
    }


    return 0;

}