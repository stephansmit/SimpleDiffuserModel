
#pragma once

class SimpleDiffuserModel {

protected:
		CFluidModel *StateInlet;
		CFluidModel *StateOutlet;
		CFluidModel *StateIsentropicOutlet;
		su2double VelocityInlet, VelocityOutlet;
		void CalculateOutletState(double A_in,double A_out, double h0_in, double c_in, double P_out);

public:
		SimpleDiffuserModel(void);
		SimpleDiffuserModel(double P_in,
							double rho_in,
							double h0_in,
							double c_in,
							double A_in,
							double A_out,
							double P_out
							);

		su2double GetEnthalpyOut();
		su2double GetDensityOut();
		su2double GetVelocityOut();
		su2double GetPressureOut();

		su2double GetIsentropicEnthalpyOut();
		su2double GetIsentropicDensityOut();
		su2double GetIsentropicPressureOut();

		su2double GetEnthalpyIn();
		su2double GetDensityIn();
		su2double GetVelocityIn();
		su2double GetPressureIn();

		su2double GetEfficiency();

		virtual ~SimpleDiffuserModel(void);

};

SimpleDiffuserModel::SimpleDiffuserModel(double P_in,
										 double rho_in,
										 double h0_in,
										 double c_in,
										 double A_in,
										 double A_out,
										 double P_out
										 ) {
    //toluene constants
    su2double gamma =1.06;
    su2double R=90.23;
    su2double Pstar = 4126300.0;        //critical pressure toluene
    su2double Tstar = 591.75;           //critical temperature toluene
    su2double w = 0.2657;
    StateInlet = new CPengRobinson(gamma, R, Pstar, Tstar, w);
    StateInlet->SetTDState_Prho(P_in, rho_in);
    VelocityInlet = c_in;

	StateIsentropicOutlet = new CPengRobinson(gamma, R, Pstar, Tstar, w);
	StateIsentropicOutlet->SetTDState_Ps(P_out, StateInlet->GetEntropy());

	StateOutlet = new CPengRobinson(gamma, R, Pstar, Tstar, w);
	CalculateOutletState(A_in, A_out, h0_in, c_in, P_out);

}

SimpleDiffuserModel::~SimpleDiffuserModel(void) {

}
