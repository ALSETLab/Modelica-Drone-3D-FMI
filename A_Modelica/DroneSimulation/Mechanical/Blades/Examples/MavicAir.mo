within DroneSimulation.Mechanical.Blades.Examples;
model MavicAir
  extends DroneSimulation.Mechanical.Blades.Templates.Blades(bodyShape4(r={0.2,
          0,0}, m=0.1), bodyShape5(r={-0.2,0,0}, m=0.1));
end MavicAir;
