within DroneSimulation.Examples.DroneWithIdealPower;
model Drone_IdealMachine_SynchronousPID
  "Drone with ideal machine and a synchronous PID controller using synchronous library"

  extends DroneSimulation.Examples.Drone_Template;

  parameter Boolean animation=true "= true, if animation shall be enabled";
  Mechanical.Propeller.Examples.Propeller
    propeller_DCMachine_Power(animation=animation, PropellerGain=1)
         annotation (Placement(transformation(extent={{-8,14},{12,24}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-2,-54})));
  Electrical.controlModule_Synchronous
                           controlModule_Synchronous2_1(maxTilt=0.05,
      samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-58,-10},{-38,10}})));
  Modelica.Blocks.Sources.Constant const2(k=0)
    annotation (Placement(transformation(extent={{-84,16},{-72,28}})));
  Mechanical.Propeller.Examples.Propeller
    propeller_DCMachine_Power1(animation=animation)
    annotation (Placement(transformation(extent={{-8,2},{12,12}})));
  Mechanical.Propeller.Examples.Propeller
    propeller_DCMachine_Power2(animation=animation, PropellerGain=1)
         annotation (Placement(transformation(extent={{-8,-12},{12,-2}})));
  Mechanical.Propeller.Examples.Propeller
    propeller_DCMachine_Power3(animation=animation)
    annotation (Placement(transformation(extent={{-8,-26},{12,-16}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis2(
    animation=animation,
    length=0.25,
    m=0.5)
    annotation (Placement(transformation(extent={{48,-12},{98,8}})));
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,-1})
    annotation (Placement(transformation(extent={{62,52},{82,72}})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{-12,-84},{8,-64}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-88,-10},{-68,10}})));
  Modelica.Blocks.Sources.Ramp ramp(height=2.5, duration=0)
    annotation (Placement(transformation(extent={{-60,40},{-40,60}})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(gPS.y,controlModule_Synchronous2_1. GPS) annotation (Line(points={{-13,-54},
          {-54.3636,-54},{-54.3636,-12}},          color={0,0,127}));
  connect(const2.y,controlModule_Synchronous2_1. yaw) annotation (Line(points={{-71.4,
          22},{-64,22},{-64,8},{-59.8182,8}},        color={0,0,127}));
  connect(droneChassis2.frame_a1,propeller_DCMachine_Power. Airframe)
    annotation (Line(
      points={{48,4},{40,4},{40,17},{12.2,17}},
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
  connect(droneChassis2.frame_a4,gPS. frame_a) annotation (Line(
      points={{73,-12},{72,-12},{72,-54},{8,-54}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.frame_a,gPS. frame_a) annotation (Line(
      points={{8,-74},{72,-74},{72,-54},{8,-54}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y,controlModule_Synchronous2_1. Gyero) annotation (Line(
        points={{-13,-74},{-48.9091,-74},{-48.9091,-12}}, color={0,0,127}));
  connect(controlModule_Synchronous2_1.position,realExtendMultiple. y)
    annotation (Line(points={{-59.8182,0},{-67,0}}, color={0,0,127}));
  connect(propeller_DCMachine_Power.position,controlModule_Synchronous2_1. y1)
    annotation (Line(points={{-10.2,18},{-24,18},{-24,6},{-37.0909,6}},
                                                                      color={0,
          0,127}));
  connect(propeller_DCMachine_Power1.position,controlModule_Synchronous2_1. y)
    annotation (Line(points={{-10.2,6},{-24,6},{-24,2},{-37.0909,2}},
                                                                    color={0,0,
          127}));
  connect(controlModule_Synchronous2_1.y2,propeller_DCMachine_Power2. position)
    annotation (Line(points={{-37.0909,-2},{-22,-2},{-22,-8},{-10.2,-8}}, color=
         {0,0,127}));
  connect(propeller_DCMachine_Power3.position,controlModule_Synchronous2_1. y3)
    annotation (Line(points={{-10.2,-22},{-23,-22},{-23,-6},{-37.0909,-6}},
                                                                          color=
         {0,0,127}));
  connect(xcoord, realExtendMultiple.u) annotation (Line(points={{-120,80},{-94,
          80},{-94,6},{-88,6}}, color={0,0,127}));
  connect(realExtendMultiple.u1, ycoord)
    annotation (Line(points={{-88,0},{-120,0}}, color={0,0,127}));
  connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-88,-6},{-96,
          -6},{-96,-80},{-120,-80}}, color={0,0,127}));
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
    __Dymola_Commands(file="modelica://DroneSimulation/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"),
     experiment(StopTime=10));
end Drone_IdealMachine_SynchronousPID;
