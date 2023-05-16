within DroneSimulation.Electrical.PowerElectronics.Converters.ACDC;
model Simulink_Averaged_Rectifier "Averaged rectifier model from Simulink"
  Modelica.Electrical.Analog.Interfaces.PositivePin DC_p
    annotation (Placement(transformation(extent={{80,50},{100,70}}),
        iconTransformation(extent={{80,50},{100,70}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin DC_n
    annotation (Placement(transformation(extent={{80,-70},{100,-50}}),
        iconTransformation(extent={{80,-70},{100,-50}})));
  Modelica.Electrical.Polyphase.Interfaces.PositivePlug AC annotation (
      Placement(transformation(extent={{-100,-10},{-80,10}}),
        iconTransformation(extent={{-100,-10},{-80,10}})));
  Modelica.Units.SI.Voltage va;
  Modelica.Units.SI.Voltage vb;
  Modelica.Units.SI.Voltage vc;
  Modelica.Units.SI.Voltage vab;
  Modelica.Units.SI.Voltage vbc;
  Modelica.Units.SI.Voltage vca;
  Modelica.Units.SI.Voltage vref;
  Modelica.Units.SI.Voltage vrms;
  Modelica.Units.SI.Voltage vdc;
  Modelica.Units.SI.Resistance rac;
  Modelica.Units.SI.Resistance R_fixed;
  Modelica.Units.SI.Power Pdc;
  parameter Modelica.Units.SI.Power P_fixed;
  parameter Modelica.Units.SI.Voltage V_rated;

  Modelica.Electrical.Analog.Interfaces.PositivePin v_ref
    annotation (Placement(transformation(extent={{74,-10},{94,10}}),
        iconTransformation(extent={{80,-10},{100,10}})));
equation
  va = AC.pin[1].v;
  vb = AC.pin[2].v;
  vc = AC.pin[3].v;
  vab = va-vb;
  vbc = vb-vc;
  vca = vc-va;

  vref = (va+vb+vc)/3;

  vrms = max(sqrt((vab^2+vbc^2+vca^2)/3),1e-12);

  vdc = 3*sqrt(2)*vrms/Modelica.Constants.pi;

  DC_p.v = vref + vdc/2;
  DC_n.v = vref - vdc/2;

  R_fixed = V_rated^2/P_fixed;
  Pdc = -DC_p.v*DC_p.i-DC_n.v*DC_n.i;
  rac = vrms^2/(Pdc+vrms^2/R_fixed);

  AC.pin[1].i = (va-vref)/rac;
  AC.pin[2].i = (vb-vref)/rac;
  AC.pin[3].i = (vc-vref)/rac;
  vref = v_ref.v;
        annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -80},{80,80}}), graphics={
        Rectangle(
          extent={{-80,80},{80,-80}},
          lineColor={28,108,200}),
        Line(
          points={{-80,80},{-80,-80},{80,-80},{80,80},{-80,80}},
          color={28,108,200},
          thickness=0.5),
        Line(
          points={{-80,-80},{80,80}},
          color={28,108,200},
          thickness=0.5),
        Text(
          extent={{-66,58},{6,28}},
          lineColor={28,108,200},
          fillColor={197,197,197},
          fillPattern=FillPattern.Solid,
          textString="AC",
          lineThickness=0.5),
        Text(
          extent={{-2,-32},{60,-58}},
          lineColor={28,108,200},
          fillColor={197,197,197},
          fillPattern=FillPattern.Solid,
          textString="DC",
          lineThickness=0.5)}), Diagram(
        coordinateSystem(preserveAspectRatio=false, extent={{-80,-80},{80,80}})));
end Simulink_Averaged_Rectifier;
