#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("������",({"yellow-bone staff","staff"}));
	set("long",@LONG
�o�O�@�ڨϥΰʪ��\���i���Ө�������A����S�����a��A
�O�o�ڰ����q�鳣�x�ۤ����C
LONG
	);
        set_weight(6000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "��");
              set("value", 1000);
			set("volume", 2);
            set("limit_str",30);
        }
		init_staff(40);
        setup();
} 

