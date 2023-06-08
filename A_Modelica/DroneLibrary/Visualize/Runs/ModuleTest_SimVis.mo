within DroneLibrary.Visualize.Runs;
model ModuleTest_SimVis
  DroneForVR
    controlModuleTest_fmu_inputs1
    annotation (Placement(transformation(extent={{12,-10},{32,10}})));

  inner Modelica.Mechanics.MultiBody.World world(n = {0,-1,0})
    annotation (Placement(transformation(extent={{-72,-46},{-52,-26}})));
  inner Visualize.UpdateVisualization updateVisualization(displayMultiBodyStructure=false) annotation (Placement(transformation(extent={{16,24},{36,44}})));
  Visualize.Shapes.FileShape shape(
    rotationType=Visualize.Internal.Types.RotationTypes.RotationAxis,
    axis={1,0,0},
    angle=-90,
    filename=Modelica.Utilities.Files.loadResource("modelica://DroneLibrary/Resources/Images/1_DroneModel.stl"),
    scaleFactor={0.01,0.01,0.01},
    reflectsLight=true,
    overwriteColor=false,
    color={0,0,0}) annotation (Placement(transformation(extent={{38,-38},{58,-18}})));
  Visualize.Shapes.FileShape shape1(
    smoothNormals=true,
    r_shape={-50,-50,-2},
    shadowMask=Visualize.Shapes.Internal.Types.ShadowMask.NoShadows,
    filename=Visualize.Utilities.RootDir + "/Extras/3DData/Terrain1/Terrain1.obj") annotation (Placement(transformation(extent={{-42,-46},{-22,-26}})));
  Visualize.Lights.SpotLight light1 annotation (Placement(transformation(extent={{-12,22},{8,42}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed(r={500,500,500}, animation=true)
    annotation (Placement(transformation(extent={{-36,22},{-16,42}})));
  Visualize.Effects.SkyBox skyBox(
    skyboxMode=Visualize.Effects.Internal.Types.SkyboxMode.SkyboxAndEphemeris,
    year=0,
    month=0,
    day=0,
    hour=0,
    minute=0,
    latitude=0,
    longitude=0,
    filename=Visualize.Utilities.RootDir + "/Extras/Bitmaps/Skymap/skymap2/skymap2_negx.png") annotation (Placement(transformation(extent={{-72,20},{-52,40}})));

  Visualize.Cameras.FreeCamera camera1(windowMode=Visualize.Cameras.Internal.Types.WindowMode.Window, startDistanceToCenter={0,-3,0}) annotation (Placement(transformation(extent={{-2,-36},{18,-16}})));
  replaceable Inputs.Keyboard.KeyboardInputs_SimVis inputDevice_SimVis
   constrainedby Interfaces.InputDevice_SimVis
    annotation (Placement(transformation(extent={{-32,-10},{-12,10}})));
  Visualize.Cameras.FreeCamera camera2(windowMode=Visualize.Cameras.Internal.Types.WindowMode.OpenVR_seated, startDistanceToCenter={0,-3,0}) annotation (Placement(transformation(extent={{-2,-54},{18,-34}})));
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
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}),
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
