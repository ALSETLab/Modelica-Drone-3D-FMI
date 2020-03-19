#include <moutil.c>
PreNonAliasDef(6)
PreNonAliasDef(7)
PreNonAliasDef(8)
PreNonAliasDef(9)
PreNonAliasDef(10)
StartNonAlias(5)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.frame_a.r_0[1]", 1, 1, 42, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.frame_a.r_0[2]", 1, 1, 43, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.frame_a.r_0[3]", 1, 1, 44, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.v_0[1]", 1, 1, 39, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.v_0[2]", 1, 1, 40, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.v_0[3]", 1, 1, 41, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[1]", 1, 5, 6186, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[2]", 1, 5, 6187, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[3]", 1, 5, 6188, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.angles_fixed",\
 "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.w_0_start[1]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.w_0_start[2]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.w_0_start[3]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_0_start[1]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_0_start[2]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_0_start[3]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sphereDiameter",\
 "Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sphereColor[1]",\
 "Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sphereColor[2]",\
 "Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sphereColor[3]",\
 "Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.cylinderDiameter",\
 "Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.cylinderColor[1]",\
 "Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.cylinderColor[2]",\
 "Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.cylinderColor[3]",\
 "Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.enforceStates",\
 "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.useQuaternions",\
 "= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[1, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[1, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[1, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[2, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[2, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[2, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[3, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[3, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.I[3, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.R_start.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a_start[1]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a_start[2]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a_start[3]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.w_a[1]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.frameTranslation.frame_a.R.w[1]", 1,\
 5, 6123, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.w_a[2]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.frameTranslation.frame_a.R.w[2]", 1,\
 5, 6124, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.w_a[3]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.blades.bodyShape5.frameTranslation.frame_a.R.w[3]", 1,\
 5, 6125, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[1])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[2])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[3])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a[1]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[1])", 1, 5, 6241, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a[2]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[2])", 1, 5, 6242, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.z_a[3]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape5.body.der(w_a[3])", 1, 5, 6243, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.g_0[1]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.g_0[2]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.g_0[3]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q[1]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q[2]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q[3]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.Q[4]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_start[1]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_start[2]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_start[3]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi[1]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 45, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi[1])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi[2]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 46, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi[2])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi[3]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 47, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi[3])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_d[1]", \
"= der(phi) [rad/s]", 48, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[1])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_d[2]", \
"= der(phi) [rad/s]", 49, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[2])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_d[3]", \
"= der(phi) [rad/s]", 50, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[3])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[1])", 1,\
 6, 48, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[2])", 1,\
 6, 49, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape5.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape5.body.der(phi_d[3])", 1,\
 6, 50, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.Blade.f[1]", -1,\
 5, 6051, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.Blade.f[2]", -1,\
 5, 6052, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.revolute.frame_a.f[3]", 1,\
 5, 5633, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[1]", -1,\
 5, 6053, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[2]", -1,\
 5, 6054, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[3]", -1,\
 5, 6055, 132)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.animation", \
"= true, if animation shall be enabled (show shape between frame_a and frame_b and optionally a sphere at the center of mass) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.animateSphere", \
"= true, if mass shall be animated as sphere provided animation=true [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 376, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 377, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 378, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.m", \
"Mass of rigid body [kg]", 379, 0.01, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 380, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 381, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 382, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 383, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 384, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 385, 0, -1E+60,1E+100,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(r_0[1])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[1]", 1, 5, 1529, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(r_0[2])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[2]", 1, 5, 1530, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(r_0[3])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[3]", 1, 5, 1531, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[1]", 1, 5, 1529, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[2]", 1, 5, 1530, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[3]", 1, 5, 1531, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[1]", 1, 5, 1624, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[2]", 1, 5, 1625, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[3]", 1, 5, 1626, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape2.body.a_0[1]", 1, 5, 1624, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape2.body.a_0[2]", 1, 5, 1625, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape2.body.a_0[3]", 1, 5, 1626, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 386, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 387, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 388, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 389, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 390, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 391, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 392, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 393, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 394, 0, \
0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.154, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.length", \
"Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.width", \
"Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.height", \
"Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 395, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sphereDiameter", \
"Diameter of sphere [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sphereColor[1]", \
"Color of sphere of mass [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sphereColor[2]", \
"Color of sphere of mass [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sphereColor[3]", \
"Color of sphere of mass [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 4)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[1]", 1, 5, 6258, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[2]", 1, 5, 6259, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine3.blades.bodyShape4.frame_b.r_0[3]", 1, 5, 6260, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.animation",\
 "= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,\
0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r[1]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r[2]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r[3]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r_shape[1]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r_shape[2]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.r_shape[3]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.154, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.length",\
 "Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.width",\
 "Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.height",\
 "Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.extra",\
 "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 396, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.color[1]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.color[2]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.color[3]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.der(r_0[1])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape2.v_0[1]", 1, 5, 1529, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.der(r_0[2])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape2.v_0[2]", 1, 5, 1530, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.der(r_0[3])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape2.v_0[3]", 1, 5, 1531, 4)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.Blade.f[1]", -1,\
 5, 6051, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.Blade.f[2]", -1,\
 5, 6052, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine3.rotor1.revolute.frame_a.f[3]", 1,\
 5, 5633, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[1]", -1,\
 5, 6053, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[2]", -1,\
 5, 6054, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine3.rotor1.Blade.t[3]", -1,\
 5, 6055, 132)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.m", \
"Mass of rigid body [kg]", 1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[1]", 1, 5, 1529, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[2]", 1, 5, 1530, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape2.v_0[3]", 1, 5, 1531, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[1]", 1, 5, 1624, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[2]", 1, 5, 1625, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape2.body.a_0[3]", 1, 5, 1626, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.angles_fixed",\
 "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.w_0_start[1]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.w_0_start[2]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.w_0_start[3]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_0_start[1]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_0_start[2]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_0_start[3]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sphereDiameter",\
 "Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sphereColor[1]",\
 "Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sphereColor[2]",\
 "Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sphereColor[3]",\
 "Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.cylinderDiameter",\
 "Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.cylinderColor[1]",\
 "Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.cylinderColor[2]",\
 "Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.cylinderColor[3]",\
 "Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.enforceStates",\
 "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.useQuaternions",\
 "= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[1, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[1, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[1, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[2, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[2, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[2, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[3, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[3, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.I[3, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.R_start.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a_start[1]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a_start[2]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a_start[3]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.w_a[1]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.w_a[2]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.w_a[3]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[1])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[2])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[3])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a[1]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[1])", 1, 5, 6423, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a[2]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[2])", 1, 5, 6424, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.z_a[3]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine3.blades.bodyShape4.body.der(w_a[3])", 1, 5, 6425, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.g_0[1]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.g_0[2]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.g_0[3]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q[1]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q[2]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q[3]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.Q[4]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_start[1]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_start[2]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_start[3]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi[1]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 51, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi[1])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi[2]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 52, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi[2])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi[3]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 53, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi[3])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_d[1]", \
"= der(phi) [rad/s]", 54, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[1])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_d[2]", \
"= der(phi) [rad/s]", 55, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[2])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_d[3]", \
"= der(phi) [rad/s]", 56, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[3])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[1])", 1,\
 6, 54, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[2])", 1,\
 6, 55, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.bodyShape4.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine3.blades.bodyShape4.body.der(phi_d[3])", 1,\
 6, 56, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine3.rotor1.Blade.f[1]", -1, 5, 6051, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine3.rotor1.Blade.f[2]", -1, 5, 6052, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine3.rotor1.revolute.frame_a.f[3]", 1, 5, 5633, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine3.rotor1.Blade.t[1]", -1, 5, 6053, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine3.rotor1.Blade.t[2]", -1, 5, 6054, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.Input.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine3.rotor1.Blade.t[3]", -1, 5, 6055, 132)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 4)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 0)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", -0.0085, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", -0.1, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", -1, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.length", \
"Length of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.width", \
"Width of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.height", \
"Height of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.extra", \
"Additional data for cylinder, cone, pipe, gearwheel and spring", 1, 0.0,0.0,0.0,\
0,513)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 5339, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 5340, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 5341, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 5348, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 5349, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 5350, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[1]", 1, 5, 1526, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[2]", 1, 5, 1527, 1024)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape2.r_0[3]", 1, 5, 1528, 1024)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.r_shape[1]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.r_shape[2]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.r_shape[3]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.length", \
"Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.height", \
"Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.color[1]", \
"Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.color[2]", \
"Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.color[3]", \
"Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.abs_n_x", \
"[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.n_z_aux[1]", \
"[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.n_z_aux[2]", \
"[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.n_z_aux[3]", \
"[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_x[1]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_x[2]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_x[3]", \
"Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_y[1]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_y[2]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.e_y[3]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.rxvisobj[1]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 2107, 1536)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.rxvisobj[2]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 2108, 1536)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.rxvisobj[3]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 2109, 1536)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.ryvisobj[1]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 5342, 1536)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.ryvisobj[2]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 5343, 1536)
DeclareAlias2("drone.propeller_DCMachine3.blades.fixedShape.vis.ryvisobj[3]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine3.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 5344, 1536)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.rvisobj[1]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.rvisobj[2]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.rvisobj[3]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.size[1]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.size[2]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.size[3]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.Material", "",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine3.blades.fixedShape.vis.Extra", "", \
1.0, 0.0,0.0,0.0,0,3585)
DeclareParameter("drone.propeller_DCMachine3.PropellerGain", "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise [1]",\
 397, 1, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine3.position", "", "drone.controlModule_Synchronous.y2", 1,\
 5, 973, 0)
DeclareParameter("drone.propeller_DCMachine3.VaNominal", "Nominal armature voltage for motor [V]",\
 398, 10, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine3.IaNominal", "Nominal armature current (>0..Motor, <0..Generator) for motor [A]",\
 399, 0.1, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.force[1]", \
"x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.force[2]", \
"x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.force[3]", \
"x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.resolveInFrame", \
"Frame in which input force is resolved (1: world, 2: frame_b, 3: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.force.N_to_m", \
"Force arrow scaling (length = force/N_to_m) [N/m]", 400, 10, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.diameter", \
"Diameter of force arrow [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.color[1]", \
"Color of arrow [:#(type=Integer)]", 244, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.color[2]", \
"Color of arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.color[3]", \
"Color of arrow [:#(type=Integer)]", 4, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.f_in_m[1]", \
"Force mapped from N to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.f_in_m[2]", \
"Force mapped from N to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.f_in_m[3]", \
"Force mapped from N to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.force[1]",\
 "x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.force[2]",\
 "x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.force[3]",\
 "x-, y-, z-coordinates of force resolved in frame defined by resolveInFrame [N]",\
 "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.basicWorldForce.resolveInFrame",\
 "Frame in which force is resolved (1: world, 2: frame_b, 3: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameB)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force.zeroPosition.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.force_out.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.force_out.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.position", "", \
"drone.controlModule_Synchronous.y3", 1, 5, 974, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.realExtend1.u", "[J]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", 1, 5, 6660,\
 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.realExtend1.y[1]", \
"[N.m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.realExtend1.y[2]", \
"[N.m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.realExtend1.y[3]", "[N.m]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", 1, 5, 6660,\
 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.gain1.k", \
"Gain value multiplied with input signal [1]", 1, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.gain1.u", "Input signal connector [N.m]",\
 "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.gain1.y", "Output signal connector [J]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", 1, 5, 6660,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.realExtend.u", "[N.m]", \
"drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.realExtend.y[1]", "[N]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.realExtend.y[2]", "[N]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.realExtend.y[3]", "[N]", \
"drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.k", "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise [1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.limiter.uMax", \
"Upper limits of input signals", 401, 100000000.0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.limiter.uMin", \
"Lower limits of input signals", 402, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.limiter.strict", \
"= true, if strict limits with noEvent(..) [:#(type=Boolean)]", false, 0.0,0.0,\
0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.limiter.homotopyType", \
"Simplified model for homotopy-based initialization [:#(type=Modelica.Blocks.Types.LimiterHomotopy)]",\
 2, 1.0,4.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.limiter.limitsAtInit", \
"Has no longer an effect and is only kept for backwards compatibility (the implementation uses now the homotopy operator) [:#(type=Boolean)]",\
 true, 0.0,0.0,0.0,0,515)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.limiter.u", \
"Connector of Real input signal", "drone.controlModule_Synchronous.y3", 1, 5, 974,\
 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.limiter.y", \
"Connector of Real output signal [V]", 0.0, 0.0,0.0,0.0,0,640)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.limiter.simplifiedExpr", \
"Simplified expression for homotopy-based initialization", "drone.controlModule_Synchronous.y3", 1,\
 5, 974, 1024)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[1]", 1,\
 5, 6697, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[2]", 1,\
 5, 6698, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[3]", 1,\
 5, 6699, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", -1,\
 5, 6660, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torque[1]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torque[2]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.torque[3]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", 1, 5, 6660,\
 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.resolveInFrame", \
"Frame in which input force is resolved (1: world, 2: frame_a, 3: frame_b, 4: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 3, 1.0,4.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.Nm_to_m", \
"Torque arrow scaling (length = torque/Nm_to_m) [N.m/m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torqueDiameter", \
"Diameter of torque arrow [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.connectionLineDiameter",\
 "Diameter of line connecting frame_a and frame_b [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torqueColor[1]", \
"Color of torque arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torqueColor[2]", \
"Color of torque arrow [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.torqueColor[3]", \
"Color of torque arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.connectionLineColor[1]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 255, 0.0,\
255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.connectionLineColor[2]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 255, 0.0,\
255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.connectionLineColor[3]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 0, 0.0,255.0,\
0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.t_in_m[1]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.t_in_m[2]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.t_in_m[3]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[1]", 1,\
 5, 6697, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[2]", 1,\
 5, 6698, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[3]", 1,\
 5, 6699, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", -1,\
 5, 6660, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[1]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[2]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.resolveInFrame",\
 "Frame in which torque is resolved (1: world, 2: frame_a, 3: frame_b, 4: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 3, 1.0,4.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.r_0[1]",\
 "Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.r_0[2]",\
 "Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.r_0[3]",\
 "Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.t_b_0[1]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.t_b_0[2]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.t_b_0[3]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque.zeroPosition.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_1.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_1.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_1.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_1.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_1.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_1.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", -1,\
 5, 6660, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torque_2.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torqueSensor.flange_a.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torqueSensor.flange_a.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torqueSensor.flange_b.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torqueSensor.flange_b.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.torqueSensor.tau", \
"Torque in flange flange_a and flange_b (tau = flange_a.tau = -flange_b.tau) as output signal [N.m]",\
 "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", \
"Fixed offset angle of housing [rad|deg]", 403, 0, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.fixed.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.fixed.flange.tau", \
"Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 132)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.TaOperational", \
"Operational armature temperature [K|degC]", 404, 293.15, 0.0,1E+100,300.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.VaNominal", \
"Nominal armature voltage [V]", 100, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.IaNominal", \
"Nominal armature current (>0..Motor, <0..Generator) [A]", 100, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.wNominal", \
"Nominal speed [rad/s|rev/min]", 149.22565104551515, 0.0,0.0,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.TaNominal", \
"Nominal armature temperature [K|degC]", 405, 293.15, 0.0,1E+100,300.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.Ra", \
"Armature resistance at TRef [Ohm]", 406, 0.05, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.TaRef", \
"Reference temperature of armature resistance [K|degC]", 407, 293.15, 0.0,1E+100,\
300.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.alpha20a", \
"Temperature coefficient of armature resistance [1/K]", 408, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.La", \
"Armature inductance [H]", 409, 0.0015, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.Jr", \
"Rotor's moment of inertia [kg.m2]", 410, 1, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.useSupport", \
"Enable / disable (=fixed stator) support [:#(type=Boolean)]", false, 0.0,0.0,\
0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.Js", \
"Stator's moment of inertia [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.useThermalPort", \
"Enable / disable (=fixed temperatures) thermal port [:#(type=Boolean)]", false,\
 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.PRef",\
 "Reference friction losses at wRef [W]", 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.wRef",\
 "Reference angular velocity that the PRef refer to [rad/s|rev/min]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.power_w",\
 "Exponent of friction torque w.r.t. angular velocity", 411, 2, 1E-60,1E+100,0.0,\
0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.tauRef",\
 "Reference friction torque at reference angular velocity [N.m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.linear",\
 "Linear angular velocity range with respect to reference angular velocity [1]",\
 0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.wLinear",\
 "Linear angular velocity range [rad/s]", 0.14922565104551516, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.frictionParameters.tauLinear",\
 "Torque corresponding with linear angular velocity range [N.m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.phiMechanical", \
"Mechanical angle of rotor against stator [rad|deg]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.der(phiMechanical)",\
 "der(Mechanical angle of rotor against stator) [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.wMechanical", \
"Mechanical angular velocity of rotor against stator [rad/s|rev/min]", 0.0, \
0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.tauElectrical", \
"Electromagnetic torque [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.tauShaft", \
"Shaft torque [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.flange.tau", \
"Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.flange_a.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.flange_a.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.flange_b.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.flange_b.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.J", \
"Moment of inertia [kg.m2]", 1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.stateSelect",\
 "Priority to use phi and w as states [:#(type=StateSelect)]", 3, 1.0,5.0,0.0,0,1541)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.phi", \
"Absolute rotation angle of component [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.der(phi)",\
 "der(Absolute rotation angle of component) [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.w", \
"Absolute angular velocity of component (= der(phi)) [rad/s]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.der(w)",\
 "der(Absolute angular velocity of component (= der(phi))) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaRotor.a", \
"Absolute angular acceleration of component (= der(w)) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.flange_a.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.flange_a.tau",\
 "Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.flange_b.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.flange_b.tau",\
 "Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.J", \
"Moment of inertia [kg.m2]", 1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.stateSelect",\
 "Priority to use phi and w as states [:#(type=StateSelect)]", 3, 1.0,5.0,0.0,0,1541)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.phi", \
"Absolute rotation angle of component [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.der(phi)",\
 "der(Absolute rotation angle of component) [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.w", \
"Absolute angular velocity of component (= der(phi)) [rad/s]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.der(w)",\
 "der(Absolute angular velocity of component (= der(phi))) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.inertiaStator.a", \
"Absolute angular acceleration of component (= der(w)) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", \
"Fixed offset angle of housing [rad|deg]", 412, 0, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.flange.tau", \
"Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.flange.tau",\
 "Cut torque in the flange [N.m]", 0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.support.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.support.tau",\
 "Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.phi", \
"Angle between shaft and support [rad|deg]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.der(phi)", \
"der(Angle between shaft and support) [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.tau", \
"Torque [N.m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.w", \
"Relative angular velocity of flange and support [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.PRef",\
 "Reference friction losses at wRef [W]", 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.wRef",\
 "Reference angular velocity that the PRef refer to [rad/s|rev/min]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.power_w",\
 "Exponent of friction torque w.r.t. angular velocity", 1E-60, 1E-60,1E+100,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.tauRef",\
 "Reference friction torque at reference angular velocity [N.m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.linear",\
 "Linear angular velocity range with respect to reference angular velocity", \
0.001, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.wLinear",\
 "Linear angular velocity range [rad/s]", 0.14922565104551516, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.frictionParameters.tauLinear",\
 "Torque corresponding with linear angular velocity range [N.m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.useHeatPort",\
 "=true, if heatPort is enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.heatPort.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.heatPort.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.friction.lossPower",\
 "Loss power leaving component via heatPort (> 0, if heat is flowing out of component) [W]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalSupport.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 1028)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalSupport.tau",\
 "Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.m", \
"Number of phases (1 for DC, 3 for induction machines) [:#(type=Integer)]", 1, \
0.0,0.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.PRef",\
 "Reference core losses at reference inner voltage VRef [W]", 0, 0.0,1E+100,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.VRef",\
 "Reference inner RMS voltage that reference core losses PRef refer to [V]", \
1E-60, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.wRef",\
 "Reference angular velocity that reference core losses PRef refer to [rad/s]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.ratioHysteresis",\
 "Ratio of hysteresis losses with respect to the total core losses at VRef and fRef",\
 0, 0.0,1.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.GcRef",\
 "Reference conductance at reference frequency and voltage [S]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.coreParameters.wMin",\
 "[rad/s]", 0.00014922565104551514, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoadParameters.PRef",\
 "Reference stray load losses at IRef and wRef [W]", 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoadParameters.IRef",\
 "Reference RMS current that PRef refers to [A]", 1E-60, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoadParameters.wRef",\
 "Reference angular velocity that PRef refers to [rad/s|rev/min]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoadParameters.power_w",\
 "Exponent of stray load loss torque w.r.t. angular velocity", 413, 1, 1E-60,\
1E+100,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoadParameters.tauRef",\
 "Reference stray load torque at reference angular velocity and reference current [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brushParameters.V", \
"Total voltage drop of brushes for currents > ILinear [V]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brushParameters.ILinear",\
 "Current indicating linear voltage region of brush voltage drop [A]", 0.01, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.powerArmature",\
 "Electrical armature power [W]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.powerMechanical",\
 "Mechanical power [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.powerInertiaStator",\
 "Stator inertia power [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.powerInertiaRotor",\
 "Rotor inertia power [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal",\
 "Total loss power [W]", 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerArmature",\
 "Armature copper losses [W]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1,\
 5, 6764, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerCore",\
 "Core losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerStrayLoad",\
 "Stray load losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerFriction",\
 "Friction losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerBrush",\
 "Brush losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerPermanentMagnet",\
 "Permanent magnet losses [W]", 0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.va", "Armature voltage [V]",\
 "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1, 5, 6580, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ia", "Armature current [A]",\
 "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1, 1, 57, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.pin_ap.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1,\
 5, 6580, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.pin_ap.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.pin_an.v", \
"Potential at the pin [V]", 0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.pin_an.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.R", \
"Resistance at temperature T_ref [Ohm]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.T_ref", \
"Reference temperature [K|degC]", 288.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.alpha", \
"Temperature coefficient of resistance (R_actual = R*(1 + alpha*(T_heatPort - T_ref)) [1/K]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.i", \
"Current flowing from pin p to pin n [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.p.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1,\
 5, 6580, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.p.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.useHeatPort", \
"=true, if heatPort is enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.T", \
"Fixed device temperature if useHeatPort = false [K|degC]", 288.15, 0.0,1E+100,\
300.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.heatPort.T", \
"Port temperature [K|degC]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.heatPort.Q_flow", \
"Heat flow rate (positive if flowing from outside into the component) [W]", \
"drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", -1, 5,\
 6764, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.LossPower", \
"Loss power leaving component via heatPort [W]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1,\
 5, 6764, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.T_heatPort", \
"Temperature of heatPort [K|degC]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.R_actual", \
"Actual resistance = R*(1 + alpha*(T_heatPort - T_ref)) [Ohm]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.v", 1,\
 5, 6775, 0)
DeclareState("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", "Current flowing from pin p to pin n [A]",\
 57, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.der(i)", \
"der(Current flowing from pin p to pin n) [A/s]", 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.p.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.v", 1,\
 5, 6775, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.p.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.n.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.L", \
"Inductance [H]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.quasiStationary",\
 "No electrical transients if true [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", 0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.i", \
"Current flowing from pin p to pin n [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.p.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.p.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.n.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.brushParameters.V",\
 "Total voltage drop of brushes for currents > ILinear [V]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.brushParameters.ILinear",\
 "Current indicating linear voltage region of brush voltage drop [A]", 0.01, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.useHeatPort", \
"=true, if heatPort is enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.heatPort.T", \
"Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.heatPort.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.brush.lossPower", \
"Loss power leaving component via heatPort (> 0, if heat is flowing out of component) [W]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.v", 1,\
 5, 6775, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.i", \
"Current flowing from pin p to pin n [A]", 0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.p.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.ra.n.v", 1,\
 5, 6775, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.p.i", \
"Current flowing into the pin [A]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.n.i", \
"Current flowing into the pin [A]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.m",\
 "Number of phases (1 for DC, 3 for induction machines) [:#(type=Integer)]", 1, \
0.0,0.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.PRef",\
 "Reference core losses at reference inner voltage VRef [W]", 0, 0.0,1E+100,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.VRef",\
 "Reference inner RMS voltage that reference core losses PRef refer to [V]", \
1E-60, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.wRef",\
 "Reference angular velocity that reference core losses PRef refer to [rad/s]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.ratioHysteresis",\
 "Ratio of hysteresis losses with respect to the total core losses at VRef and fRef",\
 0.0, 0.0,1.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.GcRef",\
 "Reference conductance at reference frequency and voltage [S]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.coreParameters.wMin",\
 "[rad/s]", 0.00014922565104551514, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.useHeatPort", \
"=true, if heatPort is enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.heatPort.T", \
"Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.heatPort.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.lossPower", \
"Loss power leaving component via heatPort (> 0, if heat is flowing out of component) [W]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.w", \
"Remagnetization angular velocity [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.Gc", \
"Variable core loss conductance [S]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.core.wLimit", \
"Limited angular velocity [rad/s]", 0.00014922565104551514, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", 0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.i", \
"Current flowing from pin p to pin n [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.p.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1,\
 5, 6580, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.p.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.n.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1,\
 5, 6580, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.n.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.flange.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.flange.tau",\
 "Cut torque in the flange [N.m]", 0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.support.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.support.tau",\
 "Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.phi", \
"Angle between shaft and support [rad|deg]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.der(phi)",\
 "der(Angle between shaft and support) [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.tau", \
"Torque [N.m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.w", \
"Relative angular velocity of flange and support [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.strayLoadParameters.PRef",\
 "Reference stray load losses at IRef and wRef [W]", 0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.strayLoadParameters.IRef",\
 "Reference RMS current that PRef refers to [A]", 1E-60, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.strayLoadParameters.wRef",\
 "Reference angular velocity that PRef refers to [rad/s|rev/min]", \
149.22565104551515, 1E-60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.strayLoadParameters.power_w",\
 "Exponent of stray load loss torque w.r.t. angular velocity", 1E-60, 1E-60,\
1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.strayLoadParameters.tauRef",\
 "Reference stray load torque at reference angular velocity and reference current [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.useHeatPort",\
 "=true, if heatPort is enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.heatPort.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.heatPort.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.strayLoad.lossPower",\
 "Loss power leaving component via heatPort (> 0, if heat is flowing out of component) [W]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.useTemperatureInputs",\
 "If true, temperature inputs are used; else, temperatures are constant [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.TDefault",\
 "Default temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Ta", \
"Temperature of armature [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowArmature",\
 "Heat flow rate of armature [W]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1,\
 5, 6764, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowCore",\
 "Heat flow rate of core losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowStrayLoad",\
 "Heat flow rate of stray load losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowFriction",\
 "Heat flow rate of friction losses [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowBrush",\
 "Heat flow rate of brushes [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortArmature.T",\
 "Port temperature [K|degC]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortArmature.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", \
"drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1, 5, 6764,\
 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortCore.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortCore.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortStrayLoad.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortStrayLoad.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortFriction.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortFriction.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortBrush.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortBrush.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortPermanentMagnet.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.thermalPort.heatPortPermanentMagnet.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureArmature.port.T",\
 "Port temperature [K|degC]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureArmature.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", \
"drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1, 5, 6764,\
 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureArmature.T",\
 "[K]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureCore.T",\
 "Fixed temperature at port [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureCore.port.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureCore.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureStrayLoad.T",\
 "Fixed temperature at port [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureStrayLoad.port.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureStrayLoad.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureFriction.T",\
 "Fixed temperature at port [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureFriction.port.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureFriction.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k",\
 "Constant output value [K]", 1, 0.0,1E+100,300.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.y",\
 "Connector of Real output signal [K]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureBrush.T",\
 "Fixed temperature at port [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureBrush.port.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperatureBrush.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Tpm",\
 "Temperature of permanent magnet [K|degC]", 293.15, 0.0,1E+100,300.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowPermanentMagnet",\
 "Heat flow rate of permanent magnets [W]", 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.Q_flowTotal",\
 "[W]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.powerBalance.lossPowerTotal", 1,\
 5, 6764, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperaturePermanentMagnet.port.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperaturePermanentMagnet.port.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.temperaturePermanentMagnet.T",\
 "[K]", 293.15, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTpm.k",\
 "Constant output value [K]", 293.15, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTpm.y",\
 "Connector of Real output signal [K]", 293.15, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.pi", "", \
3.141592653589793, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.quasiStationary", \
"No electrical transients if true [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ViNominal", \
"Nominal induced Voltage [V]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.psi_eNominal", \
"Nominal magnetic flux [Wb]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.turnsRatio", \
"Ratio of armature turns over number of turns of the excitation winding [rad-1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortArmature.T",\
 "Port temperature [K|degC]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.thermalAmbient.constTa.k", 1,\
 5, 6851, 1028)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortArmature.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortCore.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortCore.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortStrayLoad.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortStrayLoad.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortFriction.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortFriction.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortBrush.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortBrush.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortPermanentMagnet.T",\
 "Port temperature [K|degC]", 293.15, 0.0,1E+100,300.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.internalThermalPort.heatPortPermanentMagnet.Q_flow",\
 "Heat flow rate (positive if flowing from outside into the component) [W]", 0.0,\
 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.TpmOperational", \
"Operational temperature of permanent magnet [K|degC]", 293.15, 0.0,1E+100,300.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.quasiStationary",\
 "No electrical transients if true [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.turnsRatio",\
 "Ratio of armature turns over number of turns of the excitation winding [rad-1]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.w", \
"Angular velocity [rad/s]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.vei", \
"Voltage drop across field excitation inductance [V]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.ie", \
"Excitation current [A]", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.psi_e", \
"Excitation flux [Wb]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.der(psi_e)",\
 "der(Excitation flux) [V]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.vai", \
"Induced armature voltage [V]", 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.ia", \
"Armature current [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1, 1,\
 57, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.tauElectrical",\
 "[N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.fixed.phi0", 1,\
 7, 403, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.flange.der(phi)",\
 "der(Absolute rotation angle of flange) [rad/s]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.flange.tau", \
"Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", 1,\
 5, 6567, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.support.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.fixed.phi0", 1,\
 7, 412, 4)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.support.der(phi)",\
 "der(Absolute rotation angle of flange) [rad/s]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.support.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1,\
 5, 6567, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_ap.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_ap.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_ep.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_ep.i", \
"Current flowing into the pin [A]", 1.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_an.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_an.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_en.v", \
"Potential at the pin [V]", 0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.pin_en.i", \
"Current flowing into the pin [A]", -1.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.airGapDC.Le", \
"Excitation inductance [H]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.eGround.p.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.eGround.p.i", \
"Current flowing into the pin [A]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.I", \
"Value of constant current [A]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.v", \
"Voltage drop of the two pins (= p.v - n.v) [V]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.i", \
"Current flowing from pin p to pin n [A]", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.p.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.p.i", \
"Current flowing into the pin [A]", 1.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.ie.n.i", \
"Current flowing into the pin [A]", -1.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.Lme", \
"Field excitation inductance [H]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.dcpm.IeNominal", \
"Equivalent excitation current [A]", 1, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.p.v", \
"Potential at the pin [V]", "drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1,\
 5, 6580, 4)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.p.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 132)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.n.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.n.i", \
"Current flowing into the pin [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", 1,\
 1, 57, 132)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.v", \
"Voltage between pin p and n (= p.v - n.v) as input signal [V]", \
"drone.propeller_DCMachine1.dCMotor2_1.limiter.y", 1, 5, 6580, 0)
DeclareAlias2("drone.propeller_DCMachine1.dCMotor2_1.signalVoltage.i", \
"Current flowing from pin p to pin n [A]", "drone.propeller_DCMachine1.dCMotor2_1.dcpm.la.i", -1,\
 1, 57, 0)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.ground.p.v", \
"Potential at the pin [V]", 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.ground.p.i", \
"Current flowing into the pin [A]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.VaNominal", \
"Nominal armature voltage for motor [V]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.dCMotor2_1.IaNominal", \
"Nominal armature current (>0..Motor, <0..Generator) for motor [A]", 0.0, \
0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis1.frame_a3.f[1]", -1,\
 5, 2148, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis1.frame_a3.f[2]", -1,\
 5, 2149, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", -1,\
 5, 6916, 132)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[3]", -1,\
 5, 6919, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.useAxisFlange", \
"= true, if axis flange is enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,0,1539)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.animation", \
"= true, if animation shall be enabled (show axis as cylinder) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.n[1]", \
"Axis of rotation resolved in frame_a (= same as in frame_b) [1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.n[2]", \
"Axis of rotation resolved in frame_a (= same as in frame_b) [1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.n[3]", \
"Axis of rotation resolved in frame_a (= same as in frame_b) [1]", 1, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.phi_offset", \
"Relative angle offset (angle = phi_offset + phi) [rad|deg]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.cylinderLength", \
"Length of cylinder representing the joint axis [m]", 0.1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.cylinderDiameter", \
"Diameter of cylinder representing the joint axis [m]", 0.05, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.cylinderColor[1]", \
"Color of cylinder representing the joint axis [:#(type=Integer)]", 255, 0.0,\
255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.cylinderColor[2]", \
"Color of cylinder representing the joint axis [:#(type=Integer)]", 0, 0.0,255.0,\
0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.cylinderColor[3]", \
"Color of cylinder representing the joint axis [:#(type=Integer)]", 0, 0.0,255.0,\
0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.stateSelect", \
"Priority to use joint angle phi and w=der(phi) as states [:#(type=StateSelect)]",\
 4, 1.0,5.0,0.0,0,517)
DeclareState("drone.propeller_DCMachine1.rotor1.revolute.phi", "Relative rotation angle from frame_a to frame_b [rad|deg]",\
 58, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.rotor1.revolute.der(phi)", \
"der(Relative rotation angle from frame_a to frame_b) [rad/s]", 0.0, 0.0,0.0,0.0,\
0,512)
DeclareState("drone.propeller_DCMachine1.rotor1.revolute.w", "First derivative of angle phi (relative angular velocity) [rad/s]",\
 59, 0, 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.rotor1.revolute.der(w)", \
"der(First derivative of angle phi (relative angular velocity)) [rad/s2]", 0, \
0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.a", "Second derivative of angle phi (relative angular acceleration) [rad/s2]",\
 "drone.propeller_DCMachine1.rotor1.revolute.der(w)", 1, 6, 59, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.tau", "Driving torque in direction of axis of rotation [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant", 1, 7,\
 415, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.angle", \
"= phi_offset + phi [rad|deg]", "drone.propeller_DCMachine1.rotor1.revolute.phi", 1,\
 1, 58, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.e[1]", \
"Unit vector in direction of rotation axis, resolved in frame_a (= same as in frame_b) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.e[2]", \
"Unit vector in direction of rotation axis, resolved in frame_a (= same as in frame_b) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.e[3]", \
"Unit vector in direction of rotation axis, resolved in frame_a (= same as in frame_b) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[1, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[1, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[1, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[2, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[2, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[2, 3]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[3, 1]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[3, 2]", \
"Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.T[3, 3]", \
"Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.R_rel.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareParameter("drone.propeller_DCMachine1.rotor1.revolute.fixed.phi0", \
"Fixed offset angle of housing [rad|deg]", 414, 0, 0.0,0.0,0.0,0,2608)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.fixed.flange.phi", \
"Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.rotor1.revolute.fixed.phi0", 1,\
 7, 414, 1028)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.fixed.flange.tau", \
"Cut torque in the flange [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.internalAxis.tau", \
"External support torque (must be computed via torque balance in model where InternalSupport is used; = flange.tau) [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant", 1, 7,\
 415, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.internalAxis.phi", \
"External support angle (= flange.phi) [rad|deg]", "drone.propeller_DCMachine1.rotor1.revolute.phi", 1,\
 1, 58, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.internalAxis.flange.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.rotor1.revolute.phi", 1,\
 1, 58, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.internalAxis.flange.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant", 1,\
 7, 415, 1156)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.useSupport",\
 "= true, if support flange enabled, otherwise implicitly grounded [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,1539)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.flange.phi",\
 "Absolute rotation angle of flange [rad|deg]", "drone.propeller_DCMachine1.rotor1.revolute.phi", 1,\
 1, 58, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.flange.tau",\
 "Cut torque in the flange [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant", -1,\
 7, 415, 1156)
DeclareVariable("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.phi_support",\
 "Absolute angle of support flange [rad|deg]", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.phi", \
"Angle of flange with respect to support (= flange.phi - support.phi) [rad|deg]",\
 "drone.propeller_DCMachine1.rotor1.revolute.phi", 1, 1, 58, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.der(phi)",\
 "der(Angle of flange with respect to support (= flange.phi - support.phi)) [rad/s]",\
 "drone.propeller_DCMachine1.rotor1.revolute.w", 1, 1, 59, 1024)
DeclareParameter("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant",\
 "Constant torque (if negative, torque is acting as load in positive direction of rotation) [N.m]",\
 415, 0, 0.0,0.0,0.0,0,2608)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.w", \
"Angular velocity of flange with respect to support (= der(phi)) [rad/s]", \
"drone.propeller_DCMachine1.rotor1.revolute.w", 1, 1, 59, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau", \
"Accelerating torque acting at flange (= -flange.tau) [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.constantTorque.tau_constant", 1,\
 7, 415, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis1.frame_a3.f[1]", -1,\
 5, 2148, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis1.frame_a3.f[2]", -1,\
 5, 2149, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.droneChassis1.frame_a3.f[3]", -1,\
 5, 2150, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis1.frame_a3.t[1]", -1,\
 5, 2151, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis1.frame_a3.t[2]", -1,\
 5, 2152, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Airframe.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.droneChassis1.frame_a3.t[3]", -1,\
 5, 2153, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[1]",\
 "Relative angular velocity vector between frame_a and frame_b resolved in frame defined by resolveInFrame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[2]",\
 "Relative angular velocity vector between frame_a and frame_b resolved in frame defined by resolveInFrame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[3]",\
 "Relative angular velocity vector between frame_a and frame_b resolved in frame defined by resolveInFrame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.resolveInFrame",\
 "Frame in which output vector w_rel shall be resolved (world, frame_a, frame_b, or frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 2, 1.0,4.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1028)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.w_rel[1]",\
 "Relative angular velocity vector [rad/s]", "drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[1]", 1,\
 5, 6962, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.w_rel[2]",\
 "Relative angular velocity vector [rad/s]", "drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[2]", 1,\
 5, 6963, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.w_rel[3]",\
 "Relative angular velocity vector [rad/s]", "drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[3]", 1,\
 5, 6964, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.resolveInFrame",\
 "Frame in which output vector w_rel is resolved (world, frame_a, frame_b, or frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 2, 1.0,4.0,0.0,0,2565)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.relativeAngularVelocity.R_rel.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.zeroPosition.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", -1,\
 5, 7297, 132)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torque[1]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torque[2]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torque[3]", \
"x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", 1, 5, 7297, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.resolveInFrame", \
"Frame in which input force is resolved (1: world, 2: frame_a, 3: frame_b, 4: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 3, 1.0,4.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.Nm_to_m", \
"Torque arrow scaling (length = torque/Nm_to_m) [N.m/m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueDiameter", \
"Diameter of torque arrow [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLineDiameter",\
 "Diameter of line connecting frame_a and frame_b [m]", 0.025, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueColor[1]", \
"Color of torque arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueColor[2]", \
"Color of torque arrow [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueColor[3]", \
"Color of torque arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLineColor[1]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 255, 0.0,\
255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLineColor[2]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 255, 0.0,\
255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLineColor[3]",\
 "Color of line connecting frame_a and frame_b [:#(type=Integer)]", 0, 0.0,255.0,\
0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.specularCoefficient", \
"Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.t_in_m[1]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.t_in_m[2]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", \
"Torque mapped from Nm to m for animation [m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r[1]", \
"Position vector from origin of world frame to origin of arrow frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r[2]", \
"Position vector from origin of world frame to origin of arrow frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r[3]", \
"Position vector from origin of world frame to origin of arrow frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_tail[1]",\
 "Position vector from origin of arrow frame to double arrow tail, resolved in arrow frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_tail[2]",\
 "Position vector from origin of arrow frame to double arrow tail, resolved in arrow frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_tail[3]",\
 "Position vector from origin of arrow frame to double arrow tail, resolved in arrow frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", 1, 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_head[1]",\
 "Position vector from double arrow tail to the head of the double arrow, resolved in arrow frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_head[2]",\
 "Position vector from double arrow tail to the head of the double arrow, resolved in arrow frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.r_head[3]",\
 "Position vector from double arrow tail to the head of the double arrow, resolved in arrow frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", -1, 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.diameter",\
 "Diameter of arrow line [m]", 0.025, 0.0,1E+100,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.color[1]",\
 "Color of double arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,2565)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.color[2]",\
 "Color of double arrow [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,2565)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.color[3]",\
 "Color of double arrow [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,2565)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.specularCoefficient",\
 "Material property describing the reflecting of ambient light (= 0 means, that light is completely absorbed)",\
 "drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.length", \
"Length of arrow [m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.e_x[1]", \
"[1]", 1, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.e_x[2]", \
"[1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.e_x[3]", \
"[1]", 0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rxvisobj[1]",\
 "X-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rxvisobj[2]",\
 "X-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rxvisobj[3]",\
 "X-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rvisobj[1]",\
 "Position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rvisobj[2]",\
 "Position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.rvisobj[3]",\
 "Position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headLength",\
 "[m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headWidth",\
 "[m]", 0.07500000000000001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLength",\
 "[m]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r[1]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r[2]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r[3]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", 1, 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", -1,\
 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.length",\
 "Length of visual object [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLength", 1,\
 5, 7080, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.width",\
 "Width of visual object [m]", 0.025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.height",\
 "Height of visual object [m]", 0.025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.extra",\
 "Additional size data for some of the shape types", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.color[3]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.isURI",\
 "[:#(type=Boolean)]", false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.abs_n_x",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.n_z_aux[1]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.n_z_aux[3]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.n_z_aux[3]", 1,\
 5, 7098, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.n_z_aux[1]", -1,\
 5, 7096, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.Form",\
 "", 9.87103E+25, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,3584)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.size[1]",\
 "{length,width,height} of shape [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLength", 1,\
 5, 7080, 1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.size[2]",\
 "{length,width,height} of shape [m]", 0.025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.size[3]",\
 "{length,width,height} of shape [m]", 0.025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.Material",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowLine.Extra",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[1]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[2]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[3]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", -1,\
 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.length",\
 "Length of visual object [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headLength", 1,\
 5, 7078, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.width",\
 "Width of visual object [m]", 0.07500000000000001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.height",\
 "Height of visual object [m]", 0.07500000000000001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.extra",\
 "Additional size data for some of the shape types", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.color[3]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.isURI",\
 "[:#(type=Boolean)]", false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.abs_n_x",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.n_z_aux[1]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.n_z_aux[3]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.n_z_aux[3]", 1,\
 5, 7138, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.n_z_aux[1]", -1,\
 5, 7136, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.Form",\
 "", 9.87104E+25, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[1]", 1, 5, 7117,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[2]", 1, 5, 7118,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.r[3]", 1, 5, 7119,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.size[1]",\
 "{length,width,height} of shape [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headLength", 1,\
 5, 7078, 1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.size[2]",\
 "{length,width,height} of shape [m]", 0.07500000000000001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.size[3]",\
 "{length,width,height} of shape [m]", 0.07500000000000001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.Material",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead1.Extra",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[1]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[2]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[3]",\
 "Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", "drone.propeller_DCMachine1.rotor1.torque1.t_in_m[3]", -1,\
 5, 7059, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.length",\
 "Length of visual object [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headLength", 1,\
 5, 7078, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.width",\
 "Width of visual object [m]", 0.07500000000000001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.height",\
 "Height of visual object [m]", 0.07500000000000001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.extra",\
 "Additional size data for some of the shape types", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.color[1]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.color[2]",\
 "Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.color[3]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.isURI",\
 "[:#(type=Boolean)]", false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.abs_n_x",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.n_z_aux[1]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.n_z_aux[3]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.n_z_aux[3]", 1,\
 5, 7175, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", \
"drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.n_z_aux[1]", -1,\
 5, 7173, 512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.Form",\
 "", 9.87104E+25, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3584)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[1]", 1, 5, 7154,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[2]", 1, 5, 7155,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.r[3]", 1, 5, 7156,\
 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.size[1]",\
 "{length,width,height} of shape [m]", "drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.headLength", 1,\
 5, 7078, 1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.size[2]",\
 "{length,width,height} of shape [m]", 0.07500000000000001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.size[3]",\
 "{length,width,height} of shape [m]", 0.07500000000000001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.Material",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.torqueArrow.arrowHead2.Extra",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1024)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r_shape[1]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r_shape[2]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.r_shape[3]",\
 "Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.length",\
 "Length of visual object [m]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.width",\
 "Width of visual object [m]", 0.025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.height",\
 "Height of visual object [m]", 0.025, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.extra",\
 "Additional size data for some of the shape types", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.color[1]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.color[2]",\
 "Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.color[3]",\
 "Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.isURI",\
 "[:#(type=Boolean)]", false, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.abs_n_x",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.n_z_aux[1]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.n_z_aux[2]",\
 "[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.n_z_aux[3]",\
 "[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_x[1]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_x[2]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_x[3]",\
 "Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_y[1]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_y[2]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.e_y[3]",\
 "Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.Form",\
 "", 9.87103E+25, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rxvisobj[1]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 1.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rxvisobj[2]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rxvisobj[3]",\
 "x-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.ryvisobj[1]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.ryvisobj[2]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 1.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.ryvisobj[3]",\
 "y-axis unit vector of shape, resolved in world frame [1]", 0.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rvisobj[1]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rvisobj[2]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1536)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.rvisobj[3]",\
 "position vector from world frame to shape frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1536)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.size[1]",\
 "{length,width,height} of shape [m]", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.size[2]",\
 "{length,width,height} of shape [m]", 0.025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.size[3]",\
 "{length,width,height} of shape [m]", 0.025, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.Material",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.connectionLine.Extra",\
 "", 0.0, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[1]", 1,\
 5, 7036, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[2]", 1,\
 5, 7037, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.torque1.frame_a.t[3]", 1,\
 5, 7038, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", -1,\
 5, 7297, 132)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,521)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[1]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[2]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]",\
 "x-, y-, z-coordinates of torque resolved in frame defined by resolveInFrame [N.m]",\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.resolveInFrame",\
 "Frame in which torque is resolved (1: world, 2: frame_a, 3: frame_b, 4: frame_resolve) [:#(type=Modelica.Mechanics.MultiBody.Types.ResolveInFrameAB)]",\
 3, 1.0,4.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.r_0[1]", \
"Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.r_0[2]", \
"Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.r_0[3]", \
"Position vector from origin of frame_a to origin of frame_b resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.t_b_0[1]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.t_b_0[2]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.basicTorque.t_b_0[3]",\
 "frame_b.t resolved in world frame [N.m]", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,2569)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque1.zeroPosition.frame_resolve.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,2825)
DeclareParameter("drone.propeller_DCMachine1.rotor1.gain.k", "Gain value multiplied with input signal [1]",\
 416, -0.004, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.gain.u", "Input signal connector",\
 "drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[3]", 1, 5, 6964,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.gain.y", "Output signal connector",\
 "drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", 1, 5, 7297, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.realExtract.index", \
"output which variable in the array [:#(type=Integer)]", 3, 0.0,0.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtract.u[1]", "[rad/s]", \
"drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[1]", 1, 5, 6962,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtract.u[2]", "[rad/s]", \
"drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[2]", 1, 5, 6963,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtract.u[3]", "[rad/s]", \
"drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[3]", 1, 5, 6964,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtract.y", "", \
"drone.propeller_DCMachine1.rotor1.relativeAngularVelocity.w_rel[3]", 1, 5, 6964,\
 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtend2.u", "", \
"drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", 1, 5, 7297, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.realExtend2.y[1]", "[N.m]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.rotor1.realExtend2.y[2]", "[N.m]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.realExtend2.y[3]", "[N.m]", \
"drone.propeller_DCMachine1.rotor1.torque1.basicTorque.torque[3]", 1, 5, 7297, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.force.f[1]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.force.f[2]", "Cut-force resolved in connector frame [N]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.force.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.dCMotor2_1.force_out.f[3]", -1, 5, 6567, 132)
DeclareVariable("drone.propeller_DCMachine1.rotor1.force.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.force.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.force.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[1]", 1, 5, 6914, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[2]", 1, 5, 6915, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", 1, 5, 6916, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[1]", 1, 5, 6917, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.Blade.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[2]", 1, 5, 6918, 132)
DeclareVariable("drone.propeller_DCMachine1.rotor1.Blade.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1,\
 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1,\
 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1,\
 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1,\
 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1,\
 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1,\
 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_1.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_1.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_1.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[1]", -1,\
 5, 6697, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[2]", -1,\
 5, 6698, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_1.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque_2.t[3]", -1,\
 5, 6699, 132)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_2.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_2.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_2.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_2.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.rotor1.torque_2.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.rotor1.torque_2.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.torque[3]", 1,\
 5, 6660, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[1, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[1, 1]", 1, 5, 2101, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[1, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[1, 2]", 1, 5, 2102, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[1, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[1, 3]", 1, 5, 2103, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[2, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[2, 1]", 1, 5, 2104, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[2, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[2, 2]", 1, 5, 2105, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[2, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[2, 3]", 1, 5, 2106, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[3, 1]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1, 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[3, 2]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1, 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.T[3, 3]", "Transformation matrix from world frame to local frame",\
 "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1, 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[1]", 1, 5, 2110, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[2]", 1, 5, 2111, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.droneChassis1.pointMass.frame_a.R.w[3]", 1, 5, 2112, 0)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis1.frame_a3.f[1]", -1, 5, 2148, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis1.frame_a3.f[2]", -1, 5, 2149, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.droneChassis1.frame_a3.f[3]", -1, 5, 2150, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.droneChassis1.frame_a3.t[1]", -1, 5, 2151, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.droneChassis1.frame_a3.t[2]", -1, 5, 2152, 132)
DeclareAlias2("drone.propeller_DCMachine1.Airframe.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.droneChassis1.frame_a3.t[3]", -1, 5, 2153, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[1]", 1, 1, 63, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[2]", 1, 1, 64, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[3]", 1, 1, 65, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 1]", 1,\
 5, 7393, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 2]", 1,\
 5, 7394, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 3]", 1,\
 5, 7395, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 1]", 1,\
 5, 7396, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 2]", 1,\
 5, 7397, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 3]", 1,\
 5, 7398, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 1]", 1,\
 5, 7399, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 2]", 1,\
 5, 7400, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 3]", 1,\
 5, 7401, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[1]", 1,\
 5, 7402, 0)
EndNonAlias(5)
PreNonAliasNew(6)
StartNonAlias(6)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[2]", 1,\
 5, 7403, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[3]", 1,\
 5, 7404, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 1]", 1,\
 5, 7393, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 2]", 1,\
 5, 7394, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 3]", 1,\
 5, 7395, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 1]", 1,\
 5, 7396, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 2]", 1,\
 5, 7397, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 3]", 1,\
 5, 7398, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 1]", 1,\
 5, 7399, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 2]", 1,\
 5, 7400, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 3]", 1,\
 5, 7401, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[1]", 1,\
 5, 7402, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[2]", 1,\
 5, 7403, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[3]", 1,\
 5, 7404, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.animation", \
"= true, if animation shall be enabled (show shape between frame_a and frame_b and optionally a sphere at the center of mass) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.animateSphere", \
"= true, if mass shall be animated as sphere provided animation=true [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", -0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 417, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 418, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 419, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.m", \
"Mass of rigid body [kg]", 420, 0.01, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 421, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 422, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 423, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 424, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 425, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 426, 0, -1E+60,1E+100,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[1]", 1, 1, 63, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[2]", 1, 1, 64, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[3]", 1, 1, 65, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.der(r_0[1])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[1]", 1, 1, 60, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.der(r_0[2])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[2]", 1, 1, 61, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.der(r_0[3])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[3]", 1, 1, 62, 0)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", 60, 0,\
 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", 61, 0,\
 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", 62, 0,\
 0.0,0.0,0.0,0,560)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[1])", 1, 6, 60, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[2])", 1, 6, 61, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.der(v_0[3])", 1, 6, 62, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 427, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 428, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 429, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 430, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 431, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 432, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 433, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 434, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 435, 0, \
0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", -0.154, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.length", \
"Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.width", \
"Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.height", \
"Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 436, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sphereDiameter", \
"Diameter of sphere [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sphereColor[1]", \
"Color of sphere of mass [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sphereColor[2]", \
"Color of sphere of mass [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sphereColor[3]", \
"Color of sphere of mass [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[1]", 1, 1, 63, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[2]", 1, 1, 64, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[3]", 1, 1, 65, 4)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[1]", 1, 5, 7349, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[2]", 1, 5, 7350, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.frame_b.r_0[3]", 1, 5, 7351, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 1]", 1,\
 5, 7393, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 2]", 1,\
 5, 7394, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[1, 3]", 1,\
 5, 7395, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 1]", 1,\
 5, 7396, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 2]", 1,\
 5, 7397, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[2, 3]", 1,\
 5, 7398, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 1]", 1,\
 5, 7399, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 2]", 1,\
 5, 7400, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.T[3, 3]", 1,\
 5, 7401, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[1]", 1,\
 5, 7402, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[2]", 1,\
 5, 7403, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[3]", 1,\
 5, 7404, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.animation",\
 "= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,\
0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r[1]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", -0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r[2]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r[3]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r_shape[1]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r_shape[2]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.r_shape[3]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", -0.154, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.length",\
 "Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.width",\
 "Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.height",\
 "Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.extra",\
 "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 437, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.color[1]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.color[2]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.color[3]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 63, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.der(r_0[1])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 64, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.der(r_0[2])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 65, 0.0, 0.0,0.0,0.0,0,568)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.der(r_0[3])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.m", \
"Mass of rigid body [kg]", 1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[1]", 1, 1, 63, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[2]", 1, 1, 64, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.frame_a.r_0[3]", 1, 1, 65, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[1]", 1, 1, 60, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[2]", 1, 1, 61, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.v_0[3]", 1, 1, 62, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[1]", 1, 5, 7465, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[2]", 1, 5, 7466, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[3]", 1, 5, 7467, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.angles_fixed",\
 "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.w_0_start[1]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.w_0_start[2]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.w_0_start[3]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_0_start[1]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_0_start[2]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_0_start[3]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sphereDiameter",\
 "Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sphereColor[1]",\
 "Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sphereColor[2]",\
 "Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sphereColor[3]",\
 "Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.cylinderDiameter",\
 "Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.cylinderColor[1]",\
 "Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.cylinderColor[2]",\
 "Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.cylinderColor[3]",\
 "Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.enforceStates",\
 "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.useQuaternions",\
 "= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[1, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[1, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[1, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[2, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[2, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[2, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[3, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[3, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.I[3, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.R_start.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a_start[1]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a_start[2]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a_start[3]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.w_a[1]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[1]", 1,\
 5, 7402, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.w_a[2]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[2]", 1,\
 5, 7403, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.w_a[3]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.blades.bodyShape5.frameTranslation.frame_a.R.w[3]", 1,\
 5, 7404, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[1])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[2])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[3])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a[1]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[1])", 1, 5, 7520, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a[2]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[2])", 1, 5, 7521, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.z_a[3]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape5.body.der(w_a[3])", 1, 5, 7522, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.g_0[1]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.g_0[2]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.g_0[3]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q[1]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q[2]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q[3]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.Q[4]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_start[1]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_start[2]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_start[3]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi[1]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 66, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi[1])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi[2]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 67, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi[2])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi[3]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 68, \
0.0, 0.0,0.0,0.0,0,2592)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi[3])",\
 "der(Dummy or 3 angles to rotate world frame into frame_a of body) [rad/s]", \
0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_d[1]", \
"= der(phi) [rad/s]", 69, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[1])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_d[2]", \
"= der(phi) [rad/s]", 70, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[2])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareState("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_d[3]", \
"= der(phi) [rad/s]", 71, 0.0, 0.0,0.0,0.0,0,2608)
DeclareDerivative("drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[3])",\
 "der(= der(phi)) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[1])", 1,\
 6, 69, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[2])", 1,\
 6, 70, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape5.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", "drone.propeller_DCMachine1.blades.bodyShape5.body.der(phi_d[3])", 1,\
 6, 71, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[1]", -1,\
 5, 6914, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[2]", -1,\
 5, 6915, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", -1,\
 5, 6916, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[1]", -1,\
 5, 6917, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[2]", -1,\
 5, 6918, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.Blade.t[3]", -1,\
 5, 7334, 132)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 0.0, 0.0,0.0,0.0,0,520)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frame_b.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.animation", \
"= true, if animation shall be enabled (show shape between frame_a and frame_b and optionally a sphere at the center of mass) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.animateSphere", \
"= true, if mass shall be animated as sphere provided animation=true [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r[1]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r[2]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r[3]", \
"Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 438, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 439, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 440, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.m", \
"Mass of rigid body [kg]", 441, 0.01, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 442, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 443, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 444, 0.001, 0.0,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 445, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 446, 0, -1E+60,1E+100,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 447, 0, -1E+60,1E+100,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(r_0[1])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[1])", 1, 6, 3, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(r_0[2])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[2])", 1, 6, 4, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(r_0[3])", \
"der(Position vector from origin of world frame to origin of frame_a) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[3])", 1, 6, 5, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[1])", 1, 6, 3, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[2])", 1, 6, 4, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[3])", 1, 6, 5, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[1]", 1, 5, 1806, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[2]", 1, 5, 1807, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[3]", 1, 5, 1808, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape3.body.a_0[1]", 1, 5, 1806, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape3.body.a_0[2]", 1, 5, 1807, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", \
"drone.droneChassis1.bodyShape3.body.a_0[3]", 1, 5, 1808, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.angles_fixed", \
"= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 448, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 449, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 450, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.w_0_start[1]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 451, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.w_0_start[2]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 452, 0, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.w_0_start[3]", \
"Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 453, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.z_0_start[1]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 454, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.z_0_start[2]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 455, 0, \
0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.z_0_start[3]", \
"Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 456, 0, \
0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.154, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.length", \
"Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.width", \
"Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.height", \
"Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.extra", \
"Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 457, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sphereDiameter", \
"Diameter of sphere [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sphereColor[1]", \
"Color of sphere of mass [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sphereColor[2]", \
"Color of sphere of mass [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sphereColor[3]", \
"Color of sphere of mass [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.enforceStates", \
"= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.useQuaternions", \
"= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_a.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[1]", 1, 5, 7537, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[2]", 1, 5, 7538, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.propeller_DCMachine1.blades.bodyShape4.frame_b.r_0[3]", 1, 5, 7539, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.f[1]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.f[2]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.f[3]",\
 "Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.t[1]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.t[2]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.frame_b.t[3]",\
 "Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.animation",\
 "= true, if animation shall be enabled [:#(type=Boolean)]", false, 0.0,0.0,0.0,\
0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r[1]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r[2]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r[3]",\
 "Vector from frame_a to frame_b resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r_shape[1]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r_shape[2]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.r_shape[3]",\
 "Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.154, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.length",\
 "Length of shape [m]", 0.154, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.width",\
 "Width of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.height",\
 "Height of shape [m]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareParameter("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.extra",\
 "Additional parameter depending on shapeType (see docu of Visualizers.Advanced.Shape)",\
 458, 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.color[1]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.color[2]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.color[3]",\
 "Color of shape [:#(type=Integer)]", 155, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.frameTranslation.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.r_0[1]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.r_0[2]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.r_0[3]",\
 "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.der(r_0[1])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[1])", 1, 6, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.der(r_0[2])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[2])", 1, 6, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.der(r_0[3])",\
 "der(Position vector from world frame to the connector frame origin, resolved in world frame) [m/s]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[3])", 1, 6, 5, 4)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.R.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[1]", -1,\
 5, 6914, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[2]", -1,\
 5, 6915, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", -1,\
 5, 6916, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[1]", -1,\
 5, 6917, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[2]", -1,\
 5, 6918, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", "drone.propeller_DCMachine1.rotor1.Blade.t[3]", -1,\
 5, 7334, 132)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.animation", \
"= true, if animation shall be enabled (show cylinder and sphere) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.r_CM[1]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.r_CM[2]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.r_CM[3]", \
"Vector from frame_a to center of mass, resolved in frame_a [m]", 0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.m", \
"Mass of rigid body [kg]", 1, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_11", \
"(1,1) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_22", \
"(2,2) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_33", \
"(3,3) element of inertia tensor [kg.m2]", 0.0, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_21", \
"(2,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_31", \
"(3,1) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I_32", \
"(3,2) element of inertia tensor [kg.m2]", 0.0, -1E+60,1E+100,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.r_0[1]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.r_0[2]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.r_0[3]", \
"Position vector from origin of world frame to origin of frame_a [m]", \
"drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.v_0[1]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[1])", 1, 6, 3, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.v_0[2]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[2])", 1, 6, 4, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.v_0[3]", \
"Absolute velocity of frame_a, resolved in world frame (= der(r_0)) [m/s]", \
"drone.droneChassis1.bodyShape3.body.frame_a.der(r_0[3])", 1, 6, 5, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.der(v_0[1])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[1]", 1, 5, 1806, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.der(v_0[2])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[2]", 1, 5, 1807, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.der(v_0[3])", \
"der(Absolute velocity of frame_a, resolved in world frame (= der(r_0))) [m/s2]",\
 "drone.droneChassis1.bodyShape3.body.a_0[3]", 1, 5, 1808, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.a_0[1]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.a_0[2]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.a_0[3]", \
"Absolute acceleration of frame_a resolved in world frame (= der(v_0)) [m/s2]", 0,\
 0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.angles_fixed",\
 "= true, if angles_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.angles_start[1]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.angles_start[2]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.angles_start[3]",\
 "Initial values of angles to rotate frame_a around 'sequence_start' axes into frame_b [rad|deg]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_start[1]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_start[2]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_start[3]",\
 "Sequence of rotations to rotate frame_a into frame_b at initial time [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.w_0_fixed", \
"= true, if w_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.w_0_start[1]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.w_0_start[2]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.w_0_start[3]",\
 "Initial or guess values of angular velocity of frame_a resolved in world frame [rad/s]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_0_fixed", \
"= true, if z_0_start are used as initial values, else as guess values [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_0_start[1]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_0_start[2]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_0_start[3]",\
 "Initial values of angular acceleration z_0 = der(w_0) [rad/s2]", 0.0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sphereDiameter",\
 "Diameter of sphere [m]", 0.1111111111111111, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sphereColor[1]",\
 "Color of sphere [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sphereColor[2]",\
 "Color of sphere [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sphereColor[3]",\
 "Color of sphere [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.cylinderDiameter",\
 "Diameter of cylinder [m]", 0.037037037037037035, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.cylinderColor[1]",\
 "Color of cylinder [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.cylinderColor[2]",\
 "Color of cylinder [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.cylinderColor[3]",\
 "Color of cylinder [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.enforceStates",\
 "= true, if absolute variables of body object shall be used as states (StateSelect.always) [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.useQuaternions",\
 "= true, if quaternions shall be used as potential states otherwise use 3 angles as potential states [:#(type=Boolean)]",\
 false, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_angleStates[1]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 1, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_angleStates[2]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 2, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.sequence_angleStates[3]",\
 "Sequence of rotations to rotate world frame into frame_a around the 3 angles used as potential states [:#(type=Integer)]",\
 3, 1.0,3.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[1, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[1, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[1, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[2, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[2, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[2, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[3, 1]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[3, 2]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.I[3, 3]", \
"inertia tensor [kg.m2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[1, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[1, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[1, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[2, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[2, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[2, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[3, 1]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[3, 2]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.T[3, 3]",\
 "Transformation matrix from world frame to local frame", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.w[1]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.w[2]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.R_start.w[3]",\
 "Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a_start[1]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a_start[2]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a_start[3]",\
 "Initial values of angular acceleration z_a = der(w_a), i.e., time derivative of angular velocity resolved in frame_a [rad/s2]",\
 0.0, 0.0,0.0,0.0,0,513)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.w_a[1]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.w_a[2]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.w_a[3]", \
"Absolute angular velocity of frame_a resolved in frame_a [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[1])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[2])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[3])",\
 "der(Absolute angular velocity of frame_a resolved in frame_a) [rad/s2]", 0.0, \
0.0,0.0,0.0,0,512)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a[1]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[1])", 1, 5, 7702, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a[2]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[2])", 1, 5, 7703, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.bodyShape4.body.z_a[3]", \
"Absolute angular acceleration of frame_a resolved in frame_a [rad/s2]", \
"drone.propeller_DCMachine1.blades.bodyShape4.body.der(w_a[3])", 1, 5, 7704, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.g_0[1]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.g_0[2]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.g_0[3]", \
"Gravity acceleration resolved in world frame [m/s2]", 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q_start[1]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q_start[2]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q_start[3]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q_start[4]", \
"Quaternion orientation object from world frame to frame_a at initial time [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q[1]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q[2]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q[3]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.Q[4]", \
"Quaternion orientation object from world frame to frame_a (dummy value, if quaternions are not used as states) [1]",\
 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_start[1]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_start[2]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_start[3]",\
 "Potential angle states at initial time [rad|deg]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi[1]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi[2]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi[3]", \
"Dummy or 3 angles to rotate world frame into frame_a of body [rad|deg]", 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_d[1]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_d[2]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_d[3]", \
"= der(phi) [rad/s]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_dd[1]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_dd[2]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.bodyShape4.body.phi_dd[3]", \
"= der(phi_d) [rad/s2]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.r_0[1]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.r_0[2]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.r_0[3]", "Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.w[1]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.w[2]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.R.w[3]", "Absolute angular velocity of local frame, resolved in local frame [rad/s]",\
 "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.f[1]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[1]", -1, 5, 6914, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.f[2]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[2]", -1, 5, 6915, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.f[3]", "Cut-force resolved in connector frame [N]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.f[3]", -1, 5, 6916, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.t[1]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[1]", -1, 5, 6917, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.t[2]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.revolute.frame_b.t[2]", -1, 5, 6918, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.Input.t[3]", "Cut-torque resolved in connector frame [N.m]",\
 "drone.propeller_DCMachine1.rotor1.Blade.t[3]", -1, 5, 7334, 132)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.r_0[1]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.r_0[2]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.r_0[3]", \
"Position vector from world frame to the connector frame origin, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 4)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.frame_a.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 0)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.f[1]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.f[2]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.f[3]", \
"Cut-force resolved in connector frame [N]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.t[1]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.t[2]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.frame_a.t[3]", \
"Cut-torque resolved in connector frame [N.m]", 0.0, 0.0,0.0,0.0,0,777)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.animation", \
"= true, if animation shall be enabled [:#(type=Boolean)]", true, 0.0,0.0,0.0,0,515)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.r_shape[1]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", -0.0085, \
0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.r_shape[2]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", -0.1, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.r_shape[3]", \
"Vector from frame_a to shape origin, resolved in frame_a [m]", 0.0, 0.0,0.0,0.0,\
0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.lengthDirection[1]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.lengthDirection[2]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", 0, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.lengthDirection[3]",\
 "Vector in length direction of shape, resolved in frame_a [1|1]", -1, 0.0,0.0,\
0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.widthDirection[1]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.widthDirection[2]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 1, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.widthDirection[3]",\
 "Vector in width direction of shape, resolved in frame_a [1]", 0, 0.0,0.0,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.length", \
"Length of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.width", \
"Width of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.height", \
"Height of shape [m]", 0.001, 0.0,1E+100,0.0,0,513)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.color[1]", \
"Color of shape [:#(type=Integer)]", 0, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.color[2]", \
"Color of shape [:#(type=Integer)]", 128, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.color[3]", \
"Color of shape [:#(type=Integer)]", 255, 0.0,255.0,0.0,0,517)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.extra", \
"Additional data for cylinder, cone, pipe, gearwheel and spring", 1, 0.0,0.0,0.0,\
0,513)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 0)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[1, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 1]", 1,\
 5, 6620, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[1, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 2]", 1,\
 5, 6621, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[1, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[1, 3]", 1,\
 5, 6622, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[2, 1]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[2, 2]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[2, 3]", \
"Transformation matrix from world frame to local frame", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[3, 1]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", 1,\
 5, 2107, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[3, 2]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", 1,\
 5, 2108, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.T[3, 3]", \
"Transformation matrix from world frame to local frame", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", 1,\
 5, 2109, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.w[1]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[1]", 1, 5,\
 6629, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.w[2]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[2]", 1, 5,\
 6630, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.R.w[3]", \
"Absolute angular velocity of local frame, resolved in local frame [rad/s]", \
"drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.w[3]", 1, 5,\
 6631, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.r[1]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[1]", 1, 1, 3, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.r[2]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[2]", 1, 1, 4, 1024)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.r[3]", \
"Position vector from origin of world frame to origin of object frame, resolved in world frame [m]",\
 "drone.droneChassis1.bodyShape3.body.frame_a.r_0[3]", 1, 1, 5, 1024)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.r_shape[1]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.0085, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.r_shape[2]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 -0.1, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.r_shape[3]", \
"Position vector from origin of object frame to shape origin, resolved in object frame [m]",\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.lengthDirection[1]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.lengthDirection[2]",\
 "Vector in length direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.lengthDirection[3]",\
 "Vector in length direction, resolved in object frame [1]", -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.widthDirection[1]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.widthDirection[2]",\
 "Vector in width direction, resolved in object frame [1]", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.widthDirection[3]",\
 "Vector in width direction, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.length", \
"Length of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.width", \
"Width of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.height", \
"Height of visual object [m]", 0.001, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.extra", \
"Additional size data for some of the shape types", 1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.color[1]", \
"Color of shape", 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.color[2]", \
"Color of shape", 128, 0.0,0.0,0.0,0,2561)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.color[3]", \
"Color of shape", 255, 0.0,0.0,0.0,0,2561)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.specularCoefficient",\
 "Reflection of ambient light (= 0: light is completely absorbed)", \
"drone.world.defaultSpecularCoefficient", 1, 7, 28, 1024)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.isURI", \
"[:#(type=Boolean)]", true, 0.0,0.0,0.0,0,2563)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.abs_n_x", \
"[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.n_z_aux[1]", \
"[1]", 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.n_z_aux[2]", \
"[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.n_z_aux[3]", \
"[1]", 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_x[1]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_x[2]", \
"Unit vector in lengthDirection, resolved in object frame [1]", 0.0, 0.0,0.0,0.0,\
0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_x[3]", \
"Unit vector in lengthDirection, resolved in object frame [1]", -1.0, 0.0,0.0,\
0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_y[1]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_y[2]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.e_y[3]", \
"Unit vector orthogonal to lengthDirection in the plane of lengthDirection and widthDirection, resolved in object frame [1]",\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.Form", \
"[:modelica://DroneSimulation/Images/8.stl]", 9.87213E+25, 0.0,0.0,0.0,0,3585)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.rxvisobj[1]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 1]", -1,\
 5, 2107, 1536)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.rxvisobj[2]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 2]", -1,\
 5, 2108, 1536)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.rxvisobj[3]", \
"x-axis unit vector of shape, resolved in world frame [1]", "drone.droneChassis1.pointMass.frame_a.R.T[3, 3]", -1,\
 5, 2109, 1536)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.ryvisobj[1]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 1]", 1,\
 5, 6623, 1536)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.ryvisobj[2]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 2]", 1,\
 5, 6624, 1536)
DeclareAlias2("drone.propeller_DCMachine1.blades.fixedShape.vis.ryvisobj[3]", \
"y-axis unit vector of shape, resolved in world frame [1]", "drone.propeller_DCMachine1.dCMotor2_1.torque.basicTorque.frame_b.R.T[2, 3]", 1,\
 5, 6625, 1536)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.rvisobj[1]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.rvisobj[2]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.rvisobj[3]", \
"position vector from world frame to shape frame, resolved in world frame [m]", \
0.0, 0.0,0.0,0.0,0,3584)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.size[1]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.size[2]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.size[3]", \
"{length,width,height} of shape [m]", 0.001, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.Material", "",\
 0.0, 0.0,0.0,0.0,0,3585)
DeclareVariable("drone.propeller_DCMachine1.blades.fixedShape.vis.Extra", "", \
1.0, 0.0,0.0,0.0,0,3585)
DeclareParameter("drone.propeller_DCMachine1.PropellerGain", "Propeller gain. Set to 1 for clockwise, -1 for counterclockwise [1]",\
 459, -1, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.propeller_DCMachine1.position", "", "drone.controlModule_Synchronous.y3", 1,\
 5, 974, 0)
DeclareParameter("drone.propeller_DCMachine1.VaNominal", "Nominal armature voltage for motor [V]",\
 460, 10, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.propeller_DCMachine1.IaNominal", "Nominal armature current (>0..Motor, <0..Generator) for motor [A]",\
 461, 0.1, 0.0,0.0,0.0,0,560)
DeclareParameter("drone.const.k", "Constant output value", 462, 0, 0.0,0.0,0.0,0,560)
DeclareAlias2("drone.const.y", "Connector of Real output signal", \
"drone.const.k", 1, 7, 462, 0)
DeclareParameter("const1.k", "Constant output value", 463, -0.25, 0.0,0.0,0.0,0,560)
DeclareAlias2("const1.y", "Connector of Real output signal", "const1.k", 1, 7, 463,\
 0)
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
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.sample_24", "drone.controlModule_Synchronous.discreteTF1.sample2.u [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.sample_25", "drone.controlModule_Synchronous.discreteTF1.sample1.u [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_0.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.feedback.u1", 1,\
 5, 1004, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.feedback.u2", 1,\
 5, 1005, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.feedback.y", 1,\
 5, 1006, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF1.hold1.u", 1, 5, 1022, 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[1]", 1, 5, 1011,\
 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF1.transferFunction1.x[2]", 1, 5, 1012,\
 64)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.transferFunction1.x1", 1,\
 5, 1015, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[1]", 1,\
 5, 1016, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[2]", 1,\
 5, 1017, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF1.transferFunction1.xext[3]", 1,\
 5, 1018, 1088)
DeclareAlias2("_Clocks.BaseClock_0.SubClock_1.drone.controlModule_Synchronous.discreteTF1.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_0.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF1.transferFunction1.y", 1, 5, 1007, 64)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.sample_26", "drone.controlModule_Synchronous.discreteTF4.sample2.u [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.sample_27", "drone.controlModule_Synchronous.discreteTF4.sample1.u [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_1.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.feedback.u1", 1,\
 5, 1071, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.feedback.u2", 1,\
 5, 1072, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.feedback.y", 1,\
 5, 1073, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF4.hold1.u", 1, 5, 1089, 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[1]", 1, 5, 1078,\
 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF4.transferFunction1.x[2]", 1, 5, 1079,\
 64)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.transferFunction1.x1", 1,\
 5, 1082, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[1]", 1,\
 5, 1083, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[2]", 1,\
 5, 1084, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF4.transferFunction1.xext[3]", 1,\
 5, 1085, 1088)
DeclareAlias2("_Clocks.BaseClock_1.SubClock_1.drone.controlModule_Synchronous.discreteTF4.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_1.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF4.transferFunction1.y", 1, 5, 1074, 64)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.sample_28", "drone.controlModule_Synchronous.discreteTF6.sample2.u [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.sample_29", "drone.controlModule_Synchronous.discreteTF6.sample1.u [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_2.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.feedback.u1", 1,\
 5, 1117, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.feedback.u2", 1,\
 5, 1118, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.feedback.y", 1,\
 5, 1119, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF6.hold1.u", 1, 5, 1135, 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[1]", 1, 5, 1124,\
 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF6.transferFunction1.x[2]", 1, 5, 1125,\
 64)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.transferFunction1.x1", 1,\
 5, 1128, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[1]", 1,\
 5, 1129, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[2]", 1,\
 5, 1130, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF6.transferFunction1.xext[3]", 1,\
 5, 1131, 1088)
DeclareAlias2("_Clocks.BaseClock_2.SubClock_1.drone.controlModule_Synchronous.discreteTF6.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_2.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF6.transferFunction1.y", 1, 5, 1120, 64)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.sample_30", "drone.controlModule_Synchronous.discreteTF3.sample2.u [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.sample_31", "drone.controlModule_Synchronous.discreteTF3.sample1.u [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_3.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.feedback.u1", 1,\
 5, 1048, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.feedback.u2", 1,\
 5, 1049, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.feedback.y", 1,\
 5, 1050, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF3.hold1.u", 1, 5, 1066, 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[1]", 1, 5, 1055,\
 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF3.transferFunction1.x[2]", 1, 5, 1056,\
 64)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.transferFunction1.x1", 1,\
 5, 1059, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[1]", 1,\
 5, 1060, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[2]", 1,\
 5, 1061, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF3.transferFunction1.xext[3]", 1,\
 5, 1062, 1088)
DeclareAlias2("_Clocks.BaseClock_3.SubClock_1.drone.controlModule_Synchronous.discreteTF3.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_3.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF3.transferFunction1.y", 1, 5, 1051, 64)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.sample_32", "drone.controlModule_Synchronous.discreteTF5.sample2.u [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.sample_33", "drone.controlModule_Synchronous.discreteTF5.sample1.u [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_4.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.feedback.u1", 1,\
 5, 1094, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.feedback.u2", 1,\
 5, 1095, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.feedback.y", 1,\
 5, 1096, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF5.hold1.u", 1, 5, 1112, 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[1]", 1, 5, 1101,\
 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF5.transferFunction1.x[2]", 1, 5, 1102,\
 64)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.transferFunction1.x1", 1,\
 5, 1105, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[1]", 1,\
 5, 1106, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[2]", 1,\
 5, 1107, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF5.transferFunction1.xext[3]", 1,\
 5, 1108, 1088)
DeclareAlias2("_Clocks.BaseClock_4.SubClock_1.drone.controlModule_Synchronous.discreteTF5.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_4.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF5.transferFunction1.y", 1, 5, 1097, 64)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.sample_34", "drone.controlModule_Synchronous.discreteTF2.sample2.u [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.sample_35", "drone.controlModule_Synchronous.discreteTF2.sample1.u [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[1]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[2]_previous",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 0.0, 0.0,0.0,0.0,0,2688)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.first_.", "[:#(type=Boolean):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 true, 0.0,0.0,0.0,0,1666)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.active", "[:#(type=Clock):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 false, 0.0,0.0,0.0,0,642)
DeclareVariable("_Clocks.BaseClock_5.SubClock_1.activationCount", \
"[:#(type=Integer):#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", 0,\
 0.0,0.0,0.0,0,644)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.feedback.u1",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.feedback.u1", 1,\
 5, 1026, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.feedback.u2",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.feedback.u2", 1,\
 5, 1027, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.feedback.y",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.feedback.y", 1,\
 5, 1028, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.hold1.u",\
 "Connector of clocked, Real input signal [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF2.hold1.u", 1, 5, 1044, 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[1]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[1]", 1, 5, 1033,\
 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[2]",\
 "State vector of controller canonical form [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF2.transferFunction1.x[2]", 1, 5, 1034,\
 64)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.x1",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.transferFunction1.x1", 1,\
 5, 1037, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[1]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[1]", 1,\
 5, 1038, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[2]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[2]", 1,\
 5, 1039, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[3]",\
 "[:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]", "drone.controlModule_Synchronous.discreteTF2.transferFunction1.xext[3]", 1,\
 5, 1040, 1088)
DeclareAlias2("_Clocks.BaseClock_5.SubClock_1.drone.controlModule_Synchronous.discreteTF2.transferFunction1.y",\
 "Connector of clocked, Real output signal [:#(clock=_Clocks.BaseClock_5.SubClock_1.activationCount)]",\
 "drone.controlModule_Synchronous.discreteTF2.transferFunction1.y", 1, 5, 1029, 64)
EndNonAlias(6)
PreNonAliasNew(7)
