// Room: /u/l/luky/room/pearl_8.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�n��"NOR);
set("long", @LONG

�ġġġġ�   �A�����b���x���j��W�C�n��O����  �ġġġġġ�
"  .   -   �ߤ@���@��[1;33m���][m�A���֤H�i�i�X�X���A     -  '    "
:      -   �ͷN���G�ܦn�C�γ\�A�i�H�b�o�̹J��     -    "  :
= ."   -   �A�h�餣�����Ԥͤ]�����w�C             -       =
==-  " -       -                          -       - .   -==
�ááááááááááááá� �áááááááááááááá�

LONG
);
set("exits", ([ /* sizeof() == 3 */
"west" : __DIR__"pearl_9",
"south" : __DIR__"pearl_35",
"east" : __DIR__"pearl_7",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
