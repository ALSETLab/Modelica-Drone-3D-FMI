within DroneLibrary.Tests;
model discreteTest
  extends Modelica.Icons.Example;
  Modelica.Blocks.Sources.Ramp ramp(duration=0.013)
    annotation (Placement(transformation(extent={{-62,-10},{-42,10}})));
  Modelica.Blocks.Discrete.Sampler sampler(samplePeriod=0.01)
    annotation (Placement(transformation(extent={{-14,-10},{6,10}})));
  Modelica.Blocks.Discrete.ZeroOrderHold zeroOrderHold(samplePeriod=0.01)
    annotation (Placement(transformation(extent={{48,-10},{68,10}})));
equation
  connect(ramp.y, sampler.u)
    annotation (Line(points={{-41,0},{-16,0}}, color={0,0,127}));
  connect(sampler.y, zeroOrderHold.u)
    annotation (Line(points={{7,0},{46,0}}, color={0,0,127}));

end discreteTest;
