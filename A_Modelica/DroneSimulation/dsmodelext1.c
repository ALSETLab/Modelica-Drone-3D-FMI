#include <moutil.c>
PreNonAliasDef(6)
PreNonAliasDef(7)
PreNonAliasDef(8)
PreNonAliasDef(9)
PreNonAliasDef(10)
StartNonAlias(5)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi[1]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi[2]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi[3]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_d[1]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_d[2]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_d[3]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape1.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[1]", -1, 5, 4268, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[2]", -1, 5, 4269, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[3]", -1, 5, 4270, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[1]", -1, 5, 4271, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[2]", -1, 5, 4272, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[3]", -1, 5, 4273, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frame_b.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.frame_b.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.animation", "= true, if animation shall be enabled (show shape between frame_a and frame_b and optionally a sphere at the center of mass) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.animateSphere", "= true, if mass shall be animated as sphere provided animation=true [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.r[1]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r[2]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r[3]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_CM[1]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_CM[2]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 -0.175, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_CM[3]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.m", "Mass of rigid body [kg]", \
0.5, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_11", "Element (1,1) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_22", "Element (2,2) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_33", "Element (3,3) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_21", "Element (2,1) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_31", "Element (3,1) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.I_32", "Element (3,2) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape2.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(r_0[1])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape2.v_0[1]", 1, 5, 6837, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(r_0[2])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[2])", 1, 6, 66, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(r_0[3])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[3])", 1, 6, 67, 0)
DeclareVariable("drone.droneChassis2.bodyShape2.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape2.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[2])", 1, 6, 66, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[3])", 1, 6, 67, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(v_0[1])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[1]", 1, 5, 6943, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(v_0[2])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[2]", 1, 5, 6944, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.der(v_0[3])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[3]", 1, 5, 6945, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[1]", 1, 5, 6943, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[2]", 1, 5, 6944, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[3]", 1, 5, 6945, 0)
DeclareVariable("drone.droneChassis2.bodyShape2.angles_fixed", "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.w_0_fixed", "= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.w_0_start[1]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.w_0_start[2]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.w_0_start[3]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.z_0_fixed", "= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.z_0_start[1]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.z_0_start[2]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.z_0_start[3]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_shape[1]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_shape[2]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.r_shape[3]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.lengthDirection[1]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.lengthDirection[2]", \
"Vector in length direction of shape, resolved in frame_a [1]", -0.25, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.lengthDirection[3]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.widthDirection[1]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.widthDirection[2]", \
"Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.widthDirection[3]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.length", "Length of shape [m]", \
0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.width", "Width of shape [m]", \
0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.height", "Height of shape [m]", \
0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.extra", "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.color[1]", "Color of shape [:#(type=Integer)]",\
 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.color[2]", "Color of shape [:#(type=Integer)]",\
 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.color[3]", "Color of shape [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sphereDiameter", \
"Diameter of sphere [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.sphereColor[1]", \
"Color of sphere of mass [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sphereColor[2]", \
"Color of sphere of mass [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sphereColor[3]", \
"Color of sphere of mass [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.enforceStates", "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_angleStates[1]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_angleStates[2]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.sequence_angleStates[3]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 4)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[1]", -1,\
 5, 6815, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[2]", -1,\
 5, 6816, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[3]", -1,\
 5, 6817, 132)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape2.frame_b.t[2]", -1,\
 5, 6819, 132)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[1]", 1,\
 5, 6815, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[2]", 1,\
 5, 6816, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape2.frame_b.f[3]", 1,\
 5, 6817, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape2.frame_b.t[1]", 1,\
 5, 6818, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape2.frame_b.t[2]", 1,\
 5, 6819, 132)
DeclareAlias2("drone.droneChassis2.bodyShape2.frameTranslation.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape2.frame_b.t[3]", 1,\
 5, 6820, 132)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", -0.25, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.length", \
"Length of shape [m]", 0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.width", \
"Width of shape [m]", 0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.height", \
"Height of shape [m]", 0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.color[1]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.color[2]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.color[3]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 4)
DeclareState("drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 66, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[2])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0, 0.0,0.0,0.0,0,520)
DeclareState("drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 67, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[3])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[1])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyShape2.v_0[1]", 1, 5, 6837, 4)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape2.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.r_CM[1]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.r_CM[2]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 -0.175, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.r_CM[3]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.m", "Mass of rigid body [kg]",\
 0.5, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_11", "Element (1,1) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_22", "Element (2,2) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_33", "Element (3,3) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_21", "Element (2,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_31", "Element (3,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I_32", "Element (3,2) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape2.v_0[1]", 1, 5, 6837, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[2])", 1, 6, 66, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.der(r_0[3])", 1, 6, 67, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[1]", 1, 5, 6943, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[2]", 1, 5, 6944, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape2.body.a_0[3]", 1, 5, 6945, 0)
DeclareVariable("drone.droneChassis2.bodyShape2.body.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape2.body.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sphereDiameter", \
"Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sphereColor[1]", \
"Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sphereColor[2]", \
"Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sphereColor[3]", \
"Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.cylinderDiameter", \
"Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.cylinderColor[1]", \
"Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.cylinderColor[2]", \
"Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.cylinderColor[3]", \
"Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_angleStates[1]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_angleStates[2]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.sequence_angleStates[3]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[1, 1]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[1, 2]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[1, 3]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[2, 1]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[2, 2]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[2, 3]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[3, 1]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[3, 2]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.I[3, 3]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.T[3, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.R_start.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.w_a[1]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.w_a[2]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.w_a[3]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(w_a[1])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(w_a[2])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.der(w_a[3])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.z_a[1]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.z_a[2]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyShape2.body.z_a[3]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareVariable("drone.droneChassis2.bodyShape2.body.g_0[1]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.g_0[2]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.g_0[3]", "Gravity acceleration resolved in world frame [m/s2]",\
 -9.80665, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q[1]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q[2]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q[3]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.Q[4]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_start[1]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_start[2]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_start[3]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi[1]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi[2]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi[3]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_d[1]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_d[2]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_d[3]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape2.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.rotor3_1.revolute.frame_a.f[1]", -1, 5, 5208,\
 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.rotor3_1.revolute.frame_a.f[2]", -1, 5, 5209,\
 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.Airframe.f[3]", -1, 5, 5467, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[1]", -1, 5, 5468, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[2]", -1, 5, 5469, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[3]", -1, 5, 5470, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frame_b.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frame_b.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.animation", "= true, if animation shall be enabled (show shape between frame_a and frame_b and optionally a sphere at the center of mass) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.animateSphere", "= true, if mass shall be animated as sphere provided animation=true [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.r[1]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r[2]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r[3]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_CM[1]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 -0.175, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_CM[2]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_CM[3]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.m", "Mass of rigid body [kg]", \
0.5, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_11", "Element (1,1) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_22", "Element (2,2) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_33", "Element (3,3) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_21", "Element (2,1) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_31", "Element (3,1) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.I_32", "Element (3,2) of inertia tensor [kg.m2]",\
 0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape3.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 0)
DeclareVariable("drone.droneChassis2.bodyShape3.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape3.der(r_0[1])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[1]", 1, 1, 68, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.der(r_0[2])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[2]", 1, 1, 69, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.der(r_0[3])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[3]", 1, 1, 70, 0)
DeclareState("drone.droneChassis2.bodyShape3.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 68, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.droneChassis2.bodyShape3.der(v_0[1])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareState("drone.droneChassis2.bodyShape3.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 69, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.droneChassis2.bodyShape3.der(v_0[2])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareState("drone.droneChassis2.bodyShape3.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 70, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.droneChassis2.bodyShape3.der(v_0[3])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape3.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape3.der(v_0[1])", 1, 6, 68, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape3.der(v_0[2])", 1, 6, 69, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyShape3.der(v_0[3])", 1, 6, 70, 0)
DeclareVariable("drone.droneChassis2.bodyShape3.angles_fixed", "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.w_0_fixed", "= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.w_0_start[1]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.w_0_start[2]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.w_0_start[3]", "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.z_0_fixed", "= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.z_0_start[1]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.z_0_start[2]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.z_0_start[3]", "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_shape[1]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_shape[2]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.r_shape[3]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.lengthDirection[1]", \
"Vector in length direction of shape, resolved in frame_a [1]", -0.25, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.lengthDirection[2]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.lengthDirection[3]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.widthDirection[1]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.widthDirection[2]", \
"Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.widthDirection[3]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.length", "Length of shape [m]", \
0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.width", "Width of shape [m]", \
0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.height", "Height of shape [m]", \
0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.extra", "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.color[1]", "Color of shape [:#(type=Integer)]",\
 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.color[2]", "Color of shape [:#(type=Integer)]",\
 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.color[3]", "Color of shape [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sphereDiameter", \
"Diameter of sphere [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.sphereColor[1]", \
"Color of sphere of mass [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sphereColor[2]", \
"Color of sphere of mass [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sphereColor[3]", \
"Color of sphere of mass [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.enforceStates", "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_angleStates[1]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_angleStates[2]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.sequence_angleStates[3]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 4)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[1]", -1,\
 5, 7019, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[2]", -1,\
 5, 7020, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[3]", -1,\
 5, 7021, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape3.frame_b.t[1]", -1,\
 5, 7022, 132)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[1]", 1,\
 5, 7019, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[2]", 1,\
 5, 7020, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyShape3.frame_b.f[3]", 1,\
 5, 7021, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape3.frame_b.t[1]", 1,\
 5, 7022, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape3.frame_b.t[2]", 1,\
 5, 7023, 132)
DeclareAlias2("drone.droneChassis2.bodyShape3.frameTranslation.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis2.bodyShape3.frame_b.t[3]", 1,\
 5, 7024, 132)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", -0.25, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.length", \
"Length of shape [m]", 0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.width", \
"Width of shape [m]", 0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.height", \
"Height of shape [m]", 0.0125, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.color[1]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.color[2]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.color[3]", \
"Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareState("drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 71, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.droneChassis2.bodyShape3.body.frame_a.der(r_0[1])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.frame_a.der(r_0[2])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[2]", 1, 1, 69, 4)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.frame_a.der(r_0[3])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[3]", 1, 1, 70, 4)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyShape3.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.r_CM[1]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 -0.175, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.r_CM[2]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.r_CM[3]", "Vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.m", "Mass of rigid body [kg]",\
 0.5, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_11", "Element (1,1) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_22", "Element (2,2) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_33", "Element (3,3) of inertia tensor [kg.m2]",\
 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_21", "Element (2,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_31", "Element (3,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I_32", "Element (3,2) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[1]", 1, 1, 68, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[2]", 1, 1, 69, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyShape3.v_0[3]", 1, 1, 70, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape3.body.a_0[1]", 1, 5, 7147, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape3.body.a_0[2]", 1, 5, 7148, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyShape3.body.a_0[3]", 1, 5, 7149, 0)
DeclareVariable("drone.droneChassis2.bodyShape3.body.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyShape3.body.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sphereDiameter", \
"Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sphereColor[1]", \
"Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sphereColor[2]", \
"Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sphereColor[3]", \
"Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.cylinderDiameter", \
"Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.cylinderColor[1]", \
"Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.cylinderColor[2]", \
"Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.cylinderColor[3]", \
"Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_angleStates[1]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_angleStates[2]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.sequence_angleStates[3]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[1, 1]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[1, 2]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[1, 3]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[2, 1]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[2, 2]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[2, 3]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[3, 1]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[3, 2]", "Inertia tensor [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.I[3, 3]", "Inertia tensor [kg.m2]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.T[3, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.R_start.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.w_a[1]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.w_a[2]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.w_a[3]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(w_a[1])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(w_a[2])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.der(w_a[3])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.z_a[1]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.z_a[2]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyShape3.body.z_a[3]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareVariable("drone.droneChassis2.bodyShape3.body.g_0[1]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.g_0[2]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.g_0[3]", "Gravity acceleration resolved in world frame [m/s2]",\
 -9.80665, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q[1]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q[2]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q[3]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.Q[4]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_start[1]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_start[2]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_start[3]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi[1]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi[2]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi[3]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_d[1]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_d[2]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_d[3]", "= der(phi) [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyShape3.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[1]", 1, 5, 7473, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[2]", 1, 5, 7474, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[3]", 1, 5, 7475, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.animation", "= true, if animation shall be enabled (show cylinder between frame_a and frame_b) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.r[1]", "Vector from frame_a to frame_b, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r[2]", "Vector from frame_a to frame_b, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r[3]", "Vector from frame_a to frame_b, resolved in frame_a [m]",\
 -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_shape[1]", "Vector from frame_a to cylinder origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_shape[2]", "Vector from frame_a to cylinder origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_shape[3]", "Vector from frame_a to cylinder origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.lengthDirection[1]", \
"Vector in length direction of cylinder, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.lengthDirection[2]", \
"Vector in length direction of cylinder, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.lengthDirection[3]", \
"Vector in length direction of cylinder, resolved in frame_a [1]", -0.25, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.length", "Length of cylinder [m]",\
 0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.diameter", "Diameter of cylinder [m]",\
 0.01, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.innerDiameter", \
"Inner diameter of cylinder (0 <= innerDiameter <= Diameter) [m]", 0, 0.0,1E+100,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.density", "Density of cylinder (e.g., steel: 7700 .. 7900, wood : 400 .. 800) [kg/m3|g/cm3]",\
 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.color[1]", "Color of cylinder [:#(type=Integer)]",\
 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.color[2]", "Color of cylinder [:#(type=Integer)]",\
 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.color[3]", "Color of cylinder [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyCylinder.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(r_0[1])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[1]", 1, 5, 7253, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(r_0[2])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[2]", 1, 5, 7254, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(r_0[3])", "der(Position vector from origin of world frame to origin of frame_a) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[3]", 1, 5, 7255, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(v_0[1])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[1]", 1, 5, 7335, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(v_0[2])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[2]", 1, 5, 7336, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.der(v_0[3])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[3]", 1, 5, 7337, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[1]", 1, 5, 7335, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[2]", 1, 5, 7336, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[3]", 1, 5, 7337, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.w_0_fixed", "= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.z_0_fixed", "= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_angleStates[1]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_angleStates[2]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.sequence_angleStates[3]", \
"Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.radius", "Radius of cylinder [m]",\
 0.005, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.innerRadius", "Inner-Radius of cylinder [m]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.mo", "Mass of cylinder without hole [kg]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.mi", "Mass of hole of cylinder [kg]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I22", "Inertia with respect to axis through center of mass, perpendicular to cylinder axis [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.m", "Mass of cylinder [kg]", \
0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 -1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_CM[1]", "Position vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_CM[2]", "Position vector from frame_a to center of mass, resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.r_CM[3]", "Position vector from frame_a to center of mass, resolved in frame_a [m]",\
 -0.125, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[1, 1]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[1, 2]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[1, 3]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[2, 1]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[2, 2]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[2, 3]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[3, 1]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[3, 2]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.I[3, 3]", "Inertia tensor of cylinder with respect to center of mass, resolved in frame parallel to frame_a [kg.m2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.der(r_0[1])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[1]", 1, 5, 7253, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.der(r_0[2])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[2]", 1, 5, 7254, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.frame_a.der(r_0[3])", \
"der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[3]", 1, 5, 7255, 4)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", -0.125, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.m", "Mass of rigid body [kg]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_11", "Element (1,1) of inertia tensor [kg.m2]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_22", "Element (2,2) of inertia tensor [kg.m2]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_33", "Element (3,3) of inertia tensor [kg.m2]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_21", "Element (2,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_31", "Element (3,1) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I_32", "Element (3,2) of inertia tensor [kg.m2]",\
 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.r_0[1]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.r_0[2]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.r_0[3]", "Position vector from origin of world frame to origin of frame_a [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[1]", 1, 5, 7253, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[2]", 1, 5, 7254, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 "drone.droneChassis2.bodyCylinder.v_0[3]", 1, 5, 7255, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[1]", 1, 5, 7335, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[2]", 1, 5, 7336, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.bodyCylinder.body.a_0[3]", 1, 5, 7337, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.angles_start[1]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.angles_start[2]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.angles_start[3]", \
"Initial values of angles to rotate world frame around 'sequence_start' axes into frame_a [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_start[1]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_start[2]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_start[3]", \
"Sequence of rotations to rotate world frame into frame_a at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sphereDiameter", \
"Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sphereColor[1]", \
"Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sphereColor[2]", \
"Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sphereColor[3]", \
"Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.cylinderDiameter", \
"Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.cylinderColor[1]", \
"Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.cylinderColor[2]", \
"Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.cylinderColor[3]", \
"Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[1, 1]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[1, 2]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[1, 3]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[2, 1]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[2, 2]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[2, 3]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[3, 1]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[3, 2]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.I[3, 3]", \
"Inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.T[3, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.R_start.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.w_a[1]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.w_a[2]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.w_a[3]", "Absolute angular velocity of frame_a resolved in frame_a [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(w_a[1])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(w_a[2])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.der(w_a[3])", \
"der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", \
"drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.z_a[1]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[1])", 1, 5, 6581, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.z_a[2]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[2])", 1, 5, 6582, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.body.z_a[3]", "Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]",\
 "drone.droneChassis2.bodyShape.body.der(w_a[3])", 1, 5, 6583, 0)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.g_0[1]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.g_0[2]", "Gravity acceleration resolved in world frame [m/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.g_0[3]", "Gravity acceleration resolved in world frame [m/s2]",\
 -9.80665, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q[1]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q[2]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q[3]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.Q[4]", "Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_start[1]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_start[2]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_start[3]", \
"Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi[1]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi[2]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi[3]", "Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_d[1]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_d[2]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_d[3]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.bodyCylinder.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[1]", -1,\
 5, 7229, 132)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[2]", -1,\
 5, 7230, 132)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[3]", -1,\
 5, 7231, 132)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[1]", 1, 5, 7473, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[2]", 1, 5, 7474, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[3]", 1, 5, 7475, 4)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[1]", 1,\
 5, 7229, 132)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[2]", 1,\
 5, 7230, 132)
DeclareAlias2("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis2.bodyCylinder.frame_b.f[3]", 1,\
 5, 7231, 132)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", -0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", -0.25, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.length", \
"Length of shape [m]", 0.25, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.width", \
"Width of shape [m]", 0.01, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.height", \
"Height of shape [m]", 0.01, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape) [1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.bodyCylinder.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[1]", 1, 5, 7473, 4)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[2]", 1, 5, 7474, 4)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.pointMass.r_0[3]", 1, 5, 7475, 4)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis2.bodyCylinder.frame_b.f[1]", -1, 5, 7229, 132)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis2.bodyCylinder.frame_b.f[2]", -1, 5, 7230, 132)
DeclareAlias2("drone.droneChassis2.pointMass.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis2.bodyCylinder.frame_b.f[3]", -1, 5, 7231, 132)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.pointMass.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.pointMass.animation", "= true, if animation shall be enabled (show sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.pointMass.m", "Mass of mass point [kg]", \
0.5, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.pointMass.sphereDiameter", "Diameter of sphere [m]",\
 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.pointMass.sphereColor[1]", "Color of sphere [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.pointMass.sphereColor[2]", "Color of sphere [:#(type=Integer)]",\
 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.pointMass.sphereColor[3]", "Color of sphere [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.pointMass.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.pointMass.stateSelect", "Priority to use frame_a.r_0, v_0 (= der(frame_a.r_0)) as states [:#(type=StateSelect)]",\
 2, 1.0,5.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.pointMass.r_0[1]", "Position vector from origin of world frame to origin of frame_a, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.r_0[2]", "Position vector from origin of world frame to origin of frame_a, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.r_0[3]", "Position vector from origin of world frame to origin of frame_a, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.pointMass.der(r_0[1])", "der(Position vector from origin of world frame to origin of frame_a, resolved in world frame) [m/s]",\
 "drone.droneChassis2.pointMass.v_0[1]", 1, 5, 7476, 0)
DeclareAlias2("drone.droneChassis2.pointMass.der(r_0[2])", "der(Position vector from origin of world frame to origin of frame_a, resolved in world frame) [m/s]",\
 "drone.droneChassis2.pointMass.v_0[2]", 1, 5, 7477, 0)
DeclareAlias2("drone.droneChassis2.pointMass.der(r_0[3])", "der(Position vector from origin of world frame to origin of frame_a, resolved in world frame) [m/s]",\
 "drone.droneChassis2.pointMass.v_0[3]", 1, 5, 7478, 0)
DeclareVariable("drone.droneChassis2.pointMass.v_0[1]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.v_0[2]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.v_0[3]", "Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.pointMass.der(v_0[1])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.pointMass.a_0[1]", 1, 5, 7479, 0)
DeclareAlias2("drone.droneChassis2.pointMass.der(v_0[2])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.pointMass.a_0[2]", 1, 5, 7480, 0)
DeclareAlias2("drone.droneChassis2.pointMass.der(v_0[3])", "der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis2.pointMass.a_0[3]", 1, 5, 7481, 0)
DeclareVariable("drone.droneChassis2.pointMass.a_0[1]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.a_0[2]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.pointMass.a_0[3]", "Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.frame_a.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[1]", 1, 5, 6628, 4)
DeclareAlias2("drone.droneChassis2.frame_a.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[2]", 1, 5, 6629, 4)
DeclareAlias2("drone.droneChassis2.frame_a.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[3]", 1, 5, 6630, 4)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.frame_a.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power1.Airframe.f[1]", -1, 5, 3071, 132)
DeclareAlias2("drone.droneChassis2.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power1.Airframe.f[2]", -1, 5, 3072, 132)
DeclareAlias2("drone.droneChassis2.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power1.Airframe.f[3]", -1, 5, 3073, 132)
DeclareAlias2("drone.droneChassis2.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power1.Airframe.t[1]", -1, 5, 3074, 132)
DeclareAlias2("drone.droneChassis2.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power1.Airframe.t[2]", -1, 5, 3075, 132)
DeclareAlias2("drone.droneChassis2.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power1.Airframe.t[3]", -1, 5, 3076, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[1]", 1, 5, 6417, 4)
DeclareAlias2("drone.droneChassis2.frame_a1.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[2]", 1, 5, 6418, 4)
DeclareAlias2("drone.droneChassis2.frame_a1.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[3]", 1, 5, 6419, 4)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.frame_a1.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power.Airframe.f[1]", -1, 5, 1439, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power.Airframe.f[2]", -1, 5, 1440, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power.Airframe.f[3]", -1, 5, 1441, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power.Airframe.t[1]", -1, 5, 1442, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power.Airframe.t[2]", -1, 5, 1443, 132)
DeclareAlias2("drone.droneChassis2.frame_a1.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power.Airframe.t[3]", -1, 5, 1444, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 4)
DeclareAlias2("drone.droneChassis2.frame_a2.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 4)
DeclareAlias2("drone.droneChassis2.frame_a2.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 4)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.frame_a2.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[1]", -1, 5, 4268, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[2]", -1, 5, 4269, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power2.Airframe.f[3]", -1, 5, 4270, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[1]", -1, 5, 4271, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[2]", -1, 5, 4272, 132)
DeclareAlias2("drone.droneChassis2.frame_a2.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power2.Airframe.t[3]", -1, 5, 4273, 132)
DeclareAlias2("drone.droneChassis2.frame_a3.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 4)
DeclareAlias2("drone.droneChassis2.frame_a3.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 4)
DeclareAlias2("drone.droneChassis2.frame_a3.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 4)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareAlias2("drone.droneChassis2.frame_a3.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.rotor3_1.revolute.frame_a.f[1]", -1, 5, 5208,\
 132)
DeclareAlias2("drone.droneChassis2.frame_a3.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.rotor3_1.revolute.frame_a.f[2]", -1, 5, 5209,\
 132)
DeclareAlias2("drone.droneChassis2.frame_a3.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine_Power3.Airframe.f[3]", -1, 5, 5467, 132)
DeclareAlias2("drone.droneChassis2.frame_a3.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[1]", -1, 5, 5468, 132)
DeclareAlias2("drone.droneChassis2.frame_a3.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[2]", -1, 5, 5469, 132)
DeclareAlias2("drone.droneChassis2.frame_a3.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine_Power3.Airframe.t[3]", -1, 5, 5470, 132)
DeclareAlias2("drone.droneChassis2.frame_a4.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.frame_a4.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.frame_a4.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.droneChassis2.frame_a4.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.droneChassis2.frame_a4.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.frame_a4.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.frame_a4.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.frame_a4.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.frame_a4.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.frame_a4.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.length", "Length of cylinder [m]", 0.25, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.m", "Mass of rigid body [kg]", 0.5, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.fixedShape.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", 1,\
 5, 7614, 0)
DeclareAlias2("drone.droneChassis2.fixedShape.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", 1,\
 5, 7615, 0)
DeclareAlias2("drone.droneChassis2.fixedShape.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", 1,\
 5, 7616, 0)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.droneChassis2.fixedShape.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.w[2]", 1, 5, 7621, 0)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedShape.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.fixedShape.r_shape[1]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.r_shape[2]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.r_shape[3]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.lengthDirection[1]", \
"Vector in length direction of shape, resolved in frame_a [1|1]", 1, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedShape.lengthDirection[2]", \
"Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedShape.lengthDirection[3]", \
"Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedShape.widthDirection[1]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.widthDirection[2]", \
"Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.widthDirection[3]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.length", "Length of shape [m]", \
0.001025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.width", "Width of shape [m]", \
0.001025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.height", "Height of shape [m]", \
0.001025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.color[1]", "Color of shape [:#(type=Integer)]",\
 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedShape.color[2]", "Color of shape [:#(type=Integer)]",\
 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedShape.color[3]", "Color of shape [:#(type=Integer)]",\
 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedShape.extra", "Additional data for cylinder, cone, pipe, gearwheel and spring",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedShape.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[1]", 1, 5, 7490, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[2]", 1, 5, 7491, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[3]", 1, 5, 7492, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", 1,\
 5, 7614, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", 1,\
 5, 7615, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", 1,\
 5, 7616, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 1]", 1,\
 5, 7617, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 2]", 1,\
 5, 7618, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 3]", 1,\
 5, 7619, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.fixedRotation1.frame_a.R.w[2]", 1, 5, 7621, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.fixedRotation1.frame_a.R.w[3]", 1, 5, 7622, 0)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.fixedRotation.r[1]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 -0.27, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.r[2]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.r[3]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 -0.2, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.rotationType", \
"Type of rotation description [:#(type=Modelica.Mechanics.MultiBody.Types.RotationTypes)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.n[1]", "Axis of rotation in frame_a (= same as in frame_b) [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n[2]", "Axis of rotation in frame_a (= same as in frame_b) [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n[3]", "Axis of rotation in frame_a (= same as in frame_b) [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.angle", "Angle to rotate frame_a around axis n into frame_b [deg]",\
 90, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_x[1]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_x[2]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_x[3]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_y[1]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_y[2]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.n_y[3]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.sequence[1]", \
"Sequence of rotations [:#(type=Integer)]", 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.sequence[2]", \
"Sequence of rotations [:#(type=Integer)]", 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.sequence[3]", \
"Sequence of rotations [:#(type=Integer)]", 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.angles[1]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.angles[2]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.angles[3]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.r_shape[1]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.r_shape[2]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.r_shape[3]", "Vector from frame_a to shape origin, resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.lengthDirection[1]", \
"Vector in length direction of shape, resolved in frame_a [1]", -0.27, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.lengthDirection[2]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.lengthDirection[3]", \
"Vector in length direction of shape, resolved in frame_a [1]", -0.2, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.widthDirection[1]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.widthDirection[2]", \
"Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.widthDirection[3]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.length", "Length of shape [m]",\
 0.3360059523282289, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.width", "Width of shape [m]",\
 0.016800297616411445, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.height", "Height of shape [m]",\
 0.016800297616411445, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.extra", "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.color[1]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.color[2]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.color[3]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[2, 2]", \
"Transformation matrix from world frame to local frame", 6.123233995736766E-17, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[2, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[3, 2]", \
"Transformation matrix from world frame to local frame", -1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.T[3, 3]", \
"Transformation matrix from world frame to local frame", 6.123233995736766E-17, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[2, 2]", \
"Transformation matrix from world frame to local frame", 6.123233995736766E-17, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[2, 3]", \
"Transformation matrix from world frame to local frame", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[3, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.T[3, 3]", \
"Transformation matrix from world frame to local frame", 6.123233995736766E-17, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation.R_rel_inv.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[1]", 1, 5, 7490, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[2]", 1, 5, 7491, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[3]", 1, 5, 7492, 4)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[1]", 1, 5, 7490, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[2]", 1, 5, 7491, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[3]", 1, 5, 7492, 4)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[1, 1]", 1,\
 5, 7493, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[1, 2]", 1,\
 5, 7494, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[1, 3]", 1,\
 5, 7495, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", 1,\
 5, 7614, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", 1,\
 5, 7615, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", 1,\
 5, 7616, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[3, 1]", 1,\
 5, 7496, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[3, 2]", 1,\
 5, 7497, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.fixedShape.frame_a.R.T[3, 3]", 1,\
 5, 7498, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.fixedShape.frame_a.R.w[1]", 1, 5, 7499, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.fixedRotation1.frame_a.R.w[2]", 1, 5, 7621, 0)
DeclareAlias2("drone.droneChassis2.fixedRotation1.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.fixedShape.frame_a.R.w[3]", 1, 5, 7500, 0)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.droneChassis2.fixedRotation1.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.droneChassis2.fixedRotation1.r[1]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.r[2]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.r[3]", "Vector from frame_a to frame_b resolved in frame_a [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.rotationType", \
"Type of rotation description [:#(type=Modelica.Mechanics.MultiBody.Types.RotationTypes)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.n[1]", "Axis of rotation in frame_a (= same as in frame_b) [1|1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n[2]", "Axis of rotation in frame_a (= same as in frame_b) [1|1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n[3]", "Axis of rotation in frame_a (= same as in frame_b) [1|1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.angle", "Angle to rotate frame_a around axis n into frame_b [deg]",\
 45, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_x[1]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_x[2]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_x[3]", "Vector along x-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_y[1]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_y[2]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.n_y[3]", "Vector along y-axis of frame_b resolved in frame_a [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.sequence[1]", \
"Sequence of rotations [:#(type=Integer)]", 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.sequence[2]", \
"Sequence of rotations [:#(type=Integer)]", 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.sequence[3]", \
"Sequence of rotations [:#(type=Integer)]", 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.angles[1]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.angles[2]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.angles[3]", "Rotation angles around the axes defined in 'sequence' [deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.lengthDirection[1]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.lengthDirection[2]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.lengthDirection[3]", \
"Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.widthDirection[1]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.widthDirection[2]", \
"Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.widthDirection[3]", \
"Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.length", "Length of shape [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.width", "Width of shape [m]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.height", "Height of shape [m]",\
 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.extra", "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.color[1]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.color[2]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.color[3]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.droneChassis2.fixedRotation1.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[1, 3]", \
"Transformation matrix from world frame to local frame", -0.7071067811865476, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[3, 1]", \
"Transformation matrix from world frame to local frame", -0.7071067811865476, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.7071067811865476, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedRotation1.R_rel_inv.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 7450, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 7451, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 7452, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 7453, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 7454, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 7455, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.accelerometer.relativeAngles.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.relativeAngles.angles[1]", "Angles to rotate frame_a into frame_b via 'sequence' [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.angles[2]", "Angles to rotate frame_a into frame_b via 'sequence' [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.angles[3]", "Angles to rotate frame_a into frame_b via 'sequence' [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.sequence[1]", \
"Angles are returned to rotate frame_a around axes sequence[1], sequence[2] and finally sequence[3] into frame_b [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.accelerometer.relativeAngles.sequence[2]", \
"Angles are returned to rotate frame_a around axes sequence[1], sequence[2] and finally sequence[3] into frame_b [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.accelerometer.relativeAngles.sequence[3]", \
"Angles are returned to rotate frame_a around axes sequence[1], sequence[2] and finally sequence[3] into frame_b [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.accelerometer.relativeAngles.guessAngle1", \
"Select angles[1] such that abs(angles[1] - guessAngle1) is a minimum [rad|deg]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.T[3, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.accelerometer.relativeAngles.R_rel.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.accelerometer.frame_a.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[1]", 1, 5, 2544, 4)
DeclareAlias2("drone.accelerometer.frame_a.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[2]", 1, 5, 2545, 4)
DeclareAlias2("drone.accelerometer.frame_a.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.gPS.relativePosition.relativePosition.frame_b.r_0[3]", 1, 5, 2546, 4)
DeclareAlias2("drone.accelerometer.frame_a.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 1]", 1, 5, 7450, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 2]", 1, 5, 7451, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[1, 3]", 1, 5, 7452, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 1]", 1, 5, 7453, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 2]", 1, 5, 7454, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[2, 3]", 1, 5, 7455, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1, 5, 7456, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1, 5, 7457, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1, 5, 7458, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[1]", 1, 5, 7459, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[2]", 1, 5, 7460, 0)
DeclareAlias2("drone.accelerometer.frame_a.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.pointMass.frame_a.R.w[3]", 1, 5, 7461, 0)
DeclareVariable("drone.accelerometer.frame_a.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.frame_a.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.frame_a.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.frame_a.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.frame_a.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.frame_a.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.fixed.frame_b.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.fixed.frame_b.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.frame_b.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.f[3]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.frame_b.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.accelerometer.fixed.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.accelerometer.fixed.r[1]", "Position vector from world frame to frame_b, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.r[2]", "Position vector from world frame to frame_b, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.r[3]", "Position vector from world frame to frame_b, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.r_shape[1]", "Vector from world frame to shape origin, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.r_shape[2]", "Vector from world frame to shape origin, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.r_shape[3]", "Vector from world frame to shape origin, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.lengthDirection[1]", "Vector in length direction of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.lengthDirection[2]", "Vector in length direction of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.lengthDirection[3]", "Vector in length direction of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.widthDirection[1]", "Vector in width direction of shape, resolved in world frame [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.widthDirection[2]", "Vector in width direction of shape, resolved in world frame [1]",\
 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.widthDirection[3]", "Vector in width direction of shape, resolved in world frame [1]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.length", "Length of shape [m]", 0.0, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.width", "Width of shape [m]", 0.0, \
0.0,1E+100,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.height", "Height of shape [m]", 0.0, \
0.0,1E+100,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.extra", "Additional parameter for cone, pipe etc. (see docu of Visualizers.Advanced.Shape)",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.color[1]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.accelerometer.fixed.color[2]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.accelerometer.fixed.color[3]", "Color of shape [:#(type=Integer)]",\
 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.accelerometer.fixed.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,513)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r[1]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r[2]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r[3]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r_shape[1]", "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r_shape[2]", "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.r_shape[3]", "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.lengthDirection[1]", \
"Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.lengthDirection[2]", \
"Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.lengthDirection[3]", \
"Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.widthDirection[1]", \
"Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.widthDirection[2]", \
"Vector in width direction, resolved in object frame [1]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.widthDirection[3]", \
"Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.length", "Length of visual object [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.width", "Width of visual object [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.height", "Height of visual object [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.extra", "Additional size data for some of the shape types",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.color[1]", "Color of shape", 155,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.color[2]", "Color of shape", 155,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.color[3]", "Color of shape", 155,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.accelerometer.fixed.shape.isURI", "[:#(type=Boolean)]", \
false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.accelerometer.fixed.shape.abs_n_x", "[1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.n_z_aux[1]", "[1]", 0.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.n_z_aux[2]", "[1]", 0.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.n_z_aux[3]", "[1]", 1.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_x[1]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_x[2]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_x[3]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_y[1]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_y[2]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.e_y[3]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.accelerometer.fixed.shape.Form", "", 9.87103E+25, \
0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rxvisobj[1]", "x-axis unit vector of shape, resolved in world frame [1]",\
 1.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rxvisobj[2]", "x-axis unit vector of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rxvisobj[3]", "x-axis unit vector of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.ryvisobj[1]", "y-axis unit vector of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.ryvisobj[2]", "y-axis unit vector of shape, resolved in world frame [1]",\
 1.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.ryvisobj[3]", "y-axis unit vector of shape, resolved in world frame [1]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rvisobj[1]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rvisobj[2]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.rvisobj[3]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.size[1]", "{length,width,height} of shape [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.size[2]", "{length,width,height} of shape [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.size[3]", "{length,width,height} of shape [m]",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.Material", "", 6060606.0, \
0.0,0.0,0.0,0,3585)
DeclareVariable("drone.accelerometer.fixed.shape.Extra", "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.accelerometer.y[1]", "[rad]", "drone.accelerometer.relativeAngles.angles[1]", 1,\
 5, 7725, 0)
DeclareAlias2("drone.accelerometer.y[2]", "[rad]", "drone.accelerometer.relativeAngles.angles[2]", 1,\
 5, 7726, 0)
DeclareAlias2("drone.accelerometer.y[3]", "[rad]", "drone.accelerometer.relativeAngles.angles[3]", 1,\
 5, 7727, 0)
DeclareVariable("drone.realExtendMultiple.u", "", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.realExtendMultiple.y[1]", "", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.realExtendMultiple.y[2]", "", -0.25, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.realExtendMultiple.y[3]", "", "ramp1.y", 1, 5, 12, 0)
DeclareVariable("drone.realExtendMultiple.u1", "", -0.25, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.realExtendMultiple.u2", "", "ramp1.y", 1, 5, 12, 0)
DeclareVariable("drone.animation", "= true, if animation shall be enabled [:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.ramp.height", "Height of ramps", 2.5, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.ramp.duration", "Duration of ramp (= 0.0 gives a Step) [s]",\
 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.ramp.y", "Connector of Real output signal", 0.0, 0.0,0.0,\
0.0,0,512)
DeclareVariable("drone.ramp.offset", "Offset of output signal y", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.ramp.startTime", "Output y = offset for time < startTime [s]",\
 0, 0.0,0.0,0.0,0,513)
DeclareVariable("ramp2.height", "Height of ramps", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("ramp2.duration", "Duration of ramp (= 0.0 gives a Step) [s]", 5,\
 0.0,1E+100,0.0,0,513)
DeclareVariable("ramp2.y", "Connector of Real output signal", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("ramp2.offset", "Offset of output signal y", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("ramp2.startTime", "Output y = offset for time < startTime [s]",\
 20, 0.0,0.0,0.0,0,513)
DeclareAlias2("add1.u1", "Connector of Real input signal 1", "ramp1.y", 1, 5, 12,\
 0)
DeclareAlias2("add1.u2", "Connector of Real input signal 2", "uniformNoise.y", 1,\
 5, 17, 0)
DeclareVariable("add1.y", "Connector of Real output signal", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("add1.k1", "Gain of input signal 1", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("add1.k2", "Gain of input signal 2", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("const1.k", "Constant output value", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("const1.y", "Connector of Real output signal", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 1]", 1,\
 5, 1376, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 2]", 1,\
 5, 1377, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 3]", 1,\
 5, 1378, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 1379, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 1380, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 1381, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.w[1]", 1,\
 5, 1385, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.w[2]", 1,\
 5, 1386, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.w[3]", 1,\
 5, 1387, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[1]", 1, 5, 6417, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[2]", 1, 5, 6418, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape.r_0[3]", 1, 5, 6419, 1024)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.length", \
"Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.height", \
"Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.color[3]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.abs_n_x",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.n_z_aux[1]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.n_z_aux[3]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_x[1]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_x[2]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_x[3]", \
"Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_y[1]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_y[2]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.e_y[3]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 7456, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 7457, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 7458, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 1379, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 1380, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power.blades.fixedShape.vis.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 1381, 1536)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.size[1]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.size[2]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.size[3]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.Material",\
 "", 49996.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power.blades.fixedShape.vis.Extra", \
"", 1.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.gPS.relativePosition.zeroPosition.frame_resolve.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 1]", 1,\
 5, 3008, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 2]", 1,\
 5, 3009, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 3]", 1,\
 5, 3010, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 3011, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 3012, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 3013, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.w[1]", 1,\
 5, 3017, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.w[2]", 1,\
 5, 3018, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.w[3]", 1,\
 5, 3019, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[1]", 1, 5, 6628, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[2]", 1, 5, 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape1.r_0[3]", 1, 5, 6630, 1024)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.length",\
 "Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.height",\
 "Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.color[3]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.abs_n_x",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.n_z_aux[1]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.n_z_aux[3]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 7456, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 7457, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 7458, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 3011, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 3012, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power1.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 3013, 1536)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.size[1]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.size[2]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.size[3]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.Material",\
 "", 49996.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power1.blades.fixedShape.vis.Extra", \
"", 1.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 1]", 1,\
 5, 4205, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 2]", 1,\
 5, 4206, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 3]", 1,\
 5, 4207, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 4208, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 4209, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 4210, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.w[1]", 1,\
 5, 4214, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.w[2]", 1,\
 5, 4215, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.w[3]", 1,\
 5, 4216, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.r_0[1]", 1, 5, 6836, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[2]", 1, 1, 66, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape2.body.frame_a.r_0[3]", 1, 1, 67, 1024)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.length",\
 "Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.height",\
 "Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.color[3]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.abs_n_x",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.n_z_aux[1]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.n_z_aux[3]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 7456, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 7457, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 7458, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 4208, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 4209, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power2.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 4210, 1536)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.size[1]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.size[2]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.size[3]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.Material",\
 "", 49996.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power2.blades.fixedShape.vis.Extra", \
"", 1.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 1]", 1,\
 5, 5404, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 2]", 1,\
 5, 5405, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[1, 3]", 1,\
 5, 5406, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 5407, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 5408, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 5409, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 7456, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 7457, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 7458, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.w[1]", 1,\
 5, 5413, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.w[2]", 1,\
 5, 5414, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.w[3]", 1,\
 5, 5415, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.body.frame_a.r_0[1]", 1, 1, 71, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[2]", 1, 5, 7040, 1024)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.bodyShape3.r_0[3]", 1, 5, 7041, 1024)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.length",\
 "Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.height",\
 "Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.color[3]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.abs_n_x",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.n_z_aux[1]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.n_z_aux[3]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 7456, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 7457, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis2.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 7458, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 1]", 1,\
 5, 5407, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 2]", 1,\
 5, 5408, 1536)
DeclareAlias2("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine_Power3.rotor3_1.torque.basicWorldTorque.frame_b.R.T[2, 3]", 1,\
 5, 5409, 1536)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.size[1]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.size[2]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.size[3]",\
 "{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.Material",\
 "", 49996.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine_Power3.blades.fixedShape.vis.Extra", \
"", 1.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 1]", 1, 5, 7493, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 2]", 1, 5, 7494, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 3]", 1, 5, 7495, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", 1, 5, 7614, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", 1, 5, 7615, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", 1, 5, 7616, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[3, 1]", 1, 5, 7496, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[3, 2]", 1, 5, 7497, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[3, 3]", 1, 5, 7498, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.fixedShape.frame_a.R.w[1]", 1, 5, 7499, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.w[2]", 1, 5, 7621, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis2.fixedShape.frame_a.R.w[3]", 1, 5, 7500, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.r[1]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[1]", 1, 5, 7490, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.r[2]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[2]", 1, 5, 7491, 1024)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.r[3]", "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[3]", 1, 5, 7492, 1024)
DeclareVariable("drone.droneChassis2.fixedShape.vis.r_shape[1]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.r_shape[2]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.r_shape[3]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.lengthDirection[1]", \
"Vector in length direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.lengthDirection[2]", \
"Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.lengthDirection[3]", \
"Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.widthDirection[1]", \
"Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.widthDirection[2]", \
"Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.widthDirection[3]", \
"Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.length", "Length of visual object [m]",\
 0.001025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.width", "Width of visual object [m]",\
 0.001025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.height", "Height of visual object [m]",\
 0.001025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.extra", "Additional size data for some of the shape types",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.color[1]", "Color of shape",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.color[2]", "Color of shape",\
 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.color[3]", "Color of shape",\
 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", 0.7, 0.0,\
1E+100,0.0,0,2561)
DeclareVariable("drone.droneChassis2.fixedShape.vis.isURI", "[:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.droneChassis2.fixedShape.vis.abs_n_x", "[1]", 1.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.n_z_aux[1]", "[1]", 0.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.n_z_aux[2]", "[1]", 0.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.n_z_aux[3]", "[1]", 1.0, \
0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_x[1]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_x[2]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_x[3]", "Unit vector in lengthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_y[1]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_y[2]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.e_y[3]", "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.droneChassis2.fixedShape.vis.Form", "[:modelica://DroneSimulation/Images/9.stl]",\
 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rxvisobj[1]", "x-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 1]", 1, 5, 7493, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rxvisobj[2]", "x-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 2]", 1, 5, 7494, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rxvisobj[3]", "x-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedShape.frame_a.R.T[1, 3]", 1, 5, 7495, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.ryvisobj[1]", "y-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 1]", 1, 5, 7614, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.ryvisobj[2]", "y-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 2]", 1, 5, 7615, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.ryvisobj[3]", "y-axis unit vector of shape, resolved in world frame [1]",\
 "drone.droneChassis2.fixedRotation1.frame_a.R.T[2, 3]", 1, 5, 7616, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rvisobj[1]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[1]", 1, 5, 7490, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rvisobj[2]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[2]", 1, 5, 7491, 1536)
DeclareAlias2("drone.droneChassis2.fixedShape.vis.rvisobj[3]", "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis2.fixedShape.frame_a.r_0[3]", 1, 5, 7492, 1536)
DeclareVariable("drone.droneChassis2.fixedShape.vis.size[1]", "{length,width,height} of shape [m]",\
 0.001025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.droneChassis2.fixedShape.vis.size[2]", "{length,width,height} of shape [m]",\
 0.001025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.droneChassis2.fixedShape.vis.size[3]", "{length,width,height} of shape [m]",\
 0.001025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.droneChassis2.fixedShape.vis.Material", "", 49996.0, \
0.0,0.0,0.0,0,3585)
DeclareVariable("drone.droneChassis2.fixedShape.vis.Extra", "", 1.0, 0.0,0.0,0.0,\
0,3585)
DeclareOutput("CPUtime", "[s]", 0, 0.0, 0.0,0.0,0.0,0,512)
DeclareOutput("EventCounter", "", 1, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.sample_24", "drone.controlModule_Synchronous2_1.discreteTF4.sample2.u [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.sample_25", "drone.controlModule_Synchronous2_1.discreteTF4.sample1.u [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF4.feedback.u1", 1, 5, 2715, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF4.feedback.u2", 1, 5, 2716, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF4.feedback.y", 1,\
 5, 2717, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF4.hold1.u", 1, 5, 2737, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[1]", 1, 5, 2725,\
 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x[2]", 1, 5, 2726,\
 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.x1", 1,\
 5, 2729, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[1]", 1,\
 5, 2730, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[2]", 1,\
 5, 2731, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.xext[3]", 1,\
 5, 2732, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF4.transferFunction1.y", 1, 5, 2718,\
 64)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.sample_26", "drone.controlModule_Synchronous2_1.discreteTF1.sample2.u [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.sample_27", "drone.controlModule_Synchronous2_1.discreteTF1.sample1.u [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF1.feedback.u1", 1, 5, 2625, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF1.feedback.u2", 1, 5, 2626, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF1.feedback.y", 1,\
 5, 2627, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF1.hold1.u", 1, 5, 2647, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[1]", 1, 5, 2635,\
 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x[2]", 1, 5, 2636,\
 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.x1", 1,\
 5, 2639, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[1]", 1,\
 5, 2640, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[2]", 1,\
 5, 2641, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.xext[3]", 1,\
 5, 2642, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF1.transferFunction1.y", 1, 5, 2628,\
 64)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.sample_28", "drone.controlModule_Synchronous2_1.discreteTF5.sample2.u [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.sample_29", "drone.controlModule_Synchronous2_1.discreteTF5.sample1.u [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF5.feedback.u1", 1, 5, 2745, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF5.feedback.u2", 1, 5, 2746, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF5.feedback.y", 1,\
 5, 2747, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF5.hold1.u", 1, 5, 2767, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[1]", 1, 5, 2755,\
 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x[2]", 1, 5, 2756,\
 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.x1", 1,\
 5, 2759, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[1]", 1,\
 5, 2760, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[2]", 1,\
 5, 2761, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.xext[3]", 1,\
 5, 2762, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF5.transferFunction1.y", 1, 5, 2748,\
 64)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.sample_30", "drone.controlModule_Synchronous2_1.discreteTF2.sample2.u [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.sample_31", "drone.controlModule_Synchronous2_1.discreteTF2.sample1.u [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF2.feedback.u1", 1, 5, 2655, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF2.feedback.u2", 1, 5, 2656, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF2.feedback.y", 1,\
 5, 2657, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF2.hold1.u", 1, 5, 2677, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[1]", 1, 5, 2665,\
 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x[2]", 1, 5, 2666,\
 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.x1", 1,\
 5, 2669, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[1]", 1,\
 5, 2670, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[2]", 1,\
 5, 2671, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.xext[3]", 1,\
 5, 2672, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF2.transferFunction1.y", 1, 5, 2658,\
 64)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.sample_32", "drone.controlModule_Synchronous2_1.discreteTF6.sample2.u [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.sample_33", "drone.controlModule_Synchronous2_1.discreteTF6.sample1.u [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF6.feedback.u1", 1, 5, 2775, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF6.feedback.u2", 1, 5, 2776, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF6.feedback.y", 1,\
 5, 2777, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF6.hold1.u", 1, 5, 2797, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[1]", 1, 5, 2785,\
 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x[2]", 1, 5, 2786,\
 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.x1", 1,\
 5, 2789, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[1]", 1,\
 5, 2790, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[2]", 1,\
 5, 2791, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.xext[3]", 1,\
 5, 2792, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF6.transferFunction1.y", 1, 5, 2778,\
 64)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.sample_34", "drone.controlModule_Synchronous2_1.discreteTF3.sample2.u [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.sample_35", "drone.controlModule_Synchronous2_1.discreteTF3.sample1.u [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.feedback.u1",\
 "Commanded input [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF3.feedback.u1", 1, 5, 2685, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.feedback.u2",\
 "Feedback input [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", \
"drone.controlModule_Synchronous2_1.discreteTF3.feedback.u2", 1, 5, 2686, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF3.feedback.y", 1,\
 5, 2687, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF3.hold1.u", 1, 5, 2707, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[1]", 1, 5, 2695,\
 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x[2]", 1, 5, 2696,\
 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.x1", 1,\
 5, 2699, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[1]", 1,\
 5, 2700, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[2]", 1,\
 5, 2701, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.xext[3]", 1,\
 5, 2702, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous2_1.discreteTF3.transferFunction1.y", 1, 5, 2688,\
 64)
EndNonAlias(5)
PreNonAliasNew(6)
