// Room: /open/world1/tmr/bagi/ghat13.c

inherit ROOM;

void create()
{
        set("short", "崖壁前");
        set("long", @LONG
西邊不數步遠是一面高聳的崖壁，上頭佈滿了厚達數尺的積雪，就算輕功
再高，也不可能攀爬上去的，反而要小心隨時可能崩塌的雪堆。崖壁中有個石
洞的樣子，但只見洞口橫七豎八的堆滿了石塊、朽木和雪塊等雜物，看樣子要
進洞裡去，得先把這一堆清理掉。
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "石洞" : "似乎是道天然的石洞，但是洞口被雜物擋住了，不得其門而入。\n",
  "雜物" : "盡是石塊、朽木和雪塊的雜物，正擋住了洞口，不知是否可以強行通過(pass)。\n",
]));
        set("outdoors", "snow");
        set("no_clean_up", 0);
        set("current_light", 2);
        set("world", "past");
        set("objects",([
                __DIR__"npc/zhou-ying":1,
        ]) );

        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ghat12",
]));

        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me=this_player();
        if(!arg || arg!="雜物") return 0;
        if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙著，沒有空做其它事。\n");
        if(me->query("level")<25) {
                message_vision("$N想要把擋在門口的雜物踢到一旁去，但就是怎樣清都清不完....\n",me);
        } else {
                message_vision("$N把擋在門口的雜物踢到一旁去，隨即進去了石洞內....\n",me);
                me->move(__DIR__"cave1");
                tell_room(me,me->name(1)+"從洞外走了進來，並且清了清身上的雪花。\n",({me }) );
        }
        return 1;
}


