within DroneLibrary.Mechanical.Chassis.Variants;
model droneChassis
  extends DroneLibrary.Mechanical.Chassis.Templates.droneChassis;

  Modelica.Mechanics.MultiBody.Visualizers.FixedShape fixedShape(
    animation=animation,
    shapeType="modelica://DroneLibrary/Resources/Images/9.stl",
    r_shape={0,0,0},
    lengthDirection = {1,0,0},
    length=1.025e-3,
    width=1.025e-3,
    height=1.025e-3,
    extra=1) annotation (Placement(transformation(extent={{88,20},{108,40}})));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation fixedRotation(
    animation=false,
    r={-0.27,0,-0.2},
    angle=90) annotation (Placement(transformation(extent={{30,20},{50,40}})));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation fixedRotation1(
    animation=false,
    n = {0,1,0},
    angle=45) annotation (Placement(transformation(extent={{58,20},{78,40}})));
  parameter Boolean animation=true "= true, if animation shall be enabled";
equation
  connect(fixedRotation.frame_b,fixedRotation1. frame_a) annotation (Line(
      points={{50,30},{58,30}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedShape.frame_a,fixedRotation1. frame_b) annotation (Line(
      points={{88,30},{78,30}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedRotation.frame_a, bodyCylinder.frame_a) annotation (Line(
      points={{30,30},{16,30},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
end droneChassis;
