// Room: /u/t/tmr/area/nb4.c

inherit ROOM;

void create()
{
	set("short", "�b�l����");
	set("long", @LONG
�b�l����F�o�̴N�w�쩳�A���_�i�ݨ줭���˩СA�����|���@�j�q�Z
���A�N�O�����\�̰����H�]���@��ӤΡC�b�A���䰱�ۤ@���p��b����
�A�ݨӥi�H�W�h�@�@�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nb3",
  "enter" : __DIR__"bship",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
