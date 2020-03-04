// wuxiuwen.c

#include <ansi.h>

inherit NPC;
string ask_me_1(string name);
string ask_me_2(string name);
void create()
{
	set_name("�Z�פ�", ({"wu xiuwen", "wu", "xiuwen"}));
	set("title", HIY"���t�G�̤l"NOR);
	set("gender", "�k��");
	set("age", 21);
	set("long", "�L�O���t���G�̤l�A����j�F�A�M���t�d��ԡC\n");
 	set("attitude", "peaceful");
	
	set("per", 23);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"���T" : "���O�ڮv���C\n",
		"���t" : "���O�ڮv���C\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);

	set("huju_count", 20);
	set("beixin_count", 2);
	 
/*
    set_skill("force", 50);         // �򥻤��\
    set_skill("huntian-qigong", 50);    // �V�Ѯ�\
    set_skill("unarmed", 50);       // �򥻮��}
    set_skill("xianglong-zhang", 50);   // ���s�Q�K�x
    set_skill("dodge", 50);         // �򥻸��{
    set_skill("xiaoyaoyou", 50);        // �p���C
    set_skill("parry", 50);         // �򥻩۬[
*/
        set("inquiry", ([
		"�K�@��" : (: ask_me_1, "huwan" :),
		"�K�@�y" : (: ask_me_1, "huyao" :),
		"�֤�M" : (: ask_me_1, "shoutao" :),
		"�ֳ��" : (: ask_me_1, "weibo" :),
		"�K���M" : (: ask_me_1, "zhitao" :),
                "�K�I��" : (: ask_me_2, "beixin" :)
        ]));
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
}
string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"�A�{�b���W���O���o�˨���ܡA���S�ӭn�F�H �u�O�g�o�L��I";

	if (query("huju_count") < 1)
		return "��p�A�A�ӱo���O�ɭԡA����w�g�o���F�C";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("�Z�פ嵹$N�@��" + ob->query("name") + "�C\n", this_player());

	return "���h�a�C���L�n�O��A����u�i�����m�Z�A���i�̦����`�L�H�C";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (query("beixin_count") < 1)
		return "��p�A�A�ӱo���O�ɭԡA�Z���w�g�o���F�C";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("�Z�פ嵹$N�@��" + ob->query("name") + "�C\n", this_player());

	return "���h�a�C���L�n�O��A�K�I�ߤD�O�����_���A���i�̦����`�L�H�C";
}
