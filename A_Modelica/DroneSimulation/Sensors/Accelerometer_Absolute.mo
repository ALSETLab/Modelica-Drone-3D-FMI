within DroneSimulation.Sensors;
model Accelerometer_Absolute
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
    annotation (Placement(transformation(extent={{84,-16},{116,16}})));
  Modelica.Blocks.Interfaces.RealOutput y[3] annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-110,0})));
  Modelica.Mechanics.MultiBody.Sensors.AbsoluteSensor absoluteSensor(get_a=true)
    annotation (Placement(transformation(extent={{12,-10},{-8,10}})));
equation
  connect(frame_a, absoluteSensor.frame_a) annotation (Line(
      points={{100,0},{12,0}},
      color={95,95,95},
      thickness=0.5));
  connect(y, absoluteSensor.a) annotation (Line(points={{-110,0},{-54,0},{-54,
          -11},{4,-11},{4,-11}}, color={0,0,127}));
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
end Accelerometer_Absolute;
