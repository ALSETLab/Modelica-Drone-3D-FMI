within DroneSimulation.Blocks.Control;
model discretePID
  parameter Real ki=10 "I gain";
  parameter Real kd=5 "D gain";
  parameter Real kp=15 "P gain";
  parameter Modelica.SIunits.Time samplePeriod=0.01
    "Sample period of component";
  Modelica.Blocks.Discrete.TransferFunction transferFunction(samplePeriod=
        samplePeriod,
    a={1,-1,0},
    b={(kp + ki*samplePeriod/2 + kd/samplePeriod),(-kp + ki*samplePeriod/2
         - 2*kd/samplePeriod),kd/samplePeriod})
    annotation (Placement(transformation(extent={{-10,-10},{10,10}})));
  Modelica.Blocks.Interfaces.RealInput u
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}})));
  Modelica.Blocks.Interfaces.RealOutput y
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));

  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-78,-10},{-58,10}})));
  Modelica.Blocks.Interfaces.RealInput u1 annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={0,-100})));
  Modelica.Blocks.Discrete.Sampler sampler(samplePeriod=samplePeriod)
    annotation (Placement(transformation(extent={{20,-10},{40,10}})));
  Modelica.Blocks.Discrete.ZeroOrderHold zeroOrderHold(samplePeriod=
        samplePeriod)
    annotation (Placement(transformation(extent={{58,-10},{78,10}})));
equation
  connect(u, feedback.u1)
    annotation (Line(points={{-100,0},{-76,0}}, color={0,0,127}));
  connect(transferFunction.u, feedback.y)
    annotation (Line(points={{-12,0},{-59,0}}, color={0,0,127}));
  connect(feedback.u2, u1) annotation (Line(points={{-68,-8},{-68,-100},{0,
          -100}}, color={0,0,127}));
  connect(transferFunction.y, sampler.u)
    annotation (Line(points={{11,0},{18,0}}, color={0,0,127}));
  connect(sampler.y, zeroOrderHold.u)
    annotation (Line(points={{41,0},{56,0}}, color={0,0,127}));
  connect(y, zeroOrderHold.y)
    annotation (Line(points={{110,0},{79,0}}, color={0,0,127}));
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
          textString="PID")}),                                   Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end discretePID;
