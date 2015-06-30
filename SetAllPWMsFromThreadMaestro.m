function [result] = SetAllPWMsFromThreadMaestro(pMaestro, selectedchannels, pws)

pSelectedChannels_p = libpointer('int32Ptr', selectedchannels);
pPWs_p = libpointer('int32Ptr', pws);

result = calllib('hardwarex', 'SetAllPWMsFromThreadMaestrox', pMaestro, pSelectedChannels_p, pPWs_p);
