// Room: /u/l/luky/room/pearl_21.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

����                                                   ����
�� :�j�ġ�    �A�����b�ï]�j�D�W�C����O�@�y �ġġġĢ�: ��
�� :�j: :   �D�`���[���O��A���O���G�S�����i  : : :�y: : ��
�� :�j: :   �H�i�h�C���n�i�H�쥻���X�f�B�A  : : :�y: : ��
�� :�j�á�  �A���_�h�h�i�q�������ө���C   �áááâ�: ��
����                                                   ����


LONG
	);
set("objects",([
__DIR__"npc/pagurian":1,
]));
set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"pearl_2",
"north" : __DIR__"pearl_20",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
