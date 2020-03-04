// buddha_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "�д��I��" NOR, ({ "buddha staff", "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@���S�ʤS���M�D�`�H���������I���M�W���^�ۤ��ӻ����C\n");
		set("value", 6200);
		set("material", "brass");
		set("wield_msg", "$N���X�@�ڪ�����M��$n���b�⤤�C\n");
		set("unwield_msg", "$N��U�⤤��$n�C\n");
	}

	init_staff(93);
	setup();
}
