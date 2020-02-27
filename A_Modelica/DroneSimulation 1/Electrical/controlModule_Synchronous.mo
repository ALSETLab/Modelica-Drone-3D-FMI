within DroneSimulation.Electrical;
model controlModule_Synchronous
  parameter Modelica.SIunits.Time samplePeriod=0.01;
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
  Modelica.Blocks.Interfaces.RealInput Height annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={60,-120}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={60,-120})));
  Blocks.Routing.RealExtract realExtract(index=1)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Interfaces.RealInput position[3]
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  Blocks.Routing.RealExtract realExtract1(index=2)
    annotation (Placement(transformation(extent={{-80,-10},{-60,10}})));
  Blocks.Routing.RealExtract realExtract2(index=3)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Blocks.Routing.RealExtract realExtract3(index=2) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-72})));
  Blocks.Routing.RealExtract realExtract4(index=2)
    annotation (Placement(transformation(extent={{-52,-68},{-44,-60}})));
  parameter Real maxTilt=2 "Upper limits of input signals";
  Blocks.Routing.RealExtract realExtract5
    annotation (Placement(transformation(extent={{-44,-76},{-36,-68}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=0.523)
    annotation (Placement(transformation(extent={{0,20},{20,40}})));
  Blocks.Routing.RealExtract realExtract6(index=1)
    annotation (Placement(transformation(extent={{-60,-60},{-52,-52}})));
  Modelica.Blocks.Nonlinear.Limiter limiter1(uMax=0.523)
    annotation (Placement(transformation(extent={{0,-10},{20,10}})));
  Blocks.Routing.RealExtract realExtract7(index=1) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-60})));
  Blocks.Routing.RealExtract realExtract8(index=3) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-26,54})));
  Modelica.Blocks.Nonlinear.Limiter limiter2(uMax=0.1)
    annotation (Placement(transformation(extent={{-2,70},{18,90}})));
  Modelica.Blocks.Interfaces.RealInput yaw
    annotation (Placement(transformation(extent={{-140,60},{-100,100}}),
        iconTransformation(extent={{-140,60},{-100,100}})));
  Modelica.Blocks.Math.Gain gain(k=-1)
    annotation (Placement(transformation(extent={{-12,4},{-6,10}})));
  Blocks.Control.discreteTF
             discreteTF1(
    ki=0,
    kd=0.08,
    kp=0.04,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-36,72},{-16,92}})));
  Blocks.Control.discreteTF
             discreteTF2(
    ki=0.03,
    kd=0.1,
    kp=0.1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-44,26},{-24,46}})));
  Blocks.Control.discreteTF
             discreteTF3(
    ki=0.03,
    kd=0.1,
    kp=0.1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-38,-12},{-18,8}})));
  Blocks.Control.discreteTF
             discreteTF4(
    ki=1,
    kd=0.8,
    kp=1.5,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-28,-56},{-8,-36}})));
  Blocks.Control.discreteTF
             discreteTF5(
    ki=0.3,
    kd=1,
    kp=1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{52,20},{72,40}})));
  Blocks.Control.discreteTF
             discreteTF6(
    ki=0.1,
    kd=1,
    kp=1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{32,-10},{52,10}})));
  Modelica.Blocks.Math.Add3 add3_1(k1=-1, k3=-1)
    annotation (Placement(transformation(extent={{122,54},{134,66}})));
  Modelica.Blocks.Sources.RealExpression realExpression(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{86,54},{106,66}})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=limiter2.y)
    annotation (Placement(transformation(extent={{86,64},{106,74}})));
  Modelica.Blocks.Sources.RealExpression realExpression2(y=discreteTF6.y)
    annotation (Placement(transformation(extent={{86,44},{106,58}})));
  Modelica.Blocks.Math.Add3 add3_2
    annotation (Placement(transformation(extent={{122,14},{134,26}})));
  Modelica.Blocks.Sources.RealExpression realExpression3(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{82,16},{102,28}})));
  Modelica.Blocks.Sources.RealExpression realExpression4(y=limiter2.y)
    annotation (Placement(transformation(extent={{82,26},{102,36}})));
  Modelica.Blocks.Sources.RealExpression realExpression5(y=discreteTF5.y)
    annotation (Placement(transformation(extent={{82,6},{102,20}})));
  Modelica.Blocks.Math.Add3 add3_3(k1=-1)
    annotation (Placement(transformation(extent={{120,-26},{132,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression6(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{84,-26},{104,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression7(y=limiter2.y)
    annotation (Placement(transformation(extent={{84,-16},{104,-6}})));
  Modelica.Blocks.Sources.RealExpression realExpression8(y=discreteTF6.y)
    annotation (Placement(transformation(extent={{84,-36},{104,-22}})));
  Modelica.Blocks.Math.Add3 add3_4(k3=-1)
    annotation (Placement(transformation(extent={{116,-66},{128,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression9(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{80,-66},{100,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression10(y=limiter2.y)
    annotation (Placement(transformation(extent={{80,-56},{100,-46}})));
  Modelica.Blocks.Sources.RealExpression realExpression11(y=discreteTF5.y)
    annotation (Placement(transformation(extent={{80,-76},{100,-62}})));
equation
  connect(position, realExtract.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,30},{-80,30}}, color={0,0,127}));
  connect(position, realExtract1.u)
    annotation (Line(points={{-120,0},{-80,0}}, color={0,0,127}));
  connect(position, realExtract2.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,-30},{-80,-30}},    color={0,0,127}));
  connect(GPS, realExtract4.u) annotation (Line(points={{-60,-100},{-60,-64},
          {-52,-64}}, color={0,0,127}));
  connect(GPS, realExtract5.u) annotation (Line(points={{-60,-100},{-60,-72},
          {-44,-72}}, color={0,0,127}));
  connect(Gyero, realExtract3.u)
    annotation (Line(points={{0,-100},{0,-72},{10,-72}}, color={0,0,127}));
  connect(realExtract6.u, GPS)
    annotation (Line(points={{-60,-56},{-60,-100}}, color={0,0,127}));
  connect(realExtract7.u, Gyero)
    annotation (Line(points={{10,-60},{0,-60},{0,-100}}, color={0,0,127}));
  connect(realExtract8.u, Gyero) annotation (Line(points={{-26,50},{-14,
          50},{-14,-100},{0,-100}},
                                color={0,0,127}));
  connect(limiter1.u, gain.y)
    annotation (Line(points={{-2,0},{-2,7},{-5.7,7}},   color={0,0,127}));
  connect(limiter2.u, discreteTF1.y) annotation (Line(points={{-4,80},{
          -10,80},{-10,82},{-15,82}}, color={0,0,127}));
  connect(discreteTF1.u1, realExtract8.y) annotation (Line(points={{-26,72},
          {-26,58.4}},                color={0,0,127}));
  connect(discreteTF1.u, yaw) annotation (Line(points={{-36,82},{-72,82},
          {-72,80},{-120,80}}, color={0,0,127}));
  connect(realExtract6.y, discreteTF2.u1) annotation (Line(points={{
          -51.6,-56},{-42,-56},{-42,26},{-34,26}}, color={0,0,127}));
  connect(discreteTF2.u, realExtract.y) annotation (Line(points={{-44,
          36},{-52,36},{-52,30},{-59,30}}, color={0,0,127}));
  connect(discreteTF2.y, limiter.u) annotation (Line(points={{-23,36},{
          -12,36},{-12,30},{-2,30}}, color={0,0,127}));
  connect(discreteTF3.y, gain.u) annotation (Line(points={{-17,-2},{-14,-2},{
          -14,7},{-12.6,7}},        color={0,0,127}));
  connect(realExtract1.y, discreteTF3.u) annotation (Line(points={{-59,
          0},{-48,0},{-48,-2},{-38,-2}}, color={0,0,127}));
  connect(discreteTF3.u1, realExtract4.y) annotation (Line(points={{-28,
          -12},{-36,-12},{-36,-64},{-43.6,-64}}, color={0,0,127}));
  connect(discreteTF4.u, realExtract2.y) annotation (Line(points={{-28,
          -46},{-44,-46},{-44,-30},{-59,-30}}, color={0,0,127}));
  connect(discreteTF4.u1, realExtract5.y) annotation (Line(points={{-18,
          -56},{-28,-56},{-28,-72},{-35.6,-72}}, color={0,0,127}));
  connect(realExtract3.y, discreteTF5.u1) annotation (Line(points={{18.4,-72},{
          62,-72},{62,20}},            color={0,0,127}));
  connect(limiter.y, discreteTF5.u) annotation (Line(points={{21,30},{52,30}},
                                   color={0,0,127}));
  connect(limiter1.y, discreteTF6.u) annotation (Line(points={{21,0},{32,0}},
                                    color={0,0,127}));
  connect(discreteTF6.u1, realExtract7.y) annotation (Line(points={{42,-10},{42,
          -60},{18.4,-60}},          color={0,0,127}));
  connect(realExpression.y,add3_1. u2)
    annotation (Line(points={{107,60},{120.8,60}},
                                                 color={0,0,127}));
  connect(add3_1.u1,realExpression1. y) annotation (Line(points={{120.8,64.8},{
          114,64.8},{114,69},{107,69}},
                                  color={0,0,127}));
  connect(add3_1.u3,realExpression2. y) annotation (Line(points={{120.8,55.2},{
          114,55.2},{114,51},{107,51}},
                                  color={0,0,127}));
  connect(add3_1.y, y1) annotation (Line(points={{134.6,60},{141.3,60},{141.3,
          60},{150,60}}, color={0,0,127}));
  connect(realExpression3.y,add3_2. u2)
    annotation (Line(points={{103,22},{112,22},{112,20},{120.8,20}},
                                                   color={0,0,127}));
  connect(add3_2.u1,realExpression4. y) annotation (Line(points={{120.8,24.8},{
          112,24.8},{112,31},{103,31}},
                                    color={0,0,127}));
  connect(add3_2.u3,realExpression5. y) annotation (Line(points={{120.8,15.2},{
          112,15.2},{112,13},{103,13}},
                                  color={0,0,127}));
  connect(add3_2.y, y)
    annotation (Line(points={{134.6,20},{150,20}}, color={0,0,127}));
  connect(realExpression6.y,add3_3. u2)
    annotation (Line(points={{105,-20},{118.8,-20}}, color={0,0,127}));
  connect(add3_3.u1,realExpression7. y) annotation (Line(points={{118.8,-15.2},
          {112,-15.2},{112,-11},{105,-11}},color={0,0,127}));
  connect(add3_3.u3,realExpression8. y) annotation (Line(points={{118.8,-24.8},
          {112,-24.8},{112,-29},{105,-29}},color={0,0,127}));
  connect(add3_3.y, y2)
    annotation (Line(points={{132.6,-20},{150,-20}}, color={0,0,127}));
  connect(realExpression9.y,add3_4. u2)
    annotation (Line(points={{101,-60},{114.8,-60}}, color={0,0,127}));
  connect(add3_4.u1,realExpression10. y) annotation (Line(points={{114.8,-55.2},
          {108,-55.2},{108,-51},{101,-51}}, color={0,0,127}));
  connect(add3_4.u3,realExpression11. y) annotation (Line(points={{114.8,-64.8},
          {108,-64.8},{108,-69},{101,-69}}, color={0,0,127}));
  connect(add3_4.y, y3)
    annotation (Line(points={{128.6,-60},{150,-60}}, color={0,0,127}));
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
end controlModule_Synchronous;
