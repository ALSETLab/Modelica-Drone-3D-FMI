within ;
package DroneLibrary "Modelica libray to model drones(UAVs)"
extends Modelica.Icons.Package;

annotation (
  version="1.0.0",
  versionDate="2023-06-09",
  Protection(access = Access.packageDuplicate),
  preferredView="info",
  uses(Modelica(version="4.0.0"),
    Visualization(version="1.6"),
    Modelica_DeviceDrivers(version="2.1.1")),
  Icon(graphics={Bitmap(extent={{-80,-80},{80,80}},
    fileName="modelica://DroneLibrary/Resources/Images/dronepic.jpg")}));
end DroneLibrary;
