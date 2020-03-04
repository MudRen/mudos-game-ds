#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("小布袋", ({"smallbag"}) );
        set("long", 
"一個小袋子，裡面好像有東西，打開(op)來看看吧。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "個");
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
		HIW"$N"HIW"打開了$n，發現了一條頭巾！\n"NOR,me,ob);
		ob1=new(__DIR__"nicehead");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 1:
	{
		message_vision(
		HIW"$N"HIW"打開了$n，發現了一些種子！\n"NOR,me,ob);
		ob1=new(__DIR__"seeds");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 2:
	{
		message_vision(
		HIW"$N"HIW"打開了$n，發現了一本書！\n"NOR,me,ob);
		ob1=new(__DIR__"magicbook");
		ob1->move(environment(this_object() ) );
		destruct(ob);
		break;
	}
	case 3:
	{
		message_vision(
		HIW"$N"HIW"打開了$n，裡面什麼東西也沒有...\n"NOR,me,ob);
		destruct(ob);
		break;
	}
	}
	}
	return 1;
}