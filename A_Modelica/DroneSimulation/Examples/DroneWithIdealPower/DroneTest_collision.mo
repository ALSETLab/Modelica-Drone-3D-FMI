within DroneSimulation.Examples.DroneWithIdealPower;
model DroneTest_collision
  import Visualization;
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=-0.25)
    annotation (Placement(transformation(extent={{-56,36},{-36,56}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=-0.5,
    y_max=0.5)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-18},{-38,-8}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-36,-36},{-26,-26}})));
  DroneTest_FMU_Synchronous_chassis drone
    annotation (Placement(transformation(extent={{-10,2},{10,22}})));
  Modelica.Blocks.Sources.Constant const1(k=-0.25)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Visualization.Shapes.CollisionDetector collisionDetector(
    visualize=true,
    visualizerRadius=0.01,
    maxDistance=1.5,
    minDistance=0.5)
    annotation (Placement(transformation(extent={{14,-30},{34,-10}})));
equation
  connect(ramp.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},
          {-49,-10}}, color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(drone.zcoord, add.u1) annotation (Line(points={{-12,4},{-34,4},{-34,0},
          {-54,0},{-54,-10},{-49,-10}}, color={0,0,127}));
  connect(drone.ycoord, const1.y) annotation (Line(points={{-12,12},{-36,12},{
          -36,30},{-59,30}}, color={0,0,127}));
  connect(drone.xcoord, const.y) annotation (Line(points={{-12,20},{-24,20},{
          -24,46},{-35,46}}, color={0,0,127}));
  connect(drone.frame_a1, collisionDetector.frame_a) annotation (Line(
      points={{7,1.8},{6,1.8},{6,-20},{14,-20}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -40},{40,60}})), Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-80,-40},{40,60}})),
    experiment(StopTime=10),
    __Dymola_Commands(executeCall(ensureSimulated=true) = {createPlot(
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
end DroneTest_collision;
