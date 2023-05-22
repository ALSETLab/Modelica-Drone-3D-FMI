within DroneLibrary.Examples.Phantom;
model controlModuleTest
  Electrical.controlModule_Synchronous
                           controlModuleSpeed(maxTilt=0.15,
                                                       samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-30,8},{-10,28}})));
Mechanical.Chassis.Examples.Phantom droneChassis_1_1(length=0.35, m=0.65)
  annotation (Placement(transformation(extent={{42,6},{92,26}})));
Mechanical.Propeller.Examples.Phantom propeller_1_1
  annotation (Placement(transformation(extent={{8,30},{28,36}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
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
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{40,-98},{20,-78}})));
Mechanical.Propeller.Examples.Phantom propeller_1_2(PropellerGain=1)
  annotation (Placement(transformation(extent={{8,20},{28,26}})));
Mechanical.Propeller.Examples.Phantom propeller_1_3
  annotation (Placement(transformation(extent={{8,10},{28,16}})));
Mechanical.Propeller.Examples.Phantom propeller_1_4(PropellerGain=1)
  annotation (Placement(transformation(extent={{8,0},{28,6}})));
equation
   connect(propeller_1_1.position, controlModuleSpeed.y1) annotation (Line(
         points={{5.8,32.4},{-2,32.4},{-2,24},{-9.16667,24}},
                                                    color={0,0,127}));
   connect(controlModuleSpeed.position, realExtendMultiple.y)
     annotation (Line(points={{-31.6667,18},{-37,18}},
                                                  color={0,0,127}));
   connect(gPS.frame_a, droneChassis_1_1.frame_a3) annotation (Line(
       points={{28,-40},{36,-40},{36,10},{42,10}},
       color={95,95,95},
       thickness=0.5));
   connect(gPS.y, controlModuleSpeed.GPS) annotation (Line(points={{7,-40},{
        -26.6667,-40},{-26.6667,6}},
                               color={0,0,127}));
   connect(accelerometer.frame_a, droneChassis_1_1.frame_a3) annotation (
       Line(
       points={{28,-66},{36,-66},{36,10},{42,10}},
       color={95,95,95},
       thickness=0.5));
   connect(accelerometer.y, controlModuleSpeed.Gyero) annotation (Line(
         points={{7,-66},{-21.6667,-66},{-21.6667,6}},
                                             color={0,0,127}));
  connect(ramp.y, firstOrder1.u)
    annotation (Line(points={{-80,-39},{-80,-32}}, color={0,0,127}));
   connect(controlModuleSpeed.yaw, const.y) annotation (Line(points={{
        -31.6667,26},{-36,26},{-36,46},{-71,46}},
                                            color={0,0,127}));
  connect(firstOrder1.y, realExtendMultiple.u2) annotation (Line(points={{
          -80,-9},{-80,2},{-64,2},{-64,12},{-58,12}}, color={0,0,127}));
  connect(circlePath.y, realExtendMultiple.u)
    annotation (Line(points={{-71,24},{-58,24}}, color={0,0,127}));
  connect(circlePath.y1, realExtendMultiple.u1) annotation (Line(points={{
          -71,16},{-66,16},{-66,18},{-58,18}}, color={0,0,127}));
   connect(controlModuleSpeed.Height, const1.y) annotation (Line(points={{
        -16.6667,6},{-16.6667,-88},{19,-88}},
                                       color={0,0,127}));
connect(propeller_1_4.Airframe, droneChassis_1_1.frame_a3) annotation (Line(
    points={{28.2,1.8},{36,2},{36,10},{42,10}},
    color={95,95,95},
    thickness=0.5));
connect(propeller_1_4.position, controlModuleSpeed.y3) annotation (Line(
      points={{5.8,2.4},{-2.1,2.4},{-2.1,12},{-9.16667,12}}, color={0,0,127}));
connect(propeller_1_3.position, controlModuleSpeed.y2) annotation (Line(
      points={{5.8,12.4},{-1.1,12.4},{-1.1,16},{-9.16667,16}}, color={0,0,127}));
connect(controlModuleSpeed.y, propeller_1_2.position) annotation (Line(points=
       {{-9.16667,20},{-2,20},{-2,22.4},{5.8,22.4}}, color={0,0,127}));
connect(propeller_1_2.Airframe, droneChassis_1_1.frame_a) annotation (Line(
    points={{28.2,21.8},{35.1,21.8},{35.1,18},{42,18}},
    color={95,95,95},
    thickness=0.5));
connect(droneChassis_1_1.frame_a2, propeller_1_3.Airframe) annotation (Line(
    points={{42,14},{36,14},{36,11.8},{28.2,11.8}},
    color={95,95,95},
    thickness=0.5));
connect(droneChassis_1_1.frame_a1, propeller_1_1.Airframe) annotation (Line(
    points={{42,22},{36,22},{36,31.8},{28.2,31.8}},
    color={95,95,95},
    thickness=0.5));
  annotation (
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos"
        "drone_animation_setup"),
    experiment(StopTime=10, __Dymola_Algorithm="Dassl"));
end controlModuleTest;
