#include <armor.h>
#include <ansi.h> 
inherit BOOTS;void create()
{
        set_name(HIM"���s�㨬"NOR,({"dragon boots","boots"}) );
        set("long","���s�I�G���W�L���`��");
        set_weight(4000);
  if ( clonep() )
    set_default_object(__FILE__);
else
{
                set("volume",3);
set("unit","��");
                set("value",10000);
               // set("limit_lv",50); 
                set("armor_prop/str",-1);
                set("armor_prop/armor",7);
                set("armor_prop/show_damage",1); 
                set("armor_prop/bio",1);
}
setup();
}

