#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"交叉路口"NOR);
        set ("long", @LONG
這裡是個十字交叉路口，有面牌子，可能是路標
(sign)也說不定。北邊的那座皇宮越來越近，你的心
也隨著心情起伏不定。
LONG);  
        set("no_fight",1);
        set("no_spells",1);
        set("no_magic",1);
        set("exits", ([
        "south": __DIR__"dragon3",
        "north": __DIR__"dragon8",
        "west" : __DIR__"dragon9",
        "east" : __DIR__"dragon10",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
                    皇宮
                     │
                     │
超龍第一分部─——— �� —————超龍第二分部
                     ︱
                     ︱
                  敵蘭斯大道
          
        ", ]) );
        setup();
        replace_program(ROOM);
}
