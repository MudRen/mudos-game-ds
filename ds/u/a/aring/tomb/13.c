// Room: /u/a/aring/tomb/12.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�j�Ӷ�мX��");
        set("long", "�A�����b�@�y�X�Ӫ��W�Y�A�o�̲r�M�ߤF�@�Ӵä�A�ä�̭���
�G���ǷL���n���ǥX�A�x�l�Y���j�i�H���}"YEL"�ä�"NOR"�Ӭݬ�"HIR"(open)"NOR"�C
");
        set("light", "0");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"14.c",
  "west" : __DIR__"12.c",
]));

        setup();
        replace_program(ROOM);
}

