function dots = DeCasteljau(a,b,c,d,n)
    m1 = (a + b)/2;
    m2 = (b + d)/2;
    m3 = (c + d)/2;
    n1 = (m1 + m2)/2;
    n2 = (m2 + m3)/2;
    key = (n1 + n2)/2;
    if(n >= 1)
        left = DeCasteljau(a,m1,key,n1,n-1);
        right = DeCasteljau(key,n2,c,m3,n-1);
        dots = cat(2,left,right);
        dots = cat(2,dots,key(:));
    else
        dots = key(:);
    end
end