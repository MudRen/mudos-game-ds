#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("��夦", ({"blood pill","pill"}));
		set("long",@long
��夦�O�������˥\�Ī��ĤY�A�]�A����A�i�H��E�H���餺�y�媺
���\��A�F�쨳�_��_�˶ժ��\�� 
long
);
		if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eff_msg", HIG "�Aı�o�˶ի�_���֤F�C" NOR );
        }
        set("value", 300);
        set("heal",([
			"hp": 300,
        ]));
        setup();
}




