within DroneSimulation.Examples.DroneCollision;
model DroneTest_payload
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5)
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
  DroneTest_FMU_Constant_Voltage    drone(V=22.1, animation=false)
    annotation (Placement(transformation(extent={{-2,22},{18,42}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Sources.Constant const2[3](k={0,0,-9.81*3})
    annotation (Placement(transformation(extent={{-16,-16},{4,4}})));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force
    annotation (Placement(transformation(extent={{18,-12},{38,8}})));
equation
  connect(ramp.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},
          {-49,-10}}, color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(drone.ycoord, const1.y) annotation (Line(points={{-4,32},{-36,32},{
          -36,30},{-59,30}}, color={0,0,127}));
  connect(drone.xcoord, const.y) annotation (Line(points={{-4,40},{-24,40},{-24,
          46},{-35,46}},     color={0,0,127}));
  connect(drone.zcoord, ramp.y) annotation (Line(points={{-4,24},{-32,24},{-32,
          0},{-59,0}}, color={0,0,127}));
  connect(const2.y, force.force) annotation (Line(points={{5,-6},{10,-6},{10,-2},
          {16,-2}}, color={0,0,127}));
  connect(force.frame_b, drone.frame_a1) annotation (Line(
      points={{38,-2},{38,21.6},{15.2,21.6}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -40},{40,60}})), Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-80,-40},{40,60}})),
    experiment(StopTime=10, __Dymola_Algorithm="Dassl"),
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
end DroneTest_payload;
