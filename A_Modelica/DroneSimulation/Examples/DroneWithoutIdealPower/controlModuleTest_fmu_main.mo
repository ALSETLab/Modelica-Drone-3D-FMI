within DroneSimulation.Examples.DroneWithoutIdealPower;
model controlModuleTest_fmu_main
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=0,
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=-0.5,
    y_max=0.5)
    annotation (Placement(transformation(extent={{-80,-42},{-60,-22}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-50,-16},{-40,-6}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{-36,-36},{-26,-26}})));
  DroneTest_FMU_Constant_Voltage            droneTest_FMU_Constant_Voltage(V=12.1)
    annotation (Placement(transformation(extent={{-18,-8},{40,48}})));
equation
  connect(ramp.y, add.u1) annotation (Line(points={{-59,0},{-56,0},{-56,-8},{
          -51,-8}},   color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-51,-14},{-51,-32},
          {-59,-32}},      color={0,0,127}));
  connect(droneTest_FMU_Constant_Voltage.xcoord, const.y) annotation (Line(
        points={{-23.8,42.4},{-34.8,42.4},{-34.8,28},{-45,28}}, color={0,0,127}));
  connect(droneTest_FMU_Constant_Voltage.ycoord, const.y) annotation (Line(
        points={{-23.8,20},{-34,20},{-34,28},{-45,28}}, color={0,0,127}));
  connect(droneTest_FMU_Constant_Voltage.zcoord, ramp.y) annotation (Line(
        points={{-23.8,-2.4},{-40.6364,-2.4},{-40.6364,0},{-59,0}}, color={0,0,
          127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -40},{40,60}})), Diagram(coordinateSystem(preserveAspectRatio=
            false, extent={{-80,-40},{40,60}})),
    experiment(
      StopTime=10,
      __Dymola_NumberOfIntervals=5000,
      Tolerance=0.01),
    __Dymola_Commands(executeCall(ensureSimulated=true) = {createPlot(
        id=1,
        position={338,6,507,816},
        y={"droneTest_FMU_Battery.xgps","droneTest_FMU_Constant_Voltage.xgps"},
        range={0.0,10.0,-0.6000000000000001,0.8},
        grid=true,
        legends={"X Position - Battery","X Position - Ideal"},
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47}},
        patterns={LinePattern.Solid,LinePattern.Dash},
        thicknesses={1.0,1.0}),createPlot(
        id=1,
        position={338,6,507,268},
        y={"droneTest_FMU_Battery.zgps","droneTest_FMU_Constant_Voltage.zgps"},
        range={0.0,10.0,-2.0,6.0},
        grid=true,
        legends={"Z Position - Battery","Z Position - Ideal"},
        subPlot=3,
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47}},
        patterns={LinePattern.Solid,LinePattern.Dash},
        thicknesses={1.0,1.0}),createPlot(
        id=1,
        position={338,6,507,268},
        y={"droneTest_FMU_Battery.ygps","droneTest_FMU_Constant_Voltage.ygps"},
        range={0.0,10.0,-1.5,1.5},
        grid=true,
        legends={"Y Position - Battery","Y Position - Ideal"},
        subPlot=2,
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47}},
        patterns={LinePattern.Solid,LinePattern.Dash},
        thicknesses={1.0,1.0}),createPlot(
        id=2,
        position={0,856,601,414},
        y={
          "droneTest_FMU_Constant_Voltage.propeller_DCMachine_Power.blades.Input.f[3]"},
        range={0.0,10.0,0.02,0.22},
        autoscale=false,
        grid=true,
        legends={"Motor with Losses"},
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{238,46,47}},
        patterns={LinePattern.Dash},
        thicknesses={1.0},
        range2={0.275,0.325}),createPlot(
        id=3,
        position={160,856,595,414},
        y=fill("", 0),
        range={0.0,1.0,0.0,1.0},
        grid=true,
        leftTitleType=2,
        leftTitle="Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)"),createPlot(
        id=4,
        position={320,856,593,771},
        y={"droneTest_FMU_Battery.battery.SOC"},
        range={0.0,10.0,0.5994,0.6001000000000001},
        grid=true,
        legends={"State of Charge"},
        leftTitleType=2,
        leftTitle="State of Charge",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{238,46,47}},
        thicknesses={1.0}),createPlot(
        id=4,
        position={320,856,593,382},
        y={"droneTest_FMU_Battery.battery.pin_p.v"},
        range={0.0,10.0,12.401130000000004,12.401200000000003},
        grid=true,
        legends={"Battery Voltage"},
        subPlot=2,
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200}},
        thicknesses={1.0}),createPlot(
        id=5,
        position={480,856,584,414},
        y={"ramp.y","add.y","uniformNoise.y"},
        range={0.0,10.0,-1.0,6.0},
        grid=true,
        legends={"Ideal","Noise",""},
        leftTitleType=2,
        leftTitle="Input Position (m)",
        bottomTitleType=2,
        bottomTitle="Time (s)",
        colors={{28,108,200},{238,46,47},{238,46,47}},
        patterns={LinePattern.Solid,LinePattern.Dash,LinePattern.Solid},
        thicknesses={1.0,1.0,0.25})}));
end controlModuleTest_fmu_main;
