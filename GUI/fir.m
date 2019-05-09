n = 20;
f = [0 0.3 0.3 1];
m = [0 0 127 127];

bi = round(fir2(n, f, m));

[h1, w] = freqz(bi, 1);

plot(f, m, w/pi, abs(h1));
xlabel('f');
lgsfir = sprintf("n = %d", n);
lgs = {'Ideal', lgsfir};
legend(lgs);
grid on;

str = sprintf('%d, ', bi);
coeff_format = sprintf("{%s}", str(1:end-2));
fprintf(coeff_format);
clipboard('copy', coeff_format);
clear;
