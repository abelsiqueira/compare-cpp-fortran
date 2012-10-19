function x = solve ( LU, x )

n = size(LU, 1);

for i = 1:n
  for j = 1:i-1
    x(i) = x(i) - LU(i,j)*x(j);
  end
end

for i = n:-1:1
  for j = i+1:n
    x(i) = x(i) - LU(i,j)*x(j);
  end
  x(i) = x(i)/LU(i,i);
end

