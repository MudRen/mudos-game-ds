/* way4.c write by -Acme-
   update by -Acme-
*/

inherit ROOM;

void create()
{
    set("short", "長道");

    set("long", @LONG
這是一條通往監獄的長道，四周安靜異常，甚至可聽見自已心臟
跳動之聲，似乎一旁有人無時無刻在注意你的一舉一動，你不由得膽
顫心驚、步步為營。
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"way2",
        "north" : __DIR__"jail1",
    ]));

    set("light",1);

    set("objects",([
        __DIR__"npc/jailer1.c" : 3,
    ]));

    setup();
}

int valid_leave(object me, string dir)
{
    if( dir=="north" && !userp(me) )
        return notify_fail("那裡只有玩家才能進去。\n");

    if( dir == "north" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");

    return ::valid_leave(me, dir);
}
