within DroneSimulation.Electrical.PowerElectronics.Converters.ACDC;
model ThreePhaseRectifier "3 phase rectifier model"
  Switches.Diode_Snubber idealDiode1(
    Rcond=Rcond,
    Vt=Vt,
    Gof=Gof,
    R1=R1,
    C1=C1) annotation (Placement(transformation(
        origin={0,15},
        extent={{-6,-5},{6,5}},
        rotation=180)));
  Modelica.Electrical.MultiPhase.Basic.Star
             star1(m=m) annotation (Placement(transformation(
        origin={0,50},
        extent={{-10,-10},{10,10}},
        rotation=90)));
  Modelica.Electrical.MultiPhase.Basic.Star
             star2(m=m) annotation (Placement(transformation(
        origin={0,-50},
        extent={{-10,10},{10,-10}},
        rotation=270)));
  Modelica.Electrical.MultiPhase.Interfaces.PositivePlug plug_p1
                                 "Positive polyphase electrical plug with m pins"
    annotation (Placement(transformation(extent={{-90,-10},{-70,10}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin load_n
    "Negative pin connection for load"
    annotation (Placement(transformation(extent={{-10,-94},{10,-74}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin load_p
    "Positive pin connection for load"
    annotation (Placement(transformation(extent={{-10,74},{10,94}})));
  parameter Integer m=m "Number of phases";

  Switches.Diode_Snubber idealDiode2(
    Rcond=Rcond,
    Vt=Vt,
    Gof=Gof,
    R1=R1,
    C1=C1) annotation (Placement(transformation(
        origin={1e-06,-23},
        extent={{-6,-5},{6,5.00004}},
        rotation=180)));
  parameter Modelica.SIunits.Resistance Rcond=1e-5
    "Forward state-on differential resistance (closed resistance)";
  parameter Modelica.SIunits.Voltage Vt=0 "Forward threshold voltage";
  parameter Modelica.SIunits.Conductance Gof=1e-5
    "Backward state-off conductance (opened conductance)";
  parameter Modelica.SIunits.Resistance R1=1e-3 "Snubber Resistance";
  parameter Modelica.SIunits.Capacitance C1=1e-6 "SnubberCapacitance";
equation
  connect(star2.pin_n, load_n)
    annotation (Line(points={{0,-60},{0,-84}}, color={0,0,255}));
  connect(star1.pin_n, load_p)
    annotation (Line(points={{0,60},{0,84}}, color={0,0,255}));
  connect(idealDiode1.negativePlug, star1.plug_p)
    annotation (Line(points={{-0.133333,20},{0,20},{0,40}}, color={0,0,255}));
  connect(idealDiode1.positivePlug, idealDiode2.negativePlug) annotation (Line(
        points={{-8.88178e-16,9.875},{-8.88178e-16,-2.0875},{-0.133332,-2.0875},
          {-0.133332,-18}}, color={0,0,255}));
  connect(idealDiode2.positivePlug, star2.plug_p) annotation (Line(points={{1e-06,
          -28.125},{1e-06,-34},{0,-34},{0,-40}}, color={0,0,255}));
  connect(plug_p1, idealDiode2.negativePlug) annotation (Line(points={{-80,0},{-4.44089e-16,
          0},{-4.44089e-16,-2.0875},{-0.133332,-2.0875},{-0.133332,-18}}, color=
         {0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,-80},
            {80,80}}), graphics={
        Polygon(
          points={{0,20},{2,16},{20,-20},{-22,-20},{0,20}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid),
        Rectangle(
          extent={{-28,26},{28,20}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid),
        Line(
          points={{0,68},{0,26}},
          color={0,0,0}),
        Line(
          points={{0,-66},{0,-20}},
          color={0,0,0}),
        Rectangle(extent={{-80,80},{80,-80}}, lineColor={28,108,200})}),
                          Diagram(coordinateSystem(preserveAspectRatio=false,
          extent={{-80,-80},{80,80}})));
end ThreePhaseRectifier;
