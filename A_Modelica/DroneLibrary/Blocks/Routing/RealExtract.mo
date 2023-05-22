within DroneLibrary.Blocks.Routing;
model RealExtract
  "Pass a Real signal through without modification"
  parameter Integer index= 3 "output which variable in the array";

  Modelica.Blocks.Interfaces.RealInput u[3]
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}})));
  Modelica.Blocks.Interfaces.RealOutput y
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
equation
  y = u[index];
  annotation (Icon(coordinateSystem(preserveAspectRatio=true, extent={{-100,
            -100},{100,100}}), graphics={Line(points={{-100,0},{100,0}},
            color={0,0,127}), Rectangle(extent={{-100,100},{100,-100}},
            lineColor={28,108,200}),
        Line(points={{-80,80}}, color={28,108,200}),
        Line(points={{-100,60},{0,60},{100,0}}, color={28,108,200}),
        Line(points={{-80,0},{0,0}}, color={255,0,0}),
        Line(points={{-100,-60},{0,-60}}, color={255,0,0}),
        Rectangle(
          extent={{0,20},{4,-20}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid),
        Rectangle(
          extent={{0,-40},{4,-80}},
          lineColor={0,0,0},
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid)}),
                    Documentation(info="<html>
<p>This block passes a Real signal through without modification. Enables signals to be read out of one bus, have their name changed and be sent back to a bus. </p>
</html>"));
end RealExtract;
