within DroneSimulation.Electrical.PowerElectronics.Converters.DCAC;
model DCAC_HalfBridgeAverage
  Modelica.Blocks.Interfaces.BooleanInput Q1gate
    annotation (Placement(transformation(extent={{-11,-11},{11,11}},
        rotation=90,
        origin={-29,-91}), iconTransformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-50,-90})));
  Modelica.Electrical.Analog.Interfaces.PositivePin ac
    annotation (Placement(transformation(extent={{80,-10},{100,10}}),
        iconTransformation(extent={{80,-10},{100,10}})));
  Modelica.Blocks.Interfaces.BooleanInput Q4gate
    annotation (Placement(transformation(extent={{-11,-11},{11,11}},
        rotation=90,
        origin={51,-91}), iconTransformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={50,-90})));

  Switches.SwitchCellAverP switch1(Ron=plant.ron)
    annotation (Placement(transformation(extent={{-52,14},{-36,28}})));
  Switches.SwitchCellAverN switch4(Ron=plant.ron)
    annotation (Placement(transformation(extent={{-52,-38},{-36,-24}})));

  Modelica.Blocks.Interfaces.RealInput DutyCycle annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=-90,
        origin={24,90}), iconTransformation(
        extent={{-10,-10},{10,10}},
        rotation=-90,
        origin={50,90})));
  Modelica.Blocks.Interfaces.RealInput current
    annotation (Placement(transformation(extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-20,90}), iconTransformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-50,90})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{74,-10},{54,10}})));
  Modelica.Blocks.Math.Product product2
    annotation (Placement(transformation(extent={{4,-4},{-4,4}},
        rotation=90,
        origin={64,24})));
  Modelica.Blocks.Sources.Constant const5(k=plant.Vd/2)
    annotation (Placement(transformation(extent={{94,34},{84,44}})));
  Modelica.Blocks.Math.Add add(k2=-1)
    annotation (Placement(transformation(extent={{4,-4},{-4,4}},
        rotation=180,
        origin={50,36})));
  Modelica.Blocks.Math.Gain gain2(k=2) annotation (Placement(transformation(
        extent={{-4,-4},{4,4}},
        rotation=270,
        origin={24,56})));
  Modelica.Blocks.Sources.Constant const(k=1)
    annotation (Placement(transformation(extent={{4,-4},{-4,4}},
        rotation=0,
        origin={40,50})));
  Modelica.Electrical.Analog.Interfaces.Pin pin1 annotation (Placement(
        transformation(extent={{-100,50},{-80,70}}), iconTransformation(extent=
            {{-100,50},{-80,70}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin pin_n1 annotation (
      Placement(transformation(extent={{-100,-70},{-80,-50}}),
        iconTransformation(extent={{-100,-70},{-80,-50}})));
  Modelica.Electrical.Analog.Basic.Ground ground1
    annotation (Placement(transformation(extent={{0,-24},{20,-4}})));
  CHEETA.Records.NotionalPowerSystem.Plant plant
    annotation (Placement(transformation(extent={{54,54},{74,74}})));
equation
  connect(switch1.pin_n, signalVoltage.n)
    annotation (Line(points={{-48,13},{-48,0},{54,0}},   color={0,0,255}));
  connect(product2.y, signalVoltage.v) annotation (Line(points={{64,19.6},{64,
          12}},                   color={0,0,127}));
  connect(DutyCycle, switch1.DutyCycle) annotation (Line(points={{24,90},{24,66},
          {14,66},{14,25},{-35,25}},                 color={0,0,127}));
  connect(signalVoltage.p, ac)
    annotation (Line(points={{74,0},{90,0}}, color={0,0,255}));
  connect(DutyCycle, gain2.u)
    annotation (Line(points={{24,90},{24,60.8}}, color={0,0,127}));
  connect(gain2.y, add.u1) annotation (Line(points={{24,51.6},{24,33.6},{45.2,
          33.6}},             color={0,0,127}));
  connect(add.y, product2.u1) annotation (Line(points={{54.4,36},{61.6,36},{
          61.6,28.8}},  color={0,0,127}));
  connect(switch1.pin, pin1)
    annotation (Line(points={{-48,29},{-48,60},{-90,60}}, color={0,0,255}));
  connect(switch4.pin_n, pin_n1) annotation (Line(points={{-48,-39},{-48,
          -60.7143},{-90,-60.7143},{-90,-60}}, color={0,0,255}));
  connect(ground1.p, signalVoltage.n)
    annotation (Line(points={{10,-4},{10,0},{54,0}}, color={0,0,255}));
  connect(switch4.GateSignal, Q4gate) annotation (Line(points={{-53.3,-31.1},{
          -58,-31.1},{-58,-50},{51,-50},{51,-91}}, color={255,0,255}));
  connect(switch4.current, switch1.current) annotation (Line(points={{-35,-35},
          {-20,-35},{-20,17},{-35,17}}, color={0,0,127}));
  connect(switch4.DutyCycle, switch1.DutyCycle) annotation (Line(points={{-35,
          -27},{14,-27},{14,25},{-35,25}}, color={0,0,127}));
  connect(switch1.GateSignal, Q1gate) annotation (Line(points={{-53.3,21.1},{
          -64,21.1},{-64,-72},{-29,-72},{-29,-91}}, color={255,0,255}));
  connect(switch4.pin, signalVoltage.n)
    annotation (Line(points={{-48,-23},{-48,0},{54,0}}, color={0,0,255}));
  connect(current, switch1.current)
    annotation (Line(points={{-20,90},{-20,17},{-35,17}}, color={0,0,127}));
  connect(const5.y, product2.u2) annotation (Line(points={{83.5,39},{66.4,39},{
          66.4,28.8}}, color={0,0,127}));
  connect(add.u2, const.y) annotation (Line(points={{45.2,38.4},{32,38.4},{32,
          50},{35.6,50}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,-80},
            {80,80}}), graphics={
        Rectangle(extent={{-80,80},{80,-80}}, lineColor={28,108,200}),
                                Rectangle(
        extent={{-80,-80},{80,80}},
        lineColor={0,0,127},
        fillColor={255,255,255},
        fillPattern=FillPattern.Solid),
        Line(
          points={{-80,-80},{80,80}},
          color={0,0,127}),
        Rectangle(
          extent={{-40,40},{40,-40}},
          lineColor={255,255,255},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
        Line(
          points={{-20,20},{-20,-20}},
          color={0,0,255}),
        Line(
          points={{-28,20},{-28,-20}},
          color={0,0,255}),
        Line(
          points={{-40,0},{-28,0}},
          color={0,0,255}),
        Line(
          points={{-20,4},{0,24},{0,40}},
          color={0,0,255}),
        Line(
          points={{-20,-4},{0,-24},{0,-40}},
          color={0,0,255}),
        Line(
          points={{-4,-20},{-10,-8},{-16,-14},{-4,-20}},
          color={0,0,255}),
        Line(
          points={{0,-24},{10,-24},{10,24},{0,24}},
          color={0,0,255}),
        Line(
          points={{0,8},{20,8}},
          color={0,0,255}),
        Line(
          points={{10,8},{0,-8},{20,-8},{10,8}},
          color={0,0,255}),
        Text(
          extent={{-94,56},{6,36}},
          lineColor={0,0,127},
          textString="DC"),
        Text(
          extent={{-12,-38},{88,-58}},
          lineColor={0,0,127},
          textString="AC")}),  Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-80,-80},{80,80}})));
end DCAC_HalfBridgeAverage;
