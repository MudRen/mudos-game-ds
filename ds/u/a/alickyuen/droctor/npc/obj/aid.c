#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��Ͻc", ({ "first aid box","box" }) );
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",1000);
		set("unit","��");
                set("long",
                        "�@�ӫ�Ͻc�A���ѵ���ͨӶi���ϮɥΡC\n");
	}
	setup();
}



                