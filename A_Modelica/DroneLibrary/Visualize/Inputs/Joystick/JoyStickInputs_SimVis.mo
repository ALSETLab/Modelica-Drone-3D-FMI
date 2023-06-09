within DroneLibrary.Visualize.Inputs.Joystick;
model JoyStickInputs_SimVis
  extends DroneLibrary.Visualize.Interfaces.InputDevice_SimVis;
  Modelica_DeviceDrivers.Blocks.OperatingSystem.RealtimeSynchronize
                                      realtimeSynchronize
    annotation (Placement(transformation(extent={{-60,-10},{-40,10}})));
 Modelica.Blocks.Interfaces.RealOutput Y
   annotation (Placement(transformation(extent={{60,-10},{80,10}})));
 Modelica.Blocks.Interfaces.RealOutput Z
   annotation (Placement(transformation(extent={{60,-50},{80,-30}})));
 Modelica.Blocks.Interfaces.RealOutput X
   annotation (Placement(transformation(extent={{60,30},{80,50}})));
  Modelica_DeviceDrivers.Blocks.InputDevices.JoystickInput joystickInput
    annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
  DroneLibrary.Visualize.Inputs.Joystick.JoyStick_Conversion JoyStick_X(InputGain=-3) annotation (Placement(transformation(extent={{10,30},{30,50}})));
  DroneLibrary.Visualize.Inputs.Joystick.JoyStick_Conversion JoyStick_Y(InputGain=3) annotation (Placement(transformation(extent={{10,-10},{30,10}})));
  DroneLibrary.Visualize.Inputs.Joystick.JoyStick_Conversion JoyStick_Z(InputGain=1) annotation (Placement(transformation(extent={{10,-50},{30,-30}})));
equation
  connect(JoyStick_X.Output, X)
    annotation (Line(points={{32.5,40},{70,40}}, color={0,0,127}));
  connect(JoyStick_Y.Output, Y)
    annotation (Line(points={{32.5,0},{70,0}}, color={0,0,127}));
  connect(JoyStick_Z.Output, Z)
    annotation (Line(points={{32.5,-40},{70,-40}}, color={0,0,127}));
  connect(joystickInput.axes[1], JoyStick_X.JoyStickInput) annotation (Line(
        points={{-9,5.58333},{0,5.58333},{0,40},{7.5,40}},
                                                         color={0,0,127}));
  connect(joystickInput.axes[2], JoyStick_Y.JoyStickInput)
    annotation (Line(points={{-9,5.75},{0,5.75},{0,0},{7.5,0}},
                                                            color={0,0,127}));
 connect(joystickInput.axes[3], JoyStick_Z.JoyStickInput)
   annotation (Line(points={{-9,5.91667},{0,5.91667},{0,-40},{7.5,-40}},
       color={0,0,127}));
 annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-60,
           -60},{60,60}}), graphics={ Bitmap(extent={{-74,-58},{76,60}},
            fileName="modelica://Modelica_DeviceDrivers/Resources/Images/Icons/joystick.png")}),
                                                                Diagram(
       coordinateSystem(preserveAspectRatio=false, extent={{-60,-60},{60,
           60}})),
    experiment(
      StopTime=100,
      __Dymola_fixedstepsize=0.001,
      __Dymola_Algorithm="Euler"),
    __Dymola_experimentFlags(Advanced(
        InlineMethod=1,
        InlineOrder=2,
        InlineFixedStep=0.001)));
end JoyStickInputs_SimVis;
