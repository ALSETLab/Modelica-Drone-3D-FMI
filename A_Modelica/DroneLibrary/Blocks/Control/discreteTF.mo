within DroneLibrary.Blocks.Control;
model discreteTF
    parameter Real ki=10 "I gain";
    parameter Real kd=5 "D gain";
    parameter Real kp=15 "P gain";
parameter Modelica.Units.SI.Time samplePeriod=0.01
  "Sample period of component";
    Modelica.Blocks.Interfaces.RealInput u
      annotation (Placement(transformation(extent={{-120,-20},{-80,20}})));
    Modelica.Blocks.Interfaces.RealOutput y
      annotation (Placement(transformation(extent={{100,-10},{120,10}})));

    Modelica.Blocks.Math.Feedback feedback
      annotation (Placement(transformation(extent={{-40,-10},{-20,10}})));
    Modelica.Blocks.Interfaces.RealInput u1 annotation (Placement(
          transformation(
          extent={{-20,-20},{20,20}},
          rotation=90,
          origin={0,-100})));

Modelica.Clocked.RealSignals.Periodic.TransferFunction transferFunction1(
  b={(kp + ki*samplePeriod/2 + kd/samplePeriod),(-kp + ki*samplePeriod/2 - 2*
      kd/samplePeriod),kd/samplePeriod},
  a={1,-1,0},
  x(each fixed=true))
  annotation (Placement(transformation(extent={{-14,-10},{6,10}})));
Modelica.Clocked.ClockSignals.Clocks.PeriodicRealClock periodicClock(period=
      period)
  annotation (Placement(transformation(extent={{-98,-36},{-86,-24}})));
Modelica.Clocked.RealSignals.Sampler.SampleClocked sample2
  annotation (Placement(transformation(extent={{-62,-6},{-50,6}})));
Modelica.Clocked.RealSignals.Sampler.Hold hold1
  annotation (Placement(transformation(extent={{66,-6},{78,6}})));
Modelica.Clocked.RealSignals.Sampler.SampleClocked sample1 annotation (
    Placement(transformation(
      extent={{-6,6},{6,-6}},
      rotation=90,
      origin={-32,-42})));
parameter Modelica.Units.SI.Time period=0.01
  "Period of clock (defined as Real number)";
equation

    connect(hold1.u, transferFunction1.y)
      annotation (Line(points={{64.8,0},{7,0}}, color={0,0,127}));
    connect(u, sample2.u)
      annotation (Line(points={{-100,0},{-63.2,0}}, color={0,0,127}));
    connect(feedback.u1, sample2.y)
      annotation (Line(points={{-38,0},{-49.4,0}}, color={0,0,127}));
    connect(feedback.u2, sample1.y) annotation (Line(points={{-30,-8},{
            -32,-8},{-32,-35.4}}, color={0,0,127}));
    connect(u1, sample1.u) annotation (Line(points={{0,-100},{-16,-100},{
            -16,-49.2},{-32,-49.2}}, color={0,0,127}));
    connect(periodicClock.y, sample1.clock) annotation (Line(
        points={{-85.4,-30},{-60,-30},{-60,-42},{-39.2,-42}},
        color={175,175,175},
        pattern=LinePattern.Dot,
        thickness=0.5));
    connect(sample2.clock, sample1.clock) annotation (Line(
        points={{-56,-7.2},{-58,-7.2},{-58,-30},{-60,-30},{-60,-42},{
            -39.2,-42}},
        color={175,175,175},
        pattern=LinePattern.Dot,
        thickness=0.5));
    connect(hold1.y, y)
      annotation (Line(points={{78.6,0},{110,0}}, color={0,0,127}));
    connect(feedback.y, transferFunction1.u)
      annotation (Line(points={{-21,0},{-16,0}}, color={0,0,127}));
    annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
            extent={{-100,100},{100,-100}},
            lineColor={0,0,0},
            fillColor={0,0,0},
            fillPattern=FillPattern.None),
          Rectangle(
            extent={{-80,-54},{-40,-56}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.Solid),
          Rectangle(
            extent={{-38,-56},{-40,0}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.Solid),
          Rectangle(
            extent={{-40,2},{0,0}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.Solid),
          Line(points={{0,20},{0,0}}, color={0,0,0}),
          Rectangle(
            extent={{2,0},{0,20}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.Solid),
          Rectangle(
            extent={{2,18},{80,20}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.Solid),
          Text(
            extent={{-72,94},{78,30}},
            lineColor={0,0,0},
            fillColor={28,108,200},
            fillPattern=FillPattern.None,
            textString="PID")}),
  Documentation(info="<html>
<p>This is a discrete PID block to create the discrete controller using the Modelica synchronous library.</p>
</html>"));
end discreteTF;
