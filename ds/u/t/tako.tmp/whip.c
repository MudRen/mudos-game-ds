#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
    set_name(HIG"�C�D�@"NOR,({"green snake whip","whip"}) );
        set("long","�@���@�l�A�~��Ŧ��@���C�D�A���׹F��Q�إH�W\n");
      set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�K");
                set("volume",2);
       set("value",400);
        }
                set("wield_msg","$N���_�F�@��$n�C\n");
init_whip(65);
        setup();        
}       


