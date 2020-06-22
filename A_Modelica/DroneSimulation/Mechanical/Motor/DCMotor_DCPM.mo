within DroneSimulation.Mechanical.Motor;
model DCMotor_DCPM "DC motor using DC machine from MSL"

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-56,36})));
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
    IaNominal=IaNominal)
    annotation (Placement(transformation(extent={{-72,-34},{-52,-14}})));
  Modelica.Electrical.Analog.Basic.Ground ground annotation (Placement(
        transformation(
        origin={-77,-19},
        extent={{-5,-5},{5,5}},
        rotation=0)));
  parameter Modelica.SIunits.Voltage VaNominal=5
    "Nominal armature voltage for motor";
  parameter Modelica.SIunits.Current IaNominal=0.1
    "Nominal armature current (>0..Motor, <0..Generator) for motor";
  parameter Modelica.SIunits.Voltage V
    "Battery voltage";

  Modelica.Electrical.Analog.Interfaces.PositivePin p1
                           "pin to be measured"
    annotation (Placement(transformation(extent={{-110,30},{-90,50}}),
        iconTransformation(extent={{-110,30},{-90,50}})));
  parameter Modelica.SIunits.Resistance R=100 "Resistance at temperature T_ref";
  Electrical.Sources.PowerControl powerControl(V=V, R=R) annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-62,10})));
  Modelica.Blocks.Interfaces.RealInput position
    "Connector of Real input signal"
    annotation (Placement(transformation(extent={{-140,-80},{-100,-40}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={62,62})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{20,-30},{40,-10}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-12,-30},{8,-10}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{34,58},{42,66}})));
  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-12,46},{8,66}})));
  Modelica.Blocks.Math.Gain gain(k=0.0015)
    annotation (Placement(transformation(extent={{16,58},{26,68}})));
  Modelica.Mechanics.Rotational.Sensors.MultiSensor multiSensor annotation (
      Placement(transformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-40,-58})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-50,-90},{-30,-70}})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque(animation=false)
    annotation (Placement(transformation(extent={{56,-10},{76,10}})));
  Modelica.Blocks.Math.Product product1
    annotation (Placement(transformation(extent={{-14,-76},{6,-56}})));
  Modelica.Blocks.Math.Gain gain2(k=3.5e-6)
    annotation (Placement(transformation(extent={{16,-72},{26,-62}})));
  Blocks.Routing.RealExtend realExtend2
    annotation (Placement(transformation(extent={{38,-70},{46,-62}})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque1(animation=false)
    annotation (Placement(transformation(extent={{60,-70},{80,-50}})));
equation
  connect(position, limiter.u);

  connect(ground.p, dcpm.pin_an)
    annotation (Line(points={{-77,-14},{-68,-14}}, color={0,0,255}));
  connect(limiter.y, powerControl.Position) annotation (Line(points={{-56,31.6},
          {-56,22.2}},          color={0,0,127}));
  connect(powerControl.Battery, p1) annotation (Line(points={{-68.2,20},{-68.2,
          40},{-100,40}},       color={0,0,255}));
  connect(powerControl.n1, dcpm.pin_an)
    annotation (Line(points={{-68,1.77636e-15},{-68,-14}},
                                                    color={0,0,255}));
  connect(powerControl.p1, dcpm.pin_ap)
    annotation (Line(points={{-56,-1.77636e-15},{-56,-14}},
                                                    color={0,0,255}));
  connect(limiter.u, position) annotation (Line(points={{-56,40.8},{-66,40.8},{-66,
          84},{-120,84},{-120,-60}}, color={0,0,127}));
  connect(gain1.y,realExtend1. u)
    annotation (Line(points={{9,-20},{18,-20}},  color={0,0,127}));
  connect(realExtend.y,force. force) annotation (Line(points={{42.4,62},{50,62}},
                               color={0,0,127}));
  connect(product.u2,product. u1) annotation (Line(points={{-14,50},{-18,50},{
          -18,62},{-14,62}}, color={0,0,127}));
  connect(product.y,gain. u) annotation (Line(points={{9,56},{12,56},{12,63},{
          15,63}}, color={0,0,127}));
  connect(realExtend.u,gain. y) annotation (Line(points={{33.2,62},{28,62},{28,
          63},{26.5,63}}, color={0,0,127}));
  connect(multiSensor.flange_b,fixed. flange)
    annotation (Line(points={{-40,-68},{-40,-80}}, color={0,0,0}));
  connect(multiSensor.tau,gain1. u) annotation (Line(points={{-29,-58},{-22,-58},
          {-22,-20},{-14,-20}}, color={0,0,127}));
  connect(multiSensor.w,product. u1) annotation (Line(points={{-29,-64},{-26,
          -64},{-26,62},{-14,62}}, color={0,0,127}));
  connect(realExtend1.y,torque. torque) annotation (Line(points={{41,-20},{48,
          -20},{48,0},{54,0}}, color={0,0,127}));
  connect(product1.u1,product. u1) annotation (Line(points={{-16,-60},{-26,-60},
          {-26,62},{-14,62}}, color={0,0,127}));
  connect(product1.u2,product. u1) annotation (Line(points={{-16,-72},{-22,-72},
          {-22,-64},{-26,-64},{-26,62},{-14,62}}, color={0,0,127}));
  connect(gain2.u,product1. y)
    annotation (Line(points={{15,-67},{15,-66},{7,-66}}, color={0,0,127}));
  connect(realExtend2.u,gain2. y) annotation (Line(points={{37.2,-66},{28,-66},
          {28,-67},{26.5,-67}}, color={0,0,127}));
  connect(torque1.torque,realExtend2. y) annotation (Line(points={{58,-60},{50,
          -60},{50,-66},{46.4,-66}}, color={0,0,127}));
  connect(force_out, force_out) annotation (Line(
      points={{100,62},{91,62},{91,62},{100,62}},
      color={95,95,95},
      thickness=0.5));
  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{72,62}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_b, torque_1) annotation (Line(
      points={{76,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, torque1.frame_b) annotation (Line(
      points={{100,-60},{80,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(dcpm.flange, multiSensor.flange_a)
    annotation (Line(points={{-52,-24},{-40,-24},{-40,-48}}, color={0,0,0}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}}),                                  graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_DCPM;
