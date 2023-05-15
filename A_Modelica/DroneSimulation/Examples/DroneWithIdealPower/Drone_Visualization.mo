within DroneSimulation.Examples.DroneWithIdealPower;
model Drone_Visualization "Model to use for animation and visualization."
  extends DroneSimulation.Examples.Drone_Template;

  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Electrical.controlModule_Synchronous
                           controlModule_Synchronous(
                                         maxTilt=0.05, samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
  Mechanical.Chassis.Examples.droneChassis_Visualization
    droneChassis_Visualization(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{44,-12},{94,8}})));
  Mechanical.Propeller.Examples.DCMachine_Visualization
    propeller_DCMachine_Visualization(PropellerGain=1)
    annotation (Placement(transformation(extent={{10,12},{30,20}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-74,-10},{-54,10}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={20,-50})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{10,-80},{30,-60}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{2,-42},{-10,-30}})));
  Mechanical.Propeller.Examples.DCMachine_Visualization
    propeller_DCMachine_Visualization2
    annotation (Placement(transformation(extent={{10,2},{30,10}})));
  Mechanical.Propeller.Examples.DCMachine_Visualization
    propeller_DCMachine_Visualization3(PropellerGain=1)
    annotation (Placement(transformation(extent={{10,-8},{30,0}})));
  Mechanical.Propeller.Examples.DCMachine_Visualization
    propeller_DCMachine_Visualization1
    annotation (Placement(transformation(extent={{10,-18},{30,-10}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=0,
        origin={-44,8})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1 annotation (
      Placement(transformation(
        extent={{-16,-16},{16,16}},
        rotation=90,
        origin={70,-102})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(propeller_DCMachine_Visualization.position, controlModule_Synchronous.y1)
    annotation (Line(points={{8,15.2},{-2,15.2},{-2,6},{-9.09091,6}}, color={0,
          0,127}));
  connect(controlModule_Synchronous.position, realExtendMultiple.y)
    annotation (Line(points={{-31.8182,0},{-53,0}}, color={0,0,127}));
  connect(gPS.frame_a, droneChassis_Visualization.frame_a3) annotation (Line(
      points={{30,-50},{36,-50},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.y, controlModule_Synchronous.GPS) annotation (Line(points={{9,-50},{-26.3636,-50},{-26.3636,-12}},
                                          color={0,0,127}));
  connect(accelerometer.frame_a, droneChassis_Visualization.frame_a3)
    annotation (Line(
      points={{30,-70},{36,-70},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule_Synchronous.Gyero) annotation (Line(
        points={{9,-70},{-20.9091,-70},{-20.9091,-12}}, color={0,0,127}));
  connect(controlModule_Synchronous.Height, const1.y) annotation (Line(points={{-14,-12},
          {-14,-36},{-10.6,-36}},                     color={0,0,127}));
  connect(propeller_DCMachine_Visualization2.position,
    controlModule_Synchronous.y) annotation (Line(points={{8,5.2},{-0.1,5.2},{-0.1,
          2},{-9.09091,2}},      color={0,0,127}));
  connect(propeller_DCMachine_Visualization.Airframe,
    droneChassis_Visualization.frame_a1) annotation (Line(
      points={{30.2,14.4},{37.1,14.4},{37.1,4},{44,4}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine_Visualization2.Airframe,
    droneChassis_Visualization.frame_a) annotation (Line(
      points={{30.2,4.4},{36.1,4.4},{36.1,0},{44,0}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine_Visualization3.Airframe,
    droneChassis_Visualization.frame_a2) annotation (Line(
      points={{30.2,-5.6},{36.1,-5.6},{36.1,-4},{44,-4}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine_Visualization3.position,
    controlModule_Synchronous.y2) annotation (Line(points={{8,-4.8},{-9.09091,-4.8},
          {-9.09091,-2}},       color={0,0,127}));
  connect(propeller_DCMachine_Visualization1.Airframe,
    droneChassis_Visualization.frame_a3) annotation (Line(
      points={{30.2,-15.6},{36,-15.6},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine_Visualization1.position,
    controlModule_Synchronous.y3) annotation (Line(points={{8,-14.8},{-9.09091,-14.8},
          {-9.09091,-6}},        color={0,0,127}));
  connect(controlModule_Synchronous.yaw, const.y)
    annotation (Line(points={{-31.8182,8},{-39.6,8}}, color={0,0,127}));
  connect(droneChassis_Visualization.frame_a4, frame_a1) annotation (Line(
      points={{69,-12},{70,-12},{70,-102}},
      color={95,95,95},
      thickness=0.5));
  connect(xcoord, realExtendMultiple.u) annotation (Line(points={{-120,80},{-80,
          80},{-80,6},{-74,6}}, color={0,0,127}));
  connect(realExtendMultiple.u1, ycoord)
    annotation (Line(points={{-74,0},{-120,0}}, color={0,0,127}));
  connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-74,-6},{-94,
          -6},{-94,-80},{-120,-80}}, color={0,0,127}));
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
    __Dymola_Commands(file="drone_animation_setup.mos" "drone_animation_setup"),
     experiment(StopTime=10));
end Drone_Visualization;
