within DroneSimulation;
package Electrical
  annotation (Icon(graphics={
        Rectangle(
          lineColor={200,200,200},
          fillColor={248,248,248},
          fillPattern=FillPattern.HorizontalCylinder,
          extent={{-100.0,-100.0},{100.0,100.0}},
          radius=25.0),
        Rectangle(
          lineColor={128,128,128},
          extent={{-100.0,-100.0},{100.0,100.0}},
          radius=25.0),
        Line(
          points={{12,60},{12,-60}}),
        Line(
          points={{-12,60},{-12,-60}}),
        Line(points={{-80,0},{-12,0}}),
        Line(points={{12,0},{80,0}})}));
end Electrical;
