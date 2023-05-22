within DroneLibrary.Blocks.Control;
model continuousPID
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
    annotation (Placement(transformation(extent={{-78,-10},{-58,10}})));
  Modelica.Blocks.Interfaces.RealInput u1 annotation (Placement(
        transformation(
        extent={{-20,-20},{20,20}},
        rotation=90,
        origin={0,-100})));

Modelica.Blocks.Continuous.TransferFunction transferFunction1(
    b={(kp + ki*2 + kd),(-kp + ki*2 - 2*kd),kd},
    a={1,-1,0},
    x(fixed=true))
  annotation (Placement(transformation(extent={{4,-10},{24,10}})));
equation

  connect(u, feedback.u1)
    annotation (Line(points={{-100,0},{-76,0}}, color={0,0,127}));
  connect(feedback.u2, u1) annotation (Line(points={{-68,-8},{-68,-100},{0,
          -100}}, color={0,0,127}));
  connect(transferFunction1.u, feedback.y)
    annotation (Line(points={{2,0},{-59,0}}, color={0,0,127}));
  connect(transferFunction1.y, y)
    annotation (Line(points={{25,0},{110,0}}, color={0,0,127}));
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
          thickness=1)}),
    Documentation(info="<html>
<p>This is a block used to model the PID functions in the continuous controller.</p>
</html>"));
end continuousPID;
