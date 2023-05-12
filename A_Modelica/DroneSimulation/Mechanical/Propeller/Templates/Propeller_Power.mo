within DroneSimulation.Mechanical.Propeller.Templates;
partial model Propeller_Power
  replaceable
  DroneSimulation.Mechanical.Motor.Templates.DCMotor_Power
          DCMotor(k=PropellerGain)
    annotation (Placement(transformation(extent={{-80,-20},{-40,20}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  replaceable Rotor.Examples.rotor rotor1
    annotation (Placement(transformation(extent={{-16,20},{26,-20}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,-26},{118,6}})));
  replaceable DroneSimulation.Mechanical.Blades.Templates.Blades blades
    annotation (Placement(transformation(extent={{50,6},{92,46}})));
  parameter Real PropellerGain=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Electrical.Analog.Interfaces.PositivePin p1
                           "pin to be measured"
    annotation (Placement(transformation(extent={{-110,20},{-90,40}})));
equation
  connect(DCMotor.position, position)
    annotation (Line(points={{-84,0},{-122,0}},   color={0,0,127}));
  connect(rotor1.Airframe, Airframe) annotation (Line(
      points={{26.42,-10.4},{102,-10.4},{102,-10}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.Blade, blades.Input) annotation (Line(
      points={{26.42,8},{36,8},{36,26},{49.16,26}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.torque_2,DCMotor. torque_1) annotation (Line(
      points={{-16.42,0},{-40,0}},
      color={95,95,95},
      thickness=0.5));
  connect(DCMotor.torque_2, rotor1.torque_1) annotation (Line(
      points={{-40,-12},{-16.42,-12}},
      color={95,95,95},
      thickness=0.5));
  connect(rotor1.force,DCMotor. force_out) annotation (Line(
      points={{-16.42,12.4},{-40,12.4}},
      color={95,95,95},
      thickness=0.5));
  connect(DCMotor.p1, p1) annotation (Line(points={{-80,8},{-88,8},{-88,16},{-86,
          16},{-86,30},{-100,30}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-40},{100,60}})),                               Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-100,-40},{100,
            60}})));
end Propeller_Power;
