class Solution {
public:
bool canEatAll(vector<int>& piles, int mid, int h){
    int actualHours = 0;
    for(int &x : piles){
        actualHours +=x/mid;
        if(x%mid != 0){
            actualHours++;
        }
    }
    return actualHours <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int n=piles.size();
        int e=*max_element(begin(piles),end(piles));

        while(s<e){
            int mid=s+(e-s)/2;

            if(canEatAll(piles,mid,h)){
                e=mid;
            }
            else{
                s=mid+1 ;
            }
        }
     return s;
    }
};