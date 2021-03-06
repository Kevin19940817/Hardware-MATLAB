hardwarex_init;
pSSC32 = CreateSSC32();
% Check and modify the configuration file if needed...
[result] = ConnectSSC32(pSSC32, 'SSC320.txt')
%pSSC32.value

[result] = SetAllPWMsSSC32(pSSC32, [1 1 1 0 0], [1000 2000 1000 1500 1500]);

fig = figure('Position',[200 200 400 100],'NumberTitle','off');
% Force the figure to have input focus (required to capture keys).
set(fig,'WindowStyle','Modal'); axis('off');

% If SetPWMSSC32(), SetAllPWMsSSC32()... take too much time, use a thread to access data faster...
[result] = StartThreadSSC32(pSSC32);

a = 0;
key = 0;
while (isempty(key)||(key ~= 27)) % Wait for ESC key (ASCII code 27).
    clf; hold on;
    if (mod(a, 2) == 0)
        [result] = SetAllPWMsFromThreadSSC32(pSSC32, [1 1 1 0 0], [1000 2000 1250 1500 1500]);
    else
        [result] = SetAllPWMsFromThreadSSC32(pSSC32, [1 1 1 0 0], [2000 1000 1750 1500 1500]);
    end
    a = a+1;
    str = sprintf('a = %d\n', a);
    uicontrol('Style','text','String',str,'Units','normalized','Position',[0 0 1 1]);
    pause(2); key = get(gcf,'CurrentCharacter');
end

[result] = StopThreadSSC32(pSSC32);

close(fig);

[result] = DisconnectSSC32(pSSC32)
DestroySSC32(pSSC32);
clear pSSC32; % unloadlibrary might fail if all the variables that use types from the library are not removed...
unloadlibrary('hardwarex');
