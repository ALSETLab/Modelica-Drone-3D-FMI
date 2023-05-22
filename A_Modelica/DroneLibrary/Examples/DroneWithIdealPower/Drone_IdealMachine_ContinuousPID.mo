within DroneLibrary.Examples.DroneWithIdealPower;
model Drone_IdealMachine_ContinuousPID
  "Drone with ideal machine controlled by a PID controller with continuous sampling"
  extends DroneLibrary.Examples.Drone_Template;

  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis1(length=0.25, m=0.5,
    animation=animation)
    annotation (Placement(transformation(extent={{44,-12},{94,8}})));
  Mechanical.Propeller.Examples.Propeller propeller( PropellerGain=1,
      animation=animation)
    annotation (Placement(transformation(extent={{10,14},{30,22}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-74,-10},{-54,10}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={20,-62})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{10,-92},{30,-72}})));
  Mechanical.Propeller.Examples.Propeller propeller2(animation=animation)
    annotation (Placement(transformation(extent={{10,2},{30,10}})));
  Mechanical.Propeller.Examples.Propeller propeller3( PropellerGain=1,
      animation=animation)
    annotation (Placement(transformation(extent={{10,-8},{30,0}})));
  Mechanical.Propeller.Examples.Propeller propeller1(animation=animation)
    annotation (Placement(transformation(extent={{10,-18},{30,-10}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        origin={-44,8})));
  parameter Boolean animation=true "= true, if animation shall be enabled";
  Electrical.controlModule_Continuous
                           controlModule_Continuous(
    maxTilt=0.05,
    samplePeriod=0.001,
    z_kd=2,
    gyro_x_ki=2,
    gyro_y_ki=2)
    annotation (Placement(transformation(extent={{-26,-14},{-6,6}})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(gPS.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-62},{36,-62},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-82},{36,-82},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller.Airframe, droneChassis1.frame_a1) annotation (Line(
      points={{30.2,16.4},{37.1,16.4},{37.1,4},{44,4}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller2.Airframe, droneChassis1.frame_a) annotation (Line(
      points={{30.2,4.4},{36.1,4.4},{36.1,0},{44,0}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller3.Airframe, droneChassis1.frame_a2) annotation (Line(
      points={{30.2,-5.6},{36.1,-5.6},{36.1,-4},{44,-4}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller1.Airframe, droneChassis1.frame_a3) annotation (Line(
      points={{30.2,-15.6},{36,-15.6},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModule_Continuous.yaw, const.y) annotation (Line(points={{-27.6667,4},{-34,4},{-34,8},{-39.6,8}},
                                                  color={0,0,127}));
  connect(realExtendMultiple.y, controlModule_Continuous.position) annotation (
      Line(points={{-53,0},{-34,0},{-34,-4},{-27.6667,-4}}, color={0,0,127}));
  connect(gPS.y, controlModule_Continuous.GPS) annotation (Line(points={{9,-62},{-22,-62},{-22,-16},{-22.6667,-16}},
                                               color={0,0,127}));
  connect(accelerometer.y, controlModule_Continuous.Gyero) annotation (Line(
        points={{9,-82},{-17.6667,-82},{-17.6667,-16}}, color={0,0,127}));
  connect(propeller.position, controlModule_Continuous.y1) annotation (Line(
        points={{7.8,17.2},{7.8,16},{0,16},{0,2},{-5.16667,2}}, color={0,0,127}));
  connect(propeller2.position, controlModule_Continuous.y) annotation (Line(
        points={{7.8,5.2},{7.8,-2},{-5.16667,-2}}, color={0,0,127}));
  connect(propeller3.position, controlModule_Continuous.y2) annotation (Line(
        points={{7.8,-4.8},{0,-4.8},{0,-6},{-5.16667,-6}}, color={0,0,127}));
  connect(propeller1.position, controlModule_Continuous.y3) annotation (Line(
        points={{7.8,-14.8},{0,-14.8},{0,-10},{-5.16667,-10}}, color={0,0,127}));
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
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/Otus.jpg")}),
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"),
     experiment(StopTime=10));
end Drone_IdealMachine_ContinuousPID;
