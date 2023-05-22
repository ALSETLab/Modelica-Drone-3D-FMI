within DroneLibrary.Mechanical.Rotor.Examples;
model rotor3
  extends DroneLibrary.Mechanical.Rotor.Templates.rotor;
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute(animation=false)
    annotation (Placement(transformation(extent={{10,14},{30,34}})));

  Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
    relativeAngularVelocity
    annotation (Placement(transformation(extent={{12,36},{32,56}})));

  Modelica.Blocks.Sources.RealExpression aero_torque(y=-3.5e-6*(
        relativeAngularVelocity.w_rel[3])^2)
    annotation (Placement(transformation(extent={{-92,-86},{-72,-66}})));
  Blocks.Routing.RealExtend realExtend1 annotation (Placement(
        transformation(
        extent={{-6,-6},{6,6}},
        origin={-18,-76})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque
    annotation (Placement(transformation(extent={{4,-66},{24,-86}})));
  Modelica.Blocks.Math.Gain gain(k=k)
    annotation (Placement(transformation(extent={{-52,-80},{-44,-72}})));
  parameter Real k "Gain value multiplied with input signal";
equation
  connect(relativeAngularVelocity.frame_a, revolute.frame_a) annotation (Line(
      points={{12,46},{6,46},{6,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(relativeAngularVelocity.frame_b, revolute.frame_b) annotation (Line(
      points={{32,46},{42,46},{42,24},{30,24}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{-11.4,-76},{2,-76}}, color={0,0,127}));
  connect(aero_torque.y, gain.u)
    annotation (Line(points={{-71,-76},{-52.8,-76}}, color={0,0,127}));
  connect(gain.y, realExtend1.u)
    annotation (Line(points={{-43.6,-76},{-25.2,-76}}, color={0,0,127}));
  connect(torque_1, revolute.frame_a) annotation (Line(
      points={{-102,60},{-48,60},{-48,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(force, revolute.frame_a) annotation (Line(
      points={{-102,-62},{-48,-62},{-48,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(Airframe, revolute.frame_a) annotation (Line(
      points={{102,52},{56,52},{56,80},{6,80},{6,24},{10,24}},
      color={95,95,95},
      thickness=0.5));
  connect(Blade, revolute.frame_b) annotation (Line(
      points={{102,-40},{72,-40},{72,24},{30,24}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, revolute.frame_b) annotation (Line(
      points={{-102,0},{72,0},{72,24},{30,24}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b, revolute.frame_b) annotation (Line(
      points={{24,-76},{48,-76},{48,-40},{72,-40},{72,24},{30,24}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}));
end rotor3;
