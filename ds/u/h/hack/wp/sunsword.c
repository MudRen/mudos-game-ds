#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "���C" NOR, ({ "se ri sword","sword" }) );
        set_weight(17000);
        if( clonep() )
		 set_default_object(__FILE__);
        else {
		set("unit", "��");
        set("material","crimsonsteel");
        set("limit_str",20);
                set("limit_int",25);
		set("long",
			"�o�O�@��{�ۤ�Ӷ��٭n�G�����~�����C�A\n"
			"�C�e������A���o���O�����A�����O�Ѧ��\n"
			"�����ű�y�Ӧ��A�b�������U�{�{�ۡA�D�`\n"
			"ģ���C\n");
		set("wield_msg", "$N�q�I��C�T����X�@������{�{��$n�A���b�⤤��Z���C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�I��C�T���C\n");
          set("value",8000);
        set("replica_ob",__DIR__"longsword");
set("volume",5);
        }
	set("weapon_prop/con", 1);
     set("weapon_prop/dex",3);
    set("weapon_prop/hit", 10);
        init_sword(67,TWO_HANDED);
	setup();
}
