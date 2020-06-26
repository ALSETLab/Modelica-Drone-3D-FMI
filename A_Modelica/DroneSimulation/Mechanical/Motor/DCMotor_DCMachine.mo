within DroneSimulation.Mechanical.Motor;
model DCMotor_DCMachine "DC motor using DC machine from MSL"

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-94,-4},{-86,4}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b torque_1
    "Coordinate system b fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-16},{116,16}}),
        iconTransformation(extent={{84,-16},{116,16}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a torque_2
    "Coordinate system a fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-76},{116,-44}}),
        iconTransformation(extent={{84,-76},{116,-44}})));
  Modelica.Electrical.Machines.BasicMachines.DCMachines.DC_PermanentMagnet dcpm(
    TaOperational=293.15,
    VaNominal=VaNominal,
    IaNominal=IaNominal,
    Jr=1,
    useSupport=false)
    annotation (Placement(transformation(extent={{-72,-34},{-52,-14}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-68,0})));
  Modelica.Electrical.Analog.Basic.Ground ground annotation (Placement(
        transformation(
        origin={-77,-19},
        extent={{-5,-5},{5,5}},
        rotation=0)));
  parameter Modelica.SIunits.Voltage VaNominal=5
    "Nominal armature voltage for motor";
  parameter Modelica.SIunits.Current IaNominal=0.1
    "Nominal armature current (>0..Motor, <0..Generator) for motor";

  Modelica.Mechanics.Rotational.Sensors.MultiSensor multiSensor annotation (
      Placement(transformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-38,-58})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-48,-90},{-28,-70}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={36,0})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{28,-56},{48,-36}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-10,-70},{10,-50}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-10,-4},{-2,4}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque(animation=false)
                                                    annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={70,-62})));
equation
  connect(position, limiter.u)
    annotation (Line(points={{-122,0},{-94.8,0}}, color={0,0,127}));
  connect(signalVoltage.n, dcpm.pin_an)
    annotation (Line(points={{-68,-10},{-68,-14}}, color={0,0,255}));
  connect(signalVoltage.p, dcpm.pin_ap)
    annotation (Line(points={{-68,10},{-56,10},{-56,-14}}, color={0,0,255}));
  connect(ground.p, dcpm.pin_an)
    annotation (Line(points={{-77,-14},{-68,-14}}, color={0,0,255}));
  connect(limiter.y, signalVoltage.v) annotation (Line(points={{-85.6,0},{-82,0},
          {-82,6.66134e-16},{-80,6.66134e-16}}, color={0,0,127}));
  connect(dcpm.flange, multiSensor.flange_a)
    annotation (Line(points={{-52,-24},{-38,-24},{-38,-48}}, color={0,0,0}));
  connect(multiSensor.flange_b, fixed.flange)
    annotation (Line(points={{-38,-68},{-38,-80}}, color={0,0,0}));
  connect(gain1.y,realExtend1. u)
    annotation (Line(points={{11,-60},{16,-60},{16,-46},{26,-46}},
                                                 color={0,0,127}));
  connect(realExtend.y,force. force) annotation (Line(points={{-1.6,0},{24,0}},
                               color={0,0,127}));
  connect(force_out,force. frame_b) annotation (Line(
      points={{100,62},{60,62},{60,0},{46,0}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y,torque. torque)
    annotation (Line(points={{49,-46},{50,-46},{50,-68},{58,-68}},
                                                 color={0,0,127}));
  connect(torque.frame_b, torque_1) annotation (Line(
      points={{70,-52},{70,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{70,-72},{70,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend.u, multiSensor.tau) annotation (Line(points={{-10.8,0},{
          -18,0},{-18,-4},{-22,-4},{-22,-58},{-27,-58}}, color={0,0,127}));
  connect(gain1.u, multiSensor.tau) annotation (Line(points={{-12,-60},{-22,-60},
          {-22,-58},{-27,-58}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_DCMachine;
