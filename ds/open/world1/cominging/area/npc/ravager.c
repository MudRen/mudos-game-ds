inherit NPC;
void create()
{
	set_name("�}�a�H", ({ "revage man", "man" }));
	set("long","�@�ӱM���b�U�a�}�a���~���H�C\n");
	set("level",  13);
	set("age", 30);
	set("chat_chance", 5);
	set("chat_msg", ({
  this_object()->name()+"�������b�Ǥ��úV�å��I\n",
  (: command,"pk" :),
}));
	setup();
}

void init()
{
	add_action("do_kill","kill");
}

int do_kill(string arg)
{
    if( arg != "man" || arg != "revage man" ) return 0;
	else
	{
		command("snort");
		return 0;
	}
	return 0;
}
