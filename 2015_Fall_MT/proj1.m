test_images = dir('D:\dataset\test\*.bmp');
training_images = dir('D:\dataset\training\*.bmp');

num = 1300;
height = 165;
width = 120;

% initialize two 165*120*1300 metrix to load images
test = zeros(height,width,num);
training = zeros(height,width,num);

% read test images
for i = 1 : num
    test(:,:,i) = imread(strcat('D:\dataset\test\',test_images(i).name));
end

% read training images
for i = 1 : num
    training(:,:,i) = imread(strcat('D:\dataset\training\',training_images(i).name));
end

dataset = zeros(num,num);

% get SAD for every pair
for i = 1 : num
    for j = 1 : num
        SAD = 0;
        dif = test(:,:,i) - training(:,:,j);
        abs_dif = abs(dif);
        SAD = sum(abs_dif(:));
        dataset(i,j) = SAD;
    end
end

result = zeros(num,2);
ans = 0;

% get minimum for every test to training
% check if they are the same person
for i = 1 : num
    [result(i,1),result(i,2)] = min(dataset(i,1:end));
    j = floor((i-1)/13);
    if(result(i,2) > j*13 && result(i,2) <= (j+1)*13)
        ans = ans + 1;
    end
end

disp(ans/1300);