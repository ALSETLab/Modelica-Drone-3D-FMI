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
  Modelica.Electrical.Analog.Sources.SignalCurrent
                                            signalCurrent annotation (Placement(
        transformation(
        extent={{10,10},{-10,-10}},
        rotation=90,
        origin={-62,22})));
  Modelica.Electrical.Analog.Basic.Ground ground1
    annotation (Placement(transformation(extent={{-72,-16},{-52,4}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation (Placement(transformation(extent={{13,-13},{-13,13}},
        rotation=90,
        origin={79,1})));
  Modelica.Blocks.Interfaces.RealInput Position
    "Position signal from the controller"
    annotation (Placement(transformation(extent={{-142,40},{-102,80}}),
        iconTransformation(extent={{-142,40},{-102,80}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin Battery
    "pin connecting to battery/voltage source"
    annotation (Placement(transformation(extent={{-110,-72},{-90,-52}}),
        iconTransformation(extent={{-110,-72},{-90,-52}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin p1
    annotation (Placement(transformation(extent={{90,50},{110,70}}),
        iconTransformation(extent={{90,50},{110,70}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin n1
    annotation (Placement(transformation(extent={{90,-70},{110,-50}}),
        iconTransformation(extent={{90,-70},{110,-50}})));
  parameter Modelica.Units.SI.Resistance R=R "Resistance at temperature T_ref";
  Real power;
  Modelica.Blocks.Sources.RealExpression realExpression(y=3)
    annotation (Placement(transformation(extent={{-72,-46},{-52,-26}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor   currentSensor
    annotation (Placement(transformation(extent={{10,10},{-10,-10}},
        rotation=90,
        origin={80,38})));
equation
  power = p1.v*p1.i;
  connect(product.u1,potentialSensor. phi)
    annotation (Line(points={{-10,40},{-23,40}}, color={0,0,127}));
  connect(product.y,division. u1) annotation (Line(points={{13,46},{18,46},{18,18},
          {24,18}},    color={0,0,127}));
  connect(const.y,division. u2)
    annotation (Line(points={{-13,6},{24,6}}, color={0,0,127}));
  connect(signalCurrent.n, ground1.p)
    annotation (Line(points={{-62,12},{-62,4}}, color={0,0,255}));
  connect(potentialSensor.p, signalCurrent.p)
    annotation (Line(points={{-44,40},{-62,40},{-62,32}}, color={0,0,255}));
  connect(product.u2, Position) annotation (Line(points={{-10,52},{-22,52},{-22,
          60},{-122,60}}, color={0,0,127}));
  connect(potentialSensor.p, Battery) annotation (Line(points={{-44,40},{-82,40},
          {-82,-62},{-100,-62}}, color={0,0,255}));
  connect(p1, p1)
    annotation (Line(points={{100,60},{100,60},{100,60}}, color={0,0,255}));
  connect(division.y, signalVoltage.v) annotation (Line(points={{47,12},{52,12},
          {52,1},{63.4,1}}, color={0,0,127}));
  connect(signalVoltage.n, n1) annotation (Line(points={{79,-12},{78,-12},{78,
          -60},{100,-60}}, color={0,0,255}));
  connect(realExpression.y, signalCurrent.i) annotation (Line(points={{-51,-36},
          {-46,-36},{-46,18},{-50,18},{-50,22}}, color={0,0,127}));
  connect(signalVoltage.p, currentSensor.n)
    annotation (Line(points={{79,14},{80,14},{80,28}}, color={0,0,255}));
  connect(currentSensor.p, p1)
    annotation (Line(points={{80,48},{80,60},{100,60}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}), Text(
          extent={{-94,42},{100,-38}},
          lineColor={28,108,200},
          textString="Speed
Controller")}),                                                  Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end PowerControl;
