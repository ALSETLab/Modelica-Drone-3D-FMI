within DroneSimulation.Examples.DroneWithIdealPower;
model TestSystem
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-36,-36},{-26,-26}})));
  Drone_IdealMachine_ContinuousPID drone
    annotation (Placement(transformation(extent={{-24,0},{-4,20}})));
  Modelica.Blocks.Sources.Step     step1(startTime=0.1)
    annotation (Placement(transformation(extent={{-80,0},{-60,20}})));
  dronecriteria dronecriteria1
    annotation (Placement(transformation(extent={{20,20},{40,40}})));
  dronecriteria dronecriteria2
    annotation (Placement(transformation(extent={{20,0},{40,20}})));
  dronecriteria dronecriteria3
    annotation (Placement(transformation(extent={{20,-20},{40,0}})));
equation
  connect(drone.ycoord, step1.y) annotation (Line(points={{-26,10},{-59,10}},
                         color={0,0,127}));
  connect(step1.y, drone.xcoord) annotation (Line(points={{-59,10},{-32,10},{
          -32,18},{-26,18}}, color={0,0,127}));
  connect(step1.y, drone.zcoord) annotation (Line(points={{-59,10},{-32,10},{
          -32,2},{-26,2}}, color={0,0,127}));
  connect(drone.xgps, dronecriteria1.ugps) annotation (Line(points={{-3,18},{10,
          18},{10,34},{18,34}}, color={0,0,127}));
  connect(drone.ygps, dronecriteria2.ugps) annotation (Line(points={{-3,10},{10,
          10},{10,14},{18,14}}, color={0,0,127}));
  connect(drone.zgps, dronecriteria3.ugps)
    annotation (Line(points={{-3,2},{10,2},{10,-6},{18,-6}}, color={0,0,127}));
  connect(step1.y, dronecriteria3.ucoord) annotation (Line(points={{-59,10},{
          -32,10},{-32,-14},{18.2,-14}}, color={0,0,127}));
  connect(step1.y, dronecriteria2.ucoord) annotation (Line(points={{-59,10},{
          -32,10},{-32,-14},{12,-14},{12,6},{18.2,6}}, color={0,0,127}));
  connect(step1.y, dronecriteria1.ucoord) annotation (Line(points={{-59,10},{
          -32,10},{-32,-14},{12,-14},{12,26},{18.2,26}}, color={0,0,127}));
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
