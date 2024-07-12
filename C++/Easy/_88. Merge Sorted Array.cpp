#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {   // Some Modefiy
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){nums2=nums1;}
        for(int i=nums1.size()-1; i>=0; i--){   // Remove Zeros
            if(nums1[i]==0) nums1.pop_back();
        }
        
        for(int j=0; j<nums1.size(); j++){   // Insert All nums1 in nums2
            nums2.push_back(nums1[j]);
        }

        // OR Use sort(nums2.begin(),nums2.end(), greater<int>());
        // sort(nums1.begin(), nums1.end());
        int Max=0;
        for(int c=0; c<nums2.size(); c++){    // Ascending order vector nums2
            for(int b=0; b<c; b++){
                if(nums2[b]>nums2[c]){
                    Max=nums2[b];
                    nums2[b]=nums2[c];
                    nums2[c]=Max;

                } 
            }
        }



        // Correct
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());

        



        // Correct
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};