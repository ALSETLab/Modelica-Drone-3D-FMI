within DroneLibrary.Tests;
model controlModuleTest
  extends Modelica.Icons.Example;
  Electrical.controlModule controlModule(maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-30,8},{-10,28}})));
  Mechanical.Chassis.Variants.droneChassis droneChassis1(length=0.25, m=0.5) annotation (Placement(transformation(extent={{46,6},{96,26}})));
  Mechanical.Propeller.Variants.Propeller propellerRev(PropellerGain=1) annotation (Placement(transformation(extent={{8,38},{28,58}})));
  Mechanical.Propeller.Variants.Propeller propellerRev3(PropellerGain=1) annotation (Placement(transformation(extent={{8,-4},{28,16}})));
  Mechanical.Propeller.Variants.Propeller propellerRev1 annotation (Placement(transformation(extent={{8,16},{28,36}})));
  Mechanical.Propeller.Variants.Propeller propellerRev2 annotation (Placement(transformation(extent={{8,-24},{28,-4}})));
  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-58,8},{-38,28}})));
  Modelica.Blocks.Sources.Ramp ramp( duration=0.5, height=5)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-80,-50})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={18,-40})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{8,-76},{28,-56}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(
    T=0.2,
    y_start=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-80,-20})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-92,36},{-72,56}})));
  Blocks.Sources.circlePath circlePath
    annotation (Placement(transformation(extent={{-92,10},{-72,30}})));
equation
  connect(propellerRev.position, controlModule.y1) annotation (Line(points={{5.8,46},
          {-2,46},{-2,24},{-9.16667,24}},
                                     color={0,0,127}));
  connect(propellerRev1.position, controlModule.y) annotation (Line(points={{5.8,24},
          {0,24},{0,20},{-9.16667,20}}, color={0,0,127}));
  connect(propellerRev3.position, controlModule.y2) annotation (Line(points={{5.8,4},
          {0,4},{0,16},{-9.16667,16}}, color={0,0,127}));
  connect(propellerRev2.position, controlModule.y3) annotation (Line(points={{5.8,-16},
          {-2,-16},{-2,12},{-9.16667,12}}, color={0,0,127}));
  connect(controlModule.position, realExtendMultiple.y) annotation (Line(
        points={{-31.6667,18},{-37,18}},
                                    color={0,0,127}));
  connect(gPS.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{28,-40},{36,-40},{36,10},{46,10}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.y, controlModule.GPS) annotation (Line(points={{7,-40},{-26.6667,-40},{-26.6667,6}},
                    color={0,0,127}));
  connect(accelerometer.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{28,-66},{36,-66},{36,10},{46,10}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule.Gyero) annotation (Line(points={{7,-66},{-21.6667,-66},{-21.6667,6}},
                              color={0,0,127}));
  connect(ramp.y, firstOrder1.u)
    annotation (Line(points={{-80,-39},{-80,-32}}, color={0,0,127}));
  connect(controlModule.yaw, const.y) annotation (Line(points={{-31.6667,26},{-36,26},{-36,46},{-71,46}},
                                  color={0,0,127}));
  connect(firstOrder1.y, realExtendMultiple.u2) annotation (Line(points={{
          -80,-9},{-80,2},{-64,2},{-64,12},{-58,12}}, color={0,0,127}));
  connect(circlePath.y, realExtendMultiple.u)
    annotation (Line(points={{-71,24},{-58,24}}, color={0,0,127}));
  connect(circlePath.y1, realExtendMultiple.u1) annotation (Line(points={{
          -71,16},{-66,16},{-66,18},{-58,18}}, color={0,0,127}));
  connect(propellerRev.Airframe, droneChassis1.frame_a1) annotation (Line(
      points={{28.2,44},{36,44},{36,22},{46,22}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a, propellerRev1.Airframe) annotation (Line(
      points={{46,18},{34,18},{34,22},{28.2,22}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a2, propellerRev3.Airframe) annotation (Line(
      points={{46,14},{34,14},{34,2},{28.2,2}},
      color={95,95,95},
      thickness=0.5));
  connect(propellerRev2.Airframe, droneChassis1.frame_a3) annotation (Line(
      points={{28.2,-18},{36,-18},{36,10},{46,10}},
      color={95,95,95},
      thickness=0.5));
  annotation (
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos"
        "drone_animation_setup"),
    experiment(StopTime=10));
end controlModuleTest;
