within DroneLibrary.Visualize.Runs;
model ModuleTest_Dymola
 replaceable Inputs.Joystick.JoyStickInputs_Dymola inputDevice
   constrainedby Interfaces.InputDevice_Dymola
   annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
Examples.DroneWithIdealPower.Drone_IdealMachine_SynchronousPID
  controlModuleTest_fmu_inputs1
  annotation (Placement(transformation(extent={{12,-10},{32,10}})));
equation
 connect(inputDevice.X, controlModuleTest_fmu_inputs1.xcoord)
   annotation (Line(points={{-8.33333,6.66667},{-3.5,6.66667},{-3.5,8},
         {10,8}}, color={0,0,127}));
 connect(inputDevice.Y, controlModuleTest_fmu_inputs1.ycoord)
   annotation (Line(points={{-8.33333,0},{10,0}}, color={0,0,127}));
 connect(inputDevice.Z, controlModuleTest_fmu_inputs1.zcoord)
   annotation (Line(points={{-8.33333,-6.66667},{-4,-6.66667},{-4,-8},
         {10,-8}}, color={0,0,127}));
 annotation (Icon(graphics={Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}));
end ModuleTest_Dymola;
