addpath('./');

p1 = [0,0];
p2 = [0,3];
p3 = [5,5];
p4 = [5,2];
data = DeCasteljau(p1,p2,p3,p4,500);
x = data(1,1:end);
y = data(2,1:end);
x = [x,p1(1,1)];
x = [x,p3(1,1)];
y = [y,p1(1,2)];
y = [y,p3(1,2)];
plot(x,y,'d','Marker','diamond');