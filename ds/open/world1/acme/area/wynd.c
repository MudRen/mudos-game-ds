// Room: /u/a/acme/area/wynd.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�A�����b�@���p�Ѹ̡A�o�̪��H����㪺����D�}�֡A���n�i����x
����D�A�_��i�ݨ�@�a��Q�A��Q���f�W���ۤ@�i����СA�W�Y�g�ۡu
�۰]�i�_�v�A�|�Ӫ����j�r�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"street2",
  "north" : __DIR__"popshop",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
