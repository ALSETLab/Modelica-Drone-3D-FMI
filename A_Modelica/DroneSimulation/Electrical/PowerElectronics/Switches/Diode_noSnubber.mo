within DroneSimulation.Electrical.PowerElectronics.Switches;
model Diode_noSnubber
  parameter Modelica.SIunits.Resistance Rcond=1e-5
    "Forward state-on differential resistance (closed resistance)";
  parameter Modelica.SIunits.Voltage Vt=0.8 "Forward threshold voltage";
  parameter Modelica.SIunits.Conductance Gof=1e-5
    "Backward state-off conductance (opened conductance)";
  Modelica.Electrical.MultiPhase.Interfaces.PositivePlug positivePlug
    annotation (Placement(transformation(extent={{0,132},{20,152}})));
  Modelica.Electrical.MultiPhase.Interfaces.NegativePlug negativePlug
    annotation (Placement(transformation(extent={{2,-30},{22,-10}}),
        iconTransformation(extent={{2,-30},{22,-10}})));
  Modelica.Electrical.MultiPhase.Ideal.IdealDiode diode1(
    Ron={Rcond,Rcond,Rcond},
    Goff={Gof,Gof,Gof},
    Vknee={Vt,Vt,Vt}) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={10,72})));
equation
  connect(diode1.plug_p, positivePlug) annotation (Line(points={{10,82},
          {10,142}},         color={0,0,255}));
  connect(negativePlug, diode1.plug_n) annotation (Line(points={{12,-20},
          {12,32},{10,32},{10,62}}, color={0,0,255}));
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
          lineColor={0,0,255})}));
end Diode_noSnubber;
