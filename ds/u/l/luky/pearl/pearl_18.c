// Room: /u/l/luky/room/pearl_18.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

  �o�̬O�ï]�_��P[1;33m    �c�c�c�c�c�c�c[m  ����j�D����e���f�C��
�n�K�O����j�D�C[1;33m  �c[0;33m��[31m  �ݡݡݡݡ�[1;33m�y  �c[m  �_�䦳�Ӻ�o���D��
�ΡC�����ѪF[33m  ��[1;33m  �ááááááááây[m  �V�詵���C
�ġġġġġġġ�[33m�i[m��[1;37m  �����[���D���[33m  �y[m�ġġġġġġġġġ�
"  .   -          �y[1;33m     �ġġġ�[m     ��:          -  '    "
:      -          �y ��[33m  ��[1;31m�P�P�P[33m��[m�� �j:          -    "  :
= ."   -          �y[33m     �i[m ������[1;33m �j[m �j:          -       =
==-  " -       -  �y[33m     �i[m �x�x�x[1;33m �j[m �j:  -       - .   -==
�ááááááááááááááááááááááááááááá�

LONG
);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"pearl_22",
"north" : __DIR__"pearl_28",
"west" : __DIR__"pearl_17",
"east" : __DIR__"pearl_19",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
