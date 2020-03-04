//�K���� �i�� Master -By Tmr-
// last update 2006/11/09

#include <ansi.h>
inherit NPC;
inherit SSERVER;

void do_heal();
void do_combat();
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name("�d��",({"wu chung master","master","wu","chung","_BAGI_MASTER_WU_"}));

        set("gender", "�k��");
        set("long",@LONG
�d�����K�������N���l���A�~�֮ɫi��X���A�W�ޥX�s�A��Z���Ѥ@
�W�u���v���D�h�ҶǱ¡A��j�j�Z�q�����{�̡��}�A�Ҳ߱o�A�ܦ�������
�]�A�ײߪZ���A�󤭤Q���ɤj���A���~�ФK�����A�C�Q���j���j���A�h�~
�s�L�A�y�C�۱o�C
LONG
        );
        set("level",60);
	set("race","ogre");
        set("age",80);
        set("adv_class",2);
        set("class1","�K����");
        set("class2","�K����");
        set("title","�K�����}�s���v");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("fork",100);
        set_skill("six_open",100);

        set_skill("da-fork",100);
        set_skill("bagi_fist",100);
        set_skill("horse-steps",100);
        set_skill("perception",100);
        map_skill("unarmed","bagi_fist");
        map_skill("fork","da-fork");
          set_skill("constant-virtue", 50);

        //set("combat_exp",1000000);

        set("chat_chance", 50);
        set("chat_msg",({
        	(: do_heal() :),
        }) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        	(: do_combat :),
        }) );
        
        set("guild_skills",([           // ����, ����1�i��, �W��
                "force":({150,3,100}),
                "bagi_force":({200,3,100}),
                  "six_open":({200,3, 60}),

        ]) );

        set("guild_gifts",({10,7,0,3}));
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 150);
        setup();
        carry_object("/open/world1/tmr/area/npc/eq/black-leggings")->wear();
        carry_object(__DIR__"eq/cold-moon-belt")->wear();
        carry_object(__DIR__"eq/wu_pants")->wear();
        carry_object(__DIR__"eq/wu_ring")->wear();
        carry_object(__DIR__"wp/six-sun-fist")->wield();
        carry_object(__DIR__"eq/wu_gloves")->wear();
        carry_object(__DIR__"obj/liver");
        carry_object(__DIR__"obj/liver");
        carry_object(__DIR__"obj/doll-head");
}

int accept_object(object who,object ob)
{
        if(!ob->id("quest-bagi-book") ) return 0;

        message_vision("$N���F�d���@���U�l�C\n",who,ob);
        destruct(ob);
        if(who->query("adv_class")==2 
        && who->query("class2")=="�K����" 
        && !who->query_skill("bagi_force") )
        {
                command("say �@�A�]�O�������H�A���p�ڶǧA�����ߪk�a�C");
                message_vision("�d���J�Ӧa�ФF$N�K���ߪk���f�Z�C\n",who);
                who->set_skill("bagi_force",5);
        }
        else 
                command("smile "+who->query("id") );
        return 1;
}

void do_heal() {
	if( !query_temp("weapon") ) command("wield fist");
	if( query("hp") < query("max_hp") ) {
		message_vision( HBK "$N���W�_�X�}�}���¦��A�Ҩ����˶դ@�I�I�a�n��_�ӡC\n" NOR, this_object());
		receive_heal("hp", 1200);
	} else {
		switch( random(5) ) {
			case 0:
				command("say �e��Ӥ�l��B�򴲨B�A�Q���즳�t�ݨ�y�P�B�A�o�{�䤤�����ܦh�����i�H�ĩ�Z�ǡC");
			break;
			case 1:
				command("smile");
			break;
		}
	}
}

void do_combat() 
{
	object target = offensive_target(this_object());
    /* �Z���Q�����A�h�˦^�h */
	if( !query_temp("weapon") ) command("wield fist");
	if(!target) return;

	if( !target->is_busy() ) {
		command("exert six_open");
	} else {
		command("exert bagi_fist");
	}
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_guild_join","join");
        add_action("do_advance","advance");
        add_action("do_say","say");
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "�K����")
               return notify_fail("�A�ä��O�K�����̤l�C\n");

        lv = me->query_skill(arg,1);
        if(lv<5)
                return notify_fail("�ݨӧd���٤��Q���ɧA�o�ӧޯ�C\n");
        if(lv==100)
                return notify_fail("�A�w�g��F�n�p�y�����ҬɤF�C\n");
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("�ݨӧd���ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

// if(me->query("race") != "human" ) return 0; �رڭ������..by whoami
        message_vision("$N�Q�[�J"+arg+"�C\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -2: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -8: notify_fail("�S���o�Ӫ����a");break;

        }
        if(me->query("class2")=="�K����")
         if( !userp(me) ) return notify_fail("�D���a���⤣��[�J�����C\n");
        if(arg!="�K����" )
                return notify_fail("�o�̨S���o�Ӫ����C\n");
        if( me->query("class1")=="�K����" && me->query("level")==25 
        && me->query("adv_class")==1 && me->query_temp("adv-bagi-quest")==0 )
                {
                command("say �A�w�O���Ѥ媺�̤l�A��a�٨ӧ�ڳo�V���Y�H\n");
                me->set_temp("adv-bagi-quest",1);
                }
        else return notify_fail("�ݰ_�ӧd���ä��Q���A���{�C\n");

        return 1;
}


int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(j < 3 ) return notify_fail("�A���n�椣���C\n");
        if(me->query("class2") != "�K����") 
                return notify_fail("�A�ä��O�K�����̤l�C\n");
        //�s�ץ��Aadv level ���n�� (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");
        else return GUILDMASTER->do_advance(ob,me,arg);
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

int do_say(string arg)
{
        object me,ob;
        me = this_player();
        ob = this_object();

        if(me->query_temp("adv-bagi-quest") !=1 )                return 0;
        if(arg!="��")           return 0;

        message_vision("$N���D�G��\n",me);
        message_vision("$N���⤧����o�Q�������A�W�U�a����F�A�X���C\n", this_object() );
        message_vision("$N���D�G�u�A�N�J�ڪ��U�A���ڦn�n�Ǳ§A�Z���A���~�԰O�u�L�q�v�G�r�C�v\n", this_object() );
       	command("pat "+me->query("id") );
        message("world:world1:vision",
       	 	HIY "\n\t�Z�L�ֳ��G�@�N�v�v �d�����F"+me->name(1)+HIY "���K�����ĤG�N�̤l�C\n"NOR
        ,users() );

        me->command("kneel "+ob->query("id") );
        me->set("class2","�K����");
        me->create_family("�K����",2,"�L��");
        me->set("adv_class",2);
        me->delete_temp("adv-bagi-quest");
        return 1;
}

void die()
{
        object ob,scr,box;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        
        message("world:world1:vision",
			 HIW"\n\t�Z�L�ǥX�F�@�h��H������:"HIW"�K�����}�s���v�@�d�����b"+ob->name(1)+"�⤤�C\n\n"+NOR
        ,users());
         
         ob->add("popularity", 7);
           if( random(10) == 1 ) carry_object(__DIR__"wp/greatly-pike");
         tell_object(ob,HIG "(�A�o��C�I�n��F�C)\n" NOR );
         
         box = new(__DIR__"oldbox")->move(this_object());
          // �۵M�_�[�G�N��y�P�B
         "/open/world1/tmr/bagi/house.c"->open_star();

        if(ob->query_skill("six_open"))
        {
	        ::die(); return;
        }
        else{
        	if(ob->query("class2") == "�K����") {
	        	scr=new(__DIR__"bagi_scroll")->move(ob);
				tell_object(ob,"�A�X���q�d�����W���F�@�˪F��C\n");
			}
        }
        ::die();
        return;
}
// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{

		if( !this_object()->is_fighting() ) return 1;
		if( who == this_object() ) return 1;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if(this_object() == who ) {
                ::receive_damage(type,damage);
                return damage;
        }
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

		if(random(100)<40)
        {
			damage/=3;
			message_vision(HIY "\n$N��ܤ@�n�A��B���x�A�ϥX���ޡu�r��w���s�v�A�w�ͥͮ��ѤF��աI�I" NOR,this_object());
        }

    if( damage < 1) damage = 1;
        if(objectp(who) )
 			::receive_damage(type,damage,who);
        else
			::receive_damage(type,damage);
		return damage;
}
