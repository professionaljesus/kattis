#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <float.h>
#include <iomanip>
#include <queue>
#include <cmath>


#define debug 1

#if debug

#define print(x) cout << #x << " = " << x << endl;
#define print_pair(x) cout << #x << " = " << x.first << " " << x.second << endl;

#define print_it( var ) \
    cout << #var << " length = " << (var.size()) << ": "; \
for(auto a : var) { \
    cout << a<< ", "; \
} \
cout << endl << flush;

#define print_it_matrix( var ) \
    cout << #var << " length = " << (var.size()) <<  ", " << (var[0].size()) << ": "<< endl; \
for(auto a : var) { \
    for(auto b : a) \
    cout << b << ", "; \
    cout << endl; \
} \
cout << flush;

#define print_it_matrix_pair( var ) \
    cout << #var << " length = " << (var.size()) <<  ", " << (var[0].size()) << ": " << endl; \
for(auto a : var) { \
    for(auto b : a) \
    cout << "(" << b.first << " " << b.second << "), "; \
    cout << endl; \
} \
cout << flush;


#define print_it_pair( var ) \
    cout << #var << " length = " << (var.size()) << ": "; \
for(auto a : var) { \
    cout << a.first << " " << a.second << ", "; \
} \
cout << endl << flush;

#else 

#define print(x)
#define print_pair(x)
#define print_it( var )
#define print_it_matrix( var )
#define print_it_matrix_pair( var )
#define print_it_pair( var ) 

#endif

#define INT_MAX 2147483647
using namespace std;

float dist(pair<float,float> a, pair<float,float> b){
    return sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2)); 
}

int main(){

    int scenario = 0;
    int n, m;
    float x,y;
    while(true) {

        cin >> m;

        if(m == 0) break; 

        scenario++;
        vector<pair<float,float>> robots;    

        vector<pair<float,float>> holes;    
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            robots.emplace_back(x,y);
        }

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            holes.emplace_back(x,y);
        }
        cout << "Scenario " << scenario << endl;
        float mdist[] = {200.0, 100.0, 50.0};
        vector<int> ans(3, 0);
        for(int s = 0; s < 3; s++){
            vector<bool> safe(m, false);
            for(int i = 0; i < n; i++){
                priority_queue<pair<float, int>> robot_dists;

                for(int j = 0; j < m; j++){
                    if(!safe[j])
                        robot_dists.emplace(dist(holes[i], robots[j]), j);
                }

                pair<float, int> dist;
                while(!robot_dists.empty()){
                    dist = robot_dists.top();
                    if(dist.first <= mdist[s]){
                        safe[dist.second] = true;
                        ans[s]++;
                        break;
                    }
                    robot_dists.pop();

                    
                }
                
            } 
        }


        for(int s = 2; s >= 0; s--){
            cout << "In " << mdist[s]/10 << " seconds " << ans[s] << " robot(s) can escape" << endl;
        }
        cout << endl;
        
    }


    return 0;
}
