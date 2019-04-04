// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     vector<int> vec;
//     for(int i = 0;i<10;i++)
//     {
//         int tmp;
//         cin>>tmp;
//         vec.push_back(tmp);
//     }
//     int Asize;
//     cin>>Asize;
//     int Bsize;
//     cin>>Bsize;
//     if(vec[0] >= Asize||vec[0] >= Bsize) 
//     {
//         cout<<0<<endl;
//         return 0;
//     }
//     int tmpa = Asize;
//     int tmpb = Bsize;
//     int sumMin = 0;
//     int sumMax = 0;
//     //找最小的
//     int tmpMin, tmpMax;
//     tmpMin = min(Asize, Bsize);
//     tmpMax = max(Asize, Bsize);
//     //先用最小值把短的填满
//     for(int i = 0;i< 10;i++)
//     {
//         while(vec[i] && (tmpMin > 0 || tmpMax > 0))
//         {
//             if(vec[i] && tmpMin > 0){
//                 vec[i]--;
//                 sumMin = sumMin*10 + i;
//                 tmpMin--;
//             }
//             if(vec[i] && tmpMax > 0){
//                 vec[i]--;
//                 sumMax = sumMax*10 + i;
//                 tmpMax--;
//             }
//         }
//     }
//     // for(int i = 0;i<10;i++)
//     // {
//     //     if(tmpMax==0) break;
//     //     while(vec[i])
//     //     {
//     //         vec[i]--;
//     //         sumMax = sumMax*10 + i;
//     //         tmpMax--;
//     //         if(tmpMax==0) break;
//     //     }
        
//     // }
//     cout<<sumMin*sumMax<<endl;
//     return 0;
// }


#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 0;i<10;i++)
    {
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    int Asize;
    cin>>Asize;
    int Bsize;
    cin>>Bsize;
    if(vec[0] >= Asize||vec[0] >= Bsize) 
    {
        cout<<"0"<<endl;
        return 0;
    }
    int tmpa = Asize;
    int tmpb = Bsize;
    int sumMin = 0;
    int sumMax = 0;
    //找最小的
    int tmpMin, tmpMax;
    tmpMin = min(Asize, Bsize);
    tmpMax = max(Asize, Bsize);
    //先用最小值把短的填满
    for(int i = 0;i<10;i++)
    {
        if(tmpMin==0) break;
        while(vec[i])
        {
            vec[i]--;
            sumMin = sumMin*10 + i;
            tmpMin--;
            if(tmpMin==0) break;
        }
        
    }
    for(int i = 0;i<10;i++)
    {
        if(tmpMax==0) break;
        while(vec[i])
        {
            vec[i]--;
            sumMax = sumMax*10 + i;
            tmpMax--;
            if(tmpMax==0) break;
        }
        
    }
    cout<<sumMin*sumMax<<endl;
    return 0;
}






