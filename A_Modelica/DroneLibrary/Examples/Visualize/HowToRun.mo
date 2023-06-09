within DroneLibrary.Examples.Visualize;
class HowToRun "Explains how to run examples that use the Modelica Device Library and DLR's Visualization Library"
  extends Modelica.Icons.Information;
  annotation (preferredView = "info", Documentation(info="<html>
    <p>
        Some models in this package use interactive user input thanks to features from the Modelica Device Drivers Library and/or DLR's Visualization Library.
        Their output can be controlled by keyboard or joystick.
    </p>
    <p>
        Note that the example <code>ModuleTest_NoInput</code>, as its name indicates, has no input and runs as regular simulation. This is left for reference for the user's developers to understand the differences between a regular example (no interaction) and the other two examples.
    </p>
    <p>
      The following summarizes how the examples should be runned:
    <p>
      (A) If you do NOT have a license for DLR's library, you can run the example <code>ModuleTest_Dymola</code>, which has preconfigured keyboard inputs.
      To see your changes in real-time, you must select the the Simulation ribbon, which is synced with real-time.
      While a simulation is running, open a plot window and select the variables to monitor.
      For example, as shown below, one could monitor the height by monitoring the keyboard input for the Z-coordinate by plotting <code>keyboardInputs_Dymola.Z</code> and the corresponding sensor signal <code>controlModuleTest_fmu_inputs1.zgps</code>.
    </p>
    <p>
    (B) If you have a Professional Edition license for DLR's library, you can run the example
    <code>ModuleTestSimVis</code>. Follow the instructions from the library on how to run models that use this library.
    </p>

    <p>
    To obtain a license, see: <a href=\"https://visualization.ltx.de/\"> https://visualization.ltx.de/ </a>
    </p>
    <p>
    When using the Community Edition version of the library, one of the cameras in the model would need to be removed.
    </p>

    <h4>Example Run of <code>ModuleTest_Dymola</code></h4>
    <p>The image below shows a running simulation of the model <code>ModuleTest_Dymola</code>.
       The blue line shows the command issued from the keyboard, while the red line the model's response.
    </p>
    <img alt=\"Screenshot of Plot for simulation synced with real-time\" src=\"modelica://DroneLibrary/Resources/Images/realtime-sim.png\"/>
</html>"));
end HowToRun;
