// Room: /open/world1/tmr/advbonze/hill4.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p�Фe��");
	set("long", @LONG
�A�����b�@���ᬰ�T���������s���A�D����Ǫ����F�A��A�L��
�A�����b�@���s���W�A���_���D�������G���p���A���F�_�誺�s����
�f�P�l�W�g�ۡG�u���ⶳ�p���v�A����_�誺�D���������B�����p�x
�q�A������h�A�q�[���M�}���A���o���A�@�ؤ��F���R���֪��Pı�C
LONG
	);
	set("world", "past");
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"hill5",
  "northwest" : __DIR__"hill6.c",
  "south" : __DIR__"hill3.c",
]));

	setup();
	replace_program(ROOM);
}
