within DroneLibrary.Blocks.Sources;
model linePath
  Modelica.Blocks.Sources.Ramp ramp2(
    duration=0.5,
    offset=0.25,
    height=5,
    startTime=5)
    annotation (Placement(transformation(extent={{-14,-26},{6,-6}})));
  Modelica.Blocks.Sources.Ramp ramp3(
    duration=0.5,
    height=5,
    offset=0,
    startTime=15)
    annotation (Placement(transformation(extent={{-14,8},{6,28}})));
  Modelica.Blocks.Math.Add add(k1=-1)
    annotation (Placement(transformation(extent={{34,-10},{54,10}})));
  Modelica.Blocks.Interfaces.RealOutput y
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(
    T=0.2,
    y_start=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={80,0})));
equation
  connect(ramp3.y,add. u1) annotation (Line(points={{7,18},{28,18},{28,6},{
          32,6}}, color={0,0,127}));
  connect(ramp2.y,add. u2) annotation (Line(points={{7,-16},{28,-16},{28,-6},
          {32,-6}}, color={0,0,127}));
  connect(add.y, firstOrder1.u)
    annotation (Line(points={{55,0},{68,0}}, color={0,0,127}));
  connect(firstOrder1.y, y)
    annotation (Line(points={{91,0},{110,0}}, color={0,0,127}));
  annotation (
    uses(Modelica(version="3.2.3")),
    Documentation(info="<html>
<p>This applies a ramp path along an axis to control the quadcopter in a line.</p>
</html>"));
end linePath;
