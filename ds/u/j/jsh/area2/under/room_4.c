#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�C���o�̳��M�������A�ӥB���Ʋ��h�A�b�������P�ɡA�g�ѯ�
�H���祴�A���U�F�ӲӪ��쯻�A�B�a�I�����A���o���K�Ǥ��b����ŵ
����^�A�ϦӦ��جK�Ѫ��P���A�u�O�A�o�̬O�K�ǭC�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room4",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/hands-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

