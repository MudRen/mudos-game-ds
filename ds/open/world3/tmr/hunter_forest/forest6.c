// Room: /tmr/future/hunter_forest/forest6.c

inherit ROOM;

void create()
{
	set("short", "�s�}�e");
	set("long", @LONG
�b�A���_�䪺�����B���y�}�F�p�}���s�C�A�A�i�H�M����ť��u���v
���ʪ��s�n�q�p�s�}�̶ǤF�X�ӡC�A�y�L�a�ݤF�ݥ|�P�A�ѩ�Ӫ����ͪ�
�Z���A�L�����G�w�S���i�e�H�q�檺�D���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"forest5.c",
	]));
	set("item_desc",([
	"�p�s�}":"�@�Ӷ��n�Y���~���o�i�h���p�s�}�C(grovel)\n",
	]) );
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");
	setup();
}

void init()
{
	add_action("do_grovel","grovel");
}

int do_grovel(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="�p�s�}" ) return 0;
	message_vision("$N�Y�_���l�A���i�F�p�s�}�C\n",me);
	me->move(__DIR__"hole1");
	tell_room(environment(me),me->query("name")+"�q�s�}�~�Y���F�i�ӡC\n",({me}) );
	return 1;
}
