// Room: /d/gumu/obj/box.c �K��
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(RED "�j�K��" NOR, ({ "iron box", "box" }) );
	set_weight(30000000);
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@���׸񴳴����j�K���l�A�ݨӫܤ[�S���H�ʹL�F�C\n");
		set("value", 1000);
		set("material", "steel");
		set("no_get",1);
		set("no_sac",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

