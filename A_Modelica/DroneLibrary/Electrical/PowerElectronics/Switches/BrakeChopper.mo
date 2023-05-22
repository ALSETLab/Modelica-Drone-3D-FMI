within DroneLibrary.Electrical.PowerElectronics.Switches;
model BrakeChopper
  Modelica.Electrical.Analog.Ideal.IdealDiode diode annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-40,16})));
  Modelica.Electrical.Analog.Basic.Resistor resistor(
    R=R,
    T_ref=T_ref,
    alpha=alpha,
    T=T) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-20,16})));
  parameter Modelica.Units.SI.Resistance R "Resistance at temperature T_ref"
    annotation (Dialog(group="External Brake Resistor"));
  parameter Modelica.Units.SI.Temperature T_ref=300.15 "Reference temperature"
    annotation (Dialog(group="External Brake Resistor"));
  parameter Modelica.Units.SI.LinearTemperatureCoefficient alpha=0
    "Temperature coefficient of resistance (R_actual = R*(1 + alpha*(T_heatPort - T_ref))"
    annotation (Dialog(group="External Brake Resistor"));
  parameter Modelica.Units.SI.Temperature T=resistor.T_ref
    "Fixed device temperature if useHeatPort = false"
    annotation (Dialog(group="External Brake Resistor"));
  Modelica.Electrical.Analog.Basic.Capacitor capacitor(C=C) annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={40,0})));
  parameter Modelica.Units.SI.Capacitance C "Capacitance"
    annotation (Dialog(group="Bus Capacitor"));
  Modelica.Electrical.Analog.Ideal.IdealOpeningSwitch switch annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-40,-22})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{-26,-60},{-6,-40}})));
  Modelica.Blocks.Sources.BooleanPulse booleanPulse(period=period)
    annotation (Placement(transformation(extent={{-78,-32},{-58,-12}})));
  parameter Modelica.Units.SI.Time period "Switching period"
    annotation (Dialog(group="Device Switching"));
  Modelica.Electrical.Analog.Interfaces.PositivePin p_in
    "Positive electrical pin" annotation (Placement(transformation(extent={{-94,
            24},{-74,44}}), iconTransformation(extent={{-94,24},{-74,44}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin p_out
    "Positive electrical pin"
    annotation (Placement(transformation(extent={{54,24},{74,44}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin n_out
    "Negative electrical pin"
    annotation (Placement(transformation(extent={{54,-50},{74,-30}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin n_in
    "Negative electrical pin"
    annotation (Placement(transformation(extent={{-94,-50},{-74,-30}})));
equation
  connect(diode.n, resistor.p) annotation (Line(points={{-40,26},{-40,34},{-20,
          34},{-20,26}}, color={0,0,255}));
  connect(capacitor.p, resistor.p) annotation (Line(points={{40,10},{40,34},{
          -20,34},{-20,26}}, color={0,0,255}));
  connect(diode.p, resistor.n) annotation (Line(points={{-40,6},{-40,0},{-20,0},
          {-20,6}}, color={0,0,255}));
  connect(switch.n, resistor.n) annotation (Line(points={{-40,-12},{-40,0},{-20,
          0},{-20,6}}, color={0,0,255}));
  connect(switch.p, capacitor.n) annotation (Line(points={{-40,-32},{-40,-40},{
          40,-40},{40,-10}}, color={0,0,255}));
  connect(switch.p, ground.p)
    annotation (Line(points={{-40,-32},{-40,-40},{-16,-40}}, color={0,0,255}));
  connect(switch.control, booleanPulse.y)
    annotation (Line(points={{-52,-22},{-57,-22}}, color={255,0,255}));
  connect(capacitor.p, p_out)
    annotation (Line(points={{40,10},{40,34},{64,34}}, color={0,0,255}));
  connect(capacitor.n, n_out)
    annotation (Line(points={{40,-10},{40,-40},{64,-40}}, color={0,0,255}));
  connect(p_in, resistor.p)
    annotation (Line(points={{-84,34},{-20,34},{-20,26}}, color={0,0,255}));
  connect(n_in, capacitor.n)
    annotation (Line(points={{-84,-40},{40,-40},{40,-10}}, color={0,0,255}));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,-60},{60,60}}),
        graphics={Rectangle(extent={{-80,60},{60,-60}}, lineColor={28,108,200}),
          Text(
          extent={{30,-42},{-52,38}},
          lineColor={28,108,200},
          textString="Braking
Chopper")}),
    Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-80,-60},{60,
            60}})),
    Documentation(info="<html>
<p>The brake chopper circuit is shown below:</p>
<p><img src=\"modelica://CHEETA/Images/Electrical/brake-chopper-circuit-500x400.png\"/></p>
<p><a href=\"https://kebblog.com/brake-chopper-circuits-vfds/\">https://kebblog.com/brake-chopper-circuits-vfds/</a></p>
</html>"));
end BrakeChopper;
