#pragma once

#include <Eigen/Dense>

Eigen::VectorXd conjugate_gradient(
    const Eigen::MatrixXd& A,        
    const Eigen::VectorXd& b,        
    const Eigen::VectorXd& x0,       
    const double res_tol,           
    const unsigned int ite_max,
    unsigned int& ite) {

    Eigen::VectorXd x = x0;
    Eigen::VectorXd res = b - A * x;  
    Eigen::VectorXd p = res;         

    const double res0_norm_ = res.norm();                          
    ite = 0;
    while (ite < ite_max && res.norm() > res_tol * res0_norm_) {
        Eigen::VectorXd Ap = A * p;                              
        const double alpha_k = p.dot(res) / p.dot(Ap);            

        x = x + alpha_k * p;                                    
        Eigen::VectorXd res_new = b - A * x;                     
        const double beta_k = p.dot(A * res_new) / p.dot(Ap);    
        p = res_new - beta_k * p;                                
        res = res_new;
        ite = ite + 1;
    }
    return x;
}