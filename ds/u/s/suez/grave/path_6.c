// Room: /u/s/suez/grave/path_6.c

inherit ROOM;

void create()
{
	set("short", "���Ѿb��");
	set("long", @LONG
���B�`������E���A�ҥH��H�̫ȴN�٦������ѡC�N�b�������`�B�A
���������i�H�ݨ��@�ǫΪ١A���O�@�Ǧb�y�s�}�U�Q�ͬ����A�o�����M��
�O�緽�m�A���O�]�O���@�f�H���P�Ҫ��w�M�֧Q�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path_5",
  "eastup" : __DIR__"path_7",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
