within DroneLibrary.Electrical.Machines;
model SimpleDCmotor
  type Drag = Real (final unit="N.m.s2");
  type Thrust = Real (final unit="N.s2");
  parameter Modelica.Units.SI.Inertia Jp=0.002 "Propeller inertia";
  parameter Modelica.Units.SI.ElectricalTorqueConstant Kt = 2 "Motor current to torque constant";
  parameter Drag bp = 2e-2 "Drag constant";
  parameter Modelica.Units.SI.Area A=1 "Cross section of vehicle";
  parameter Modelica.Units.SI.Density rho=1 "Density of air";
  parameter Thrust Ke= 0.0015 "Lift constant";

  Modelica.Units.SI.Torque tout "Output torque";
  Modelica.Units.SI.Force fout "Output force";
  Modelica.Units.SI.AngularVelocity w "Angular speed of motor";
  Modelica.Units.SI.Power p "Machine power";
  Modelica.Blocks.Interfaces.RealInput current
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}})));
  Modelica.Blocks.Interfaces.RealOutput torque
    annotation (Placement(transformation(extent={{100,30},{120,50}})));
  Modelica.Blocks.Interfaces.RealOutput force
    annotation (Placement(transformation(extent={{100,-50},{120,-30}})));
equation
  tout=Kt*current;
  Jp*der(w)= tout-bp*(w^2);
  fout=Ke*(w^2);
  force = fout;
  torque = tout;
  p = tout*w;
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
        Text(
          extent={{60,46},{100,20}},
          lineColor={28,108,200},
          textString="Lift

"), Text( extent={{64,-34},{96,-50}},
          lineColor={28,108,200},
          textString="T"),
        Text(
          extent={{-62,28},{74,-20}},
          lineColor={28,108,200},
          textString="motor")}),
    Documentation(info="<html>
<p>This is a simple representation of a motor that is only dependent on current. All losses are neglected from the motor.</p>
</html>"));
end SimpleDCmotor;
