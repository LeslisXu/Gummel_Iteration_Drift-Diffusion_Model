#include <vector>
#include <iostream>
#include <iomanip>
#include "parameters.h"
#include <fstream>
#include <algorithm>

//Generation rate file should contain num_cell -2 number of entries in a single column, 
// corresponding to
//the the generation rate at each mesh point (except the endpoints).
// 生成率文件应在单列中包含 num_cell -2 个条目，对应于每个网格点（端点除外）的生成率。

std::vector<double> PhotogenerationRate(){

    std::vector<double> G(num_cell);

    std::ifstream GenRateFile;
    // 声明一个名为 GenRateFile 的输入文件流对象，
    // 用于读取存储光生率信息的文件。

    std::string filePath = "D:\\USTC——科学计算研究\\Numerical_Iteration\\Gummel_Initial\\Drift-Diffusion_models-Cpp_Matlab-master\\Drift-Diffusion_models-Cpp_Matlab-master\\1D\\Multi-Layer_Devices\\Perovskite_solar_cell\\gen_rate.txt";

     GenRateFile.open(filePath);
     //check if file was opened
     if (!GenRateFile) {
         std::cerr << "Unable to open file gen_rate.txt";
         exit(1);   // call system to stop
         // 检查文件是否成功打开，如果没有成功，则输出错误信息并退出程序。
     }

     for(int i=1;i<=num_cell-1;i++){
         GenRateFile >> G[i];
         //std::cout << "G(i) " << G[i] <<std::endl;
     }
     // 通过循环从文件中读取光生率信息，并将其存储在向量 G 中。


     double maxOfG = *std::max_element(G.begin(),G.end());
     // 计算向量 G 中的最大值，存储在 maxOfG 中。


     for(int i= 1;i<=num_cell-1;i++){
         G[i] = G_max*G[i]/maxOfG;
         //std::cout << "G(i) " << G[i] <<std::endl;
         
         // 通过循环对读取的光生率进行归一化，
         // 将其缩放到 [0, G_max] 的范围内。
         GenRateFile.close();
     }
     


     //Using constant generation rate
     //std::fill(G.begin(), G.end(), G_max);


     return G;
}
