// Room: /open/world1/tmr/freezetaoism/temple3.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�Ŧa");
	set("long", @LONG
�o�̬O�D�[�����Ŧa�A�Ŧa���C�ƨB�N���Ȥ�d�s�Ӧ����찲�H�A��
�[���D�H�m�k�I�N���a��C
LONG
	);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"temple1",
  "east" : __DIR__"temple5",
  "south" : __DIR__"temple4",
]));
        set("objects", ([
                __DIR__"npc/taoist":2,
                "/open/world1/npc/stake" : 2, // ���H

        ]) );


	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
