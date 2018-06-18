#include <iostream>
#include <fstream>
using namespace std;
#include "../SU2-fork/Common/include/mpi_structure.hpp"
#include "../SU2-fork/SU2_CFD/include/fluid_model.hpp"
#include "../SU2-fork/SU2_CFD/src/fluid_model_pig.cpp"
#include "../SU2-fork/SU2_CFD/src/fluid_model_ppr.cpp"
#include "../SU2-fork/SU2_CFD/src/fluid_model_pvdw.cpp"
#include "../SU2-fork/SU2_CFD/src/fluid_model.cpp"
#include "../SU2-fork/SU2_CFD/src/transport_model.cpp"
#include "../SU2-fork/SU2_CFD/include/transport_model.hpp"
#include "../SU2-fork/SU2_CFD/src/transport_model_toluene.cpp"
#include "simple_diffuser_model.hpp"
#include "simple_diffuser_model.cpp"
#include <iomanip>







int main() 
{
    su2double rho3, rho4;
    su2double A3, A4;
    su2double  c3, c4;
    su2double h03, h04;
    su2double P3,P4;
    su2double h3, h4, h4s;
    su2double s3, s4;
    su2double T3, T4;


    double P_in=11493.864797;
    double rho_in=0.307649;
    double h0_in=718624.090088;
    double c_in=302.969728;
    double A_in=368.64698860465114;
    double A_out=10000;
    double P_out=0.2e5;

    SimpleDiffuserModel* Diffuser = new  SimpleDiffuserModel(P_in,
											rho_in,
											h0_in,
											c_in,
											A_in,
											A_out,
											P_out
											);
    su2double efficiency = Diffuser->GetEfficiency();
    cout << efficiency << "\n";

//    s4 = FluidModelPR_4->GetEntropy();
//    T4 = FluidModelPR_4->GetTemperature();
//
//    cout.precision(5);
//    cout    << setw(20) << "s4"
//        	<< setw(20) << "s3"
//        	<< setw(20) << "c4"
//        	<< setw(20) << "c3"
//        	<< setw(20) << "T4"
//        	<< setw(20) << "T3"
//        	<< setw(20) << "P4"
//        	<< setw(20) << "P3"
//
//        	<< "\n";
//
//    cout    << setw(20) << s4
//    		<< setw(20) << s3
//    		<< setw(20) << c4
//    		<< setw(20) << c3
//    		<< setw(20) << T4
//    		<< setw(20) << T3
//    		<< setw(20) << P4
//    		<< setw(20) << P3
//    		<< "\n";
//
//    su2double efficiency = (h4s-h3)/(h4-h3);
//    cout << "Isentropic efficiency diffuser: " << efficiency << "\n";
    return 0;

}
