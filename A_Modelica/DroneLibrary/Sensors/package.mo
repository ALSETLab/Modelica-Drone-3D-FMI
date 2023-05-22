within DroneLibrary;
package Sensors
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
        Ellipse(origin={0.0,-30.0},
          fillColor={255,255,255},
          extent={{-90.0,-90.0},{90.0,90.0}},
          startAngle=20.0,
          endAngle=160.0),
        Ellipse(origin={0.0,-30.0},
          fillColor={128,128,128},
          pattern=LinePattern.None,
          fillPattern=FillPattern.Solid,
          extent={{-20.0,-20.0},{20.0,20.0}}),
        Line(origin={0.0,-30.0},
          points={{0.0,60.0},{0.0,90.0}}),
        Ellipse(origin={-0.0,-30.0},
          fillColor={64,64,64},
          pattern=LinePattern.None,
          fillPattern=FillPattern.Solid,
          extent={{-10.0,-10.0},{10.0,10.0}}),
        Polygon(
          origin={-0.0,-30.0},
          rotation=-35.0,
          fillColor={64,64,64},
          pattern=LinePattern.None,
          fillPattern=FillPattern.Solid,
          points={{-7.0,0.0},{-3.0,85.0},{0.0,90.0},{3.0,85.0},{7.0,0.0}})}));
end Sensors;
