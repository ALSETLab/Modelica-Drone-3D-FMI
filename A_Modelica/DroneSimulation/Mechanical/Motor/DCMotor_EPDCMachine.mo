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
  Modelica.Mechanics.Rotational.Sensors.TorqueSensor torqueSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-40,-76})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-46,-98},{-34,-86}})));
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
    annotation (Placement(transformation(extent={{22,38},{12,48}})));
  Electrification.Machines.Control.Adapters.Input_tau_ref
                                 torqueCommand annotation (Placement(
        transformation(
        extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-40,14})));
  replaceable Electrification.Machines.Examples.DCMachineIdeal
                                   machine(
    enable_thermal_port=false,
    internal_ground=true,
    redeclare Electrification.Machines.Core.Examples.Ideal core,
    redeclare Electrification.Machines.Electrical.Resistor electrical)
    constrainedby Electrification.Machines.Examples.DCMachine(internal_ground=
        true)                                                     annotation (Placement(transformation(extent={{-82,-60},
            {-62,-40}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{-52,-4},{-72,16}})));
  Modelica.Mechanics.Rotational.Components.Inertia inertia(
    J=0.1,
    w(fixed=true, start=0),
    phi(fixed=true, start=0))
    annotation (Placement(transformation(extent={{-58,-60},{-38,-40}})));
equation
  connect(position, limiter.u)
    annotation (Line(points={{-120,0},{-88,0},{-88,34},{-78.8,34}},
                                                  color={0,0,127}));
  connect(torqueSensor.flange_b, fixed.flange)
    annotation (Line(points={{-40,-86},{-40,-92}}, color={0,0,0}));
  connect(dcSensor.plug_a,splitterHVDC. plug_a) annotation (Line(
      points={{-90,-22},{-90,-16},{-62,-16}},
      color={255,128,0},
      thickness=0.5));
  connect(torqueCommand.tau_ref,trq_cmd. y)
    annotation (Line(points={{-40,18},{-40,43},{11.5,43}},
                                                        color={0,0,127}));
  connect(torqueCommand.systemBus, machine.controlBus) annotation (Line(
      points={{-40,10},{-40,-26},{-80,-26},{-80,-40}},
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
  connect(machine.flange, inertia.flange_a)
    annotation (Line(points={{-62,-50},{-58,-50}}, color={0,0,0}));
  connect(inertia.flange_b, torqueSensor.flange_a)
    annotation (Line(points={{-38,-50},{-40,-50},{-40,-66}}, color={0,0,0}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_EPDCMachine;
