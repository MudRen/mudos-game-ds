#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"�i "HIC"�E�ׯ��] "HIW"�j�� �J�f"NOR);
        set("long", @LONG
�b�A���e�u���@���L��L�ڪ��۾�, �b�۾����|�P���ۼh�h��������
¶, ���A�û����ݤ��M���o�䪺����, �ϱo�P�򳣥R���F�����P�P��E��
, �����ǨӤ@�}�}�ʪ������q�n���A���g�����^��̰��I�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "enter" : __DIR__"k1.c",
]));
 set("objects",([
                "/u/r/romeo/area2/npc/guard_lee":1,
 ]));
                

        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
