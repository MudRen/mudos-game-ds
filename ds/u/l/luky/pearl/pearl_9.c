// Room: /u/l/luky/room/pearl_9.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�n��"NOR);
set("long", @LONG

�ġġġġ�   �A�����b���x���j��W�C���ǨӤ@  �ġġġġġ�
"  .   -   �ѫܿ@���Ĩ��A�ӧA�ݨ��\�h�_�I�̱q     -  '    "
:      -   �F�誺�@�ɫؿv�������X�ӡC�a�W�e��     -    "  :
= ."   -   �@�Ǯ�l�A���A�Q�_�p�ɫ�̷R�����@     -       =
==-  " -   �عC���K����l�C               -       - .   -==
�áááá�                   �áááááááááááááá�

LONG
);
set("exits", ([ /* sizeof() == 2 */
 "west" : __DIR__"pearl_10",
 "east" : __DIR__"pearl_8",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
