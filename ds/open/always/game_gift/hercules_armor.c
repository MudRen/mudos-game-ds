//�� /std/item/game_gift.c �гy by -Acme-

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
	set_name( "[1;35m�b��[0m[0m", ({ "fly moon","fly" }) );
	set_weight(6801);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�b��۶ǬO�߮Z�b���V��c�ɱ��F�@���v¯�Ұ�����,�b��㦳�@�ǵL�k�������k�O,��a�ܻ����m�O�o�ܰ��C");
		set("unit", "��");
		set("value",6870);
	}
	set("armor_prop/shield", 28);
	set("armor_prop/str", 1);
	set("armor_prop/con", 1);
	set("armor_prop/armor", 49);
	setup();
}
int query_autoload() { return 1; }
