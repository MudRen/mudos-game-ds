// This is a room made by roommaker.

inherit ROOM;

void create()
{
set("short", "������G��");
set("long", @LONG
�o�̪��x���G���F�ǹ�, ��W�K�F�X���������𮧡C�b���t�����u���A�o
�{����W�g�F�X�y�g��, �ѩ�~�N�Ӥ[���F�H�ܩ󤣤֦r���w�g�Q���ƦӼҽk
���M�F�C�������~, �o�Ӫſ����ӱ趡��b�O�S������n�r�d���C
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
]));
set("exits", ([ 
  "up" : __DIR__"tower3",
  "down" : __DIR__"tower",
]));
set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
