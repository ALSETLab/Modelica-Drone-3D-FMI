within DroneLibrary.Mechanical.Rotor.Templates;
partial model rotor

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force
    "Coordinate system fixed to the joint with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-118,-78},{-86,-46}}),
      iconTransformation(extent={{-118,-78},{-86,-46}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Blade
    annotation (Placement(transformation(extent={{86,-56},{118,-24}})));
Modelica.Mechanics.MultiBody.Interfaces.Frame_a torque_1
    "Coordinate system a fixed to the component with one cut-force and cut-torque"
  annotation (Placement(transformation(extent={{-118,44},{-86,76}}),
      iconTransformation(extent={{-118,44},{-86,76}})));
Modelica.Mechanics.MultiBody.Interfaces.Frame_b torque_2
    "Coordinate system b fixed to the component with one cut-force and cut-torque"
  annotation (Placement(transformation(extent={{-118,-16},{-86,16}}),
      iconTransformation(extent={{-118,-16},{-86,16}})));
  parameter Real k=-1 "Gain value multiplied with input signal";
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}));
end rotor;
