
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
set_name(HIG"�]"HIR"�F"HIY"��"NOR,({ "Jade of Night Spirit" , "sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
set("long", "�o�O�ѯ�|�����ؼC�A���b�C�W�A�O���~�ٱ��]�F��ù���䤸�ɩ�ű��\n");
		set("value", 400);
		set("material", "steel");
set("wield_msg", "$N�N�M�a���ۡA$n�j����~���J$N�����ءC\n");
set("unwield_msg", "�@�}��إ��~��$n�����L�ܡC\n");
	}
init_sword(35);
	setup();
}
