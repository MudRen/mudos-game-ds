// Room: /tmr/garea/forest5.c

inherit ROOM;

void create()
{
	set("short", "�ծ|");
	set("long", @LONG
�A���b�˪L�����@���p�|�A�b�A�k�観�ʤQ�����j�B�a�Ѫ�����A��
�Ӥֻ��]���Ʀʦ~�����֡A�ƵM���ߡA���M���D���s�쪺�𷧡C�������~
�A�o�O�F�L�n�T�A����p�|�R�o���I�A�A�զ�ť�쪺�n���A�u���A���I�l
�n�A�O�H���Ѧa���q�M�C
LONG
	);
	set("no_clean_up", 0);
	set("item_desc",([
	"����":"���A�Y�W��ƤسB�A���ڬ�X���ʾ�K�A���G�i�W�h(jump)�ݬݡC\n",
	]) );

	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest3",
	  "northwest" : __DIR__"forest7",
	]));
	set("outdoors","forest");
      set("objects",([
         __DIR__"npc/obj/firewood": random(5),
      ]) );
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me=this_player();

	if (!arg || arg !="�ʾ�K" ) return 0;
	message_vision("$N�o�@�n�ܡA�ĤO���W����W���@�ڲʾ�K�C\n",me);
	me->move(__DIR__"tree_up");
	tell_room(environment(me),me->query("name")+"���F�W�ӡC\n",me);
	return 1;
}
