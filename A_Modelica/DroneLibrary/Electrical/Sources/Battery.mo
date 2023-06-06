within DroneLibrary.Electrical.Sources;
model Battery
  PowerElectronics.Converters.DCDC.BuckConverter         dcdc annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={4,2})));
  Modelica.Electrical.PowerConverters.DCDC.Control.SignalPWM pwm(
      constantDutyCycle=0.4, f(displayUnit="kHz") = 1000)
    annotation (Placement(transformation(extent={{-6,-40},{14,-20}})));
  Modelica.Electrical.Batteries.BatteryStacks.CellRCStack battery2(
    Ns=3,
    Np=1,
    cellData=cellData2,
    useHeatPort=false,
    SOC(fixed=true, start=0.95)) annotation (Placement(transformation(
        extent={{10,10},{-10,-10}},
        origin={-30,8})));
  parameter Modelica.Electrical.Batteries.ParameterRecords.TransientData.ExampleData cellData2(
    Qnom=18000,
    useLinearSOCDependency=false,
    Ri=cellData2.OCVmax/1200,
    Idis=0.1,
    nRC=2,
    rcData={Modelica.Electrical.Batteries.ParameterRecords.TransientData.RCData(
        R=0.2*cellData2.Ri, C=60/(0.2*cellData2.Ri)),
        Modelica.Electrical.Batteries.ParameterRecords.TransientData.RCData(R=
        0.1*cellData2.Ri, C=10/(0.1*cellData2.Ri))})
    annotation (Placement(transformation(extent={{-40,24},{-20,44}})));
  Modelica.Electrical.Analog.Interfaces.PositivePin dc_p1
    "Positive DC output"
    annotation (Placement(transformation(extent={{18,14},{38,34}})));
  Modelica.Electrical.Analog.Interfaces.NegativePin dc_n1
    "Negative DC output"
    annotation (Placement(transformation(extent={{32,14},{52,34}})));
equation
  connect(dcdc.fire_p,pwm. fire)
    annotation (Line(points={{-2,-10},{-2,-19}},    color={255,0,255}));
  connect(battery2.p,dcdc. dc_p1)
    annotation (Line(points={{-20,8},{-6,8}},      color={0,0,255}));
  connect(battery2.n,dcdc. dc_n1) annotation (Line(points={{-40,8},{-44,8},{-44,
          -4},{-6,-4}},         color={0,0,255}));
  connect(dcdc.dc_p2, dc_p1)
    annotation (Line(points={{14,8},{28,8},{28,24}}, color={0,0,255}));
  connect(dcdc.dc_n2, dc_n1)
    annotation (Line(points={{14,-4},{42,-4},{42,24}}, color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end Battery;
