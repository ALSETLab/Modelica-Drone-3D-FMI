within DroneSimulation.Examples.DroneWithIdealPower;
model DroneTest
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5,
    startTime=30)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  DroneTest_FMU                       droneTest_FMU_DCmotor
    annotation (Placement(transformation(extent={{-18,-16},{32,34}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=-0.5,
    y_max=0.5)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-18},{-38,-8}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-36,-36},{-26,-26}})));
equation
  connect(const.y, droneTest_FMU_DCmotor.xcoord) annotation (Line(points={{-45,
          28},{-28,28},{-28,29},{-23,29}}, color={0,0,127}));
  connect(droneTest_FMU_DCmotor.ycoord, droneTest_FMU_DCmotor.xcoord)
    annotation (Line(points={{-23,9},{-36,9},{-36,28},{-28,28},{-28,29},{-23,29}},
        color={0,0,127}));
  connect(ramp.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},
          {-49,-10}}, color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(droneTest_FMU_DCmotor.zcoord, add.u1) annotation (Line(points={{-23,-11},
          {-54,0},{-54,-10},{-49,-10}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -40},{40,60}})), Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-80,-40},{40,60}})),
    experiment(StopTime=40));
end DroneTest;
