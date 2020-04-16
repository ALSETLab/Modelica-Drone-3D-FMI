within DroneSimulation.Examples.DroneWithoutIdealPower;
model controlModuleTest_fmu_main
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5);
  Modelica.Blocks.Sources.Ramp ramp1(
    duration=5,
    height=5,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=0.25)
    annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=-0.5,
    y_max=0.5)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-18},{-38,-8}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-14,-76},{-4,-66}})));
  DroneTest_FMU_Constant_Voltage
                         drone(V=12.1, animation=false)
    annotation (Placement(transformation(extent={{-2,-60},{88,50}})));
equation


  connect(ramp1.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},{
          -49,-10}},
                 color={0,0,127}));
  connect(add.u2,uniformNoise. y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(drone.ycoord, const.y) annotation (Line(points={{-11,-5},{-36,-5},{
          -36,28},{-45,28}},
                         color={0,0,127}));
  connect(drone.xcoord, const.y) annotation (Line(points={{-11,39},{-24,39},{
          -24,28},{-45,28}}, color={0,0,127}));
  connect(add.y, drone.zcoord) annotation (Line(points={{-37.5,-13},{-37.5,
          -32.5},{-11,-32.5},{-11,-49}}, color={0,0,127}));
  annotation (experiment(StopTime=10), __Dymola_Commands(executeCall(
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
        thicknesses={1.0,1.0,1.0})}));
end controlModuleTest_fmu_main;
