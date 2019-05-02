#include "stl.h"

void Permutation::permute(const vector<int>& nums) {
    std::vector<int> temp1(nums);
    sort(temp1.begin(),temp1.end());
    do{
        p.push_back(temp1);
    } while(next_permutation(temp1.begin(),temp1.end()));
}

void Permutation::print() const {
    for(std::vector<std::vector<int> >::const_iterator i=p.begin();i!=p.end();i++){
        for(std::vector<int>::const_iterator j=(*i).begin();j!=(*i).end();j++){
            cout<<*j<<' ';
        }
        cout<<endl;
    }
}

void Intersection::intersect(const vector<int>& nums1, const vector<int>& nums2) {
    std::vector<int> temp1(nums2);
    inter.clear();
    for(std::vector<int>::const_iterator p=nums1.begin();p!=nums1.end();p++){
        std::vector<int>::iterator temp=find(temp1.begin(),temp1.end(),*p);
        if(temp!=temp1.end()){
            inter.push_back(*temp);
            temp1.erase(temp);
        }
    }
}

void Intersection::print() const {
    for(std::vector<int>::const_iterator p=inter.begin();p!=inter.end();p++){
        cout<<*p<<' ';
    }
    cout<<endl;
}
