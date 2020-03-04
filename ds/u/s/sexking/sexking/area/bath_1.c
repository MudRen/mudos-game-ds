#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIM"一番"HIR"滋味"HIC"澡堂"NOR" ");
        set("long", @LONG
這是一間璧麗輝煌的澡堂，四周充滿著清新芳香，裡面便是澡堂了，
很多人很喜歡泡澡，因為不但可舒解壓力，調解身心，還可補充體力
，泡起來十分舒服，只要你錢夠的話，就向店主訂個位子進去泡澡吧。
LONG
        );
        set("exits", ([
  "east" : __DIR__"map_9",
  "west" : __DIR__"bath_2",
  "up" : __DIR__"bath_3",
]));
set("objects",([
       __DIR__"npc/mo" : 1,
    ]) );
 
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
        call_other( "/obj/board/fushun_b.c", "???" );
}

int valid_leave(object me, string dir)
{
        if( dir!="west" )return ::valid_leave(me, dir);

        if( dir=="west" && me->query_temp("suds") <=0 || !me->query_temp("suds") )
                return notify_fail("你還沒有付錢不能泡澡喲！\n");

        return ::valid_leave(me, dir);
}


