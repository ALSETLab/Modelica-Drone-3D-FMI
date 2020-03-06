within DroneSimulation.Mechanical.Motor;
model DCMotor_EPDCMachine "DC motor using DC machine from MSL"

  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8,
    uMin=0,
    homotopyType=Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)
    annotation (Placement(transformation(extent={{-80,56},{-72,64}})));


  Electrification.Electrical.DCSplitter splitterHVDC annotation (Placement(
        transformation(
        extent={{-4,4},{4,-4}},
        rotation=90,
        origin={-62,-12})));
  Electrification.Electrical.DCTripleSensor dcSensor
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=270,
        origin={-90,-28})));
              Electrification.Machines.Examples.DCMachineIdeal
                                   machine(enable_thermal_port=true,
    internal_ground=true,
    redeclare Electrification.Machines.Mechanical.RotorInertia mechanical,
    redeclare replaceable Electrification.Machines.Control.TorqueControl
      controller)                                                 annotation (Placement(transformation(extent={{-82,-60},
            {-62,-40}})));
public
  Modelica.Thermal.HeatTransfer.Celsius.FixedTemperature ambientTemperature(T=40)
    annotation (Placement(transformation(extent={{-2,70},{18,90}})));
  Modelica.Thermal.HeatTransfer.Sources.FixedHeatFlow converterCoolingHeat(Q_flow=-1000)
    annotation (Placement(transformation(extent={{-2,38},{18,58}})));
  Modelica.Thermal.HeatTransfer.Sources.FixedHeatFlow machineCoolingHeat(Q_flow=-1000) annotation (Placement(transformation(extent={{-2,8},{
            18,28}})));
  Electrification.Machines.Thermal.Adapters.Ambient ambient
    annotation (Placement(transformation(extent={{32,76},{24,84}})));
  Electrification.Machines.Thermal.Adapters.MachineLumped machineLumped
    annotation (Placement(transformation(extent={{30,14},{22,22}})));
  Electrification.Machines.Thermal.Adapters.ConverterLumped converterLumped
    annotation (Placement(transformation(extent={{30,44},{22,52}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{10,-78},{30,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{52,0},{60,8}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
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

  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{-52,-4},{-72,16}})));
  Electrification.Machines.Control.Adapters.Input_tau_ref input_tau_ref
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=180,
        origin={-30,30})));
  Modelica.Blocks.Math.Gain gain(k=4) annotation (Placement(transformation(
        extent={{-6,-6},{6,6}},
        rotation=270,
        origin={-62,32})));
  Modelica.Blocks.Sources.Cosine trq_cmd(amplitude=10, freqHz=1000)
    annotation (Placement(transformation(extent={{-60,60},{-40,80}})));
  Modelica.Mechanics.Rotational.Sensors.TorqueSensor torqueSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-16,-60})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-26,-84},{-6,-64}})));
  Modelica.Blocks.Math.Gain gain2(k=-1)
    annotation (Placement(transformation(extent={{14,-46},{34,-26}})));
equation
  connect(position, limiter.u)
    annotation (Line(points={{-120,0},{-88,0},{-88,60},{-80.8,60}},
                                                  color={0,0,127}));
  connect(dcSensor.plug_a,splitterHVDC. plug_a) annotation (Line(
      points={{-90,-22},{-90,-16},{-62,-16}},
      color={255,128,0},
      thickness=0.5));
  connect(dcSensor.plug_b, machine.plug_a) annotation (Line(
      points={{-90,-34},{-90,-50},{-82,-50}},
      color={255,128,0},
      thickness=0.5));
  connect(ambient.heat,ambientTemperature. port)
    annotation (Line(points={{24,80},{18,80}}, color={191,0,0}));
  connect(ambient.machine, machine.thermalPort) annotation (Line(points={{32,80},
          {36,80},{36,-16},{-10,-16},{-10,-28},{-72,-28},{-72,-40}},
                                          color={191,0,0}));
  connect(machineLumped.machine, machine.thermalPort)
    annotation (Line(points={{30,18},{36,18},{36,-16},{-10,-16},{-10,-28},{-72,-28},
          {-72,-40}},                                color={191,0,0}));
  connect(machineCoolingHeat.port,machineLumped. heat)
    annotation (Line(points={{18,18},{22,18}}, color={191,0,0}));
  connect(converterCoolingHeat.port,converterLumped. heat)
    annotation (Line(points={{18,48},{22,48}}, color={191,0,0}));
  connect(converterLumped.machine, machine.thermalPort) annotation (Line(points={{30,48},
          {36,48},{36,-16},{-10,-16},{-10,-28},{-72,-28},{-72,-40}},
                                                  color={191,0,0}));
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
  connect(signalVoltage.n, splitterHVDC.n) annotation (Line(points={{-72,6},{-78,
          6},{-78,-8},{-66,-8}}, color={0,0,255}));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{66,-72},{66,-80},{80,-80},{80,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(machine.controlBus, input_tau_ref.systemBus) annotation (Line(
      points={{-80,-40},{-80,-22},{-30,-22},{-30,20}},
      color={240,170,40},
      pattern=LinePattern.Dot,
      thickness=0.5));
  connect(limiter.y, gain.u) annotation (Line(points={{-71.6,60},{-62,60},{-62,
          39.2}}, color={0,0,127}));
  connect(signalVoltage.v, gain.y)
    annotation (Line(points={{-62,18},{-62,25.4}}, color={0,0,127}));
  connect(signalVoltage.p, splitterHVDC.p) annotation (Line(points={{-52,6},{
          -44,6},{-44,-8},{-58,-8}}, color={0,0,255}));
  connect(trq_cmd.y, input_tau_ref.tau_ref)
    annotation (Line(points={{-39,70},{-30,70},{-30,40}}, color={0,0,127}));
  connect(torqueSensor.tau, gain1.u) annotation (Line(points={{-5,-52},{4,-52},
          {4,-68},{8,-68}}, color={0,0,127}));
  connect(torqueSensor.flange_b, fixed.flange)
    annotation (Line(points={{-16,-70},{-16,-74}}, color={0,0,0}));
  connect(realExtend.u, gain2.y) annotation (Line(points={{51.2,4},{46,4},{46,
          -36},{35,-36}}, color={0,0,127}));
  connect(gain2.u, gain1.u) annotation (Line(points={{12,-36},{4,-36},{4,-68},{
          8,-68}}, color={0,0,127}));
  connect(torqueSensor.flange_a, machine.flange)
    annotation (Line(points={{-16,-50},{-62,-50}}, color={0,0,0}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_EPDCMachine;
