within DroneLibrary.Tests;
model propellerTest
  extends Modelica.Icons.Example;
   Modelica.Mechanics.MultiBody.Forces.WorldForce force(color={244,0,4},
       resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
     annotation (Placement(transformation(extent={{-44,46},{-24,66}})));

  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape(
    m=0.5,
    r={0,0.25,0},
    r_CM={0,0.175,0})
    annotation (Placement(transformation(extent={{-10,46},{10,66}})));
  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,-1})
    annotation (Placement(transformation(extent={{-78,-84},{-58,-64}})));
   Modelica.Mechanics.MultiBody.Forces.WorldForce force1(color={244,0,4},
       resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
     annotation (Placement(transformation(
         extent={{-10,-10},{10,10}},
         origin={-34,24})));

  Modelica.Blocks.Sources.Constant torque1
                                         [3](k={0,0,-1})
    annotation (Placement(transformation(
        origin={-120,80},
        extent={{10,-10},{-10,10}},
        rotation=180)));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape1(
    m=0.5,
    r={0.25,0,0},
    r_CM={0.175,0,0}) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={0,24})));
   Modelica.Mechanics.MultiBody.Forces.WorldForce force2(color={244,0,4},
       resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
     annotation (Placement(transformation(extent={{-44,-16},{-24,4}})));

  Modelica.Blocks.Sources.Constant torque2(k=1) annotation (Placement(
        transformation(
        origin={-200,14},
        extent={{10,-10},{-10,10}},
        rotation=180)));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape2(
    m=0.5,
    r={0,-0.25,0},
    r_CM={0,-0.175,0})
    annotation (Placement(transformation(extent={{-10,-16},{10,4}})));
   Modelica.Mechanics.MultiBody.Forces.WorldForce force3(color={244,0,4},
       resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
     annotation (Placement(transformation(
         extent={{-10,-10},{10,10}},
         origin={-34,-38})));

  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape3(
    m=0.5,
    r={-0.25,0,0},
    r_CM={-0.175,0,0}) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={0,-38})));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder bodyCylinder(
    density=0,
    r_shape={0,0,0},
    length=0.25,
    diameter=0.01,
    r={0,0,-0.25})
    annotation (Placement(transformation(extent={{44,0},{64,20}})));
  Modelica.Mechanics.MultiBody.Parts.PointMass pointMass(m=0.50)
    annotation (Placement(transformation(extent={{64,0},{84,20}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape4(
    m=0.01,
    r={0.154,0,0},
    I_33=0.001)
    annotation (Placement(transformation(extent={{72,72},{92,92}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape5(
    m=0.010,
    r={-0.154,0,0},
    I_33=0.001)
    annotation (Placement(transformation(extent={{72,46},{92,66}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque(resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.frame_a)
    annotation (Placement(transformation(extent={{-10,94},{10,114}})));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute
    annotation (Placement(transformation(extent={{-8,72},{12,92}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape6(
    m=0.01,
    r={0.154,0,0},
    I_33=0.001)
    annotation (Placement(transformation(extent={{246,-216},{266,-196}})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape7(
    m=0.010,
    r={-0.154,0,0},
    I_33=0.001)
    annotation (Placement(transformation(extent={{246,-242},{266,-222}})));
  Modelica.Blocks.Sources.Constant torque4
                                         [3](k={0,0,1})
    annotation (Placement(transformation(
        origin={126,-144},
        extent={{10,-10},{-10,10}},
        rotation=180)));
  Modelica.Mechanics.MultiBody.Forces.Torque torque5(resolveInFrame=
        Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.frame_a)
    annotation (Placement(transformation(extent={{164,-194},{184,-174}})));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute1
    annotation (Placement(transformation(extent={{166,-216},{186,-196}})));
  DroneLibrary.Blocks.Routing.RealExtend realExtend annotation (Placement(transformation(extent={{-78,46},{-58,66}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngles relativeAngles
    annotation (Placement(transformation(extent={{18,-84},{38,-64}})));
  Modelica.Mechanics.MultiBody.Sensors.RelativePosition relativePosition
    annotation (Placement(transformation(extent={{18,-114},{38,-94}})));
  DroneLibrary.Blocks.Routing.RealExtract realExtract annotation (Placement(transformation(
        extent={{-7,-7},{7,7}},
        rotation=180,
        origin={-149,-115})));
  Modelica.Blocks.Math.Gain gain(k=15)
    annotation (Placement(transformation(extent={{-146,38},{-126,58}})));
  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-176,38},{-156,58}})));
  Modelica.Blocks.Continuous.Derivative
                      realDer(k=5, initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-144,-50},{-124,-30}})));
  Modelica.Blocks.Continuous.Integrator integrator(k=10, initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-144,-82},{-124,-62}})));
  Modelica.Blocks.Math.Add3
                      sISO
    annotation (Placement(transformation(extent={{-86,-24},{-66,-4}})));
equation
  connect(force.frame_b, bodyShape.frame_a) annotation (Line(
      points={{-24,56},{-10,56}},
      color={95,95,95},
      thickness=0.5));
  connect(force1.frame_b, bodyShape1.frame_a) annotation (Line(
      points={{-24,24},{-10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(force2.frame_b, bodyShape2.frame_a) annotation (Line(
      points={{-24,-6},{-10,-6}},
      color={95,95,95},
      thickness=0.5));
  connect(force3.frame_b, bodyShape3.frame_a) annotation (Line(
      points={{-24,-38},{-10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape.frame_b, bodyShape3.frame_b) annotation (Line(
      points={{10,56},{28,56},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape2.frame_b, bodyShape3.frame_b) annotation (Line(
      points={{10,-6},{28,-6},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape1.frame_b, bodyShape3.frame_b) annotation (Line(
      points={{10,24},{28,24},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyCylinder.frame_a, bodyShape3.frame_b) annotation (Line(
      points={{44,10},{28,10},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyCylinder.frame_b, pointMass.frame_a) annotation (Line(
      points={{64,10},{74,10}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, bodyShape.frame_a) annotation (Line(
      points={{-10,104},{-20,104},{-20,56},{-10,56}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b, bodyShape4.frame_a) annotation (Line(
      points={{10,104},{42,104},{42,82},{72,82}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape5.frame_a, bodyShape4.frame_a) annotation (Line(
      points={{72,56},{70,56},{70,82},{72,82}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.torque, torque1.y) annotation (Line(points={{-6,116},{-28,
          116},{-28,80},{-109,80}}, color={0,0,127}));
  connect(revolute.frame_a, bodyShape.frame_a) annotation (Line(
      points={{-8,82},{-20,82},{-20,56},{-10,56}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute.frame_b, bodyShape4.frame_a) annotation (Line(
      points={{12,82},{72,82}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape7.frame_a, bodyShape6.frame_a) annotation (Line(
      points={{246,-232},{244,-232},{244,-206},{246,-206}},
      color={95,95,95},
      thickness=0.5));
  connect(torque5.torque, torque4.y) annotation (Line(points={{168,-172},{146,
          -172},{146,-144},{137,-144}}, color={0,0,127}));
  connect(revolute1.frame_b, bodyShape6.frame_a) annotation (Line(
      points={{186,-206},{246,-206}},
      color={95,95,95},
      thickness=0.5));
  connect(torque5.frame_b, bodyShape7.frame_a) annotation (Line(
      points={{184,-184},{216,-184},{216,-232},{246,-232}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute1.frame_a, torque5.frame_a) annotation (Line(
      points={{166,-206},{158,-206},{158,-184},{164,-184}},
      color={95,95,95},
      thickness=0.5));
  connect(bodyShape2.frame_a, torque5.frame_a) annotation (Line(
      points={{-10,-6},{-16,-6},{-16,-220},{68,-220},{68,-184},{164,-184}},
      color={95,95,95},
      thickness=0.5));
  connect(force.force, realExtend.y)
    annotation (Line(points={{-46,56},{-57,56}}, color={0,0,127}));
  connect(force1.force, realExtend.y) annotation (Line(points={{-46,24},{-46,
          40},{-57,40},{-57,56}}, color={0,0,127}));
  connect(force2.force, realExtend.y) annotation (Line(points={{-46,-6},{-52,
          -6},{-52,56},{-57,56}}, color={0,0,127}));
  connect(force3.force, realExtend.y) annotation (Line(points={{-46,-38},{-46,
          9},{-57,9},{-57,56}}, color={0,0,127}));
  connect(world.frame_b, relativeAngles.frame_a) annotation (Line(
      points={{-58,-74},{18,-74}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngles.frame_b, bodyShape3.frame_b) annotation (Line(
      points={{38,-74},{38,10},{28,10},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(world.frame_b, relativePosition.frame_a) annotation (Line(
      points={{-58,-74},{-20,-74},{-20,-104},{18,-104}},
      color={95,95,95},
      thickness=0.5));
  connect(relativePosition.frame_b, bodyShape3.frame_b) annotation (Line(
      points={{38,-104},{38,10},{28,10},{28,-38},{10,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(relativePosition.r_rel, realExtract.u) annotation (Line(points={{28,
          -115},{-142,-115},{-142,-115}}, color={0,0,127}));
  connect(torque2.y, feedback.u1) annotation (Line(points={{-189,14},{-182,14},
          {-182,48},{-174,48}}, color={0,0,127}));
  connect(gain.u, feedback.y)
    annotation (Line(points={{-148,48},{-157,48}}, color={0,0,127}));
  connect(feedback.u2, realExtract.y) annotation (Line(points={{-166,40},{
          -166,-115},{-156.7,-115}}, color={0,0,127}));
  connect(integrator.u, feedback.y) annotation (Line(points={{-146,-72},{
          -156,-72},{-156,48},{-157,48}},
                                     color={0,0,127}));
  connect(sISO.u1, gain.y) annotation (Line(points={{-88,-6},{-112,-6},{
          -112,48},{-125,48}}, color={0,0,127}));
  connect(sISO.y, realExtend.u) annotation (Line(points={{-65,-14},{-62,-14},
          {-62,38},{-102,38},{-102,56},{-80,56}}, color={0,0,127}));
  connect(realDer.y, sISO.u2) annotation (Line(points={{-123,-40},{-120,-40},
          {-120,-14},{-88,-14}}, color={0,0,127}));
  connect(integrator.y, sISO.u3) annotation (Line(points={{-123,-72},{-112,
          -72},{-112,-22},{-88,-22}}, color={0,0,127}));
  connect(realDer.u, feedback.y) annotation (Line(points={{-146,-40},{-156,
          -40},{-156,48},{-157,48}}, color={0,0,127}));
  annotation (Diagram(coordinateSystem(extent={{-220,-260},{280,120}})),
              experiment(StopTime=15));
end propellerTest;
