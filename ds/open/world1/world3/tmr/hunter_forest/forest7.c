// Room: /tmr/future/hunter_forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "�L���Ŧa");
	set("long", @LONG
�A�����b�˪L���@�B�Ŧa�A�b�ͪ��@�K���˪L�A��b��������o��@
�B���諸��a�A�u�O�A���G�o�{���a�����ۤ@�ӤS�@�Ӥ@���p�}�ޡA�@
���ݥh�A�ֻ��]���T�B�|�Q�Ӥ��h�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest5.c",
	]));
	set("item_desc",([
	"�p�}��":"���u���j����e�A�O�H�n�_���Y�쩳������F��C(embed)\n",
	]) );
	set("no_clean_up", 0);
	set("world", "future");
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_embed","embed");
}

int do_embed(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="�p�}��" ) return 0;
	message_vision("$N�����F����Y���i�F�a�W���@�Ӥp�}�ޡA���G���G�S����ơC\n",me);
	return 1;
}
