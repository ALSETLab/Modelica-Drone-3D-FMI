within DroneLibrary.Examples.PowerSystem;
model PowerSystem
  Modelica.Electrical.PowerConverters.DCDC.ChopperStepUp dcdc annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={-50,0})));
  Modelica.Electrical.PowerConverters.DCAC.SinglePhase2Level inverter(
      constantEnable=false)
    annotation (Placement(transformation(extent={{26,-10},{46,10}})));
  Modelica.Electrical.Analog.Basic.Inductor inductor(L=1e-6)
    annotation (Placement(transformation(extent={{-24,-4},{-4,16}})));
  Modelica.Electrical.PowerConverters.DCDC.Control.SignalPWM pwm(
      constantDutyCycle=0.5, f(displayUnit="kHz") = 100000)
    annotation (Placement(transformation(extent={{-60,-40},{-40,-20}})));
  Modelica.Electrical.PowerConverters.DCDC.Control.SignalPWM pwm1(
      constantDutyCycle=0.5, f(displayUnit="kHz") = 100000)
    annotation (Placement(transformation(extent={{26,-42},{46,-22}})));
  Modelica.Electrical.Analog.Basic.Inductor inductor1(L=1e-6)
    annotation (Placement(transformation(extent={{-24,-16},{-4,4}})));
  Electrical.Sources.FuelCell.SimplifiedFuelCell simplifiedFuelCell(R=100, L=
        0.001,
    V=V) annotation (Placement(transformation(extent={{-86,-6},{-74,6}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin ac1
                                                       "AC output" annotation (
      Placement(transformation(extent={{-10,90},{10,110}}), iconTransformation(
          extent={{-10,90},{10,110}})));
  parameter Modelica.Units.SI.Voltage V=10 "Fuel cell voltage";
equation
  connect(dcdc.dc_p2, inductor.p)
    annotation (Line(points={{-40,6},{-24,6}}, color={0,0,255}));
  connect(inductor.n, inverter.dc_p)
    annotation (Line(points={{-4,6},{26,6}}, color={0,0,255}));
  connect(dcdc.fire_p, pwm.fire)
    annotation (Line(points={{-56,-12},{-56,-19}}, color={255,0,255}));
  connect(inductor1.p, dcdc.dc_n2)
    annotation (Line(points={{-24,-6},{-40,-6}}, color={0,0,255}));
  connect(inductor1.n, inverter.dc_n)
    annotation (Line(points={{-4,-6},{26,-6}}, color={0,0,255}));
  connect(pwm1.fire, inverter.fire_p)
    annotation (Line(points={{30,-21},{30,-12}}, color={255,0,255}));
  connect(pwm1.notFire, inverter.fire_n)
    annotation (Line(points={{42,-21},{42,-12}}, color={255,0,255}));
  connect(simplifiedFuelCell.pin_p, dcdc.dc_p1) annotation (Line(points={{-73,4},
          {-66,4},{-66,6},{-60,6}}, color={0,0,255}));
  connect(simplifiedFuelCell.pin_p1, dcdc.dc_n1) annotation (Line(points={{-73,
          -4},{-68,-4},{-68,-6},{-60,-6}}, color={0,0,255}));
  connect(inverter.ac, ac1) annotation (Line(points={{46,0},{24,0},{24,100},{0,
          100}}, color={0,0,255}));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(
          extent={{-80,60},{80,-80}},
          lineColor={95,95,95},
          fillPattern=FillPattern.Solid,
          fillColor={215,215,215}),
        Line(
          points={{-50,90},{-50,60}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{50,90},{50,60}},
          color={95,95,95},
          smooth=Smooth.None),
        Text(
          extent={{90,60},{50,100}},
          lineColor={95,95,95},
          textString="+"),
        Text(
          extent={{-50,60},{-90,100}},
          lineColor={95,95,95},
          textString="-"),
        Line(
          points={{-60,-58},{-60,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{-40,-58},{-40,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{-20,-58},{-20,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{0,-58},{0,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{20,-58},{20,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{40,-58},{40,22}},
          color={95,95,95},
          smooth=Smooth.None),
        Line(
          points={{60,-58},{60,22}},
          color={95,95,95},
          smooth=Smooth.None)}),
    Documentation(info="<html>
<p>The architecture of the CHEETA electrical system is shown below:</p>
<p><br><img src=\"modelica://CHEETA/Images/Electrical/CHEETASystem.PNG\"/></p>
</html>"),
    experiment(StopTime=0.5));
end PowerSystem;
