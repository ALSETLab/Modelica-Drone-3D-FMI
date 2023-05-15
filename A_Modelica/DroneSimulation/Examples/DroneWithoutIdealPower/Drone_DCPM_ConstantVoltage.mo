within DroneSimulation.Examples.DroneWithoutIdealPower;
model Drone_DCPM_ConstantVoltage
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

  parameter Modelica.Units.SI.Voltage V "Battery voltage";
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power(
    IaNominal=50,
    animation=animation,
    PropellerGain=1,
    VaNominal=15.2,
    V=V) annotation (Placement(transformation(extent={{-8,16},{12,26}})));
  Modelica.Electrical.Analog.Sources.ConstantVoltage constantVoltage(V=V)
    annotation (Placement(transformation(extent={{-8,36},{12,56}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{16,20},{36,40}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-2,-54})));
  Electrical.controlModule_Synchronous
                           controlModule_Synchronous2_1(
    maxTilt=0.05, samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-58,-10},{-38,10}})));
  Modelica.Blocks.Sources.Constant const2(k=0)
    annotation (Placement(transformation(extent={{-84,16},{-72,28}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power1(
    IaNominal=50,
    animation=animation,
    VaNominal=15.2,                          V=V)
    annotation (Placement(transformation(extent={{-8,2},{12,12}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power2(
    IaNominal=50,
    animation=animation,
    PropellerGain=1,
    VaNominal=15.2,
    V=V) annotation (Placement(transformation(extent={{-8,-12},{12,-2}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power3(
    IaNominal=50,
    animation=animation,
    VaNominal=15.2,                          V=V)
    annotation (Placement(transformation(extent={{-8,-26},{12,-16}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis2(
    animation=animation,                                 length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{48,-12},{98,8}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,-1})
    annotation (Placement(transformation(extent={{62,52},{82,72}})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{-12,-84},{8,-64}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-88,-10},{-68,10}})));

  parameter Boolean animation=true "= true, if animation shall be enabled";
  Modelica.Blocks.Sources.Ramp     ramp(height=2.5, duration=0)
    annotation (Placement(transformation(extent={{-60,40},{-40,60}})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(constantVoltage.n,ground. p)
    annotation (Line(points={{12,46},{22,46},{22,40},{26,40}},
                                               color={0,0,255}));
  connect(gPS.y, controlModule_Synchronous2_1.GPS) annotation (Line(points={{-13,-54},{-54.3636,-54},{-54.3636,-12}},
                                                   color={0,0,127}));
  connect(propeller_DCMachine_Power1.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,10},{-16,10},{-16,24},{-8.4,24}}, color={0,0,
          255}));
  connect(propeller_DCMachine_Power3.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,-18},{-16,-18},{-16,24},{-8.4,24}},
                     color={0,0,255}));
  connect(propeller_DCMachine_Power2.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,-4},{-16,-4},{-16,24},{-8.4,24}},
                     color={0,0,255}));
  connect(const2.y, controlModule_Synchronous2_1.yaw) annotation (Line(points={{-71.4,22},{-64,22},{-64,8},{-59.8182,8}},
                                                     color={0,0,127}));
  connect(droneChassis2.frame_a1,propeller_DCMachine_Power. Airframe)
    annotation (Line(
      points={{48,4},{40,4},{40,19},{12.2,19}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a,propeller_DCMachine_Power1. Airframe)
    annotation (Line(
      points={{48,0},{38,0},{38,5},{12.2,5}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a2,propeller_DCMachine_Power2. Airframe)
    annotation (Line(
      points={{48,-4},{36,-4},{36,-9},{12.2,-9}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a3,propeller_DCMachine_Power3. Airframe)
    annotation (Line(
      points={{48,-8},{42,-8},{42,-23},{12.2,-23}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a4, gPS.frame_a) annotation (Line(
      points={{73,-12},{72,-12},{72,-54},{8,-54}},
      color={95,95,95},
      thickness=0.5));
  connect(constantVoltage.p, propeller_DCMachine_Power.p1) annotation (Line(
        points={{-8,46},{-16,46},{-16,24},{-8.4,24}}, color={0,0,255}));
  connect(accelerometer.frame_a, gPS.frame_a) annotation (Line(
      points={{8,-74},{72,-74},{72,-54},{8,-54}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule_Synchronous2_1.Gyero) annotation (Line(
        points={{-13,-74},{-48.9091,-74},{-48.9091,-12}}, color={0,0,127}));
  connect(controlModule_Synchronous2_1.position, realExtendMultiple.y)
    annotation (Line(points={{-59.8182,0},{-67,0}}, color={0,0,127}));
  connect(realExtendMultiple.u1, ycoord)
    annotation (Line(points={{-88,0},{-120,0}}, color={0,0,127}));
  connect(realExtendMultiple.u, xcoord) annotation (Line(points={{-88,6},{-98,6},
          {-98,80},{-120,80}}, color={0,0,127}));
  connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-88,-6},{-96,
          -6},{-96,-80},{-120,-80}}, color={0,0,127}));
  connect(propeller_DCMachine_Power.position, controlModule_Synchronous2_1.y1)
    annotation (Line(points={{-10,18},{-24,18},{-24,6},{-37.0909,6}}, color={0,
          0,127}));
  connect(propeller_DCMachine_Power1.position, controlModule_Synchronous2_1.y)
    annotation (Line(points={{-10,4},{-24,4},{-24,2},{-37.0909,2}}, color={0,0,
          127}));
  connect(controlModule_Synchronous2_1.y2, propeller_DCMachine_Power2.position)
    annotation (Line(points={{-37.0909,-2},{-22,-2},{-22,-10},{-10,-10}}, color=
         {0,0,127}));
  connect(propeller_DCMachine_Power3.position, controlModule_Synchronous2_1.y3)
    annotation (Line(points={{-10,-24},{-23,-24},{-23,-6},{-37.0909,-6}}, color=
         {0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={28,108,200},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={215,215,215},
          lineThickness=1), Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/Otus.jpg")}),
                                                                 Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    __Dymola_Commands(file="drone_animation_setup.mos" "drone_animation_setup"));
end Drone_DCPM_ConstantVoltage;
