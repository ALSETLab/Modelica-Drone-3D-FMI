within DroneSimulation.Examples.DroneWithIdealPower;
model TestSystem
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=0.25)
    annotation (Placement(transformation(extent={{-56,38},{-36,58}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=0,
    y_max=0)
    annotation (Placement(transformation(extent={{-80,-40},{-60,-20}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-18},{-38,-8}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-36,-36},{-26,-26}})));
  replaceable Drone_IdealMachine                                    drone
    constrainedby DroneSimulation.Examples.Drone_Template
    annotation (Placement(transformation(extent={{-12,-2},{8,18}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-82,20},{-62,40}})));
equation
  connect(ramp.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-10},
          {-49,-10}}, color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-49,-16},{-49,
          -30},{-59,-30}}, color={0,0,127}));
  connect(drone.ycoord, const1.y) annotation (Line(points={{-14,8},{-36,8},{-36,
          30},{-61,30}},     color={0,0,127}));
  connect(drone.xcoord, const.y) annotation (Line(points={{-14,16},{-24,16},{
          -24,48},{-35,48}}, color={0,0,127}));
  connect(drone.zcoord, ramp.y) annotation (Line(points={{-14,0},{-59,0}},
                    color={0,0,127}));
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
end TestSystem;
