#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"���줧��"NOR,({"red staff","staff"}));
set("long", 
"�i���ѤH�Ү�������A�O�@����⪺���Y�d���A�ݰ_�ӨS����S�O��"

);
        set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("value",2000);
                set("volume",4);
          set("limit_str",24);
          set("limit_int",30);
        }
        set("weapon_prop/int",3);
init_staff(37);
        setup();
} 

