#include <vector>
#include <cmath>
#include"parameters.h"
#include <iostream>

/*
 计算并更新两个向量 B_n1 和 B_n2 的值，
 这两个向量是基于输入向量 V 进行计算的
*/

/*
B(z)=z/(exp(z)-1)
B(-z)=exp(z)*B(z)
B_n1[i] = dV[i]/(exp(dV[i])-1.0);
        // 算出来是B(dV[i])
*/

// BernoulliFnc_p(V, B_p1, B_p2);
void BernoulliFnc_n(const std::vector<double> &V, std::vector<double> &B_n1, std::vector<double> &B_n2){  
    //NOTE: this V has the right side bndry condition appended 
    
    std::vector<double> dV(num_cell+1);
    // dV 用于存储输入向量 V 相邻元素之间的差值。

    for(int i = 1; i<=num_cell;i++){
        dV[i] =  V[i]-V[i-1];
    }
    // 循环计算dV中的向量值

    for(int i = 1; i<=num_cell;i++){
        B_n1[i] = dV[i]/(exp(dV[i])-1.0);
        // 算出来是B(dV[i])
        B_n2[i] = B_n1[i]*exp(dV[i]);
        // 算出来是B(-dV[i])
    }
}


void BernoulliFnc_p(const std::vector<double> &V, std::vector<double> &B_p1, std::vector<double> &B_p2){  //NOTE: this V has the right side bndry condition appended
    std::vector<double> dV(num_cell+1);

    for(int i = 1; i<=num_cell;i++){
        dV[i] =  V[i]-V[i-1];
    }

    for(int i = 1; i<=num_cell;i++){
        B_p1[i] = dV[i]/(exp(dV[i])-1.0);
        B_p2[i] = B_p1[i]*exp(dV[i]);
    }
}
