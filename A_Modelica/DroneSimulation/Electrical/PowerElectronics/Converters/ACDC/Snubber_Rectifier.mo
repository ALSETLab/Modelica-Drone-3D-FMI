within DroneSimulation.Electrical.PowerElectronics.Converters.ACDC;
model Snubber_Rectifier
  "3 phase AC to single phase DC rectifier using snubber diodes"
  Modelica.Electrical.Polyphase.Basic.Star star(m=3) annotation (Placement(
        transformation(
        origin={-24,66},
        extent={{-10,10},{10,-10}})));
  Switches.Diode_Snubber diode_Snubber(
    Rcond=Rcond,
    Vt=Vt,
    Gof=Gof,
    R1=R1,
    C1=C1) annotation (Placement(transformation(
        extent={{-9,-8},{9,8}},
        rotation=180,
        origin={-51,48})));
  Switches.Diode_Snubber diode_Snubber1(
    Rcond=Rcond,
    Vt=Vt,
    Gof=Gof,
    R1=R1,
    C1=C1) annotation (Placement(transformation(
        extent={{-9,-8},{9,8}},
        rotation=180,
        origin={-51,20})));
  parameter Modelica.Units.SI.Resistance Rcond=1e-5
    "Forward state-on differential resistance (closed resistance)";
  parameter Modelica.Units.SI.Voltage Vt=0 "Forward threshold voltage";
  parameter Modelica.Units.SI.Conductance Gof=1e-5
    "Backward state-off conductance (opened conductance)";
  parameter Modelica.Units.SI.Resistance R1=1e-3 "Snubber Resistance";
  parameter Modelica.Units.SI.Capacitance C1=1e-6 "SnubberCapacitance";
  Modelica.Electrical.Polyphase.Basic.Star star1(m=3) annotation (Placement(
        transformation(
        origin={-16,-6},
        extent={{-10,10},{10,-10}})));
  Modelica.Electrical.Polyphase.Interfaces.PositivePlug positivePlug
    annotation (Placement(transformation(extent={{-120,10},{-100,30}}),
        iconTransformation(extent={{-120,10},{-100,30}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin pin_p
    annotation (Placement(transformation(extent={{40,40},{60,60}}),
        iconTransformation(extent={{40,40},{60,60}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin pin_n
    annotation (Placement(transformation(extent={{40,-20},{60,0}}),
        iconTransformation(extent={{40,-20},{60,0}})));
equation
  connect(diode_Snubber.negativePlug, star.plug_p) annotation (Line(points={{-51.2,
          56},{-52,56},{-52,66},{-34,66}}, color={0,0,255}));
  connect(diode_Snubber1.negativePlug, diode_Snubber.positivePlug)
    annotation (Line(points={{-51.2,28},{-51,28},{-51,39.8}}, color={0,
          0,255}));
  connect(star1.plug_p, diode_Snubber1.positivePlug) annotation (Line(
        points={{-26,-6},{-50,-6},{-50,11.8},{-51,11.8}}, color={0,0,
          255}));
  connect(positivePlug, diode_Snubber.positivePlug) annotation (Line(
        points={{-110,20},{-82,20},{-82,34},{-51,34},{-51,39.8}},
                                                color={0,0,255}));
  connect(pin_p, star.pin_n)
    annotation (Line(points={{50,50},{18,50},{18,66},{-14,66}},
                                                color={0,0,255}));
  connect(pin_n, star1.pin_n)
    annotation (Line(points={{50,-10},{22,-10},{22,-6},{-6,-6}},
                                               color={0,0,255}));
  connect(pin_p, pin_p)
    annotation (Line(points={{50,50},{50,50}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,-40},
            {40,80}}), graphics={
        Rectangle(
          extent={{-100,80},{40,-40}},
          lineColor={0,0,127},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
        Text(
          extent={{-114,64},{-14,44}},
          lineColor={0,0,127},
          textString="AC"),
        Line(
          points={{-100,-40},{40,80}},
          color={0,0,127}),
        Text(
          extent={{-44,-12},{56,-32}},
          lineColor={0,0,127},
          textString="DC"),
        Rectangle(
          extent={{-72,42},{8,-6}},
          lineColor={255,255,255},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
        Line(
          points={{-10,16},{-50,40},{-50,-8},{-10,16}},
          color={0,0,255}),
        Line(
          points={{-70,16},{10,16}},
          color={0,0,255}),
        Line(
          points={{-10,40},{-10,-8}},
          color={0,0,255})}), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-100,-40},{40,80}})),
    experiment(StopTime=0.1, __Dymola_NumberOfIntervals=5000),
    Documentation(info="<html>
<p>This rectifier converter interfaces a 3 phase system to a single phase DC system.</p>
</html>"));
end Snubber_Rectifier;
