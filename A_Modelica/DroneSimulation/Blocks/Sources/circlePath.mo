within DroneSimulation.Blocks.Sources;
model circlePath
  Modelica.Blocks.Sources.Cosine cosine(
    startTime=10,
    amplitude=2,
    offset=-2,
    f=0.2) annotation (Placement(transformation(extent={{-44,42},{-24,62}})));
  Modelica.Blocks.Sources.Ramp ramp4(
    height=1,
    duration=0,
    offset=0,
    startTime=10)
    annotation (Placement(transformation(extent={{-42,0},{-22,20}})));
  Modelica.Blocks.Math.Add add2(k1=+1)
    annotation (Placement(transformation(extent={{-2,-50},{18,-30}})));
  Modelica.Blocks.Sources.Ramp ramp5(
    duration=0.5,
    offset=0.25,
    startTime=3,
    height=2)
    annotation (Placement(transformation(extent={{-40,-74},{-20,-54}})));
  Modelica.Blocks.Math.Product product
    annotation (Placement(transformation(extent={{-12,24},{8,44}})));
  Modelica.Blocks.Sources.Sine sine(
    startTime=10,
    offset=0.25,
    amplitude=2,
    f=0.2) annotation (Placement(transformation(extent={{-12,68},{8,88}})));
  Modelica.Blocks.Interfaces.RealOutput y
    annotation (Placement(transformation(extent={{100,30},{120,50}})));
  Modelica.Blocks.Interfaces.RealOutput y1
    annotation (Placement(transformation(extent={{100,-50},{120,-30}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder3(
    T=0.2,
    y_start=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={40,-40})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder4(
    T=0.2,
    y_start=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={80,40})));
equation
  connect(ramp5.y,add2. u2) annotation (Line(points={{-19,-64},{-12,-64},{
          -12,-46},{-4,-46}}, color={0,0,127}));
  connect(cosine.y, product.u1) annotation (Line(points={{-23,52},{-18,52},
          {-18,40},{-14,40}}, color={0,0,127}));
  connect(ramp4.y, product.u2) annotation (Line(points={{-21,10},{-18,10},{
          -18,28},{-14,28}}, color={0,0,127}));
  connect(product.y, add2.u1) annotation (Line(points={{9,34},{14,34},{14,
          -12},{-18,-12},{-18,-34},{-4,-34}}, color={0,0,127}));
  connect(sine.y, firstOrder4.u) annotation (Line(points={{9,78},{56,78},{
          56,40},{68,40}}, color={0,0,127}));
  connect(firstOrder4.y, y)
    annotation (Line(points={{91,40},{110,40}}, color={0,0,127}));
  connect(add2.y, firstOrder3.u)
    annotation (Line(points={{19,-40},{28,-40}}, color={0,0,127}));
  connect(firstOrder3.y, y1) annotation (Line(points={{51,-40},{110,-40}},
                           color={0,0,127}));
  annotation (Icon(graphics={
Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
        Ellipse(extent={{-56,56},{54,-42}}, lineColor={28,108,200}),
        Line(
          points={{34,52},{50,40},{58,30},{64,16},{64,0},{60,-12},{56,-20},
              {50,-26},{44,-32},{38,-34}},
          color={0,0,0},
          thickness=1,
          smooth=Smooth.Bezier,
          arrow={Arrow.Filled,Arrow.None})}), Documentation(info="<html>
<p>This applies a circular path along two axises.</p>
</html>"));
end circlePath;
