#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
這裡是一條陰森漆黑的通道，隱約聽到滴答的水聲，若有若無地
打擊你的心臟，突然一陣寒意從你背脊竄上腦門。你似乎感覺到有個
黑影從前方的轉角一閃而過，讓你心裡不禁顫了一下。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"startroom", 
            "north" : __DIR__"room2",
            "southwest" : __DIR__"room_1",
            "southeast" : __DIR__"room-1",]));
        set("no_light",1);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/leggings-guard" : 1,
           ]));
        setup();
        replace_program(ROOM);
}
