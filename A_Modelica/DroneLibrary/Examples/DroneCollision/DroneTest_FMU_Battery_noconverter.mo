within DroneLibrary.Examples.DroneCollision;
model DroneTest_FMU_Battery_noconverter
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
    PropellerGain=1,
    VaNominal=15,
    IaNominal=50,
    V=V,
    animation=animation)
         annotation (Placement(transformation(extent={{-8,14},{12,24}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{-92,-140},{-72,-120}})));
  Sensors.GPS gPS_collision
                  annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={2,-40})));
  Electrical.controlModule controlModule_Power(
    maxTilt=0.05, samplePeriod=0.001,
    z_kp=2)
    annotation (Placement(transformation(extent={{-58,-10},{-38,10}})));
  Modelica.Blocks.Sources.Constant const2(k=0)
    annotation (Placement(transformation(extent={{-84,16},{-72,28}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power1(
    VaNominal=15,
    IaNominal=50, V=V,
    animation=animation)
    annotation (Placement(transformation(extent={{-8,0},{12,10}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power2(
    PropellerGain=1,
    VaNominal=15,
    IaNominal=50,
    V=V,
    animation=animation)
         annotation (Placement(transformation(extent={{-8,-12},{12,-2}})));
  Mechanical.Propeller.Examples.Propeller_DCMachine_Power
    propeller_DCMachine_Power3(
    VaNominal=15,
    IaNominal=50, V=V,
    animation=animation)
    annotation (Placement(transformation(extent={{-8,-26},{12,-16}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis2(
    length=0.5,
    m=0.5,
    animation=animation)
    annotation (Placement(transformation(extent={{48,-12},{98,8}})));
  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,-1})
    annotation (Placement(transformation(extent={{62,52},{82,72}})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{-8,-70},{12,-50}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-88,-10},{-68,10}})));

  parameter Boolean animation=true "= true, if animation shall be enabled";
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1 annotation (
      Placement(transformation(
        extent={{-16,-16},{16,16}},
        rotation=90,
        origin={72,-102})));
  Electrical.Sources.Battery battery(
    internal_ground=false,
    SOC_start=1,
    ns=6)
    annotation (Placement(transformation(extent={{18,-18},{-18,18}},
        rotation=270,
        origin={-82,-80})));
equation
  gPS_collision.y[1] = xgps;
  gPS_collision.y[2] = ygps;
  gPS_collision.y[3] = zgps;
  connect(gPS_collision.y, controlModule_Power.GPS) annotation (Line(points={{-9,-40},{-54.6667,-40},{-54.6667,-12}},
                                                  color={0,0,127}));
  connect(propeller_DCMachine_Power1.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,8},{-16,8},{-16,22},{-8.4,22}}, color={0,0,
          255}));
  connect(propeller_DCMachine_Power2.position, controlModule_Power.y2)
    annotation (Line(points={{-10,-10},{-24,-10},{-24,-2},{-37.1667,-2}}, color=
         {0,0,127}));
  connect(controlModule_Power.y3, propeller_DCMachine_Power3.position)
    annotation (Line(points={{-37.1667,-6},{-28,-6},{-28,-24},{-10,-24}}, color=
         {0,0,127}));
  connect(propeller_DCMachine_Power3.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,-18},{-16,-18},{-16,22},{-8.4,22}},
                     color={0,0,255}));
  connect(propeller_DCMachine_Power2.p1,propeller_DCMachine_Power. p1)
    annotation (Line(points={{-8.4,-4},{-16,-4},{-16,22},{-8.4,22}},
                     color={0,0,255}));
  connect(const2.y, controlModule_Power.yaw) annotation (Line(points={{-71.4,22},{-64,22},{-64,8},{-59.6667,8}},
                                          color={0,0,127}));
  connect(droneChassis2.frame_a1,propeller_DCMachine_Power. Airframe)
    annotation (Line(
      points={{48,4},{40,4},{40,17},{12.2,17}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis2.frame_a,propeller_DCMachine_Power1. Airframe)
    annotation (Line(
      points={{48,0},{38,0},{38,3},{12.2,3}},
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
  connect(droneChassis2.frame_a4, gPS_collision.frame_a) annotation (Line(
      points={{73,-12},{72,-12},{72,-40},{12,-40}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.frame_a, gPS_collision.frame_a) annotation (Line(
      points={{12,-60},{72,-60},{72,-40},{12,-40}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule_Power.Gyero) annotation (Line(points={{-9,-60},{-49.6667,-60},{-49.6667,-12}},
                                                   color={0,0,127}));
  connect(controlModule_Power.position, realExtendMultiple.y)
    annotation (Line(points={{-59.6667,0},{-67,0}}, color={0,0,127}));
  connect(realExtendMultiple.u1, ycoord)
    annotation (Line(points={{-88,0},{-120,0}}, color={0,0,127}));
  connect(realExtendMultiple.u, xcoord) annotation (Line(points={{-88,6},{-98,6},
          {-98,80},{-120,80}}, color={0,0,127}));
  connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-88,-6},{-96,
          -6},{-96,-80},{-120,-80}}, color={0,0,127}));
  connect(controlModule_Power.y1, propeller_DCMachine_Power.position)
    annotation (Line(points={{-37.1667,6},{-23.5833,6},{-23.5833,16},{-10,16}},
        color={0,0,127}));
  connect(propeller_DCMachine_Power1.position, controlModule_Power.y)
    annotation (Line(points={{-10,2},{-37.1667,2}}, color={0,0,127}));
  connect(droneChassis2.frame_a4, frame_a1) annotation (Line(
      points={{73,-12},{72,-12},{72,-102}},
      color={95,95,95},
      thickness=0.5));
  connect(battery.pin_n, ground.p) annotation (Line(points={{-67,-86},{-70,-86},
          {-70,-120},{-82,-120}}, color={0,0,255}));
  connect(battery.pin_p, propeller_DCMachine_Power.p1) annotation (Line(points=
          {{-67,-74},{-16,-18},{-16,22},{-8.4,22}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -120},{100,100}}), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={215,215,215},
          lineThickness=1), Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}),
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"));
end DroneTest_FMU_Battery_noconverter;
