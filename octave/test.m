n = 100;
A = rand(n);
b = A*ones(n,1);
LU = lu_abel(A);
x = solve(LU,b);
norm(A*x - b) + norm(x - ones(n,1))
