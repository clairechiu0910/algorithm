#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int sLength, tmp;
        cin>>sLength;

        vector<int> num, weight;
        for(int i=0; i<sLength; i++){
            cin>>tmp;
            num.push_back(tmp);
        }
        for(int i=0; i<sLength; i++){
            cin>>tmp;
            weight.push_back(tmp);
        }

        map<int, int> container;
        map<int, int>::iterator lowIt;
        container[0]=0;
        for(int i=0; i<sLength; i++){
            bool judge=true;
            lowIt=container.lower_bound(num[i]);  //lowIt->first >= num[i]
            lowIt--;
            pair<int, int> newItem(num[i], weight[i] + lowIt->second);
            lowIt++;
            while(lowIt!=container.end()){
                if(lowIt->first==num[i] && lowIt->second>=newItem.second){  //lowIt->second(weight) >= weight[i]
                    judge=false;
                    break;
                }
                else if(lowIt->second <= newItem.second){  //lowIt->first > num[i], lowIt->second(weight) <= weight[i]
                    map<int, int>::iterator tmpIt = (++lowIt);
                    lowIt--;
                    container.erase(lowIt);
                    lowIt=tmpIt;
                }
                else
                    break;
            }
            if(judge)
                container.insert(newItem);
        }

        cout<<container.rbegin()->second<<endl;
    }
    return 0;
}
