/*
* AUTHOR: ASHWIN ABRAHAM
*/

//say there were p moves where 2 coins were removed from left and 1 coin was removed from the right and q moves where the opposite happened
//Both can be emptied if and only if a = 2p+q and b = p+2q for some non-negative integers p and q
//solving these equations we get p = (2a-b)/3 and q = (2b-a)/3
//So if 2a-b and 2b-a are both divisible by 3, then emptying both piles is possible, otherwise, it is not
//Actually if 2a-b is a multiple of 3 then 2b-a is also a multiple of 3 and vice versa (because their difference is 3a-3b which is always a multiple of 3)
//So checking only one of these conditions is sufficient
int coin_piles(int a, int b){
    if((2*a-b)%3==0){return 1;}
    return 0;
}
