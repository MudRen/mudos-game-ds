inherit ROOM;

void create()
{
	set("short", "���l�p�s��");
	set("long", @LONG
�o�̬O�X���Фl��X�Ӫ��Ŧa�C���Ӥ]�O���H���|�����ҡA�]��
�a�W�i�H�ݨ�������N�L������C�_�䪺�ЫάO�o�ӧ����̰����Фl
�A�ݨӥi�H�i�h�������������C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"house1",
  		"east" : __DIR__"house2",
  		"west" : __DIR__"house3",
  		"south" : __DIR__"burg1",
	]));

	setup();
	replace_program(ROOM);
}
