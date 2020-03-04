#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIM"一番"HIR"滋味"HIC"澡堂"NOR"中庭 ");
        set("long", @LONG
這裡是一番滋味澡堂的中庭，往南是男生的間，裡面便是澡堂了，
很多人很喜歡泡澡，因為不但可舒解壓力，調解身心，還可補充體力
，泡起來十分舒服，只要你錢夠的話，就向店主訂個位子進去泡澡吧。
LONG
        );
        set("exits", ([
  "north" : __DIR__"girl_suds",
  "south" : __DIR__"boy_suds",
  "east" : __DIR__"bath_1",
  ]));

        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="north" )return ::valid_leave(me, dir);

        if( dir=="north" && me->query("male")  || !me->query("male") )
                return notify_fail("那是女生去的地方，男生止步！\n");
        if( dir!="south" )return ::valid_leave(me, dir);

        if( dir=="south" && me->query("gender")  || !me->query("male") )
                return notify_fail("那是男生去的地方，女生止步！\n");

        return ::valid_leave(me, dir);
}

