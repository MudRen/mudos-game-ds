/* 私塾 */
inherit ROOM;
void create()
{
        set("short", "小私塾");
        set("long",@LONG
這是一個小小的私塾，在這教導的老師，聽說是上一任縣太爺的左
右手，而教出來的學生大都大名鼎鼎，不過也有很多是不有名的人，在
屋外鳥語花香，滿天花雨，不亦美乎。
LONG
        );
        set("exits", ([
  "south" : __DIR__"sidestreet3.c",
]));
        set("objects", ([
  __DIR__"npc/teacher.c" : 1,
]));
        set("no_clean_up", 0);
        set("light", 1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_cast",1);
        set("no_kill",1);
        set("no_fight",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir == "south" && me->query_temp("Confucius") )
                me->delete_temp("Confucius");
        return ::valid_leave(me, dir);
}
