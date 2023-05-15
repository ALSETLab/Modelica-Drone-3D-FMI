within DroneSimulation.Tests;
model simpleHoverTest
   DroneSimulation.Mechanical.Chassis.Examples.droneChassis droneChassis1(m=10)
     annotation (Placement(transformation(extent={{30,-10},{80,10}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,40},{80,60}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={50,-68})));
  Modelica.Mechanics.MultiBody.Sensors.RelativePosition relativePosition
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={38,-28})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract annotation (Placement(
         transformation(
         extent={{-10,-10},{10,10}},
         rotation=90,
         origin={-76,-40})));
  Modelica.Blocks.Sources.Ramp ramp(height=5, duration=0.5)
    annotation (Placement(transformation(extent={{-118,-10},{-98,10}})));
   Modelica.Blocks.Continuous.PID PID(
     k=1.5,
     Ti=0.8,
     Td=1,
     initType=Modelica.Blocks.Types.Init.SteadyState)
     annotation (Placement(transformation(extent={{-58,-6},{-46,6}})));
  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-86,-10},{-66,10}})));
  Mechanical.Propeller propellerRev(PropellerGain=1)
     annotation (Placement(transformation(extent={{-20,40},{0,60}})));
  Mechanical.Propeller propellerRev1
     annotation (Placement(transformation(extent={{-20,10},{0,30}})));
  Mechanical.Propeller propellerRev3
     annotation (Placement(transformation(extent={{-20,-16},{0,4}})));
  Mechanical.Propeller propellerRev2
     annotation (Placement(transformation(extent={{-20,-40},{0,-20}})));
equation
  connect(relativePosition.frame_b, droneChassis1.frame_a3) annotation (
      Line(
      points={{28,-28},{26,-28},{26,-6},{30,-6}},
      color={95,95,95},
      thickness=0.5));
  connect(fixed.frame_b, relativePosition.frame_a) annotation (Line(
      points={{50,-58},{50,-28},{48,-28}},
      color={95,95,95},
      thickness=0.5));
  connect(relativePosition.r_rel, realExtract.u) annotation (Line(points={{
          38,-17},{66,-17},{66,-92},{-76,-92},{-76,-50}}, color={0,0,127}));
  connect(feedback.u1, ramp.y)
    annotation (Line(points={{-84,0},{-97,0}}, color={0,0,127}));
  connect(feedback.u2, realExtract.y)
    annotation (Line(points={{-76,-8},{-76,-29}}, color={0,0,127}));
  connect(feedback.y, PID.u)
    annotation (Line(points={{-67,0},{-59.2,0}}, color={0,0,127}));
  connect(propellerRev1.position,propellerRev. position) annotation (Line(
        points={{-22.2,20},{-30,20},{-30,50},{-22.2,50}}, color={0,0,127}));
   connect(droneChassis1.frame_a1, propellerRev.Airframe) annotation (Line(
       points={{30,6},{16,6},{16,49.6},{0.2,49.6}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev3.Airframe, droneChassis1.frame_a2) annotation (Line(
       points={{0.2,-6.4},{15.1,-6.4},{15.1,-2},{30,-2}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev1.Airframe, droneChassis1.frame_a) annotation (Line(
       points={{0.2,19.6},{0.2,20},{10,20},{10,2},{30,2}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev2.Airframe, droneChassis1.frame_a3) annotation (Line(
       points={{0.2,-30.4},{18,-30.4},{18,-6},{30,-6}},
       color={95,95,95},
       thickness=0.5));
   connect(PID.y, propellerRev3.position) annotation (Line(points={{-45.4,0},{
           -30,0},{-30,-6},{-22.2,-6}}, color={0,0,127}));
   connect(propellerRev2.position, propellerRev3.position) annotation (Line(
         points={{-22.2,-30},{-30,-30},{-30,-6},{-22.2,-6}}, color={0,0,127}));
   connect(propellerRev1.position, propellerRev3.position) annotation (Line(
         points={{-22.2,20},{-30,20},{-30,-6},{-22.2,-6}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -120,-100},{100,100}})), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-120,-100},{
            100,100}})));
end simpleHoverTest;
