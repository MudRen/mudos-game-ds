inherit ROOM;
void create()
{
	set("short", "�m�Z���J�f");
	set("long", @LONG
�o�̬O�m�Z�����J�f�A�m�Z���D�n�O���e�������̤l�m�Z�\�һݡA
��M�]�i�H�ѵ��~�ӮȫȨϥΡA�����j�M���ɡA���|��o�̨��|��A
�a�W���ۤ@�������𸭡C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flurry39.c",
  "west" : __DIR__"flurry33.c",
  "east" : __DIR__"flurry35.c",
  "southup" : __DIR__"flurry32.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("mob_amount", 2);
	set("mob_object",({
  __DIR__"npc/apprentice",
}));
	set("outdoors","land");
	setup();
}
