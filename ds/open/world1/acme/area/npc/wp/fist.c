#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
    set_name(HIG"錦衣爪"NOR,({"gin yi fist","fist"}) );
    set("long","一個朝廷裡尋常禁軍所使用的武器。\n");
    set_weight(5000);
    if (clonep() )
          set_default_object(__FILE__);
    else {
        set("unit","個");
         set("value",2000);
set("volume",3);
        set("material","iron");
   }
          set("limit_str",10);
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
   init_fist(36);
   setup();
}
