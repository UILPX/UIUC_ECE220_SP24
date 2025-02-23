function save_mp9mat(A,filename)
%given a matrix or sparsematrix A, save the matrix to a text file in the
%format that MP9 expects.
dlmwrite(filename,size(A),'delimiter',' ');
[i j a] = find(A);
b = sortrows([i j a]);
c = [b(:,1)'-1; b(:,2)'-1; b(:,3)'];
f = fopen(filename,'a+');

fprintf(f,'%d %d %f\n',c);
fclose(f);
%dlmwrite(filename,[b(:,1)-1 b(:,2)-1 b(:,3)], '-append','delimiter',' ','precision',['%f' '%f' '%.6f']);

end
