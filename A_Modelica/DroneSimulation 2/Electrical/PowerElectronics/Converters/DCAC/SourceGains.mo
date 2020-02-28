within DroneSimulation.Electrical.PowerElectronics.Converters.DCAC;
model SourceGains
  Modelica.Blocks.Interfaces.RealInput m "Voltage Modulation"
    annotation (Placement(transformation(extent={{-120,54},{-80,94}})));
  Modelica.Blocks.Interfaces.RealInput i "Output Current"
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}})));
  Modelica.Blocks.Interfaces.RealOutput I_p "Positive Branch Current"
    annotation (Placement(transformation(extent={{100,70},{120,90}})));
  Modelica.Blocks.Interfaces.RealOutput I_n "Negative Branch Current"
    annotation (Placement(transformation(extent={{100,-10},{120,10}})));
  Modelica.Blocks.Interfaces.RealOutput Vt "Output Voltage"
    annotation (Placement(transformation(extent={{100,-92},{120,-72}})));
  Modelica.Blocks.Interfaces.RealInput Vdc "DC Voltage between Terminals"
    annotation (Placement(transformation(extent={{-120,-78},{-80,-38}})));
equation
  I_p = ((1+m)/2)*i;
  I_n = ((1-m)/2)*i;
  Vt = m*Vdc/2;
  annotation (Documentation(info="<html>
<p>Averaged Inverter Curent and Voltage Command generator.</p>
</html>"));
end SourceGains;
