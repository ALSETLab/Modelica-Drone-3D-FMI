within DroneSimulation.Electrical.Machines;
model SimpleDCmotor
  type motorK = Real(quantity = "Torque constant", unit = "Nm/A", min=0);
  type aeroFriction = Real(quantity = "Propeller friction", unit = "Nms", min=0);
  type propellerK = Real(quantity = "Propeller constant", unit = "Ns", min=0);

  parameter Modelica.SIunits.Inertia Jp = 0.002 "Propeller inertia";
  parameter motorK Kt = 2 "Motor current to torque constant";
  parameter aeroFriction bp = 0.004 "Propeller friction force";
  parameter propellerK Ke= 0.004 "Propeller constant";

  Modelica.SIunits.Torque tout "Output torque";
  Modelica.SIunits.Force fout "Output force";
  Modelica.SIunits.AngularVelocity w "Angular speed of motor";
  Modelica.SIunits.Voltage V "machine voltage";
  Modelica.SIunits.Power p "Machine power";
  Modelica.Blocks.Interfaces.RealInput current
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}})));
  Modelica.Blocks.Interfaces.RealOutput torque
    annotation (Placement(transformation(extent={{100,30},{120,50}})));
  Modelica.Blocks.Interfaces.RealOutput force
    annotation (Placement(transformation(extent={{100,-50},{120,-30}})));
equation
  tout=Kt*current;
  Jp*der(w)= tout-bp*w;
  fout=w*Ke;
  force = fout;
  torque = tout;
  V = (tout*Ke*w);
  p = current*V;
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
        Text(
          extent={{60,46},{100,20}},
          lineColor={28,108,200},
          textString="Lift

"),     Text(
          extent={{64,-34},{96,-50}},
          lineColor={28,108,200},
          textString="T"),
        Text(
          extent={{-62,28},{74,-20}},
          lineColor={28,108,200},
          textString="motor")}),                                 Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end SimpleDCmotor;
