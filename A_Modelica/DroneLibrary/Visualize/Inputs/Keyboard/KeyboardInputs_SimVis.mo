within DroneLibrary.Visualize.Inputs.Keyboard;
model KeyboardInputs_SimVis
  extends DroneLibrary.Visualize.Interfaces.InputDevice_SimVis;
  Modelica_DeviceDrivers.Blocks.OperatingSystem.RealtimeSynchronize
                                      realtimeSynchronize
    annotation (Placement(transformation(extent={{-60,-10},{-40,10}})));
 DroneLibrary.Visualize.Inputs.Keyboard.Keyboard_Conversion y(InputGain=3) annotation (Placement(transformation(extent={{12,-10},{30,10}})));
 DroneLibrary.Visualize.Inputs.Keyboard.Keyboard_Conversion x(InputGain=3) annotation (Placement(transformation(extent={{12,20},{30,40}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput(keyCode=Forward)
   annotation (Placement(transformation(extent={{-36,0},{-26,10}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput1(keyCode=Backward)
   annotation (Placement(transformation(extent={{-36,-10},{-26,0}})));
 DroneLibrary.Visualize.Inputs.Keyboard.Keyboard_Conversion z(InputGain=3) annotation (Placement(transformation(extent={{12,-40},{30,-20}})));
 Modelica.Blocks.Interfaces.RealOutput Y
   annotation (Placement(transformation(extent={{100,-10},{120,10}}),
       iconTransformation(extent={{100,-10},{120,10}})));
 Modelica.Blocks.Interfaces.RealOutput Z
   annotation (Placement(transformation(extent={{100,-60},{120,-40}}),
       iconTransformation(extent={{100,-60},{120,-40}})));
 Modelica.Blocks.Interfaces.RealOutput X
   annotation (Placement(transformation(extent={{100,40},{120,60}}),
       iconTransformation(extent={{100,40},{120,60}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput2(keyCode=Right)
   annotation (Placement(transformation(extent={{-36,30},{-26,40}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput3(keyCode=Left)
   annotation (Placement(transformation(extent={{-36,20},{-26,30}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput4(keyCode=Up)
   annotation (Placement(transformation(extent={{-36,-30},{-26,-20}})));
 Modelica_DeviceDrivers.Blocks.InputDevices.KeyboardKeyInput
   keyboardKeyInput5(keyCode=Down)
   annotation (Placement(transformation(extent={{-36,-40},{-26,-30}})));
 parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Left="A"
    "Monitored Key";
  parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Right="D"
    "Monitored Key";
  parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Forward="W"
    "Monitored Key";
  parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Backward="S"
    "Monitored Key";
  parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Up="Up"
    "Monitored Key";
  parameter Modelica_DeviceDrivers.Blocks.InputDevices.Types.keyCodes Down="Down"
    "Monitored Key";
equation
 connect(keyboardKeyInput.keyState, y.Direction_Pos)
   annotation (Line(points={{-25.5,5},{7.5,5}}, color={255,0,255}));
 connect(keyboardKeyInput1.keyState, y.Direction_Neg)
   annotation (Line(points={{-25.5,-5},{7.5,-5}}, color={255,0,255}));
 connect(keyboardKeyInput3.keyState, x.Direction_Neg)
   annotation (Line(points={{-25.5,25},{7.5,25}}, color={255,0,255}));
 connect(keyboardKeyInput2.keyState, x.Direction_Pos)
   annotation (Line(points={{-25.5,35},{7.5,35}}, color={255,0,255}));
 connect(keyboardKeyInput4.keyState, z.Direction_Pos)
   annotation (Line(points={{-25.5,-25},{7.5,-25}}, color={255,0,255}));
 connect(keyboardKeyInput5.keyState, z.Direction_Neg)
   annotation (Line(points={{-25.5,-35},{7.5,-35}}, color={255,0,255}));
 connect(x.Output, X)
   annotation (Line(points={{32.25,30},{72,30},{72,50},{110,50}},
                                                 color={0,0,127}));
 connect(y.Output, Y)
   annotation (Line(points={{32.25,0},{110,0}},color={0,0,127}));
 connect(z.Output, Z)
   annotation (Line(points={{32.25,-30},{72,-30},{72,-50},{110,-50}},
                                                   color={0,0,127}));
 annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,
           -100},{100,100}}), graphics={ Polygon(
          points={{0,-100},{-80,-100},{-88,-98},{-94,-94},{-98,-88},{-100,-80},
              {-100,80},{-98,88},{-94,94},{-88,98},{-80,100},{80,100},{88,98},{
              94,94},{98,88},{100,80},{100,-80},{98,-88},{94,-94},{88,-98},{80,
              -100},{0,-100}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={255,255,255},
          fillPattern=FillPattern.Solid), Line(
          points={{0,-100},{-80,-100},{-88,-98},{-94,-94},{-98,-88},{-100,-80},
              {-100,80},{-98,88},{-94,94},{-88,98},{-80,100},{80,100},{88,98},{
              94,94},{98,88},{100,80},{100,-80},{98,-88},{94,-94},{88,-98},{80,
              -100},{0,-100}},
          color={0,64,127},
          thickness=0.5),
        Rectangle(
          extent={{-28,58},{28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={215,215,215},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-28,58},{-20,58},{-20,18},{-28,2},{-28,58}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={175,175,175},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{28,58},{18,58},{18,18},{28,2},{28,58}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={135,135,135},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-28,2},{-20,18},{18,18},{28,2},{-28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Rectangle(
          extent={{-28,2},{28,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={215,215,215},
          fillPattern=FillPattern.Solid),
        Rectangle(
          extent={{28,2},{84,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={215,215,215},
          fillPattern=FillPattern.Solid),
        Rectangle(
          extent={{-84,2},{-28,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={215,215,215},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-84,-54},{-76,-38},{-38,-38},{-28,-54},{-84,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-84,2},{-76,2},{-76,-38},{-84,-54},{-84,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={175,175,175},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-28,2},{-38,2},{-38,-38},{-28,-54},{-28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={135,135,135},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-28,2},{-20,2},{-20,-38},{-28,-54},{-28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={175,175,175},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{28,2},{18,2},{18,-38},{28,-54},{28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={135,135,135},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{-28,-54},{-20,-38},{18,-38},{28,-54},{-28,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{28,2},{36,2},{36,-38},{28,-54},{28,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={175,175,175},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{84,2},{74,2},{74,-38},{84,-54},{84,2}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={135,135,135},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{28,-54},{36,-38},{74,-38},{84,-54},{28,-54}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Line(points={{-2,50},{-2,28}}, color={95,95,95}),
        Polygon(
          points={{-2,50},{-6,42},{2,42},{-2,50}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Line(points={{-2,-6},{-2,-28}}, color={95,95,95}),
        Polygon(
          points={{-2,-28},{-6,-20},{2,-20},{-2,-28}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Line(points={{-46,-18},{-68,-18}}, color={95,95,95}),
        Polygon(
          points={{-60,-22},{-68,-18},{-60,-14},{-60,-22}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid),
        Line(points={{66,-18},{44,-18}}, color={95,95,95}),
        Polygon(
          points={{58,-22},{66,-18},{58,-14},{58,-22}},
          lineColor={0,0,255},
          pattern=LinePattern.None,
          fillColor={95,95,95},
          fillPattern=FillPattern.Solid)}));
end KeyboardInputs_SimVis;
