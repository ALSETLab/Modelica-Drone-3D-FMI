within DroneLibrary;
package Mechanical

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
      Rectangle(
        origin={8.6,63.3333},
        lineColor={64,64,64},
        fillColor={192,192,192},
        fillPattern=FillPattern.HorizontalCylinder,
        extent={{-4.6,-93.3333},{41.4,-53.3333}}),
      Ellipse(
        origin={9.0,46.0},
        extent={{-90.0,-60.0},{-80.0,-50.0}}),
      Line(
        origin={9.0,46.0},
        points={{-85.0,-55.0},{-60.0,-21.0}},
        thickness=0.5),
      Ellipse(
        origin={9.0,46.0},
        extent={{-65.0,-26.0},{-55.0,-16.0}}),
      Line(
        origin={9.0,46.0},
        points={{-60.0,-21.0},{9.0,-55.0}},
        thickness=0.5),
      Ellipse(
        origin={9.0,46.0},
        fillPattern=FillPattern.Solid,
        extent={{4.0,-60.0},{14.0,-50.0}}),
      Line(
        origin={9.0,46.0},
        points={{-10.0,-26.0},{72.0,-26.0},{72.0,-86.0},{-10.0,-86.0}})}),
    Documentation(info="<html>
<p>The models for the drone&apos;s motors and power sources are located in the <b>Mechanical</b> package. This package contains models for the following:</p>
<ul>
<li><a href=\"modelica://DroneLibrary.Mechanical.Blades\">Blades:</a> the mechanical models for the quadcopter&apos;s blades.</li>
<li><a href=\"modelica://DroneLibrary.Mechanical.Propeller\">Propeller:</a> the top-level package of the propeller containing the models for the motor, rotor, and blades connected in different variations.</li>
<li><a href=\"modelica://DroneLibrary.Mechanical.Chassis\">Chassis: </a>models of the quadcopter body.</li>
<li><a href=\"modelica://DroneLibrary.Mechanical.Rotor\">Rotor:</a> the models of the rotor connecting the motor to the blades.</li>
<li><a href=\"modelica://DroneLibrary.Mechanical.Motor\">Motor</a>: motor models to drive the blades to provied lift to the aircraft.</li>
</ul>
</html>"));
end Mechanical;
