within DroneSimulation.Sensors;
model GPS
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{-116,-16},{-84,16}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={0,-70})));
  Modelica.Mechanics.MultiBody.Sensors.RelativePosition relativePosition(
      resolveInFrame=resolveInFrame)
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-40,0})));
  Modelica.Blocks.Interfaces.RealOutput y[3]
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  parameter Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB.frame_a
    "GPS location frame";
equation
  connect(relativePosition.frame_a, fixed.frame_b) annotation (Line(
      points={{-30,-1.77636e-15},{0,-1.77636e-15},{0,-60},{6.66134e-16,
          -60}},
      color={95,95,95},
      thickness=0.5));
  connect(frame_a, relativePosition.frame_b) annotation (Line(
      points={{-100,0},{-50,0}},
      color={95,95,95},
      thickness=0.5));
  connect(relativePosition.r_rel, y) annotation (Line(points={{-40,11},{
          32,11},{32,0},{110,0}}, color={0,0,127}));
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
          textString="GPS
")}));
end GPS;
