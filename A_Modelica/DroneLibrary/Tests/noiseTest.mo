within DroneLibrary.Tests;
model noiseTest
  extends Modelica.Icons.Example;
  Modelica.Blocks.Noise.BandLimitedWhiteNoise bandLimitedWhiteNoise(
      noisePower=0)
    annotation (Placement(transformation(extent={{-80,30},{-60,50}})));
  Modelica.Blocks.Continuous.Filter filter(
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    filterType=Modelica.Blocks.Types.FilterType.LowPass,
    order=4,
    normalized=true,
    f_cut=5)
    annotation (Placement(transformation(extent={{-40,30},{-20,50}})));
  Modelica.Blocks.Noise.BandLimitedWhiteNoise bandLimitedWhiteNoise1(
      noisePower=0)
    annotation (Placement(transformation(extent={{-80,-50},{-60,-30}})));
  Modelica.Blocks.Continuous.Filter filter1(
    filterType=Modelica.Blocks.Types.FilterType.HighPass,
    order=4,
    f_cut=5,
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    normalized=true)
    annotation (Placement(transformation(extent={{-40,-50},{-20,-30}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{0,10},{20,30}})));
  Modelica.Blocks.Math.Add add1
    annotation (Placement(transformation(extent={{0,-30},{20,-10}})));
  Modelica.Blocks.Continuous.Filter filter2(
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    filterType=Modelica.Blocks.Types.FilterType.LowPass,
    normalized=true,
    order=5,
    f_cut=5)
    annotation (Placement(transformation(extent={{32,-30},{52,-10}})));
  Modelica.Blocks.Continuous.Filter filter3(
    filterType=Modelica.Blocks.Types.FilterType.HighPass,
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    normalized=true,
    f_cut=5,
    order=5)
    annotation (Placement(transformation(extent={{30,10},{50,30}})));
  Modelica.Blocks.Math.Add add2
    annotation (Placement(transformation(extent={{72,-10},{92,10}})));
  Modelica.Blocks.Sources.Ramp ramp(duration=0.013)
    annotation (Placement(transformation(extent={{-60,-10},{-40,10}})));
equation
  connect(bandLimitedWhiteNoise.y, filter.u)
    annotation (Line(points={{-59,40},{-42,40}}, color={0,0,127}));
  connect(bandLimitedWhiteNoise1.y, filter1.u)
    annotation (Line(points={{-59,-40},{-42,-40}}, color={0,0,127}));
  connect(filter.y, add.u1) annotation (Line(points={{-19,40},{-14,40},{-14,26},{-2,26}},
                    color={0,0,127}));
  connect(add1.y, filter2.u)
    annotation (Line(points={{21,-20},{30,-20}}, color={0,0,127}));
  connect(add.y, filter3.u)
    annotation (Line(points={{21,20},{28,20}}, color={0,0,127}));
  connect(filter3.y, add2.u1) annotation (Line(points={{51,20},{60,20},{60,6},{70,6}},
                              color={0,0,127}));
  connect(filter2.y, add2.u2) annotation (Line(points={{53,-20},{60,-20},{60,-6},{70,-6}},
                              color={0,0,127}));
  connect(ramp.y, add.u2) annotation (Line(points={{-39,0},{-20,0},{-20,14},{-2,14}},
                              color={0,0,127}));
  connect(filter1.y, add1.u2) annotation (Line(points={{-19,-40},{-12,-40},{-12,-26},{-2,-26}}, color={0,0,127}));
  connect(add1.u1, ramp.y) annotation (Line(points={{-2,-14},{-20,-14},{-20,0},{-39,0}}, color={0,0,127}));
end noiseTest;
