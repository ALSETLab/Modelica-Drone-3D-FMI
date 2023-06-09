within DroneLibrary.Mechanical.Propeller.Variants;
model MavicAir
  extends DroneLibrary.Mechanical.Propeller.Templates.Propeller(
    redeclare Blades.Variants.MavicAir blades,
    redeclare Rotor.Variants.rotor rotor1,
    redeclare Motor.Variants.DCMotor DCMotor);
end MavicAir;
