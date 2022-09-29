within DroneSimulation.Electrical.Machines;
model SimpleDCmotor
  type motorK = Real(quantity = "Torque constant", unit = "Nm/A", min=0);
  type aeroFriction = Real(quantity = "Propeller friction", unit = "Nms", min=0);
  type propellerK = Real(quantity = "Propeller constant", unit = "Ns", min=0);

  parameter Modelica.Units.SI.Inertia Jp=0.002 "Propeller inertia";
  parameter motorK Kt = 2 "Motor current to torque constant";
  parameter aeroFriction bp = 3.5e-2 "Propeller friction force";
  parameter propellerK Ke= 0.0015 "Propeller constant";

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

"),     Text(
          extent={{64,-34},{96,-50}},
          lineColor={28,108,200},
          textString="T"),
        Text(
          extent={{-62,28},{74,-20}},
          lineColor={28,108,200},
          textString="motor")}),                                 Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    Documentation(info="<html>
<p>This is a simple representation of a motor that is only dependent on current. All losses are neglected from the motor.</p>
</html>"));
end SimpleDCmotor;
