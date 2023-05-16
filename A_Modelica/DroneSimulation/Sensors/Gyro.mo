within DroneSimulation.Sensors;
model Gyro
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b frame_b1
    "Coordinate system b"
    annotation (Placement(transformation(extent={{84,-16},{116,16}})));
  Modelica.Mechanics.MultiBody.Sensors.AbsoluteSensor absoluteSensor(get_v=
        false, get_w=true)
    annotation (Placement(transformation(extent={{8,-10},{-12,10}})));
  Modelica.Blocks.Interfaces.RealOutput w1[3]
                                      "Absolute angular velocity vector"
    annotation (Placement(transformation(extent={{-100,-12},{-120,8}})));
equation
  connect(absoluteSensor.frame_a, frame_b1) annotation (Line(
      points={{8,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(absoluteSensor.w, w1) annotation (Line(points={{-8,-11},{-8,-22},{-76,
          -22},{-76,-2},{-110,-2}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(
          extent={{-100,100},{100,-100}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.None)}));
end Gyro;
