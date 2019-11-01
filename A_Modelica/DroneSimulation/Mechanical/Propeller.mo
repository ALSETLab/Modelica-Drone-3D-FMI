within DroneSimulation.Mechanical;
model Propeller
  DCMotor dCMotor(k=PropellerGain)
    annotation (Placement(transformation(extent={{-82,-22},{-42,18}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  rotor rotor1
    annotation (Placement(transformation(extent={{-16,18},{26,-22}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,-26},{118,6}})));
  Blades blades
    annotation (Placement(transformation(extent={{50,6},{92,46}})));
  parameter Real PropellerGain=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
equation
  connect(dCMotor.position, position)
    annotation (Line(points={{-86.4,-2},{-104,-2},{-104,0},{-122,0}},
                                                  color={0,0,127}));
  connect(rotor1.Airframe, Airframe) annotation (Line(
      points={{26.42,-12.4},{102,-12.4},{102,-10}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.Blade, blades.Input) annotation (Line(
      points={{26.42,6},{36,6},{36,26},{49.16,26}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.torque_2, dCMotor.torque_1) annotation (Line(
      points={{-16.42,-2},{-29.21,-2},{-29.21,-2},{-42,-2}},
      color={95,95,95},
      thickness=0.5));
  connect(dCMotor.torque_2, rotor1.torque_1) annotation (Line(
      points={{-42,-14},{-28.8,-14},{-28.8,-14},{-16.42,-14}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.force, dCMotor.force_out) annotation (Line(
      points={{-16,10.4},{-30,10.4},{-30,10.4},{-42,10.4}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-40},{100,60}})),                               Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-100,-40},{100,
            60}})));
end Propeller;
