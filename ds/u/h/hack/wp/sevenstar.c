#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name(HIC"�C�P�ˮp�C"NOR,({"sevenstar barb sword","sword","sevenstar"}));

	set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"�o��C�����X�n�A�i�O�b�A��X�o��C�ɡA�o�o�{�o��C���ݦ�M�i��\n"
                      "���B�A�b�C�W�W�������ǳ\\����w�y�S�X�ӡC�ǻ��o���O�j�N�ɲ��H\n"
            "�Φ�M���Kű�����A�ҥH�o�@��C�O�L�񪺾W�Q�M�L�񪺦�{�C\n"NOR);
		set("volume",2);
                set("unit", "��");
		set("value",12500);
        set("limit_skill",60);
	set("material","silver");
		set("limit_lv",25);
		set("limit_str",30);
		set("limit_dex",35);
	}
	init_sword(70);
	set("wield_msg","$N�q�I�᪺�C�U����X�@��$n�A�n�ɤ@������q$N�����W���o�X�ӡI\n");
	set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
	set("replica_ob", __DIR__"longsword.c");
	setup();
}
void attack(object me,object victim)
{
	int damage,str,dex,random1;
	if( random(200)>150)
	{
	str = me->query("str")-random(20);
	dex = me->query("dex")-random(18);
	random1 = 1+random(2);
	damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
	message_vision(
	"\n"
	+HIY"�C�P�˾W�C�b�C�y�@�w�@�w����y�������p���W�몺�y�F�X�ӡC\n"NOR
	+HIG"�@���n���q�C���H���F�X�ӡ���D�D�D�D�D�D\n"NOR
        +HIR"���a���A�b$N���e�@���������I�I�I�q�C���o�X�@�D�®�$N�ӥh�C\n"NOR
	+HIB"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
	,victim);
	return;
	}
}
