#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, double> umap = { {"manh", 1} };

    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

        //    iterating over all value of umap
    unordered_map<string, double>::iterator itr;
    cout << "\nAll Elements : \n";
    for (auto itr = umap.begin(); itr != umap.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stores the value part
        cout << (*itr).first << "  " << (*itr).second << endl;
     }

    cout << "\nOne more time : \n";
        for(auto x: umap)
    {
       cout << x.first << "->" <<
               x.second <<endl;
    } 
}