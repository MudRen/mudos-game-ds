#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("�C�ɤ���",({"reactor"}) );
	set_weight(3000);
	set("long",@long
�@�ӫC�ɰ��������A�O��h�ΨӲ��t�誺����C
long
);
        set_max_encumbrance(4000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",200);
	}
	setup();
}