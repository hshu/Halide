#ifndef MLVAL_H
#define MLVAL_H

#include <memory>

using std::shared_ptr;

// Opaque ocaml type
struct _MLValue;
class MLVal {
public:
    shared_ptr<_MLValue> val;
    static MLVal find(const char *name);
    MLVal() {};
    MLVal(int x);
    MLVal(const char *str);
    MLVal operator()();
    MLVal operator()(MLVal x);
    MLVal operator()(MLVal x, MLVal y);
    MLVal operator()(MLVal x, MLVal y, MLVal z);
};

// Macro to help dig out functions
#define ML_FUNC0(n)                                            \
    MLVal n() {                                                \
        static MLVal callback;                                 \
        if (!callback.val) callback = MLVal::find(#n);         \
        return callback();                                     \
    }

#define ML_FUNC1(n)                                            \
    MLVal n(MLVal x) {                                         \
        static MLVal callback;                                 \
        if (!callback.val) callback = MLVal::find(#n);         \
        return callback(x);                                    \
    }

#define ML_FUNC2(n)                                            \
    MLVal n(MLVal x, MLVal y) {                                \
        static MLVal callback;                                 \
        if (!callback.val) callback = MLVal::find(#n);         \
        return callback(x, y);                                 \
    }

#define ML_FUNC3(n)                                            \
    MLVal n(MLVal x, MLVal y, MLVal z) {                       \
        static MLVal callback;                                 \
        if (!callback.val) callback = MLVal::find(#n);         \
        return callback(x, y, z);                              \
    }

#endif
