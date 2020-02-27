within DroneSimulation.Examples;
model test
  inner Modelica.Mechanics.MultiBody.World world
    annotation (Placement(transformation(extent={{-46,2},{-26,22}})));
  Mechanical.Blades.Blades2 blades2_1
    annotation (Placement(transformation(extent={{-10,2},{10,22}})));
equation
  connect(world.frame_b, blades2_1.Input) annotation (Line(
      points={{-26,12},{-10.4,12}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end test;
