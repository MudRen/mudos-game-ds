// Room: /u/l/luky/room/pearl_17.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

[1;31m                                     �d�d�d�d�d�d�d�d
                                   �y[41m�i�i�i�i�i�i�i�i[40m�j[m
�ġġġġ�   �A�����b���x���j��W�C��[30;47m���ݡݡݡݡݡ���[m�ġġ�
"  .   -   �\�h��a���~���H�b�o�̻E  [30;47m��[35m �۰ʳc���[30m ��[m     "
:      -   �|��ѡC�A�ݨ���䦳�@��  [30;47m���ݡݡݡݡݡ���[m  "  :
= ."   -   �j�Фl�A�H�ӤH�����n����  [30;47m����������������[m     =
==-  " -   �x�C���䦳�@�x�۰ʳc���  [30;47m����������������[m   -==
�áááá� �C                      ��[30;47m��[32mInsert coins[30m��[m�áá�
                                     [30;47m�ࢤ������������[m


LONG
);
set("objects",([
__DIR__"npc/playboy":1,
__DIR__"obj/automat":1,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_16",
"east" : __DIR__"pearl_18",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
