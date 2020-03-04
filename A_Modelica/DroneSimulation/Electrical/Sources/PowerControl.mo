within DroneSimulation.Electrical.Sources;
model PowerControl
  parameter Real V "Reference voltage";
  Modelica.Electrical.Analog.Sensors.PotentialSensor potentialSensor
    annotation (Placement(transformation(extent={{-44,30},{-24,50}})));
  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-8,56},{12,36}})));
  Modelica.Blocks.Math.Division division
    annotation (Placement(transformation(extent={{26,2},{46,22}})));
  Modelica.Blocks.Sources.Constant const(k=V)
    annotation (Placement(transformation(extent={{-34,-4},{-14,16}})));
  Modelica.Electrical.Analog.Basic.Resistor resistor(R=R) annotation (Placement(
        transformation(
        extent={{10,-10},{-10,10}},
        rotation=90,
        origin={-62,22})));
  Modelica.Electrical.Analog.Basic.Ground ground1
    annotation (Placement(transformation(extent={{-72,-16},{-52,4}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{13,-13},{-13,13}},
        rotation=90,
        origin={79,11})));
  Modelica.Blocks.Interfaces.RealInput Position
    "Position signal from the controller"
    annotation (Placement(transformation(extent={{-142,40},{-102,80}}),
        iconTransformation(extent={{-142,40},{-102,80}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin Battery
    "pin connecting to battery/voltage source"
    annotation (Placement(transformation(extent={{-114,-72},{-94,-52}}),
        iconTransformation(extent={{-114,-72},{-94,-52}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin p1
    annotation (Placement(transformation(extent={{92,50},{112,70}}),
        iconTransformation(extent={{92,50},{112,70}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin n1
    annotation (Placement(transformation(extent={{94,-70},{114,-50}}),
        iconTransformation(extent={{94,-70},{114,-50}})));
  parameter Modelica.SIunits.Resistance R=R "Resistance at temperature T_ref";
equation
  connect(product.u1,potentialSensor. phi)
    annotation (Line(points={{-10,40},{-23,40}}, color={0,0,127}));
  connect(product.y,division. u1) annotation (Line(points={{13,46},{18,46},{18,18},
          {24,18}},    color={0,0,127}));
  connect(const.y,division. u2)
    annotation (Line(points={{-13,6},{24,6}}, color={0,0,127}));
  connect(resistor.n,ground1. p)
    annotation (Line(points={{-62,12},{-62,4}},  color={0,0,255}));
  connect(potentialSensor.p, resistor.p)
    annotation (Line(points={{-44,40},{-62,40},{-62,32}}, color={0,0,255}));
  connect(division.y, signalVoltage.v) annotation (Line(points={{47,12},{52,12},
          {52,11},{63.4,11}}, color={0,0,127}));
  connect(product.u2, Position) annotation (Line(points={{-10,52},{-22,52},{-22,
          60},{-122,60}}, color={0,0,127}));
  connect(potentialSensor.p, Battery) annotation (Line(points={{-44,40},{-82,40},
          {-82,-62},{-104,-62}}, color={0,0,255}));
  connect(signalVoltage.p, p1) annotation (Line(points={{79,24},{80,24},{80,60},
          {102,60}}, color={0,0,255}));
  connect(signalVoltage.n, n1) annotation (Line(points={{79,-2},{80,-2},{80,-60},
          {104,-60}}, color={0,0,255}));
  connect(p1, p1)
    annotation (Line(points={{102,60},{102,60},{102,60}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200})}),
                                                                 Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end PowerControl;
