#include <weapon.h> 
#include <ansi.h>
inherit FORK;
void create()
{
        set_name("青鋼短矛",({"steel pike","pike"}) ); 
        set("long","李鎮遠的隨身武器，不論長度、重量皆恰巧打造成能左握的武器•\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","桿");
        set("value",8600);
        set("volume",4);
        set("material","iron");
        set("limit_str",65);
        set("limit_lv",35); 
        set("weapon_prop/str",2);
        set("weapon_prop/dex",1);
        init_fork(48, SECONDARY);
        }
        setup();
}


