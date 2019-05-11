classdef fir < handle
    properties
        % Filter parameters
        n
        f
        f1
        f2
        m
        FilterType
    end
    
    properties(Dependent)
        coeff = round(fir2(obj.n, obj.f_, obj.m_));
    end
    
    properties(Hidden)
        freq
        mag
    end
    
    properties(Dependent, Hidden)
        coeff_format
    end
        
    methods
        function obj = fir()
            obj.n = 20;
            obj.f = 0.5;
            obj.f1 = 0.3;
            obj.f2 = 0.6;
            obj.m = 127; 
            obj.FilterType = 'lowpass';
        end
        function value = get.coeff(obj)
            switch obj.FilterType
                case 'lowpass'
                    obj.freq = [0 obj.f obj.f 1];
                    obj.mag = [obj.m obj.m 0 0];   
                case 'highpass'
                    obj.freq = [0 obj.f obj.f 1];
                    obj.mag = [0 0 obj.m obj.m];   
                case 'bandpass'
                    obj.freq = [0 obj.f1 obj.f1 obj.f2 obj.f2 1];
                    obj.mag = [0 0 obj.m obj.m 0 0];                       
                case 'bandstop'
                    obj.freq = [0 obj.f1 obj.f1 obj.f2 obj.f2 1];
                    obj.mag = [obj.m obj.m 0 0 obj.m obj.m];                       
            end
            value = round(fir2(obj.n, obj.freq, obj.mag));
        end
        
        function coeff_format = get.coeff_format(obj)
            str = sprintf('%d, ', obj.coeff);
            coeff_format = sprintf("{%s}\n", str(1:end-2));
        end
                
        function plot(obj)
            [h1, w] = freqz(obj.coeff, 1);
            plot(obj.freq, obj.mag/obj.m, w/pi, abs(h1)/obj.m);
            ylabel('Normalized Amplitude');
            xlabel('Normalized Frecuency (F)');
            legend('Ideal', sprintf("n = %d", obj.n));
            grid on;
        end
        
        function dispCoeff(obj)
            fprintf(obj.coeff_format);
        end
        
        function copyCoeff(obj)
            clipboard('copy', obj.coeff_format); 
        end
        
        function value = coeffPacked(obj)
            value = int8([20 obj.coeff]);
        end
        
    end
    
    methods(Static)
        function value = enableBuzzer
            value = int8(17);
        end
        function value = disableBuzzer
           value = int8(16); 
        end 
    end
    
end