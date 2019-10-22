within DroneSimulation.Mechanical;
model Propeller
  DCMotor dCMotor(k=PropellerGain)
    annotation (Placement(transformation(extent={{-66,-10},{-46,10}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  rotor rotor1
    annotation (Placement(transformation(extent={{-8,10},{12,-10}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,-20},{118,12}})));
  Blades blades
    annotation (Placement(transformation(extent={{68,28},{88,48}})));
  parameter Real PropellerGain=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
equation
  connect(dCMotor.position, position)
    annotation (Line(points={{-68.2,0},{-122,0}}, color={0,0,127}));
  connect(rotor1.Airframe, Airframe) annotation (Line(
      points={{12.2,-5.2},{102,-5.2},{102,-4}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.torque2, dCMotor.torque) annotation (Line(points={{-10,-6},{
          -28,-6},{-28,-6.8},{-45,-6.8}}, color={0,0,127}));
  connect(rotor1.force, dCMotor.force_out) annotation (Line(
      points={{-8.2,0},{-45.8,0}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.Blade, blades.Input) annotation (Line(
      points={{12.2,4},{42,4},{42,40},{67.6,40},{67.6,38}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end Propeller;
