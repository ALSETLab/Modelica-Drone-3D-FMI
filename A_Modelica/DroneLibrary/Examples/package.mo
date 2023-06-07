within DroneLibrary;
package Examples
extends Modelica.Icons.ExamplesPackage;

annotation (Documentation(info="<html>
<p>This package contains examples of test systems with different model variants. The examples include using different input signals to control the inputs <b>xcoord</b>, <b>ycoord</b>, and <b>zcoord</b>, which can be signals provided in the <b>DroneLibrary</b>, Modelica Standard Library, experimental data, and custom signal functions defined by the user.</p>
<p>The inputs for the quadcopter model can also be left disconnected from any inputs and compiled as a Functional Mock-up Unit (FMU). By selecting this option, the model can be exported to other software tools for analysis and simulation. </p>
</html>"));
end Examples;
