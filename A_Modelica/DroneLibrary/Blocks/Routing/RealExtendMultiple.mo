within DroneLibrary.Blocks.Routing;
model RealExtendMultiple
  "Pass a Real signal through without modification"

  Modelica.Blocks.Interfaces.RealInput u
    annotation (Placement(transformation(extent={{-120,40},{-80,80}})));
  Modelica.Blocks.Interfaces.RealOutput y[3]
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  Modelica.Blocks.Interfaces.RealInput u1
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}})));
  Modelica.Blocks.Interfaces.RealInput u2
    annotation (Placement(transformation(extent={{-120,-80},{-80,-40}})));
equation
  y = {u,u1,u2};
  annotation (Icon(coordinateSystem(preserveAspectRatio=true, extent={{-100,
            -100},{100,100}}), graphics={Line(points={{-100,0},{100,0}},
            color={0,0,127}), Rectangle(extent={{-100,100},{100,-100}},
            lineColor={28,108,200}),
        Line(points={{-80,0}}, color={81,255,0}),
        Line(points={{-80,0},{0,60},{100,60}}, color={28,108,200}),
        Line(points={{-80,0},{100,0},{100,-60},{0,-60},{-80,0}}, color={28,108,200})}),
                    Documentation(info="<html>
<p>Passes a Real signal through without modification. Enables signals to be read out of one bus, have their name changed and be sent back to a bus. </p>
<p>This block tables inputs u1, u2, and u3 to produce output y = [u1,u2,u3].</p>
</html>"));
end RealExtendMultiple;
