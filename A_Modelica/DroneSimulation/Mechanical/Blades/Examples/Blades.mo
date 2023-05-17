within DroneSimulation.Mechanical.Blades.Examples;
model Blades
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape5(
    animation=false,
    animateSphere=false,
    m=0.010,
    r={-0.154,0,0},
    I_33=0.001,
    useQuaternions=false)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={66,-10})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape4(
    animation=false,
    animateSphere=false,
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
  Modelica.Mechanics.MultiBody.Visualizers.FixedShape fixedShape(
    animation=animation,
    shapeType="modelica://DroneSimulation/Resources/Images/8.stl",
    r_shape={-0.0085,-0.1,0},
    lengthDirection(displayUnit="1") = {0,0,-1},
    length=1e-3,
    width=1e-3,
    height=1e-3,
    extra=1) annotation (Placement(transformation(extent={{-18,12},{2,32}})));
  parameter Boolean animation=true "= true, if animation shall be enabled";
equation
  connect(bodyShape4.frame_a, Input) annotation (Line(
      points={{66,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedShape.frame_a, Input) annotation (Line(
      points={{-18,22},{-30,22},{-30,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));

end Blades;
