inherit NPC;
void create()
{
	set_name("���H",({ "woman","���H" }));
    set("long","�ѱ��̤l���a���C\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: command,"sing" :),
}) );
	setup();
	add_money("coin",10);
}
