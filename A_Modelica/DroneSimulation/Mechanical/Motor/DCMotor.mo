within DroneSimulation.Mechanical.Motor;
model DCMotor
  extends DroneSimulation.Mechanical.Motor.Templates.DCMotor;
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    animation=false,
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={36,0})));

  Electrical.Machines.SimpleDCmotor dCmotor
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
  Modelica.Mechanics.MultiBody.Forces.Torque torque(animation=false)
                                                    annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={70,-62})));
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{-9,-68},{14,-68}}, color={0,0,127}));
  connect(dCmotor.force, gain1.u) annotation (Line(points={{-49,-8},{-44,-8},
          {-44,-68},{-32,-68}},      color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-1.6,0},{24,0}},
                               color={0,0,127}));
  connect(dCmotor.torque, realExtend.u) annotation (Line(points={{-49,0},{
          -10.8,0}},                      color={0,0,127}));
  connect(dCmotor.current, limiter.y)
    annotation (Line(points={{-72,-4},{-80,-4},{-80,0},{-85.6,0}},
                                                 color={0,0,127}));
  connect(realExtend1.y, torque.torque)
    annotation (Line(points={{37,-68},{58,-68}}, color={0,0,127}));
  connect(limiter.u, position)
    annotation (Line(points={{-94.8,0},{-122,0}}, color={0,0,127}));
  connect(force_out, force.frame_b) annotation (Line(
      points={{100,62},{52,62},{52,0},{46,0}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, torque.frame_b) annotation (Line(
      points={{100,0},{70,0},{70,-52}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_2, torque.frame_a) annotation (Line(
      points={{100,-60},{82,-60},{82,-76},{70,-76},{70,-72}},
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
