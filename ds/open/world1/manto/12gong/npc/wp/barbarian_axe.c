#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
     set_name( YEL"���Z�H"NOR"��"HIR"��q�ԩ�"NOR,({"barbarian axe","axe"}) );
     set_weight(13500);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
          set("unit", "��");             
          set("value",5600);
          set("material","gold"); 
          }
     set("limit_str", 24);
     set("limit_skill", 65);
     set("limit_level", 25);

     set("weapon_prop/dex", -3);
     set("weapon_prop/con", 5);
     set("weapon_prop/tec", 1);
     set("weapon_prop/sou", -1);
     init_axe(70);
     setup();
}

