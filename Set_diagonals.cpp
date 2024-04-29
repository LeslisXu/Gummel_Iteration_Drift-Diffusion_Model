#include <iostream>
#include <vector>
#include "parameters.h"

//---------------Setup AV diagonals (Poisson solve)---------------------------------------------------------------
//this is a in tridiag_solver
/*
设置一个主对角线向量 main_diag，
其元素值与输入向量 epsilon 中的元素相关。
*/
// 输入向量 epsilon，包含了某种物理量（可能是介电常数）的信息。
// 输出向量 main_diag，用于存储设置后的主对角线元素。
void set_main_AVdiag(const std::vector<double> &epsilon, std::vector<double> &main_diag){
    int num_elements = main_diag.size() - 1; //num_elements corresponds to the particular diagonal. -1 b/c we don't use the 0th element.
    //  计算 main_diag 的元素数量

    for (int i=1; i<= num_elements;i++){
        main_diag[i] = -2.*epsilon[i];
    }
   

}

//this is b in tridiag_solver
void set_upper_AVdiag(const std::vector<double> &epsilon, std::vector<double> &upper_diag){
    int num_elements = upper_diag.size() -1;  //-1 since vectors fill from 0, but I'm indexing from 1
    //NOTE: num_elements here, is actually # of elements in the off-diagonal
    
    for (int i = 1; i<=num_elements; i++){
        upper_diag[i] = epsilon[i];
    }
 
}

//this is c in tridiag_solver
void set_lower_AVdiag(const std::vector<double> &epsilon, std::vector<double> &lower_diag){
    int num_elements = lower_diag.size() -1;
    
    for (int i = 1; i<=num_elements; i++){
        lower_diag[i] = epsilon[i];
    }
    std::cout << "Size of lower_diag of AV: " << lower_diag.size() << std::endl;


}

//-------------------------------Setup An diagonals (Continuity/drift-diffusion solve)-----------------------------
void set_main_An_diag(const std::vector<double> &n_mob,const  std::vector<double> &B_n1,const  std::vector<double> &B_n2, std::vector<double> &main_diag){
    int num_elements = main_diag.size() - 1;

    for (int i=1; i<= num_elements;i++){
        main_diag[i] = -(n_mob[i]*B_n1[i] + n_mob[i+1]*B_n2[i+1]);
    }
  
}

//this is b in tridiag_solver
void set_upper_An_diag(const std::vector<double> &n_mob,const  std::vector<double> &B_n1, std::vector<double> &upper_diag){
    int num_elements = upper_diag.size() -1;  //-1 since vectors fill from 0, but I'm indexing from 1
    //NOTE: num_elements here, is actually # of elements in the off-diagonal

    for (int i = 1; i<=num_elements; i++){
        upper_diag[i] = n_mob[i+1]*B_n1[i+1];
    }
   
}

//this is c in tridiag_solver
void set_lower_An_diag(const std::vector<double> &n_mob,const  std::vector<double> &B_n2, std::vector<double> &lower_diag){
    int num_elements = lower_diag.size() -1;

    for (int i = 1; i<=num_elements; i++){
        lower_diag[i] = n_mob[i+1]*B_n2[i+1];
    }
   
}

//------------------------------Setup Ap diagonals----------------------------------------------------------------
//set_main_Ap_diag(p_mob, B_p1, B_p2, a);
void set_main_Ap_diag(const std::vector<double> &p_mob,const  std::vector<double> &B_p1, const std::vector<double> &B_p2, std::vector<double> &main_diag){
    int num_elements = main_diag.size() - 1;

    for (int i=1; i<= num_elements;i++){
        main_diag[i] = -(p_mob[i]*B_p2[i] + p_mob[i+1]*B_p1[i+1]);
    }
    

}

//this is b in tridiag_solver
//set_upper_Ap_diag(p_mob, B_p2, b);
void set_upper_Ap_diag(const std::vector<double> &p_mob,const  std::vector<double> &B_p2, std::vector<double> &upper_diag){
    int num_elements = upper_diag.size() -1;  //-1 since vectors fill from 0, but I'm indexing from 1
    //NOTE: num_elements here, is actually # of elements in the off-diagonal

    for (int i = 1; i<=num_elements; i++){
        upper_diag[i] = p_mob[i+1]*B_p2[i+1];
    }
    //std::cout << "Size of upper_diag of Ap: " << upper_diag.size() << std::endl;
    /*std::cout << "upper_diag matrix:" << std::endl;
    for (int i = 0; i < upper_diag.size(); ++i) {
        std::cout << upper_diag[i] << " ";
    }
    std::cout << std::endl;*/

}

//this is c in tridiag_solver 
//set_lower_Ap_diag(p_mob, B_p1, c);
void set_lower_Ap_diag(const std::vector<double> &p_mob,const  std::vector<double> &B_p1, std::vector<double> &lower_diag){
    int num_elements = lower_diag.size() -1;

    for (int i = 1; i<=num_elements; i++){
        lower_diag[i] = p_mob[i+1]*B_p1[i+1];
    }
   // std::cout << "Size of lower_diag of Ap: " << lower_diag.size() << std::endl;
   /* std::cout << "lower_diag matrix:" << std::endl;
    for (int i = 0; i < lower_diag.size(); ++i) {
        std::cout << lower_diag[i] << " ";
    }
    std::cout << std::endl;*/

}




