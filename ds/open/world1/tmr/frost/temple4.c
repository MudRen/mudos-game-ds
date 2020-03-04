// Room: /open/world1/tmr/freezetaoism/temple4.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�Ŧa");
	set("long", @LONG
�o�̬O�D�[�����Ŧa�A�Ŧa���C�ƨB�N���Ȥ�d�s�Ӧ����찲�H�A��
�[���D�H�m�k�I�N���a��C�Ŧa�n�������I�ǡC
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"temple7",
  "east" : __DIR__"temple6",
  "north" : __DIR__"temple3",
]));
        set("objects",([
                "/open/world1/npc/stake" : 2, // ���H

         ]) );
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
