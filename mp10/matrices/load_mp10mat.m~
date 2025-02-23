function retmat = load_mp9mat(filename)

% This function will accumulate values if they have identical subscripts
% which is not the same functionality as MP9's read matrix. i.e. this will
% only produce identical output matrix when there are repeating coordinates

size_m = dlmread(filename,' ',[0 0 0 1]);
loaddata = dlmread(filename,' ',1,0);
retmat = sparse(loaddata(:,1)+1,loaddata(:,2)+1,loaddata(:,3)+1, size_m(1),size_m(2));

end