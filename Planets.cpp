#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
/*
 name: Tejo sai venkata kali prasad kandula ,
 college: Andhra University college of Engineering ,
 year of passing: 2022 ECE B.Tech ,
 phone number: 9182453544 
 email : kaliprasad4035@gmail.com


*/
class Planet 
{
    
    string name;
    vector<string> surface_gasses;
    int moon_count;
    bool have_rings;
    public:
    Planet(string name,vector<string> surface_gasses,int moon_count,bool have_rings)
    {
        this->name=name;
        this->surface_gasses=surface_gasses;
        this->moon_count=moon_count;
        this->have_rings=have_rings;
    }
    int get_moons()
    {
        return moon_count;
    }
    bool check_rings()
    {
        return have_rings;
    }
    vector<string> get_gases()
    {
        return surface_gasses;
    }
    
};
int count_moonsOfPlanetsWithRings(vector<Planet*> planets)
{
    int ans=0;
    for(auto planett:planets)
    {
        if(planett->check_rings())
        {
            ans+=planett->get_moons();
        }
    }
    return ans;
}
string find_the_gas(vector<Planet*> planets)
{
    map<string,int> gas_map;
    int maxi=INT_MIN;
    string ans;
    for(auto planett:planets)
    {
        auto gasses=planett->get_gases();
        for(auto gas:gasses)
        {
            gas_map[gas]++;
            if(maxi<gas_map[gas])
            {
                maxi=gas_map[gas];
                ans=gas;
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> planet_names
    ={"Mercury","Venus","Earth","Jupitor","Saturn","Uranus"};
    vector<vector<string>> gases
    ={  {},
        {"Carbon Dioxide", "Nitrogen"},
        {"Nitrogen", "Oxygen"},
        {"Hydrogen","Helium"},
        {"Hydrogen", "Helium"},
        {"Hydrogen", "Helium", "Methane"}
    };
    vector<bool> rings={
        false,
        false,
        false,
        true,
        true,
        true
        
    };
    vector<int> moons={
        0,
        0,
        1,
        79,
        83,
        27
    };
    vector<Planet*> planets;
    for(int i=0;i<planet_names.size();i++)
    {
        Planet* p=new Planet(planet_names[i],gases[i],moons[i],rings[i]);
        planets.push_back(p);
        
    }
    cout<<"No. of moons of all the palnets with rings:";
    cout<<count_moonsOfPlanetsWithRings(planets)<<endl;
    cout<<"Gas found on most of the planets: ";
    cout<<find_the_gas(planets)<<endl;
    
}