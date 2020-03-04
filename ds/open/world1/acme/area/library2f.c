// Room: /open/world1/acme/area/library2f.c

inherit ROOM;

void create()
{
	set("short", "�G��");
	set("long", @LONG
�o�̬O�îѻժ��G�ӡA���B�o�b���ѳ��S���A�ˬO�@���J��o��
�ݦp�ͪ����H�A���O�����Z�̤l�m�ߪZ�\�Ϊ��a�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"library",
]));
        set("light",1);
    set("objects",([
            __DIR__"npc/woodman" : 6,
    ]));
	set("world", "past");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
