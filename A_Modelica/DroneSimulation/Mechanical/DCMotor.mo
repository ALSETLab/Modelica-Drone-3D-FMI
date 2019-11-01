within DroneSimulation.Mechanical;
model DCMotor
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={50,0})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{84,46},{116,78}}),
        iconTransformation(extent={{84,46},{116,78}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  Electrical.SimpleDCmotor dCmotor
    annotation (Placement(transformation(extent={{-70,-14},{-50,6}})));
  Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{16,-78},{36,-58}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-30,-78},{-10,-58}})));
  Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-10,-4},{-2,4}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-94,-4},{-86,4}})));
  Modelica.Mechanics.MultiBody.Forces.Torque torque annotation (Placement(
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
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{-9,-68},{14,-68}}, color={0,0,127}));
  connect(dCmotor.force, gain1.u) annotation (Line(points={{-49,-8},{-44,-8},
          {-44,-68},{-32,-68}},      color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-1.6,0},{38,0}},
                               color={0,0,127}));
  connect(dCmotor.torque, realExtend.u) annotation (Line(points={{-49,0},{
          -10.8,0}},                      color={0,0,127}));
  connect(dCmotor.current, limiter.y)
    annotation (Line(points={{-72,-4},{-80,-4},{-80,0},{-85.6,0}},
                                                 color={0,0,127}));
  connect(position, limiter.u)
    annotation (Line(points={{-122,0},{-94.8,0}}, color={0,0,127}));
  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{80,62},{80,0},{60,0}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{37,-68},{58,-68}}, color={0,0,127}));
  connect(torque.frame_b, torque_1) annotation (Line(
      points={{70,-52},{70,0},{100,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque.frame_a, torque_2) annotation (Line(
      points={{70,-72},{70,-60},{100,-60}},
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
end DCMotor;
