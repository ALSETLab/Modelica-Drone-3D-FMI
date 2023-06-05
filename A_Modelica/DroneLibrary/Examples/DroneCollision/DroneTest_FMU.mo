within DroneLibrary.Examples.DroneCollision;
model DroneTest_FMU
  inner Modelica.Mechanics.MultiBody.World world(n = {0,0,
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
  Electrical.controlModule controlModule_Synchronous(
                                         maxTilt=0.05, samplePeriod=0.001)
    annotation (Placement(transformation(extent={{-30,-8},{-10,12}})));
  Mechanical.Chassis.Variants.droneChassis droneChassis1(length=0.25, m=0.5) annotation (Placement(transformation(extent={{44,-12},{94,8}})));
  Mechanical.Propeller.Variants.Propeller propellerRev(PropellerGain=1, animation=animation) annotation (Placement(transformation(extent={{10,12},{30,20}})));
  Blocks.Routing.RealExtendMultiple realExtendMultiple
    annotation (Placement(transformation(extent={{-74,-10},{-54,10}})));
  Sensors.GPS gPS annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={20,-62})));
  Sensors.Accelerometer accelerometer
    annotation (Placement(transformation(extent={{10,-92},{30,-72}})));
  Mechanical.Propeller.Variants.Propeller propellerRev1(animation=animation) annotation (Placement(transformation(extent={{10,2},{30,10}})));
  Mechanical.Propeller.Variants.Propeller propellerRev2(PropellerGain=1, animation=animation) annotation (Placement(transformation(extent={{10,-8},{30,0}})));
  Mechanical.Propeller.Variants.Propeller propellerRev3(animation=animation) annotation (Placement(transformation(extent={{10,-18},{30,-10}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        origin={-44,8})));
  parameter Boolean animation=true "= true, if animation shall be enabled";
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1 annotation (
      Placement(transformation(
        extent={{-16,-16},{16,16}},
        rotation=270,
        origin={70,-102})));
equation
  gPS.y[1] = xgps;
  gPS.y[2] = ygps;
  gPS.y[3] = zgps;
  connect(propellerRev.position, controlModule_Synchronous.y1) annotation (Line(
        points={{7.8,15.2},{-2,15.2},{-2,8},{-9.16667,8}}, color={0,0,127}));
  connect(controlModule_Synchronous.position, realExtendMultiple.y)
    annotation (Line(points={{-31.6667,2},{-42,2},{-42,0},{-53,0}},
                                                    color={0,0,127}));
  connect(gPS.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-62},{36,-62},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(gPS.y, controlModule_Synchronous.GPS) annotation (Line(points={{9,-62},{-26.6667,-62},{-26.6667,-10}},
                                          color={0,0,127}));
  connect(accelerometer.frame_a,droneChassis1. frame_a3) annotation (Line(
      points={{30,-82},{36,-82},{36,-8},{44,-8}},
      color={95,95,95},
      thickness=0.5));
  connect(accelerometer.y, controlModule_Synchronous.Gyero) annotation (Line(
        points={{9,-82},{-21.6667,-82},{-21.6667,-10}}, color={0,0,127}));
  connect(propellerRev1.position, controlModule_Synchronous.y) annotation (Line(
        points={{7.8,5.2},{-0.1,5.2},{-0.1,4},{-9.16667,4}}, color={0,0,127}));
   connect(propellerRev.Airframe,droneChassis1. frame_a1) annotation (Line(
       points={{30.2,14.4},{37.1,14.4},{37.1,4},{44,4}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev1.Airframe,droneChassis1. frame_a) annotation (Line(
       points={{30.2,4.4},{36.1,4.4},{36.1,0},{44,0}},
       color={95,95,95},
       thickness=0.5));
   connect(propellerRev2.Airframe,droneChassis1. frame_a2) annotation (Line(
       points={{30.2,-5.6},{36.1,-5.6},{36.1,-4},{44,-4}},
       color={95,95,95},
       thickness=0.5));
  connect(propellerRev2.position, controlModule_Synchronous.y2) annotation (
      Line(points={{7.8,-4.8},{-9.16667,-4.8},{-9.16667,0}}, color={0,0,127}));
   connect(propellerRev3.Airframe,droneChassis1. frame_a3) annotation (Line(
       points={{30.2,-15.6},{36,-15.6},{36,-8},{44,-8}},
       color={95,95,95},
       thickness=0.5));
  connect(propellerRev3.position, controlModule_Synchronous.y3) annotation (
      Line(points={{7.8,-14.8},{-9.16667,-14.8},{-9.16667,-4}}, color={0,0,127}));
  connect(controlModule_Synchronous.yaw, const.y)
    annotation (Line(points={{-31.6667,10},{-36,10},{-36,8},{-39.6,8}},
                                                      color={0,0,127}));
   connect(realExtendMultiple.u, xcoord) annotation (Line(points={{-74,6},{-88,
           6},{-88,80},{-120,80}}, color={0,0,127}));
   connect(realExtendMultiple.u1, ycoord)
     annotation (Line(points={{-74,0},{-120,0}}, color={0,0,127}));
   connect(realExtendMultiple.u2, zcoord) annotation (Line(points={{-74,-6},{
           -90,-6},{-90,-80},{-120,-80}}, color={0,0,127}));
  connect(droneChassis1.frame_a4, frame_a1) annotation (Line(
      points={{69,-12},{70,-12},{70,-102}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}}), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={215,215,215},
          lineThickness=1), Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}),
    __Dymola_Commands(file="modelica://DroneLibrary/Resources/Scripts/drone_animation_setup.mos" "drone_animation_setup"));
end DroneTest_FMU;
