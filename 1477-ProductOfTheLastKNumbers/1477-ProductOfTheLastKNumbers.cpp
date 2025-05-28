// Last updated: 5/28/2025, 9:53:19 PM
class ProductOfNumbers {
public:
    ProductOfNumbers() : prefix{1} {}

    void add(int num) {
        if (num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        return k >= prefix.size()
                   ? 0
                   : prefix.back() / prefix[prefix.size() - k - 1];
    }

private:
    vector<int> prefix;
};