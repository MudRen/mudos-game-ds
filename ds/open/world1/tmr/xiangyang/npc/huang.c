// huang.c
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("���T", ({"huang rong", "huang", "rong"}));
	set("gender", "�k��");
	set("age", 36);
	set("long", "�o�O�_�L���t���ҤH�A�F�����Įv���R�k�A�e���������D�C\n");

	set("attitude", "peaceful");
	   
	set("per", 30);
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 0);
	   
	set("combat_exp", 500000);
	set("score", 0);
	   
/*
    set_skill("force", 120);
    set_skill("bibo-shengong", 120);
    set_skill("unarmed", 120);
    set_skill("luoying-zhang", 120);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 120);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying-shenjian", 120);
    set_skill("qimen-wuxing", 120);
    set_skill("cookery", 200);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
*/
	set("inquiry",([
		"���y"     : (: ask_me :),
		"�i���J��" : (: ask_me :),
	]));	
	set("book_count", 1);	   
	create_family("���q", 2, "�̤l");
	setup();
//      carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
//      carry_object("/kungfu/class/taohua/obj/shudai")->wear();


}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/�T")) return 0;
	ob->add_temp("mark/�T", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/�T"))
		who->set_temp("mark/�T", 0);
	if (ob->query("money_id") && ob->value() >= 1000)
	{
		message_vision("���T�P�N���I$N�@�ǲi�����������D�C\n", who);
		who->add_temp("mark/�T", ob->value() / 500);
		return 1;
	}
	return 0;
}

string ask_me()
{
	object ob,me;

	if (this_player()->query_skill("cookery",1)<60)
                return "�A���i�����N�|�����ԡA�U�^�A�ӧa�C";
	if (query("book_count") < 1)
		return "�A�ӱߤF�A�u�i���J���v���b���B�C";
	add("book_count", -1);
	ob = new("/clone/book/cookery_book.c");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"����i���J���աC\n");
	return "�n�a�A�o���u�i���J���v�A���^�h�n�n�p��C";
}