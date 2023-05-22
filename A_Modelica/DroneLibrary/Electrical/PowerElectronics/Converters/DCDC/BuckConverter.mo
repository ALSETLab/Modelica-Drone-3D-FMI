within DroneLibrary.Electrical.PowerElectronics.Converters.DCDC;
model BuckConverter "Step down chopper"
  import Modelica.Constants.pi;
  extends Modelica.Electrical.PowerConverters.Icons.Converter;
  parameter Modelica.Units.SI.Resistance RonTransistor=1e-05
    "Transistor closed resistance";
  parameter Modelica.Units.SI.Conductance GoffTransistor=1e-05
    "Transistor opened conductance";
  parameter Modelica.Units.SI.Voltage VkneeTransistor=0
    "Transistor threshold voltage";
  parameter Modelica.Units.SI.Resistance RonDiode(final min=0) = 1e-05
    "Closed diode resistance";
  parameter Modelica.Units.SI.Conductance GoffDiode(final min=0) = 1e-05
    "Opened diode conductance";
  parameter Modelica.Units.SI.Voltage VkneeDiode(final min=0) = 0
    "Diode forward threshold voltage";
  extends Modelica.Electrical.PowerConverters.Interfaces.DCDC.DCtwoPin1;
  extends Modelica.Electrical.PowerConverters.Interfaces.DCDC.DCtwoPin2;
  extends Modelica.Electrical.Analog.Interfaces.ConditionalHeatPort(final T=
       293.15);
  extends Modelica.Electrical.PowerConverters.Interfaces.Enable.Enable1;
  Modelica.Electrical.Analog.Ideal.IdealGTOThyristor transistor(
    useHeatPort=useHeatPort,
    Ron=RonTransistor,
    Goff=GoffTransistor,
    Vknee=VkneeTransistor) "Switching transistor" annotation (Placement(
        transformation(
        origin={-68,60},
        extent={{-10,-10},{10,10}})));
  Modelica.Electrical.Analog.Ideal.IdealDiode diode(
    Ron=RonDiode,
    Goff=GoffDiode,
    Vknee=VkneeDiode,
    useHeatPort=useHeatPort) "Free wheeling diode" annotation (Placement(
        transformation(
        origin={-42,8},
        extent={{-10,-10},{10,10}},
        rotation=90)));
  Modelica.Electrical.Analog.Basic.Inductor inductor(L=L)
    annotation (Placement(transformation(extent={{14,50},{34,70}})));
  parameter Modelica.Units.SI.Inductance L=1e-3 "Inductance";
  Modelica.Electrical.Analog.Basic.Capacitor capacitor annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={64,6})));
equation
  if not useHeatPort then
    LossPower = diode.LossPower + transistor.LossPower;
  end if;
  connect(diode.n, transistor.n) annotation (Line(
      points={{-42,18},{-42,60},{-58,60}},
                                        color={0,0,255}));
  connect(transistor.heatPort, heatPort) annotation (Line(
      points={{-68,50},{-68,-26},{0,-26},{0,-100}},
                                color={191,0,0}));
  connect(diode.heatPort, heatPort) annotation (Line(
      points={{-32,8},{0,8},{0,-100}},color={191,0,0}));
  connect(dc_p1, transistor.p) annotation (Line(
      points={{-100,60},{-78,60}}, color={0,0,255}));
  connect(dc_n1, diode.p) annotation (Line(
      points={{-100,-60},{-42,-60},{-42,-2}},color={0,0,255}));
  connect(dc_n1, dc_n2) annotation (Line(
      points={{-100,-60},{100,-60}}, color={0,0,255}));
  connect(andCondition_p.y, transistor.fire) annotation (Line(points={{-60,-69},
          {-60,50},{-48,50},{-48,78},{-58,78},{-58,72}}, color={255,0,255}));
  connect(dc_p2, dc_p2)
    annotation (Line(points={{100,60},{100,60}}, color={0,0,255}));
  connect(dc_p2, inductor.n)
    annotation (Line(points={{100,60},{34,60}}, color={0,0,255}));
  connect(inductor.p, transistor.n)
    annotation (Line(points={{14,60},{-58,60}}, color={0,0,255}));
  connect(capacitor.p, inductor.n)
    annotation (Line(points={{64,16},{64,60},{34,60}}, color={0,0,255}));
  connect(capacitor.n, dc_n2)
    annotation (Line(points={{64,-4},{64,-60},{100,-60}}, color={0,0,255}));
  annotation (defaultComponentName="dcdc",
    Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,-100},{
            100,100}}), graphics={
        Text(
          extent={{-100,70},{0,50}},
          lineColor={0,0,127},
          textString="DC in"),
        Text(
          extent={{0,-50},{100,-70}},
          lineColor={0,0,127},
          textString="DC out"),
        Text(
          extent={{-150,150},{150,110}},
          textString="%name",
          lineColor={0,0,255}),
        Rectangle(
          extent={{-40,40},{40,-40}},
          lineColor={255,255,255},
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid),
        Line(points={{-30,20},{-30,0}}, color={217,67,180}),
        Line(points={{-40,30},{-30,20},{-20,30}}, color={0,0,255}),
        Polygon(
          points={{-20,30},{-26,26},{-24,24},{-20,30}},
          lineColor={0,0,255},
          fillColor={0,0,255},
          fillPattern=FillPattern.Solid),
        Polygon(points={{20,10},{10,-10},{30,-10},{20,10}}, lineColor={0,0,
              255}),
        Line(points={{10,10},{30,10}}, color={0,0,255}),
        Line(points={{-20,30},{60,30}}, color={0,0,255}),
        Line(points={{-60,30},{-40,30}}, color={0,0,255}),
        Line(points={{-60,-30},{60,-30}}, color={0,0,255}),
        Line(points={{20,30},{20,-30}}, color={0,0,255}),
        Ellipse(extent={{-62,32},{-58,28}}, lineColor={0,0,255}),
        Ellipse(extent={{-62,-28},{-58,-32}}, lineColor={0,0,255}),
        Ellipse(extent={{18,-28},{22,-32}}, lineColor={0,0,255}),
        Ellipse(extent={{58,-28},{62,-32}}, lineColor={0,0,255}),
        Ellipse(extent={{58,32},{62,28}}, lineColor={0,0,255}),
        Ellipse(extent={{18,32},{22,28}}, lineColor={0,0,255}),
        Ellipse(extent={{-44,40},{-16,12}}, lineColor={0,0,255}),
        Line(points={{-40,20},{-20,20}}, color={0,0,255})}),
    Documentation(info="<html>
<p>
This is a conventional step down chopper (buck converter) model. It consists of a transistor and free wheeling diode.
</p>
</html>"));
end BuckConverter;
