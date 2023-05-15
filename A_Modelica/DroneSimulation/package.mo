within ;
package DroneSimulation
annotation (Documentation, uses(
    Visualization(version="1.5.1"),
    IdealizedContact(version="0.2.0"),
    ModelicaServices(version="4.0.0"),
    Modelica(version="4.0.0"),
    VeSyMA(version="2023.1"),
    Claytex(version="2023.1"),
    BrushlessDCDrives(version="1.1.2"),
    Battery(version="2.5.0"),
    Modelon(version="3.6")),
  version="4",
  conversion(from(version={"2","1"}, script=
          "modelica://DroneSimulation/ConvertFromDroneSimulation_2.mos"),
      noneFromVersion="3"));
end DroneSimulation;
