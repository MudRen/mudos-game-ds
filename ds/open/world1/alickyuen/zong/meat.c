#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT"�Ц׺�"NOR, ({"salty-meat zong"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���~�����o�ۦ˸��M���A�̭��]�۪ά��w�ת��w�׺�C\n");
		set("unit", "�u");
		set("value", 5000);
        }
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if( !arg ) return notify_fail("�A�n�Y����?\n");
        if( arg == "salty-meat zong" )
	{
		if( me->is_busy() ) return notify_fail("�A���b�����I\n");
		me->set("hp",me->query("max_hp") );
		me->set("mp",me->query("max_mp") );
		me->set("ap",me->query("max_ap") );
                message_vision("$N�Y�U�@��$n�C\n", me, this_object() );
		tell_object(me, "�A��Mı�o�����R���O��C\n");
                if(random(2)==0)
		{
			tell_object(me, HIY"�A�o�{��̦��@�i������I\n"NOR);
			new(__DIR__"ticket")->move(me);
		} else tell_object(me, HIR"�u���n�B...�o�Ӻ�̨S�������...\n"NOR);

        me->start_busy(3);
	call_out( (: destruct(this_object()) :), 1);

	return 1;
	}
}
