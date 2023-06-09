within DroneLibrary.Examples.DroneWithIdealPower;
model TestSystem
  extends Modelica.Icons.Example;
  Modelica.Blocks.Sources.Ramp zcoord_ramp(
    duration=5,
    height=5,
    startTime=0) annotation (Placement(transformation(extent={{-10,-10},{10,10}}, origin={-68,-52})));
  Modelica.Blocks.Sources.Constant xcoord(k=0.25) annotation (Placement(transformation(extent={{-80,40},{-60,60}})));
  replaceable Drone_IdealMachine drone
    constrainedby DroneLibrary.Examples.Drone_Template
    annotation (Placement(transformation(extent={{-30,-28},{28,30}})));
  Modelica.Blocks.Sources.Constant ycoord(k=0)
    annotation (Placement(transformation(extent={{-80,-10},{-60,10}})));
equation
  connect(drone.ycoord,ycoord. y) annotation (Line(points={{-35.8,1},{-35.8,0},{-59,0}},
                         color={0,0,127}));
  connect(drone.xcoord, xcoord.y) annotation (Line(points={{-35.8,24.2},{-54,24.2},{-54,50},{-59,50}}, color={0,0,127}));
  connect(drone.zcoord, zcoord_ramp.y) annotation (Line(points={{-35.8,-22.2},{-52,-22.2},{-52,-52},{-57,-52}}, color={0,0,127}));
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
        thicknesses={1.0,1.0,1.0})} "PlotXYZposition"));
end TestSystem;
