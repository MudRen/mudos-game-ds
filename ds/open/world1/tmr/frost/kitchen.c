// Room: /open/world1/tmr/freezetaoism/kitchen.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�p��");
	set("long", @LONG
�o�̬O�D�[���x�ޥ뭹���p�СA�𨤰�F����������A�Ф����@�Ӥj
���W�]�ﺡ�U���A���A�G�A�G�ӥ뭹�D�H��������N�����o���i�}��A
�G�Ӥj���l�]������u�u�a�b�i�N�����C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple5",
]));
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/cook-taoist":1,
                __DIR__"npc/obj/water":3,
        ]) );


	setup();
	replace_program(ROOM);
}
