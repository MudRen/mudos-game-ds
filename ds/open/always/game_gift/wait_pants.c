//�� /std/item/game_gift.c �гy by -Acme-

#include <armor.h>
#include <ansi.h>
inherit PANTS;

void create()
{
        set_name( MAG"���z"HIR"�����"NOR, ({ "Crazy's pants","pants" }) );
	set_weight(3224);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�ǻ��������z�G�H�աA�g���L�Ƴ��ԧЩүd�U���@������ǡA�J�Ӥ@�ݤW�Y�V���F�ĤH���A��A�p�G���`�N�ݡA�٥H�����z���U����F�Y�����ж�....");
		set("unit", "��");
		set("value",3608);
	}
	set("armor_prop/shield", 1);
	set("armor_prop/str", 1);
//        set("armor_prop/con", 2);
        set("armor_prop/con", 1); // �˱�EQ���g�@
	set("armor_prop/armor", 6);
	setup();
}
int query_autoload() { return 1; }
