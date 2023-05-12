within DroneSimulation.Mechanical.Motor;
model DCMotor_EMF
extends DroneSimulation.Mechanical.Motor.Templates.DCMotor;
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(color={244,0,4},
      resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={36,0})));

  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{16,-78},{36,-58}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-30,-78},{-10,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-10,-4},{-2,4}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0,
    homotopyType=Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)
    annotation (Placement(transformation(extent={{-94,-4},{-86,4}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={70,-62})));
  Electrical.Machines.SimpleMotor_EMF simpleMotor_EMF(
    R_trs=0.1,
    X_s=0.2,
    R_hyst=1)
    annotation (Placement(transformation(extent={{-74,-10},{-54,10}})));
  Modelica.Mechanics.Rotational.Sensors.TorqueSensor torqueSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-40,-16})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-78,-62},{-58,-42}})));
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{-9,-68},{14,-68}}, color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-1.6,0},{24,0}},
                               color={0,0,127}));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{37,-68},{58,-68}}, color={0,0,127}));
  connect(limiter.y, simpleMotor_EMF.Current)
    annotation (Line(points={{-85.6,0},{-76,0}}, color={0,0,127}));
  connect(simpleMotor_EMF.flange1, torqueSensor.flange_a)
    annotation (Line(points={{-53.6,0},{-40,0},{-40,-6}}, color={0,0,0}));
  connect(gain1.u, realExtend.u) annotation (Line(points={{-32,-68},{-42,-68},{
          -42,-34},{-20,-34},{-20,0},{-10.8,0}}, color={0,0,127}));
  connect(torqueSensor.flange_b, fixed.flange) annotation (Line(points={{-40,
          -26},{-54,-26},{-54,-52},{-68,-52}}, color={0,0,0}));
  connect(torqueSensor.tau, realExtend.u) annotation (Line(points={{-29,-8},{
          -20,-8},{-20,0},{-10.8,0}}, color={0,0,127}));
  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{100,60},{56,60},{56,0},{46,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, torque.frame_b) annotation (Line(
      points={{100,0},{70,0},{70,-52}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, torque.frame_a) annotation (Line(
      points={{100,-60},{86,-60},{86,-72},{70,-72}},
      color={95,95,95},
      thickness=0.5));
  connect(position, limiter.u) annotation (Line(points={{-122,0},{-110,0},{-110,
          0},{-94.8,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_EMF;
