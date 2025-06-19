BINDING_HEADER_INTERACT = 'Interact'

StaticPopupDialogs['INTERACT_WARNING'] = {
   text = 'Failed to load |cffffd200Interact|cffffffff. Follow the installation instructions to ensure proper installation.',
   button1 = 'Okay',
   OnAccept = function()
      DisableAddOn('Interact')
      ReloadUI()
   end,
   timeout = 0,
   whileDead = true,
}

if not InteractNearest then
   StaticPopup_Show('INTERACT_WARNING')
end