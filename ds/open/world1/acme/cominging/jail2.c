/* jail2.c write by -Acme-
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

    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"jail3",
        "south" : __DIR__"jail1",
    ]));

    set("objects",([
        __DIR__"npc/jailer3.c" : 3,
    ]) );

    set("light",1);
    setup();
}

int valid_leave(object me, string dir)
{
    if( objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");

    return ::valid_leave(me, dir);
}
