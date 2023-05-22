within DroneLibrary.Mechanical.Blades.Examples;
model Blades_Animation
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Input
    "Input from motor connecting the propeller blades to the motor"
    annotation (Placement(transformation(extent={{-120,-16},{-88,16}}),
        iconTransformation(extent={{-120,-16},{-88,16}})));
  Modelica.Mechanics.MultiBody.Visualizers.FixedShape fixedShape(
    shapeType="modelica://DroneLibrary/Resources/Images/8.stl",
    r_shape={-0.0085,-0.1,0},
    lengthDirection(displayUnit="1") = {0,0,-1},
    length=1e-3,
    width=1e-3,
    height=1e-3,
    extra=1) annotation (Placement(transformation(extent={{-24,-10},{-4,10}})));
equation
  connect(fixedShape.frame_a, Input) annotation (Line(
      points={{-24,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));

end Blades_Animation;
