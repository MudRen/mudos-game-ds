#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG"����"NOR,({"green staff","staff"}));
		set("long",
		  "�o�O�@�ڥΤ����W�����s´�Ӧ����k���A���ۧA�q�ӨS���L���k���C\n"
		);
        set_weight(15000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("value",3000);
             set("volume",4);
        }
        set("weapon_prop/int",1);
		init_staff(40);
        setup();
} 
