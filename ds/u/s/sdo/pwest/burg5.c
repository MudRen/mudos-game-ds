inherit ROOM;

void create()
{
	set("short", "���l����p��");
	set("long", @LONG
�A�����b���~���p���W�C�o���p�����F��N�O��J���A�ӻ�����
��_�䦳�@�y�p�s�A�X�_���O�A�p�s��������r�r���A�@�ʾ𳣨S��
�A���H���I�ôb�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"burg4",
  		"northwest" : __DIR__"burg10",
	]));

	setup();
	replace_program(ROOM);
}
