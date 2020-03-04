inherit ROOM;
void create()
{
        set("short", "泊浪村口");
        set("long",@LONG
你現在站在泊浪村的村口，或許你會覺得這個村莊十分平靜沒有獨
特之處，不過這卻是泊浪村中吸引人之處，在世上要找個生活能如此愜
意的地方已經很少了，因此也有許多高人選擇隱居於此，因此常常有傳
說此地有些武林先宿有著絕強本領，來此尋名師的人也絡繹不絕，而再
往前便是泊浪村內了。
LONG
        );
  
  set("objects", 
([__DIR__ "npc/aw-fout" : 1,
    ]));
  set("exits", ([
  "north" : __DIR__"po1.c",
  "south" : __DIR__"po.c",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 int valid_leave(object me, string dir)
{
      if( dir=="south" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}



