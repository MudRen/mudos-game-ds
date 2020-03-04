// Room: /open/world1/whoami/birdarea/village2.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�F�_[0m�A�L");
	set("long", @LONG
�A�u�۪d�g������F�o�̡A�D����ǬO��ƭZ�K����L�A����
���@�ǩ_�Ǫ����A�~�򩹪F�䨫�i�H�q���y�����A�q�o��i�H��
���F�䦳�ӥ��j�L�񪺥۫����A�٦��X�Ӭ�۩_�˲��A���H�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"village3",
  "west" : __DIR__"village1",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
