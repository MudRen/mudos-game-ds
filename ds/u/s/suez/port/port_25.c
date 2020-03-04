#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","商業大道");
        set("long",@LONG
從兩旁往南北延伸的長綠樹隨著海風搖晃著，潔淨的街道是兩旁商家
每日努力的結果，雖然說這裡完全是商業的世界，但是由於不想被說成只
愛賺錢的守財奴，商家都很努力將這裡整理的舒適美觀，也的確讓前來買
賣的人感覺好很多。不過隱藏的犯罪和當地人的排擠仍然讓商家十分頭痛
。
LONG 
);
        set("exits",([
            "north":__DIR__"port_23",
           // "south":__DIR__"port_34",
            "east":__DIR__"port_26"
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( dir=="east" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

