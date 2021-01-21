within DroneSimulation.Mechanical.Motor;
model DCMotor_Averaged_Machine "DC motor using DC machine from MSL"

  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8,
    uMin=0,
    homotopyType=Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-90,-16})));

  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{10,-78},{30,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{52,0},{60,8}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={74,32})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{36,-72},{44,-64}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque(animation=false)
                                                    annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={66,-62})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a torque_2
    "Coordinate system a fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-76},{116,-44}}),
        iconTransformation(extent={{84,-76},{116,-44}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b torque_1
    "Coordinate system b fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-16},{116,16}}),
        iconTransformation(extent={{84,-16},{116,16}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  parameter Real V=V "Reference voltage";
  parameter Real R=R "reference resistance";

  Modelica.Mechanics.Rotational.Sensors.TorqueSensor torqueSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-16,-60})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-26,-84},{-6,-64}})));
  Modelica.Blocks.Math.Gain gain2(k=-1)
    annotation (Placement(transformation(extent={{14,-46},{34,-26}})));
  BrushlessDCDrives.Machines.Averaged machine(redeclare
      BrushlessDCDrives.Machines.Records.Data.Sinusoidal.MSL data)
    annotation (Placement(transformation(extent={{-50,-44},{-30,-24}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage annotation (
      Placement(transformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-72,-32})));
equation
  connect(position, limiter.u)
    annotation (Line(points={{-120,0},{-90,0},{-90,-11.2}},
                                                  color={0,0,127}));
  connect(force_out,force. frame_b) annotation (Line(
      points={{100,62},{74,62},{74,42}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b,torque_1)  annotation (Line(
      points={{66,-52},{66,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.torque, realExtend1.y)
    annotation (Line(points={{54,-68},{44.4,-68}}, color={0,0,127}));
  connect(force.force, realExtend.y)
    annotation (Line(points={{74,20},{74,4},{60.4,4}}, color={0,0,127}));
  connect(realExtend1.u, gain1.y)
    annotation (Line(points={{35.2,-68},{31,-68}}, color={0,0,127}));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{66,-72},{66,-80},{80,-80},{80,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(torqueSensor.tau, gain1.u) annotation (Line(points={{-5,-52},{4,-52},
          {4,-68},{8,-68}}, color={0,0,127}));
  connect(torqueSensor.flange_b, fixed.flange)
    annotation (Line(points={{-16,-70},{-16,-74}}, color={0,0,0}));
  connect(realExtend.u, gain2.y) annotation (Line(points={{51.2,4},{46,4},{46,
          -36},{35,-36}}, color={0,0,127}));
  connect(gain2.u, gain1.u) annotation (Line(points={{12,-36},{4,-36},{4,-68},{
          8,-68}}, color={0,0,127}));
  connect(torqueSensor.flange_a, machine.flange)
    annotation (Line(points={{-16,-50},{-16,-34},{-30,-34}}, color={0,0,0}));
  connect(machine.pin_p, signalVoltage.p) annotation (Line(points={{-50,-28},{
          -62,-28},{-62,-22},{-72,-22}}, color={0,0,255}));
  connect(machine.pin_n, signalVoltage.n) annotation (Line(points={{-50,-40},{
          -62,-40},{-62,-42},{-72,-42}}, color={0,0,255}));
  connect(limiter.y, signalVoltage.v) annotation (Line(points={{-90,-20.4},{-90,
          -32},{-84,-32}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_Averaged_Machine;
