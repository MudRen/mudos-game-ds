// Room: /u/l/luky/room/pearl_7.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�n��"NOR);
set("long", @LONG

�ġġġġ�   �A�����b���x���j��W�C�o�̪��~��  �ġġġġġ�
"  .   -   ���G�ä��b�N�A����ӡA�ٱy�v���ȵ�     -  '    "
:      -   ���C�x�H�o����򦳤����}�I�A�J�Ӥ@     -    "  :
= ."   -   �ݤ~���D�A��ӥL�̬O�b��"����"�C       -       =
==-  " -       -                          -       - .   -==
�ááááááááááááá� �áááááááááááááá�

LONG
);
set("objects",([
__DIR__"npc/cancer1":2,
]));
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pearl_8",
  "east" : __DIR__"pearl_6",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
