#include <room.h>
#include <ansi.h>
#include <path.h>

inherit ROOM;


void reset_citronm() {
        // 重新設定西瓜數量
       set("citron", 5 + random(10));
}

void create()
{
        set("short", "田邊小路");
        set("long", @LONG
你正走在一條田邊的泥巴路，道路兩旁是片青翠的西瓜田，滿滿地佈
滿整片田地，星羅棋佈似的在享受陽光的洗禮。在西南方有面小池塘，再
往東、西兩邊可延著小路繼續往前走。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
          "west" : __DIR__"ms4",
          "east" : __DIR__"ms1",
          "southwest" : __DIR__"ms3",
      "north" : WD_PAST+"meadow/room1",
        ]));
        set("item_desc",([
         "西瓜" : "一顆顆翠綠碩大的西瓜，看了真令人想偷拔(pick)幾顆來嚐嚐看。\n",
        ]) );   
        set("outdoors","land");
        set("no_clean_up", 0);
       set("citron", 5 + random(10));
 
        setup();
        call_out("reset_citronm", 180);
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me;
        object citron;

        me=this_player();
        if(arg != "西瓜") return notify_fail("你要摘什麼??\n");
        message_vision("$N擦了擦滿嘴的口水，偷偷摸摸地爬進去瓜田裡..\n",me);

        if( query("citron") <= 0 )
                tell_object(me,"你在瓜田尋覓了一陣，終究找不到可吃的西瓜。\n");
        else {
                add("citron",-1);
                citron=new(__DIR__"npc/obj/citron");
                citron->move(me);
                tell_object(me,"你在瓜田偷摘了顆已熟透的西瓜揣在懷裡。\n");       
        }
        return 1;       
}

