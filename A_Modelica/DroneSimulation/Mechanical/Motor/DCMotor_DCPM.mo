within DroneSimulation.Mechanical.Motor;
model DCMotor_DCPM "DC motor using DC machine from MSL"
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={36,0})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-16,-78},{4,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-10,-4},{-2,4}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-56,36})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque(animation=false)
                                                    annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={70,-62})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b torque_1
    "Coordinate system b fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-16},{116,16}}),
        iconTransformation(extent={{84,-16},{116,16}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a torque_2
    "Coordinate system a fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{84,-76},{116,-44}}),
        iconTransformation(extent={{84,-76},{116,-44}})));
  Modelica.Mechanics.Rotational.Sensors.TorqueSensor torqueSensor annotation (
      Placement(transformation(
        extent={{-10,10},{10,-10}},
        rotation=270,
        origin={-40,-48})));
  Modelica.Mechanics.Rotational.Components.Fixed fixed
    annotation (Placement(transformation(extent={{-46,-68},{-34,-56}})));
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
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{30,-72},{38,-64}})));
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{5,-68},{29.2,-68}},color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-1.6,0},{24,0}},
                               color={0,0,127}));
  connect(position, limiter.u);

  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{60,62},{60,0},{46,0}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{38.4,-68},{58,-68}},
                                                 color={0,0,127}));
  connect(torque.frame_b, torque_1) annotation (Line(
      points={{70,-52},{70,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{70,-72},{70,-60},{100,-60}},
      color={95,95,95},
      thickness=0.5));
  connect(gain1.u, realExtend.u) annotation (Line(points={{-18,-68},{-24,-68},{
          -24,0},{-10.8,0}}, color={0,0,127}));
  connect(torqueSensor.flange_b, fixed.flange)
    annotation (Line(points={{-40,-58},{-40,-62}}, color={0,0,0}));
  connect(torqueSensor.tau, realExtend.u) annotation (Line(points={{-29,-40},{
          -24,-40},{-24,0},{-10.8,0}}, color={0,0,127}));
  connect(torqueSensor.flange_a, dcpm.flange)
    annotation (Line(points={{-40,-38},{-40,-24},{-52,-24}}, color={0,0,0}));
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
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}}),                                  graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-100,-100},{100,100}})));
end DCMotor_DCPM;
