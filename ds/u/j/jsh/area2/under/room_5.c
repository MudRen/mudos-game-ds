#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
此室是最後兩間密室之一，滿地都是籃子，籃子裡面裝的都是青
菜，原來定期都會有人拿東西下來。 這裡的空間寬廣許多,四周有一 
些蒲團，竹蓆,衣物.. 等等，牆角上方微微透出日光，原來是個拳頭
大的通風孔，日光灑落正照在牆角的一個大瓦盆，盆中有棵不知名的
植物。上面結有大小不一的果實 。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/finger-guard" : 1, 
 __DIR__"npc/obj/fire-fruit" : 1, 
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

