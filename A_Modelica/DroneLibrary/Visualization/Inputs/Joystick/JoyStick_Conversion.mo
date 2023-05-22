within DroneLibrary.Visualization.Inputs.Joystick;
model JoyStick_Conversion
  Modelica.Blocks.Interfaces.RealOutput Output
    annotation (Placement(transformation(extent={{40,-10},{60,10}})));
  Modelica.Blocks.Continuous.Integrator integrator
    annotation (Placement(transformation(extent={{-14,-6},{-2,6}})));
  Modelica.Blocks.Math.Gain gain(k=InputGain)
    annotation (Placement(transformation(extent={{6,-4},{14,4}})));
  parameter Real InputGain "Gain value multiplied with input signal";
  Modelica.Blocks.Math.Gain gain1(k=-2)
    annotation (Placement(transformation(extent={{-28,-4},{-20,4}})));
 Modelica.Blocks.Interfaces.RealInput JoyStickInput annotation (
     Placement(transformation(extent={{-60,-10},{-40,10}})));
 Modelica.Blocks.Continuous.FirstOrder firstOrder(T=0.3)
   annotation (Placement(transformation(extent={{22,-6},{34,6}})));
equation
 connect(gain.u, integrator.y)
   annotation (Line(points={{5.2,0},{-1.4,0}}, color={0,0,127}));
 connect(integrator.u, gain1.y)
   annotation (Line(points={{-15.2,0},{-19.6,0}}, color={0,0,127}));
 connect(JoyStickInput, gain1.u)
   annotation (Line(points={{-50,0},{-28.8,0}}, color={0,0,127}));
 connect(gain.y, firstOrder.u)
   annotation (Line(points={{14.4,0},{20.8,0}}, color={0,0,127}));
 connect(Output, firstOrder.y)
   annotation (Line(points={{50,0},{34.6,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-40,-40},
            {40,40}})), Diagram(coordinateSystem(preserveAspectRatio=false,
          extent={{-40,-40},{40,40}})));
end JoyStick_Conversion;
