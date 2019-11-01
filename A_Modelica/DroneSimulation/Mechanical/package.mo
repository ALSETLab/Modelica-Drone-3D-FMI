within DroneSimulation;
package Mechanical
  model droneChassis
    Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape(
      r={0,0.25,0},
      r_CM={0,0.175,0},
      m=m,
    useQuaternions=false)
      annotation (Placement(transformation(extent={{-22,36},{-2,56}})));
    Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape1(
      r={0.25,0,0},
      r_CM={0.175,0,0},
      m=0.5,
    useQuaternions=false)
                        annotation (Placement(transformation(
          extent={{-10,-10},{10,10}},
          rotation=0,
          origin={-12,14})));
    Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape2(
      m=0.5,
      r={0,-0.25,0},
      r_CM={0,-0.175,0},
    useQuaternions=false)
      annotation (Placement(transformation(extent={{-22,-24},{-2,-4}})));
    Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape3(
      m=0.5,
      r={-0.25,0,0},
      r_CM={-0.175,0,0},
    useQuaternions=false)
                         annotation (Placement(transformation(
          extent={{-10,-10},{10,10}},
          rotation=0,
          origin={-12,-48})));
    Modelica.Mechanics.MultiBody.Parts.BodyCylinder bodyCylinder(
      density=0,
      r_shape={0,0,0},
      diameter=0.01,
      r={0,0,-length},
      length=length,
    useQuaternions=false)
      annotation (Placement(transformation(extent={{32,-10},{52,10}})));
    Modelica.Mechanics.MultiBody.Parts.PointMass pointMass(m=0.50,
        sphereColor={255,0,255})
      annotation (Placement(transformation(extent={{52,-10},{72,10}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a
      annotation (Placement(transformation(extent={{-116,4},{-84,36}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a1
      annotation (Placement(transformation(extent={{-116,44},{-84,76}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a2
      annotation (Placement(transformation(extent={{-116,-36},{-84,-4}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a3
      annotation (Placement(transformation(extent={{-116,-76},{-84,-44}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a frame_a4
      annotation (Placement(transformation(extent={{-16,-16},{16,16}},
          rotation=90,
          origin={0,-100})));
    parameter Modelica.SIunits.Length length=0.25 "Length of cylinder";
    parameter Modelica.SIunits.Mass m=1 "Mass of rigid body";
  equation
    connect(bodyShape.frame_b, bodyCylinder.frame_a) annotation (Line(
        points={{-2,46},{16,46},{16,0},{32,0}},
        color={95,95,95},
        thickness=0.5));
    connect(bodyShape3.frame_b, bodyCylinder.frame_a) annotation (Line(
        points={{-2,-48},{16,-48},{16,0},{32,0}},
        color={95,95,95},
        thickness=0.5));
    connect(bodyShape1.frame_b, bodyCylinder.frame_a) annotation (Line(
        points={{-2,14},{16,14},{16,0},{32,0}},
        color={95,95,95},
        thickness=0.5));
    connect(bodyShape2.frame_b, bodyCylinder.frame_a) annotation (Line(
        points={{-2,-14},{16,-14},{16,0},{32,0}},
        color={95,95,95},
        thickness=0.5));
    connect(pointMass.frame_a, bodyCylinder.frame_b) annotation (Line(
        points={{62,0},{52,0}},
        color={95,95,95},
        thickness=0.5));
    connect(frame_a1, bodyShape.frame_a) annotation (Line(
        points={{-100,60},{-62,60},{-62,46},{-22,46}},
        color={95,95,95},
        thickness=0.5));
    connect(frame_a, bodyShape1.frame_a) annotation (Line(
        points={{-100,20},{-62,20},{-62,14},{-22,14}},
        color={95,95,95},
        thickness=0.5));
    connect(frame_a2, bodyShape2.frame_a) annotation (Line(
        points={{-100,-20},{-62,-20},{-62,-14},{-22,-14}},
        color={95,95,95},
        thickness=0.5));
    connect(frame_a3, bodyShape3.frame_a) annotation (Line(
        points={{-100,-60},{-62,-60},{-62,-48},{-22,-48}},
        color={95,95,95},
        thickness=0.5));
    connect(bodyCylinder.frame_a, frame_a4) annotation (Line(
        points={{32,0},{16,0},{16,-76},{0,-76},{0,-100}},
        color={95,95,95},
        thickness=0.5));
    annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
            Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
            Text(
            extent={{-68,26},{70,-26}},
            lineColor={28,108,200},
            textString="droneChassis")}), Diagram(coordinateSystem(
            preserveAspectRatio=false)));
  end droneChassis;

  model rotor
    Modelica.Mechanics.MultiBody.Joints.Revolute revolute
      annotation (Placement(transformation(extent={{4,-10},{24,10}})));

    Modelica.Mechanics.MultiBody.Interfaces.Frame_a Airframe
      annotation (Placement(transformation(extent={{86,36},{118,68}})));
    Modelica.Mechanics.MultiBody.Sensors.RelativeAngularVelocity
      relativeAngularVelocity
      annotation (Placement(transformation(extent={{30,74},{50,94}})));
    Modelica.Mechanics.MultiBody.Forces.Torque torque1
      annotation (Placement(transformation(extent={{8,-88},{28,-68}})));
    Modelica.Blocks.Math.Gain gain(k=-0.004) annotation (Placement(
          transformation(
          extent={{-6,-6},{6,6}},
          rotation=270,
          origin={40,10})));
    Blocks.Routing.RealExtract realExtract annotation (Placement(
          transformation(
          extent={{-6,-6},{6,6}},
          rotation=270,
          origin={40,40})));
    Blocks.Routing.RealExtend realExtend2 annotation (Placement(
          transformation(
          extent={{-6,-6},{6,6}},
          rotation=270,
          origin={40,-22})));
    parameter Real k=-1
      "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise";
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a force
      "Coordinate system fixed to the joint with one cut-force and cut-torque"
      annotation (Placement(transformation(extent={{-116,-78},{-84,-46}}),
        iconTransformation(extent={{-116,-78},{-84,-46}})));
    Modelica.Mechanics.MultiBody.Interfaces.Frame_a Blade
      annotation (Placement(transformation(extent={{86,-56},{118,-24}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a torque_1
      "Coordinate system a fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-118,44},{-86,76}}),
        iconTransformation(extent={{-118,44},{-86,76}})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_b torque_2
      "Coordinate system b fixed to the component with one cut-force and cut-torque"
    annotation (Placement(transformation(extent={{-118,-16},{-86,16}}),
        iconTransformation(extent={{-118,-16},{-86,16}})));
  equation
    connect(relativeAngularVelocity.w_rel, realExtract.u)
      annotation (Line(points={{40,73},{40,46}}, color={0,0,127}));
    connect(realExtract.y, gain.u)
      annotation (Line(points={{40,33.4},{40,17.2}}, color={0,0,127}));
    connect(gain.y, realExtend2.u)
      annotation (Line(points={{40,3.4},{40,-14.8}},
                                                  color={0,0,127}));
    connect(realExtend2.y, torque1.torque) annotation (Line(points={{40,-28.6},
            {40,-40},{12,-40},{12,-66}},
                                color={0,0,127}));
    connect(relativeAngularVelocity.frame_a, torque1.frame_a) annotation (
        Line(
        points={{30,84},{-14,84},{-14,-78},{8,-78}},
        color={95,95,95},
        thickness=0.5));
    connect(revolute.frame_a, torque1.frame_a) annotation (Line(
        points={{4,0},{-14,0},{-14,-78},{8,-78}},
        color={95,95,95},
        thickness=0.5));
    connect(revolute.frame_a, force) annotation (Line(
        points={{4,0},{-48,0},{-48,-62},{-100,-62}},
        color={95,95,95},
        thickness=0.5));
    connect(Airframe, torque1.frame_a) annotation (Line(
        points={{102,52},{84,52},{84,92},{-14,92},{-14,-78},{8,-78}},
        color={95,95,95},
        thickness=0.5));
    connect(Blade, torque1.frame_b) annotation (Line(
        points={{102,-40},{62,-40},{62,-78},{28,-78}},
        color={95,95,95},
        thickness=0.5));
    connect(revolute.frame_b, torque1.frame_b) annotation (Line(
        points={{24,0},{62,0},{62,-78},{28,-78}},
        color={95,95,95},
        thickness=0.5));
    connect(relativeAngularVelocity.frame_b, torque1.frame_b) annotation (
        Line(
        points={{50,84},{62,84},{62,-78},{28,-78}},
        color={95,95,95},
        thickness=0.5));
  connect(torque_2, torque1.frame_b) annotation (Line(
      points={{-102,0},{62,0},{62,-78},{28,-78}},
      color={95,95,95},
      thickness=0.5));
  connect(torque_1, torque1.frame_a) annotation (Line(
      points={{-102,60},{-14,60},{-14,-78},{8,-78}},
      color={95,95,95},
      thickness=0.5));
    annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
            Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
            Text(
            extent={{-72,22},{76,-20}},
            lineColor={28,108,200},
            textString="Rotor")}),      Diagram(coordinateSystem(
            preserveAspectRatio=false)));
  end rotor;

  annotation (Icon(graphics={
        Rectangle(
          lineColor={200,200,200},
          fillColor={248,248,248},
          fillPattern=FillPattern.HorizontalCylinder,
          extent={{-100.0,-100.0},{100.0,100.0}},
          radius=25.0),
        Rectangle(
          lineColor={128,128,128},
          extent={{-100.0,-100.0},{100.0,100.0}},
          radius=25.0),
      Rectangle(
        origin={8.6,63.3333},
        lineColor={64,64,64},
        fillColor={192,192,192},
        fillPattern=FillPattern.HorizontalCylinder,
        extent={{-4.6,-93.3333},{41.4,-53.3333}}),
      Ellipse(
        origin={9.0,46.0},
        extent={{-90.0,-60.0},{-80.0,-50.0}}),
      Line(
        origin={9.0,46.0},
        points={{-85.0,-55.0},{-60.0,-21.0}},
        thickness=0.5),
      Ellipse(
        origin={9.0,46.0},
        extent={{-65.0,-26.0},{-55.0,-16.0}}),
      Line(
        origin={9.0,46.0},
        points={{-60.0,-21.0},{9.0,-55.0}},
        thickness=0.5),
      Ellipse(
        origin={9.0,46.0},
        fillPattern=FillPattern.Solid,
        extent={{4.0,-60.0},{14.0,-50.0}}),
      Line(
        origin={9.0,46.0},
        points={{-10.0,-26.0},{72.0,-26.0},{72.0,-86.0},{-10.0,-86.0}})}));
end Mechanical;
