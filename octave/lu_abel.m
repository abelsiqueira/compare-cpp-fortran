% LU sem pivoteamento
function A = lu_abel (A)

[m, n] = size(A);

for j = 1:m
  for i = j+1:m
    A(i,j) = A(i,j)/A(j,j);
    for k = j+1:n
      A(i,k) = A(i,k) - A(j,k) * A(i,j);
    end
  end
end
