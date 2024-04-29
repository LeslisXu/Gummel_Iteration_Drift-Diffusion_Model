#include <vector>
#include <iostream>
#include <iomanip>
#include "parameters.h"
#include <fstream>
#include <algorithm>

//Generation rate file should contain num_cell -2 number of entries in a single column, 
// corresponding to
//the the generation rate at each mesh point (except the endpoints).
// �������ļ�Ӧ�ڵ����а��� num_cell -2 ����Ŀ����Ӧ��ÿ������㣨�˵���⣩�������ʡ�

std::vector<double> PhotogenerationRate(){

    std::vector<double> G(num_cell);

    std::ifstream GenRateFile;
    // ����һ����Ϊ GenRateFile �������ļ�������
    // ���ڶ�ȡ�洢��������Ϣ���ļ���

    std::string filePath = "D:\\USTC������ѧ�����о�\\Numerical_Iteration\\Gummel_Initial\\Drift-Diffusion_models-Cpp_Matlab-master\\Drift-Diffusion_models-Cpp_Matlab-master\\1D\\Multi-Layer_Devices\\Perovskite_solar_cell\\gen_rate.txt";

     GenRateFile.open(filePath);
     //check if file was opened
     if (!GenRateFile) {
         std::cerr << "Unable to open file gen_rate.txt";
         exit(1);   // call system to stop
         // ����ļ��Ƿ�ɹ��򿪣����û�гɹ��������������Ϣ���˳�����
     }

     for(int i=1;i<=num_cell-1;i++){
         GenRateFile >> G[i];
         //std::cout << "G(i) " << G[i] <<std::endl;
     }
     // ͨ��ѭ�����ļ��ж�ȡ��������Ϣ��������洢������ G �С�


     double maxOfG = *std::max_element(G.begin(),G.end());
     // �������� G �е����ֵ���洢�� maxOfG �С�


     for(int i= 1;i<=num_cell-1;i++){
         G[i] = G_max*G[i]/maxOfG;
         //std::cout << "G(i) " << G[i] <<std::endl;
         
         // ͨ��ѭ���Զ�ȡ�Ĺ����ʽ��й�һ����
         // �������ŵ� [0, G_max] �ķ�Χ�ڡ�
         GenRateFile.close();
     }
     


     //Using constant generation rate
     //std::fill(G.begin(), G.end(), G_max);


     return G;
}
