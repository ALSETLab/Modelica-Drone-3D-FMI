within DroneSimulation.Sensors;
model TorqueSensor
  "Ideal sensor to measure the torque between two flanges (= flange_a.tau)"

  extends Modelica.Icons.RoundSensor;
  Modelica.Blocks.Interfaces.RealOutput tau(unit="N.m")
    "Torque in flange flange_a and flange_b (tau = flange_a.tau = -flange_b.tau) as output signal"
    annotation (Placement(transformation(
        origin={-80,-110},
        extent={{10,-10},{-10,10}},
        rotation=90)));

  Modelica.Mechanics.Rotational.Interfaces.Flange_a flange_a
    annotation (Placement(transformation(extent={{-110,-10},{-90,10}})));
equation
  flange_a.tau = tau;
  annotation (
    Documentation(info="<html>
<p>
Measures the <strong>cut-torque between two flanges</strong> in an ideal way
and provides the result as output signal <strong>tau</strong>
(to be further processed with blocks of the Modelica.Blocks library).
</p>
</html>"),
       Icon(
    coordinateSystem(preserveAspectRatio=true,
      extent={{-100.0,-100.0},{100.0,100.0}}),
      graphics={
    Text(extent={{-50.0,-120.0},{50.0,-80.0}},
      textString="tau"),
    Line(points={{-80,-100},{-80,0}},
      color={0,0,127}),
    Line(points={{-70,0},{-102,0}},
      color={0,0,127})}));
end TorqueSensor;
