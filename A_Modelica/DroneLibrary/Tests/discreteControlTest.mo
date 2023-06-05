within DroneLibrary.Tests;
model discreteControlTest
  DroneLibrary.Mechanical.Chassis.Variants.droneChassis droneChassis1 annotation (Placement(transformation(extent={{30,10},{80,30}})));
  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,
      -1})
    annotation (Placement(transformation(extent={{-100,-80},{-80,-60}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={50,-48})));
  Modelica.Mechanics.MultiBody.Sensors.RelativePosition relativePosition
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={38,-8})));
  DroneLibrary.Blocks.Routing.RealExtract realExtract annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-76,-20})));
  Modelica.Blocks.Sources.Ramp ramp(height=5, duration=0.5)
    annotation (Placement(transformation(extent={{-130,8},{-110,28}})));
  DroneLibrary.Blocks.Control.discretePID discretePID(
    ki=1,
    kd=0.8,
    kp=1.5,
    samplePeriod=0.01) annotation (Placement(transformation(extent={{-86,8},{-66,28}})));
  Mechanical.Propeller.Variants.Propeller propellerRev(PropellerGain=1) annotation (Placement(transformation(extent={{-20,34},{0,54}})));
  Mechanical.Propeller.Variants.Propeller propellerRev1 annotation (Placement(transformation(extent={{-20,10},{0,30}})));
  Mechanical.Propeller.Variants.Propeller propellerRev3 annotation (Placement(transformation(extent={{-20,-16},{0,4}})));
  Mechanical.Propeller.Variants.Propeller propellerRev2 annotation (Placement(transformation(extent={{-20,-40},{0,-20}})));
equation
  connect(relativePosition.frame_b, droneChassis1.frame_a3) annotation (
      Line(
      points={{28,-8},{26,-8},{26,14},{30,14}},
      color={95,95,95},
      thickness=0.5));
  connect(fixed.frame_b, relativePosition.frame_a) annotation (Line(
      points={{50,-38},{50,-8},{48,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(relativePosition.r_rel, realExtract.u) annotation (Line(points={{38,3},{
          66,3},{66,-72},{-76,-72},{-76,-30}}, color={0,0,127}));
  connect(ramp.y, discretePID.u)
    annotation (Line(points={{-109,18},{-86,18}}, color={0,0,127}));
  connect(realExtract.y, discretePID.u1)
    annotation (Line(points={{-76,-9},{-76,8}}, color={0,0,127}));
   connect(propellerRev.Airframe, droneChassis1.frame_a1) annotation (Line(
       points={{0.2,40},{14,40},{14,26},{30,26}},
       color={95,95,95},
       thickness=0.5));
   connect(droneChassis1.frame_a, propellerRev1.Airframe) annotation (Line(
       points={{30,22},{16,22},{16,16},{0.2,16}},
       color={95,95,95},
       thickness=0.5));
   connect(droneChassis1.frame_a2, propellerRev3.Airframe) annotation (Line(
       points={{30,18},{14,18},{14,-10},{0.2,-10}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev2.Airframe, droneChassis1.frame_a3) annotation (Line(
       points={{0.2,-34},{20,-34},{20,14},{30,14}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev.position, propellerRev2.position) annotation (Line(
         points={{-22.2,42},{-32,42},{-32,-32},{-22.2,-32}}, color={0,0,127}));
   connect(discretePID.y, propellerRev2.position) annotation (Line(points={{-65,18},
          {-32,18},{-32,-32},{-22.2,-32}},          color={0,0,127}));
   connect(propellerRev1.position, propellerRev2.position) annotation (Line(
         points={{-22.2,18},{-32,18},{-32,-32},{-22.2,-32}}, color={0,0,127}));
   connect(propellerRev3.position, propellerRev2.position) annotation (Line(
         points={{-22.2,-8},{-32,-8},{-32,-32},{-22.2,-32}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -140,-100},{100,100}})), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-140,-100},{
            100,100}})));
end discreteControlTest;
