within DroneLibrary.Tests;
model motorTest
   DroneLibrary.Electrical.Machines.SimpleDCmotor dCmotor annotation (Placement(transformation(extent={{-10,-2},{10,18}})));
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
  Mechanical.Propeller.Variants.Propeller propellerRev1 annotation (Placement(transformation(extent={{-10,-76},{10,-56}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed1(r={0.5,0,0}) annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={54,-66})));
  Mechanical.Propeller.Variants.Propeller propellerRev2 annotation (Placement(transformation(extent={{-10,-44},{10,-24}})));
equation
  connect(step.y, feedback.u1)
    annotation (Line(points={{-65,8},{-56,8}}, color={0,0,127}));
  connect(feedback.y, dCmotor.current)
    annotation (Line(points={{-39,8},{-12,8}}, color={0,0,127}));
  connect(step1.y, feedback.u2) annotation (Line(points={{-55,-36},{-48,-36},
          {-48,0}}, color={0,0,127}));
  connect(propellerRev1.position, dCmotor.current) annotation (Line(points={{-12.2,
          -68},{-24,-68},{-24,8},{-12,8}},  color={0,0,127}));
  connect(propellerRev2.position, dCmotor.current) annotation (Line(points={{-12.2,
          -36},{-24,-36},{-24,8},{-12,8}},  color={0,0,127}));

  connect(fixed.frame_b, propellerRev2.Airframe) annotation (Line(
      points={{44,-34},{16,-34},{16,-38},{10.2,-38}},
      color={95,95,95},
      thickness=0.5));
  connect(fixed1.frame_b, propellerRev1.Airframe) annotation (Line(
      points={{44,-66},{16,-66},{16,-70},{10.2,-70}},
      color={95,95,95},
      thickness=0.5));
end motorTest;
