/* way4.c write by -Acme-
   update by -Acme-
*/

inherit ROOM;

void create()
{
    set("short", "���D");

    set("long", @LONG
�o�O�@���q���ʺ������D�A�|�P�w�R���`�A�Ʀܥiť���ۤw��Ŧ
���ʤ��n�A���G�@�Ǧ��H�L�ɵL��b�`�N�A���@�|�@�ʡA�A���ѱo�x
Ÿ����B�B�B����C
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
        return notify_fail("���̥u�����a�~��i�h�C\n");

    if( dir == "north" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");

    return ::valid_leave(me, dir);
}
