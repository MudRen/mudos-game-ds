inherit ROOM;

void create()
{
	set("short", "�}�]���q�D");
	set("long", @LONG
�A���b�o�̡A�a����W�L�z������A�~�o�{��Ө���e������o
���٬O�|�|�X���@���q�D�A�ݨӳo�Ӥs�}�c�y���_�S���A�A���T�P��
�y���̪�����C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"gcave7",
  		"southwest" : __DIR__"gcave4",
  		"southeast" : __DIR__"gcave5",
	]));

	setup();
	replace_program(ROOM);
}
