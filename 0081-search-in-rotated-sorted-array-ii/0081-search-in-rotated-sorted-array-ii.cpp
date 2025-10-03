class Solution {
public:
    bool search(vector<int>& A, int target) {
        int s=0;
        int e=A.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(A[mid] == target)
            return true;
            if(A[s] == A[mid] && A[mid] == A[e]){
                s++,e--;
                continue;
            }

            if(A[s]<=A[mid]){//left sorted
             if(A[s]<=target && target<=A[mid]){
                e=mid-1;
             }
             else{
                s=mid+1;
             }
            }
            else{//right sorted
             if(A[mid]<=target && target<=A[e]){
                s=mid+1;
             }
             else{
                e=mid-1;
             }
            }

        }
        return false;
    }
};
    