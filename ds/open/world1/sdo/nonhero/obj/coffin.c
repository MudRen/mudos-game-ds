#include <ansi2.h>
inherit ITEM;
	
void create()
{
        set_name("棺木", ({"coffin"}) );
        set("long",@LONG
在你眼前橫躺著一具巨大的棺木，不過奇怪的是裡面好像可以放東西
(putting xxx)。那麼無名英雄的遺體在哪裡？難不成要用招喚(summon)
的？
LONG
	);
        set_weight(1000);
        set_max_capacity(4);
        set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("no_get",1);
	set("no_drop",1);
        set("unit", "具");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
	add_action("summon_hero","summon");
	add_action("putting_eq","putting");
}

int putting_eq(string str)
{
	object me=this_player();
	object ob;

	if(str=="armor")
	{
	if(!ob=present("rusty armor",me))
		{return notify_fail("這樣東西是不能放進去的。\n");}

	if(this_object()->query_temp("armor")==1)
		{
		write("已經有放過了！\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N看到盔甲變成一道白光消失。\n"NOR,me);
		set_temp("armor",1);
		return 1;
	}

	if(str=="pike")
	{
	if(!ob=present("rusty pike",me))
		{return notify_fail("這樣東西是不能放進去的。\n");}

	if(this_object()->query_temp("pike")==1)
		{
		write("已經有放過了！\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N看到長槍變成一道白光消失。\n"NOR,me);
		set_temp("pike",1);
		return 1;
	}

	if(str=="leggings")
	{	
	if(!ob=present("rusty leggings",me))
		{return notify_fail("這樣東西是不能放進去的。\n");}

	if(this_object()->query_temp("leggings")==1)
		{
		write("已經有放過了！\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N看到脛甲變成一道白光消失。\n"NOR,me);
		set_temp("leggings",1);
		return 1;
	}

	if(str=="shield")
	{
	if(!ob=present("broken shield",me))
		{return notify_fail("這樣東西是不能放進去的。\n");}

	if(this_object()->query_temp("shield")==1)
		{
		write("已經有放過了！\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N看到盾牌變成一道白光消失。\n"NOR,me);
		set_temp("shield",1);
		return 1;
	}
}

int summon_hero(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="hero" || str=="英雄" || str=="無名英雄")
	{
	object me,b;
	me=this_player();

	message_vision(
	HIW"\n$N低頭唸道：無名英雄快出來！快出來！你的仰慕者來了！\n"NOR,me);

	if(this_object()->query_temp("shield")==1 && this_object()->query_temp("armor")==1 && this_object()->query_temp("pike")==1 && this_object()->query_temp("leggings")==1)
	  {
	  message_vision(
	  HIW"$N看見一道白光由棺木中飛射而出，並且凝結成一個人型，原來是無名英雄英靈出現了！\n"NOR,me);

	  b=new(__DIR__"npc/none_hero.c" );
	  b->move(environment(this_object()) );
	  delete_temp("pike");
	  delete_temp("shield");
	  delete_temp("armor");
	  delete_temp("leggings");

            //set_temp("opened",1);
	  return 1;
	  }
	else
	  {
	  message_vision(
	  HIW"$N發現什麼事都沒發生...。\n"NOR,me);
	  }
	return 1;
	}
}
