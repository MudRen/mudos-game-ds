#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
	set_name("�v�Y��", ({ "mace" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�����Y���٦h�F�X�ڨ�b�W��, �����D�����򦳥Ϊ��a��C\n");
		set("value", 800);
		set("material", "iron");
	}
    init_blade(13);
    setup();
}
