#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�ȤѪk��",({"black sky staff","staff"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               
               set("unit", "��");
               set("long", "�o�O�@��ΤW�n���һs�����k��,�i�H�����j���k�O�C\n");
               set("volume",8);
               set("value",4200);
               set("material", "wood");
               set("limit_lv",20);
               set("limit_str",25);
               set("weapon_prop/wit",1);
               set("weapon_prop/str",1);
               set("weapon_prop/int",2);
                             
        }
    init_staff(50);
 
    setup();
}

