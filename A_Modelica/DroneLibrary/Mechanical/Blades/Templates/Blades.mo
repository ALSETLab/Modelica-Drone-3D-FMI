within DroneLibrary.Mechanical.Blades.Templates;
partial model Blades
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape5(
    animation=false,
    animateSphere=false,
    m=m,
    r=r,
    I_33=0.001,
    useQuaternions=true)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={66,-10})));
  Modelica.Mechanics.MultiBody.Parts.BodyShape bodyShape4(
    animation=false,
    animateSphere=false,
    m=m,
    r=r,
    I_33=0.001,
    shapeType="cylinder",
    useQuaternions=true)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={66,10})));
  Modelica.Mechanics.MultiBody.Interfaces.Frame_a Input
    "Input from motor connecting the propeller blades to the motor"
    annotation (Placement(transformation(extent={{-120,-16},{-88,16}}),
        iconTransformation(extent={{-120,-16},{-88,16}})));
  parameter Modelica.Units.SI.Mass m=0.01 "Mass of rigid body";
  parameter Modelica.Units.SI.Position r[3]={0.154,0,0}
    "Vector from frame_a to frame_b resolved in frame_a";
equation
  connect(bodyShape4.frame_a, Input) annotation (Line(
      points={{66,0},{-104,0}},
      color={95,95,95},
      thickness=0.5));

end Blades;
