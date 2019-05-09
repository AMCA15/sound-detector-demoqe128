n = 20;
f = 0.5;

f1 = 0.3;
f2 = 0.6;

m = 127;

% FilterType
%   1: LowPass     3: BandPass
%   2: HighPass    4: BandStop
FilterType = 2;

switch FilterType
    case {1, 2}
        f = [0 f f 1];
        if FilterType == 1
            m = [m m 0 0];   
        elseif FilterType == 2
            m = [0 0 m m];   
        end
    case {3, 4}
        f = [0 f1 f1 f2 f2 1];
        if FilterType == 3
            m = [0 0 m m 0 0];   
        elseif FilterType == 4
            m = [m m 0 0 m m];   
        end
end


bi = round(fir2(n, f, m));

[h1, w] = freqz(bi, 1);

plot(f, m/max(m), w/pi, abs(h1)/max(m));
ylabel('Normalized Amplitude');
xlabel('Normalized Frecuency (F)');
legend('Ideal', sprintf("n = %d", n));
grid on;

str = sprintf('%d, ', bi);
coeff_format = sprintf("normal {%s}\n", str(1:end-2));
fprintf(coeff_format);

clipboard('copy', coeff_format);

clear;
