within DroneSimulation.Electrical.PowerElectronics.Converters.DCAC;
model Simulink_AverageInverter
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=180,
        origin={24,56})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ina
    annotation (Placement(transformation(extent={{-30,10},{-10,30}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ipa
    annotation (Placement(transformation(extent={{-32,58},{-12,78}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor
    annotation (Placement(transformation(extent={{52,46},{72,66}})));
  SourceGains sourceGains annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={38,34})));
  Modelica.Electrical.Analog.Basic.Ground ground1
    annotation (Placement(transformation(extent={{-34,34},{-14,54}})));
  Modelica.Electrical.Analog.Sensors.VoltageSensor voltageSensor
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-46,50})));
  Modelica.Electrical.MultiPhase.Interfaces.PositivePlug positivePlug
    annotation (Placement(transformation(extent={{140,-74},{160,-54}}),
        iconTransformation(extent={{140,-74},{160,-54}})));
  .AircraftPowerSystem.Interfaces.multiphtoabc multiphtoabc annotation (
     Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={118,0})));
  Modelica.Electrical.Analog.Interfaces.PositivePin pin_p annotation (
      Placement(transformation(extent={{-140,8},{-120,28}}),
        iconTransformation(extent={{-140,8},{-120,28}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin pin_n annotation (Placement(
        transformation(extent={{-140,-130},{-120,-110}}), iconTransformation(
          extent={{-140,-130},{-120,-110}})));
  Modelica.Electrical.Analog.Basic.Ground ground2 annotation (Placement(
        transformation(extent={{-112,-78},{-92,-58}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ina1
    annotation (Placement(transformation(extent={{-28,-82},{-8,-62}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ipa1 annotation (
      Placement(transformation(extent={{-30,-36},{-10,-16}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor1
    annotation (Placement(transformation(extent={{54,-48},{74,-28}})));
  SourceGains sourceGains1 annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={40,-60})));
  Modelica.Electrical.Analog.Basic.Ground ground3 annotation (Placement(
        transformation(extent={{-32,-60},{-12,-40}})));
  Modelica.Electrical.Analog.Sensors.VoltageSensor voltageSensor1
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-44,-44})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ina2 annotation (
      Placement(transformation(extent={{-28,-188},{-8,-168}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent Ipa2 annotation (
      Placement(transformation(extent={{-30,-142},{-10,-122}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor2
    annotation (Placement(transformation(extent={{54,-154},{74,-134}})));
  SourceGains sourceGains2 annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={40,-166})));
  Modelica.Electrical.Analog.Basic.Ground ground4 annotation (Placement(
        transformation(extent={{-32,-166},{-12,-146}})));
  Modelica.Electrical.Analog.Sensors.VoltageSensor voltageSensor2
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-44,-150})));
  Modelica.Blocks.Interfaces.RealInput ma "Phase A Modulation Signal" annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={-102,116}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={-76,82})));
  Modelica.Blocks.Interfaces.RealInput mc "Phase B Modulation Signal" annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={116,118}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={120,82})));
  Modelica.Blocks.Interfaces.RealInput mb "Phase C Modulation Signal" annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={2,114}), iconTransformation(
        extent={{-20,-20},{20,20}},
        rotation=270,
        origin={20,82})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage1
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=180,
        origin={26,-32})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage2
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=180,
        origin={32,-126})));
equation
  connect(sourceGains.Vt, signalVoltage.v) annotation (Line(points={{27,42.2},
          {27,44},{24,44}},       color={0,0,127}));
  connect(sourceGains.I_n, Ina.i)
    annotation (Line(points={{27,34},{4,34},{4,32},{-20,32}},
                                                color={0,0,127}));
  connect(sourceGains.I_p, Ipa.i) annotation (Line(points={{27,26},{6,
          26},{6,80},{-22,80}}, color={0,0,127}));
  connect(voltageSensor.p, Ipa.p) annotation (Line(points={{-46,60},{
          -46,68},{-32,68}}, color={0,0,255}));
  connect(voltageSensor.n, Ina.p) annotation (Line(points={{-46,40},{
          -46,20},{-30,20}}, color={0,0,255}));
  connect(voltageSensor.v, sourceGains.Vdc) annotation (Line(points={{
          -57,50},{-58,50},{-58,39.8},{48,39.8}}, color={0,0,127}));
  connect(currentSensor.i, sourceGains.i) annotation (Line(points={{62,
          45},{60,45},{60,34},{48,34}}, color={0,0,127}));
  connect(multiphtoabc.m, positivePlug) annotation (Line(points={{128.4,
          -1.22125e-15},{127.8,-1.22125e-15},{127.8,-64},{150,-64}},
                                                     color={0,0,255}));

  connect(pin_p, Ipa.p)
    annotation (Line(points={{-130,18},{-82,18},{-82,68},{-32,68}},
                                                  color={0,0,255}));

  connect(pin_n, Ina.p) annotation (Line(points={{-130,-120},{-130,20},{-30,20}},
        color={0,0,255}));
  connect(sourceGains1.I_n, Ina1.i)
    annotation (Line(points={{29,-60},{-18,-60}}, color={0,0,127}));
  connect(sourceGains1.I_p, Ipa1.i) annotation (Line(points={{29,-68},{
          8,-68},{8,-14},{-20,-14}}, color={0,0,127}));
  connect(voltageSensor1.p, Ipa1.p) annotation (Line(points={{-44,-34},
          {-44,-26},{-30,-26}}, color={0,0,255}));
  connect(voltageSensor1.n, Ina1.p) annotation (Line(points={{-44,-54},
          {-44,-72},{-28,-72}}, color={0,0,255}));
  connect(voltageSensor1.v, sourceGains1.Vdc) annotation (Line(points={
          {-55,-44},{-56,-44},{-56,-54.2},{50,-54.2}}, color={0,0,127}));
  connect(currentSensor1.i, sourceGains1.i) annotation (Line(points={{
          64,-49},{62,-49},{62,-60},{50,-60}}, color={0,0,127}));
  connect(pin_p, Ipa1.p) annotation (Line(points={{-130,18},{-74,18},{-74,-26},
          {-30,-26}},          color={0,0,255}));
  connect(pin_n, Ina1.p) annotation (Line(points={{-130,-120},{-28,-120},{-28,-72}},
        color={0,0,255}));
  connect(pin_n, Ina.p) annotation (Line(points={{-130,-120},{-30,-120},{-30,20}},
        color={0,0,255}));
  connect(sourceGains2.I_n, Ina2.i)
    annotation (Line(points={{29,-166},{-18,-166}}, color={0,0,127}));
  connect(sourceGains2.I_p, Ipa2.i) annotation (Line(points={{29,-174},
          {8,-174},{8,-120},{-20,-120}}, color={0,0,127}));
  connect(voltageSensor2.p, Ipa2.p) annotation (Line(points={{-44,-140},
          {-44,-132},{-30,-132}}, color={0,0,255}));
  connect(voltageSensor2.n, Ina2.p) annotation (Line(points={{-44,-160},
          {-44,-178},{-28,-178}}, color={0,0,255}));
  connect(voltageSensor2.v, sourceGains2.Vdc) annotation (Line(points={
          {-55,-150},{-56,-150},{-56,-160.2},{50,-160.2}}, color={0,0,
          127}));
  connect(currentSensor2.i, sourceGains2.i) annotation (Line(points={{
          64,-155},{62,-155},{62,-166},{50,-166}}, color={0,0,127}));
  connect(pin_p, Ipa2.p) annotation (Line(points={{-130,18},{-74,18},{-74,-132},
          {-30,-132}},           color={0,0,255}));
  connect(pin_n, Ina2.p) annotation (Line(points={{-130,-120},{-28,-120},{-28,-178}},
        color={0,0,255}));
  connect(ma, sourceGains.m) annotation (Line(points={{-102,116},{-28,
          116},{-28,26.6},{48,26.6}}, color={0,0,127}));
  connect(mb, sourceGains1.m) annotation (Line(points={{2,114},{2,19},{
          50,19},{50,-67.4}}, color={0,0,127}));
  connect(mc, sourceGains2.m) annotation (Line(points={{116,118},{122,
          118},{122,-173.4},{50,-173.4}}, color={0,0,127}));
  connect(multiphtoabc.a, currentSensor.n) annotation (Line(points={{
          107.6,-9.6},{107.6,-10.8},{72,-10.8},{72,56}}, color={0,0,255}));
  connect(multiphtoabc.b, currentSensor1.n) annotation (Line(points={{
          107.6,-0.4},{107.6,-1.2},{74,-1.2},{74,-38}}, color={0,0,255}));
  connect(multiphtoabc.c, currentSensor2.n) annotation (Line(points={{
          107.6,9.6},{98,9.6},{98,-144},{74,-144}}, color={0,0,255}));
  connect(signalVoltage.n, Ipa.n) annotation (Line(points={{14,56},{2,
          56},{2,68},{-12,68}}, color={0,0,255}));
  connect(Ina.n, signalVoltage.n) annotation (Line(points={{-10,20},{2,
          20},{2,56},{14,56}}, color={0,0,255}));
  connect(signalVoltage.p, currentSensor.p)
    annotation (Line(points={{34,56},{52,56}}, color={0,0,255}));
  connect(signalVoltage1.n, Ipa1.n) annotation (Line(points={{16,-32},{
          4,-32},{4,-26},{-10,-26}}, color={0,0,255}));
  connect(signalVoltage1.n, Ina1.n) annotation (Line(points={{16,-32},{
          4,-32},{4,-72},{-8,-72}}, color={0,0,255}));
  connect(signalVoltage1.p, currentSensor1.p) annotation (Line(points={
          {36,-32},{46,-32},{46,-38},{54,-38}}, color={0,0,255}));
  connect(signalVoltage1.v, sourceGains1.Vt) annotation (Line(points={{
          26,-44},{29,-44},{29,-51.8}}, color={0,0,127}));
  connect(ground1.p, Ipa.n) annotation (Line(points={{-24,54},{2,54},{2,
          68},{-12,68}}, color={0,0,255}));
  connect(ground3.p, Ina1.n) annotation (Line(points={{-22,-40},{4,-40},
          {4,-72},{-8,-72}}, color={0,0,255}));
  connect(Ipa2.n, Ina2.n) annotation (Line(points={{-10,-132},{-10,-156},
          {-8,-156},{-8,-178}}, color={0,0,255}));
  connect(ground4.p, Ina2.n) annotation (Line(points={{-22,-146},{-10,
          -146},{-10,-156},{-8,-156},{-8,-178}}, color={0,0,255}));
  connect(signalVoltage2.n, Ina2.n) annotation (Line(points={{22,-126},
          {-10,-126},{-10,-156},{-8,-156},{-8,-178}}, color={0,0,255}));
  connect(signalVoltage2.p, currentSensor2.p) annotation (Line(points={
          {42,-126},{48,-126},{48,-144},{54,-144}}, color={0,0,255}));
  connect(sourceGains2.Vt, signalVoltage2.v) annotation (Line(points={{
          29,-157.8},{29,-148.9},{32,-148.9},{32,-138}}, color={0,0,127}));
  connect(ground2.p, Ina.p) annotation (Line(points={{-102,-58},{-130,-58},{
          -130,20},{-30,20}}, color={0,0,255}));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false, extent={{-120,-180},{140,
            60}}), graphics={
        Rectangle(extent={{-68,20},{92,-140}},lineColor={28,108,200}),
                                Rectangle(
        extent={{-120,-180},{140,60}},
        lineColor={0,0,127},
        fillColor={255,255,255},
        fillPattern=FillPattern.Solid),
        Line(
          points={{-120,-180},{140,60}},
          color={0,0,127}),
        Rectangle(
          extent={{-28,-20},{52,-100}},
          lineColor={255,255,255},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
        Line(
          points={{-8,-40},{-8,-80}},
          color={0,0,255}),
        Line(
          points={{-16,-40},{-16,-80}},
          color={0,0,255}),
        Line(
          points={{-28,-60},{-16,-60}},
          color={0,0,255}),
        Line(
          points={{-8,-56},{12,-36},{12,-20}},
          color={0,0,255}),
        Line(
          points={{-8,-64},{12,-84},{12,-100}},
          color={0,0,255}),
        Line(
          points={{8,-80},{2,-68},{-4,-74},{8,-80}},
          color={0,0,255}),
        Line(
          points={{12,-84},{22,-84},{22,-36},{12,-36}},
          color={0,0,255}),
        Line(
          points={{12,-52},{32,-52}},
          color={0,0,255}),
        Line(
          points={{22,-52},{12,-68},{32,-68},{22,-52}},
          color={0,0,255}),
        Text(
          extent={{-82,-6},{18,-26}},
          lineColor={0,0,127},
          textString="DC"),
        Text(
          extent={{0,-98},{100,-118}},
          lineColor={0,0,127},
          textString="AC")}),
    Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-120,-180},{
            140,60}})),
    experiment(StopTime=100, __Dymola_NumberOfIntervals=50000),
    Documentation(info="<html>
<p>Averaged Inverter Model</p>
<p>Inputs ma, mb, mc modulate the controlled sources.</p>
<p>Modulation signals must be between -1 and 1 (no error will be tiven for higher values).</p>
<p>Modulation signal of 1 generates voltage equal to one of the input terminals of the converter.</p>
</html>"));
end Simulink_AverageInverter;
