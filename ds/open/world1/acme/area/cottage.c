// Room: /u/a/acme/area/cottage.c

inherit ROOM;

void create()
{
	set("short", "�TĪ");
     set("light",1);
	set("long", @LONG
�o�O�@���έT��ҫسy�Ӧ����p�ΡA������ۥΦˤl�һs�������B
�p�ȡA����W���ۤG��u��M����A�Τ��o�S�����l�A�ϤHı�o���a���H
�a�ͬ��o�w�O�Q�����¾�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"farm1",
]));
    set("objects",([
       __DIR__"npc/woman.c" : 1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
