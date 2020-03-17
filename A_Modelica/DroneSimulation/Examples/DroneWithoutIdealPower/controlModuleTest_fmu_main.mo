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
  DroneTest_FMU_Battery2 droneTest_FMU_Battery2_1(V=12.1)
    annotation (Placement(transformation(extent={{0,-60},{90,50}})));
equation


  connect(ramp1.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},{
          -49,-10}},
                 color={0,0,127}));
  connect(add.u2,uniformNoise. y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(droneTest_FMU_Battery2_1.ycoord, const.y) annotation (Line(points={{-9,0},{
          -36,0},{-36,28},{-45,28}},     color={0,0,127}));
  connect(droneTest_FMU_Battery2_1.xcoord, const.y) annotation (Line(points={{-9,40},
          {-24,40},{-24,28},{-45,28}},     color={0,0,127}));
  connect(droneTest_FMU_Battery2_1.zcoord, add.u1) annotation (Line(points={{-9,-40},
          {-32,-40},{-32,-2},{-54,-2},{-54,-10},{-49,-10}},      color={0,0,127}));
  annotation (experiment(StopTime=10));
end controlModuleTest_fmu_main;
