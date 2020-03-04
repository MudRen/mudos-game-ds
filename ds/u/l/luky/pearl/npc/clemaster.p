// /daemon/class/hunter/clemaster.c	by Luky
#include <path.h>
#include <ansi.h>
inherit LUKY+"guildmaster";
void dispel();

void create()
{
	set_name("���Q",({"solid"}));
	set("gender", "�k��");
	set("long","�L�O�@��з|����¾�H��, �]�O���v���|����դH�C\n\n"
	+"  �p�G�n�[�J���|�Х� join <¾�~> \n"
	+"  �n�ݦ����|�ޯ�Х� list \n"
	+"  �n�ǲߤ��|�ޯ�Х� train <�ޯ�> \n\n"
	);
	set("title","�j���v");
	set("adv_class",2);
	set("class","caster");
	set("adv_class2","cleric");
	set("level",70);
	set("age",40);
	set("lck",140);
	set("evil",-300);
	set("jointerm","evil<20");
	set("jointerm_msg","���Q���q�F�A�@��, ��A��: ���c���H�ڭ̬O���w�諸.\n");
	set_skill("dispel",350);
	set_skill("multi_arrow",500);
	set_skill("arrow",2000);
	set_skill("bless",500);
	set_skill("dodge",310);
	set_skill("wand",210);
	set_skill("staff",210);
	set_skill("aid",320);
	set_skill("mostlight",410);
	set_skill("armor",1000);
	set("env/spellpower",5);
        set("guild_skills",([  // ����, ����1�i�Ǩ쪺�ޯ൥�ŤW��, �W��
		"dodge"		:({48,3,200}), // �򥻰{��
		"dispel"	:({38,6,420}), // �c�F�h��
		"bless"		:({30,5,350}), // ���ֳN
		"scanbody"	:({999,1,90}), // ���鱴��
		"armor"		:({20,9,600}), 
		"aid"		:({33,6,420}), 
		"mostlight"	:({33,6,420}), 
		"meditate"	:({48,2,140}), 
		"invoke"	:({50,2,140}), 
		"recharge"	:({50,2,140}), 
		"staff"		:({48,3,210}), 
		"wand"		:({48,3,210}), 
        ]) );
        set_temp("apply/armor",300);	//�beq�٨S�g�n�e�ȥ�
	set("accept",1);		//�s�W�i�H�����F��
        set("chat_chance", 10 );
	set("chat_msg", ({
	(:command("say �p�S�̮��I���a, �W�ҷ|���֧A��."):),
	(:command,"get all":),
	(:command,"drink potion":),
	(:command("smile"):),
	}) );

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
	(: command, "say ...���t���a����e�\\�A�b����v!!\n" :),
	(: cast_spell2, "multi_arrow":),
	(: cast_spell2, "mostlight":),
	(: cast_spell2, "aid":),
	(: command, "get all" :),
	(: command, "drink potion" :),
	(: cast_spell2, "armor":),
	(: dispel :),
	(: dispel :),
	(: dispel :),
	}) );
	set("msg_guildclass0",HIG"$n�������V���@�ɪ���¾�H���ŧG:"NOR"\n\n");
	set("msg_guildclass1",HIW"�i�q���Ѱ_, $N�̥S�����[�J�ڭ�$c���|���������l��.�j\n"NOR);
	set("msg_guildclass2",HIW"�i�Ʊ�j�a���᳣��ۤ��߫�, �N�ѥD���֭�������@�ɪ��C�Ө���!!�j\n\n"NOR);
   	setup();
	set("coin",2000);
	carry_object(__DIR__"eq/holyrobe")->wear();
	carry_object(__DIR__"wp/cross")->wield();
	//carry_object(__DIR__"hmclothes")->wear();
}
/*
void init()
{
 add_action("do_give","give");	
}
*/
void dispel()
{
	command("sigh");
	tell_room(environment(this_object()),"\n���Q��M���l����h�F�@�B\n");
	command("c dispel");
}

int accept_money(object me, int money_amount ,string money)
{
 string who;
 who = me->query("name");
 if(money_amount<1) return 0;
 if(this_object()->is_fighting()) return 0;
 if( money == "coin" )
 {
   if( this_player()->query("coin") < money_amount ) return notify_fail("�A�S������h��.\n");
   me->add("coin", - money_amount );
   this_object()->add("coin", money_amount/5);
   message_vision("$N���F�@�ǿ������Q.\n",this_player());
   message_vision(HIY"���Q�ܰ�������$N��: "HIG"���§A���^�m!! �ѥD�|�O���A��!!.\n"NOR,me);
   if(random(money_amount) > 8000 ) command("c armor "+me->query("id"));
   else if(random(money_amount) > 5000 ) command("c bless "+me->query("id"));
   if(me->query("evil") > -9999 && money_amount>999 ) me->add("evil",- random(money_amount/180));
   return 1;
 } else return 0;
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�L���Q���A���F��C\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "�ȫȻ��D�R�h�³o��" + RANK_D->query_respect(who)
                + "�M�����@�w�|�O���A���C\n");

        return 1;
}