/* jail4.c write by -Acme-
   update by -Acme-
*/

#include <room.h> //要加門要這一行
inherit ROOM;
inherit DOOR;

void create()
{
    set("short", "監獄");
    set("long", @LONG
這裡就是天城看管犯人的監獄，不管是大小老少，皆是關於此地
，四周盡是看管監獄的官兵，看守十分嚴謹，深怕被犯人脫逃。
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"jail3",
        "south" : __DIR__"injail",
    ]));

    set("objects",([
        __DIR__"npc/jailer5" : 3,
        __DIR__"npc/hing" : 1,
    ]));

    set("light",1);
    setup();
    create_door("south","牢門","north",DOOR_LOCKED,"jailkey");
}

int valid_leave(object me, string dir)
{
    if( objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");

    return ::valid_leave(me, dir);
}
