#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(WHT"�Q������"NOR,({ "gray silkworm thread drapery", "drapery","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�����q���Ө��ʶR�ӨӪ��Q�������A�W���٦��@�ǨǦǦǪ��ǹСC\n");
		set("unit","�j��");
		set("value",290);
		set("cloth",1);
	}
	setup();
}