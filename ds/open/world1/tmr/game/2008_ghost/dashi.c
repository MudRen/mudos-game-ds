#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name(HIY"�j�h��"NOR,({"dashi buddha", "dashi", "buddha"}) );
	set("long",@LONG
���U�j�h�O�[���j�h���ƨ��A�]�s���U�����B�J���j�h�B�K�f�����A
�U�٤j�h�ݡB�j�h���A�b�D�ФS�L�٬��u���礽�v�C���֦a�褤���`
�����`�F���e�A�|�������u�j�h�ݡv�A�H���{���A�¾�C��A�Ҧ��b
���@���`�F�A���k�u�j�h�ݡv�޲z�C
LONG
);
	set("age",5000);
	set("race","celestial");
	set("level", 1);
    set("attitude", "peaceful");
    set("title","����t����D");
    set("gender", "�k��" );
    set("no_kill",1);
	setup();
	set("sell_list", ([     
             "/open/world1/tmr/game/2008_ghost/boat"    : 1, 
         ]) );

}


void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

// ��o���y
void bouns(object me, string type, int amount)
{
	int points = 0;
	string ctype;
	if(type=="art") {
		points = amount/50;
		ctype = "�԰����N";
	}
	if(type=="pop") {
		points = amount/5;
		ctype = "�n��";
	}
	if(type=="exp") {
		points = amount*100;
		ctype = "�g���";
	}
	if(type=="money") {
		points = amount*10;
		ctype = "�ɪO";
	}
	if(points<1) {
		type = "money";
		points = amount*10;
		ctype = "�ɪO";
	}

	tell_object(me, sprintf("�A��o %4d %s�C\n", points, ctype ) );
	if(type=="art")
		me->add("war_art", points);
	else if(type=="pop")
		me->add("popularity", points);
	else if(type=="exp")
		me->add("exp", points);
	else if(type=="money")
		me->add("bank/past", points);
}

int accept_object(object who,object ob)
{
	if(!ob->id("_DEAD_PAPER_"))
		return 0;
    message_vision("$N���F�j�h�ݤ@�i$n�C\n",who,ob);
	command("say �n�n�n�I�p�l�z��o���D�A������ְڡC");
	bouns(who, ob->query("type"), ob->query("amount") );
	destruct(ob);
	return 1;
}
