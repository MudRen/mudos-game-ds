// Room: /u/l/luky/room/pearl_41.c
inherit ROOM;
void create()
{
set("short", "[1;35m�a��[m");
set("long", @LONG

  �@���i�o�Ӷ·t�ӤS���㪺�a���A�A���T���F�ӴHŸ�A�B�D��
�Ů���G��ɶ������ᵲ�F�C�o�̲צ~�����Ѥ�A�x���W���C�a
��ܥX�Y�ϬO�׹D�|���H�]�ܤֶi�ӳo�̡C���⪺���u�����ܷt
�F�A�A�{�b�u���@�ө��Y�A���N�O....�ߨ����}�o��!!

LONG
);
set("objects",([
__DIR__"npc/oten":1,
]));
set("exits", ([ /* sizeof() == 1 */
"up" : __DIR__"pearl_37",
]));
set("no_clean_up", 1);
set("light",0);
setup();
replace_program(ROOM);
}
