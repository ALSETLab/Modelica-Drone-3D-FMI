within DroneLibrary.Mechanical.Chassis.Examples;
model droneChassis_Visualization
  import Visualization;
  extends DroneLibrary.Mechanical.Chassis.Templates.droneChassis;
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
  Visualization.Shapes.FileShape shape(
    r_shape={0,0,0},
    lengthDirection(displayUnit="1") = {1,0,0},
    filename="modelica://DroneLibrary/Resources/Images/9.stl",
    scaleFactor={1.025e-3,1.025e-3,1.025e-3})
             annotation (Placement(transformation(extent={{88,-68},{108,-48}})));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation fixedRotation2(
    animation=false,
    r={-0.27,0,-0.2},
    angle=90) annotation (Placement(transformation(extent={{30,-68},{50,-48}})));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation fixedRotation3(
    animation=false,
    n(displayUnit="1") = {0,1,0},
    angle=45) annotation (Placement(transformation(extent={{58,-68},{78,-48}})));
equation
  connect(pointMass.frame_a, bodyCylinder.frame_b) annotation (Line(
      points={{64,0},{52,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyCylinder.frame_a, frame_a4) annotation (Line(
      points={{32,0},{16,0},{16,-76},{0,-76},{0,-100}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedRotation2.frame_a, bodyCylinder.frame_a) annotation (Line(
      points={{30,-58},{16,-58},{16,0},{32,0}},
      color={95,95,95},
      thickness=0.5));
  connect(fixedRotation2.frame_b, fixedRotation3.frame_a) annotation (Line(
      points={{50,-58},{58,-58}},
      color={95,95,95},
      thickness=0.5));
  connect(shape.frame_a, fixedRotation3.frame_b) annotation (Line(
      points={{88,-58},{78,-58}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-68,26},{70,-26}},
          lineColor={28,108,200},
          textString="droneChassis")}));
end droneChassis_Visualization;
