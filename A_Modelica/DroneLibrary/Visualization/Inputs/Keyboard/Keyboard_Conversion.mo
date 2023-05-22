within DroneLibrary.Visualization.Inputs.Keyboard;
model Keyboard_Conversion
  Modelica.Blocks.Interfaces.BooleanInput Direction_Pos
    annotation (Placement(transformation(extent={{-80,0},{-40,40}})));
  Modelica.Blocks.Interfaces.BooleanInput Direction_Neg
    annotation (Placement(transformation(extent={{-80,-40},{-40,0}})));
  Modelica.Blocks.Interfaces.RealOutput Output
    annotation (Placement(transformation(extent={{40,-10},{60,10}})));
  Modelica.Blocks.Math.BooleanToReal booleanToReal
    annotation (Placement(transformation(extent={{-36,14},{-24,26}})));
  Modelica.Blocks.Math.BooleanToReal booleanToReal1
    annotation (Placement(transformation(extent={{-36,-26},{-24,-14}})));
  Modelica.Blocks.Continuous.Integrator integrator
    annotation (Placement(transformation(extent={{-18,14},{-6,26}})));
  Modelica.Blocks.Continuous.Integrator integrator1
    annotation (Placement(transformation(extent={{-18,-26},{-6,-14}})));
  Modelica.Blocks.Math.Add add(k2=-1)
    annotation (Placement(transformation(extent={{4,-6},{16,6}})));
  Modelica.Blocks.Math.Gain gain(k=InputGain)
    annotation (Placement(transformation(extent={{30,-4},{38,4}})));
  parameter Real InputGain "Gain value multiplied with input signal";
 Modelica.Blocks.Continuous.FirstOrder firstOrder(T=0.3) annotation (
    Placement(transformation(extent={{18,-24},{28,-14}})));
equation
  connect(Direction_Pos, booleanToReal.u)
    annotation (Line(points={{-60,20},{-37.2,20}}, color={255,0,255}));
  connect(Direction_Neg, booleanToReal1.u)
    annotation (Line(points={{-60,-20},{-37.2,-20}}, color={255,0,255}));
  connect(booleanToReal.y, integrator.u)
    annotation (Line(points={{-23.4,20},{-19.2,20}}, color={0,0,127}));
  connect(booleanToReal1.y, integrator1.u)
    annotation (Line(points={{-23.4,-20},{-19.2,-20}}, color={0,0,127}));
  connect(integrator.y, add.u1) annotation (Line(points={{-5.4,20},{0,20},{0,
          3.6},{2.8,3.6}},
                     color={0,0,127}));
  connect(integrator1.y, add.u2) annotation (Line(points={{-5.4,-20},{0,-20},
          {0,-3.6},{2.8,-3.6}},
                          color={0,0,127}));
  connect(Output, gain.y)
    annotation (Line(points={{50,0},{38.4,0}}, color={0,0,127}));
 connect(add.y, firstOrder.u) annotation (Line(points={{16.6,0},{17,
         0},{17,-19}}, color={0,0,127}));
 connect(firstOrder.y, gain.u) annotation (Line(points={{28.5,-19},{
         28.5,-9.5},{29.2,-9.5},{29.2,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-40,-40},
            {40,40}})), Diagram(coordinateSystem(preserveAspectRatio=false,
          extent={{-40,-40},{40,40}})));
end Keyboard_Conversion;
