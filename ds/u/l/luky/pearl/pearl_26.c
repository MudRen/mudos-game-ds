// Room: /u/l/luky/room/pearl_26.c
inherit ROOM;
void create()
{
set("short", "[1m�L�ҫ�[m");
set("long", @LONG

                                                  ��
�ġ�        �o�̬O�ѹp���q�K������      �ġġġĢ�
" �y���ġīȹL�ҫǡA���F�w���]�����ġĢ��j'    "�j��
: �y�y    �Ҷq�A�Ҧ��[���ȳ�������    �j�j  "  :�j�i
= �y�y    ���Y�檺�ˬd�C�\�h�L�k�J    �j�j     =�j�i
: �y���áùҪ��H�����_�a���ѹp���áâ��j   -==�j�i
�á�      �U���Y�V���W�w�C              �áááâ��i
                                                  �âj
                                                    ��

LONG
);
set("objects",([
__DIR__"npc/passenger":1,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_27",
"east" : __DIR__"pearl_12",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
