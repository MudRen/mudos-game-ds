/* jail4.c write by -Acme-
   update by -Acme-
*/

#include <room.h> //�n�[���n�o�@��
inherit ROOM;
inherit DOOR;

void create()
{
    set("short", "�ʺ�");
    set("long", @LONG
�o�̴N�O�ѫ��ݺޥǤH���ʺ��A���ެO�j�p�Ѥ֡A�ҬO���󦹦a
�A�|�P�ɬO�ݺ޺ʺ����x�L�A�ݦu�Q���Y�ԡA�`�ȳQ�ǤH��k�C
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
    create_door("south","�c��","north",DOOR_LOCKED,"jailkey");
}

int valid_leave(object me, string dir)
{
    if( objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");

    return ::valid_leave(me, dir);
}
