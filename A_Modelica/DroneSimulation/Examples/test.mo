within DroneSimulation.Examples;
model test
  Mechanical.Propeller.Propeller_DCMachine_Power propeller_DCMachine_Power(
      PropellerGain=1, V=5)
    annotation (Placement(transformation(extent={{-8,52},{12,62}})));
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-156,-36})));
  Modelica.Electrical.Analog.Sources.ConstantVoltage constantVoltage(V=5)
    annotation (Placement(transformation(extent={{-8,70},{12,90}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{20,60},{40,80}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-2,-18})));
  Electrical.controlModule controlModule(maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-58,26},{-38,46}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-30,10},{-42,22}})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{-12,-50},{8,-30}})));
  Modelica.Blocks.Sources.Constant const2(k=0)
    annotation (Placement(transformation(extent={{-82,38},{-70,50}})));
  Mechanical.Propeller.Propeller_DCMachine_Power propeller_DCMachine_Power1(V=5)
    annotation (Placement(transformation(extent={{-8,38},{12,48}})));
  Mechanical.Propeller.Propeller_DCMachine_Power propeller_DCMachine_Power2(
      PropellerGain=1, V=5)
    annotation (Placement(transformation(extent={{-8,24},{12,34}})));
  Mechanical.Propeller.Propeller_DCMachine_Power propeller_DCMachine_Power3(V=5)
    annotation (Placement(transformation(extent={{-8,10},{12,20}})));
  Mechanical.Chassis.droneChassis droneChassis1(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{36,-110},{86,-90}})));
  Mechanical.Chassis.droneChassis droneChassis2(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{68,34},{118,54}})));
  Modelica.Blocks.Sources.Constant const4(k=0)
    annotation (Placement(transformation(extent={{-106,-92},{-94,-80}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-122,-32},{-102,-12}})));
  Modelica.Blocks.Sources.Constant const5(k=0)
    annotation (Placement(transformation(extent={{-162,-6},{-150,6}})));
  Mechanical.Propeller.Propeller_DCMachine propeller_DCMachine(PropellerGain=1)
    annotation (Placement(transformation(extent={{-24,-80},{-4,-70}})));
  Sensors.GPS gPS1
                  annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-18,-150})));
  Electrical.controlModule controlModule1(maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-74,-106},{-54,-86}})));
  Modelica.Blocks.Sources.Constant const3(k=0)
    annotation (Placement(transformation(extent={{-46,-122},{-58,-110}})));
  Sensors.Accelerometer accelerometer2
    annotation (Placement(transformation(extent={{-28,-182},{-8,-162}})));
  Mechanical.Propeller.Propeller_DCMachine propeller_DCMachine2
    annotation (Placement(transformation(extent={{-24,-94},{-4,-84}})));
  Mechanical.Propeller.Propeller_DCMachine propeller_DCMachine3(PropellerGain=1)
    annotation (Placement(transformation(extent={{-24,-108},{-4,-98}})));
  Mechanical.Propeller.Propeller_DCMachine propeller_DCMachine4
    annotation (Placement(transformation(extent={{-24,-122},{-4,-112}})));
equation
  connect(constantVoltage.n, ground.p)
    annotation (Line(points={{12,80},{30,80}}, color={0,0,255}));
  connect(constantVoltage.p, propeller_DCMachine_Power.p1) annotation (Line(
        points={{-8,80},{-14,80},{-14,60},{-8.4,60}}, color={0,0,255}));
  connect(propeller_DCMachine_Power.position, controlModule.y1) annotation (
      Line(points={{-10,54},{-24,54},{-24,42},{-37.1667,42}}, color={0,0,127}));
  connect(accelerometer.frame_a, gPS.frame_a) annotation (Line(
      points={{8,-40},{46,-40},{46,-18},{8,-18}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModule.Height, const1.y) annotation (Line(points={{-44.6667,24},
          {-44,24},{-44,16},{-42.6,16}}, color={0,0,127}));
  connect(accelerometer.y, controlModule.Gyero) annotation (Line(points={{-13,-40},
          {-49.6667,-40},{-49.6667,24}},      color={0,0,127}));
  connect(gPS.y, controlModule.GPS) annotation (Line(points={{-13,-18},{
          -54.6667,-18},{-54.6667,24}}, color={0,0,127}));
  connect(propeller_DCMachine_Power1.position, controlModule.y) annotation (
      Line(points={{-10,40},{-24,40},{-24,38},{-37.1667,38}}, color={0,0,127}));
  connect(propeller_DCMachine_Power1.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,46},{-14,46},{-14,60},{-8.4,60}}, color={0,0,
          255}));
  connect(propeller_DCMachine_Power2.position, controlModule.y2) annotation (
      Line(points={{-10,26},{-24,26},{-24,34},{-37.1667,34}}, color={0,0,127}));
  connect(controlModule.y3, propeller_DCMachine_Power3.position) annotation (
      Line(points={{-37.1667,30},{-24,30},{-24,12},{-10,12}}, color={0,0,127}));
  connect(propeller_DCMachine_Power3.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,18},{-16,18},{-16,46},{-14,46},{-14,60},{
          -8.4,60}}, color={0,0,255}));
  connect(propeller_DCMachine_Power2.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,32},{-16,32},{-16,46},{-14,46},{-14,60},{
          -8.4,60}}, color={0,0,255}));
  connect(const2.y, controlModule.yaw)
    annotation (Line(points={{-69.4,44},{-59.6667,44}}, color={0,0,127}));
  connect(ramp.y, realExtendMultiple.u2) annotation (Line(points={{-145,-36},{
          -134,-36},{-134,-28},{-122,-28}}, color={0,0,127}));
  connect(realExtendMultiple.y, controlModule.position) annotation (Line(points={{-101,
          -22},{-74,-22},{-74,36},{-59.6667,36}},       color={0,0,127}));
  connect(realExtendMultiple.u, const5.y) annotation (Line(points={{-122,-16},{
          -136,-16},{-136,0},{-149.4,0}}, color={0,0,127}));
  connect(realExtendMultiple.u1, const5.y) annotation (Line(points={{-122,-22},
          {-136,-22},{-136,0},{-149.4,0}}, color={0,0,127}));
  connect(propeller_DCMachine.position, controlModule1.y1) annotation (Line(
        points={{-26,-76},{-40,-76},{-40,-90},{-53.1667,-90}}, color={0,0,127}));
  connect(accelerometer2.frame_a, gPS1.frame_a) annotation (Line(
      points={{-8,-172},{30,-172},{30,-150},{-8,-150}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModule1.Height, const3.y) annotation (Line(points={{-60.6667,
          -108},{-60,-108},{-60,-116},{-58.6,-116}}, color={0,0,127}));
  connect(accelerometer2.y, controlModule1.Gyero) annotation (Line(points={{-29,
          -172},{-65.6667,-172},{-65.6667,-108}}, color={0,0,127}));
  connect(gPS1.y, controlModule1.GPS) annotation (Line(points={{-29,-150},{
          -70.6667,-150},{-70.6667,-108}}, color={0,0,127}));
  connect(propeller_DCMachine2.position, controlModule1.y) annotation (Line(
        points={{-26,-90},{-40,-90},{-40,-94},{-53.1667,-94}}, color={0,0,127}));
  connect(propeller_DCMachine3.position, controlModule1.y2) annotation (Line(
        points={{-26,-104},{-40,-104},{-40,-98},{-53.1667,-98}}, color={0,0,127}));
  connect(controlModule1.y3, propeller_DCMachine4.position) annotation (Line(
        points={{-53.1667,-102},{-40,-102},{-40,-118},{-26,-118}}, color={0,0,
          127}));
  connect(droneChassis2.frame_a1, propeller_DCMachine_Power.Airframe)
    annotation (Line(
      points={{68,50},{40,50},{40,55},{12.2,55}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a, propeller_DCMachine_Power1.Airframe)
    annotation (Line(
      points={{68,46},{40,46},{40,41},{12.2,41}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a2, propeller_DCMachine_Power2.Airframe)
    annotation (Line(
      points={{68,42},{42,42},{42,27},{12.2,27}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a3, propeller_DCMachine_Power3.Airframe)
    annotation (Line(
      points={{68,38},{42,38},{42,13},{12.2,13}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a4, gPS.frame_a) annotation (Line(
      points={{93,34},{88,34},{88,-18},{8,-18}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a1, propeller_DCMachine.Airframe) annotation (
      Line(
      points={{36,-94},{18,-94},{18,-77},{-3.8,-77}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine2.Airframe, droneChassis1.frame_a) annotation (
      Line(
      points={{-3.8,-91},{13.1,-91},{13.1,-98},{36,-98}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a3, propeller_DCMachine4.Airframe) annotation (
      Line(
      points={{36,-106},{16,-106},{16,-119},{-3.8,-119}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a2, propeller_DCMachine3.Airframe) annotation (
      Line(
      points={{36,-102},{16,-102},{16,-105},{-3.8,-105}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a4, gPS1.frame_a) annotation (Line(
      points={{61,-110},{61,-150},{-8,-150}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModule1.yaw, const4.y) annotation (Line(points={{-75.6667,-88},
          {-84,-88},{-84,-86},{-93.4,-86}}, color={0,0,127}));
  connect(controlModule1.position, realExtendMultiple.y) annotation (Line(
        points={{-75.6667,-96},{-114,-96},{-114,-98},{-142,-98},{-142,-58},{-74,
          -58},{-74,-22},{-101,-22}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-180,
            -180},{100,100}})),                                  Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-180,-180},{100,
            100}})),
    experiment(StopTime=10));
end test;
