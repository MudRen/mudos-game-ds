#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIB"�L�W�^���J��"NOR,({ "the none hero statue","statue" }));
	set_weight(30000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�o�O�b�F�j��j�a���F��������@�ϳo�ӫ������L�W�^���ҫإߪ��J���C\n");
		set("no_get",1);
		set("no_drop",1);
		set("value", 100000);
                set("unit","�y");
	}
	setup();
}
