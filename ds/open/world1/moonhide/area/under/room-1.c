#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
���G�Ҧ����K�ǳ����@�쯫�����H�A�����ٷ|�������~�X�S�A��
�A�N�n�ݧA�ۤ��۫H�F�C���ǧj�۷L�L���D���A���Hı�o�M�n�A�D��
�A�I�����߱��A�@���ӪšC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/mask-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

