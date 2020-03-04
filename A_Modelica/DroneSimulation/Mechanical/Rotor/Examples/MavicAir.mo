within DroneSimulation.Mechanical.Rotor.Examples;
model MavicAir
  Modelica.Mechanics.MultiBody.Forces.Torque torque(resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.frame_a)
    annotation (Placement(transformation(extent={{4,12},{24,32}})));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute
    annotation (Placement(transformation(extent={{4,-10},{24,10}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{30,74},{50,94}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque1
    annotation (Placement(transformation(extent={{8,-88},{28,-68}})));
  Modelica.Blocks.Math.Gain gain(k=-0.004) annotation (Placement(
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
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force
    "Coordinate system fixed to the joint with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-118,-16},{-86,16}})));
  Modelica.Blocks.Interfaces.RealInput torque2[3]
    "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame"
    annotation (Placement(transformation(extent={{-140,40},{-100,80}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Blade
    annotation (Placement(transformation(extent={{86,-56},{118,-24}})));
equation
  connect(relativeAngularVelocity.w_rel, realExtract.u)
    annotation (Line(points={{40,73},{40,46}}, color={0,0,127}));
  connect(realExtract.y, gain.u)
    annotation (Line(points={{40,33.4},{40,17.2}}, color={0,0,127}));
  connect(gain.y, realExtend2.u)
    annotation (Line(points={{40,3.4},{40,-14.8}},
                                                color={0,0,127}));
  connect(realExtend2.y, torque1.torque) annotation (Line(points={{40,-28.6},
          {40,-40},{12,-40},{12,-66}},
                              color={0,0,127}));
  connect(relativeAngularVelocity.frame_a, torque1.frame_a) annotation (
      Line(
      points={{30,84},{-14,84},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, torque1.frame_a) annotation (Line(
      points={{4,0},{-14,0},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, torque1.frame_a) annotation (Line(
      points={{4,22},{-14,22},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, force) annotation (Line(
      points={{4,0},{-102,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.torque, torque2)
    annotation (Line(points={{8,34},{8,60},{-120,60}}, color={0,0,127}));
  connect(Airframe, torque1.frame_a) annotation (Line(
      points={{102,52},{84,52},{84,92},{-14,92},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(Blade, torque1.frame_b) annotation (Line(
      points={{102,-40},{62,-40},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_b, torque1.frame_b) annotation (Line(
      points={{24,0},{62,0},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b, torque1.frame_b) annotation (Line(
      points={{24,22},{62,22},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, torque1.frame_b) annotation (
      Line(
      points={{50,84},{62,84},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end MavicAir;
