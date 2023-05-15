within DroneSimulation.Examples.Visualization;
model ModuleTest_NoInput
  Modelica.Blocks.Sources.Ramp     ramp(
    height=2,
    duration=4,
    startTime=0)
    annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  DroneWithIdealPower.Drone_IdealMachine_SynchronousPID
    controlModuleTest_fmu_inputs1
    annotation (Placement(transformation(extent={{-18,-16},{32,34}})));
  Modelica.Blocks.Sources.Constant const1(k=0)
    annotation (Placement(transformation(extent={{-68,-22},{-46,0}})));
equation
  connect(ramp.y, controlModuleTest_fmu_inputs1.xcoord) annotation (
      Line(points={{-45,28},{-28,28},{-28,29},{-23,29}}, color={0,0,127}));
  connect(controlModuleTest_fmu_inputs1.zcoord, const1.y) annotation (
      Line(points={{-23,-11},{-44.9,-11}},                   color={0,0,
          127}));
  connect(ramp.y, controlModuleTest_fmu_inputs1.ycoord) annotation (
      Line(points={{-45,28},{-36,28},{-36,9},{-23,9}}, color={0,0,127}));
  annotation (Icon(graphics={
                            Bitmap(extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/dronepic.jpg")}),
    experiment(
      StopTime=10,
      __Dymola_fixedstepsize=0.01,
      __Dymola_Algorithm="Euler"),
    __Dymola_experimentFlags(Advanced(
        InlineMethod=1,
        InlineOrder=2,
        InlineFixedStep=0.01)));
end ModuleTest_NoInput;
