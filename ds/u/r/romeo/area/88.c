#include <ansi.h>
#include <path.h>
inherit ROOM;
void entercheck(object ob);
void create()
{
        set("short",HIR"�԰�X�a-�Ĥ@�h"NOR);
        set("long", @LONG
�o�̥|�P���O�G�ꪺ����A���n���~���S�X�ѡA�q��B�������Z��
�ݨӡA�L�����ӳ��O�Z�̡A�ӥB�Z�\�]���٤����A�ϥΪ����O�@�ǦW�Q
���Z���A�֧��ݡA���@�w���A�X�A���Z����C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r1",
  "east" : __DIR__"r3",
]));
        set("world", "undefine");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


