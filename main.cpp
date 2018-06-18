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
    su2double temperatureOut = Diffuser->GetTemperatureOut();
    su2double velocityOut = Diffuser->GetVelocityOut();


    cout << "Velocity" << "\t" << "Temperature" << "\t" << "Efficiency" << "\n";
    cout << velocityOut<< "\t" << temperatureOut<< "\t" <<  efficiency  << "\n";

    return 0;

}
