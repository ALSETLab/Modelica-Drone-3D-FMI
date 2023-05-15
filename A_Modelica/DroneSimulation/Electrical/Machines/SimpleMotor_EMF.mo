within DroneSimulation.Electrical.Machines;
model SimpleMotor_EMF "Simplified DC motor model with EMF"

  Modelica.Electrical.Analog.Basic.Inductor inductor(L=X_s)
                                                           "Reactance"
    annotation (Placement(transformation(extent={{-10,8},{10,28}})));

  Modelica.Electrical.Analog.Basic.Resistor resistor(R=R_trs)
    "Effective resistance for transport ac loss"
    annotation (Placement(transformation(extent={{-50,8},{-30,28}})));
  parameter Modelica.Units.SI.Resistance R_trs=1e-6
    "Effective resistance for transport ac loss";
  parameter Modelica.Units.SI.Inductance X_s=0.041 "Reactance";
  Modelica.Electrical.Analog.Basic.Resistor hysteresis(R=R_hyst)
    "Effective resistance for hysteresis ac loss" annotation (Placement(
        transformation(
        extent={{-10,-10},{10,10}},
        rotation=270,
        origin={40,0})));
  parameter Modelica.Units.SI.Resistance R_hyst=149
    "Effective resistance for hysteresis ac loss";
  Modelica.Electrical.Analog.Basic.RotationalEMF emf(k=k) "back EMF"
    annotation (Placement(transformation(extent={{62,-10},{82,10}})));
  parameter Modelica.Units.SI.ElectricalTorqueConstant k=0.021
    "Transformation coefficient of back EMF";
  Modelica.Mechanics.Rotational.Interfaces.Flange_b flange1
                                                           "Flange"
    annotation (Placement(transformation(extent={{94,-10},{114,10}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(extent={{46,-42},{66,-22}})));
  Modelica.Electrical.Analog.Sources.SignalCurrent signalCurrent annotation (
      Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=90,
        origin={-72,0})));
  Modelica.Blocks.Interfaces.RealInput Current
    "Current flowing from pin p to pin n as input signal"
    annotation (Placement(transformation(extent={{-140,-20},{-100,20}})));
equation
  connect(inductor.p, resistor.n)
    annotation (Line(points={{-10,18},{-30,18}}, color={0,0,255}));
  connect(inductor.n, hysteresis.p)
    annotation (Line(points={{10,18},{40,18},{40,10}}, color={0,0,255}));
  connect(emf.p, hysteresis.p) annotation (Line(points={{72,10},{72,18},{40,18},
          {40,10}}, color={0,0,255}));
  connect(emf.flange, flange1)
    annotation (Line(points={{82,0},{104,0}}, color={0,0,0}));
  connect(hysteresis.n, ground.p) annotation (Line(points={{40,-10},{40,-16},{
          56,-16},{56,-22}}, color={0,0,255}));
  connect(emf.n, ground.p) annotation (Line(points={{72,-10},{72,-16},{56,-16},
          {56,-22}}, color={0,0,255}));
  connect(resistor.p, signalCurrent.n)
    annotation (Line(points={{-50,18},{-72,18},{-72,10}}, color={0,0,255}));
  connect(signalCurrent.p, ground.p) annotation (Line(points={{-72,-10},{-72,-16},
          {56,-16},{56,-22}}, color={0,0,255}));
  connect(signalCurrent.i, Current) annotation (Line(points={{-84,6.66134e-16},{
          -98,6.66134e-16},{-98,0},{-120,0}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
        Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
        Text(
          extent={{-62,28},{74,-20}},
          lineColor={28,108,200},
          textString="motor")}),
    Documentation(info="<html>
<p>This motor model considers losses in the system by including hysteresis and transfer losses.</p>
</html>"));
end SimpleMotor_EMF;
