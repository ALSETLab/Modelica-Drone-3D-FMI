within DroneSimulation.Tests;
model motorTest
   DroneSimulation.Electrical.Machines.SimpleDCmotor dCmotor
     annotation (Placement(transformation(extent={{-10,-2},{10,18}})));
  Modelica.Blocks.Sources.Step step(startTime=1)
    annotation (Placement(transformation(extent={{-86,-2},{-66,18}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={54,-34})));
  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-58,-2},{-38,18}})));
  Modelica.Blocks.Sources.Step step1(startTime=2)
    annotation (Placement(transformation(extent={{-76,-46},{-56,-26}})));
  Electrical.propeller                 propellerRev1
     annotation (Placement(transformation(extent={{-10,-76},{10,-56}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed1(r={0.5,0,0}) annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={54,-66})));
  Electrical.propeller                 propellerRev2
     annotation (Placement(transformation(extent={{-10,-44},{10,-24}})));
equation
  connect(step.y, feedback.u1)
    annotation (Line(points={{-65,8},{-56,8}}, color={0,0,127}));
  connect(feedback.y, dCmotor.current)
    annotation (Line(points={{-39,8},{-12,8}}, color={0,0,127}));
  connect(step1.y, feedback.u2) annotation (Line(points={{-55,-36},{-48,-36},
          {-48,0}}, color={0,0,127}));
  connect(propellerRev1.position, dCmotor.current) annotation (Line(points={{-12.2,
           -66},{-24,-66},{-24,8},{-12,8}},        color={0,0,127}));
  connect(propellerRev2.position, dCmotor.current) annotation (Line(points={{-12.2,
           -34},{-24,-34},{-24,8},{-12,8}},        color={0,0,127}));
   connect(propellerRev2.frame_a, fixed.frame_b) annotation (Line(
       points={{10,-34},{44,-34}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev1.frame_a, fixed1.frame_b) annotation (Line(
       points={{10,-66},{44,-66}},
       color={95,95,95},
       thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end motorTest;
