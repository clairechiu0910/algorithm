#include <bits/stdc++.h>

using namespace std;

vector <unsigned int> record;

int binarySearch(int num)  //找大於num的最小值
{
    int low=0, high=record.size()-1, mid;
    //cout<<"binarySearch: "<<low<<" "<<high<<" "<<record.size()<<endl;
    while(low<=high){
        mid=(low+high)/2;
        //cout<<"mid="<<mid<<" "<<record[mid]<<endl;
        if(record[mid] >= num){
            if(record[mid-1] >= num && mid-1>=0)
                high=mid-1;
            else
                return mid;
        }
        else
            low=mid+1;;
    }
    return record.size();
}

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int sLength;
        cin>>sLength;
        unsigned int seg;
        record.clear();

        for(int i=0; i<sLength; i++){
            cin>>seg;
            int len=record.size();
            int j=binarySearch(seg);  //record[j]>=seg;
            //cout<<"j="<<j<<endl;
            if(j==record.size())
                record.push_back(seg);
            else
                record[j]=seg;

            /*for(int j=0; j<record.size(); j++)
                cout<<record[j]<<" ";
            cout<<endl;*/
        }
        cout<<record.size();
        if(tcase)
            cout<<endl;
    }
    return 0;
}
