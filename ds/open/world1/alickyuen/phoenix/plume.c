#include <ansi2.h>
#include <weapon.h>

inherit ITEM;

void create()
{
	set_name(HIR"��Ĥ���"NOR, ({ "plume of phoenix", "plume" }) );
         set_weight(100);
	set("long", @long
�o�@�ڬO�ǻ������j�N�ͪ���Ĩ��W���Ф�A�㦳���i��ĳ
����O�A�ǻ��γo�Ф����F�賣�O��w�L��C
long);
	set("unit" , "��");
	set("value", 1);
	set("no_repair", 1);

	setup();
}

void init()
{
	object room = environment(this_object());

	remove_call_out("gone");

	if( !room) return;
	if( userp(room) ) return;

        call_out("gone", 2, this_object());
	add_action("do_get", "get");
	return;
}
void gone(object obj)
{
	remove_call_out("gone");
        message_vision("$N�b�@�����ܦ����u�F ....\n\n", obj);

	destruct(obj);
	return;
}

int do_get(string arg)
{
        if( arg=="plume")
	{
                if( !this_player()->query_temp("quest/phoenix") ) 
		{
                        write("���د��_�O�q�O�A�����_�o�ӪF��C\n");
                        return 1;
		}
	}
}
