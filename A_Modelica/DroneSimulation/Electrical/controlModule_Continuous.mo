within DroneSimulation.Electrical;
model controlModule_Continuous

  Modelica.Blocks.Interfaces.RealOutput y annotation (Placement(transformation(
          extent={{140,10},{160,30}}), iconTransformation(extent={{140,10},{160,
            30}})));
  Modelica.Blocks.Interfaces.RealOutput y1 annotation (Placement(transformation(
          extent={{140,50},{160,70}}), iconTransformation(extent={{140,50},{160,
            70}})));
  Modelica.Blocks.Interfaces.RealOutput y2 annotation (Placement(transformation(
          extent={{140,-30},{160,-10}}), iconTransformation(extent={{140,-30},{
            160,-10}})));
  Modelica.Blocks.Interfaces.RealOutput y3 annotation (Placement(transformation(
          extent={{140,-70},{160,-50}}), iconTransformation(extent={{140,-70},{
            160,-50}})));
  Modelica.Blocks.Interfaces.RealInput GPS[3] annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={-60,-100}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={-60,-120})));
  Modelica.Blocks.Interfaces.RealInput Gyero[3] annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={0,-100}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={0,-120})));
  Blocks.Control.continuousPID               continuousPID4(
    Ti=z_Ti,
    Td=z_Td,
    kp=z_kp)
    annotation (Placement(transformation(extent={{-38,-40},{-18,-20}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract(index=1)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Interfaces.RealInput position[3]
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract1(index=2)
    annotation (Placement(transformation(extent={{-80,-10},{-60,10}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract2(index=3)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Blocks.Control.continuousPID               continuousPID3(
    kp=y_kp,
    Ti=y_Ti,
    Td=y_Td)
    annotation (Placement(transformation(extent={{-40,-10},{-20,10}})));
  Blocks.Control.continuousPID               continuousPID1(
    kp=gyro_x_kp,
    Ti=gyro_x_Ti,
    Td=gyro_x_Td)
            annotation (Placement(transformation(extent={{46,20},{66,40}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract3(index=2)
    annotation (Placement(transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-72})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract4(index=2)
    annotation (Placement(transformation(extent={{-52,-68},{-44,-60}})));
  parameter Real maxTilt=2 "Upper limits of input signals";
  DroneSimulation.Blocks.Routing.RealExtract realExtract5
    annotation (Placement(transformation(extent={{-44,-76},{-36,-68}})));
  Blocks.Control.continuousPID               continuousPID(
    kp=x_kp,
    Ti=x_Ti,
    Td=x_Td)
    annotation (Placement(transformation(extent={{-40,20},{-20,40}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=0.523)
    annotation (Placement(transformation(extent={{0,20},{20,40}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract6(index=1)
    annotation (Placement(transformation(extent={{-60,-60},{-52,-52}})));
  Modelica.Blocks.Nonlinear.Limiter limiter1(uMax=0.523)
    annotation (Placement(transformation(extent={{0,-10},{20,10}})));
  Blocks.Control.continuousPID               continuousPID5(
    kp=gyro_y_kp,
    Ti=gyro_y_Ti,
    Td=gyro_y_Td)
            annotation (Placement(transformation(extent={{32,-10},{52,10}})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract7(index=1)
    annotation (Placement(transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-60})));
  DroneSimulation.Blocks.Routing.RealExtract realExtract8(index=3)
    annotation (Placement(transformation(
        extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-28,58})));
  Blocks.Control.continuousPID               continuousPID2(
    kp=Yaw_kp,
    Ti=Yaw_Ti,
    Td=Yaw_Td)
    annotation (Placement(transformation(extent={{-38,70},{-18,90}})));
  Modelica.Blocks.Nonlinear.Limiter limiter2(uMax=0.1)
    annotation (Placement(transformation(extent={{-2,70},{18,90}})));
  Modelica.Blocks.Interfaces.RealInput yaw
    annotation (Placement(transformation(extent={{-140,60},{-100,100}}),
        iconTransformation(extent={{-140,60},{-100,100}})));
  Modelica.Blocks.Math.Gain gain(k=-1)
    annotation (Placement(transformation(extent={{-14,-2},{-8,4}})));
  parameter Real Yaw_Ti=0 "I time constant for yaw" annotation (Dialog(group="Yaw PID"));
  parameter Real Yaw_Td=0.08 "D time constant for yaw" annotation (Dialog(group="Yaw PID"));
  parameter Real Yaw_kp=0.04 "P gain for yaw" annotation (Dialog(group="Yaw PID"));
  parameter Real x_Ti=0.03 "I time constant for x position" annotation (Dialog(group="X position PID"));
  parameter Real x_Td=0.1 "D time constant for x position" annotation (Dialog(group="X position PID"));
  parameter Real x_kp=0.1 "P gain for x position" annotation (Dialog(group="X position PID"));
  parameter Real y_Ti=0.03 "I time constant for y position" annotation (Dialog(group="Y position PID"));
  parameter Real y_Td=0.1 "D time constant for y position" annotation (Dialog(group="Y position PID"));
  parameter Real y_kp=0.1 "P gain for y position" annotation (Dialog(group="Y position PID"));
  parameter Real z_Ti=1 "I time constant for z position" annotation (Dialog(group="Z position PID"));
  parameter Real z_Td=0.8 "D time constant for z position" annotation (Dialog(group="Z position PID"));
  parameter Real z_kp=1.5 "P gain for z position" annotation (Dialog(group="Z position PID"));
  parameter Real gyro_x_Ti=0.3
    "I time constant for gyroscope measurements in the x direction" annotation (Dialog(group="Gyroscope PID"));
  parameter Real gyro_x_Td=1
    "D time constant for the gyroscope measurements in the x direction" annotation (Dialog(group="Gyroscope PID"));
  parameter Real gyro_x_kp=1
    "P gain for the gyroscope measurements in the x direction" annotation (Dialog(group="Gyroscope PID"));
  parameter Real gyro_y_Ti=0.1
    "I time constant for the gyroscope measurements in the y direction" annotation (Dialog(group="Gyroscope PID"));
  parameter Real gyro_y_Td=1
    "D time constant for the gyroscope measurements in the y direction" annotation (Dialog(group="Gyroscope PID"));
  parameter Real gyro_y_kp=1
    "P gain for the gyroscope measurements in the y direction" annotation (Dialog(group="Gyroscope PID"));
  Modelica.Blocks.Math.Add3 add3_2
    annotation (Placement(transformation(extent={{118,14},{130,26}})));
  Modelica.Blocks.Sources.RealExpression realExpression3(y=continuousPID4.y)
    annotation (Placement(transformation(extent={{76,14},{96,26}})));
  Modelica.Blocks.Sources.RealExpression realExpression4(y=limiter2.y)
    annotation (Placement(transformation(extent={{76,24},{96,34}})));
  Modelica.Blocks.Sources.RealExpression realExpression5(y=continuousPID1.y)
    annotation (Placement(transformation(extent={{76,4},{96,18}})));
  Modelica.Blocks.Math.Add3 add3_3(k1=-1)
    annotation (Placement(transformation(extent={{114,-26},{126,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression6(y=continuousPID4.y)
    annotation (Placement(transformation(extent={{78,-26},{98,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression7(y=limiter2.y)
    annotation (Placement(transformation(extent={{78,-16},{98,-6}})));
  Modelica.Blocks.Sources.RealExpression realExpression8(y=continuousPID5.y)
    annotation (Placement(transformation(extent={{78,-36},{98,-22}})));
  Modelica.Blocks.Math.Add3 add3_4(k3=-1)
    annotation (Placement(transformation(extent={{116,-66},{128,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression9(y=continuousPID4.y)
    annotation (Placement(transformation(extent={{80,-66},{100,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression10(y=limiter2.y)
    annotation (Placement(transformation(extent={{80,-56},{100,-46}})));
  Modelica.Blocks.Sources.RealExpression realExpression11(y=continuousPID1.y)
    annotation (Placement(transformation(extent={{80,-76},{100,-62}})));
  Modelica.Blocks.Math.Add3 add3_1(k1=-1, k3=-1)
    annotation (Placement(transformation(extent={{76,68},{88,80}})));
  Modelica.Blocks.Sources.RealExpression realExpression(y=continuousPID4.y)
    annotation (Placement(transformation(extent={{40,68},{60,80}})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=limiter2.y)
    annotation (Placement(transformation(extent={{40,78},{60,88}})));
  Modelica.Blocks.Sources.RealExpression realExpression2(y=continuousPID5.y)
    annotation (Placement(transformation(extent={{40,58},{60,72}})));
equation
  connect(position, realExtract.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,30},{-80,30}}, color={0,0,127}));
  connect(position, realExtract1.u)
    annotation (Line(points={{-120,0},{-80,0}}, color={0,0,127}));
  connect(position, realExtract2.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,-30},{-80,-30}},    color={0,0,127}));
  connect(realExtract2.y, continuousPID4.u)
    annotation (Line(points={{-59,-30},{-38,-30}}, color={0,0,127}));
  connect(realExtract1.y, continuousPID3.u)
    annotation (Line(points={{-59,0},{-40,0}}, color={0,0,127}));
  connect(GPS, realExtract4.u) annotation (Line(points={{-60,-100},{-60,-64},
          {-52,-64}}, color={0,0,127}));
  connect(realExtract3.y, continuousPID1.u1)
    annotation (Line(points={{18.4,-72},{56,-72},{56,20}}, color={0,0,127}));
  connect(realExtract4.y, continuousPID3.u1) annotation (Line(points={{-43.6,-64},
          {-4,-64},{-4,-16},{-30,-16},{-30,-10}}, color={0,0,127}));
  connect(GPS, realExtract5.u) annotation (Line(points={{-60,-100},{-60,-72},
          {-44,-72}}, color={0,0,127}));
  connect(realExtract5.y, continuousPID4.u1) annotation (Line(points={{-35.6,-72},
          {-28,-72},{-28,-40}}, color={0,0,127}));
  connect(Gyero, realExtract3.u)
    annotation (Line(points={{0,-100},{0,-72},{10,-72}}, color={0,0,127}));
  connect(continuousPID1.u, limiter.y)
    annotation (Line(points={{46,30},{21,30}}, color={0,0,127}));
  connect(realExtract.y, continuousPID.u)
    annotation (Line(points={{-59,30},{-40,30}}, color={0,0,127}));
  connect(realExtract6.u, GPS)
    annotation (Line(points={{-60,-56},{-60,-100}}, color={0,0,127}));
  connect(realExtract6.y, continuousPID.u1) annotation (Line(points={{-51.6,-56},
          {-46,-56},{-46,20},{-30,20}}, color={0,0,127}));
  connect(continuousPID.y, limiter.u)
    annotation (Line(points={{-19,30},{-2,30}}, color={0,0,127}));
  connect(limiter1.y, continuousPID5.u)
    annotation (Line(points={{21,0},{32,0}}, color={0,0,127}));
  connect(realExtract7.u, Gyero)
    annotation (Line(points={{10,-60},{0,-60},{0,-100}}, color={0,0,127}));
  connect(realExtract7.y, continuousPID5.u1)
    annotation (Line(points={{18.4,-60},{42,-60},{42,-10}}, color={0,0,127}));
  connect(realExtract8.u, Gyero) annotation (Line(points={{-28,54},{-14,54},
          {-14,-100},{0,-100}}, color={0,0,127}));
  connect(continuousPID2.y, limiter2.u)
    annotation (Line(points={{-17,80},{-4,80}}, color={0,0,127}));
  connect(continuousPID2.u1, realExtract8.y)
    annotation (Line(points={{-28,70},{-28,62.4}}, color={0,0,127}));
  connect(yaw, continuousPID2.u) annotation (Line(points={{-120,80},{-80,80},{-80,
          80},{-38,80}}, color={0,0,127}));
  connect(continuousPID3.y, gain.u) annotation (Line(points={{-19,0},{-18,0},{-18,
          1},{-14.6,1}}, color={0,0,127}));
  connect(limiter1.u, gain.y)
    annotation (Line(points={{-2,0},{-2,1},{-7.7,1}},   color={0,0,127}));
  connect(realExpression3.y,add3_2. u2)
    annotation (Line(points={{97,20},{116.8,20}},  color={0,0,127}));
  connect(add3_2.u1,realExpression4. y) annotation (Line(points={{116.8,24.8},{
          106,24.8},{106,29},{97,29}},
                                    color={0,0,127}));
  connect(add3_2.u3,realExpression5. y) annotation (Line(points={{116.8,15.2},{
          106,15.2},{106,11},{97,11}},
                                  color={0,0,127}));
  connect(realExpression6.y,add3_3. u2)
    annotation (Line(points={{99,-20},{112.8,-20}},  color={0,0,127}));
  connect(add3_3.u1,realExpression7. y) annotation (Line(points={{112.8,-15.2},
          {106,-15.2},{106,-11},{99,-11}}, color={0,0,127}));
  connect(add3_3.u3,realExpression8. y) annotation (Line(points={{112.8,-24.8},
          {106,-24.8},{106,-29},{99,-29}}, color={0,0,127}));
  connect(realExpression9.y,add3_4. u2)
    annotation (Line(points={{101,-60},{114.8,-60}}, color={0,0,127}));
  connect(add3_4.u1,realExpression10. y) annotation (Line(points={{114.8,-55.2},
          {108,-55.2},{108,-51},{101,-51}}, color={0,0,127}));
  connect(add3_4.u3,realExpression11. y) annotation (Line(points={{114.8,-64.8},
          {108,-64.8},{108,-69},{101,-69}}, color={0,0,127}));
  connect(realExpression.y,add3_1. u2)
    annotation (Line(points={{61,74},{74.8,74}}, color={0,0,127}));
  connect(add3_1.u1,realExpression1. y) annotation (Line(points={{74.8,78.8},{
          68,78.8},{68,83},{61,83}},
                                  color={0,0,127}));
  connect(add3_1.u3,realExpression2. y) annotation (Line(points={{74.8,69.2},{
          68,69.2},{68,65},{61,65}},
                                  color={0,0,127}));
  connect(add3_1.y, y1) annotation (Line(points={{88.6,74},{120,74},{120,60},{
          150,60}}, color={0,0,127}));
  connect(y, add3_2.y)
    annotation (Line(points={{150,20},{130.6,20}}, color={0,0,127}));
  connect(add3_3.y, y2)
    annotation (Line(points={{126.6,-20},{150,-20}}, color={0,0,127}));
  connect(add3_4.y, y3) annotation (Line(points={{128.6,-60},{140,-60},{140,-60},
          {150,-60}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{140,100}}),                                  graphics={Text(
          extent={{-44,30},{86,-32}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None,
          textString="MCU"), Rectangle(
          extent={{-100,100},{140,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None)}), Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{140,100}})));
end controlModule_Continuous;
