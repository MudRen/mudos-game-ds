#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
   set_name(CYN"�C�K������"NOR, ({ "big pen","pen" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@����j���򵧵S�j�F�ƭ����K��, �W���� ���� �G�r...�C\n");
		set("material", "iron");
		set("limit_str",9);
	}
    set("weapon_prop/dex",-1);
    init_hammer(23);
    setup();
}

