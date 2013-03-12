function env = upEnv(x,y)
% find the upper (concave) envelope
env = -lowEnv(x,-y);


