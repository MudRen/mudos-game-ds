#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIC"������"NOR);
        set("long", "�j�Ѫ��󴺡A�Ӥj���ۿj�A�o���������j�@���ڬw����D�R����
�j�N�s�M���ҼˡC��ƪ����}���F�Z�����K���A�a�U�E�ۥ���ᰵ
���a��A�b�𩳤U���ۤ@�Ǳ��Q�b�ͱ��A�]���a�H�@�_�ӽ��媺�A�@
�T���R���Ϯ���{�b�A�����e�C�_�䦳����W�ߤ@�����f�E�C
");
        set("exits", ([
        "west":__DIR__"a10",
        ]));
        set("outdoor",1);
        setup();
        replace_program(ROOM);
}

