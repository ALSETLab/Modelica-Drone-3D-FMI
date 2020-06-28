within DroneSimulation.Examples.DroneWithoutIdealPower;
model controlModuleTest_fmu_main
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
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=-0.25,
    y_max=0.25)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-20},{-38,-10}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-14,-76},{-4,-66}})));
  DroneTest_FMU_Battery  drone(V=12.1, animation=true)
    annotation (Placement(transformation(extent={{-2,-58},{88,52}})));
  Modelica.Blocks.Sources.Ramp ramp2(
    duration=5,
    height=0,
    startTime=20)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-72,-72})));
  Modelica.Blocks.Math.Add add1
    annotation (Placement(transformation(extent={{-40,-52},{-30,-42}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-80,60},{-60,80}})));
equation


  connect(ramp1.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-12},{
          -49,-12}},
                 color={0,0,127}));
  connect(add.u2, ramp2.y) annotation (Line(points={{-49,-18},{-54,-18},{-54,
          -72},{-61,-72}}, color={0,0,127}));
  connect(uniformNoise.y, add1.u2) annotation (Line(points={{-59,-30},{-50,-30},
          {-50,-50},{-41,-50}}, color={0,0,127}));
  connect(add.y, add1.u1) annotation (Line(points={{-37.5,-15},{-34,-15},{-34,
          -36},{-44,-36},{-44,-44},{-41,-44}}, color={0,0,127}));
  connect(const.y, drone.ycoord) annotation (Line(points={{-59,30},{-24,30},{
          -24,-2},{-12,-2},{-12,-3},{-11,-3}}, color={0,0,127}));
  connect(const1.y, drone.xcoord) annotation (Line(points={{-59,70},{-40,70},{
          -40,40},{-11,40},{-11,41}}, color={0,0,127}));
  connect(drone.zcoord, add1.u1) annotation (Line(points={{-11,-47},{-34,-16},{
          -34,-36},{-44,-36},{-44,-44},{-41,-44}}, color={0,0,127}));
  annotation (experiment(StopTime=10, Tolerance=0.001),
                                       __Dymola_Commands(executeCall(
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
end controlModuleTest_fmu_main;
