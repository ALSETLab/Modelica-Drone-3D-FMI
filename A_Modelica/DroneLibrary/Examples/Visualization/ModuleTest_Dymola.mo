within DroneLibrary.Examples.Visualization;
model ModuleTest_Dymola
  extends Modelica.Icons.Example;
 replaceable DroneLibrary.Visualization.Inputs.Keyboard.KeyboardInputs_SimVis inputDevice constrainedby
    Interfaces.InputDevice_Dymola                                                                                                     annotation (Placement(transformation(extent={{-28,-10},{-8,10}})));
  DroneWithIdealPower.Drone_IdealMachine_SynchronousPID
    controlModuleTest_fmu_inputs1
    annotation (Placement(transformation(extent={{12,-10},{32,10}})));
equation
 connect(inputDevice.X, controlModuleTest_fmu_inputs1.xcoord)
   annotation (Line(points={{-7,5},{-3.5,5},{-3.5,8},{10,8}},
                  color={0,0,127}));
 connect(inputDevice.Y, controlModuleTest_fmu_inputs1.ycoord)
   annotation (Line(points={{-7,0},{10,0}}, color={0,0,127}));
 connect(inputDevice.Z, controlModuleTest_fmu_inputs1.zcoord)
   annotation (Line(points={{-7,-5},{-4,-5},{-4,-8},{10,-8}},
                   color={0,0,127}));
  annotation (experiment(StopTime=360));
end ModuleTest_Dymola;
