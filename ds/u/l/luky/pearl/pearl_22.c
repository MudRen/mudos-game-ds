// Room: /u/l/luky/room/pearl_22.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIM"����j�D"NOR);
set("long", @LONG

[33m                          �c�c�c
[m����[33m                  �c��[31m�ݡݡ�[33m�c[m                     ����
�� :�j�ġ�     �o�̬O����j�D�C��n�観�@�y  �ġġġĢy: ��
�� :�j: :    �ڦ����׹D�|�A�A���_���O����   : : :  �y: ��
�� :�j: :    �ө���C�n�観�X�ӥ��ƪZ�˪���   : : :  �y: ��
�� :�j�á�   ��u�èӦ^���޵ۡC              �áááây: ��
����                                                   ����

LONG
);
set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"pearl_23",
"north" : __DIR__"pearl_18",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
