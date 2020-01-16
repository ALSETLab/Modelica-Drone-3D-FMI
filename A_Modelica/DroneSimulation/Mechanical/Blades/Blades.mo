within DroneSimulation.Mechanical.Blades;
model Blades
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape5(
    m=0.010,
    r={-0.154,0,0},
    I_33=0.001,
    useQuaternions=false)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={66,-10})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape4(
    m=0.01,
    r={0.154,0,0},
    I_33=0.001,
    shapeType="cylinder",
    useQuaternions=false)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={66,10})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Input
    "Input from motor connecting the propeller blades to the motor"
    annotation (Placement(transformation(extent={{-120,-16},{-88,16}}),
        iconTransformation(extent={{-120,-16},{-88,16}})));
equation
  connect(bodyShape4.frame_a, Input) annotation (Line(
      points={{66,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end Blades;
