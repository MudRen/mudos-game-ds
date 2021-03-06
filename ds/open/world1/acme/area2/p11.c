// Room: /u/a/acme/area3/p11.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "涼亭");
	set("long", @LONG
這是一座石造涼亭，涼亭中央有個黃石大桌，四方則有四顆平整大石
以當椅子使用，在涼亭外有個小池塘，四周花草如茵，百花競豔，芬香馥
郁，翠麗如畫。在涼亭中央石桌上，放著一盤未下完之象棋，顯然這盤象
棋已轉為一盤細棋，輸贏也在一兩目之間，不知何人不將此盤下完，而留
棋於此，真令人匪夷所思。
LONG
	);
       set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p7",
]));
set("objects",([
      __DIR__"npc/yi2" : 1,
]) );
 set("item_desc", ([ /* sizeof() == 1 */
"象棋" :    "        １  ２  ３  ４  ５  ６  ７  ８  ９\n"
            "      A  ---------------"HIB"將"NOR"------"HIB"象"NOR"-------\n"
            "        ∣  ∣  ∣  ∣＼∣／∣  ∣  ∣  ∣\n"
            "      B "HIR"炮"NOR"----------"HIR"兵"NOR"--"HIR"兵"NOR"----------"HIB"車"NOR"--- \n"
            "        ∣  ∣  ∣  ∣／∣＼∣  ∣  ∣  ∣\n"
            "      C  ---------------"HIB"象"NOR"---------------     這是一盤未下完的棋，\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣    或許\你可以(grasp)去\n"
            "      D  --------------------------------     完成這盤未完成的棋。\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣    例：grasp 5a move 6a，\n"
            "      E  --------------------------------     這步是使「將」往右移一格。\n"
            "        ∣    "HIC"楚  河          漢  界"NOR"    ∣\n"
            "      F  -------------------------------- \n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      G  ---------------"HIB"包"NOR"---------------\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      H  -------"HIB"馬"NOR"------"HIR"炮"NOR"--------------- \n"
            "        ∣  ∣  ∣  ∣＼∣／∣  ∣  ∣  ∣\n"
            "      I  -----------"HIB"卒"NOR"--"HIR"仕"NOR"--------------- \n"
            "        ∣  ∣  ∣  ∣／∣＼∣  ∣  ∣  ∣\n"
            "      J "HIB"包"NOR"--------------"HIR"帥"NOR"--"HIR"仕"NOR"-----------\n"NOR,
]));
	setup();
}
void init()
{
        add_action("typegrasp","grasp");
}
int typegrasp(string arg)
{
        object me;
        me=this_player();
        if(arg != "5b move 5a") return notify_fail("你發覺這樣走好像不對。\n");
        else {
        message_vision("$N把藍方的「將」吃掉了。\n" ,me);
        message_vision("$N發覺石桌不停的晃動，不多時，石桌破碎了，且出現了個入口。\n",me);
           set("exits", ([ /* sizeof() == 1 */
              "north" : __DIR__"p7",
              "down" : __DIR__"t",
           ]));
        set("item_desc", ([ /* sizeof() == 1 */
"象棋" :    "        １  ２  ３  ４  ５  ６  ７  ８  ９\n"
            "      A  ---------------"HIR"兵"NOR"------"HIB"象"NOR"-------\n"
            "        ∣  ∣  ∣  ∣＼∣／∣  ∣  ∣  ∣\n"
            "      B "HIR"炮"NOR"----------"HIR"兵"NOR"----------------"HIB"車"NOR"--- \n"
            "        ∣  ∣  ∣  ∣／∣＼∣  ∣  ∣  ∣\n"
            "      C  ---------------"HIB"象"NOR"---------------\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      D  --------------------------------\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      E  --------------------------------\n"
            "        ∣    "HIC"楚  河          漢  界"NOR"    ∣\n"
            "      F  -------------------------------- \n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      G  ---------------"HIB"包"NOR"---------------\n"
            "        ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣  ∣\n"
            "      H  -------"HIB"馬"NOR"------"HIR"炮"NOR"--------------- \n"
            "        ∣  ∣  ∣  ∣＼∣／∣  ∣  ∣  ∣\n"
            "      I  -----------"HIB"卒"NOR"--"HIR"仕"NOR"--------------- \n"
            "        ∣  ∣  ∣  ∣／∣＼∣  ∣  ∣  ∣\n"
            "      J "HIB"包"NOR"--------------"HIR"帥"NOR"--"HIR"仕"NOR"-----------\n"NOR,
]));
        return 1;
       }
}
int valid_leave(object me, string dir)
{
       if( dir=="down" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
