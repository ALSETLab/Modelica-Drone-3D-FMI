within DroneSimulation.Visualization.Inputs;
package Joystick
  model JoyStick_Conversion
    Modelica.Blocks.Interfaces.RealOutput Output
      annotation (Placement(transformation(extent={{40,-10},{60,10}})));
    Modelica.Blocks.Continuous.Integrator integrator
      annotation (Placement(transformation(extent={{-14,-6},{-2,6}})));
    Modelica.Blocks.Math.Gain gain(k=InputGain)
      annotation (Placement(transformation(extent={{6,-4},{14,4}})));
    parameter Real InputGain "Gain value multiplied with input signal";
    Modelica.Blocks.Math.Gain gain1(k=-2)
      annotation (Placement(transformation(extent={{-28,-4},{-20,4}})));
   Modelica.Blocks.Interfaces.RealInput JoyStickInput annotation (
       Placement(transformation(extent={{-60,-10},{-40,10}})));
   Modelica.Blocks.Continuous.FirstOrder firstOrder(T=0.3)
     annotation (Placement(transformation(extent={{22,-6},{34,6}})));
  equation
   connect(gain.u, integrator.y)
     annotation (Line(points={{5.2,0},{-1.4,0}}, color={0,0,127}));
   connect(integrator.u, gain1.y)
     annotation (Line(points={{-15.2,0},{-19.6,0}}, color={0,0,127}));
   connect(JoyStickInput, gain1.u)
     annotation (Line(points={{-50,0},{-28.8,0}}, color={0,0,127}));
   connect(gain.y, firstOrder.u)
     annotation (Line(points={{14.4,0},{20.8,0}}, color={0,0,127}));
   connect(Output, firstOrder.y)
     annotation (Line(points={{50,0},{34.6,0}}, color={0,0,127}));
    annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-40,-40},
              {40,40}})), Diagram(coordinateSystem(preserveAspectRatio=false,
            extent={{-40,-40},{40,40}})));
  end JoyStick_Conversion;

  model JoyStickInputs_SimVis
    extends DroneSimulation.Visualization.Interfaces.InputDevice_SimVis;
    import DroneSimulation;
    Modelica_DeviceDrivers.Blocks.OperatingSystem.SynchronizeRealtime
                                        synchronizeRealtime
      annotation (Placement(transformation(extent={{-60,-10},{-40,10}})));
   Modelica.Blocks.Interfaces.RealOutput Y
     annotation (Placement(transformation(extent={{60,-10},{80,10}})));
   Modelica.Blocks.Interfaces.RealOutput Z
     annotation (Placement(transformation(extent={{60,-50},{80,-30}})));
   Modelica.Blocks.Interfaces.RealOutput X
     annotation (Placement(transformation(extent={{60,30},{80,50}})));
    Modelica_DeviceDrivers.Blocks.InputDevices.JoystickInput joystickInput
      annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
    DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
      JoyStick_X(InputGain=-3)
      annotation (Placement(transformation(extent={{10,30},{30,50}})));
    DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
      JoyStick_Y(InputGain=3)
      annotation (Placement(transformation(extent={{10,-10},{30,10}})));
    DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
      JoyStick_Z(InputGain=1)
      annotation (Placement(transformation(extent={{10,-50},{30,-30}})));
  equation
    connect(JoyStick_X.Output, X)
      annotation (Line(points={{32.5,40},{70,40}}, color={0,0,127}));
    connect(JoyStick_Y.Output, Y)
      annotation (Line(points={{32.5,0},{70,0}}, color={0,0,127}));
    connect(JoyStick_Z.Output, Z)
      annotation (Line(points={{32.5,-40},{70,-40}}, color={0,0,127}));
    connect(joystickInput.axes[1], JoyStick_X.JoyStickInput) annotation (Line(
          points={{-9,5.16667},{0,5.16667},{0,40},{7.5,40}},
                                                           color={0,0,127}));
    connect(joystickInput.axes[2], JoyStick_Y.JoyStickInput)
      annotation (Line(points={{-9,5.5},{0,5.5},{0,0},{7.5,0}},
                                                              color={0,0,127}));
   connect(joystickInput.axes[3], JoyStick_Z.JoyStickInput)
     annotation (Line(points={{-9,5.83333},{0,5.83333},{0,-40},{7.5,-40}},
         color={0,0,127}));
   annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-60,
             -60},{60,60}}), graphics={    Bitmap(extent={{-74,-58},{76,60}},
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

  model JoyStickInputs_Dymola
    extends
     DroneSimulation.Visualization.Interfaces.InputDevice_Dymola;
    import DroneSimulation;
    Modelica_DeviceDrivers.Blocks.OperatingSystem.SynchronizeRealtime
                                        synchronizeRealtime
      annotation (Placement(transformation(extent={{-60,-10},{-40,10}})));
   Modelica.Blocks.Interfaces.RealOutput Y
     annotation (Placement(transformation(extent={{60,-10},{80,10}})));
   Modelica.Blocks.Interfaces.RealOutput Z
     annotation (Placement(transformation(extent={{60,-50},{80,-30}})));
   Modelica.Blocks.Interfaces.RealOutput X
     annotation (Placement(transformation(extent={{60,30},{80,50}})));
    Modelica_DeviceDrivers.Blocks.InputDevices.JoystickInput joystickInput
      annotation (Placement(transformation(extent={{-30,-10},{-10,10}})));
   DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
     JoyStick_X(InputGain=XGain)
     annotation (Placement(transformation(extent={{10,30},{30,50}})));
   DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
     JoyStick_Y(InputGain=YGain)
     annotation (Placement(transformation(extent={{10,-10},{30,10}})));
   DroneSimulation.Visualization.Inputs.Joystick.JoyStick_Conversion
     JoyStick_Z(InputGain=ZGain) annotation (Placement(transformation(
           extent={{10,-50},{30,-30}})));
    parameter Real XGain=0.5 "Gain value multiplied with input signal";
    parameter Real YGain=0.5 "Gain value multiplied with input signal";
    parameter Real ZGain=1 "Gain value multiplied with input signal";
  equation
    connect(joystickInput.axes[3],JoyStick_Z.JoyStickInput)  annotation (Line(
          points={{-9,5.83333},{-2,5.83333},{-2,-40},{7.5,-40}},
                                                               color={0,0,127}));
    connect(JoyStick_X.Output, X)
      annotation (Line(points={{32.5,40},{70,40}}, color={0,0,127}));
    connect(JoyStick_Y.Output, Y)
      annotation (Line(points={{32.5,0},{70,0}}, color={0,0,127}));
    connect(JoyStick_Z.Output, Z)
      annotation (Line(points={{32.5,-40},{70,-40}}, color={0,0,127}));
   connect(joystickInput.axes[1], JoyStick_X.JoyStickInput)
     annotation (Line(points={{-9,5.16667},{0,5.16667},{0,40},{7.5,40}},
         color={0,0,127}));
   connect(joystickInput.axes[2], JoyStick_Y.JoyStickInput)
     annotation (Line(points={{-9,5.5},{0,5.5},{0,0},{7.5,0}},
                                                             color={0,
           0,127}));
   annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-60,
             -60},{60,60}}), graphics={    Bitmap(extent={{-74,-58},{
               76,60}},
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
  end JoyStickInputs_Dymola;
end Joystick;
