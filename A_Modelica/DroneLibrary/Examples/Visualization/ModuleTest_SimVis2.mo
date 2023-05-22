within DroneLibrary.Examples.Visualization;
model ModuleTest_SimVis2
  inner Modelica.Mechanics.MultiBody.World world(n(displayUnit="1") = {0,-1,0})
    annotation (Placement(transformation(extent={{-72,-60},{-52,-40}})));
  inner Visualization.UpdateVisualization updateVisualization(
      displayMultiBodyStructure=false)
    annotation (Placement(transformation(extent={{60,42},{80,62}})));
  Visualization.Shapes.FileShape shape1(
    smoothNormals=true,
    r_shape={-50,-50,-2},
    shadowMask=Visualization.Shapes.Internal.Types.ShadowMask.NoShadows,
    filename=Visualization.Utilities.RootDir +
        "/Extras/3DData/Terrain1/Terrain1.obj")
    annotation (Placement(transformation(extent={{-42,-60},{-22,-40}})));
  Visualization.Lights.SpotLight light1
    annotation (Placement(transformation(extent={{-14,40},{6,60}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed fixed(r={500,500,500}, animation=true)
    annotation (Placement(transformation(extent={{-38,40},{-18,60}})));
  Visualization.Effects.SkyBox skyBox(
    skyboxMode=Visualization.Effects.Internal.Types.SkyboxMode.SkyboxAndEphemeris,
    year=0,
    month=0,
    day=0,
    hour=0,
    minute=0,
    latitude=0,
    longitude=0,
    filename=Visualization.Utilities.RootDir +
        "/Extras/Bitmaps/Skymap/skymap2/skymap2_negx.png")
    annotation (Placement(transformation(extent={{-76,38},{-56,58}})));

  Visualization.Cameras.FreeCamera camera1(windowMode=Visualization.Cameras.Internal.Types.WindowMode.Window,
      startDistanceToCenter={0,-3,0})
    annotation (Placement(transformation(extent={{-2,-36},{18,-16}})));
  replaceable DroneLibrary.Visualization.Inputs.Keyboard.KeyboardInputs_SimVis inputDevice_SimVis constrainedby DroneLibrary.Visualization.Interfaces.InputDevice_SimVis annotation (Placement(transformation(extent={{-32,-10},{-12,10}})));
  Visualization.Cameras.FreeCamera camera2(windowMode=Visualization.Cameras.Internal.Types.WindowMode.OpenVR_seated,
      startDistanceToCenter={0,-3,0})
    annotation (Placement(transformation(extent={{-2,-52},{18,-32}})));
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
  connect(inputDevice_SimVis.X, controlModuleTest_fmu_inputs1.xcoord)
    annotation (Line(points={{-11,5},{-0.16665,5},{-0.16665,8},{12,8}},
                   color={0,0,127}));
  connect(inputDevice_SimVis.Y, controlModuleTest_fmu_inputs1.ycoord)
    annotation (Line(points={{-11,0},{12,0}}, color={0,0,127}));
  connect(inputDevice_SimVis.Z, controlModuleTest_fmu_inputs1.zcoord)
    annotation (Line(points={{-11,-5},{-0.16665,-5},{-0.16665,-8},{12,
          -8}}, color={0,0,127}));
 connect(controlModuleTest_fmu_inputs1.frame_a1, camera1.frame_b) annotation (
     Line(
     points={{31,-10.2},{31,-26},{18,-26}},
     color={95,95,95},
     thickness=0.5));
  connect(camera2.frame_b, camera1.frame_b) annotation (Line(
      points={{18,-42},{24,-42},{24,-40},{30,-40},{30,-26},{18,-26}},
      color={95,95,95},
      thickness=0.5));
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
