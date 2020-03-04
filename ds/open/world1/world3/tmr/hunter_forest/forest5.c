// Room: /tmr/future/hunter_forest/forest5.c

inherit ROOM;

void create()
{
	set("short", "�H���L��");
	set("long", @LONG
�A���B�b�@�������H�������A�|�g���ۯS������L�A��O��o���H��
��C�A���g�N���o�{�b�|�P��¶����L�A���M���ʵo�X������~����A��
�F���ʤj��ܥX�o�ʾ𪺦~�֤w���Ʀʦ~���[�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"forest7",
  "south" : __DIR__"forest3.c",
  "north" : __DIR__"forest6.c",
]));
	set("item_desc", ([ /* sizeof() == 2 */
   "������~����" : "�A��_�Y�ӥJ�Ӧa�[��F�o�ʩ_������A���G�o�{��W���F�@�ǪG��I�H
",
  "�G��" : "�@���񴲵۵�����~���G��A�@�}�L���j�ӡA�A���G�i�H�D��@�ѵΪA�������C
",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
}

void init()
{
	add_action("do_shake","shake");
}


int do_shake(string arg)
{
	object me,ob;
	me=this_player();

	if(!arg || arg!="������~����")
		return 0;
	message_vision("$N���F�o�X������~���j��A�ĤO���n�F�_�ӡC\n",me);
	if(query("shake_ok") )
		return notify_fail("���G����Ƥ]�S�o�͡C\n");	
	else {
		message_vision("�g�L�@�}�n�ʡA��W���G���U�F�@�ӵo�X������~���F��C\n",me);
		ob=new(__DIR__"obj/fruit");
		ob->move(__FILE__);
		set("shake_ok",1);
	}	
	return 1;
}

void reset()
{
	if(query("shake_ok") )
		delete("shake_ok");
}
