#pragma once
#include <iostream>
#include <concepts>

template<typename I> requires std::integral<I>
class rational
{
    I num_;
    I den_;
    
    void simplify()
    {
        if (num_ == 0 && den_ == 0) {             // gestisco il caso 0/0
            return;
        }

        if (den_ < 0) {                           // semplifico i segni
            num_ = -num_;
            den_ = -den_;
        }

        I a = 0;                                  // calcolo MCD
        I b = 0;

        if (num_ < 0) {                                // trovo i valori assoluti
            a = -num_;
        } else {
            a = num_;
        }

        if (den_ < 0) {
            b = -den_;
        } else {
            b = den_;
        }

        while (b != 0) {                              // implemento l'algoritmo di Euclide per il MCD
            I resto = a % b;                          
            a = b;
            b = resto;
        }                                            // MCD = a
        
        num_ /= a;                                   // il caso b = 0 lascerà comunque a come MCD (ok)
        den_ /= a;
    }

public:
    /* Costruttore di default */
    rational()
        : num_(0), den_(1)
    {}

    /* Costruttore user-defined */
    rational(const I& n, const I& d)
        : num_(n), den_(d)
    {
        simplify();
    }

    /* Restituiscono i valori di numeratore e denominatore */
    I num() const { return num_; }
    I den() const { return den_; }

    /* Gestione casi particolari */
    bool is_nan() const {                             // indeterminata 0/0
        return (num_ == 0 && den_ == 0);
    }

    bool is_pos_inf() const {                         // infinito positivo
        return (num_ > 0 && den_ == 0);
    }

    bool is_neg_inf() const {                         // infinito negativo
        return (num_ < 0 && den_ == 0);
    }

    /* Implementazione += */
    rational& operator+=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {           // almeno un Nan
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() && other.is_neg_inf()) || (is_neg_inf() && other.is_pos_inf())) {        // Inf + (-Inf) oppure - Inf + Inf
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() && other.is_pos_inf()) || (is_neg_inf() && other.is_neg_inf())) {         // Inf + Inf oppure -Inf + (-Inf)     
            return *this;
        }

        if (is_pos_inf() || is_neg_inf()) {              // +-Inf + numero finito
            return *this;
        }

        if (other.is_pos_inf() || other.is_neg_inf()) {         // numero finito + (+-Inf)
            num_ = other.num();
            den_ = other.den();
            return *this;
        }

        num_ = num_*other.den() + other.num()*den_;        // numero finito + numero finito
        den_ = den_*other.den();
        simplify();
        return *this;
    }

    /* Implementazione somma */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    /* Implementazione -= */
    rational& operator-=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {           // almeno un Nan
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() && other.is_pos_inf()) || (is_neg_inf() && other.is_neg_inf())) {        // Inf - Inf oppure -Inf - (-Inf)
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() && other.is_neg_inf()) || (is_neg_inf() && other.is_pos_inf())) {         // Inf - (-Inf) oppure -Inf - Inf     
            return *this;
        }

        if (is_pos_inf() || is_neg_inf()) {              // +-Inf - numero finito
            return *this;
        }

        if (other.is_pos_inf() || other.is_neg_inf()) {         // numero finito - (+-Inf)
            num_ = -other.num();
            den_ = other.den();
            return *this;
        }

        num_ = num_*other.den() - other.num()*den_;        // numero finito - numero finito
        den_ = den_*other.den();
        simplify();
        return *this;
    }

    /* Implementazione differenza */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    /* Implementazione *= */
    rational& operator*=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {           // almeno un Nan
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((num_ == 0 && den_ != 0) && (other.is_pos_inf() || other.is_neg_inf())) {            // 0 * (+-Inf)
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() || is_neg_inf()) && (other.num() == 0 && other.den() != 0)) {          // +-Inf * 0
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (is_pos_inf()) {                 // primo fattore è Inf
            if (other.num() > 0) {                // secondo fattore positivo
                num_ = 1;
                den_ = 0;
            } else {                              // secondo fattore negativo
                num_ = -1;
                den_ = 0;
            }
            return *this;
        }

        if (is_neg_inf()) {                 // primo fattore è -Inf
            if (other.num() > 0) {                 // secondo fattore positivo
                num_ = -1;
                den_ = 0;
            } else {                               // secondo fattore negativo
                num_ = 1;
                den_ = 0;
            }
            return *this;
        }

        if (other.is_pos_inf()) {           // secondo fattore è Inf
            if (num_ > 0) {                        // primo fattore positivo
                num_ = 1;
                den_ = 0;
            } else {                               // primo fattore negativo
                num_ = -1;
                den_ = 0;
            }
            return *this;
        }

        if (other.is_neg_inf()) {           // secondo fattore è -Inf
            if (num_ > 0) {                        // primo fattore positivo
                num_ = -1;
                den_ = 0;
            } else {                               // primo fattore negativo
                num_ = 1;
                den_ = 0;
            }
            return *this;
        }

        num_ = num_*other.num();
        den_ = den_*other.den();
        simplify();
        return *this;
    }

    /* Implementazione prodotto */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    /* Implementazione /= */
    rational& operator/=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {           // almeno un NaN
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_pos_inf() || is_neg_inf()) &&
            (other.is_pos_inf() || other.is_neg_inf())) {             // +-Inf/(+-Inf)
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (other.is_pos_inf() || other.is_neg_inf()) {               // finito/(+-Inf)
            num_ = 0;
            den_ = 1;
            return *this;
        }

        if (is_pos_inf()) {                            // dividendo Inf
            if (other.num() >= 0) {                           // divisore positivo o zero                
                num_ = 1;
                den_ = 0;
            } else {                                          // divisore negativo
                num_ = -1;
                den_ = 0;
            }
            return *this;
        }

        if (is_neg_inf()) {                            // dividendo -Inf
            if (other.num() >= 0) {                           // divisore positivo o zero
                num_ = -1;
                den_ = 0;
            } else {                                          // divisore negativo
                num_ = 1;
                den_ = 0;
            }
            return *this;
        }

        if (other.num() == 0 && other.den() != 0) {        // divisore zero
            if (num_ == 0) {                                      // dividendo zero
                num_ = 0;
                den_ = 0;
            } else if (num_ > 0) {                                // dividendo positivo
                num_ = 1;
                den_ = 0;
            } else {                                              // dividendo negativo
                num_ = -1;
                den_ = 0;
            }
            return *this;
        }

        num_ = num_*other.den();
        den_ = den_*other.num();
        simplify();
        return *this;
    }

    /* Implementazione quoziente */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.is_nan()) {
        os << "NaN";
        return os;
    }

    if (r.is_pos_inf()) {
        os << "Inf";
        return os;
    }

    if (r.is_neg_inf()) {
        os << "-Inf";
        return os;
    }

    if (r.den() == 1) {
        os << r.num();
        return os;
    }

    os << r.num() << "/" << r.den();
    return os;
}