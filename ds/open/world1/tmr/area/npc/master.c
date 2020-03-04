/* �K���� ��Ův��
 *
 * -By Tmr 
 * -Update 2002/02/22
 *
 */
inherit NPC;
inherit SSERVER;

#include <ansi.h>

void create()
{
    set_name("���Ѥ�", ({ "lee shu wen master", "master", "lee" }) );
    set("nickname", "���j��");
    set("gender", "�k��");
    set("class","fighter");
    set("age", 60);
    set("adv_class",1);
    set("class1","�K����");
    set("guild_gifts",({10,7,0,3}));
    set("long",
"���Ѥ�ݨӵu�p�A�o���H�۷�뮫���Pı�A�@�y�¿p�A�O�H�椧�ͬȡC\n"
"�L��O�{���u�K�����v���Ĥ��N�x���A���Ⱥ�q�K�����A��j�j�Z��O�w�F\n"
"�n�p�y�����ҬɡA�b����W�O�췥���W���@�N�v�v�C\n"
    );
    set("attitude", "peaceful");
    set("level",40);
    set("guild_skills",([
        "bagi_fist":({150,3,60}),
        "horse-steps":({130,4,100}),
        "dodge" : ({120,2,60}),
        "parry" : ({120,3,70}),
        "unarmed":({110,3,80}),
        "fork":({120,3,70}),
        "da-fork":({150,3,60}),
    ])  );
    set_skill("unarmed", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("fork",100);
    set_skill("bagi_fist",100);
    set_skill("da-fork",100);
    set_skill("horse-steps",100);
    set_skill("six_open",100);
        map_skill("unarmed", "bagi_fist");
        map_skill("fork", "da-fork");

        set("no_check_class",1);
        set("chat_chance",20);
        /*
        set("chat_msg",({
            "���Ѥ�f�����ۡu�E�����y�v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ�f�����ۡu�ꥴ���y�v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ�f�����ۡu���L�v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ�f�����ۡu�涧���v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ�f�����ۡu�㥴�v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ�f�����ۡu½���p��v���q�Z�A�@���t�m�_�ӡC\n",
            "���Ѥ家�İ_�믫�A�~��m�ߡu���j�}�v�����Ӱ򥻩ۦ��C\n",
            }) );
*/


        set("chat_msg",({
          "���Ѥ廴�����D�G�u�@�P�ڦӬ۹H�A�_�r�����j�D�H�v\n" ,
          "���Ѥ廴�����D�G�u�@�P�ڦӬ۹H�A�_�r�����j�D�H�v\n" ,
          "���Ѥ廴�����D�G�u���˱������ܡA�ֵ^�ѥH���~�C�v\n" ,
          "���Ѥ廴�����D�G�u�w�o�G.......�v\n" ,
        (:command("exert horse-steps twine-power"):),
          "���Ѥ廴�����D�G�u�J�Φt���_�X�ɡA�T���e�ߥ��h�d�A�J���N�N���󤧡H�v\n" ,
          "���Ѥ廴�����D�G�u�h�}���H�t���A�δӧ��ӯ��T�A�v\n" ,
          (:command("think"):),
          "���Ѥ廴�����D�G�u�n�F�o�H�μS�A�{�M�y�ӽ�֡C�v\n" ,
          "���Ѥ廴�����D�G�u�᭼�ƥH�k�ɡA�֤ҤѩR�_�O�áC�v\n" ,
        (:command("sigh"):),
         }) );

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
            (:command("exert bagi_fist"):), // �K���� �S��
            (:command("exert bagi_fist"):), // �K���� �S��
            (:command("exert six_open"):),  //  ���j�} �S��
            (:command("exert da-fork"):),   // �j�j�Z �S�� 
         }) );
    
    create_family("�K����", 6, "�x���H");
    set_temp("apply/armor", 100);
    set_temp("apply/damage", 150);

    setup();
    carry_object(__DIR__"eq/cloth")->wear();
      carry_object(__DIR__"eq/heave-boots")->wear();
        carry_object(__DIR__"eq/black-leggings")->wear();
    carry_object(__DIR__"wp/masterfork")->wield();
}


void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_speak","speak");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();
      if( me->id("ghost") ) return 0;
	message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me);	
	if(arg != "�K����") return notify_fail("���Ѥ�ôb���ݵۧA�C\n");
	if(me->query("adv_class")) return notify_fail("�A�w�[�J�����F�C\n");
	if(me->query_temp("can_join_bagi"))
	{
		i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
		switch(i)
		{
		case 1:
			me->set("adv_class",1);
			me->set("class1","�K����");
 			me->create_family("�K����",7,"�L��");
 			message_vision("$N�[�J�F�K�����C\n",me);
 			me->delete_temp("can_join_bagi");
			return 1;
		case -1: return notify_fail("�A�w�������F�C\n");
		case -2: return notify_fail("�A�w�������F�C\n");
		case -8: return notify_fail("�S���o�ت����C\n");
		}
		return 0;
	}
	if(me->query_temp("eight_speak") )
		command("say �o��"+ RANK_D->query_respect(me) +"�p�������y�ܡA�N�O�b�����F�T�ѤT�]�A�ڤ]�O���|�����C\n");
	else	
	{
		command("say ������A�p�A�໡�X(speak)�����Q����Ҳ��Ǫ��@�y�ܡA�ڴN���F�A�a");
		me->set_temp("eight_speak",1);			
	}

	return 1;
}

int do_speak(string arg)
{
	object me;
	me=this_player();

	if(!me->query_temp("eight_speak") )return 0;

	if(arg != "�A���ѤK���A�^���۲���")
	{
		message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
		command("shake");
		command("say ���O���O�A�A�Q�Q�a�C");
	}
	else
	{
		message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
		command("say �n�A�N�O�o�y�ܡA�A�i�H�[�J�u�K�����v�F�I(join �K����)�C");
		me->set_temp("can_join_bagi",1);
 		me->delete_temp("eight_speak");
	}	
	return 1;

}

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
            if(me->query("level") > 24 && me->query("class2")=="�K����" )
          return notify_fail("�A���O���Ѥ媺�̤l�C\n");
	if(me->query("class1")=="�K����" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O�K�������̤l�C\n");
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	message("world:world1:vision",
  HIG"\n�i�Z�L�����j" +HIW"�@�N�v�v�u���j�v���Ѥ妺�b"+ob->name(1)+"���⤤�F�C\n\n"+NOR
	,users());
	ob->add("popularity",1); //�n��
	::die();
	//destruct(this_object());
	return;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // �N rank �������Ӽh��

        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�K��������X�TĪ"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�K�����������p�W"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�K�������M�q����"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�K�������L�𻷼�"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�K���������W�ѤU"; break;
                                // LV 50
                        default: rank = HIC "�K�������@�N�v�v" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�K��������X�|��"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�K�����������^�W"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�K�������M�q�|��"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�K�������^�𻷼�"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�K���������W�ѤU"; break;
                                // LV 50
                        default: rank = HIC "�K�������@�N�k��" NOR;
                }

        }
        return rank;
}

