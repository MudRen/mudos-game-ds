// Room: /open/world1/tmr/freezetaoism/temple6.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�Ŧa");
	set("long", @LONG
�o�̬O�D�[�����Ŧa�A�Ŧa���C�ƨB�N���Ȥ�d�s�Ӧ����찲�H�A��
�[���D�H�m�k�I�N���a��C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"temple5",
  "west" : __DIR__"temple4",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
        set("objects", ([
                __DIR__"npc/taoist":1,
        ]) );


	setup();
	replace_program(ROOM);
}
