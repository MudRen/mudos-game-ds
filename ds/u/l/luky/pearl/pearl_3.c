// Room: /u/l/luky/room/pearl_3.c
inherit ROOM;
void create()
{
set("short","[1;32m�ï]��[m");
set("long", @LONG

����                                                   ����
�� :��    �ߺD�F�ï]�𴲵o�X�����~��A�A���������   ��: ��
�� : :�j�M���e�誺�ؿv���C���⪺����G���F�D������ �y: : ��
�� : :�j�ǡA�@���Q���i�R���p�H�~�ɱq�A�}�U�w�w���L �y: : ��
�� :��  �C�D���V�n�_�@�������ӥh�C                   ��: ��
����                                                   ����

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pearl_4",
  "north" : __DIR__"pearl_2",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
