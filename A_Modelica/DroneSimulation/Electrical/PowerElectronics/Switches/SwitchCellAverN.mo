within DroneSimulation.Electrical.PowerElectronics.Switches;
model SwitchCellAverN "Switching cell average n"
  Modelica.Blocks.Interfaces.BooleanInput GateSignal
    annotation (Placement(transformation(extent={{-186,-4},{-160,22}}),
        iconTransformation(extent={{-186,-4},{-160,22}})));
  Modelica.Electrical.Analog.Interfaces.Pin pin
    annotation (Placement(transformation(extent={{-130,80},{-110,100}}),
        iconTransformation(extent={{-130,80},{-110,100}})));
  parameter Modelica.SIunits.Resistance Ron
    "Forward state-on differential resistance (closed resistance)";
  Modelica.Electrical.Analog.Interfaces.NegativePin pin_n
    annotation (Placement(transformation(extent={{-130,-80},{-110,-60}}),
        iconTransformation(extent={{-130,-80},{-110,-60}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent   signalCurrent
    annotation (Placement(transformation(
        extent={{10,-10},{-10,10}},
        rotation=-90,
        origin={-132,0})));

  Modelica.Blocks.Interfaces.RealInput DutyCycle
    annotation (Placement(transformation(extent={{20,40},{0,60}}),
        iconTransformation(extent={{20,40},{0,60}})));
  Modelica.Blocks.Math.Gain gain2(k=2) annotation (Placement(transformation(
        extent={{-5,-5},{5,5}},
        rotation=180,
        origin={-13,41})));
  Modelica.Blocks.Sources.Constant const(k=1)
    annotation (Placement(transformation(extent={{-4,16},{-16,28}})));
  Modelica.Blocks.Math.Add add(k2=-1)
    annotation (Placement(transformation(extent={{-26,30},{-36,40}})));
  Modelica.Blocks.Math.Add add1(k2=+1, k1=-1)
    annotation (Placement(transformation(extent={{-48,26},{-58,36}})));
  Modelica.Blocks.Math.Division division
    annotation (Placement(transformation(extent={{-72,14},{-84,26}})));
  Modelica.Blocks.Sources.Constant const2(k=2)
    annotation (Placement(transformation(extent={{-48,2},{-60,14}})));
  Modelica.Blocks.Sources.Constant const1(k=1)
    annotation (Placement(transformation(extent={{-26,10},{-38,22}})));
  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-90,-6},{-102,6}})));
  Modelica.Blocks.Interfaces.RealInput current
    annotation (Placement(transformation(extent={{20,-40},{0,-20}}),
        iconTransformation(extent={{20,-40},{0,-20}})));
  Modelica.Electrical.Analog.Basic.Resistor resistor(R=Ron)
                                                     annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=-90,
        origin={-132,-30})));
equation
  connect(signalCurrent.n, pin)
    annotation (Line(points={{-132,10},{-132,50},{-132,90},{-120,90}},
                                                   color={0,0,255}));
  connect(gain2.u, DutyCycle) annotation (Line(points={{-7,41},{-5.5,41},{-5.5,
          50},{10,50}},      color={0,0,127}));
  connect(gain2.y, add.u1) annotation (Line(points={{-18.5,41},{-20,41},{
          -20,40},{-22,40},{-22,38},{-25,38}}, color={0,0,127}));
  connect(const.y, add.u2) annotation (Line(points={{-16.6,22},{-20,22},{
          -20,32},{-25,32}}, color={0,0,127}));
  connect(add1.u1, add.y) annotation (Line(points={{-47,34},{-42,34},{-42,
          35},{-36.5,35}}, color={0,0,127}));
  connect(add1.u2, const1.y) annotation (Line(points={{-47,28},{-44,28},{
          -44,16},{-38.6,16}}, color={0,0,127}));
  connect(add1.y, division.u1) annotation (Line(points={{-58.5,31},{-64.25,
          31},{-64.25,23.6},{-70.8,23.6}}, color={0,0,127}));
  connect(const2.y, division.u2) annotation (Line(points={{-60.6,8},{-66,8},
          {-66,16.4},{-70.8,16.4}}, color={0,0,127}));
  connect(division.y, product.u1) annotation (Line(points={{-84.6,20},{-86,
          20},{-86,3.6},{-88.8,3.6}}, color={0,0,127}));
  connect(current, product.u2) annotation (Line(points={{10,-30},{-34,-30},{-34,
          -3.6},{-88.8,-3.6}},      color={0,0,127}));
  connect(product.y, signalCurrent.i)
    annotation (Line(points={{-102.6,0},{-120,0}}, color={0,0,127}));
  connect(signalCurrent.p, resistor.p)
    annotation (Line(points={{-132,-10},{-132,-20}}, color={0,0,255}));
  connect(resistor.n, pin_n) annotation (Line(points={{-132,-40},{-132,-70},{
          -120,-70}},
                 color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-160,
            -60},{0,80}}), graphics={Rectangle(extent={{-160,80},{0,-60}},
            lineColor={28,108,200})}),
                             Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-160,-60},{0,80}})));
end SwitchCellAverN;
