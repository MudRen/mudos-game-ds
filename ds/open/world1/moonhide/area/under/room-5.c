#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�o�̪��Ů���G�M�b�ǡA���䦳�@�ǧɡA�Q���ͬ��Ϋ~�A�n����
�H�b�o��ͬ��J�Ӥ@�ݡA�@�䪺��W�G���\�h�貪�A�i��O�Y�ǤH��
�F�S�إت��ҷǳƪ��a�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/waist-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

