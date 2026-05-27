#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "grad_coniugato.hpp"
using namespace std;

double condA(const Eigen::MatrixXd& A) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    Eigen::VectorXd singularValuesA = svd.singularValues();
    return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main() {
    const double tol = 1.0e-15;
    const unsigned int n = 4;

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (abs(B.determinant()) < tol) {
        return -1;
    }

    Eigen::MatrixXd A = B.transpose() * B;            
    Eigen::VectorXd x_es = Eigen::VectorXd::Ones(n);  
    Eigen::VectorXd b = A * x_es;                     
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    const unsigned int ite_max = 10000;
    const double res_tol = 1.0e-12;

    unsigned int ite = 0;

    Eigen::VectorXd x = conjugate_gradient(A, b, x0, res_tol, ite_max, ite);

    Eigen::VectorXd residuo = b - A * x;


    double err_rel = (x_es.norm() == 0.0) ? (x - x_es).norm() :
                                            (x - x_es).norm() / x_es.norm();

    cout.precision(4);

    cout << "Condizionamento di A: " << condA(A) << "\n"
    << "Iterazioni effettuate: " << scientific << ite << "/" << ite_max << "\n"
    << "Norma del residuo finale: " << scientific << residuo.norm() << "\n"
    << "Errore relativo: " << scientific << err_rel << "\n\n";
    
    cout << "Soluzione calcolata:\n" << scientific << x << "\n\n";

    cout << "Soluzione esatta:\n" << scientific << x_es << "\n\n";

    if (err_rel < 1.0e-8) {
        cout << "Test superato." << "\n";
    } else {
        cout << "Test fallito." << "\n";
    }
    return 0;
}