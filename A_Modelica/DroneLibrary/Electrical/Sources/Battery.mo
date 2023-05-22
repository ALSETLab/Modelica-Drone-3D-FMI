within DroneLibrary.Electrical.Sources;
model Battery
  extends Modelon.Electrical.EnergyStorage.Battery(stackVoltage(ns=ns,
        redeclare
        Modelon.Electrical.EnergyStorage.Components.CellInfo.CellData.LiIon_18650
        cellInfo));
  parameter Integer ns=1 "Number of cells connected in series"
    annotation (Dialog(tab="Conditional"));
  annotation (Diagram(coordinateSystem(extent={{-120,-120},{120,120}})), Icon(
        coordinateSystem(extent={{-120,-120},{120,120}})),
    Documentation(info="<html>
<p>This is a battery model that is dependent on the Modelon standard library.</p>
</html>"));
end Battery;
