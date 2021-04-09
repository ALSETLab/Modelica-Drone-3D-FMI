within ;
model dronecriteria

  Optimization.Criteria.Control.Overshoot overshoot
    annotation (Placement(transformation(extent={{-20,40},{0,60}})));
  Optimization.Criteria.Control.RiseTime riseTime
    annotation (Placement(transformation(extent={{-20,-10},{0,10}})));
  Optimization.Criteria.Control.SettlingTime settlingTime
    annotation (Placement(transformation(extent={{-20,-58},{0,-38}})));
  Modelica.Blocks.Interfaces.RealInput ugps
    annotation (Placement(transformation(extent={{-140,20},{-100,60}})));
  Modelica.Blocks.Interfaces.RealInput ucoord
    annotation (Placement(transformation(extent={{-138,-60},{-98,-20}})));
  Modelica.Blocks.Math.Feedback feedback
    annotation (Placement(transformation(extent={{-76,-32},{-56,-52}})));
equation
  connect(ugps, riseTime.u) annotation (Line(points={{-120,40},{-30,40},{-30,0},
          {-22,0}}, color={0,0,127}));
  connect(ugps, overshoot.u) annotation (Line(points={{-120,40},{-30,40},{-30,
          50},{-22,50}}, color={0,0,127}));
  connect(ucoord, feedback.u1) annotation (Line(points={{-118,-40},{-80,-40},{
          -80,-42},{-74,-42}}, color={0,0,127}));
  connect(feedback.u2, ugps)
    annotation (Line(points={{-66,-34},{-66,40},{-120,40}}, color={0,0,127}));
  connect(feedback.y, settlingTime.u) annotation (Line(points={{-57,-42},{-30,
          -42},{-30,-48},{-22,-48}}, color={0,0,127}));
  annotation (uses(Optimization(version="2.2.5"), Modelica(version="4.0.0")));
end dronecriteria;
