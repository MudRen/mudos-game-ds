
#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("�E�_�R��", ({ "nine ti pill","pill" }));
        set("long",
"�@���V�¦⪺���Y�A�����a�������A�ݤ��X��ĥΦp�ΡC\n"
	);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        set("unit", "��");
        set("value", 300);
        set("heal_hp",50);      
	set("eat_msg","$N�Y�U�@���¦⪺�ĤY�C");
        set("eff_msg",HIG "�Aı�o�@�}�}�W���b�L�̴��}��...\n" NOR );
	}
        setup();
}
