within DroneSimulation.Gyroscope;
model GyroModel "Example of how gyroscopic precession works on a simple gyro."
  extends Modelica.Icons.Example;
  inner Modelica.Mechanics.MultiBody.World world(animateWorld = false, animateGravity = false) "world component" annotation(Placement(visible = true, transformation(origin = {-132.021, -80}, extent = {{-10, -10}, {10, 10}}, rotation = -720)));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder mount(r = {0, 0.002, 0}, color = {155, 155, 155}, diameter = 0.08, specularCoefficient = 1) "mount of the gyro" annotation(Placement(visible = true, transformation(origin = {-70, -80}, extent = {{-10, -10}, {10, 10}}, rotation = -720)));
  parameter Modelica.Units.SI.AngularVelocity spin=500
    "Angular velocity of inner rotor.";
  parameter Modelica.Units.SI.Force forceMagnitude=0.3
    "Magnitude of applied force.";
  Modelica.Mechanics.MultiBody.Visualizers.VoluminousWheel outerRing(rRim = 0.041, width = 0.005, color = {155, 155, 155}, specularCoefficient = 1, rTire = 0.045, rCurvature = 0.040) "outer ring of the gyro" annotation(Placement(visible = true, transformation(origin = {100.85, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation fixedTranslation(r = {0, 0.041, 0}, animation = false) "distance from the outer ring to the center of the gyro" annotation(Placement(visible = true, transformation(origin = {0, -40}, extent = {{-10, -10}, {10, 10}}, rotation = -270)));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation outerRinFixedgRotation(animation = false, angle = 90) "fixed rotation to line up the outer ring initially" annotation(Placement(visible = true, transformation(origin = {70, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Visualizers.VoluminousWheel innerRing(rRim = 0.036, rTire = 0.040, width = 0.005, color = {155, 155, 155}, specularCoefficient = 1, rCurvature = 0.035) "inner ring of the gyro" annotation(Placement(visible = true, transformation(origin = {100.85, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation innerRingFixedRotation(animation = false, angle = 90) "fixed rotation to line up the inner ring initially" annotation(Placement(visible = true, transformation(origin = {69.15, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation fixedTranslation1(r = {0, 0.005, 0}, animation = true, width = 0.003, color = {155, 155, 155}, specularCoefficient = 1) "distance from the mount to the outer ring" annotation(Placement(visible = true, transformation(origin = {0, -65}, extent = {{-10, -10}, {10, 10}}, rotation = -270)));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder rotor(diameter = 0.07, r = {0.0025, 0, 0}, r_shape = {-0.0025, 0, 0}, color = {100, 100, 100}, specularCoefficient = 1) "the rotor of the gyro" annotation(Placement(visible = true, transformation(origin = {100, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Parts.FixedRotation rotorFixedRotation(animation = false, angle = 90, n = {0, 1, 0}) "fixed rotation to line up the rotor initially" annotation(Placement(visible = true, transformation(origin = {70, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revoluteX(n = {1, 0, 0}, animation = false) "revolution around the x-axis" annotation(Placement(visible = true, transformation(origin = {0, 15}, extent = {{-10, -10}, {10, 10}}, rotation = -270)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revoluteZ(n = {0, 0, 1}, animation = false,
    w(                                                                                     start =   spin))
                                                                                                           "revolution around the Z-axis" annotation(Placement(visible = true, transformation(origin = {0, 45}, extent = {{-10, -10}, {10, 10}}, rotation = -270)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revoluteY(n = {0, 1, 0}, animation = false) "revolution around the Y-axis" annotation(Placement(visible = true, transformation(origin = {0, -15}, extent = {{-10, -10}, {10, 10}}, rotation = -270)));
  Modelica.Mechanics.MultiBody.Visualizers.FixedShape rotationIndicator(color = {255, 255, 0}, length = 0.002, width = 0.04, height = 0.002, specularCoefficient = 1) "indicator of the orientation of the rotor" annotation(Placement(visible = true, transformation(origin = {130, 85}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation rotationIndicatorOrientator(r = {-0.003, 0, 0}, animation = false) "placement for the indicator of the rotor orientation" annotation(Placement(visible = true, transformation(origin = {100, 85}, extent = {{-10, -10}, {10, 10}}, rotation = -360)));
  Modelica.Mechanics.MultiBody.Forces.WorldForce force1(resolveInFrame=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB.frame_b)
    "external force" annotation (Placement(visible=true, transformation(
        origin={70,-80},
        extent={{-10,-10},{10,10}},
        rotation=0)));
  Modelica.Blocks.Sources.Pulse pulse1[3](amplitude = {0, 0, -forceMagnitude}, period = 100, width = 3, startTime = 1, nperiod = 1) "signal to external force" annotation(Placement(visible = true, transformation(origin = {30, -80}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Mechanics.MultiBody.Visualizers.FixedShape baseOrientationIndicator(color = {0, 0, 200}, length = 0.002, width = 0.0012, height = 0.06, specularCoefficient = 1) "indicator of the orientation of the mount" annotation(Placement(visible = true, transformation(origin = {-70, -50}, extent = {{-10, -10}, {10, 10}}, rotation = -180)));
  parameter Modelica.Units.NonSI.Angle_deg degreeOfForce=45
    "Angle of applied force.";
  Modelica.Mechanics.MultiBody.Parts.FixedRotation forceOrientator(
    animation=false,
    angle=90,
    r={0.038*cos(Modelica.Units.Conversions.from_deg(degreeOfForce)),0.038*sin(
        Modelica.Units.Conversions.from_deg(degreeOfForce)),0},
    n={0,0,1}) "displacement showing where to put the external force"
    annotation (Placement(visible=true, transformation(
        origin={70,-25},
        extent={{-10,-10},{10,10}},
        rotation=0)));
equation
  connect(mount.frame_a, world.frame_b) annotation(Line(visible = true, origin = {-101.01, -80}, points = {{21.01, 0}, {-21.011, 0}}, color = {95, 95, 95}));
  connect(outerRinFixedgRotation.frame_b, outerRing.frame_a) annotation(Line(visible = true, origin = {85.425, 0}, points = {{-5.425, 0}, {5.425, 0}}, color = {95, 95, 95}));
  connect(innerRingFixedRotation.frame_b, innerRing.frame_a) annotation(Line(visible = true, origin = {85, 30}, points = {{-5.85, 0}, {5.85, 0}}, color = {95, 95, 95}));
  connect(fixedTranslation1.frame_b, fixedTranslation.frame_a) annotation(Line(visible = true, origin = {0, -52.5}, points = {{0, -2.5}, {0, 2.5}}, color = {95, 95, 95}));
  connect(fixedTranslation1.frame_a, mount.frame_b) annotation(Line(visible = true, origin = {-20, -78.333}, points = {{20, 3.333}, {20, -1.667}, {-40, -1.667}}, color = {95, 95, 95}));
  connect(rotor.frame_a, rotorFixedRotation.frame_b) annotation(Line(visible = true, origin = {85, 60}, points = {{5, 0}, {-5, 0}}, color = {95, 95, 95}));
  connect(revoluteX.frame_b, innerRingFixedRotation.frame_a) annotation(Line(visible = true, origin = {19.717, 28.333}, points = {{-19.717, -3.333}, {-19.717, 1.667}, {39.433, 1.667}}, color = {95, 95, 95}));
  connect(revoluteX.frame_b, revoluteZ.frame_a) annotation(Line(visible = true, origin = {0, 30}, points = {{0, -5}, {0, 5}}, color = {95, 95, 95}));
  connect(revoluteZ.frame_b, rotorFixedRotation.frame_a) annotation(Line(visible = true, origin = {20, 58.333}, points = {{-20, -3.333}, {-20, 1.667}, {40, 1.667}}, color = {95, 95, 95}));
  connect(fixedTranslation.frame_b, revoluteY.frame_a) annotation(Line(visible = true, origin = {0, -27.5}, points = {{0, -2.5}, {0, 2.5}}, color = {95, 95, 95}));
  connect(revoluteY.frame_b, revoluteX.frame_a) annotation(Line(visible = true, points = {{0, -5}, {0, 5}}, color = {95, 95, 95}));
  connect(revoluteY.frame_b, outerRinFixedgRotation.frame_a) annotation(Line(visible = true, origin = {20, -1.667}, points = {{-20, -3.333}, {-20, 1.667}, {40, 1.667}}, color = {95, 95, 95}));
  connect(rotationIndicatorOrientator.frame_a, rotor.frame_a) annotation(Line(visible = true, origin = {85.506, 72.5}, points = {{4.494, 12.5}, {-0.506, 12.5}, {-0.506, -12.5}, {4.494, -12.5}}, color = {95, 95, 95}));
  connect(rotationIndicatorOrientator.frame_b, rotationIndicator.frame_a) annotation(Line(visible = true, origin = {115, 85}, points = {{-5, 0}, {5, 0}}, color = {95, 95, 95}));
  connect(pulse1.y, force1.force) annotation(Line(visible = true, origin = {49.5, -80}, points = {{-8.5, 0}, {8.5, 0}}, color = {1, 37, 163}));
  connect(baseOrientationIndicator.frame_a, mount.frame_b) annotation(Line(visible = true, origin = {-41.613, -65}, points = {{-18.387, 15}, {1.613, 15}, {1.613, -15}, {-18.387, -15}}, color = {95, 95, 95}));
  connect(forceOrientator.frame_a, innerRingFixedRotation.frame_a) annotation(Line(visible = true, origin = {36.294, 2.5}, points = {{23.706, -27.5}, {-6.294, -27.5}, {-6.294, 27.5}, {22.856, 27.5}}, color = {95, 95, 95}));
  connect(forceOrientator.frame_b, force1.frame_b) annotation(Line(visible = true, origin = {93.5, -65}, points = {{-13.5, 40}, {6.5, 40}, {6.5, -15}, {-13.5, -15}}, color = {95, 95, 95}));
  annotation(experiment(StopTime = 10.0, __Wolfram_SynchronizeWithRealTime = false), preferredView = "diagram", __Wolfram(PlotSet(plots = {Plot(name = "RevolutionAngles", preferred = true, subPlots = {SubPlot(curves = {Curve(x = time, y = revoluteX.angle, legend = "Revolute X angle"), Curve(x = time, y = revoluteY.angle, legend = "Revolute Y angle")})}), Plot(name = "AppliedForce", subPlots = {SubPlot(curves = {Curve(x = time, y = force1.force[3], legend = "Applied Force")})})})), Documentation(info = "<html><!--WSMINSERTIONTAGSTART gyroModel -->
   <head>
   <style type=\"text/css\">
   
  body {
   padding: 0px;
   margin: 0px;
  }
  
  a {
   color: #cf1d24;
  }
  
  a.target {
   padding-top: 40px;
   margin-top: -40px;
  }
  
  p {
   font-family: arial;
   font-size: 13;
   margin: 9px 40px 5px 40px;
   padding-bottom: 0px;
   color: #555555;
   max-width: 800px;
  }
  
  h1 {
   font-size: 30;
   color: #cf1d24;
   font-weight: bold;
   margin-left: 20px;
   margin-top: 32px;
   margin-bottom: 15px;
   margin-right: 20px;
   padding-top: 0px;
  }
  
  h2 {
   font-size: 20;
   color: #cf1d24;
   font-weight: bold;
   margin-left: 20px;
   margin-right: 20px;
   margin-top: 5px;
   margin-bottom: 9px;
  }
  
  h3 {
   background: url('DocumentationFiles/dingbat3.png') no-repeat 0 0;
   font-size: 14px;
   font-family: helvetica;
   color: #4B4B4B;
   font-weight: bold;
   padding-left: 18px;
   margin-left: 20px;
   margin-right: 20px;
   margin-top: 12px;
   margin-bottom: 8px;
  }
  
  ul {
   font-family: arial;
   font-size: 13;
   margin: 9px 40px 5px 40px;
   padding-bottom: 0px;
   color: #555555;
   max-width: 800px;
   list-style-type: square;
  }
  
  li {
   margin-left: 0px;
   margin-top: 4px;
   margin-bottom: 2px;
   padding-left: 0px;
  }

  div.header {
   background: url('DocumentationFiles/WSMLogo.png') no-repeat 0 0;
   height: 96px;
   margin-top: 35px;
   background-color: #871613;
  }
  
  .headerspan {
   font-family: arial;
   text-decoration: none;
   font-size: 12px;
   font-weight: bold;
   display: inline-block;
   height: 35px;
   color: gray;
   padding: 0px;
   margin: 0px;
   margin-left: 20px;
  }
  
  .headera {
   font-family: arial;
   text-decoration: none;
   font-size: 12px;
   font-weight: bold;
   padding: 0px;
   color: inherit;
   vertical-align: middle;
   margin: 0px;
  }
  
  .headerlinkdiv {
   background: black;
   padding: 0px;
   height: 35px;
   margin: 0px;
   position: fixed; top: 0px; left: 0px; width: 100%;
  }
  
  .contenttable {
   -webkit-box-shadow: 3px 3px 3px #DDDDDD;
   border-top: 3px solid #cf1d24;
   background: #f9f9f9;
   max-width: 500px;
   margin: 15px 15px 0px 20px;
   padding: 6px 10px 3px 10px;
  }
  
  .contenttableheader {
   color: #a4a4a4;
   font-size: 14px;
   font-family: arial;
  }
  
  .contenttabletable {
   border: 0px solid #FFFFFF;
   padding: 0px;
   padding-left: 20px;
  }
  
  .contenttable tr td {
   padding: 3px;
   min-width: 200px;
  }
  
  .contenttable tr td a {
   color: #555555;
   text-decoration: none;
   font-size: 13px;
   font-family: arial;
  }
  
  .hacek {
   color: #cf1d24;
   font-size: 25px;
   font-weight: plain;
   vertical-align: -40%;
  }
  
  .mathematicapointerwrapper {
   border: 0px solid #DDDDDD;
   margin: 15px 15px 15px 40px;
   padding: 0px;
   max-width: 500px;
  }
  
  .mathematicapointertop {
   border: 1px solid #DDDDDD;
   background-color: #F2F2F2;
   padding: 0px;
   max-width: 500px;
   height: 4px;
  }
  
  .mathematicapointerdiv {
   background: url('./DocumentationFiles/mathematicabook.png') no-repeat  left center;
   border: 1px solid #DDDDDD;
   background-color: #FFFFFF;
   margin: 0px;
   padding: 15px 9px 9px 89px;
   max-width: 500px;
   min-height: 67px;
  }
  
  p.mathematicapointer {
   padding: 0px;
   margin: 0px;
   font-size: 12px;
  }
  
  .infoboxwrapper {
   border: 0px solid #DDDDDD;
   -webkit-box-shadow: 3px 3px 3px #DDDDDD;
   margin: 15px 15px 15px 40px;
   padding: 0px;
   max-width: 500px;
  }
  
  .infoboxtop {
   background: url('./DocumentationFiles/infotick.png') no-repeat left center;
   border: 1px solid #DDDDDD;
   background-color: #F2F2F2;
   padding: 0px;
   max-width: 500px;
   height: 37px;
  }
  
  div.infobox {
   border: 1px solid #DDDDDD;
   background-color: #FFFFFF;
   margin: 0px;
   padding: 15px;
   max-width: 500px;
  }
  
  p.infobox {
   padding: 0px;
   margin: 0px;
   font-size: 12px;
  }
  
  h2.legal {
   font-family: arial;
   font-size: 14;
   color: #cf1d24;
   margin: 15px 15px 15px 20px;
   font-weight: bold;
  }
  
  h3.legal {
   background: url('./DocumentationFiles/dingbat3.png') no-repeat 0 0;
   font-family: arial;
   font-size: 12;
   color: #808080;
   margin-left: 38px;
   padding-left: 12px;
   font-weight: bold;
  }
  
  ul.legal {
   font-size: 10px;
   font-family: arial;
   color: #555555;
   margin-left: 28px;
  }
  
  ul.legal li {
   margin-left: 0px;
   margin-top: 4px;
   margin-bottom: 2px;
   padding-left: 0px;
  }

  ul.imgbullets li {
   margin-left: -40px;
   margin-top: 4px;
   margin-bottom: 10px;
   padding-left: 30px;
   list-style-type: none;
  }
  
  p.legallarge {
   font-size: 12px;
   margin-left: 38px;
  }
  
  p.legalsmall {
   font-size: 11px;
   margin-left: 38px;
   padding-left: 12px;
  }
  
  .legalend {
   height: 10px;
  }
  
  .variablename {
   font-family: Courier New, Courier;
  }
  
  .dialogelement {
   font-weight: bold;
  }
  
  .menuitem {
   font-weight: bold;
  }
  
  .mr {
   font-family: Courier New, Courier;
  }
  
  .ttable {
        border-collapse: collapse;
    width: 100%;
        }

        .ttable td, th {
    border: 1px solid #dddddd;
    text-align: left;
        padding: 8px;
        }

        .ttable tr:nth-child(even) {
                background-color: #dddddd;
        }
  
   </style>
   </head>
   <body>
   
  <div class=\"headerlinkdiv\">
  
   <span class=\"headerspan\" style=\"background: url(DocumentationFiles/examples.png) no-repeat 0 0;
   padding-left: 24px;
   \"
   onmouseover=\"
           this.style.color = 'white';
           this.style.background = 'url(DocumentationFiles/examples_active.png) no-repeat 0 0';
   \"
   onmouseout=\"
           this.style.color = 'gray';
           this.style.background = 'url(DocumentationFiles/examples.png) no-repeat 0 0';
   \"><a href=\"https://www.wolfram.com/system-modeler/examples/\" class=\"headera\">More Examples</a></span>
  
   <span class=\"headerspan\" style=\"background: url(DocumentationFiles/video.png) no-repeat 0 0;
   padding-left: 29px;
   \"
   onmouseover=\"
           this.style.color = 'white';
           this.style.background = 'url(DocumentationFiles/video_active.png) no-repeat 0 0';
   \"
   onmouseout=\"
           this.style.color = 'gray';
           this.style.background = 'url(DocumentationFiles/video.png) no-repeat 0 0';
   \"><a href=\"http://www.wolfram.com/system-modeler/resources/get-started/\" class=\"headera\">Introductory Videos</a></span>
  
   <span class=\"headerspan\" style=\"background: url(DocumentationFiles/docs.png) no-repeat 0 0;
   padding-left: 20px;
   \"
   onmouseover=\"
           this.style.color = 'white';
           this.style.background = 'url(DocumentationFiles/docs_active.png) no-repeat 0 0';
   \"
   onmouseout=\"
           this.style.color = 'gray';
           this.style.background = 'url(DocumentationFiles/docs.png) no-repeat 0 0';
   \"><a href=\"http://reference.wolfram.com/system-modeler\" class=\"headera\">Documentation</a></span>
  
   <span class=\"headerspan\" style=\"background: url(DocumentationFiles/contact.png) no-repeat 0 0;
   padding-left: 24px;
   \"
   onmouseover=\"
           this.style.color = 'white';
           this.style.background = 'url(DocumentationFiles/contact_active.png) no-repeat 0 0';
   \"
   onmouseout=\"
           this.style.color = 'gray';
           this.style.background = 'url(DocumentationFiles/contact.png) no-repeat 0 0';
   \"><a href=\"http://www.wolfram.com/system-modeler/contact-us/\" class=\"headera\">Contact Us</a></span>
  </div> <div class=\"header\">&nbsp;</div> <h1>Gyroscopic Precession Example Model</h1><div class=\"contenttable\">
   <span class=\"contenttableheader\">CONTENTS:</span><br/>
   <table class=\"contenttabletable\"><tr><td><a href=\"#\" onClick=\"document.getElementById('headerTag_Introduction').scrollIntoView(); return false;\"><span class=\"hacek\">&#711;</span> Introduction</a></td><td><a href=\"#\" onClick=\"document.getElementById('headerTag_GyroModel').scrollIntoView(); return false;\"><span class=\"hacek\">&#711;</span> Gyro Model</a></td></tr><tr><td><a href=\"#\" onClick=\"document.getElementById('headerTag_Simulation').scrollIntoView(); return false;\"><span class=\"hacek\">&#711;</span> Simulation</a></td><td><a href=\"#\" onClick=\"document.getElementById('headerTag_GyroscopicPrecession').scrollIntoView(); return false;\"><span class=\"hacek\">&#711;</span> Gyroscopic Precession</a></td></tr></table></div><a id=\"headerTag_Introduction\" class=\"target\">&nbsp;</a>
    <h2>Introduction</h2>
    <p class=\"\">
This model studies how the torque applied to a rotating object may induce gyroscopic precession.
</p><a id=\"headerTag_GyroModel\" class=\"target\">&nbsp;</a>
    <h2>Gyro Model</h2>
    <p class=\"\">
The gyro in this model consists of a mount on which a rotor is placed in a system of two outer rings. This system makes it possible for the rotor to rotate in all three spatial dimensions (see graphic below). The rotor is given an initial angular velocity, and after a little while an external force acts on the inner ring, inducing a phenomenon called gyroscopic precession. An easy way of visualizing what is going on is to just add a 90 degree delay of the force being applied; a force being applied to the &quot;3 o'clock&quot; position acts as if it is being applied at the &quot;12 o'clock&quot; position (provided the rotor is spinning counterclockwise).
</p><p class=\"\">
<img src=\"./DocumentationFiles/gyro.png\" alt=\"\"/>
</p><a id=\"headerTag_Simulation\" class=\"target\">&nbsp;</a>
    <h2>Simulation</h2>
    <p class=\"\">
By simulating the model, you can try different values of the parameters and see how the gyro behaves. One of the most interesting parameters is the degreeOfForce, which will put the force on the inner ring at the degree specified, where 0 degrees is &quot;3 o'clock&quot;, 90 degrees is &quot;12 o'clock&quot;, etc. Try different values and check for yourself that the force always gets delayed by 90 degrees. Also try different values of the strength of the force (here called forceMagnitude) and the angular speed (here called spin) of the rotor and see how this affects the motion.
</p><p class=\"\">
To simulate the model and see the generated 3D animation, follow the steps below:
</p><ul><li>Click the <span class=\"dialogelement\">Simulate</span> button <img src=\"./DocumentationFiles/simulate.png\" alt=\"\"/>.</li><li>When the simulation is finished, click the <span class=\"dialogelement\">Animate</span> button <img src=\"./DocumentationFiles/animate.png\" alt=\"\"/> in Simulation Center.</li><li>Use your mouse or trackpad to drag the animation into a good angle and zoom in with your scroll wheel or by using the trackpad. Then click the <span class=\"dialogelement\">Play</span> button <img src=\"./DocumentationFiles/simPlay.png\" alt=\"\"/> to play the animation.</li></ul><p class=\"\">
If you would like to examine other things like angles and speeds during the simulation, you can plot these in the Simulation Center. Double click the <span class=\"dialogelement\">RevolutionAngles</span> plot in the Stored Plots section to see a plot of the angle of the inner ring.
</p><a id=\"headerTag_GyroscopicPrecession\" class=\"target\">&nbsp;</a>
    <h2>Gyroscopic Precession</h2>
    <p class=\"\">
Earlier the gyroscopic precession was described as a 90 degree delay of a force applied to a rotating body. While this is perfectly true, there is a more mathematical way of describing it. There are three physical quantities involved in gyroscopic precession: <b>T</b>, <b>&omega;<sub>p</sub></b>, <b>&omega;<sub>s</sub></b>, where <b>T</b> is the applied torque, <b>&omega;<sub>p</sub></b> is the angular velocity due to precession, and <b>&omega;<sub>s</sub></b> is the angular velocity of the rotor. These three make up a right-handed system in this order. This means, for example, that if the rotor spins around the <b>x</b> axis and torque is applied around the <b>y</b> axis, the gyro starts precessing around the <b>z</b> axis. The graphic below illustrates a rotor and the three rotational quantities. The vectors denote the direction of the rotational axes.
</p><p class=\"\">
<img src=\"./DocumentationFiles/GyroPrec.png\" alt=\"\"/>
</p><h2 class=\"legal\"> <a href=\"#\" onclick=\"
   if(document.getElementById('64').style.display == 'none'){
   document.getElementById('64').style.display = 'block';
   document.getElementById('show64').style.display = 'none';
   document.getElementById('hide64').style.display = 'inline';
   } else {
   document.getElementById('64').style.display = 'none';
   document.getElementById('show64').style.display = 'inline';
   document.getElementById('hide64').style.display = 'none';
   };
   return false;\" style=\"text-decoration: inherit; color: inherit\"><img src=\"./DocumentationFiles/showhide2.png\" alt=\"Show\" id=\"show64\" style=\"display: inline; vertical-align: text-bottom;\" /><img src=\"./DocumentationFiles/showhide.png\" alt=\"Hide\" id=\"hide64\" style=\"display: none; vertical-align: text-bottom;\" />Terms and Conditions of Use</a> </h2>
    <span id=\"64\" style=\"display: none;\"><p class=\"legallarge\">
This domain example is an informational resource made freely available by Wolfram Research.
</p><h3 class=\"legal\">Use of This Example</h3>
    <span id=\"65\" style=\"display: block;\"><ul class=\"legal\"><li>You may not use this example for any purpose that is unlawful or dangerous.</li><li>You assume total responsibility and risk for your use of this example.</li><li>You may not present this example with any alteration to its trade dress, trademarks, or design.</li></ul></span><h3 class=\"legal\">License</h3>
    <span id=\"66\" style=\"display: block;\"><p class=\"legalsmall\">
All content in this bundle is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License. By accessing the content or using it in any way, you accept and agree to be bound by the terms of this license. If you do not agree to these Terms of Use, you may not use this content. Wolfram Research reserves the right to change, modify, add to, or remove portions of these Terms of Use at any time without notice. Please refer back to <a href=\"http://www.wolfram.com\">www.wolfram.com</a> for the latest Terms of Use.
</p><p class=\"legalsmall\">
A summary of the licensing terms can be found at:<br>
        <a href=\"http://creativecommons.org/licenses/by-nc-sa/3.0\">http://creativecommons.org/licenses/by-nc-sa/3.0</a>
</p><p class=\"legalsmall\">
The full legal code can be found at:<br>
        <a href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/legalcode\">http://creativecommons.org/licenses/by-nc-sa/3.0/legalcode</a>
</p></span></span><div class=\"legalend\">&nbsp;</div>
   </body>
   <!--WSMINSERTIONTAGEND gyroModel --></html>", revisions = ""), Diagram(coordinateSystem(extent = {{-160, -120}, {160, 117.912}}, preserveAspectRatio = true, initialScale = 0.1, grid = {5, 5})),
    __Dymola_Commands(file="../animate_gyroscope.mos" "animate_gyroscope"));
end GyroModel;
