within DroneSimulation.Visualization;
package Runs
 model ModuleTest_SimVis
  import Visualization;
   DroneForVR
     controlModuleTest_fmu_inputs1
     annotation (Placement(transformation(extent={{12,-10},{32,10}})));

   inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,-1,0})
     annotation (Placement(transformation(extent={{-72,-46},{-52,-26}})));
   inner Visualization.UpdateVisualization updateVisualization(
       displayMultiBodyStructure=false) annotation (Placement(
         transformation(extent={{16,24},{36,44}})));
   Visualization.Shapes.FileShape shape(
     rotationType=Visualization.Internal.Types.RotationTypes.RotationAxis,
     axis(displayUnit="1") = {1,0,0},
     angle=-90,
    filename=Modelica.Utilities.Files.loadResource(
        "modelica://DroneSimulation/Resources/Images/1_DroneModel.stl"),
     scaleFactor={0.01,0.01,0.01},
     reflectsLight=true,
     overwriteColor=false,
     color={0,0,0})
     annotation (Placement(transformation(extent={{38,-38},{58,-18}})));
   Visualization.Shapes.FileShape shape1(
     smoothNormals=true,
     r_shape={-50,-50,-2},
     shadowMask=Visualization.Shapes.Internal.Types.ShadowMask.NoShadows,
     filename=Visualization.Utilities.RootDir + "/Extras/3DData/Terrain1/Terrain1.obj")
     annotation (Placement(transformation(extent={{-42,-46},{-22,-26}})));
   Visualization.Lights.SpotLight light1
     annotation (Placement(transformation(extent={{-12,22},{8,42}})));
   Modelica.Mechanics.MultiBody.Parts.Fixed fixed(r={500,500,500}, animation=true)
     annotation (Placement(transformation(extent={{-36,22},{-16,42}})));
   Visualization.Effects.SkyBox skyBox(
     skyboxMode=Visualization.Effects.Internal.Types.SkyboxMode.SkyboxAndEphemeris,
     year=0,
     month=0,
     day=0,
     hour=0,
     minute=0,
     latitude=0,
     longitude=0,
     filename=Visualization.Utilities.RootDir + "/Extras/Bitmaps/Skymap/skymap2/skymap2_negx.png")
     annotation (Placement(transformation(extent={{-72,20},{-52,40}})));

   Visualization.Cameras.FreeCamera camera1(windowMode=Visualization.Cameras.Internal.Types.WindowMode.Window,
       startDistanceToCenter={0,-3,0})
     annotation (Placement(transformation(extent={{-2,-36},{18,-16}})));
   replaceable Inputs.Keyboard.KeyboardInputs_SimVis inputDevice_SimVis
    constrainedby Interfaces.InputDevice_SimVis
     annotation (Placement(transformation(extent={{-32,-10},{-12,10}})));
   Visualization.Cameras.FreeCamera camera2(windowMode=Visualization.Cameras.Internal.Types.WindowMode.OpenVR_seated,
      startDistanceToCenter={0,-3,0})
     annotation (Placement(transformation(extent={{-2,-54},{18,-34}})));
 equation
   connect(world.frame_b, shape1.frame_a) annotation (Line(
       points={{-52,-36},{-42,-36}},
       color={95,95,95},
       thickness=0.5));
   connect(fixed.frame_b,light1. frame_a) annotation (Line(
       points={{-16,32},{-12,32}},
       color={95,95,95},
       thickness=0.5,
       smooth=Smooth.None));
   connect(shape.frame_a, camera1.frame_b) annotation (Line(
       points={{38,-28},{28,-28},{28,-26},{18,-26}},
       color={95,95,95},
       thickness=0.5));
   connect(inputDevice_SimVis.X, controlModuleTest_fmu_inputs1.xcoord)
     annotation (Line(points={{-11,5},{-0.16665,5},{-0.16665,8},{10,8}},
                    color={0,0,127}));
   connect(inputDevice_SimVis.Y, controlModuleTest_fmu_inputs1.ycoord)
     annotation (Line(points={{-11,0},{10,0}}, color={0,0,127}));
   connect(inputDevice_SimVis.Z, controlModuleTest_fmu_inputs1.zcoord)
     annotation (Line(points={{-11,-5},{-0.16665,-5},{-0.16665,-8},{10,-8}},
                     color={0,0,127}));
  connect(camera2.frame_b, camera1.frame_b) annotation (Line(
      points={{18,-44},{28,-44},{28,-26},{18,-26}},
      color={95,95,95},
      thickness=0.5));
  connect(controlModuleTest_fmu_inputs1.frame_a, camera1.frame_b) annotation (
      Line(
      points={{29,-10},{28,-10},{28,-26},{18,-26}},
      color={95,95,95},
      thickness=0.5));
   annotation (Icon(graphics={
                             Bitmap(
           extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/dronepic.jpg")}),
                              Diagram(coordinateSystem(preserveAspectRatio=
             false, extent={{-100,-80},{100,80}})),
     experiment(
       StopTime=50,
       __Dymola_fixedstepsize=0.01,
       __Dymola_Algorithm="Euler"),
     __Dymola_experimentFlags(Advanced(
         InlineMethod=1,
         InlineOrder=2,
         InlineFixedStep=0.01)));
 end ModuleTest_SimVis;

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
            extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/dronepic.jpg")}));
  end ModuleTest_Dymola;

 model ModuleTest_NoInput
   Modelica.Blocks.Sources.Ramp ramp(
     height=2,
     duration=4,
     startTime=0)
     annotation (Placement(transformation(extent={{-66,18},{-46,38}})));
  Examples.DroneWithIdealPower.Drone_IdealMachine_SynchronousPID
    controlModuleTest_fmu_inputs1
    annotation (Placement(transformation(extent={{-18,-16},{32,34}})));
   Modelica.Blocks.Sources.Constant const1(k=0)
     annotation (Placement(transformation(extent={{-68,-22},{-46,0}})));
 equation
   connect(ramp.y, controlModuleTest_fmu_inputs1.xcoord) annotation (
       Line(points={{-45,28},{-28,28},{-28,29},{-23,29}}, color={0,0,127}));
   connect(controlModuleTest_fmu_inputs1.zcoord, const1.y) annotation (
       Line(points={{-23,-11},{-44.9,-11}}, color={0,0,
           127}));
   connect(ramp.y, controlModuleTest_fmu_inputs1.ycoord) annotation (
       Line(points={{-45,28},{-36,28},{-36,9},{-23,9}}, color={0,0,127}));
   annotation (Icon(graphics={
                             Bitmap(
           extent={{-98,-98},{98,98}}, fileName="modelica://DroneSimulation/Resources/Images/dronepic.jpg")}),
     experiment(
       StopTime=10,
       __Dymola_fixedstepsize=0.01,
       __Dymola_Algorithm="Euler"),
     __Dymola_experimentFlags(Advanced(
         InlineMethod=1,
         InlineOrder=2,
         InlineFixedStep=0.01)));
 end ModuleTest_NoInput;
end Runs;
