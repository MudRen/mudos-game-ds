#include <ansi.h>
inherit ITEM;

string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
	set_name(HIW"�����"NOR, ({ "mine-fan stone", "stone" }));
	set("long", "�@�ө_�S�����Y, �ڻ��i�H��_����. \n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
        set("value", 0);
        set("no_give", 1);
		set("no_sell", 1);
		set("no_sac", 1);
	}
	setup();
	call_out("receive_by_stone", 60);
}

void receive_by_stone()
{
	object me = environment(this_object());
	int p_hp, i;

        if( !this_object() || !me ) return;
	if( interactive(me) )
	{
		p_hp = me->query("max_hp");
		if( me->query("hp") < p_hp )
		{
            me->receive_heal("hp", p_hp*5/10);
			for(i=0;i<sizeof(wounds);i++)
				me->receive_curing(wounds[i], 1);
			message_vision(HIM"$N�o�X�@�D��, $n���G���쪺�~�˦��ǫ�_�I\n"NOR, this_object(), me);
		}
		else
		{
			message_vision("$N�o�X�@�D��, ���O�S������Ƶo�͡I\n", this_object());
		}
	}
	call_out("receive_by_stone", 30);
}
