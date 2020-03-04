inherit ROOM;

void create()
{
        set("short", "石室");
        set("light",0);
        set("long", @LONG
你一腳踏進這裡，便覺事情不妙，只感覺這裡陰森森的，突然一股
陰冷的風往你臉上吹去，你不禁打了個哆嗦，在牆角你可以看到一俱棺
木，正前方也有二俱棺木，你只是想快快離開這裡................。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"pathway7",
        ]));
        set("no_clean_up", 0);

     set("item_desc", ([
         "棺木" : "這棺木看起來相當老舊，你似乎可以掀開(uncover)它。\n",
     ]) );
        setup();
}
void init()
{
        add_action("do_uncover","uncover");
}
int do_uncover(string arg)
{
        object me;
        object zombie;
            object zombie2;
        me=this_player();
        if(query_temp("kkzombie")) return notify_fail("什麼？\n");
        if(arg != "棺木" ) 
        {  
          notify_fail("你要掀開什麼？\n");
          return 0;
        } 
        else { 
          message_vision(
          "$N將前面的棺木打開，突然從棺木裡跳出了二俱殭屍....\n\n"
         "你聽見殭屍低聲嘶吼了幾聲.....\n"
         "突然你周圍的棺木都跳出了殭屍.....\n"
         "你突然聽見棺木裡一聲「轟隆」巨響，原來棺底塌陷了。\n"
         ,me);
        
        zombie=new(__DIR__"npc/zombie.c");
            zombie2=new(__DIR__"npc/zombie.c");
        zombie->move(__DIR__"h1");
              zombie2->move(__DIR__"h1");
        set("exits", ([
          "north" : __DIR__"pathway7",
          "down" : __DIR__"tnb",
        ]));
        set_temp("kkzombie",1);
        set("item_desc", ([
        "棺木" : "這棺木似乎已經被人打開了。\n",
        ]) );
set("long", @LONG
你一腳踏進這裡，便覺事情不妙，只感覺這裡陰森森的，突然一股
陰冷的風往你臉上吹去，你不禁打了個哆嗦，在牆腳你可以看到一俱棺
，正前方也有二俱棺木，但是已經被人打開了。
LONG
);
        return 1;
   }
}
