class ProductOfNumbers {
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        int n = nums.size();
        
        for(int i = n-k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};