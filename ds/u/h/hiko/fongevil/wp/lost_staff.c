#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("喪心杖",({"lost heart staff","staff"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把由墓地陰木所製的杖，給人怨氣不散的感覺。\n");
               set("volume",5);
               set("value",6000);
               set("material", "gem");
               set("limit_str",20);
               set("limit_int",15);
               set("limit_con",20);
              
          }
   set("weapon_prop/int",3);
   set("weapon_prop/str",1);
   set("weapon_prop/hit",8);
   init_staff(45);
   setup();
}

