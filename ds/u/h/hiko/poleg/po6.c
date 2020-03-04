inherit ROOM;
void create()
{
        set("short", "泊浪村港口");        
        set("long",@LONG
泊浪村的港口並沒想像中的十分大，也沒看到許多大船，泊浪村的
的漁夫靠的是所謂的經驗和技巧，所以並沒有十分依靠物具的習慣，跟
一般靠著好性能的大船，卻不了解海的特性的漁夫不同，他們深知如何
在海上討生活的一切知識。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po6-1",
  "south" : __DIR__"po5"
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




int valid_leave(object me, string dir)
{
      if( dir=="north" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}






