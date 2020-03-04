// Room: /open/world1/tmr/advbonze/hill13.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v�W�A�A�i�H�ݨ쩵�۩��_�ӳq��
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A�ݼˤl�u��
�U���줭�Q�Ӷ����۱���A�A�����M�q�p���@�p�����̬ݨ�@������
����u���o�X�ӡA�A�Q�o�D���u�Ӯg�����I�ΪA�C
LONG
	);
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill14",
  "south" : __DIR__"hill12.c",
]));

	setup();
	replace_program(ROOM);
}
