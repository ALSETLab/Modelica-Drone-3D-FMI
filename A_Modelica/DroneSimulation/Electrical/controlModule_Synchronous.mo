within DroneSimulation.Electrical;
model controlModule_Synchronous
  parameter Modelica.SIunits.Time samplePeriod=0.01;
  Modelica.Blocks.Interfaces.RealOutput y annotation (Placement(transformation(
          extent={{100,10},{120,30}}), iconTransformation(extent={{100,10},{120,
            30}})));
  Modelica.Blocks.Interfaces.RealOutput y1 annotation (Placement(transformation(
          extent={{100,50},{120,70}}), iconTransformation(extent={{100,50},{120,
            70}})));
  Modelica.Blocks.Interfaces.RealOutput y2 annotation (Placement(transformation(
          extent={{100,-30},{120,-10}}), iconTransformation(extent={{100,-30},{120,
            -10}})));
  Modelica.Blocks.Interfaces.RealOutput y3 annotation (Placement(transformation(
          extent={{100,-70},{120,-50}}), iconTransformation(extent={{100,-70},{120,
            -50}})));
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
  Blocks.Control.discretePID discretePID(
    ki=1,
    kd=0.8,
    kp=1.5,
    samplePeriod=samplePeriod)
    annotation (Placement(transformation(extent={{-38,-40},{-18,-20}})));
  Blocks.Routing.RealExtract realExtract(index=1)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Interfaces.RealInput position[3]
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  Blocks.Routing.RealExtract realExtract1(index=2)
    annotation (Placement(transformation(extent={{-80,-10},{-60,10}})));
  Blocks.Routing.RealExtract realExtract2(index=3)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Blocks.Control.discretePID discretePID1(
    kp=0.1,
    kd=0.1,
    samplePeriod=samplePeriod,
    ki=0.03)
    annotation (Placement(transformation(extent={{-40,-10},{-20,10}})));
  Blocks.Control.discretePID discretePID2(
    kd=1,
    kp=1,
    samplePeriod=samplePeriod,
    ki=0.3) annotation (Placement(transformation(extent={{44,20},{64,40}})));
  Blocks.Routing.RealExtract realExtract3(index=2) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-72})));
  Blocks.Routing.RealExtract realExtract4(index=2)
    annotation (Placement(transformation(extent={{-52,-68},{-44,-60}})));
  parameter Real maxTilt=2 "Upper limits of input signals";
  Modelica.Blocks.Math.Add add(k1=+1)
    annotation (Placement(transformation(extent={{76,16},{84,24}})));
  Modelica.Blocks.Math.Add add1(k1=+1)
    annotation (Placement(transformation(extent={{76,-64},{84,-56}})));
  Blocks.Routing.RealExtract realExtract5
    annotation (Placement(transformation(extent={{-44,-76},{-36,-68}})));
  Blocks.Control.discretePID discretePID3(
    kd=0.1,
    kp=0.1,
    samplePeriod=samplePeriod,
    ki=0.03)
    annotation (Placement(transformation(extent={{-40,20},{-20,40}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=0.523)
    annotation (Placement(transformation(extent={{0,20},{20,40}})));
  Blocks.Routing.RealExtract realExtract6(index=1)
    annotation (Placement(transformation(extent={{-60,-60},{-52,-52}})));
  Modelica.Blocks.Math.Add add2(k1=-1)
    annotation (Placement(transformation(extent={{76,56},{84,64}})));
  Modelica.Blocks.Math.Add add3(k1=-1)
    annotation (Placement(transformation(extent={{76,-24},{84,-16}})));
  Modelica.Blocks.Nonlinear.Limiter limiter1(uMax=0.523)
    annotation (Placement(transformation(extent={{0,-10},{20,10}})));
  Blocks.Control.discretePID discretePID4(
    kd=1,
    kp=1,
    samplePeriod=samplePeriod,
    ki=0.1)
    annotation (Placement(transformation(extent={{32,-10},{52,10}})));
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
  Blocks.Control.discretePID discretePID5(
    kd=0.08,
    kp=0.04,
    ki=0,
    samplePeriod=samplePeriod)
    annotation (Placement(transformation(extent={{-38,72},{-18,92}})));
  Modelica.Blocks.Nonlinear.Limiter limiter2(uMax=0.1)
    annotation (Placement(transformation(extent={{-2,70},{18,90}})));
  Modelica.Blocks.Interfaces.RealInput yaw
    annotation (Placement(transformation(extent={{-140,60},{-100,100}}),
        iconTransformation(extent={{-140,60},{-100,100}})));
  Modelica.Blocks.Math.Add add4(k2=-1)
    annotation (Placement(transformation(extent={{88,46},{96,54}})));
  Modelica.Blocks.Math.Add add5
    annotation (Placement(transformation(extent={{88,6},{96,14}})));
  Modelica.Blocks.Math.Add add6(k2=+1)
    annotation (Placement(transformation(extent={{88,-34},{96,-26}})));
  Modelica.Blocks.Math.Add add7(k2=-1)
    annotation (Placement(transformation(extent={{88,-74},{96,-66}})));
  Modelica.Blocks.Math.Gain gain(k=-1)
    annotation (Placement(transformation(extent={{-10,10},{-4,16}})));
equation
  connect(position, realExtract.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,30},{-80,30}}, color={0,0,127}));
  connect(position, realExtract1.u)
    annotation (Line(points={{-120,0},{-80,0}}, color={0,0,127}));
  connect(position, realExtract2.u) annotation (Line(points={{-120,0},{-90,0},
          {-90,-30},{-80,-30}},    color={0,0,127}));
  connect(realExtract2.y, discretePID.u)
    annotation (Line(points={{-59,-30},{-38,-30}}, color={0,0,127}));
  connect(realExtract1.y, discretePID1.u)
    annotation (Line(points={{-59,0},{-40,0}}, color={0,0,127}));
  connect(GPS, realExtract4.u) annotation (Line(points={{-60,-100},{-60,-64},
          {-52,-64}}, color={0,0,127}));
  connect(realExtract3.y, discretePID2.u1) annotation (Line(points={{18.4,
          -72},{54,-72},{54,20}}, color={0,0,127}));
  connect(realExtract4.y, discretePID1.u1) annotation (Line(points={{-43.6,
          -64},{-4,-64},{-4,-16},{-30,-16},{-30,-10}}, color={0,0,127}));
  connect(discretePID.y, add.u2) annotation (Line(points={{-17,-30},{26,-30},
          {26,17.6},{75.2,17.6}}, color={0,0,127}));
  connect(discretePID.y, add1.u2) annotation (Line(points={{-17,-30},{26,
          -30},{26,-62.4},{75.2,-62.4}}, color={0,0,127}));
  connect(GPS, realExtract5.u) annotation (Line(points={{-60,-100},{-60,-72},
          {-44,-72}}, color={0,0,127}));
  connect(realExtract5.y, discretePID.u1) annotation (Line(points={{-35.6,
          -72},{-28,-72},{-28,-40}}, color={0,0,127}));
  connect(Gyero, realExtract3.u)
    annotation (Line(points={{0,-100},{0,-72},{10,-72}}, color={0,0,127}));
  connect(discretePID2.u, limiter.y)
    annotation (Line(points={{44,30},{21,30}}, color={0,0,127}));
  connect(realExtract.y, discretePID3.u)
    annotation (Line(points={{-59,30},{-40,30}}, color={0,0,127}));
  connect(realExtract6.u, GPS)
    annotation (Line(points={{-60,-56},{-60,-100}}, color={0,0,127}));
  connect(realExtract6.y, discretePID3.u1) annotation (Line(points={{-51.6,
          -56},{-46,-56},{-46,20},{-30,20}}, color={0,0,127}));
  connect(discretePID3.y, limiter.u)
    annotation (Line(points={{-19,30},{-2,30}}, color={0,0,127}));
  connect(add2.u2, add.u2) annotation (Line(points={{75.2,57.6},{26,57.6},{
          26,17.6},{75.2,17.6}}, color={0,0,127}));
  connect(add3.u2, add.u2) annotation (Line(points={{75.2,-22.4},{48,-22.4},
          {48,-30},{26,-30},{26,17.6},{75.2,17.6}}, color={0,0,127}));
  connect(limiter1.y, discretePID4.u)
    annotation (Line(points={{21,0},{32,0}}, color={0,0,127}));
  connect(realExtract7.u, Gyero)
    annotation (Line(points={{10,-60},{0,-60},{0,-100}}, color={0,0,127}));
  connect(realExtract7.y, discretePID4.u1) annotation (Line(points={{18.4,
          -60},{42,-60},{42,-10}}, color={0,0,127}));
  connect(realExtract8.u, Gyero) annotation (Line(points={{-26,50},{-14,50},
          {-14,-100},{0,-100}}, color={0,0,127}));
  connect(discretePID5.y, limiter2.u)
    annotation (Line(points={{-17,82},{-10,82},{-10,80},{-4,80}},
                                                color={0,0,127}));
  connect(limiter2.y, add1.u1) annotation (Line(points={{19,80},{72,80},{72,
          -57.6},{75.2,-57.6}}, color={0,0,127}));
  connect(add3.u1, add1.u1) annotation (Line(points={{75.2,-17.6},{72,-17.6},
          {72,-57.6},{75.2,-57.6}}, color={0,0,127}));
  connect(add.u1, add1.u1) annotation (Line(points={{75.2,22.4},{72,22.4},{
          72,-57.6},{75.2,-57.6}}, color={0,0,127}));
  connect(add2.u1, add1.u1) annotation (Line(points={{75.2,62.4},{72,62.4},
          {72,-57.6},{75.2,-57.6}}, color={0,0,127}));
  connect(discretePID5.u1, realExtract8.y)
    annotation (Line(points={{-28,72},{-28,58.4},{-26,58.4}},
                                                   color={0,0,127}));
  connect(yaw, discretePID5.u)
    annotation (Line(points={{-120,80},{-80,80},{-80,82},{-38,82}},
                                                  color={0,0,127}));
  connect(add2.y, add4.u1) annotation (Line(points={{84.4,60},{86,60},{86,
          52.4},{87.2,52.4}}, color={0,0,127}));
  connect(add.y, add5.u1) annotation (Line(points={{84.4,20},{87.2,20},{
          87.2,12.4}}, color={0,0,127}));
  connect(add3.y, add6.u1) annotation (Line(points={{84.4,-20},{86,-20},{86,
          -27.6},{87.2,-27.6}}, color={0,0,127}));
  connect(add1.y, add7.u1) annotation (Line(points={{84.4,-60},{86,-60},{86,
          -67.6},{87.2,-67.6}}, color={0,0,127}));
  connect(add4.y, y1) annotation (Line(points={{96.4,50},{98,50},{98,60},{
          110,60}}, color={0,0,127}));
  connect(add5.y, y) annotation (Line(points={{96.4,10},{98,10},{98,20},{
          110,20}}, color={0,0,127}));
  connect(add6.y, y2) annotation (Line(points={{96.4,-30},{98,-30},{98,-20},
          {110,-20}}, color={0,0,127}));
  connect(add7.y, y3) annotation (Line(points={{96.4,-70},{98,-70},{98,-60},
          {110,-60}}, color={0,0,127}));
  connect(discretePID2.y, add5.u2) annotation (Line(points={{65,30},{68,30},
          {68,8},{87.2,8},{87.2,7.6}}, color={0,0,127}));
  connect(discretePID2.y, add7.u2) annotation (Line(points={{65,30},{68,30},
          {68,-72},{87.2,-72},{87.2,-72.4}}, color={0,0,127}));
  connect(discretePID4.y, add6.u2) annotation (Line(points={{53,0},{70,0},{
          70,-32.4},{87.2,-32.4}}, color={0,0,127}));
  connect(discretePID4.y, add4.u2) annotation (Line(points={{53,0},{70,0},{
          70,47.6},{87.2,47.6}}, color={0,0,127}));
  connect(discretePID1.y, gain.u) annotation (Line(points={{-19,0},{-18,0},
          {-18,13},{-10.6,13}}, color={0,0,127}));
  connect(limiter1.u, gain.y)
    annotation (Line(points={{-2,0},{-2,13},{-3.7,13}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={Text(
          extent={{-64,74},{66,12}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None,
          textString="MCU"), Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None)}), Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end controlModule_Synchronous;
