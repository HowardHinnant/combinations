#include "combinations"
#include <iostream>
#include <vector>
#include <numeric>

template <class It>
unsigned
display(It begin, It end)
{
    unsigned r = 0;
    if (begin != end)
    {
        std::cout << *begin;
        ++r;
        for (++begin; begin != end; ++begin)
        {
            std::cout << ", " << *begin;
            ++r;
        }
    }
    return r;
}

// functor called for each permutation
class f
{
    unsigned len;
    std::uint64_t count;
public:
    explicit f(unsigned l) : len(l), count(0) {}

    template <class It>
        bool operator()(It first, It last)  // called for each permutation
        {
            // count the number of times this is called
            ++count;
            // print out [first, mid) surrounded with [ ... ]
            std::cout << "[ ";
            unsigned r = display(first, last);
            // If [mid, last) is not empty, then print it out too
            //     prefixed by " | "
            if (r < len)
            {
                std::cout << " | ";
                display(last, std::next(last, len - r));
            }
            std::cout << " ]\n";
            return false;  // Don't break out of the loop
        }

    operator std::uint64_t() const {return count;}
};
struct F
{
    unsigned long long count_;

    F() : count_(0) {}

    bool operator()(std::vector<int>::iterator, std::vector<int>::iterator)
  {++count_; return false;}
}; 

int main() {

    unsigned i = 1;
    int n = 33;
    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 0); 
    f a(v.size());
  a = for_each_combination(v.begin(), v.end()+i, v.end(), a);
  //F f;
  //  f = for_each_combination(v.begin(), v.end()+i, v.end(), f);
//  GenerationFormer g(state, new_game);
  //  g = for_each_combination(hand().begin(), hand().begin()+i, hand().end(), g);
}

