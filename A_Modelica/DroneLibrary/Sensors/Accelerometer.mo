within DroneLibrary.Sensors;
model Accelerometer
  Modelica.Mechanics.MultiBody.Sensors.RelativeAngles relativeAngles
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={10,40})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{84,-16},{116,16}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed
    annotation (Placement(transformation(extent={{-74,30},{-54,50}})));
  Modelica.Blocks.Interfaces.RealOutput y[3] annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-110,0})));
equation
  connect(relativeAngles.frame_b, frame_a) annotation (Line(
      points={{20,40},{20,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngles.frame_a, fixed.frame_b) annotation (Line(
      points={{-8.88178e-16,40},{-54,40}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngles.angles, y) annotation (Line(points={{10,29},{10,
          -4.44089e-16},{-110,-4.44089e-16}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None), Text(
          extent={{-74,32},{76,-54}},
          lineColor={0,0,0},
          fillColor={28,108,200},
          fillPattern=FillPattern.None,
          textString="Accelerometer
")}));
end Accelerometer;
