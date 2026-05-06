#include <cstdlib>
#include <vector>
#include <string>

#include "sorts.hpp"
#include "randfiller.h"

using namespace std;

int main()
{
    randfiller rf;

    for (int i = 0; i < 100; i++) {
        vector<int> d(1);
        rf.fill(d, 1, 100);

        int N = d[0];
        vector<int> v(N);
        rf.fill(v, -500, 500);

        selection_sort(v);

        if (!is_sorted(v)) {
            return EXIT_FAILURE;
        }
    }

    vector<string> s = {
        "frutta", "conte", "terrazze", "leone", "fiducia", 
        "nuotare", "danza", "filetto", "bolla", "immagine"
    };
    
    selection_sort(s);
    
    if (!is_sorted(s)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}