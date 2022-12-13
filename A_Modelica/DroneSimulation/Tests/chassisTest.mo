within DroneSimulation.Tests;
model chassisTest
  Mechanical.Propeller                 propellerRev(PropellerGain=1)
     annotation (Placement(transformation(extent={{-20,40},{0,60}})));
   Mechanical.Chassis.Examples.droneChassis droneChassis1
     annotation (Placement(transformation(extent={{30,-10},{80,10}})));
  Modelica.Blocks.Sources.Step step(startTime=0, height=1)
    annotation (Placement(transformation(extent={{-100,-2},{-80,18}})));
  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-72,0},{-56,16}})));
  Modelica.Blocks.Sources.Step step1(height=1, startTime=0.5)
    annotation (Placement(transformation(extent={{-100,-38},{-80,-18}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Mechanical.Propeller                 propellerRev1
     annotation (Placement(transformation(extent={{-20,10},{0,30}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={60,-70})));
  Modelica.Mechanics.MultiBody.Sensors.RelativePosition relativePosition(
      resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.world)
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={44,-36})));
  Modelica.Blocks.Math.Gain gain(k=5)
    annotation (Placement(transformation(extent={{-50,4},{-42,12}})));
  Mechanical.Propeller                 propellerRev3
     annotation (Placement(transformation(extent={{-20,-16},{0,4}})));
  Mechanical.Propeller                 propellerRev2
     annotation (Placement(transformation(extent={{-20,-40},{0,-20}})));
equation
  connect(step.y, feedback.u1)
    annotation (Line(points={{-79,8},{-70.4,8}}, color={0,0,127}));
  connect(step1.y, feedback.u2) annotation (Line(points={{-79,-28},{-64,-28},
          {-64,1.6}}, color={0,0,127}));
  connect(propellerRev1.position, propellerRev.position) annotation (Line(
        points={{-22.2,18},{-30,18},{-30,48},{-22.2,48}}, color={0,0,127}));
  connect(feedback.y, gain.u)
    annotation (Line(points={{-56.8,8},{-50.8,8}}, color={0,0,127}));
  connect(relativePosition.frame_a, fixed.frame_b) annotation (Line(
      points={{54,-36},{58,-36},{58,-60},{60,-60}},
      color={95,95,95},
      thickness=0.5));
   connect(droneChassis1.frame_a1, propellerRev.Airframe) annotation (Line(
       points={{30,6},{16,6},{16,46},{0.2,46}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev3.position, gain.y) annotation (Line(points={{-22.2,-8},
           {-30,-8},{-30,8},{-41.6,8}}, color={0,0,127}));
   connect(propellerRev1.position, gain.y) annotation (Line(points={{-22.2,18},
           {-30,18},{-30,8},{-41.6,8}}, color={0,0,127}));
   connect(propellerRev2.position, gain.y) annotation (Line(points={{-22.2,-32},
           {-30,-32},{-30,8},{-41.6,8}}, color={0,0,127}));
   connect(propellerRev3.Airframe, droneChassis1.frame_a2) annotation (Line(
       points={{0.2,-10},{15.1,-10},{15.1,-2},{30,-2}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev1.Airframe, droneChassis1.frame_a) annotation (Line(
       points={{0.2,16},{0.2,20},{10,20},{10,2},{30,2}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev2.Airframe, droneChassis1.frame_a3) annotation (Line(
       points={{0.2,-34},{18,-34},{18,-6},{30,-6}},
       color={95,95,95},
       thickness=0.5));
   connect(relativePosition.frame_b, droneChassis1.frame_a3) annotation (Line(
       points={{34,-36},{18,-36},{18,-6},{30,-6}},
       color={95,95,95},
       thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end chassisTest;
