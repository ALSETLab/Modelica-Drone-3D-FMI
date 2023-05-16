within DroneSimulation.Mechanical.Propeller.Examples;
model propellerVR
  "This model is the propeller used in the cases when the model is interfaced with virtual reality softwares."
  Modelica.Mechanics.MultiBody.Forces.Torque torque(resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.frame_a)
    annotation (Placement(transformation(extent={{4,12},{24,32}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape4(
    m=0.01,
    r={0.154,0,0},
    I_33=0.001,
    shapeType="cylinder")
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={66,10})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape5(
    m=0.010,
    r={-0.154,0,0},
    I_33=0.001)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={66,-10})));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute
    annotation (Placement(transformation(extent={{4,-10},{24,10}})));
Modelica.Mechanics.MultiBody.Forces.WorldForce force(color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
  annotation (Placement(transformation(
      extent={{-10,-10},{10,10}},
      rotation=90,
      origin={-14,-10})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{84,-16},{116,16}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
Electrical.Machines.SimpleDCmotor dCmotor
    annotation (Placement(transformation(extent={{-72,-10},{-52,10}})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{38,-78},{58,-58}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{30,74},{50,94}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque1
    annotation (Placement(transformation(extent={{4,-50},{24,-30}})));
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
        origin={40,-10})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-30,-78},{-10,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-28,-42},{-18,-32}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-94,-4},{-86,4}})));
equation
  connect(revolute.frame_b,bodyShape4. frame_a) annotation (Line(
      points={{24,0},{66,0}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape4.frame_a, bodyShape5.frame_a) annotation (Line(
      points={{66,0},{66,0}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_a, force.frame_b) annotation (Line(
      points={{4,0},{-14,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, force.frame_b) annotation (Line(
      points={{4,22},{-2,22},{-2,0},{-14,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b, bodyShape4.frame_a) annotation (Line(
      points={{24,22},{50,22},{50,0},{66,0}},
      color={95,95,95},
      thickness=0.5));
  connect(force.frame_b, frame_a) annotation (Line(
      points={{-14,0},{-38,0},{-38,58},{86,58},{86,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_a, force.frame_b) annotation (Line(
      points={{30,84},{-38,84},{-38,0},{-14,0},{-14,8.88178e-16}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, bodyShape4.frame_a) annotation (
      Line(
      points={{50,84},{50,0},{66,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque1.frame_a, force.frame_b) annotation (Line(
      points={{4,-40},{-2,-40},{-2,0},{-14,0},{-14,8.88178e-16}},
      color={95,95,95},
      thickness=0.5));
  connect(torque1.frame_b, bodyShape4.frame_a) annotation (Line(
      points={{24,-40},{50,-40},{50,0},{66,0},{66,-8.88178e-16}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.w_rel, realExtract.u)
    annotation (Line(points={{40,73},{40,46}}, color={0,0,127}));
  connect(realExtract.y, gain.u)
    annotation (Line(points={{40,33.4},{40,17.2}}, color={0,0,127}));
  connect(gain.y, realExtend2.u)
    annotation (Line(points={{40,3.4},{40,-2.8}},
                                                color={0,0,127}));
  connect(realExtend2.y, torque1.torque) annotation (Line(points={{40,-16.6},
          {8,-16.6},{8,-28}}, color={0,0,127}));
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{-9,-68},{36,-68}}, color={0,0,127}));
  connect(dCmotor.force, gain1.u) annotation (Line(points={{-51,-4},{-44,-4},
          {-44,-68},{-32,-68}}, color={0,0,127}));
  connect(realExtend1.y, torque.torque) annotation (Line(points={{59,-68},{
          80,-68},{80,72},{8,72},{8,34}}, color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-17.5,-37},{
          -14,-37},{-14,-22}}, color={0,0,127}));
  connect(dCmotor.torque, realExtend.u) annotation (Line(points={{-51,4},{
          -40,4},{-40,-37},{-29,-37}}, color={0,0,127}));
  connect(dCmotor.current, limiter.y)
    annotation (Line(points={{-74,0},{-85.6,0}}, color={0,0,127}));
  connect(position, limiter.u)
    annotation (Line(points={{-122,0},{-94.8,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="propellerR")}));
end propellerVR;
