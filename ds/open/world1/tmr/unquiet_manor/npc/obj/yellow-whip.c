#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("�����@",({"yellow-bone whip","whip"}));
	set("long",@LONG
�o�O�@���ϥΰʪ���ղV���۵��֦ӻs�����@�A������@
�q�鳣�x�ۤ����A�b��­������]�̬ݡA��O�����z��
���A�D�`�޲��C
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
		init_whip(45);
        setup();
} 

