#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG "�y�����a" NOR);
        set ("long", @LONG

�H�H�խ��A�M�ַx���A�o�̥��O�y�����a�C�A�V�|�P��F��
�A�L�Ŧ⪺�a��A�I��ۯ¥զ⪺�Ѫ�O�A���㪺���M��n
�A�b�A���Ǥ@��N�R���k�H�A�����y�����K������--����(s
ophon)�C
LONG      );

        set("valid_startroom", 1);
        set("exits", ([
        "wiz": "/d/wiz/hall1",
        ]));
        setup();

}

void init()
{
write("�w����{�y�����a\n");
}
