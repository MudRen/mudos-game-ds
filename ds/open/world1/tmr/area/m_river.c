// Room: /u/t/tmr/area/m_river.c
inherit ROOM;
int do_enter(string arg);

void create()
{
        set("short", "河邊小路");
        set("long", @LONG
你正走在河邊小路，沿途可看到不少村婦拿著木棒蹲在河邊槌打一些
衣物，也有不少釣客正在享受垂釣的樂趣。此河也被引用通到村外的農田
的溝渠，每當乾旱之時，此河的水卻仍泉湧不絕，堪稱一絕，你留意到河
邊的水裡有個不小的【黑洞】。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "northeast" : __DIR__"vroad3",
           ]));
        set("objects",([
            __DIR__"npc/fisher" : 4,
           ]) );
        set("outdoors","land");
        set("item_desc", ([
                "黑洞" : "一個黑黑的洞，看來可以進去(enter)...不過水蠻深的...要小心。\n",
                ]));

        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "黑洞")
            return 0;
          else {
            message_vision("$N往黑洞的方向游了過去。\n",me);
            me->move("/open/world1/moonhide/pool/room1");
            return 1;
          }
}
