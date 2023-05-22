within DroneLibrary.Tests;
model discretePIDTest
  DroneLibrary.Blocks.Control.discretePID discretePID(
    kd=0,
    ki=0,
    kp=1) annotation (Placement(transformation(extent={{-10,-10},{10,10}})));
   Modelica.Blocks.Sources.Sine sine(f=10)
     annotation (Placement(transformation(extent={{-98,-10},{-78,10}})));
  Modelica.Blocks.Sources.Step step1(height=1)
    annotation (Placement(transformation(extent={{-74,-68},{-54,-48}})));
  Modelica.Blocks.Discrete.Sampler sampler(samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-64,-10},{-44,10}})));
  Modelica.Blocks.Discrete.ZeroOrderHold zeroOrderHold(samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-36,-10},{-16,10}})));
equation
  connect(step1.y, discretePID.u1)
    annotation (Line(points={{-53,-58},{0,-58},{0,-10}}, color={0,0,127}));
  connect(sine.y, sampler.u)
    annotation (Line(points={{-77,0},{-66,0}}, color={0,0,127}));
  connect(sampler.y, zeroOrderHold.u)
    annotation (Line(points={{-43,0},{-38,0}}, color={0,0,127}));
  connect(discretePID.u, zeroOrderHold.y)
    annotation (Line(points={{-10,0},{-15,0}}, color={0,0,127}));

end discretePIDTest;
