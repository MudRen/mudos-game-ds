#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIW"�L�W�^���^�F"NOR,({"none hero","hero"}));
        set("long",@LONG
͢���g�DŢ�n�ۤ@�h�ե��A���A�X�G���������A�ӥB�]�ᬰ�ɪA��͢
�Ҵ��o�X�Ӫ���աC�L�W�^���O��~�L�W�ꤤ���^�����@�C�b�L����
���M���a�������ѡA�ҥH����N���׻E�A�Ʊ�����~�ӤH�A�~��
�O�a�ð�C
LONG
	);

        set("level",43);
	set("no_fight",1);
        set("age",200+random(50));
        set("combat_exp", 200000);
	set("gender","�k��");

	set_skill("fork",100);
	set_skill("block",50);
        set_skill("parry", 85);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        
        set_skill("combatwolf-fork",100);
	map_skill("fork","combatwolf-fork");

	set_temp("apply/armor",40);

	setup();

	set("talk_reply",HIW"�A�n�����սm�ܡH\n"NOR);
        set("chat_chance", 10);
        set("chat_msg", ({
	HIW"�L�W�^�����D�G�����D��@���S���H����O�~�ӧڪ���ӡH\n"NOR,
	(: command("think") :),
	(: command("sigh") :),
	}));
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
	(:command,"exert combatwolf-fork skywolf":),
	(:command,"exert combatwolf-fork icewolf":),
	(:command,"wield pike":),
	}));
        carry_object(__DIR__"wp/hero_pike.c")->wield();
        carry_object(__DIR__"eq/hero_armor.c")->wear();
	carry_object(__DIR__"eq/hero_shield.c")->wear();
	carry_object(__DIR__"eq/hero_leggings.c")->wear();
}

void init()
{
	add_action("reply_say","say");
}

int reply_say(string str)
{

	if(this_object()->query_temp("fight") != 0) return 0;

	if (str=="��" || str=="�n")
	{   
	object me;
	me=this_player();

	message_vision(
	HIW"\n�^�F���$N�L���D�G�n�I�n�I���x�Ѫ��H�I\n"
	HIW"�^�F�j�ܤ@�n�G�d���ӡI\n\n",me);

	this_object()->kill_ob(this_player());
	delete("no_fight");
	set_temp("fight",1);
	return 1;
	}
}    

void die()
{
        object ob,me,obj;
	me=this_player();
	obj=load_object(SDO_PAST+"nonhero/obj/coffin");
	obj->delete("temp/opened");

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", 
	HIC"\n\n    �L�W�^���^�F��"+ob->name(1)+"���D�G\n\n"NOR
	HIC"            �y�Ӧn�F�I�Ӧn�F�I�ګ��~���H�F�I�z\n\n"NOR, 
	users());

	message_vision(
	HIW"\n�A�ݨ�@�D�ե��^��ä줧���C\n"NOR,me);

        ob->add("popularity", 3); //�n��
	tell_object(ob,HIC"[�]���A���V�O�A�A�o��F 3 �I�n��!!]\n"NOR);
        ::die();
        return;
}