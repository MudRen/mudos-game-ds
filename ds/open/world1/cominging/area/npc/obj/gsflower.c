#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("��Ĭ����", ({ "gei-su flower", "flower" }));
	set("long","�@�ئb�˪L������ä��a�ұ`������C\n");
	set_weight(450);

	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("value", 100 );
	}
	setup();
}