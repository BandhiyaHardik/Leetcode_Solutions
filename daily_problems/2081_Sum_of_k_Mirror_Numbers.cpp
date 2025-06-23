class Solution {
public:
    
    bool isPalindrome(string baseK) {
        int i = 0;
        int j = baseK.length()-1;

        while(i <= j) {
            if(baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string convertToBaseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string res = "";
        while(num > 0) {
            res += to_string(num%k);
            num /= k;
        }

        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1;

        while(n > 0) {
            int half_length = (L+1)/2;
            
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if(L % 2 == 0) {
                    pal = first_half + second_half;
                } else {
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPalindrome(baseK)) {
                    sum += pal_num;
                    n--;
                    if(n == 0) {
                        break;
                    }
                }
            }

            L++;
        }

        return sum;
    }
};