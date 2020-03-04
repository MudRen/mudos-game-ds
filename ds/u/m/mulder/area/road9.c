// Room: /u/m/mulder/area/road9.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�s���o�� - �s���j��");
	set("long", @LONG
  �u�n�A�V�n���N�i��o�����V�m�ҡA�i��@�s�ꪺ�S�V�D�A
ı�o�o�ئ��ǩ_�ǡD�D�D�D�D�Aı�o�`�`���F��n���ݵۧA�D���A
�J�ӬݡA�o�{��ӳo�̬O�S���H�C�A�ݨ��o�̦��X�K�q�O�W�D
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road20",
  "west" : __DIR__"road8",
  "east" : __DIR__"shop5",
]));
	set("item_desc", ([
        "lamp post" : "�@�ӤQ���_�Ǫ��q�O�W, �γ\\�A�i�H�V���ݡC\n",
        "�q�O�W" : "�@�ӤQ���_�Ǫ��q�O�W, �γ\\�A�i�H�V���ݡC\n",
        ]));
	set("light",1);
	set("outdoors", "road");
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_knock", "knock");
}
	int do_knock(string arg)
{
	object me;
	me=this_player();
	if (arg != "�q�O�W" && arg !="lamp post" )
	return 0;

	else
	{
	message_vision(HIW"$N�V�q�O�W�V�F�X�U�A�o�{�h�F�@�����A��M���H��$P���J�h�I\n"NOR,me);
	me->move(__DIR__"blackshop");
	tell_room(environment(me),me->query("name")+"�V�q�O�W�V�F�X�U�A�o�{�h�F�@�����A��M���H��$P���J �h�I\n",me);
	return 1;	}
}
