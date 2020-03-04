within DroneSimulation.Mechanical.Chassis;
model Phantom_droneChassis
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape(r={0,0.2,0})
    annotation (Placement(transformation(extent={{-36,40},{-16,60}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape1(r={0.2,0,0})
                      annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-26,16})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape2(r={0,-0.2,0})
    annotation (Placement(transformation(extent={{-22,-24},{-2,-4}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape3(r={-0.2,0,0})
                       annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-12,-48})));
  Modelica.Mechanics.MultiBody.Parts.BodyBox      bodyBox(
    width=0.11,
    height=0.05,
    density=0,
    r_shape={0,0,0},
    r={0.05,0.001,-length},
    length=0.01)
    annotation (Placement(transformation(extent={{32,-8},{52,12}})));
  Modelica.Mechanics.MultiBody.Parts.PointMass pointMass(
    m=0.680,
      sphereColor={255,0,255},
    r_0(start={length/2,W/2,H/2}))
    annotation (Placement(transformation(extent={{62,-8},{82,12}})));
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
  parameter Modelica.SIunits.Length length=0.168
                                                "Length of cylinder";
  parameter Modelica.SIunits.Length W=0.083;
   parameter Modelica.SIunits.Length H=0.049;
  parameter Modelica.SIunits.Mass m=1 "Mass of rigid body";
equation
  connect(bodyShape.frame_b, bodyBox.frame_a) annotation (Line(
      points={{-16,50},{16,50},{16,2},{32,2}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape3.frame_b, bodyBox.frame_a) annotation (Line(
      points={{-2,-48},{16,-48},{16,2},{32,2}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape1.frame_b, bodyBox.frame_a) annotation (Line(
      points={{-16,16},{16,16},{16,2},{32,2}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape2.frame_b, bodyBox.frame_a) annotation (Line(
      points={{-2,-14},{16,-14},{16,2},{32,2}},
      color={95,95,95},
      thickness=0.5));
  connect(pointMass.frame_a, bodyBox.frame_b) annotation (Line(
      points={{72,2},{52,2}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a1, bodyShape.frame_a) annotation (Line(
      points={{-100,60},{-62,60},{-62,50},{-36,50}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a, bodyShape1.frame_a) annotation (Line(
      points={{-100,20},{-62,20},{-62,16},{-36,16}},
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
  connect(bodyBox.frame_a, frame_a4) annotation (Line(
      points={{32,2},{16,2},{16,-76},{0,-76},{0,-100}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-68,26},{70,-26}},
          lineColor={28,108,200},
          textString="droneChassis")}), Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end Phantom_droneChassis;
