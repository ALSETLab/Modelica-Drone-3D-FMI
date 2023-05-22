within DroneLibrary.Mechanical.Chassis.Templates;
model droneChassis
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape(
    animation=false,
    animateSphere=false,
    r={0,0.25,0},
    r_CM={0,0.175,0},
    m=m,
  useQuaternions=false)
    annotation (Placement(transformation(extent={{-22,34},{-2,54}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape1(
    animation=false,
    animateSphere=false,
    r={0.25,0,0},
    r_CM={0.175,0,0},
    m=m,
  useQuaternions=false)
                      annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={-12,12})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape2(
    animation=false,
    animateSphere=false,
    m=m,
    r={0,-0.25,0},
    r_CM={0,-0.175,0},
  useQuaternions=false)
    annotation (Placement(transformation(extent={{-22,-26},{-2,-6}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape3(
    animation=false,
    animateSphere=false,
    m=m,
    r={-0.25,0,0},
    r_CM={-0.175,0,0},
  useQuaternions=false)
                       annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={-12,-50})));
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
  parameter Modelica.Units.SI.Length length=0.25 "Length of cylinder";
  parameter Modelica.Units.SI.Mass m=1 "Mass of rigid body";
equation
  connect(bodyShape.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,44},{16,44},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape3.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,-50},{16,-50},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape1.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,12},{16,12},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape2.frame_b, bodyCylinder.frame_a) annotation (Line(
      points={{-2,-16},{16,-16},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(pointMass.frame_a, bodyCylinder.frame_b) annotation (Line(
      points={{64,0},{52,0}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a1, bodyShape.frame_a) annotation (Line(
      points={{-100,60},{-62,60},{-62,44},{-22,44}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a, bodyShape1.frame_a) annotation (Line(
      points={{-100,20},{-62,20},{-62,12},{-22,12}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a2, bodyShape2.frame_a) annotation (Line(
      points={{-100,-20},{-62,-20},{-62,-16},{-22,-16}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a3, bodyShape3.frame_a) annotation (Line(
      points={{-100,-60},{-62,-60},{-62,-50},{-22,-50}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyCylinder.frame_a, frame_a4) annotation (Line(
      points={{32,0},{16,0},{16,-76},{0,-76},{0,-100}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-68,26},{70,-26}},
          lineColor={28,108,200},
          textString="droneChassis")}));
end droneChassis;
