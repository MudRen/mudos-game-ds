//�� /std/item/game_gift.c �гy by -Acme-

#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
	set_name( "[1;36m��[1;33m�P[1;31m��[1;37mä��[35m�ӱa[0m", ({ "aass's flower waist" }) );
	set_weight(1874);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�Τ@�������P��s´�Ӧ����y�a");
		set("unit", "��");
		set("value",1209);
	}
	set("armor_prop/armor", 4);
	set("armor_prop/shield", 3);
	set("armor_prop/con", 1);
	setup();
}
int query_autoload() { return 1; }
