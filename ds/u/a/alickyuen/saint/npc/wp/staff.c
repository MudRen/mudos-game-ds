#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name(HIY "�q����" NOR,({"electric staff","staff"}) );
        set("long",
        "�o�O�@��©媺�Τl�C\n"
        "���o��γ̯S�O���B�N�O�|��q�A�Y�����q��A�N�⤣���]���ˡC\n"
);
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
          set("value",500);
set("weapon_prop/hit", -2);
        }
 set("material","silver");
   set("weapon_prop/dodge",-2);
        init_staff(20);
        setup();
}
