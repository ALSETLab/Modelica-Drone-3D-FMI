within DroneLibrary;
package Blocks
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
        origin={0.0,35.1488},
        fillColor={255,255,255},
        extent={{-30.0,-20.1488},{30.0,20.1488}}),
      Rectangle(
        origin={0.0,-34.8512},
        fillColor={255,255,255},
        extent={{-30.0,-20.1488},{30.0,20.1488}}),
      Line(
        origin={-51.25,0.0},
        points={{21.25,-35.0},{-13.75,-35.0},{-13.75,35.0},{6.25,35.0}}),
      Polygon(
        origin={-40.0,35.0},
        pattern=LinePattern.None,
        fillPattern=FillPattern.Solid,
        points={{10.0,0.0},{-5.0,5.0},{-5.0,-5.0}}),
      Line(
        origin={51.25,0.0},
        points={{-21.25,35.0},{13.75,35.0},{13.75,-35.0},{-6.25,-35.0}}),
      Polygon(
        origin={40.0,-35.0},
        pattern=LinePattern.None,
        fillPattern=FillPattern.Solid,
        points={{-10.0,0.0},{5.0,5.0},{5.0,-5.0}})}));
end Blocks;
