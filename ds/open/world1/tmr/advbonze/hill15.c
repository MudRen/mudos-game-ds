// Room: /open/world1/tmr/advbonze/hill15.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v�W�A�A�i�H�ݨ쩵�۩��_�ӳq��
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A�ݼˤl�u��
�U����G�Q�Ӷ����۱���A�A�����M�q�p���@�p�����̬ݨ�M������
����u���o�X�ӡA�A�Q�o�D���u�Ӯg�����ƵM�A�D�`���ΪA�A���G�]
�ѰO�F���s������h�ҡC
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill16",
  "southdown" : __DIR__"hill14",
]));

	setup();
	replace_program(ROOM);
}
