within DroneLibrary.Examples.Phantom;
model DroneTest_FMU_Synchronous
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
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
  Electrical.controlModule_Synchronous
                           controlModule_Synchronous(
                                         maxTilt=0.05, samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
  Mechanical.Chassis.Examples.MavicAir mavicAir_droneChassis(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{44,-12},{94,8}})));
  Mechanical.Propeller.Examples.Phantom phantom_propeller
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
  Mechanical.Propeller.Examples.Phantom phantom_propeller1(PropellerGain=1)
    annotation (Placement(transformation(extent={{10,2},{30,10}})));
  Mechanical.Propeller.Examples.Phantom phantom_propeller2
    annotation (Placement(transformation(extent={{10,-8},{30,0}})));
  Mechanical.Propeller.Examples.Phantom phantom_propeller3(PropellerGain=1)
    annotation (Placement(transformation(extent={{10,-18},{30,-10}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        origin={-44,8})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(phantom_propeller.position, controlModule_Synchronous.y1) annotation (
     Line(points={{7.8,15.2},{-2,15.2},{-2,6},{-9.09091,6}}, color={0,0,127}));
  connect(controlModule_Synchronous.position, realExtendMultiple.y)
    annotation (Line(points={{-31.8182,0},{-53,0}}, color={0,0,127}));
  connect(gPS.y, controlModule_Synchronous.GPS) annotation (Line(points={{9,-50},{-26.3636,-50},{-26.3636,-12}},
                                          color={0,0,127}));
  connect(accelerometer.y, controlModule_Synchronous.Gyero) annotation (Line(
        points={{9,-70},{-20.9091,-70},{-20.9091,-12}}, color={0,0,127}));
  connect(controlModule_Synchronous.Height, const1.y) annotation (Line(points={{
          -16.6667,-12},{-16.6667,-36},{-10.6,-36}}, color={0,0,127}));
  connect(phantom_propeller1.position, controlModule_Synchronous.y) annotation (
     Line(points={{7.8,5.2},{-0.1,5.2},{-0.1,2},{-9.09091,2}}, color={0,0,127}));
  connect(phantom_propeller2.position, controlModule_Synchronous.y2)
    annotation (Line(points={{7.8,-4.8},{-9.09091,-4.8},{-9.09091,-2}}, color={
          0,0,127}));
  connect(phantom_propeller3.position, controlModule_Synchronous.y3)
    annotation (Line(points={{7.8,-14.8},{-9.09091,-14.8},{-9.09091,-6}}, color=
         {0,0,127}));
  connect(controlModule_Synchronous.yaw, const.y)
    annotation (Line(points={{-31.8182,8},{-39.6,8}}, color={0,0,127}));
   connect(realExtendMultiple.u, xcoord) annotation (Line(points={{-74,6},{-88,
           6},{-88,80},{-120,80}}, color={0,0,127}));
   connect(realExtendMultiple.u1, ycoord)
     annotation (Line(points={{-74,0},{-120,0}}, color={0,0,127}));
   connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-74,-6},{
           -90,-6},{-90,-80},{-120,-80}}, color={0,0,127}));
  connect(mavicAir_droneChassis.frame_a2, phantom_propeller2.Airframe)
    annotation (Line(
      points={{44,-4},{38,-4},{38,-5.6},{30.2,-5.6}},
      color={95,95,95},
      thickness=0.5));
  connect(phantom_propeller1.Airframe, mavicAir_droneChassis.frame_a)
    annotation (Line(
      points={{30.2,4.4},{37.1,4.4},{37.1,0},{44,0}},
      color={95,95,95},
      thickness=0.5));
  connect(mavicAir_droneChassis.frame_a1, phantom_propeller.Airframe)
    annotation (Line(
      points={{44,4},{38,4},{38,14.4},{30.2,14.4}},
      color={95,95,95},
      thickness=0.5));
  connect(phantom_propeller3.Airframe, mavicAir_droneChassis.frame_a3)
    annotation (Line(
      points={{30.2,-15.6},{37.1,-15.6},{37.1,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.frame_a, mavicAir_droneChassis.frame_a3) annotation (Line(
      points={{30,-50},{34,-50},{34,-44},{38,-44},{38,-16},{36,-16},{36,-15.6},
          {37.1,-15.6},{37.1,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.frame_a, mavicAir_droneChassis.frame_a3) annotation (
      Line(
      points={{30,-70},{36,-70},{36,-72},{38,-72},{38,-16},{36,-16},{36,-15.6},
          {37.1,-15.6},{37.1,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={215,215,215},
          lineThickness=1), Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}),
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"));
end DroneTest_FMU_Synchronous;
