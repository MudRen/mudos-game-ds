inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
牆壁上的怪異文字到此消失，壁上的青綠色螢光芒也漸漸變淡，
遺跡到此似乎已經到了盡頭，要不要再多觀察一下，就看你自己的判
斷了。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-23",
                  "north" : __DIR__"room-27",
                  "west" : __DIR__"room-21", 
                  "south":"/open/world1/jangshow/flame_area/room",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}

