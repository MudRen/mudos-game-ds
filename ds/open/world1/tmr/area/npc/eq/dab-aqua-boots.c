#include <armor.h>
#include <ansi.h> 
inherit BOOTS;

void create()
{
        set_name(HIM"���s�㨬"NOR,({"Dab-aqua boots","boots"}) );
        set("long","���s�I�G���W�L���`�ҡC\n");
        set_weight(2300);
  if ( clonep() )
    set_default_object(__FILE__);
  else{
                set("volume",3);
                set("unit","��");
                set("value",4500);
               // set("limit_lv",50); 
      }
                set("armor_prop/str",-2);
                set("armor_prop/armor",7);
//                set("armor_prop/show_damage",1); 
                set("armor_prop/bio",1);
//                set("beast_armor_prop/armor",40);
//                set("beast_armor_prop/bar",2);
//                set("beast_armor_type","armor");
setup();
}

