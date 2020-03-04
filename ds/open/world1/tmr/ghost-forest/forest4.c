// Room: /u/t/tmr/area2/forest4.c

inherit ROOM;

void create()
{
	set("short", "�L���p��");
	set("long", @LONG
�A�����b�@���L���p���W�A�}�U�񪺬ҬO�H�۬\���A�L�����ɩبӤ@
�}�D���A�j�۪K���P�P�@�T�A���Y�W��A�u����찪�q�J���A���P���
����۱��աA���P�������ǳ\�Żؤ����z�S�ۤ@�u�����u�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest2",
	  "northwest" : __DIR__"forest6",
	]));

          set("outdoors","forest");
	set("no_clean_up", 0);
      set("objects",([
         __DIR__"npc/obj/firewood": random(5),
      ]) );
	setup();
	replace_program(ROOM);
}

