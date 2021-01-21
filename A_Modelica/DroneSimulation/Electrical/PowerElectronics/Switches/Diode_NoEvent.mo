within DroneSimulation.Electrical.PowerElectronics.Switches;
model Diode_NoEvent
  parameter Real Ron(final min=0) = 1e-5
    "Forward state-on differential resistance (closed resistance)";
  parameter Real Goff(final min=0) = 1e-5
    "Backward state-off conductance (opened conductance)";
  parameter Real Vknee(final min=0) = 0.7;
  Real va,vb,vc,ia,ib,ic, LossPower;
  Boolean offa,offb,offc;
  Modelica.Electrical.Polyphase.Interfaces.PositivePlug p_p
    annotation (Placement(transformation(extent={{-114,-10},{-94,10}})));
  Modelica.Electrical.Polyphase.Interfaces.NegativePlug p_n
    annotation (Placement(transformation(extent={{94,-10},{114,10}})));
protected
    Real sa(start=0, final unit="1");
    Real sb(start=0, final unit="1");
    Real sc(start=0, final unit="1");
equation
  va = p_p.pin[1].v - p_n.pin[1].v;
  vb = p_p.pin[2].v - p_n.pin[2].v;
  vc = p_p.pin[3].v - p_n.pin[3].v;
  p_p.pin[1].i + p_n.pin[1].i = 0;
  p_p.pin[2].i + p_n.pin[2].i = 0;
  p_p.pin[3].i + p_n.pin[3].i = 0;
  ia = p_p.pin[1].i;
  ib = p_p.pin[2].i;
  ic = p_p.pin[3].i;

  va = sa*(if offa then 1 else Ron) + Vknee;
  ia = sa*(if offa then Goff else 1) + Goff*Vknee;
  vb = sb*(if offb then 1 else Ron) + Vknee;
  ib = sb*(if offb then Goff else 1) + Goff*Vknee;
  vc = sc*(if offc then 1 else Ron) + Vknee;
  ic = sc*(if offc then Goff else 1) + Goff*Vknee;

  LossPower = va*ia+vb*ib+ic*vc;

  when sa<0 then
    offa = true;
  elsewhen sa>=0 then
    offa = false;
  end when;

  when sb<0 then
    offb = true;
  elsewhen sb>=0 then
    offb = false;
    end when;

  when sb<0 then
    offc = true;
  elsewhen sc>=0 then
    offc = false;
  end when;
end Diode_NoEvent;
