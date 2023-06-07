within DroneLibrary.UsersGuide;
model GettingStarted
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false)),
    Diagram(coordinateSystem(preserveAspectRatio=false)),
    Documentation(info="<html>
<p>The Drone Library was developed to model and simulate a quadcopter in multiple domains. To start, navigate to <a href=\"modelica://DroneLibrary.Examples.DroneWithIdealPower.TestSystem\">DroneLibrary.Examples.DroneWithIdealPower.TestSystem</a>. This model contains the simplest version of the quadcopter. </p>
<h4><span style=\"color: #00aa00\">Simulating the Drone Model</span></h4>
<p>Using the model in DroneLibrary.Examples.DroneWithIdealPower.TestSystem, the model is configured as shown below:</p>
<p><img src=\"modelica://DroneLibrary/Resources/Images/UserGuide/TestSystem.png\"/></p>
<p>It is configured to hold the x- and y-direction coordinates to remain at the origin (0 m) and ramp the height of the drone up to 5m in the z-direction using the input <b>zcoord_ramp</b>. When the model is simulated, the following response is achieved:</p>
<p><img src=\"modelica://DroneLibrary/Resources/Images/UserGuide/AnimationPlot_Dashed.png\"/></p>
<h4><span style=\"color: #00aa00\">Changing model variants</span></h4>
<p>The model variants can be changed by right clicking on the drone model and changing the class following the figure below.</p>
<p><img src=\"modelica://DroneLibrary/Resources/Images/UserGuide/droneLib_Example1.png\"/></p>
<p>The system can then be simulated using different model variants and input commands.</p>
<h4><span style=\"color: #00aa00\">Automation Scripts</span></h4>
<p>The Drone Library contains scripts to configure the animation of the drone within a Modelica simulation environment and automated plotting of the XYZ-coordinate response of the system. These models were tested in Dymola 2019, 2020, 2021x, and 2022x. To set up the animation, run the DroneLibrary/Resources/Scripts/drone_animation_setup.mos script. Then the following animation appears and can be interacted with using the inputs supplied in <b>xcoord</b>, <b>ycoord</b>, and <b>zcoord</b>.</p>
<p><img src=\"modelica://DroneLibrary/Resources/Images/UserGuide/AnimationSetup.png\"/></p>
<p>The DroneLibrary/Resources/Scripts/plotOutput.mos script will plot the XYZ position of the drone and can be used for any of the tests in the <b>Examples</b> package. The  DroneLibrary/Resources/Scripts/drone_simulation_setup.mos configures the animation of the drone and plot windows for any of the example cases. </p>
</html>"));
end GettingStarted;
