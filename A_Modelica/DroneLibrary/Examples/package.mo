within DroneLibrary;
package Examples
extends Modelica.Icons.ExamplesPackage;

annotation (Documentation(info="<html>
<p>This package contains examples of test systems with different model variants. The examples include using different input signals to control the inputs <strong>xcoord</strong>, <strong>ycoord</strong>, and <strong>zcoord</strong>, which can be signals provided in the <strong>DroneLibrary</strong>, Modelica Standard Library, experimental data, and custom signal functions defined by the user.</p>
<p>The inputs for the quadcopter model can also be left disconnected from any inputs and compiled as a Functional Mock-up Unit (FMU). By selecting this option, the model can be exported to other software tools for analysis and simulation. </p>
<p>The user can create their own drone models using the <strong>Drone_Template</strong>, which provides a standard template to interface the drone with any of the test cases.</p>
</html>"));
end Examples;
