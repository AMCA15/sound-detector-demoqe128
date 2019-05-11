classdef fir < handle
    properties
        % Filter parameters
        n
        f
        f1
        f2
        m
        FilterType
        % Data test
        dataTest
    end
    
    properties(Dependent)
        coeff
        dataTestFiltered
    end
    
    properties(Hidden)
        freq
        mag
    end
    
    properties(Dependent, Hidden)
        coeff_format
        dataTest_format
        dataTestFiltered_format
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
        
        function value = get.dataTestFiltered(obj)
            value = filter(obj.coeff, 1, obj.dataTest);
        end
        
        function value = get.coeff_format(obj)
            str = sprintf('%d, ', obj.coeff);
            value = sprintf("{%s}\n", str(1:end-2));
        end
        
        function value = get.dataTestFiltered_format(obj)
            str = sprintf('%d, ', obj.dataTestFiltered);
            value = sprintf("{%s}\n", str(1:end-2));
        end
        
        function obj = generateDataTest(obj, type, dimension)
            if nargin == 1
                return
            elseif nargin == 2
                dim = obj.n + 1;
            elseif nargin == 3
                dim = dimension;
            end
            switch type
                case 'random'
                    obj.dataTest = randi(obj.m, 1, dim, 'int8');
                case 'linear'
                    obj.dataTest = int8(1:dim);
            end
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
        
        function dispDataTestFiltered(obj)
            fprintf(obj.dataTestFiltered_format);
        end
        
        function copyDataTestFiltered(obj)
            clipboard('copy', obj.dataTestFiltered_format); 
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