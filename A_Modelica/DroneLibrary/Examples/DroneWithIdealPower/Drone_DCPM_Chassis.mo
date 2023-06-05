within DroneLibrary.Examples.DroneWithIdealPower;
model Drone_DCPM_Chassis
  "Drone with external chassis connection to add external loads. Drone has DC permanent magnent machines in drivetrain."
  extends DroneLibrary.Examples.Drone_Template;

  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,
      -1})
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  Electrical.controlModule_Synchronous
                           controlModule_Synchronous(
                                         maxTilt=0.05, samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
  Mechanical.Chassis.Examples.droneChassis droneChassis1(
    animation=animation, length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{44,-10},{94,10}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine(animation=
        animation, PropellerGain=1)
    annotation (Placement(transformation(extent={{10,14},{30,22}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-74,-10},{-54,10}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={20,-50})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{10,-80},{30,-60}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine1(animation=
        animation)
    annotation (Placement(transformation(extent={{10,4},{30,12}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine2(animation=
        animation, PropellerGain=1)
    annotation (Placement(transformation(extent={{10,-6},{30,2}})));
  Mechanical.Propeller.Examples.DCMachine propeller_DCMachine3(animation=
        animation)
    annotation (Placement(transformation(extent={{10,-16},{30,-8}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        origin={-44,8})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1 annotation (
      Placement(transformation(
        extent={{-16,-16},{16,16}},
        rotation=90,
        origin={70,-102})));
  parameter Boolean animation=true "= true, if animation shall be enabled";
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(propeller_DCMachine.position, controlModule_Synchronous.y1)
    annotation (Line(points={{8,17.2},{-2,17.2},{-2,6},{-9.09091,6}}, color={0,
          0,127}));
  connect(controlModule_Synchronous.position, realExtendMultiple.y)
    annotation (Line(points={{-31.8182,0},{-53,0}}, color={0,0,127}));
  connect(gPS.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-50},{36,-50},{36,-6},{44,-6}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.y, controlModule_Synchronous.GPS) annotation (Line(points={{9,-50},
          {-26.3636,-50},{-26.3636,-12}}, color={0,0,127}));
  connect(accelerometer.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-70},{36,-70},{36,-6},{44,-6}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule_Synchronous.Gyero) annotation (Line(
        points={{9,-70},{-20.9091,-70},{-20.9091,-12}}, color={0,0,127}));
  connect(propeller_DCMachine1.position, controlModule_Synchronous.y)
    annotation (Line(points={{8,7.2},{-0.1,7.2},{-0.1,2},{-9.09091,2}}, color={
          0,0,127}));
  connect(propeller_DCMachine.Airframe, droneChassis1.frame_a1) annotation (
      Line(
      points={{30.2,16.4},{37.1,16.4},{37.1,6},{44,6}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine1.Airframe, droneChassis1.frame_a) annotation (
      Line(
      points={{30.2,6.4},{36.1,6.4},{36.1,2},{44,2}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine2.Airframe, droneChassis1.frame_a2) annotation (
      Line(
      points={{30.2,-3.6},{36.1,-3.6},{36.1,-2},{44,-2}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine2.position, controlModule_Synchronous.y2)
    annotation (Line(points={{8,-2.8},{-9.09091,-2.8},{-9.09091,-2}}, color={0,
          0,127}));
  connect(propeller_DCMachine3.Airframe, droneChassis1.frame_a3) annotation (
      Line(
      points={{30.2,-13.6},{36,-13.6},{36,-6},{44,-6}},
      color={95,95,95},
      thickness=0.5));
  connect(propeller_DCMachine3.position, controlModule_Synchronous.y3)
    annotation (Line(points={{8,-12.8},{-9.09091,-12.8},{-9.09091,-6}}, color={
          0,0,127}));
  connect(controlModule_Synchronous.yaw, const.y)
    annotation (Line(points={{-31.8182,8},{-39.6,8}}, color={0,0,127}));
  connect(droneChassis1.frame_a4, frame_a1) annotation (Line(
      points={{69,-10},{70,-10},{70,-102}},
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
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/Otus.jpg")}),
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"),
     experiment(StopTime=10));
end Drone_DCPM_Chassis;
