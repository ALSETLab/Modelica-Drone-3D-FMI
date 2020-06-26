within DroneSimulation.Mechanical.Rotor.Examples;
model rotor3
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute(animation=false)
    annotation (Placement(transformation(extent={{10,14},{30,34}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{12,36},{32,56}})));

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
  Modelica.Blocks.Sources.RealExpression realExpression(y=-3.5e-6*(
        relativeAngularVelocity.w_rel[3])^2)
    annotation (Placement(transformation(extent={{-92,-86},{-72,-66}})));
  Blocks.Routing.RealExtend realExtend1 annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-18,-76})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=0.0015*(
        relativeAngularVelocity.w_rel[3]))
    annotation (Placement(transformation(extent={{-92,-102},{-72,-82}})));
  Blocks.Routing.RealExtend realExtend2 annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-52,-92})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque
    annotation (Placement(transformation(extent={{14,-30},{34,-50}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force2
    annotation (Placement(transformation(extent={{-30,-102},{-10,-82}})));
  Modelica.Blocks.Math.Gain gain(k=k)
    annotation (Placement(transformation(extent={{-52,-80},{-44,-72}})));
  parameter Real k "Gain value multiplied with input signal";
equation
  connect(torque_2, Blade) annotation (Line(
      points={{-102,0},{64,0},{64,-40},{102,-40}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_a, revolute.frame_a) annotation (Line(
      points={{12,46},{6,46},{6,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, revolute.frame_b) annotation (Line(
      points={{32,46},{42,46},{42,24},{30,24}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_b, Blade) annotation (Line(
      points={{30,24},{64,24},{64,-40},{102,-40}},
      color={95,95,95},
      thickness=0.5));
  connect(Airframe, revolute.frame_a) annotation (Line(
      points={{102,52},{54,52},{54,72},{6,72},{6,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, revolute.frame_a) annotation (Line(
      points={{-102,60},{-48,60},{-48,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(force, revolute.frame_a) annotation (Line(
      points={{-102,-62},{-48,-62},{-48,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(realExpression1.y, realExtend2.u)
    annotation (Line(points={{-71,-92},{-59.2,-92}}, color={0,0,127}));
  connect(realExtend2.y, force2.force)
    annotation (Line(points={{-45.4,-92},{-32,-92}}, color={0,0,127}));
  connect(force2.frame_b, revolute.frame_a) annotation (Line(
      points={{-10,-92},{6,-92},{6,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{-11.4,-76},{12,-76},{12,-40}}, color={0,0,127}));
  connect(torque.frame_b, Blade) annotation (Line(
      points={{34,-40},{102,-40}},
      color={95,95,95},
      thickness=0.5));
  connect(realExpression.y, gain.u)
    annotation (Line(points={{-71,-76},{-52.8,-76}}, color={0,0,127}));
  connect(gain.y, realExtend1.u)
    annotation (Line(points={{-43.6,-76},{-25.2,-76}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end rotor3;
