#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
    set_name(HIG"青蛇鞭"NOR,({"green snake whip","whip"}) );
        set("long","一條鞭子，外表酷似一條青蛇，長度達到十尺以上\n");
      set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","枝");
                set("volume",2);
       set("value",400);
        }
                set("wield_msg","$N拿起了一條$n。\n");
init_whip(65);
        setup();        
}       


