within DroneSimulation.Examples.DroneWithoutIdealPower;
model TestSystem
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5);
  Modelica.Blocks.Sources.Ramp ramp1(
    duration=5,
    height=5,
    offset=0,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=-0.25)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-20},{-38,-10}})));

  replaceable Drone_DCPM_ConstantVoltage   drone(V=12.1, animation=true)
    constrainedby DroneSimulation.Examples.Drone_Template
    annotation (Placement(transformation(extent={{42,20},{62,40}})));

  Modelica.Blocks.Sources.Ramp ramp2(
    duration=5,
    height=0,
    startTime=20)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-72,-72})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-80,60},{-60,80}})));
equation

  connect(ramp1.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-12},{
          -49,-12}},
                 color={0,0,127}));
  connect(add.u2, ramp2.y) annotation (Line(points={{-49,-18},{-54,-18},{-54,
          -72},{-61,-72}}, color={0,0,127}));
  connect(const1.y, drone.xcoord) annotation (Line(points={{-59,70},{34,70},{34,
          38},{40,38}},               color={0,0,127}));
  connect(const.y, drone.ycoord) annotation (Line(points={{-59,30},{40,30}},
                               color={0,0,127}));
  connect(add.y, drone.zcoord) annotation (Line(points={{-37.5,-15},{34,-15},{
          34,22},{40,22}},               color={0,0,127}));
  annotation (experiment(
      StopTime=30,
      __Dymola_NumberOfIntervals=5000,
      Tolerance=0.001,
      __Dymola_Algorithm="Dassl"),     __Dymola_Commands(executeCall(
          ensureSimulated=true) = {createPlot(
        id=1,
        position={15,10,584,420},
        y={"drone.xgps","drone.ygps","drone.zgps"},
        range={0.0,10.0,-2.0,6.0},
        grid=true,
        legends={"X Position","Y Position","Z Position"},
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47},{0,140,72}},
        patterns={LinePattern.Solid,LinePattern.Dash,LinePattern.Dot},
        thicknesses={1.0,1.0,1.0})},
      file="PlotThrust.mos" "PlotThrust",
      file="PlotPowerConsumption.mos" "PlotPowerConsumption"));
end TestSystem;
