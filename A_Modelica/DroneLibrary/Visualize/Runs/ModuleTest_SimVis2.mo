within DroneLibrary.Visualize.Runs;
model ModuleTest_SimVis2
  inner Modelica.Mechanics.MultiBody.World world(n = {0,-1,0})
    annotation (Placement(transformation(extent={{-72,-60},{-52,-40}})));
  inner Visualize.UpdateVisualization updateVisualization(displayMultiBodyStructure=false) annotation (Placement(transformation(extent={{60,42},{80,62}})));
  Visualize.Shapes.FileShape shape1(
    smoothNormals=true,
    r_shape={-50,-50,-2},
    shadowMask=Visualize.Shapes.Internal.Types.ShadowMask.NoShadows,
    filename=Visualize.Utilities.RootDir + "/Extras/3DData/Terrain1/Terrain1.obj") annotation (Placement(transformation(extent={{-42,-60},{-22,-40}})));
  Visualize.Lights.SpotLight light1 annotation (Placement(transformation(extent={{-14,40},{6,60}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed(r={500,500,500}, animation=true)
    annotation (Placement(transformation(extent={{-38,40},{-18,60}})));
  Visualize.Effects.SkyBox skyBox(
    skyboxMode=Visualize.Effects.Internal.Types.SkyboxMode.SkyboxAndEphemeris,
    year=0,
    month=0,
    day=0,
    hour=0,
    minute=0,
    latitude=0,
    longitude=0,
    filename=Visualize.Utilities.RootDir + "/Extras/Bitmaps/Skymap/skymap2/skymap2_negx.png") annotation (Placement(transformation(extent={{-76,38},{-56,58}})));

  Visualize.Cameras.FreeCamera camera1(windowMode=Visualize.Cameras.Internal.Types.WindowMode.Window, startDistanceToCenter={0,-3,0}) annotation (Placement(transformation(extent={{-2,-36},{18,-16}})));
  replaceable Inputs.Keyboard.KeyboardInputs_SimVis inputDevice_SimVis
   constrainedby Interfaces.InputDevice_SimVis
    annotation (Placement(transformation(extent={{-28,8},{-8,28}})));
  Visualize.Cameras.FreeCamera camera2(windowMode=Visualize.Cameras.Internal.Types.WindowMode.OpenVR_seated, startDistanceToCenter={0,-3,0}) annotation (Placement(transformation(extent={{-2,-52},{18,-32}})));
  Examples.DroneWithIdealPower.Drone_Visualize droneTest_FMU_VISUALIZATON annotation (Placement(transformation(extent={{42,-8},{62,12}})));
  Modelica.Blocks.Sources.Constant const(k=0)
    annotation (Placement(transformation(extent={{4,0},{24,20}})));
equation
  connect(world.frame_b, shape1.frame_a) annotation (Line(
      points={{-52,-50},{-42,-50}},
      color={95,95,95},
      thickness=0.5));
  connect(fixed.frame_b,light1. frame_a) annotation (Line(
      points={{-18,50},{-14,50}},
      color={95,95,95},
      thickness=0.5,
      smooth=Smooth.None));
  connect(camera1.frame_b, droneTest_FMU_VISUALIZATON.frame_a1) annotation (
      Line(
      points={{18,-26},{60,-26},{60,-8.2},{59,-8.2}},
      color={95,95,95},
      thickness=0.5));
  connect(camera2.frame_b, droneTest_FMU_VISUALIZATON.frame_a1) annotation (
      Line(
      points={{18,-42},{60,-42},{60,-8.2},{59,-8.2}},
      color={95,95,95},
      thickness=0.5));
  connect(droneTest_FMU_VISUALIZATON.xcoord, const.y)
    annotation (Line(points={{40,10},{25,10}}, color={0,0,127}));
  connect(droneTest_FMU_VISUALIZATON.ycoord, const.y)
    annotation (Line(points={{40,2},{32,2},{32,10},{25,10}}, color={0,0,127}));
  connect(droneTest_FMU_VISUALIZATON.zcoord, const.y) annotation (Line(points={
          {40,-6},{32,-6},{32,10},{25,10}}, color={0,0,127}));
  annotation (Icon( graphics={
                            Bitmap(
          extent={{-98,-98},{98,98}}, fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}),
          experiment(
      StopTime=50,
      __Dymola_fixedstepsize=0.01,
      __Dymola_Algorithm="Euler"),
    __Dymola_experimentFlags(Advanced(
        InlineMethod=1,
        InlineOrder=2,
        InlineFixedStep=0.01)));
end ModuleTest_SimVis2;
