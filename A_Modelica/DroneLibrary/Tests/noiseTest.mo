within DroneLibrary.Tests;
model noiseTest
  Modelica.Blocks.Noise.BandLimitedWhiteNoise bandLimitedWhiteNoise(
      noisePower=0)
    annotation (Placement(transformation(extent={{-68,34},{-48,54}})));
  Modelica.Blocks.Continuous.Filter filter(
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    filterType=Modelica.Blocks.Types.FilterType.LowPass,
    order=4,
    normalized=true,
    f_cut=5)
    annotation (Placement(transformation(extent={{-26,34},{-6,54}})));
  Modelica.Blocks.Noise.BandLimitedWhiteNoise bandLimitedWhiteNoise1(
      noisePower=0)
    annotation (Placement(transformation(extent={{-64,-66},{-44,-46}})));
  Modelica.Blocks.Continuous.Filter filter1(
    filterType=Modelica.Blocks.Types.FilterType.HighPass,
    order=4,
    f_cut=5,
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    normalized=true)
    annotation (Placement(transformation(extent={{-22,-66},{-2,-46}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{24,-20},{44,0}})));
  Modelica.Blocks.Math.Add add1
    annotation (Placement(transformation(extent={{24,-72},{44,-52}})));
  Modelica.Blocks.Continuous.Filter filter2(
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    filterType=Modelica.Blocks.Types.FilterType.LowPass,
    normalized=true,
    order=5,
    f_cut=5)
    annotation (Placement(transformation(extent={{64,-72},{84,-52}})));
  Modelica.Blocks.Continuous.Filter filter3(
    filterType=Modelica.Blocks.Types.FilterType.HighPass,
    analogFilter=Modelica.Blocks.Types.AnalogFilter.CriticalDamping,
    normalized=true,
    f_cut=5,
    order=5)
    annotation (Placement(transformation(extent={{64,-20},{84,0}})));
  Modelica.Blocks.Math.Add add2
    annotation (Placement(transformation(extent={{102,-46},{122,-26}})));
  Modelica.Blocks.Sources.Ramp ramp(duration=0.013)
    annotation (Placement(transformation(extent={{-146,-90},{-126,-70}})));
equation
  connect(bandLimitedWhiteNoise.y, filter.u)
    annotation (Line(points={{-47,44},{-28,44}}, color={0,0,127}));
  connect(bandLimitedWhiteNoise1.y, filter1.u)
    annotation (Line(points={{-43,-56},{-24,-56}}, color={0,0,127}));
  connect(filter.y, add.u1) annotation (Line(points={{-5,44},{10,44},{10,-4},
          {22,-4}}, color={0,0,127}));
  connect(filter1.y, add1.u1)
    annotation (Line(points={{-1,-56},{22,-56}}, color={0,0,127}));
  connect(add1.y, filter2.u)
    annotation (Line(points={{45,-62},{62,-62}}, color={0,0,127}));
  connect(add.y, filter3.u)
    annotation (Line(points={{45,-10},{62,-10}}, color={0,0,127}));
  connect(filter3.y, add2.u1) annotation (Line(points={{85,-10},{92,-10},{
          92,-30},{100,-30}}, color={0,0,127}));
  connect(filter2.y, add2.u2) annotation (Line(points={{85,-62},{92,-62},{
          92,-42},{100,-42}}, color={0,0,127}));
  connect(ramp.y, add.u2) annotation (Line(points={{-125,-80},{-90,-80},{
          -90,-16},{22,-16}}, color={0,0,127}));
  connect(add1.u2, ramp.y) annotation (Line(points={{22,-68},{10,-68},{10,
          -80},{-125,-80}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -160,-100},{140,100}})), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-160,-100},{
            140,100}})));
end noiseTest;
