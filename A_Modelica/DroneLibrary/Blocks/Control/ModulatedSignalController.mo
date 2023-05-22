within DroneLibrary.Blocks.Control;
model ModulatedSignalController "Modulated signal controller for PWM control"
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=uMax, uMin=uMin)
    annotation (Placement(transformation(extent={{68,-6},{80,6}})));
  Modelica.Blocks.Math.Add add(k2=-1)
    annotation (Placement(transformation(extent={{-78,-6},{-66,6}})));
  Modelica.Blocks.Interfaces.RealInput Reference
    annotation (Placement(transformation(extent={{-120,30},{-100,50}})));
  Modelica.Blocks.Interfaces.RealInput FeedbackSignal
    annotation (Placement(transformation(extent={{-120,-50},{-100,-30}})));
  Modelica.Blocks.Interfaces.RealInput Vdc2 annotation (Placement(
        transformation(
        extent={{-12,-12},{12,12}},
        rotation=90,
        origin={0,-112})));
  Modelica.Blocks.Math.Division division
    annotation (Placement(transformation(extent={{42,-6},{54,6}})));
  Modelica.Blocks.Interfaces.RealOutput y
    annotation (Placement(transformation(extent={{100,-10},{120,10}}),
        iconTransformation(extent={{100,-10},{120,10}})));
  Modelica.Blocks.Continuous.TransferFunction transferFunction(
    b=b2,
    a=a2,
    initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-14,-6},{-2,6}})));
  Modelica.Blocks.Continuous.TransferFunction transferFunction1(b=b3, a=a3)
    annotation (Placement(transformation(extent={{8,-6},{20,6}})));
  Modelica.Blocks.Continuous.TransferFunction transferFunction2(b=b1, a=a1,
    initType=Modelica.Blocks.Types.Init.SteadyState)
    annotation (Placement(transformation(extent={{-38,-6},{-26,6}})));
  Modelica.Blocks.Math.Gain gain(k=k)
    annotation (Placement(transformation(extent={{-58,-6},{-48,4}})));
  parameter Real k=8680
    "Reference gain for difference between reference signal and the actual signal";
  parameter Real b1[:]={1,8.52} "Transfer function numerator 1";
  parameter Real a1[:]={1,0,142129} "Transfer function denominator 1";
  parameter Real b2[:]={1,966} "Transfer function numerator 2";
  parameter Real a2[:]={1,5633} "Transfer function denominator 2";
  parameter Real b3[:]={1,2} "Transfer function numerator 3";
  parameter Real a3[:]={1,0.05} "Transfer function numerator 3";
  parameter Real uMax=1 "Upper limit of output signal y";
  parameter Real uMin=-1 "Lower limits of output signal y";
equation
  connect(Reference, add.u1) annotation (Line(points={{-110,40},{-86,40},{-86,3.6},
          {-79.2,3.6}}, color={0,0,127}));
  connect(FeedbackSignal, add.u2) annotation (Line(points={{-110,-40},{-86,-40},
          {-86,-3.6},{-79.2,-3.6}}, color={0,0,127}));
  connect(division.y, limiter.u)
    annotation (Line(points={{54.6,0},{66.8,0}}, color={0,0,127}));
  connect(limiter.y, y)
    annotation (Line(points={{80.6,0},{110,0}}, color={0,0,127}));
  connect(division.u2, Vdc2) annotation (Line(points={{40.8,-3.6},{40,-3.6},{40,
          -4},{32,-4},{32,-74},{0,-74},{0,-112}},
                                  color={0,0,127}));
  connect(transferFunction2.u, gain.y) annotation (Line(points={{-39.2,0},{-40,0},
          {-40,-1},{-47.5,-1}}, color={0,0,127}));
  connect(add.y, gain.u) annotation (Line(points={{-65.4,0},{-64,0},{-64,-1},{-59,
          -1}}, color={0,0,127}));
  connect(transferFunction2.y, transferFunction.u)
    annotation (Line(points={{-25.4,0},{-15.2,0}}, color={0,0,127}));
  connect(transferFunction.y, transferFunction1.u)
    annotation (Line(points={{-1.4,0},{6.8,0}}, color={0,0,127}));
  connect(transferFunction1.y, division.u1) annotation (Line(points={{20.6,0},{30,
          0},{30,3.6},{40.8,3.6}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false), graphics={
          Rectangle(extent={{-100,100},{100,-100}}, lineColor={28,108,200}),
          Text(
          extent={{-86,30},{80,-34}},
          lineColor={28,108,200},
          textString="Modulated Signal
Controller")}));
end ModulatedSignalController;
