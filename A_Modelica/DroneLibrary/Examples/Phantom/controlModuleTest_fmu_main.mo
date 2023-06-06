within DroneLibrary.Examples.Phantom;
model controlModuleTest_fmu_main
  extends Modelica.Icons.Example;
  Modelica.Blocks.Sources.Ramp ramp(duration=5, height=5)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        origin={-56,-8})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  DroneTest_FMU_Synchronous droneTest_FMU_Synchronous
    annotation (Placement(transformation(extent={{-18,-16},{32,34}})));
equation
  connect(const.y, droneTest_FMU_Synchronous.xcoord) annotation (Line(points={{
          -45,28},{-28,28},{-28,29},{-23,29}}, color={0,0,127}));
  connect(droneTest_FMU_Synchronous.ycoord, droneTest_FMU_Synchronous.xcoord)
    annotation (Line(points={{-23,9},{-36,9},{-36,28},{-28,28},{-28,29},{-23,29}},
        color={0,0,127}));
  connect(droneTest_FMU_Synchronous.zcoord, ramp.y) annotation (Line(points={{-23,-11},{-42,-11},{-42,-8},{-45,-8}}, color={0,0,127}));
  annotation (experiment(StopTime=10, Tolerance=0.01));
end controlModuleTest_fmu_main;
