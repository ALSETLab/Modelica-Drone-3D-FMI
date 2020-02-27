within DroneSimulation.Electrical.Sources;
model Battery
  extends Modelon.Electrical.EnergyStorage.Battery(stackVoltage(ns=ns,
        redeclare
        Modelon.Electrical.EnergyStorage.Components.CellInfo.CellData.NiMH_AA
        cellInfo));
  parameter Integer ns=1 "Number of cells connected in series"
    annotation (Dialog(tab="Conditional"));
  annotation (Diagram(coordinateSystem(extent={{-120,-120},{120,120}})), Icon(
        coordinateSystem(extent={{-120,-120},{120,120}})));
end Battery;
