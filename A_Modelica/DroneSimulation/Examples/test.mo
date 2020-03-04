within DroneSimulation.Examples;
model test
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power(
    PropellerGain=1,
    VaNominal=10,
    V=10) annotation (Placement(transformation(extent={{-8,52},{12,62}})));
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-156,-36})));
  Modelica.Electrical.Analog.Sources.ConstantVoltage constantVoltage(V=9.5)
    annotation (Placement(transformation(extent={{-8,70},{12,90}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{20,60},{40,80}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-2,-18})));
  Electrical.controlModule controlModule_SynchronousPower(
                                         maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-58,26},{-38,46}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-30,10},{-42,22}})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{-12,-50},{8,-30}})));
  Modelica.Blocks.Sources.Constant const2(k=0)
    annotation (Placement(transformation(extent={{-82,38},{-70,50}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power1(VaNominal=10, V=10)
    annotation (Placement(transformation(extent={{-8,38},{12,48}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power2(
    PropellerGain=1,
    VaNominal=10,
    V=10) annotation (Placement(transformation(extent={{-8,24},{12,34}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power3(VaNominal=10, V=10)
    annotation (Placement(transformation(extent={{-8,10},{12,20}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis2(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{68,34},{118,54}})));
  Modelica.Blocks.Sources.Constant const4(k=0)
    annotation (Placement(transformation(extent={{-62,-72},{-50,-60}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-122,-32},{-102,-12}})));
  Modelica.Blocks.Sources.Constant const5(k=0)
    annotation (Placement(transformation(extent={{-162,-6},{-150,6}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,-1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Electrical.controlModule controlModule(maxTilt=0.05, samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-34,-94},{-14,-74}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis1(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{40,-96},{90,-76}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine(PropellerGain=1,
      VaNominal=10)
    annotation (Placement(transformation(extent={{6,-72},{26,-64}})));
  Sensors.GPS gPS1
                  annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={16,-134})));
  Sensors.Accelerometer accelerometer1
    annotation (Placement(transformation(extent={{6,-164},{26,-144}})));
  Modelica.Blocks.Sources.Constant const3(k=0)
    annotation (Placement(transformation(extent={{-2,-126},{-14,-114}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine1(VaNominal=10)
    annotation (Placement(transformation(extent={{6,-82},{26,-74}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine2(PropellerGain=1,
      VaNominal=10)
    annotation (Placement(transformation(extent={{6,-92},{26,-84}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine3(VaNominal=10)
    annotation (Placement(transformation(extent={{6,-102},{26,-94}})));
  Electrical.Sources.Battery battery(
    redeclare Modelon.Electrical.EnergyStorage.Components.BatteryPackEMF
      stackVoltage,
    SOC_start=1,
    ns=7) annotation (Placement(transformation(extent={{-104,60},{-80,84}})));
equation
  connect(constantVoltage.n, ground.p)
    annotation (Line(points={{12,80},{30,80}}, color={0,0,255}));
  connect(propeller_DCMachine_Power.position, controlModule_SynchronousPower.y1)
    annotation (Line(points={{-10,54},{-24,54},{-24,42},{-37.1667,42}}, color={
          0,0,127}));
  connect(accelerometer.frame_a, gPS.frame_a) annotation (Line(
      points={{8,-40},{46,-40},{46,-18},{8,-18}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModule_SynchronousPower.Height, const1.y) annotation (Line(
        points={{-44.6667,24},{-44,24},{-44,16},{-42.6,16}}, color={0,0,127}));
  connect(accelerometer.y, controlModule_SynchronousPower.Gyero) annotation (
      Line(points={{-13,-40},{-49.6667,-40},{-49.6667,24}}, color={0,0,127}));
  connect(gPS.y, controlModule_SynchronousPower.GPS) annotation (Line(points={{-13,-18},
          {-54.6667,-18},{-54.6667,24}},          color={0,0,127}));
  connect(propeller_DCMachine_Power1.position, controlModule_SynchronousPower.y)
    annotation (Line(points={{-10,40},{-24,40},{-24,38},{-37.1667,38}}, color={
          0,0,127}));
  connect(propeller_DCMachine_Power1.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,46},{-14,46},{-14,60},{-8.4,60}}, color={0,0,
          255}));
  connect(propeller_DCMachine_Power2.position, controlModule_SynchronousPower.y2)
    annotation (Line(points={{-10,26},{-24,26},{-24,34},{-37.1667,34}}, color={
          0,0,127}));
  connect(controlModule_SynchronousPower.y3, propeller_DCMachine_Power3.position)
    annotation (Line(points={{-37.1667,30},{-24,30},{-24,12},{-10,12}}, color={
          0,0,127}));
  connect(propeller_DCMachine_Power3.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,18},{-16,18},{-16,46},{-14,46},{-14,60},{
          -8.4,60}}, color={0,0,255}));
  connect(propeller_DCMachine_Power2.p1, propeller_DCMachine_Power.p1)
    annotation (Line(points={{-8.4,32},{-16,32},{-16,46},{-14,46},{-14,60},{
          -8.4,60}}, color={0,0,255}));
  connect(const2.y, controlModule_SynchronousPower.yaw)
    annotation (Line(points={{-69.4,44},{-59.6667,44}}, color={0,0,127}));
  connect(ramp.y, realExtendMultiple.u2) annotation (Line(points={{-145,-36},{
          -134,-36},{-134,-28},{-122,-28}}, color={0,0,127}));
  connect(realExtendMultiple.y, controlModule_SynchronousPower.position)
    annotation (Line(points={{-101,-22},{-74,-22},{-74,36},{-59.6667,36}},
        color={0,0,127}));
  connect(realExtendMultiple.u, const5.y) annotation (Line(points={{-122,-16},{
          -136,-16},{-136,0},{-149.4,0}}, color={0,0,127}));
  connect(realExtendMultiple.u1, const5.y) annotation (Line(points={{-122,-22},
          {-136,-22},{-136,0},{-149.4,0}}, color={0,0,127}));
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
      points={{93,34},{94,34},{94,-18},{8,-18}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine.position,controlModule. y1) annotation (Line(
        points={{4,-68.8},{-6,-68.8},{-6,-78},{-13.1667,-78}},
                                                         color={0,0,127}));
  connect(controlModule.position,realExtendMultiple. y) annotation (Line(
        points={{-35.6667,-84},{-70,-84},{-70,-22},{-101,-22}},
                                                      color={0,0,127}));
  connect(gPS1.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{26,-134},{32,-134},{32,-92},{40,-92}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS1.y, controlModule.GPS) annotation (Line(points={{5,-134},{
          -30.6667,-134},{-30.6667,-96}}, color={0,0,127}));
  connect(accelerometer1.frame_a, droneChassis1.frame_a3) annotation (Line(
      points={{26,-154},{32,-154},{32,-92},{40,-92}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer1.y, controlModule.Gyero) annotation (Line(points={{5,-154},
          {-25.6667,-154},{-25.6667,-96}},       color={0,0,127}));
  connect(controlModule.Height,const3. y) annotation (Line(points={{-20.6667,
          -96},{-20.6667,-120},{-14.6,-120}},
                                color={0,0,127}));
  connect(propeller_DCMachine1.position,controlModule. y) annotation (Line(
        points={{4,-78.8},{-4.1,-78.8},{-4.1,-82},{-13.1667,-82}},
                                                           color={0,0,127}));
  connect(propeller_DCMachine.Airframe,droneChassis1. frame_a1) annotation (
      Line(
      points={{26.2,-69.6},{33.1,-69.6},{33.1,-80},{40,-80}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine1.Airframe,droneChassis1. frame_a) annotation (
      Line(
      points={{26.2,-79.6},{32.1,-79.6},{32.1,-84},{40,-84}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine2.Airframe,droneChassis1. frame_a2) annotation (
      Line(
      points={{26.2,-89.6},{32.1,-89.6},{32.1,-88},{40,-88}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine2.position,controlModule. y2) annotation (Line(
        points={{4,-88.8},{-13.1667,-88.8},{-13.1667,-86}},
                                                         color={0,0,127}));
  connect(propeller_DCMachine3.Airframe,droneChassis1. frame_a3) annotation (
      Line(
      points={{26.2,-99.6},{32,-99.6},{32,-92},{40,-92}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine3.position,controlModule. y3) annotation (Line(
        points={{4,-98.8},{-13.1667,-98.8},{-13.1667,-90}},color={0,0,127}));
  connect(controlModule.yaw, const4.y) annotation (Line(points={{-35.6667,-76},
          {-42,-76},{-42,-66},{-49.4,-66}}, color={0,0,127}));
  connect(constantVoltage.p, propeller_DCMachine_Power.p1) annotation (Line(
        points={{-8,80},{-14,80},{-14,60},{-8.4,60}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-180,
            -180},{100,100}})),                                  Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-180,-180},{100,
            100}})),
    experiment(StopTime=10));
end test;
