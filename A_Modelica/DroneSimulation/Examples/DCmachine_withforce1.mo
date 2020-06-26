within DroneSimulation.Examples;
model DCmachine_withforce1
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=1e8, uMin=0)
    annotation (Placement(transformation(extent={{-46,72},{-38,80}})));
  Modelica.Electrical.Machines.BasicMachines.DCMachines.DC_PermanentMagnet dcpm(
    TaOperational=293.15,
    VaNominal=12.1,
    IaNominal=20,
    wNominal(displayUnit="rad/s") = 200,
    TaNominal=293.15,
    Ra=0.1,
    TaRef=293.15,
    alpha20a(displayUnit="1/K") = Modelica.Electrical.Machines.Thermal.Constants.alpha20Zero,
    La=0.01,
    Jr=1,
    useSupport=true,
    Js=1,
    wMechanical(displayUnit="rad/s", start=-200))
    annotation (Placement(transformation(extent={{-24,42},{-4,62}})));

  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-20,76})));
  Modelica.Electrical.Analog.Basic.Ground ground annotation (Placement(
        transformation(
        origin={3,57},
        extent={{-5,-5},{5,5}},
        rotation=0)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute2(
    useAxisFlange=true,
    animation=true,
    n(displayUnit="1") = {0,0,1},
    w(start=-200))
    annotation (Placement(transformation(extent={{32,2},{52,22}})));
  Modelica.Blocks.Math.Gain aero_coef[3](k={1,1,-1})
    annotation (Placement(transformation(extent={{-70,-18},{-50,2}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force(animation=false)
                                                       annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={2,-28})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-112,22},{-92,42}})));
  Modelica.Blocks.Sources.RealExpression realExpression(y=0.0015*dcpm.wMechanical
        *dcpm.wMechanical)
    annotation (Placement(transformation(extent={{-122,-18},{-102,2}})));
  Modelica.Blocks.Math.Gain aero_coef1
                                     [3](k={1,1,-1})
    annotation (Placement(transformation(extent={{-70,-88},{-50,-68}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-110,-48},{-90,-28}})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=3.5e-6*dcpm.wMechanical
        *dcpm.wMechanical)
    annotation (Placement(transformation(extent={{-118,-86},{-98,-66}})));
  Modelica.Mechanics.MultiBody.Forces.WorldTorque torque(animation=false)
                                                       annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={4,-78})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b frame_b1
    "Coordinate system fixed to the joint with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{86,-4},{118,28}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1
    "Coordinate system fixed to the joint with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{86,44},{118,76}})));
  Modelica.Blocks.Interfaces.RealInput u1
              "Connector of Real input signal"
    annotation (Placement(transformation(extent={{-140,58},{-100,98}})));
  parameter Real k "Gain value multiplied with input signal";
  Modelica.Blocks.Math.Gain gain(k=1)
    annotation (Placement(transformation(extent={{-76,68},{-56,88}})));
equation
  connect(limiter.y,signalVoltage. v) annotation (Line(points={{-37.6,76},{-32,
          76}},                                 color={0,0,127}));
  connect(dcpm.support,revolute2. support)
    annotation (Line(points={{-4,42},{36,42},{36,22}},       color={0,0,0}));
  connect(const.y,aero_coef [1].u) annotation (Line(points={{-91,32},{-80,32},{
          -80,-8},{-72,-8}},           color={0,0,127}));
  connect(const.y,aero_coef [2].u) annotation (Line(points={{-91,32},{-86,32},{
          -86,-8},{-72,-8}},           color={0,0,127}));
  connect(realExpression.y,aero_coef [3].u)
    annotation (Line(points={{-101,-8},{-72,-8}},    color={0,0,127}));
  connect(aero_coef.y,force. force) annotation (Line(points={{-49,-8},{-38,-8},
          {-38,-28},{-10,-28}}, color={0,0,127}));
  connect(force.frame_b,revolute2. frame_b) annotation (Line(
      points={{12,-28},{72,-28},{72,12},{52,12}},
      color={95,95,95},
      thickness=0.5));
  connect(const1.y,aero_coef1 [1].u) annotation (Line(points={{-89,-38},{-78,
          -38},{-78,-78},{-72,-78}},     color={0,0,127}));
  connect(const1.y,aero_coef1 [2].u) annotation (Line(points={{-89,-38},{-84,
          -38},{-84,-78},{-72,-78}},     color={0,0,127}));
  connect(realExpression1.y,aero_coef1 [3].u)
    annotation (Line(points={{-97,-76},{-86,-76},{-86,-78},{-72,-78}},
                                                       color={0,0,127}));
  connect(aero_coef1.y,torque. torque)
    annotation (Line(points={{-49,-78},{-8,-78}},    color={0,0,127}));
  connect(torque.frame_b,revolute2. frame_b) annotation (Line(
      points={{14,-78},{72,-78},{72,12},{52,12}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute2.frame_b, frame_b1) annotation (Line(
      points={{52,12},{102,12}},
      color={95,95,95},
      thickness=0.5));
  connect(revolute2.frame_a, frame_a1) annotation (Line(
      points={{32,12},{6,12},{6,60},{102,60}},
      color={95,95,95},
      thickness=0.5));
  connect(dcpm.flange, revolute2.axis)
    annotation (Line(points={{-4,52},{42,52},{42,22}}, color={0,0,0}));
  connect(u1, gain.u)
    annotation (Line(points={{-120,78},{-78,78}}, color={0,0,127}));
  connect(gain.y, limiter.u) annotation (Line(points={{-55,78},{-50,78},{-50,76},
          {-46.8,76}}, color={0,0,127}));
  connect(dcpm.pin_ap, ground.p)
    annotation (Line(points={{-8,62},{3,62}}, color={0,0,255}));
  connect(signalVoltage.p, dcpm.pin_an)
    annotation (Line(points={{-20,66},{-20,62}}, color={0,0,255}));
  connect(signalVoltage.n, dcpm.pin_ap) annotation (Line(points={{-20,86},{-20,
          90},{-8,90},{-8,62}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end DCmachine_withforce1;
