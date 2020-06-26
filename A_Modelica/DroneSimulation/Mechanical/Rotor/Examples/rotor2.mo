within DroneSimulation.Mechanical.Rotor.Examples;
model rotor2
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute(useAxisFlange=true,
                                                        animation=false)
    annotation (Placement(transformation(extent={{8,-26},{28,-6}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
    annotation (Placement(transformation(extent={{86,36},{118,68}})));

  Modelica.Mechanics.MultiBody.Interfaces.Frame_a force
    "Coordinate system fixed to the joint with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-118,-96},{-86,-64}}),
      iconTransformation(extent={{-118,-96},{-86,-64}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Blade
    annotation (Placement(transformation(extent={{86,-56},{118,-24}})));
Modelica.Mechanics.MultiBody.Interfaces.Frame_a aero_torque
    "Coordinate system a fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-116,72},{-84,104}}),
        iconTransformation(extent={{-118,54},{-86,86}})));
  Modelica.Mechanics.Rotational.Interfaces.Flange_b support1
    "1-dim. rotational flange of the drive support (assumed to be fixed in the world frame, NOT in the joint)"
    annotation (Placement(transformation(extent={{-110,-30},{-90,-10}})));
  Modelica.Mechanics.Rotational.Interfaces.Flange_a axis1
    "1-dim. rotational flange that drives the joint"
    annotation (Placement(transformation(extent={{-110,10},{-90,30}})));
equation
  connect(revolute.support, support1) annotation (Line(points={{12,-6},{12,-2},
          {-100,-2},{-100,-20}}, color={0,0,0}));
  connect(revolute.axis, axis1)
    annotation (Line(points={{18,-6},{18,20},{-100,20}}, color={0,0,0}));
  connect(force, revolute.frame_b) annotation (Line(
      points={{-102,-80},{-78,-80},{-78,-30},{42,-30},{42,-16},{28,-16}},
      color={95,95,95},
      thickness=0.5));
  connect(aero_torque, revolute.frame_b) annotation (Line(
      points={{-100,88},{42,88},{42,-16},{28,-16}},
      color={95,95,95},
      thickness=0.5));
  connect(Blade, revolute.frame_b) annotation (Line(
      points={{102,-40},{72,-40},{72,-30},{42,-30},{42,-16},{28,-16}},
      color={95,95,95},
      thickness=0.5));
  connect(Airframe, revolute.frame_a) annotation (Line(
      points={{102,52},{-2,52},{-2,-16},{8,-16}},
      color={95,95,95},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-72,22},{76,-20}},
          lineColor={28,108,200},
          textString="Rotor")}),      Diagram(coordinateSystem(
          preserveAspectRatio=false)));
end rotor2;
