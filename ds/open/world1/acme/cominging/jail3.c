/* jail3.c write by -Acme-
   update by -Acme-
*/

inherit ROOM;

void create()
{
    set("short", "監獄");

    set("long", @LONG
這裡就是天城看管犯人的監獄，不管是大小老少，皆是關於此地
，四周盡是看管監獄的官兵，看守十分嚴謹，深怕被犯人脫逃。
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"jail2",
        "south" : __DIR__"jail4",
    ]));

    set("objects",([
        __DIR__"npc/jailer4" : 4,
    ]));

    set("light",1);
    setup();
}

int valid_leave(object me, string dir)
{
    if( objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");

    return ::valid_leave(me, dir);
}
