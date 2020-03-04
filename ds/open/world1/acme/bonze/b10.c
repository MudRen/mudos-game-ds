// Room: /open/world1/acme/bonze/b10.c

inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�A�����b�W�s�p�|���A�|�P���r�|ᣡA�ǥ۷D�o�A�H�٤����y��
���s�z�A�A���Y�@��A�s�ծm�I�A�������ѡA�ݤs�ӥh�A����������
�ҽk�[�W�N�����A�������~�q��ڡA�N�ﳾ�s�A�V�o�O�H���Y�D��
�P�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b9",
  "north" : __DIR__"b11",
]));
set("objects",([
  __DIR__"npc/dog.c" : 4,
]) );
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
