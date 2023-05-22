within DroneLibrary.Mechanical.Rotor;
package Templates

annotation (Icon(graphics={
      Rectangle(
        lineColor={200,200,200},
        fillColor={248,248,248},
        fillPattern=FillPattern.HorizontalCylinder,
        extent={{-100.0,-100.0},{100.0,100.0}},
        radius=25.0),
      Rectangle(
        lineColor={128,128,128},
        fillPattern=FillPattern.None,
        extent={{-100.0,-100.0},{100.0,100.0}},
        radius=25.0),
                Text(
          extent={{-40,90},{60,-90}},
          lineColor={255,0,0},
          textString="T",
          textStyle={TextStyle.Bold})}));
end Templates;
