within DroneLibrary.Examples.DroneWithoutIdealPower;
model TestSystem
  extends Modelica.Icons.Example;
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5);
  Modelica.Blocks.Sources.Ramp ramp1(
    duration=5,
    height=5,
    offset=0,
    startTime=0)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={-70,0})));
  Modelica.Blocks.Sources.Constant const(k=-0.25)
    annotation (Placement(transformation(extent={{-80,20},{-60,40}})));
  Modelica.Blocks.Math.Add add
    annotation (Placement(transformation(extent={{-48,-20},{-38,-10}})));
  Modelica.Blocks.Sources.Ramp ramp2(
    duration=5,
    height=0,
    startTime=20)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={-72,-72})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-80,60},{-60,80}})));
equation

public
  replaceable Drone_DCPM_ConstantVoltage drone(V=12.1, animation=true) constrainedby DroneWithoutIdealPower_Template annotation (Placement(transformation(extent={{-2,-38},{90,48}})));
equation
  connect(ramp1.y, add.u1) annotation (Line(points={{-59,0},{-54,0},{-54,-12},{
          -49,-12}},
                 color={0,0,127}));
  connect(add.u2, ramp2.y) annotation (Line(points={{-49,-18},{-54,-18},{-54,
          -72},{-61,-72}}, color={0,0,127}));
  connect(const1.y, drone.xcoord) annotation (Line(points={{-59,70},{-40,70},{
          -40,40},{-11.2,40},{-11.2,39.4}},
                                      color={0,0,127}));
  connect(const.y, drone.ycoord) annotation (Line(points={{-59,30},{-34.5,30},{
          -34.5,5},{-11.2,5}}, color={0,0,127}));
  connect(add.y, drone.zcoord) annotation (Line(points={{-37.5,-15},{-25.75,-15},
          {-25.75,-29.4},{-11.2,-29.4}}, color={0,0,127}));
  annotation (experiment(
      StopTime=30,
      Interval=0.006,
      Tolerance=0.001),
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
        thicknesses={1.0,1.0,1.0})} "PlotXYZposition"));
end TestSystem;
