// Room: /u/l/luky/room/pearl_15.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

�ġġġġ�   �o�̬O�ï]�_��A�]�O����������a  �ġġġġ�
"  .   -   �C���ǩ�F�X�Ӥj�c�l�A�γ\�O���a���n   -  '    "
:      -   �Ӱ��b���Ǫ��a�C�A���Gť�즳�H�b  �ġġ�  "  :
= ."   -   ���ܪ��n���A�i�O�èS���H�ڡH�γ\�O�y[33m���i�i��[m   =
==-  " -   �A����ı�a�C                      �y  �j  �y  ==
�áááá�             �áááááááááááâ��j  �y�á�
                                                 �áá�
LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_14",
"east" : __DIR__"pearl_16",
]));
set("item_desc",([
//  "box":"�@�Ӹ˪F��Ϊ��Žc�l�C\n",
//  "�c�l":"�@�Ӹ˪F��Ϊ��Žc�l�C\n",
]));
set("no_clean_up", 0);
set("light",1);
set("objects",([
__DIR__"obj/box1":1,
]));
setup();
}
