// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "�F�a");
set("long", @LONG
�A�����b�@���n�n���F�a�W�C�A�ݨ��_�褣���B���Ӷ�, �j���O�Ψ��A
�滷�誺�[����a�C�P��G���F�U���U�˪������G����, �o�̤@�I�n�����S��
, �w�R�����H�`��, �A�Pı����G�����򯫯����ͪ��b�ʵ��ۧA���@�|�@�ʡC
LONG
);
set("exits", ([ 
  "west" : __DIR__"sea3",
  "north" : __DIR__"sea5",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
