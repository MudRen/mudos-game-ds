#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name("����j�T", ({ "buddhist robe","robe" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��j�����P�Ƴq�`���O�@�x���D�~�|�諸(�v�O?)�H�x����,\n"
                           "�A�J�Ӥ@�@, �G�M�~��W�n.\n");
		set("unit", "��");
		set("value",1999);
		set("material", "cloth");
	}
	set("armor_prop/dex",-1);
	set("armor_prop/int",1);
	set("armor_prop/armor",7);
	set("armor_prop/shield",7);
	setup();
}
