#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name("�y��", ({ "belt" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@���²�檺�y��, ���L�q�`�]�n���I�������H�~�|�Ψ쥦.\n");
		set("unit", "��");
		set("material", "cloth");
	}
	set("armor_prop/armor", 1);
	setup();
}
