#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�p���U", ({"smallbag"}) );
        set("long", 
"�@�Ӥp�U�l�A�̭��n�����F��A���}(op)�Ӭݬݧa�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        }
        setup(); 
}
void init()
{
	add_action("do_open","op");
}
int do_open(string arg)
{
	object ob,ob1,me;
	me=this_player();
	ob=this_object();
	
	if(arg == "smallbag" )
	{
	switch(random(4))
	{
	case 0:
	{
		message_vision(
		HIW"$N"HIW"���}�F$n�A�o�{�F�@���Y�y�I\n"NOR,me,ob);
		ob1=new(__DIR__"nicehead");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 1:
	{
		message_vision(
		HIW"$N"HIW"���}�F$n�A�o�{�F�@�Ǻؤl�I\n"NOR,me,ob);
		ob1=new(__DIR__"seeds");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 2:
	{
		message_vision(
		HIW"$N"HIW"���}�F$n�A�o�{�F�@���ѡI\n"NOR,me,ob);
		ob1=new(__DIR__"magicbook");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 3:
	{
		message_vision(
		HIW"$N"HIW"���}�F$n�A�̭�����F��]�S��...\n"NOR,me,ob);
		destruct(ob);
		break;
	}
	}
	}
	return 1;
}