#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(HIR"���⥨��"NOR,({"red tooth","tooth"}) );
  set("long",
"�o�O���Ƥ��������A�i��O�����P�����C\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","��");
               set("value",6000);
                set("limit_str",32);
        }
                set("weapon_prop/parry",14); 
                set("weapon_prop/dodge",5); 
                set("weapon_prop/con",-4);
                set("weapon_prop/str",3);
                set("weapon_prop/dex",1);
init_dagger(50);
        setup();
}

