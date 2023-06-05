within DroneLibrary.Mechanical.Propeller.Variants;
model Phantom
  Motor.Variants.DCMotor dCMotor(k=PropellerGain) annotation (Placement(transformation(extent={{-80,-20},{-40,20}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  Rotor.Variants.rotor rotor1 annotation (Placement(transformation(extent={{-16,20},{26,-20}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,-26},{118,6}})));
  Blades.Variants.Phantom phantom_Blades
    annotation (Placement(transformation(extent={{50,6},{92,46}})));
  parameter Real PropellerGain=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
equation
  connect(dCMotor.position, position)
    annotation (Line(points={{-84.4,0},{-122,0}}, color={0,0,127}));
  connect(rotor1.Airframe, Airframe) annotation (Line(
      points={{26.42,-10.4},{102,-10.4},{102,-10}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.Blade, phantom_Blades.Input) annotation (Line(
      points={{26.42,8},{36,8},{36,26},{49.16,26}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.torque_2, dCMotor.torque_1) annotation (Line(
      points={{-16.42,0},{-40,0}},
      color={95,95,95},
      thickness=0.5));
  connect(dCMotor.torque_2, rotor1.torque_1) annotation (Line(
      points={{-40,-12},{-16.42,-12}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.force, dCMotor.force_out) annotation (Line(
      points={{-16.42,12.4},{-40,12.4}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-40},{100,60}})), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-100,-40},{100,
            60}})));
end Phantom;
