inherit ROOM;

void create()
{
	set("short", "���l�F��p��");
	set("long", @LONG
���b�����F�䪺�~��p���W�A�A�~�o�{�A��ӧ����O�ؿv�b�o�@
�j���s����������L�̪��@���p�Ŧa�W�C�Ӫu�ۤp����L�h�A���Y�S
�O�����b��L�����C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg7",
  		"west" : __DIR__"burg1",
	]));

	setup();
	replace_program(ROOM);
}
