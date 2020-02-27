within DroneSimulation.Mechanical.Chassis;
model droneChassis
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape(
    animation=false,
    r={0,0.25,0},
    r_CM={0,0.175,0},
    m=m,
  useQuaternions=false)
    annotation (Placement(transformation(extent={{-22,36},{-2,56}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape1(
    animation=false,
    r={0.25,0,0},
    r_CM={0.175,0,0},
    m=m,
  useQuaternions=false)
                      annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-12,14})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape2(
    animation=false,
    m=m,
    r={0,-0.25,0},
    r_CM={0,-0.175,0},
  useQuaternions=false)
    annotation (Placement(transformation(extent={{-22,-24},{-2,-4}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape3(
    animation=false,
    m=m,
    r={-0.25,0,0},
    r_CM={-0.175,0,0},
  useQuaternions=false)
                       annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-12,-48})));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder bodyCylinder(
    animation=false,
    density=0,
    r_shape={0,0,0},
    diameter=0.01,
    r={0,0,-length},
    length=length,
  useQuaternions=false)
    annotation (Placement(transformation(extent={{32,-10},{52,10}})));
  Modelica.Mechanics.MultiBody.Parts.PointMass pointMass(
    animation=false,
    m=m,
      sphereColor={255,0,255})
    annotation (Placement(transformation(extent={{54,-10},{74,10}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{-116,4},{-84,36}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1
    annotation (Placement(transformation(extent={{-116,44},{-84,76}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a2
    annotation (Placement(transformation(extent={{-116,-36},{-84,-4}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a3
    annotation (Placement(transformation(extent={{-116,-76},{-84,-44}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a4
    annotation (Placement(transformation(extent={{-16,-16},{16,16}},
        rotation=90,
        origin={0,-100})));
  parameter Modelica.SIunits.Length length=0.25 "Length of cylinder";
  parameter Modelica.SIunits.Mass m=1 "Mass of rigid body";
  Modelica.Mechanics.MultiBody.Visualizers.FixedShape fixedShape(
    shapeType="modelica://DroneSimulation/Images/9.stl",
    r_shape={0,0,0},
    lengthDirection(displayUnit="1") = {1,0,0},
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
    n(displayUnit="1") = {0,1,0},
    angle=45) annotation (Placement(transformation(extent={{58,20},{78,40}})));
equation
  connect(bodyShape.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,46},{16,46},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape3.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,-48},{16,-48},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape1.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,14},{16,14},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape2.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,-14},{16,-14},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(pointMass.frame_a, bodyCylinder.frame_b) annotation (Line(
      points={{64,0},{52,0}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a1, bodyShape.frame_a) annotation (Line(
      points={{-100,60},{-62,60},{-62,46},{-22,46}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a, bodyShape1.frame_a) annotation (Line(
      points={{-100,20},{-62,20},{-62,14},{-22,14}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a2, bodyShape2.frame_a) annotation (Line(
      points={{-100,-20},{-62,-20},{-62,-14},{-22,-14}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a3, bodyShape3.frame_a) annotation (Line(
      points={{-100,-60},{-62,-60},{-62,-48},{-22,-48}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyCylinder.frame_a, frame_a4) annotation (Line(
      points={{32,0},{16,0},{16,-76},{0,-76},{0,-100}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedRotation.frame_a, bodyCylinder.frame_a) annotation (Line(
      points={{30,30},{16,30},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedRotation.frame_b, fixedRotation1.frame_a) annotation (Line(
      points={{50,30},{58,30}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedShape.frame_a, fixedRotation1.frame_b) annotation (Line(
      points={{88,30},{78,30}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-68,26},{70,-26}},
          lineColor={28,108,200},
          textString="droneChassis")}), Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end droneChassis;
