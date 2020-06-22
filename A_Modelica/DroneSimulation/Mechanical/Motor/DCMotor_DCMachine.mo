within DroneSimulation.Mechanical.Motor;
model DCMotor_DCMachine "DC motor using DC machine from MSL"
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={64,62})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{22,-30},{42,-10}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-10,-30},{10,-10}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{36,58},{44,66}})));
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

  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-10,46},{10,66}})));
  Modelica.Blocks.Math.Gain gain(k=0.0015)
    annotation (Placement(transformation(extent={{18,58},{28,68}})));
  Modelica.Mechanics.Rotational.Sensors.MultiSensor multiSensor annotation (
      Placement(transformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-38,-58})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-48,-90},{-28,-70}})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque(animation=false)
    annotation (Placement(transformation(extent={{58,-10},{78,10}})));
  Modelica.Blocks.Math.Product product1
    annotation (Placement(transformation(extent={{-12,-76},{8,-56}})));
  Modelica.Blocks.Math.Gain gain2(k=3.5e-6)
    annotation (Placement(transformation(extent={{18,-72},{28,-62}})));
  Blocks.Routing.RealExtend realExtend2
    annotation (Placement(transformation(extent={{40,-70},{48,-62}})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque1(animation=false)
    annotation (Placement(transformation(extent={{62,-70},{82,-50}})));
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{11,-20},{20,-20}}, color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{44.4,62},{52,62}},
                               color={0,0,127}));
  connect(position, limiter.u)
    annotation (Line(points={{-122,0},{-94.8,0}}, color={0,0,127}));
  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{74,62}},
      color={95,95,95},
      thickness=0.5));
  connect(signalVoltage.n, dcpm.pin_an)
    annotation (Line(points={{-68,-10},{-68,-14}}, color={0,0,255}));
  connect(signalVoltage.p, dcpm.pin_ap)
    annotation (Line(points={{-68,10},{-56,10},{-56,-14}}, color={0,0,255}));
  connect(ground.p, dcpm.pin_an)
    annotation (Line(points={{-77,-14},{-68,-14}}, color={0,0,255}));
  connect(limiter.y, signalVoltage.v) annotation (Line(points={{-85.6,0},{-82,0},
          {-82,6.66134e-16},{-80,6.66134e-16}}, color={0,0,127}));
  connect(product.u2, product.u1) annotation (Line(points={{-12,50},{-16,50},{
          -16,62},{-12,62}}, color={0,0,127}));
  connect(product.y, gain.u) annotation (Line(points={{11,56},{14,56},{14,63},{
          17,63}}, color={0,0,127}));
  connect(realExtend.u, gain.y) annotation (Line(points={{35.2,62},{30,62},{30,
          63},{28.5,63}}, color={0,0,127}));
  connect(dcpm.flange, multiSensor.flange_a)
    annotation (Line(points={{-52,-24},{-38,-24},{-38,-48}}, color={0,0,0}));
  connect(multiSensor.flange_b, fixed.flange)
    annotation (Line(points={{-38,-68},{-38,-80}}, color={0,0,0}));
  connect(multiSensor.tau, gain1.u) annotation (Line(points={{-27,-58},{-20,-58},
          {-20,-20},{-12,-20}}, color={0,0,127}));
  connect(multiSensor.w, product.u1) annotation (Line(points={{-27,-64},{-24,
          -64},{-24,62},{-12,62}}, color={0,0,127}));
  connect(torque_1, torque.frame_b) annotation (Line(
      points={{100,0},{78,0}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque.torque) annotation (Line(points={{43,-20},{50,
          -20},{50,0},{56,0}}, color={0,0,127}));
  connect(product1.u1, product.u1) annotation (Line(points={{-14,-60},{-24,-60},
          {-24,62},{-12,62}}, color={0,0,127}));
  connect(product1.u2, product.u1) annotation (Line(points={{-14,-72},{-20,-72},
          {-20,-64},{-24,-64},{-24,62},{-12,62}}, color={0,0,127}));
  connect(gain2.u, product1.y)
    annotation (Line(points={{17,-67},{17,-66},{9,-66}}, color={0,0,127}));
  connect(realExtend2.u, gain2.y) annotation (Line(points={{39.2,-66},{30,-66},
          {30,-67},{28.5,-67}}, color={0,0,127}));
  connect(torque1.torque, realExtend2.y) annotation (Line(points={{60,-60},{52,
          -60},{52,-66},{48.4,-66}}, color={0,0,127}));
  connect(torque1.frame_b, torque_2) annotation (Line(
      points={{82,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{
            -100,-100},{100,100}}),                             graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_DCMachine;
