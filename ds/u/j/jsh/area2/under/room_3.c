#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�I�㤣�����Ӫ��@�}�N���A�ް_�|�P�@�Ǹ޲������T�A�� . . .
����ť��H�B�ȴ̪����p�G�s�n�A��ӤW���N�O�H�B�ȴ̡C���䪺��
�_�j�X�w�w���D���C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/armor-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

