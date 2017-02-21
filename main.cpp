// O(nlog(n)) solution
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <iterator>
// #include <unordered_map>
// #include <functional>
// #include <numeric>

// namespace std {
//     template<>
//     struct less<std::vector<int>> {
//         bool operator()(const std::vector<int> & v1, const std::vector<int> & v2) {
//             if (v1.size() != v2.size())
//                 return v1.size() < v2.size();
//             else
//                 return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
//         }
//     };
// }

// namespace std {
//     template<>
//     struct hash<std::vector<int>> {
//         size_t operator()(const std::vector<int> & v) const {
//             return std::accumulate(v.begin(), v.end(), 0, std::bit_xor<size_t>());
//         }
//     };
// }

// class solution {
//   private:
//     std::unordered_map<std::vector<int>,int> dict;
    
//   public:
//     int maxProfit(const std::vector<int> & prices) {
//         int profit;
//         if (dict.find(prices) == dict.end()) {
//             if (prices.size() < 2) {
//                 profit = 0;
//             }
//             else if (prices.size() == 2) {
//                 profit = prices[1]>=prices[0]?prices[1]-prices[0]:0;
//             }
//             else {
//                 std::vector<int> cands;
//                 for (size_t i = 1; i < prices.size()-1; i++) {
//                     std::vector<int> left(prices.begin(), prices.begin()+i), right(prices.begin()+i, prices.end());
//                     int left_max = maxProfit(left), right_max = maxProfit(right);
//                     int cross_max = *std::max_element(right.begin(), right.end())-*std::min_element(left.begin(),left.end());
//                     cands.push_back(std::max({left_max, cross_max, right_max}));
//                 }
//                 if (!cands.empty())
//                     profit = *std::max_element(cands.begin(), cands.end());
//                 else
//                     profit = 0;
//             }
//             std::copy(prices.begin(), prices.end(), std::ostream_iterator<int>(std::cout, " "));
//             std::cout << "-> ";
//             std::cout << profit << std::endl;
//             dict[prices] = profit;
//         }
//         else
//             profit = dict[prices];
//         return profit;
//     }
// };

// solution O(n)
#include <iostream>
#include <vector>
#include <limits>

class solution {
  public:
    int maxProfit(const std::vector<int> & prices) {
        int maxPfit = 0, minPrice = std::numeric_limits<int>::max();
        // std::cout << "maxprofit = " << maxPfit << ", minprice = " << minPrice << std::endl;
        for (int p : prices) {
            std::cout << "current price = " << p << ": maxprofit = " << maxPfit << ", minprice = " << minPrice << std::endl;
            maxPfit = std::max(maxPfit, p-minPrice);
            minPrice = std::min(minPrice, p);
        }
        return maxPfit;
    }
};

int main() {
    std::vector<int> prices{7,1,5,3,6,4};
    // std::vector<int> prices{7,6,4,3,1};
    
    solution soln;
    int mprofit = soln.maxProfit(prices);
    std::cout << "The maximum profit = "
              << mprofit << std::endl;
}
