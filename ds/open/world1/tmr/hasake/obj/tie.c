#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"�ֳ��ɴ���"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "�i");
                set("weight", 300);
		set("long", "�o�O�ʤ������Ҽg�����A�ȥU���A�a�G�T�o�A��@�|�o�C\n");
		set("material", "paper");
		}
	setup();
}