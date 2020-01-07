within DroneSimulation.Examples.DroneWithoutIdealPower;
model PropellerTestwithBody
  Mechanical.Propeller_DCMachine propeller_DCMachine(PropellerGain=1)
    annotation (Placement(transformation(extent={{-10,16},{10,26}})));
  Modelica.Blocks.Sources.Ramp ramp(height=2, duration=1)
    annotation (Placement(transformation(extent={{-62,10},{-42,30}})));
  Mechanical.Propeller_DCMachine propeller_DCMachine1
    annotation (Placement(transformation(extent={{-10,-2},{10,8}})));
  Mechanical.Propeller_DCMachine propeller_DCMachine2(PropellerGain=1)
    annotation (Placement(transformation(extent={{-10,-18},{10,-8}})));
  Mechanical.Propeller_DCMachine propeller_DCMachine3
    annotation (Placement(transformation(extent={{-10,-34},{10,-24}})));
  Mechanical.droneChassis droneChassis1(length=0.25, m=0.5)
    annotation (Placement(transformation(extent={{44,-12},{94,8}})));
equation
  connect(propeller_DCMachine.position, ramp.y)
    annotation (Line(points={{-12,20},{-41,20}}, color={0,0,127}));
  connect(propeller_DCMachine1.position, ramp.y) annotation (Line(points={{-12,
          2},{-20,2},{-20,20},{-41,20}}, color={0,0,127}));
  connect(propeller_DCMachine2.position, ramp.y) annotation (Line(points={{-12,
          -14},{-20,-14},{-20,20},{-41,20}}, color={0,0,127}));
  connect(propeller_DCMachine3.position, ramp.y) annotation (Line(points={{-12,
          -30},{-20,-30},{-20,20},{-41,20}}, color={0,0,127}));
  connect(droneChassis1.frame_a1, propeller_DCMachine.Airframe) annotation (
      Line(
      points={{44,4},{28,4},{28,19},{10.2,19}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a, propeller_DCMachine1.Airframe) annotation (
      Line(
      points={{44,0},{28,0},{28,1},{10.2,1}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a2, propeller_DCMachine2.Airframe) annotation (
      Line(
      points={{44,-4},{26,-4},{26,-15},{10.2,-15}},
      color={95,95,95},
      thickness=0.5));
  connect(droneChassis1.frame_a3, propeller_DCMachine3.Airframe) annotation (
      Line(
      points={{44,-8},{28,-8},{28,-31},{10.2,-31}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    experiment(StopTime=10));
end PropellerTestwithBody;
