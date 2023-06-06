within DroneLibrary.Examples.DroneWithIdealPower;
model TestSystem
  extends Modelica.Icons.Example;
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={-70,-30})));
  Modelica.Blocks.Sources.Constant const(k=0.25)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Noise.UniformNoise uniformNoise(
    samplePeriod=0.1,
    y_min=0,
    y_max=0)
    annotation (Placement(transformation(extent={{-80,-70},{-60,-50}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-30,-60},{-10,-40}})));
   inner Modelica.Blocks.Noise.GlobalSeed globalSeed
     annotation (Placement(transformation(extent={{0,-60},{20,-40}})));
  replaceable Drone_IdealMachine drone
    constrainedby DroneLibrary.Examples.Drone_Template
    annotation (Placement(transformation(extent={{-10,-10},{10,10}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-80,-10},{-60,10}})));
equation
  connect(ramp.y, add.u1) annotation (Line(points={{-59,-30},{-40,-30},{-40,-44},{-32,-44}},
                      color={0,0,127}));
  connect(add.u2, uniformNoise.y) annotation (Line(points={{-32,-56},{-40,-56},{-40,-60},{-59,-60}},
                           color={0,0,127}));
  connect(drone.ycoord, const1.y) annotation (Line(points={{-12,0},{-59,0}},
                         color={0,0,127}));
  connect(drone.xcoord, const.y) annotation (Line(points={{-12,8},{-20,8},{-20,30},{-59,30}},
                             color={0,0,127}));
  connect(drone.zcoord, ramp.y) annotation (Line(points={{-12,-8},{-20,-8},{-20,-30},{-59,-30}},
                    color={0,0,127}));
  annotation (experiment(StopTime=10),
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
