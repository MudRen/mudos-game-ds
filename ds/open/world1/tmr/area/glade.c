#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "空地");
        set("long", @LONG
你正在一片石泥空地上，四周環繞林木，只見空地中佇立了不少木刻
假人，乍數之下，約有十來具之數，皆有一般成人大小，似乎是給人練功
打擊用的。在空地西首有間簡陋的石板屋，除此之外，盡皆花草樹木，了
無人氣。
如果你想要進去石板室，可以打enter house。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "northeast" : __DIR__"vroad5",
	]));
        set("item_desc", ([
        "house" : "一間看來十分樸素的小石屋, 或許\你可以進去看看。\n",
        "石板屋" : "一間看來十分樸素的小石屋, 或許\你可以進去看看。\n",
        ]));
	set("objects",([
		//__DIR__"npc/leewuda_13":1,
		//__DIR__"npc/leewuder_12":1,
		__DIR__"npc/leecharfan_22":1,
	]));
	set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_practice","practice");
}

int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg != "石板屋" && arg !="house" )
		return 0;
	else 
	{
	message_vision("$N打開了石板屋的木板門，走了進去。\n",me);
	me->move(__DIR__"s_house");
      tell_room(environment(me),me->query("name")+"打開了石板屋的木板門，走了進來。\n",me);
	return 1;
	}
}

int do_practice(string arg)
{
	object me,weapon;	
	me=this_player();

	if(!arg) return 0;
	if(!me->query_skill("da-fork") ) return 0;
	if(arg!="da-fork") return notify_fail("你只能練大槍訣(da-fork)。\n");

	weapon=me->query_temp("weapon");
	if(!weapon)	return notify_fail("你得拿枝槍才能練大槍訣。\n");
	if(weapon->query("skill_type")!="fork") 
		return notify_fail("你得拿枝槍才能練大槍訣。\n");
         if(me->query_skill("da-fork")>9 )  return notify_fail("你的大槍訣已有小成了，在此練槍已無益了。\n");
	if(me->query("ap") <10) 
		return notify_fail("你的內勁不夠，不能練大槍訣耶。\n");

     message_vision("$N拿起手中的"+weapon->query("name")+NOR"對著假人東刺一槍，西刺一槍地練了招大槍訣的基本招式。\n",me);
	me->receive_damage("ap",10);

	if(me->query("sk/da-fork") )
		me->add("sk/da-fork",random(me->query_int()) );
	else
		me->set("sk/da-fork",random(me->query_int()) );

      if(me->query("sk/da-fork" )>5000)
	{
		tell_object(me,HIY "經過一番苦練，你的大槍訣有成了。\n" NOR);
        me->delete("sk/da-fork");
          me->set_skill("da-fork",10);
	}
	return 1;

}



