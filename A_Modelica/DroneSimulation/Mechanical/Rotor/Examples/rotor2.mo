within DroneSimulation.Mechanical.Rotor.Examples;
model rotor2
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute(animation=false)
    annotation (Placement(transformation(extent={{10,10},{30,30}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{30,74},{50,94}})));
  Modelica.Mechanics.MultiBody.Forces.ForceAndTorque
                                             forceAndTorque(
                                                     animation=false)
    annotation (Placement(transformation(extent={{8,-88},{28,-68}})));
  Modelica.Blocks.Math.Gain gain(k=-1)     annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        rotation=270,
        origin={40,10})));
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
  Modelica.Mechanics.MultiBody.Sensors.CutForce cutForce
    annotation (Placement(transformation(extent={{-60,-52},{-40,-32}})));
equation
  connect(relativeAngularVelocity.w_rel, realExtract.u)
    annotation (Line(points={{40,73},{40,46}}, color={0,0,127}));
  connect(realExtract.y, gain.u)
    annotation (Line(points={{40,33.4},{40,17.2}}, color={0,0,127}));
  connect(gain.y, realExtend2.u)
    annotation (Line(points={{40,3.4},{40,-14.8}},
                                                color={0,0,127}));
  connect(realExtend2.y, forceAndTorque.torque) annotation (Line(points={{40,
          -28.6},{40,-40},{18,-40},{18,-66}}, color={0,0,127}));
  connect(relativeAngularVelocity.frame_a, forceAndTorque.frame_a) annotation (
      Line(
      points={{30,84},{-14,84},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(Airframe, forceAndTorque.frame_a) annotation (Line(
      points={{102,52},{84,52},{84,92},{-14,92},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_b, forceAndTorque.frame_b) annotation (Line(
      points={{30,20},{62,20},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, forceAndTorque.frame_b) annotation (
      Line(
      points={{50,84},{62,84},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, forceAndTorque.frame_b) annotation (Line(
      points={{-102,0},{62,0},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, forceAndTorque.frame_a) annotation (Line(
      points={{-102,60},{-14,60},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, forceAndTorque.frame_a) annotation (Line(
      points={{10,20},{-14,20},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(force, cutForce.frame_a) annotation (Line(
      points={{-102,-62},{-86,-62},{-86,-42},{-60,-42}},
      color={95,95,95},
      thickness=0.5));
  connect(cutForce.frame_b, forceAndTorque.frame_a) annotation (Line(
      points={{-40,-42},{-14,-42},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(forceAndTorque.force, cutForce.force) annotation (Line(points={{10,
          -66},{10,-59},{-58,-59},{-58,-53}}, color={0,0,127}));
  connect(Blade, forceAndTorque.frame_b) annotation (Line(
      points={{102,-40},{62,-40},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end rotor2;
