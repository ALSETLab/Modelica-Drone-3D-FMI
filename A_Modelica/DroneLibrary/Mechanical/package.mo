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
    Documentation(info=""));
end Mechanical;
