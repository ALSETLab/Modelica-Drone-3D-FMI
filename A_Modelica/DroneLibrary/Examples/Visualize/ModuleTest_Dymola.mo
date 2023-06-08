within DroneLibrary.Examples.Visualize;
model ModuleTest_Dymola "Enables the use of keyboard input, see \"HowToRun\" information in this package."
  extends Modelica.Icons.Example;
  DroneForVR controlModuleTest_fmu_inputs1 annotation (Placement(transformation(extent={{20,-16},{48,12}})));
  DroneLibrary.Visualize.Inputs.Keyboard.KeyboardInputs_Dymola             keyboardInputs_Dymola annotation (Placement(transformation(extent={{-46,-22},{-6,18}})));
equation
  connect(keyboardInputs_Dymola.X, controlModuleTest_fmu_inputs1.xcoord) annotation (Line(points={{-4,8},{-2,9.2},{17.2,9.2}}, color={0,0,127}));
  connect(keyboardInputs_Dymola.Y, controlModuleTest_fmu_inputs1.ycoord) annotation (Line(points={{-4,-2},{17.2,-2}}, color={0,0,127}));
  connect(keyboardInputs_Dymola.Z, controlModuleTest_fmu_inputs1.zcoord) annotation (Line(points={{-4,-12},{6,-12},{6,-13.2},{17.2,-13.2}}, color={0,0,127}));
  annotation (experiment(StopTime=360));
end ModuleTest_Dymola;
