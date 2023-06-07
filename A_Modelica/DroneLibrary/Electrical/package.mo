within DroneLibrary;
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
        Line(points={{12,0},{80,0}})}), Documentation(info="<html>
<p>The models for the drone&apos;s motors and power sources are located in the <b>Electrical</b> package. This package contains models for the following:</p>
<ul>
<li><a href=\"modelica://DroneLibrary.Electrical.Sources\">Sources</a></li>
<li><a href=\"modelica://DroneLibrary.Electrical.Machines\">Machines</a></li>
<li><a href=\"modelica://DroneLibrary.Electrical.PowerElectroincs\">Power </a><a href=\"modelica://DroneLibrary.Electrical.PowerElectronics\">electronics</a></li>
<li><a href=\"modelica://DroneLibrary.Electrical\">Control modules</a></li>
</ul>
</html>"));
end Electrical;
