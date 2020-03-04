// Room: /u/a/acme/area/portal.c

inherit ROOM;

void create()
{
	set("short", "���Z�j��");
     set("light",1);
	set("long", @LONG
�o�̬O���Z�Ъ��j���A�j���W���T�Ӥ����j�r�A�W���g�ۡi���Z�Сj
�A�j���O�κ���ҫسy�Ӧ��A�N��O�Τ����]�O�����}���A��O�O�H�ٹ�
�سy���������u�K�����򯫤u�ڡI
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hills3",
  "south" : __DIR__"corridor",
]));
    set("objects",([
       __DIR__"npc/guard1" : 4,
    ]) );
	set("no_clean_up", 0);

	setup();
}
