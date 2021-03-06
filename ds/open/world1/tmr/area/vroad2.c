// Room: /u/t/tmr/area/vroad2.c

inherit ROOM;

void create()
{
	set("short", "孟村廣場");
	set("long", @LONG
這是一座位於孟村的小廣場，在秋後收割時，這裡常常會被用來做碾
米等工作，於農閒時，則大都是孟村小孩的玩樂地方，廣場中有棵數人合
抱的老柳樹，傳聞它已活了有上百年之久，算是孟村的神木了。本村每當
遇有什麼大事，常會相約於此討論談判。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"vroad4",
  "west" : __DIR__"vroad3",
  "east" : __DIR__"vroad1",
]));
	set("objects",([
 	  __DIR__"npc/mvillager" : 4,
        __DIR__"npc/seller" : 1,
	]) );
	set("outdoors","land");
        set("item_desc", ([
	"老柳樹" : "一棵盤根錯節的老柳樹，據說已成樹仙，頗有靈驗。\n",
	]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_beg","beg");
}

int do_beg(string arg)
{
        object me;
        me=this_player();
        if (!arg) return 0;
          if(arg!="老柳樹") return 0;
        if(me->is_busy() || me->is_fighting() )
                return 0;
        else{           
                message_vision("$N恭恭敬敬對著老柳樹合十拜了數拜。\n",me);
                me->set_temp("beg-tree",1);
        }
        return 1;
}

