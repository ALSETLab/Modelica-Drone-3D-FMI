within DroneSimulation.Mechanical.Blades;
model Pinwheel

  parameter Modelica.Units.SI.Inertia J=10 "Moment of inertia";
  Modelica.Mechanics.MultiBody.Visualizers.PipeWithScalarField
    pipeWithScalarField(
    animation=false,
    rOuter=0.3,
    length=1,
    T=Modelica.Math.sin(Modelica.Constants.pi*pipeWithScalarField.xsi)*
        Modelica.Math.cos(Modelica.Constants.pi*time) .+ 1,
    T_min=0,
    T_max=2) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={88,42})));
  Modelica.Mechanics.MultiBody.Joints.GearConstraint
                        gearConstraint(
    ratio=10,
    phi_b(fixed=true),
    w_b(fixed=true),
    checkTotalPower=true)
                     annotation (Placement(transformation(extent={{6,32},{26,52}})));
  inner Modelica.Mechanics.MultiBody.World
              world(driveTrainMechanics3D=true, g=0) annotation (Placement(
        transformation(extent={{-94,2},{-74,22}})));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder
                     cyl1(
    animation=false,
    diameter=0.1,
    color={0,128,0},
    r={0.4,0,0}) annotation (Placement(transformation(extent={{-24,32},{-4,52}})));
  Modelica.Mechanics.MultiBody.Forces.Torque
                torque1 annotation (Placement(transformation(extent={{-54,32},{
            -34,52}})));
  Modelica.Mechanics.MultiBody.Parts.Fixed
              fixed annotation (Placement(transformation(extent={{-48,-92},{-28,
            -72}})));
  Modelica.Mechanics.Rotational.Components.Inertia
                                inertia1(
    J=cyl1.I[1, 1],
    a(fixed=false),
    phi(fixed=true, start=0),
    w(fixed=true, start=0)) annotation (Placement(transformation(extent={{32,-44},
            {52,-24}})));
  Modelica.Mechanics.Rotational.Sources.Torque
                            torque2(useSupport=true) annotation (Placement(
        transformation(extent={{2,-44},{22,-24}})));
  Modelica.Mechanics.MultiBody.Parts.Mounting1D
                   mounting1D annotation (Placement(transformation(extent={{-18,-74},
            {2,-54}})));
  CHEETA.Blocks.Routing.VectorInput
                         vectorInput(n=3)
    annotation (Placement(transformation(extent={{-76,70},{-56,90}})));
  Modelica.Blocks.Sources.RealExpression realExpression(y=inertia.flange_a.tau)
    annotation (Placement(transformation(extent={{-106,70},{-86,90}})));
  Modelica.Blocks.Sources.RealExpression realExpression1(y=inertia.flange_a.tau)
    annotation (Placement(transformation(extent={{-44,-44},{-24,-24}})));
  Modelica.Mechanics.Rotational.Components.Inertia inertia(J=J)
    annotation (Placement(transformation(extent={{-76,-28},{-56,-8}})));
  Modelica.Mechanics.MultiBody.Visualizers.PipeWithScalarField
    pipeWithScalarField1(
    animation=false,
    rOuter=0.3,
    length=1,
    T=Modelica.Math.sin(Modelica.Constants.pi*pipeWithScalarField.xsi)*
        Modelica.Math.cos(Modelica.Constants.pi*time) .+ 1,
    T_min=0,
    T_max=2) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        origin={86,6})));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder
                     cyl2(
    animation=false,
    diameter=0.1,
    color={0,128,0},
    r={0.4,0.4,0})
                 annotation (Placement(transformation(extent={{44,32},{64,52}})));
  Modelica.Mechanics.MultiBody.Parts.BodyCylinder
                     cyl3(
    animation=false,
    diameter=0.1,
    color={0,128,0},
    r={0.4,-0.4,0})
                 annotation (Placement(transformation(extent={{44,-4},{64,16}})));
Modelica.Mechanics.Rotational.Interfaces.Flange_a flange_a1
                    "Flange of left shaft"
  annotation (Placement(transformation(extent={{-110,-10},{-90,10}})));
equation
  connect(world.frame_b,gearConstraint. bearing) annotation (Line(
      points={{-74,12},{16,12},{16,32}},
      color={95,95,95},
      thickness=0.5));
  connect(cyl1.frame_b,gearConstraint. frame_a) annotation (Line(
      points={{-4,42},{6,42}},
      color={95,95,95},
      thickness=0.5));
  connect(torque1.frame_b,cyl1. frame_a) annotation (Line(
      points={{-34,42},{-24,42}},
      color={95,95,95},
      thickness=0.5));
  connect(torque1.frame_a,world. frame_b) annotation (Line(
      points={{-54,42},{-64,42},{-64,12},{-74,12}},
      color={95,95,95},
      thickness=0.5));
  connect(torque2.flange,inertia1. flange_a) annotation (Line(
      points={{22,-34},{32,-34}}));
  connect(mounting1D.flange_b,torque2. support) annotation (Line(
      points={{2,-64},{12,-64},{12,-44}}));
  connect(fixed.frame_b,mounting1D. frame_a) annotation (Line(
      points={{-28,-82},{-8,-82},{-8,-74}},
      color={95,95,95},
      thickness=0.5));
  connect(vectorInput.y,torque1. torque) annotation (Line(points={{-56,80},{-50,
          80},{-50,54}}, color={0,0,127}));
  connect(vectorInput.u,realExpression. y)
    annotation (Line(points={{-78,80},{-85,80}}, color={0,0,127}));
  connect(torque2.tau,realExpression1. y)
    annotation (Line(points={{0,-34},{-23,-34}}, color={0,0,127}));
connect(inertia.flange_a,flange_a1) annotation (Line(points={{-76,-18},{-92,
          -18},{-92,-14},{-100,-14},{-100,0}},
                                             color={0,0,0}));
connect(gearConstraint.frame_b,cyl2. frame_a) annotation (Line(
    points={{26,42},{44,42}},
    color={95,95,95},
    thickness=0.5));
connect(pipeWithScalarField.frame_a,cyl2. frame_b) annotation (Line(
    points={{78,42},{64,42}},
    color={95,95,95},
    thickness=0.5));
connect(pipeWithScalarField1.frame_a,cyl3. frame_b) annotation (Line(
    points={{76,6},{64,6}},
    color={95,95,95},
    thickness=0.5));
connect(cyl3.frame_a,cyl2. frame_a) annotation (Line(
    points={{44,6},{40,6},{40,42},{44,42}},
    color={95,95,95},
    thickness=0.5));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false), graphics={Rectangle(
          extent={{-100,100},{100,-100}}, lineColor={28,108,200})}),

    Documentation(info="<html>
<p>This model aims to simulate the animation of a pinwheel connected to a DC motor.</p>
</html>"));
end Pinwheel;
