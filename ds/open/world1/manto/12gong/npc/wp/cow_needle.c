#include <ansi.h>
#include <weapon.h>
inherit NEEDLE; 
void create()
{
     set_name(HIY"�������w"NOR,({"cow needle","needle"}));
     set_weight(1400);
     if( clonep() )
     set_default_object(__FILE__);
     else {
          set("value", 5200); 
          set("unit", "��");
          set("material","gold");
          set("limit_int",30);
          set("limit_str",18);
          }
     set("weapon_prop/dex", -2);
     set("weapon_prop/con", 1);
     set("weapon_prop/int", 2);
     set("weapon_prop/tec", 1);
     set("weapon_prop/bio", -1);
     init_needle(35);   
     setup();
}

