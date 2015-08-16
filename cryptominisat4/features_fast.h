#ifndef __FEATURES_FAST_H__
#define __FEATURES_FAST_H__

#include <vector>
#include <limits>
#include "features.h"
using std::vector;

namespace CMSat {

class Solver;

struct FeatureExtract {
public:
    FeatureExtract(const Solver* _solver) :
        solver(_solver) {
    }
    Features extract();
    void print_stats() const;

private:
    void fill_vars_cls();
    void calculate_clause_stats();
    void calculate_variable_stats();
    void calculate_extra_var_stats();
    void calculate_extra_clause_stats();


    const Solver* solver;
    template<class Function, class Function2>
    void for_one_clause(
        const Watched& cl
        , const Lit lit
        ,  Function func
        ,  Function2 func_each_lit
    ) const;
    template<class Function, class Function2>
    void for_all_clauses(Function for_each_clause,  Function2 func_each_lit) const;
    struct VARIABLE {
        int numPos = 0;
        int size = 0;
        int horn = 0;
    };

    vector<VARIABLE> myVars;
    int clause_id = 0;
    Features feat;
};

} //end namespace

#endif //__FEATURES_FAST_H__