within DroneSimulation.Examples;
model DCMotor_DCMachine4 "DC motor using DC machine from MSL"

  parameter Real k=-1
    "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";

  parameter Modelica.SIunits.Voltage VaNominal=5
    "Nominal armature voltage for motor";
  parameter Modelica.SIunits.Current IaNominal=0.1
    "Nominal armature current (>0..Motor, <0..Generator) for motor";

  DCmachine_withforce dCmachine_withforce(k=1)
    annotation (Placement(transformation(extent={{0,60},{20,80}})));
  DCmachine_withforce1 dCmachine_withforce1(
                                           k=-1)
    annotation (Placement(transformation(extent={{0,20},{20,40}})));
  DCmachine_withforce dCmachine_withforce2(k=1)
    annotation (Placement(transformation(extent={{0,-20},{20,0}})));
  DCmachine_withforce1 dCmachine_withforce1_1(
                                           k=-1)
    annotation (Placement(transformation(extent={{0,-60},{20,-40}})));
  Mechanical.Blades.Examples.Blades blades1
    annotation (Placement(transformation(extent={{34,32},{42,40}})));
  Mechanical.Blades.Examples.Blades blades2
    annotation (Placement(transformation(extent={{34,-8},{42,0}})));
  Mechanical.Blades.Examples.Blades blades3
    annotation (Placement(transformation(extent={{34,-48},{42,-40}})));
  Mechanical.Blades.Examples.Blades blades
    annotation (Placement(transformation(extent={{34,72},{42,80}})));
  Modelica.Blocks.Sources.Ramp ramp(height=12, duration=0)
    annotation (Placement(transformation(extent={{-60,0},{-40,20}})));
  Sensors.GPS gPS
    annotation (Placement(transformation(extent={{74,-58},{94,-38}})));
  Modelica.Mechanics.MultiBody.Parts.Body body(r_CM={0.25,0,0}, m=0.25)
    annotation (Placement(transformation(extent={{42,42},{62,62}})));
  Modelica.Mechanics.MultiBody.Parts.Body body1(r_CM={0,0.25,0}, m=0.25)
    annotation (Placement(transformation(extent={{58,0},{78,20}})));
  Modelica.Mechanics.MultiBody.Parts.Body body2(r_CM={-0.25,0,0}, m=0.25)
    annotation (Placement(transformation(extent={{68,-20},{88,0}})));
  Modelica.Mechanics.MultiBody.Parts.Body body3(r_CM={0,-0.25,0}, m=0.25)
    annotation (Placement(transformation(extent={{50,-80},{70,-60}})));
equation
  connect(dCmachine_withforce1.frame_a1, blades1.Input) annotation (Line(
      points={{20.2,36},{33.84,36}},
      color={95,95,95},
      thickness=0.5));
  connect(dCmachine_withforce2.frame_a1, blades2.Input) annotation (Line(
      points={{20.2,-4},{33.84,-4}},
      color={95,95,95},
      thickness=0.5));
  connect(dCmachine_withforce1_1.frame_a1, blades3.Input) annotation (Line(
      points={{20.2,-44},{33.84,-44}},
      color={95,95,95},
      thickness=0.5));
  connect(dCmachine_withforce.frame_a1, blades.Input) annotation (Line(
      points={{20.2,76},{33.84,76}},
      color={95,95,95},
      thickness=0.5));
  connect(ramp.y, dCmachine_withforce1_1.u1) annotation (Line(points={{-39,10},
          {-22,10},{-22,-42.2},{-2,-42.2}}, color={0,0,127}));
  connect(dCmachine_withforce2.u1, ramp.y) annotation (Line(points={{-2,-2.2},{
          -20,-2.2},{-20,10},{-39,10}}, color={0,0,127}));
  connect(dCmachine_withforce1.u1, ramp.y) annotation (Line(points={{-2,37.8},{
          -22,37.8},{-22,10},{-39,10}}, color={0,0,127}));
  connect(dCmachine_withforce.u1, ramp.y) annotation (Line(points={{-2,77.8},{
          -22,77.8},{-22,10},{-39,10}}, color={0,0,127}));
  connect(gPS.frame_a, dCmachine_withforce1_1.frame_b1) annotation (Line(
      points={{74,-48},{54,-48},{54,-48.8},{20.2,-48.8}},
      color={95,95,95},
      thickness=0.5));
  connect(dCmachine_withforce.frame_b1, body.frame_a) annotation (Line(
      points={{20.2,71.2},{32,71.2},{32,52},{42,52}},
      color={95,95,95},
      thickness=0.5));
  connect(body1.frame_a, dCmachine_withforce1.frame_b1) annotation (Line(
      points={{58,10},{40,10},{40,31.2},{20.2,31.2}},
      color={95,95,95},
      thickness=0.5));
  connect(body2.frame_a, dCmachine_withforce2.frame_b1) annotation (Line(
      points={{68,-10},{44,-10},{44,-8.8},{20.2,-8.8}},
      color={95,95,95},
      thickness=0.5));
  connect(body3.frame_a, dCmachine_withforce1_1.frame_b1) annotation (Line(
      points={{50,-70},{44,-70},{44,-48},{48,-48},{48,-48.8},{20.2,-48.8}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false, extent={{-80,
            -100},{140,100}}),                                  graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Motor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false, extent={{-80,-100},{140,100}})),
    experiment(StopTime=30, __Dymola_Algorithm="Dassl"));
end DCMotor_DCMachine4;
