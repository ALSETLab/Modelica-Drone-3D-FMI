within DroneSimulation.Examples.DroneWithoutIdealPower;
model PropellerTest
  Mechanical.Propeller_DCMachine propeller_DCMachine(PropellerGain=1)
    annotation (Placement(transformation(extent={{-8,-4},{12,6}})));
  Modelica.Blocks.Sources.Ramp ramp(height=2, duration=1)
    annotation (Placement(transformation(extent={{-68,-10},{-48,10}})));
equation
  connect(propeller_DCMachine.position, ramp.y)
    annotation (Line(points={{-10,0},{-47,0}},   color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end PropellerTest;
