// Room: /u/l/luky/room/pearl_19.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

�ġġġġ�   �A�����b�e�����j��W�C���ǨӤH  �ġġġġġ�
"  .   -   �s�ټM���n���C�����ݰ_�ӫܷs�A���G       -     "
:      -   �O�̪�~���E�]�n���C���䪺����o�X       -  "  :
= ."   -   �X�X�����~�A�ϩ��m���P�Ҥ@��C�D��       -     =
==-  " -   �V��ǩ����}�ӡC               -         -   -==
�áááá�                   �áááááááááááááá�

LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_18",
"east" : __DIR__"pearl_20",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
