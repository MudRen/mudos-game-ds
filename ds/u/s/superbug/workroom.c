// Room: /u/s/superbug/workroom.c

inherit ROOM;

void create()
{
	set("short", "�j�Τ��a");
	set("long", @LONG
�o�O�j�Ϊ��u�@�ǡA���a�����ΧU�⥿���L���N��Ʈ����j
�ΡA�u�ݨ��j�ΧV�O���u�@�ۡA��Ӧb�L���ᦳ�ۤ@�i�_(tmr)
���Ӥ����n�ۥL�A�A���T���j�ξ�ߵۥL������...
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "train" : __DIR__"train/1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
 call_other("/obj/board/superbug_b", "???");
}
