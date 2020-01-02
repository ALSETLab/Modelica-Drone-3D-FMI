within DroneSimulation.Electrical.PowerElectronics.Switches;
model SwitchCellAverP "Switching cell average P"
  Modelica.Blocks.Interfaces.BooleanInput GateSignal
    annotation (Placement(transformation(extent={{-126,-22},{-100,4}}),
        iconTransformation(extent={{-126,-22},{-100,4}})));
  Modelica.Electrical.Analog.Interfaces.Pin pin
    annotation (Placement(transformation(extent={{-70,60},{-50,80}}),
        iconTransformation(extent={{-70,60},{-50,80}})));

  Modelica.Electrical.Analog.Interfaces.NegativePin pin_n
    annotation (Placement(transformation(extent={{-70,-100},{-50,-80}}),
        iconTransformation(extent={{-70,-100},{-50,-80}})));

  Modelica.Electrical.Analog.Sources.SignalCurrent signalCurrent annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=-90,
        origin={-72,-16})));

  Modelica.Blocks.Interfaces.RealInput DutyCycle
    annotation (Placement(transformation(extent={{68,18},{52,34}}),
        iconTransformation(extent={{80,20},{60,40}})));
  Modelica.Blocks.Math.Gain gain2(k=2) annotation (Placement(transformation(
        extent={{-5,-5},{5,5}},
        rotation=180,
        origin={37,25})));
  Modelica.Blocks.Sources.Constant const(k=1)
    annotation (Placement(transformation(extent={{46,0},{34,12}})));
  Modelica.Blocks.Math.Add add(k2=-1)
    annotation (Placement(transformation(extent={{24,14},{14,24}})));
  Modelica.Blocks.Math.Add add1(k2=+1)
    annotation (Placement(transformation(extent={{2,10},{-8,20}})));
  Modelica.Blocks.Math.Division division
    annotation (Placement(transformation(extent={{-22,-2},{-34,10}})));
  Modelica.Blocks.Sources.Constant const2(k=2)
    annotation (Placement(transformation(extent={{2,-14},{-10,-2}})));
  Modelica.Blocks.Sources.Constant const1(k=1)
    annotation (Placement(transformation(extent={{24,-6},{12,6}})));
  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-40,-22},{-52,-10}})));
  Modelica.Blocks.Interfaces.RealInput current
    annotation (Placement(transformation(extent={{80,-60},{60,-40}}),
        iconTransformation(extent={{80,-60},{60,-40}})));
  Modelica.Electrical.Analog.Basic.Resistor resistor(R=Ron)
                                                     annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=-90,
        origin={-72,-48})));
  parameter Modelica.SIunits.Resistance Ron "Forward state-on differential resistance (closed resistance)";
equation
  connect(pin, signalCurrent.p)
    annotation (Line(points={{-60,70},{-60,32},{-72,32},{-72,-6}},
                                                 color={0,0,255}));
  connect(gain2.u, DutyCycle) annotation (Line(points={{43,25},{44.5,25},{
          44.5,26},{60,26}}, color={0,0,127}));
  connect(gain2.y, add.u1) annotation (Line(points={{31.5,25},{30,25},{30,
          24},{28,24},{28,22},{25,22}}, color={0,0,127}));
  connect(const.y, add.u2) annotation (Line(points={{33.4,6},{30,6},{30,16},
          {25,16}}, color={0,0,127}));
  connect(add1.u1, add.y) annotation (Line(points={{3,18},{8,18},{8,19},{
          13.5,19}}, color={0,0,127}));
  connect(add1.u2, const1.y) annotation (Line(points={{3,12},{6,12},{6,0},{
          11.4,0}}, color={0,0,127}));
  connect(add1.y, division.u1) annotation (Line(points={{-8.5,15},{-14.25,
          15},{-14.25,7.6},{-20.8,7.6}}, color={0,0,127}));
  connect(const2.y, division.u2) annotation (Line(points={{-10.6,-8},{-16,
          -8},{-16,0.4},{-20.8,0.4}}, color={0,0,127}));
  connect(division.y, product.u1) annotation (Line(points={{-34.6,4},{-36,4},
          {-36,-12.4},{-38.8,-12.4}}, color={0,0,127}));
  connect(current, product.u2) annotation (Line(points={{70,-50},{12,-50},{12,
          -19.6},{-38.8,-19.6}},    color={0,0,127}));
  connect(product.y, signalCurrent.i)
    annotation (Line(points={{-52.6,-16},{-60,-16}}, color={0,0,127}));
  connect(signalCurrent.n, resistor.p)
    annotation (Line(points={{-72,-26},{-72,-38}}, color={0,0,255}));
  connect(resistor.n, pin_n)
    annotation (Line(points={{-72,-58},{-72,-74},{-72,-90},{-60,-90}},
                                                   color={0,0,255}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -80},{60,60}}), graphics={Rectangle(extent={{-100,60},{60,-80}},
            lineColor={28,108,200})}),
                             Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-100,-80},{60,60}})));
end SwitchCellAverP;
