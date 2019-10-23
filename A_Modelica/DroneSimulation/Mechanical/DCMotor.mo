within DroneSimulation.Mechanical;
model DCMotor
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(
    color={244,0,4},
    resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b,
    N_to_m=10)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={64,0})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force_out
    annotation (Placement(transformation(extent={{86,-16},{118,16}})));
  Modelica.Blocks.Interfaces.RealInput position
    annotation (Placement(transformation(extent={{-142,-20},{-102,20}})));
  DroneSimulation.Electrical.SimpleDCmotor dCmotor
    annotation (Placement(transformation(extent={{-70,-14},{-50,6}})));
  DroneSimulation.Blocks.Routing.RealExtend realExtend1
    annotation (Placement(transformation(extent={{38,-78},{58,-58}})));
  Modelica.Blocks.Math.Gain gain1(k=k)
    annotation (Placement(transformation(extent={{-30,-78},{-10,-58}})));
  DroneSimulation.Blocks.Routing.RealExtend realExtend
    annotation (Placement(transformation(extent={{-10,-4},{-2,4}})));
  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-94,-4},{-86,4}})));
  Modelica.Blocks.Interfaces.RealOutput torque[3]
    annotation (Placement(transformation(extent={{100,-78},{120,-58}})));
equation
  connect(gain1.y, realExtend1.u)
    annotation (Line(points={{-9,-68},{36,-68}}, color={0,0,127}));
  connect(dCmotor.force, gain1.u) annotation (Line(points={{-49,-8},{-44,-8},
          {-44,-68},{-32,-68}},      color={0,0,127}));
  connect(realExtend.y, force.force) annotation (Line(points={{-1.6,0},{52,
          0}},                 color={0,0,127}));
  connect(dCmotor.torque, realExtend.u) annotation (Line(points={{-49,0},{
          -10.8,0}},                      color={0,0,127}));
  connect(dCmotor.current, limiter.y)
    annotation (Line(points={{-72,-4},{-80,-4},{-80,0},{-85.6,0}},
                                                 color={0,0,127}));
  connect(position, limiter.u)
    annotation (Line(points={{-122,0},{-94.8,0}}, color={0,0,127}));
  connect(force_out, force.frame_b) annotation (Line(
      points={{102,0},{74,0}},
      color={95,95,95},
      thickness=0.5));
  connect(realExtend1.y, torque)
    annotation (Line(points={{59,-68},{110,-68}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end DCMotor;
