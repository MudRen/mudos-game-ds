// Room: /future/area/stihy.c

inherit ROOM;

void create()
{
	set("short", "���K�[�u�t");
	set("long", @LONG
�o�O�@�����W�Ҫ��u�t�A�M���ΨӦ��ʦ��a�ұĶ��ӱo�q���C�A�i
�H�ݨ������q�u�z�ۤ@�U�S�@�U���q���ӳo�̳c��A�u�t����n�ۦp�s��
���q���A�q�s�Ǭ���ۼƤQ�x�B�q�����H�A���b�]���q���C
LONG
	);
	set("world", "future");
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"digging_road2",
	]));
	set("no_clean_up", 0);
	set("light",1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/collector" : 1,
                  __DIR__"npc/obj/iron_shovel" : 1,
        ]));


	setup();
	replace_program(ROOM);
}
