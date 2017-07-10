addpath('./');

[y0,fs0] = wavread('./record/speak.wav');
[y1,fs1] = wavread('./record/shout.wav');
[y2,fs2] = wavread('./record/sing.wav');
[y3,fs3] = wavread('./record/concat.wav');

time0 = (1 : length(y0)) / fs0;
time1 = (1 : length(y1)) / fs1;
time2 = (1 : length(y2)) / fs2;
time3 = (1 : length(y3)) / fs3;

subplot(4,4,1);
plot(time0,y0(:,1));

subplot(4,4,2);
plot(time1,y1(:,1));

subplot(4,4,3);
plot(time2,y2(:,1));

subplot(4,4,4);
plot(time3,y3(:,1));


Y0 = fft(y0(:,1));
Y0 = fftshift(abs(Y0));
subplot(4,4,5);
plot(Y0);
title('speak');

Y1 = fft(y1(:,1));
Y1 = fftshift(abs(Y1));
subplot(4,4,6);
plot(Y1);
title('shout');

Y2 = fft(y2(:,1));
Y2 = fftshift(abs(Y2));
subplot(4,4,7);
plot(Y2);
title('sing');

Y3 = fft(y3);
Y3 = fftshift(abs(Y3));
subplot(4,4,8);
plot(Y3);
title('concat');

subplot(4,4,9);
spectrogram(y0(:,1));

subplot(4,4,10);
spectrogram(y1(:,1));

subplot(4,4,11);
spectrogram(y2(:,1));

subplot(4,4,12);
spectrogram(y3);

