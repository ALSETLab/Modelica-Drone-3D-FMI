within DroneSimulation.Tests;
model controlModuleTest_fmu_inputs
  Electrical.controlModule controlModule(maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
   Mechanical.Chassis.Examples.droneChassis droneChassis1(length=0.25, m=0.5)
     annotation (Placement(transformation(extent={{44,-12},{94,8}})));
  Mechanical.Propeller.Examples.Propeller
                       propellerRev(PropellerGain=1)
    annotation (Placement(transformation(extent={{8,18},{28,38}})));
  Mechanical.Propeller.Examples.Propeller
                       propellerRev3(PropellerGain=1)
    annotation (Placement(transformation(extent={{8,-22},{28,-2}})));
  Mechanical.Propeller.Examples.Propeller
                       propellerRev1
    annotation (Placement(transformation(extent={{8,-2},{28,18}})));
  Mechanical.Propeller.Examples.Propeller
                       propellerRev2
    annotation (Placement(transformation(extent={{8,-42},{28,-22}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-58,-10},{-38,10}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={18,-58})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{8,-94},{28,-74}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-36,26})));
  Modelica.Blocks.Interfaces.RealInput xcoord
    annotation (Placement(transformation(extent={{-140,60},{-100,100}})));
  Modelica.Blocks.Interfaces.RealInput zcoord
    annotation (Placement(transformation(extent={{-140,-100},{-100,-60}})));
  Modelica.Blocks.Interfaces.RealInput ycoord
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}})));
  Modelica.Blocks.Interfaces.RealOutput xgps
    annotation (Placement(transformation(extent={{100,70},{120,90}})));
  Modelica.Blocks.Interfaces.RealOutput ygps
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  Modelica.Blocks.Interfaces.RealOutput zgps
    annotation (Placement(transformation(extent={{100,-90},{120,-70}})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(propellerRev.position, controlModule.y1) annotation (Line(points={{5.8,26},
          {-2,26},{-2,6},{-9.16667,6}},
                                  color={0,0,127}));
  connect(propellerRev1.position, controlModule.y) annotation (Line(points={{5.8,6},
          {0,6},{0,2},{-9.16667,2}},    color={0,0,127}));
  connect(propellerRev3.position, controlModule.y2) annotation (Line(points={{5.8,-14},
          {0,-14},{0,-2},{-9.16667,-2}},     color={0,0,127}));
  connect(propellerRev2.position, controlModule.y3) annotation (Line(points={{5.8,-34},
          {-2,-34},{-2,-6},{-9.16667,-6}},     color={0,0,127}));
  connect(controlModule.position, realExtendMultiple.y) annotation (Line(
        points={{-31.6667,0},{-37,0}}, color={0,0,127}));
  connect(gPS.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{28,-58},{36,-58},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.y, controlModule.GPS) annotation (Line(points={{7,-58},{-26.6667,
          -58},{-26.6667,-12}},
                          color={0,0,127}));
  connect(accelerometer.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{28,-84},{36,-84},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule.Gyero) annotation (Line(points={{7,-84},
          {-21.6667,-84},{-21.6667,-12}},
                                    color={0,0,127}));
  connect(controlModule.yaw, const.y) annotation (Line(points={{-31.6667,8},{
          -36,8},{-36,15},{-36,15}},   color={0,0,127}));
  connect(xcoord, realExtendMultiple.u) annotation (Line(points={{-120,80},{-78,
          80},{-78,6},{-58,6}}, color={0,0,127}));
  connect(ycoord, realExtendMultiple.u1)
    annotation (Line(points={{-120,0},{-58,0}}, color={0,0,127}));
  connect(zcoord, realExtendMultiple.u2) annotation (Line(points={{-120,-80},{-80,
          -80},{-80,-6},{-58,-6}}, color={0,0,127}));
  connect(droneChassis1.frame_a1, propellerRev.Airframe) annotation (Line(
      points={{44,4},{44,24},{28.2,24}},
      color={95,95,95},
      thickness=0.5));
  connect(propellerRev1.Airframe, droneChassis1.frame_a) annotation (Line(
      points={{28.2,4},{34,4},{34,0},{44,0}},
      color={95,95,95},
      thickness=0.5));
  connect(propellerRev3.Airframe, droneChassis1.frame_a2) annotation (Line(
      points={{28.2,-16},{34,-16},{34,-4},{44,-4}},
      color={95,95,95},
      thickness=0.5));
  connect(propellerRev2.Airframe, droneChassis1.frame_a3) annotation (Line(
      points={{28.2,-36},{36,-36},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={215,215,215},
          lineThickness=1), Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/dronepic.jpg")}),
    __Dymola_Commands(file="modelica://DroneSimulation/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"),
     experiment(StopTime=10));
end controlModuleTest_fmu_inputs;
