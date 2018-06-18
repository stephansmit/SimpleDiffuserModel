#include "simple_diffuser_model.hpp"

void SimpleDiffuserModel::CalculateOutletState(double A_in,double A_out, double h0_in, double c_in, double P_out){
	su2double c4o, c4n;
	double res, delta;
	su2double rho_out, h_out;
	c4o=0.1;	//initial guess
	delta=1e-6; //step size
	res = 1e10;	//residual
	while (res > 1e-8){
		rho_out = StateInlet->GetDensity()*A_in*c_in/(A_out*c4o);	//Continuity
		StateOutlet->SetTDState_Prho((su2double) P_out,rho_out);	//EOS
		h_out = StateOutlet->GetStaticEnergy()+P_out/rho_out;
		c4n = pow(2*(h0_in-h_out), 0.5);							//Adiabatic
		c4o = c4o +0.000001*(c4n-c4o);
		res = fabs(c4o-c4n);
	}
	VelocityOutlet=c4n;
}

su2double SimpleDiffuserModel::GetEnthalpyIn() {
	return StateInlet->GetStaticEnergy()
			+StateInlet->GetPressure()/StateInlet->GetDensity();
}
su2double SimpleDiffuserModel::GetDensityIn(){
	return StateInlet->GetPressure();
}
su2double SimpleDiffuserModel::GetVelocityIn(){
	return VelocityInlet;
}
su2double SimpleDiffuserModel::GetPressureIn(){
	return StateInlet->GetPressure();
}


su2double SimpleDiffuserModel::GetIsentropicEnthalpyOut() {
	return StateIsentropicOutlet->GetStaticEnergy()
			+StateIsentropicOutlet->GetPressure()/StateIsentropicOutlet->GetDensity();
}
su2double SimpleDiffuserModel::GetIsentropicDensityOut(){
	return StateIsentropicOutlet->GetDensity();
}
su2double SimpleDiffuserModel::GetIsentropicPressureOut(){
	return StateIsentropicOutlet->GetPressure();
}


su2double SimpleDiffuserModel::GetEnthalpyOut() {
	return StateOutlet->GetStaticEnergy()
			+StateOutlet->GetPressure()/StateOutlet->GetDensity();
}
su2double SimpleDiffuserModel::GetDensityOut(){
	return StateOutlet->GetDensity();
}
su2double SimpleDiffuserModel::GetVelocityOut(){
	return VelocityOutlet;
}
su2double SimpleDiffuserModel::GetPressureOut(){
	return StateOutlet->GetPressure();
}


su2double SimpleDiffuserModel::GetEfficiency(){
	return (GetIsentropicEnthalpyOut()-GetEnthalpyIn())/(GetEnthalpyOut()-GetEnthalpyIn());
}
