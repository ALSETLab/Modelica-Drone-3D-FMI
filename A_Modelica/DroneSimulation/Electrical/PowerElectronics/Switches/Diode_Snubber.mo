within DroneSimulation.Electrical.PowerElectronics.Switches;
model Diode_Snubber
  parameter Modelica.Units.SI.Resistance Rcond=1e-5
    "Forward state-on differential resistance (closed resistance)";
  parameter Modelica.Units.SI.Voltage Vt=0 "Forward threshold voltage";
  parameter Modelica.Units.SI.Conductance Gof=1e-5
    "Backward state-off conductance (opened conductance)";
  parameter Modelica.Units.SI.Resistance R1=1e-3 "Snubber Resistance";
  parameter Modelica.Units.SI.Capacitance C1=1e-6 "SnubberCapacitance";
  Modelica.Electrical.Polyphase.Ideal.IdealDiode diode(
    Ron={Rcond,Rcond,Rcond},
    Goff={Gof,Gof,Gof},
    Vknee={Vt,Vt,Vt}) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={0,64})));
  Modelica.Electrical.Polyphase.Basic.Resistor resistor(R={R1,R1,R1})
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={28,76})));
  Modelica.Electrical.Polyphase.Basic.Capacitor capacitor(C={C1,C1,C1})
    annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={28,44})));
  Modelica.Electrical.Polyphase.Interfaces.PositivePlug positivePlug
    annotation (Placement(transformation(extent={{0,132},{20,152}})));
  Modelica.Electrical.Polyphase.Interfaces.NegativePlug negativePlug
    annotation (Placement(transformation(extent={{2,-30},{22,-10}}),
        iconTransformation(extent={{2,-30},{22,-10}})));
equation
  connect(capacitor.plug_n, resistor.plug_n)
    annotation (Line(points={{28,54},{28,66}}, color={0,0,255}));
  connect(resistor.plug_p, diode.plug_p)
    annotation (Line(points={{28,86},{0,86},{0,74}}, color={0,0,255}));
  connect(capacitor.plug_p, diode.plug_n)
    annotation (Line(points={{28,34},{0,34},{0,54}}, color={0,0,255}));
  connect(positivePlug, diode.plug_p) annotation (Line(points={{10,142},{12,142},
          {12,86},{0,86},{0,74},{1.77636e-15,74}}, color={0,0,255}));
  connect(negativePlug, diode.plug_n) annotation (Line(points={{12,-20},
          {12,34},{0,34},{0,54},{-1.77636e-15,54}},
                                            color={0,0,255}));
  annotation (Diagram(coordinateSystem(extent={{-80,-20},{100,140}})), Icon(
        coordinateSystem(extent={{-80,-20},{100,140}}), graphics={
        Polygon(
          points={{50,9.00308e-15},{-38,64},{-38,-72},{50,9.00308e-15}},
          lineColor={0,0,255},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid,
          origin={12,44},
          rotation=270),
        Line(points={{-40,92},{60,92}},
                                     color={0,0,255}),
        Line(points={{12,138},{12,-20}},color={0,0,255}),
        Text(
          extent={{-138,134},{162,94}},
          textString="%name",
          lineColor={0,0,255})}),
    Documentation(info="<html>
<p>This is a multi-phase diode that will not conduct under normal conditions. It is currently configured as a 3-phase diode.</p>
</html>"));
end Diode_Snubber;
