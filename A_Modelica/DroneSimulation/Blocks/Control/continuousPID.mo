within DroneSimulation.Blocks.Control;
model continuousPID
  parameter Real kp=15 "P gain";

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

  parameter Modelica.Units.SI.Time Ti "Time Constant of Integrator";
  parameter Modelica.Units.SI.Time Td "Time Constant of Derivative block";
  Modelica.Blocks.Discrete.ZeroOrderHold zeroOrderHold(samplePeriod=0.0001)
    annotation (Placement(transformation(extent={{-46,-10},{-26,10}})));
  Modelica.Blocks.Continuous.Derivative derivative(
    k=kp,
    T=Td,
    initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-8,10},{12,30}})));
  Modelica.Blocks.Continuous.PI PI(
    k=kp,
    T=Ti,
    initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-8,-30},{12,-10}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{38,-10},{58,10}})));
  Modelica.Blocks.Discrete.ZeroOrderHold zeroOrderHold1(samplePeriod=0.05)
    annotation (Placement(transformation(extent={{68,-10},{88,10}})));
equation

  connect(u, feedback.u1)
    annotation (Line(points={{-100,0},{-76,0}}, color={0,0,127}));
  connect(feedback.u2, u1) annotation (Line(points={{-68,-8},{-68,-100},{0,
          -100}}, color={0,0,127}));
  connect(feedback.y, zeroOrderHold.u)
    annotation (Line(points={{-59,0},{-48,0}}, color={0,0,127}));
  connect(zeroOrderHold.y, derivative.u) annotation (Line(points={{-25,0},{-20,
          0},{-20,20},{-10,20}}, color={0,0,127}));
  connect(zeroOrderHold.y, PI.u) annotation (Line(points={{-25,0},{-20,0},{-20,
          -20},{-10,-20}}, color={0,0,127}));
  connect(derivative.y, add.u1)
    annotation (Line(points={{13,20},{22,20},{22,6},{36,6}}, color={0,0,127}));
  connect(PI.y, add.u2) annotation (Line(points={{13,-20},{22,-20},{22,-6},{36,
          -6}}, color={0,0,127}));
  connect(y, zeroOrderHold1.y)
    annotation (Line(points={{110,0},{89,0}}, color={0,0,127}));
  connect(add.y, zeroOrderHold1.u)
    annotation (Line(points={{59,0},{66,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None),
        Text(
          extent={{-28,98},{122,34}},
          lineColor={0,0,0},
          fillColor={28,108,200},
          fillPattern=FillPattern.None,
          textString="PID"),
                          Line(
          origin={-7.939,-5.816},
          points={{81.939,36.056},{65.362,36.056},{14.39,-26.199},{-29.966,
              113.485},{-65.374,-61.217},{-78.061,-78.184}},
          color={95,95,95},
          smooth=Smooth.Bezier,
          thickness=1)}),                                        Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end continuousPID;
