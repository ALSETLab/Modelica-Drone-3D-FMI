within DroneSimulation.Electrical;
model controlModule_Synchronous
  parameter Modelica.Units.SI.Time samplePeriod=0.01;
  Modelica.Blocks.Interfaces.RealOutput y annotation (Placement(transformation(
          extent={{120,10},{140,30}}), iconTransformation(extent={{120,10},{140,
            30}})));
  Modelica.Blocks.Interfaces.RealOutput y1 annotation (Placement(transformation(
          extent={{120,50},{140,70}}), iconTransformation(extent={{120,50},{140,
            70}})));
  Modelica.Blocks.Interfaces.RealOutput y2 annotation (Placement(transformation(
          extent={{120,-30},{140,-10}}), iconTransformation(extent={{120,-30},{
            140,-10}})));
  Modelica.Blocks.Interfaces.RealOutput y3 annotation (Placement(transformation(
          extent={{120,-70},{140,-50}}), iconTransformation(extent={{120,-70},{
            140,-50}})));
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
    annotation (Placement(transformation(extent={{0,-14},{20,6}})));
  Blocks.Routing.RealExtract realExtract7(index=1) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=0,
        origin={14,-60})));
  Blocks.Routing.RealExtract realExtract8(index=3) annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-26,60})));
  Modelica.Blocks.Nonlinear.Limiter limiter2(uMax=0.1)
    annotation (Placement(transformation(extent={{-2,70},{18,90}})));
  Modelica.Blocks.Interfaces.RealInput yaw
    annotation (Placement(transformation(extent={{-140,60},{-100,100}}),
        iconTransformation(extent={{-140,60},{-100,100}})));
  Modelica.Blocks.Math.Gain gain(k=-1)
    annotation (Placement(transformation(extent={{-16,-2},{-12,2}})));
  Blocks.Control.discreteTF
             discreteTF1(
    ki=0,
    kd=0.08,
    kp=0.04,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-36,70},{-16,90}})));
  Blocks.Control.discreteTF
             discreteTF2(
    ki=0.03,
    kd=0.1,
    kp=0.1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-44,20},{-24,40}})));
  Blocks.Control.discreteTF
             discreteTF3(
    ki=0.03,
    kd=0.1,
    kp=0.1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-44,-10},{-24,10}})));
  Blocks.Control.discreteTF
             discreteTF4(
    ki=1,
    kd=2,
    kp=1.5,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{-42,-40},{-22,-20}})));
  Blocks.Control.discreteTF
             discreteTF5(
    ki=2,
    kd=1,
    kp=1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{34,20},{54,40}})));
  Blocks.Control.discreteTF
             discreteTF6(
    ki=2,
    kd=1,
    kp=1,
    samplePeriod=5*samplePeriod,
    period=5*samplePeriod)
    annotation (Placement(transformation(extent={{26,-14},{46,6}})));
  Modelica.Blocks.Math.Add3 add3_1(k1=-1, k3=-1)
    annotation (Placement(transformation(extent={{96,54},{108,66}})));
  Modelica.Blocks.Sources.RealExpression realExpression(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{60,54},{80,66}})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=limiter2.y)
    annotation (Placement(transformation(extent={{60,64},{80,74}})));
  Modelica.Blocks.Sources.RealExpression realExpression2(y=discreteTF6.y)
    annotation (Placement(transformation(extent={{60,44},{80,58}})));
  Modelica.Blocks.Math.Add3 add3_2
    annotation (Placement(transformation(extent={{96,14},{108,26}})));
  Modelica.Blocks.Sources.RealExpression realExpression3(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{60,14},{80,26}})));
  Modelica.Blocks.Sources.RealExpression realExpression4(y=limiter2.y)
    annotation (Placement(transformation(extent={{60,24},{80,34}})));
  Modelica.Blocks.Sources.RealExpression realExpression5(y=discreteTF5.y)
    annotation (Placement(transformation(extent={{60,4},{80,18}})));
  Modelica.Blocks.Math.Add3 add3_3(k1=-1)
    annotation (Placement(transformation(extent={{96,-26},{108,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression6(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{60,-26},{80,-14}})));
  Modelica.Blocks.Sources.RealExpression realExpression7(y=limiter2.y)
    annotation (Placement(transformation(extent={{60,-16},{80,-6}})));
  Modelica.Blocks.Sources.RealExpression realExpression8(y=discreteTF6.y)
    annotation (Placement(transformation(extent={{60,-36},{80,-22}})));
  Modelica.Blocks.Math.Add3 add3_4(k3=-1)
    annotation (Placement(transformation(extent={{96,-66},{108,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression9(y=discreteTF4.y)
    annotation (Placement(transformation(extent={{60,-66},{80,-54}})));
  Modelica.Blocks.Sources.RealExpression realExpression10(y=limiter2.y)
    annotation (Placement(transformation(extent={{60,-56},{80,-46}})));
  Modelica.Blocks.Sources.RealExpression realExpression11(y=discreteTF5.y)
    annotation (Placement(transformation(extent={{60,-76},{80,-62}})));
  Modelica.Blocks.Sources.RealExpression realExpression12(y=Gyero[3])
    annotation (Placement(transformation(extent={{-56,44},{-36,54}})));
  Modelica.Blocks.Sources.RealExpression realExpression13(y=realExtract6.y)
    annotation (Placement(transformation(extent={{-62,10},{-42,20}})));
  Modelica.Blocks.Sources.RealExpression realExpression14(y=realExtract4.y)
    annotation (Placement(transformation(extent={{-60,-22},{-40,-12}})));
  Modelica.Blocks.Sources.RealExpression realExpression15(y=realExtract3.y)
    annotation (Placement(transformation(extent={{18,8},{38,18}})));
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
  connect(limiter1.u, gain.y)
    annotation (Line(points={{-2,-4},{-6,-4},{-6,0},{-11.8,0}},
                                                        color={0,0,127}));
  connect(limiter2.u, discreteTF1.y) annotation (Line(points={{-4,80},{-15,80}},
                                      color={0,0,127}));
  connect(discreteTF1.u1, realExtract8.y) annotation (Line(points={{-26,70},{
          -26,64.4}},                 color={0,0,127}));
  connect(discreteTF1.u, yaw) annotation (Line(points={{-36,80},{-120,80}},
                               color={0,0,127}));
  connect(discreteTF2.u, realExtract.y) annotation (Line(points={{-44,30},{-59,
          30}},                            color={0,0,127}));
  connect(discreteTF2.y, limiter.u) annotation (Line(points={{-23,30},{-2,30}},
                                     color={0,0,127}));
  connect(discreteTF3.y, gain.u) annotation (Line(points={{-23,0},{-16.4,0}},
                                    color={0,0,127}));
  connect(realExtract1.y, discreteTF3.u) annotation (Line(points={{-59,0},{-44,
          0}},                           color={0,0,127}));
  connect(discreteTF4.u, realExtract2.y) annotation (Line(points={{-42,-30},{
          -59,-30}},                           color={0,0,127}));
  connect(discreteTF4.u1, realExtract5.y) annotation (Line(points={{-32,-40},{
          -32,-72},{-35.6,-72}},                 color={0,0,127}));
  connect(limiter.y, discreteTF5.u) annotation (Line(points={{21,30},{34,30}},
                                   color={0,0,127}));
  connect(limiter1.y, discreteTF6.u) annotation (Line(points={{21,-4},{26,-4}},
                                    color={0,0,127}));
  connect(discreteTF6.u1, realExtract7.y) annotation (Line(points={{36,-14},{36,
          -60},{18.4,-60}},          color={0,0,127}));
  connect(realExpression.y,add3_1. u2)
    annotation (Line(points={{81,60},{94.8,60}}, color={0,0,127}));
  connect(add3_1.u1,realExpression1. y) annotation (Line(points={{94.8,64.8},{
          88,64.8},{88,69},{81,69}},
                                  color={0,0,127}));
  connect(add3_1.u3,realExpression2. y) annotation (Line(points={{94.8,55.2},{
          88,55.2},{88,51},{81,51}},
                                  color={0,0,127}));
  connect(realExpression3.y, add3_2.u2)
    annotation (Line(points={{81,20},{94.8,20}}, color={0,0,127}));
  connect(add3_2.u1,realExpression4. y) annotation (Line(points={{94.8,24.8},{
          88,24.8},{88,29},{81,29}},
                                  color={0,0,127}));
  connect(add3_2.u3,realExpression5. y) annotation (Line(points={{94.8,15.2},{
          88,15.2},{88,11},{81,11}},
                                  color={0,0,127}));
  connect(realExpression6.y, add3_3.u2)
    annotation (Line(points={{81,-20},{94.8,-20}}, color={0,0,127}));
  connect(add3_3.u1,realExpression7. y) annotation (Line(points={{94.8,-15.2},{
          88,-15.2},{88,-11},{81,-11}},
                                  color={0,0,127}));
  connect(add3_3.u3,realExpression8. y) annotation (Line(points={{94.8,-24.8},{
          88,-24.8},{88,-29},{81,-29}},
                                  color={0,0,127}));
  connect(realExpression9.y, add3_4.u2)
    annotation (Line(points={{81,-60},{94.8,-60}}, color={0,0,127}));
  connect(add3_4.u1, realExpression10.y) annotation (Line(points={{94.8,-55.2},
          {88,-55.2},{88,-51},{81,-51}}, color={0,0,127}));
  connect(add3_4.u3, realExpression11.y) annotation (Line(points={{94.8,-64.8},
          {88,-64.8},{88,-69},{81,-69}}, color={0,0,127}));
  connect(realExtract8.u[3], realExpression12.y) annotation (Line(points={{
          -26.5333,56},{-26,56},{-26,49},{-35,49}}, color={0,0,127}));
  connect(add3_4.y, y3)
    annotation (Line(points={{108.6,-60},{130,-60}}, color={0,0,127}));
  connect(add3_1.y, y1)
    annotation (Line(points={{108.6,60},{130,60}}, color={0,0,127}));
  connect(realExpression13.y, discreteTF2.u1)
    annotation (Line(points={{-41,15},{-34,15},{-34,20}}, color={0,0,127}));
  connect(discreteTF3.u1, realExpression14.y)
    annotation (Line(points={{-34,-10},{-34,-17},{-39,-17}}, color={0,0,127}));
  connect(realExpression15.y, discreteTF5.u1)
    annotation (Line(points={{39,13},{44,13},{44,20}}, color={0,0,127}));
  connect(add3_2.y, y)
    annotation (Line(points={{108.6,20},{130,20}}, color={0,0,127}));
  connect(add3_3.y, y2)
    annotation (Line(points={{108.6,-20},{130,-20}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{120,100}}),                                  graphics={Text(
          extent={{-54,30},{76,-32}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None,
          textString="MCU"), Rectangle(
          extent={{-100,100},{120,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None)}), Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{120,100}})),
    __Dymola_Commands(executeCall(ensureSimulated=true) = {createPlot(
        id=2,
        position={622,11,584,414},
        y={
          "drone.propeller_DCMachine_Power.dCMotor_DCMachine_Power.force.force[3]"},
        range={0.0,10.0,-1.0,7.0},
        autoscale=false,
        grid=true,
        legends={"Thrust (on one motor)"},
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200}},
        thicknesses={1.0}),createPlot(
        id=1,
        position={15,10,584,420},
        y={"drone.xgps","drone.ygps","drone.zgps"},
        range={0.0,10.0,-0.5,5.5},
        grid=true,
        legends={"X Position","Y Position","Z Position"},
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47},{0,140,72}},
        patterns={LinePattern.Solid,LinePattern.Dash,LinePattern.Dot},
        thicknesses={1.0,1.0,1.0})} "CreateThrust"));
end controlModule_Synchronous;
