//�� /std/item/game_gift.c �гy by -Acme-

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( "[33m����[35m���s[31m��[36m��[1;37m�v[1;31m��[30m�C[0m", ({ "dragon's sword","sword" }) );
	set_weight(7457);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@�⥿��B����X�@�x�C�A�ϥΪ̥����祿�稸�A�_�h�N�|����o��C������ӯ��g���áB�g�ߺɸH���`�C");
		set("unit", "��");
		set("value",4886);
	}
	set("weaopn_prop/hit", 10 );
	set("weaopn_prop/dex", 1 );
	init_sword(60);
	setup();
}
int query_autoload() { return 1; }
