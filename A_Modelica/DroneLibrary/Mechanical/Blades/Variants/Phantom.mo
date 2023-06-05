within DroneLibrary.Mechanical.Blades.Variants;
model Phantom

  extends DroneLibrary.Mechanical.Blades.Templates.Blades(bodyShape4(
      m=0.010,
      r={-0.2,0,0},
      I_33=0.001), bodyShape5(
      m=0.01,
      r={0.2,0,0},
      I_33=0.001));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Input
    "Input from motor connecting the propeller blades to the motor"
    annotation (Placement(transformation(extent={{-120,-16},{-88,16}}),
        iconTransformation(extent={{-120,-16},{-88,16}})));
equation
  connect(bodyShape4.frame_a, Input) annotation (Line(
      points={{66,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));

end Phantom;
