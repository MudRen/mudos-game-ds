inherit ROOM;

void create()
{
        set("short", "水寒星洞");
        set("long", @LONG 
這裡的景觀，在這裡更成一色，所有的東西都蓋上了白色的沙
子，一片雪白的景色，在你心中印下的美好的印象，且中間還有著
一塊大的『石頭』，不知道是做什麼用的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room7", 
  "north" : __DIR__"room9",
]));
        set("light",1);
set("item_desc",([
"石頭":"長高寬都正好五寸的花鋼石，似乎可以搬開[take]的樣子，可是感覺滿重的！？\n",
]) );

        set("no_clean_up", 0);

        setup();
}
void init() 
{
        add_action("do_take","take");
}


int do_take(string arg)
{
        object me,x;
        x=new(__DIR__"npc/obj/paper");      
        if( !arg || arg!="石頭" ) return 0;
        me=this_player();
         if( me->query("level") > 39  )
        {
        message_vision("$N使力搬開巨石，瞧見一張牛皮紙。\n",me);
        x->move(environment(me) ); 
        }
        else
        {
        message_vision("$N使力搬開巨石，結果什麼也沒有發現。\n",me);
        }               
        return 1; 

        call_out("reborn", 900);
}

