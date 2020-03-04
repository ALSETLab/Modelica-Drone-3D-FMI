within DroneSimulation.Mechanical.Motor;
model DCMotor_EPDCMachine "DC motor using DC machine from MSL"

  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}}),
        iconTransformation(extent={{-140,-20},{-100,20}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0,
    homotopyType=Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)
    annotation (Placement(transformation(extent={{-78,30},{-70,38}})));
  parameter Modelica.SIunits.Voltage VaNominal=5
    "Nominal armature voltage for motor";
  parameter Modelica.SIunits.Current IaNominal=0.1
    "Nominal armature current (>0..Motor, <0..Generator) for motor";
  parameter Modelica.SIunits.Voltage V
    "Battery voltage";

  parameter Modelica.SIunits.Resistance R=100 "Resistance at temperature T_ref";
  Electrification.Electrical.DCSplitter splitterHVDC annotation (Placement(
        transformation(
        extent={{-4,4},{4,-4}},
        rotation=90,
        origin={-62,-12})));
  Electrification.Electrical.DCTripleSensor dcSensor
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=270,
        origin={-90,-28})));
  replaceable
  Modelica.Blocks.Sources.Cosine trq_cmd(amplitude=150, freqHz=2) constrainedby
    Modelica.Blocks.Sources.Cosine
    annotation (Placement(transformation(extent={{-78,48},{-68,58}})));
  Electrification.Machines.Control.Adapters.Input_tau_ref
                                 torqueCommand annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-46,14})));
  replaceable Electrification.Machines.Examples.DCMachineIdeal
                                   machine(enable_thermal_port=true,
    internal_ground=true)
    constrainedby Electrification.Machines.Examples.DCMachine(internal_ground=
        true)                                                     annotation (Placement(transformation(extent={{-82,-60},
            {-62,-40}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{-52,-4},{-72,16}})));
public
  Modelica.Thermal.HeatTransfer.Celsius.FixedTemperature ambientTemperature(T=40)
    annotation (Placement(transformation(extent={{-28,70},{-8,90}})));
  Modelica.Thermal.HeatTransfer.Sources.FixedHeatFlow converterCoolingHeat(Q_flow=-1000)
    annotation (Placement(transformation(extent={{-28,38},{-8,58}})));
  Modelica.Thermal.HeatTransfer.Sources.FixedHeatFlow machineCoolingHeat(Q_flow=-1000) annotation (Placement(transformation(extent={{-28,8},
            {-8,28}})));
  Electrification.Machines.Thermal.Adapters.Ambient ambient
    annotation (Placement(transformation(extent={{6,76},{-2,84}})));
  Electrification.Machines.Thermal.Adapters.MachineLumped machineLumped
    annotation (Placement(transformation(extent={{4,14},{-4,22}})));
  Electrification.Machines.Thermal.Adapters.ConverterLumped converterLumped
    annotation (Placement(transformation(extent={{4,44},{-4,52}})));
  Modelica.Mechanics.Rotational.Sensors.MultiSensor multiSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-14,-64})));
  Modelica.Mechanics.Rotational.Components.Inertia inertia(
    J=0.1,
    w(fixed=true, start=0),
    phi(fixed=true, start=0))
    annotation (Placement(transformation(extent={{-46,-60},{-26,-40}})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-20,-94},{-8,-82}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{10,-78},{30,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{26,0},{34,8}})));
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
    annotation (Placement(transformation(extent={{84,44},{116,76}}),
        iconTransformation(extent={{84,44},{116,76}})));
equation
  connect(position, limiter.u)
    annotation (Line(points={{-120,0},{-88,0},{-88,34},{-78.8,34}},
                                                  color={0,0,127}));
  connect(dcSensor.plug_a,splitterHVDC. plug_a) annotation (Line(
      points={{-90,-22},{-90,-16},{-62,-16}},
      color={255,128,0},
      thickness=0.5));
  connect(torqueCommand.tau_ref,trq_cmd. y)
    annotation (Line(points={{-46,18},{-46,53},{-67.5,53}},
                                                        color={0,0,127}));
  connect(torqueCommand.systemBus, machine.controlBus) annotation (Line(
      points={{-46,10},{-46,-26},{-80,-26},{-80,-40}},
      color={240,170,40},
      pattern=LinePattern.Dot,
      thickness=0.5));
  connect(dcSensor.plug_b, machine.electricalPort_a) annotation (Line(
      points={{-90,-34},{-90,-50},{-82,-50}},
      color={255,128,0},
      thickness=0.5));
  connect(signalVoltage.n, splitterHVDC.n) annotation (Line(points={{-72,6},{
          -78,6},{-78,-6},{-66,-6},{-66,-8}}, color={0,0,255}));
  connect(signalVoltage.p, splitterHVDC.p) annotation (Line(points={{-52,6},{
          -48,6},{-48,-6},{-58,-6},{-58,-8}}, color={0,0,255}));
  connect(signalVoltage.v, limiter.y)
    annotation (Line(points={{-62,18},{-62,34},{-69.6,34}}, color={0,0,127}));
  connect(ambient.heat,ambientTemperature. port)
    annotation (Line(points={{-2,80},{-8,80}}, color={191,0,0}));
  connect(ambient.machine, machine.thermalPort) annotation (Line(points={{6,80},{
          10,80},{10,-16},{-36,-16},{-36,-28},{-72,-28},{-72,-40}},
                                          color={191,0,0}));
  connect(machineLumped.machine, machine.thermalPort)
    annotation (Line(points={{4,18},{10,18},{10,-16},{-36,-16},{-36,-28},{-72,
          -28},{-72,-40}},                           color={191,0,0}));
  connect(machineCoolingHeat.port,machineLumped. heat)
    annotation (Line(points={{-8,18},{-4,18}}, color={191,0,0}));
  connect(converterCoolingHeat.port,converterLumped. heat)
    annotation (Line(points={{-8,48},{-4,48}}, color={191,0,0}));
  connect(converterLumped.machine, machine.thermalPort) annotation (Line(points={{4,48},{
          10,48},{10,-16},{-36,-16},{-36,-28},{-72,-28},{-72,-40}},
                                                  color={191,0,0}));
  connect(machine.flange, inertia.flange_a)
    annotation (Line(points={{-62,-50},{-46,-50}}, color={0,0,0}));
  connect(multiSensor.flange_a, inertia.flange_b)
    annotation (Line(points={{-14,-54},{-14,-50},{-26,-50}}, color={0,0,0}));
  connect(multiSensor.flange_b, fixed.flange)
    annotation (Line(points={{-14,-74},{-14,-88}}, color={0,0,0}));
  connect(force_out,force. frame_b) annotation (Line(
      points={{100,60},{74,60},{74,42}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b,torque_1)  annotation (Line(
      points={{66,-52},{66,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{66,-72},{68,-72},{68,-88},{80,-88},{80,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.torque, realExtend1.y)
    annotation (Line(points={{54,-68},{44.4,-68}}, color={0,0,127}));
  connect(force.force, realExtend.y)
    annotation (Line(points={{74,20},{74,4},{34.4,4}}, color={0,0,127}));
  connect(realExtend1.u, gain1.y)
    annotation (Line(points={{35.2,-68},{31,-68}}, color={0,0,127}));
  connect(multiSensor.tau, gain1.u) annotation (Line(points={{-3,-64},{4,-64},{
          4,-68},{8,-68}}, color={0,0,127}));
  connect(realExtend.u, gain1.u) annotation (Line(points={{25.2,4},{18,4},{18,
          -26},{4,-26},{4,-68},{8,-68}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_EPDCMachine;