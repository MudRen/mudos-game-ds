#include <path.h>
#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit FINGER;
void create()
{
	set_name(HIC"��q�٤l"NOR,({"powerful ring","ring"}));

	set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",HIB"�o�O�@�T���M�`���٤l�A�ݨӳo�٤l���@�ǯS�O���B�C\n"NOR);	    
                	set("unit", "�T");
		set("value",4000);
         		set("limit_skill",60);
		set("material", "starring");
		set("limit_str",32);
		set("armor_prop/armor", 10);
		set("limit_dex",20);
	}
	set("wear_msg","$N�q�U�̮��X$n���b��W�I\n");
	set("remove_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
	set("replica_ob", __DIR__"ring2.c");
	setup();
}
void defend(object me,object victim)
{
	int damage,str,dex,random1;
	if( random(150)>100)
	{
	str = me->query("str")-random(20);
	dex = me->query("dex")-random(18);
	random1 = 1+random(2);
	damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
	message_vision(
	"\n"
	+HIG"$N����q�٤l��M�o�X�@�D������E��\n"NOR
	+HIR"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
	,victim);
	return;
	}
}
