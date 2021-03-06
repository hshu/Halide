#ifndef IR_OPERATOR_H
#define IR_OPERATOR_H

#include "IR.h"

namespace HalideInternal {

    inline Expr operator+(Expr a, Expr b) {
        return new Add(a, b);
    }
    
    inline Expr operator-(Expr a, Expr b) {
        return new Sub(a, b);
    }
    
    inline Expr operator*(Expr a, Expr b) {
        return new Mul(a, b);
    }
    
    inline Expr operator/(Expr a, Expr b) {
        return new Div(a, b);
    }

    inline Expr operator%(Expr a, Expr b) {
        return new Mod(a, b);
    }

    inline Expr operator>(Expr a, Expr b) {
        return new GT(a, b);
    }

    inline Expr operator<(Expr a, Expr b) {
        return new LT(a, b);
    }

    inline Expr operator<=(Expr a, Expr b) {
        return new LE(a, b);
    }

    inline Expr operator>=(Expr a, Expr b) {
        return new GE(a, b);
    }

    inline Expr operator==(Expr a, Expr b) {
        return new EQ(a, b);
    }

    inline Expr operator!=(Expr a, Expr b) {
        return new NE(a, b);
    }
}


#endif
