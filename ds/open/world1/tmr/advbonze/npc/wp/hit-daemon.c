#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( HIY "如來撼魔杖"  NOR ,({"hit-daemon staff","staff"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "把");
               set("long",@LONG
這是一把用上好金剛石所製成的長杖，為佛教中的鎮魔重寶，傳聞具有神通力，
用於去妖除魔，特別有功效。
LONG
);
               set("volume",6);
               set("value",12000);
               set("material", "gold");
               set("limit_str",40);
               set("limit_int",25);
               set("limit_con",30);
        }
      init_staff(60);
      set("weapon_prop/dex",  1);
      set("weapon_prop/int",  1);
      set("male_only",1);
      setup();
}

