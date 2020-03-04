within DroneSimulation.Sensors;
model Height
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{-116,-16},{-84,16}})));
  Modelica.Blocks.Interfaces.RealOutput y[3]
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  Modelica.Mechanics.MultiBody.Sensors.AbsolutePosition absolutePosition
    annotation (Placement(transformation(extent={{-14,-10},{6,10}})));
equation
  connect(absolutePosition.frame_a, frame_a) annotation (Line(
      points={{-14,0},{-100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(y, absolutePosition.r)
    annotation (Line(points={{110,0},{7,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None), Text(
          extent={{-76,26},{78,-72}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None,
          textString="Height
")}), Diagram(coordinateSystem(preserveAspectRatio=false)));
end Height;
