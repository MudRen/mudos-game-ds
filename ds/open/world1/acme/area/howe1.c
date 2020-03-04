inherit ROOM;
void create()
{
        set("short", "洞穴");
        set("long", @LONG
此地竟跟之前的景致截然不同，這裡十分寬敞，沒有什麼沙，但在角
落的地方卻有一個沙堆，四周昏暗不明，你仔細的看了看四周，發現
在你眼前有個木梯，說不定能靠這木梯脫出這個深穴。
LONG
        );
set("exits", ([ /* sizeof() == 2 */
   "north" : __DIR__"howe",
]));
set("objects",([
__DIR__"npc/worm" : 3,
]) );
    set("no_clean_up", 0);
    set("item_desc", ([
        "木梯" : "這個木梯相當老舊，使用(use)時應該要小心。\n",
        "沙堆" : "你好奇的看了看這堆沙，不知裡頭有何東西。\n",
        "屍骨" : "你仔細瞧了瞧這堆屍骨，發現他身旁放著一袋銀兩，這…嘿嘿…\n",
    ]));
        setup();
}
void init()
{
    add_action("do_search","search");
    add_action("do_use","use");
}
int do_use(string arg)
{
       object me;
       me=this_player();
       if(arg != "木梯") return 0;
       else {
         message_vision("$N將木梯架在牆角，小心翼翼的往上爬。\n\n",me);
         me->move(__DIR__"hills2");
         return 1;
       }
}
int do_search(string arg)
{
   object me;
   me=this_player();
   if(arg != "沙堆") 
   {
     if(arg != "屍骨") return 0;
     else {
       if(query_temp("getsilver")) return notify_fail("你搜查了屍骨，但發覺並無特別之處。\n");
       else {
        message_vision("$N從這堆屍骨上搜出一些銀兩。\n",me);
        me->receive_money(2000);
        set_temp("getsilver",1);
        set("item_desc", ([
        "木梯" : "這個木梯相當老舊，使用(use)時應該要小心。\n",
        "沙堆" : "你好奇的看了看這堆沙，不知裡頭有何東西。\n",
        "屍骨" : "你仔細瞧了瞧這堆屍骨，並沒有什麼特別之處。\n",
        ]));
        call_out("delay",600,this_object());
       }
     }
return 1;
   }
   else {
        message_vision("$N仔細的搜查著沙堆，赫然發現裡頭有一堆屍骨。\n",me);
        return 1;
   }
}
void delay(object room)
{
    delete_temp("getsilver");
    set("item_desc", ([
        "木梯" : "這個木梯相當老舊，使用(use)時應該要小心。\n",
        "沙堆" : "你好奇的看了看這堆沙，不知裡頭有何東西。\n",
        "屍骨" : "你仔細瞧了瞧這堆屍骨，發現他身旁放著一袋銀兩，這…嘿嘿…\n",
    ]));
}
