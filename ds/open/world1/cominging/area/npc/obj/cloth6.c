#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"�A�v"NOR,({ "filamentus silk", "silk","filamentus","cloth" }));
	set_weight(500);
	set("cloth",1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�����q���Ө��ʶR�ӨӪ�"+this_object()->name()+"�A�W���٦��@�ǨǦǦǪ��ǹСC\n");
		set("unit","�j��");
		set("value",240);
		set("cloth",7);
	}
	setup();
}