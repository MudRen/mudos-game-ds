inherit ROOM;
void create()
{
        set("short", "密室");
         set("light",1);
        set("long", @LONG
這裡是一間小密室，滿地盡是塵土，四面土牆剝落殆盡，眼前有一張
石製小桌，小桌旁坐著一俱骸骨，骸骨的頭顱呈現著一股黑氣，顯然是身
中巨毒而亡，密室的東邊有個出口。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tnb",
]));
        set("no_clean_up", 0);
      set("item_desc", ([
        "小桌" : "這個石製小桌相當的陳舊，桌上有張紙。\n",
        "骸骨"  : "這俱骸骨頭上破了個大洞，可見殺此人者力大無窮。\n",
        "紙"  : "這張紙已泛黃，上頭寫了幾行字，你可以拿起來(take)看。\n",
      ]));
      setup();
}
void init()
{
    add_action("do_search","search");    
    add_action("do_take","take");
}
int do_search(string arg)
{
     object me;
     object peachsword;
     me=this_player();
     if(query_temp("getsword"))return notify_fail("你東翻西找，但是卻沒找到什麼。\n");
     if(arg != "骸骨") 
     {
      return 0;
     }
     else {
     message_vision("$N仔細瞧了瞧骸骨，發現骸骨的手上拿著一把劍，劍順勢掉在地上。     \n\n",me);
        peachsword=new(__DIR__"npc/wp/peachsword.c");
        peachsword->move(__DIR__"secret.c");
        set_temp("getsword",1);
        call_out("delay",600,this_object());
        return 1;
        }
}
int do_take(string arg)
{
    object me;
    object paper;
    me=this_player();
        if(query_temp("getpaper"))return notify_fail("什麼？\n");
     if(arg != "紙") 
     {  
      return 0;
     }
     else {
     message_vision("$N從桌上拿起紙。\n\n",me);
     paper=new(__DIR__"obj/paper.c");
     paper->move(me);
     set_temp("getpaper",1);
     set("item_desc", ([
        "小桌" : "這個石製小桌相當的陳舊，但桌上卻空無一物。\n",
        "骸骨"  : "這俱骸骨頭上破了個大洞，可見殺此人者力大無窮。\n",
      ]));
        call_out("delay",600,this_object());
        return 1;
        }
}

void delay(object room)
{
      delete_temp("getsword");
      delete_temp("getpaper");
      set("item_desc", ([
        "小桌" : "這個石製小桌相當的陳舊，桌上有張紙。\n",
        "骸骨"  : "這俱骸骨頭上破了個大洞，可見殺此人者力大無窮。\n",
        "紙"  : "這張紙已泛黃，上頭寫了幾行字，你可以拿起來(take)看。\n",
      ]));
      set("light",1);
}
