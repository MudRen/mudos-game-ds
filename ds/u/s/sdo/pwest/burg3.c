inherit ROOM;

void create()
{
	set("short", "���l�̤p��");
	set("long", @LONG
�y�������b�o�̡A�ݨ��u�۳o���񦳴X���p�A�СA���Ṋ̀��ص�
�p���A���ǫh�O�صۤ@�ǽ���A�ݨӧ��H�O�L�ۦ۵��ۨ����ͬ��C��
����ݹL�h�A���@��H�a�t�ߦb�A�Ф����C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg1",
  		"west" : __DIR__"burg4",
	]));

	setup();
	replace_program(ROOM);
}
