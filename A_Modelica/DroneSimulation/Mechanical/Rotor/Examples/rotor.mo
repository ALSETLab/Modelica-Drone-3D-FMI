within DroneSimulation.Mechanical.Rotor.Examples;
model rotor
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute(animation=false)
    annotation (Placement(transformation(extent={{4,14},{24,34}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{30,74},{50,94}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque( animation=false)
    annotation (Placement(transformation(extent={{10,-74},{30,-54}})));
  Modelica.Blocks.Math.Gain gain(k=-1)     annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=270,
        origin={40,0})));
  Blocks.Routing.RealExtract realExtract annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=270,
        origin={40,40})));
  Blocks.Routing.RealExtend realExtend2 annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=270,
        origin={40,-22})));

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
  Modelica.Blocks.Sources.RealExpression realExpression(y=3.5e-6*(
        relativeAngularVelocity.w_rel[3])^2)
    annotation (Placement(transformation(extent={{-80,-90},{-60,-70}})));
  Blocks.Routing.RealExtend realExtend1 annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-40,-80})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force1
    annotation (Placement(transformation(extent={{-22,-90},{-2,-70}})));
equation
  connect(relativeAngularVelocity.w_rel, realExtract.u)
    annotation (Line(points={{40,73},{40,46}}, color={0,0,127}));
  connect(realExtend2.y, torque.torque) annotation (Line(points={{40,-28.6},{40,
          -40},{14,-40},{14,-52}}, color={0,0,127}));
  connect(relativeAngularVelocity.frame_a, torque.frame_a) annotation (Line(
      points={{30,84},{-14,84},{-14,-64},{10,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, torque.frame_a) annotation (Line(
      points={{4,24},{-14,24},{-14,-64},{10,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, force) annotation (Line(
      points={{4,24},{-48,24},{-48,-62},{-102,-62}},
      color={95,95,95},
      thickness=0.5));
  connect(Airframe, torque.frame_a) annotation (Line(
      points={{102,52},{84,52},{84,92},{-14,92},{-14,-64},{10,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(Blade, torque.frame_b) annotation (Line(
      points={{102,-40},{62,-40},{62,-64},{30,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_b, torque.frame_b) annotation (Line(
      points={{24,24},{62,24},{62,-64},{30,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, torque.frame_b) annotation (Line(
      points={{50,84},{62,84},{62,-64},{30,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, torque.frame_b) annotation (Line(
      points={{-102,0},{62,0},{62,-64},{30,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, torque.frame_a) annotation (Line(
      points={{-102,60},{-14,60},{-14,-64},{10,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend2.u, gain.y)
    annotation (Line(points={{40,-14.8},{40,-6.6}}, color={0,0,127}));
  connect(realExpression.y, realExtend1.u)
    annotation (Line(points={{-59,-80},{-47.2,-80}}, color={0,0,127}));
  connect(realExtend1.y, force1.force)
    annotation (Line(points={{-33.4,-80},{-24,-80}}, color={0,0,127}));
  connect(force1.frame_b, torque.frame_a) annotation (Line(
      points={{-2,-80},{6,-80},{6,-64},{10,-64}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtract.y, gain.u)
    annotation (Line(points={{40,33.4},{40,7.2}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end rotor;
