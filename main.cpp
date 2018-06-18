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
#include "include/simple_diffuser_model.hpp"
#include "src/simple_diffuser_model.cpp"
#include <iomanip>
#include "include/configuration.h"


configuration::data readConfigurationFile(string filename){
	configuration::data configdata;
	ifstream f( filename.c_str() );
	f >> configdata;
	f.close();
	return configdata;
}

void writeOutputFile(string filename, SimpleDiffuserModel* SimpleDiffuserModel){
	ofstream f;
	f.open (filename.c_str());
	f << "H_IN"    << ": " << SimpleDiffuserModel->GetEnthalpyIn() 	 << '\n';
	f << "A_IN"    << ": " << SimpleDiffuserModel->GetAreaIn() 		 << '\n';
	f << "RHO_IN"  << ": " << SimpleDiffuserModel->GetDensityIn()	 << '\n';
	f << "P_IN"    << ": " << SimpleDiffuserModel->GetPressureIn() 	 << '\n';
	f << "C_IN"    << ": " << SimpleDiffuserModel->GetVelocityIn() 	 << '\n';
	f << "T_IN"    << ": " << SimpleDiffuserModel->GetTemperatureIn()<< '\n';
	f << "H_OUT"   << ": " << SimpleDiffuserModel->GetEnthalpyOut()  << '\n';
	f << "A_OUT"   << ": " << SimpleDiffuserModel->GetAreaOut() 	 << '\n';
	f << "RHO_OUT" << ": " << SimpleDiffuserModel->GetDensityOut()	 << '\n';
	f << "P_OUT"   << ": " << SimpleDiffuserModel->GetPressureOut()  << '\n';
	f << "C_OUT"   << ": " << SimpleDiffuserModel->GetVelocityOut()  << '\n';
	f << "T_OUT"   << ": " << SimpleDiffuserModel->GetTemperatureOut()<< '\n';
	f << "EFFICIENCY" <<": " <<  SimpleDiffuserModel->GetEfficiency() << "\n";
	f.close();
}

int main()

{
	configuration::data configData = readConfigurationFile("diffuser.cfg");

	double P_in  =configData.getDoubleValue("P_IN");
    double rho_in=configData.getDoubleValue("RHO_IN");
    double h0_in =configData.getDoubleValue("H0_IN");
    double c_in  =configData.getDoubleValue("C_IN");
    double A_in  =configData.getDoubleValue("A_IN");
    double A_out =configData.getDoubleValue("A_OUT");
    double P_out =configData.getDoubleValue("P_OUT");
    string outputFilename = configData.getStringValue("OUTPUT_FILENAME");


    SimpleDiffuserModel* Diffuser = new  SimpleDiffuserModel(P_in,
											rho_in,
											h0_in,
											c_in,
											A_in,
											A_out,
											P_out
											);

    writeOutputFile(outputFilename, Diffuser);

    return 0;

}
