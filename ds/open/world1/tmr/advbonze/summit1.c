// Room: /open/world1/tmr/advbonze/summit1.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p��-���x����");
	set("long", @LONG
�A�����b�ⶳ�p���W���@�B�H�y���x���A�ѩ�a�ΰ��m�A��ԫD�`��
�H�N�A���Y�Q�����a�����n�F�@�h�����C�b���x�������ѩ^�ۤ@�L���Q��
�H���������j�p�Ӫ��򹳡A���B�s�p�̤���Ӯg�L�ӡA�n�����Aı�o����
�{�{�A���d���A��Ӳ����X�G�ָC���}�F�C
LONG
	);
	set("current_light", 1);
	set("no_recall",1);
	set("no_clean_up", 0);
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"summit2",
  "northwest" : __DIR__"summit3",
  "south" : __DIR__"hill17",
    "north" : __DIR__"summit6",
  "southwest" : __DIR__"summit5",
  "southeast" : __DIR__"summit4",
]));

        set("objects", ([
                __DIR__"buddha-statue.c" : 1,
                ]));


	setup();
	replace_program(ROOM);
}
