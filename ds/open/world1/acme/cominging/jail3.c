/* jail3.c write by -Acme-
   update by -Acme-
*/

inherit ROOM;

void create()
{
    set("short", "�ʺ�");

    set("long", @LONG
�o�̴N�O�ѫ��ݺޥǤH���ʺ��A���ެO�j�p�Ѥ֡A�ҬO���󦹦a
�A�|�P�ɬO�ݺ޺ʺ����x�L�A�ݦu�Q���Y�ԡA�`�ȳQ�ǤH��k�C
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
        return notify_fail("�A�Q����צ�F�h���C\n");

    return ::valid_leave(me, dir);
}
