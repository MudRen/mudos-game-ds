//�ⶳ�x �i�� Master -By Tmr 2002/1/24-

#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name("����",({"miao-jian bonze","bonze","master","miao-jian"}));
        set("gender", "�k��");
        set("long",@LONG
�����������ⶳ�x�e������A�����p���D�A�z�ڲ`�p�A���~�ɴ��]�t�ڷ|
�߱o������Ĥ@���ޡu�p�ӤE���v�A�ۦ���B�Z�G�D���������A�׬��X�H�F
��u�i�ơv���ҬɡC
LONG
        );
        set("level",60);
        set("age",80);
        set("adv_class",2);
        set("class1","�ⶳ�x");
        set("class2","�ⶳ�x");
        set("title","�ⶳ�x����");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
		set_skill("buddha-skill",100);
		set_skill("wuchen-staff",100);
		set_skill("jingang-finger",100);
		set_skill("staff",100);
        map_skill("staff","wuchen-staff");
        map_skill("unarmed","jingang-finger");

        set("inquiry", ([
			"�p�ӤE��" : "�۶Ǧ򯪬����粳�͡B�ѧT���M�A�d�ǥ@�H���@�M�m�@���ǡI",
			"�}�k" : "�I�D�O�n�߰ݦѯǦ���"+HIY"�u����ù�~�}�v"+NOR CYN "���Ʊ��ܡH",
			"����ù�~�}" : "��....���D��������T�j�}�k���@�A������i�g�Ѥ@��"+HIY"���"+NOR CYN"�i�ǲߨ�C",
			"���" : "�������"+HIY"�|����"+NOR CYN"�u�@�b"HIY"�ⶳ�p��" 
					   +NOR CYN"�W�A�I�D�p��t�`�p�A���ϥi�h"+HIY "����"+NOR CYN"�C",
			"�|����":"���|����Y���p�Ӧ򯪨��骺�|�j�@�k�Ϫ̡A�U�㦳���q�O�A��ݦl�����]�O���d�������C",
			"�ⶳ�p��":"�ⶳ�p���s���I�m�A�D���\\���W�̡A���H�n�W�s���C",
			"����":"�p�Ӧ򯪩ҳ]�U���շҡA�ߦa���}�B��k�`�p�̡A�i�q�L�|���誺����A���o���}�k������C"
			]) );

        set("chat_chance", 10);
        set("chat_msg",({
			(:command("say �����������"):),
			(:command("say �p�Ӧ���̥@�����]���h�A�S�d�U�@�աu�}�k�v�y�֥@�H�ڡC"):),
			(:command("say �ڬ�����l�A�������O���C"):),
		}) );
	
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_heal:), 
					(:do_heal:), 
		}) );        
        
		set("guild_skills",([           // ����, ����1�i��, �W��
                "buddha-skill":({200,4,100}),
        ]) );

        set("guild_gifts",({4,5,6,5}));

        set_temp("apply/armor",100);
        set_temp("apply/damage",50);


		setup();
		carry_object(__DIR__"wp/hit-daemon")->wield();
		carry_object(__DIR__"obj/shelizi");
}

void init()
{
        add_action("do_say","say");
		add_action("do_skill_list","list");
		add_action("do_skill_train","train");
		add_action("do_guild_join","join");
        add_action("do_advance","advance");
}

int do_say(string arg)
{
	object me=this_player();
	object book;
	if(arg!="�n�D����" || this_object()->is_fighting() 	||me->is_fighting() )
		return 0;
	message_vision("$N���D�G�u�n�D�����C�v\n",me);
	// ���Ť���
            if(!userp(me) || me->query("level") < 30)
	{
		message_vision("$N���D�G�u�ڷQ�o��I�D���\\���٥�����������{�קa�C�v\n",this_object());
		return 1;
	}
	// �w�g���ѤF
	if( objectp( book=present("_BUDDHA_WAR_BOOK_",me)	)
		) 
	{
		message_vision("$N���G���Q�z�|$n�C\n",this_object(),me);
		return 1;
	}
	book=new(__DIR__"obj/bore-book");
	message_vision("$N�I�F�I�Y�A�q�h�̮��F���ѡA�b�W���g�F�X�Ӧr�A�M��浹�F$n\n",this_object(),me);
	book->set_warname(me->query("id"));
	//command("give " + me->query("id"));	
	book->move(me); 
	return 1;
}

// �԰�������
void do_heal()
{
	object me=this_object();
	if(me->query("hp") < me->query("max_hp")/2)
	{
		message_vision(HIG "$N�ϥX������]�������u�B�ѰҪ�ù�ءv�A����p�����t�I��F���W���U�Ӥ�媺�޹D�C\n" NOR,me);
		me->heal("hp",100);
		me->add_busy(1);
	} else {
		if(me->is_busy() ) return;
		if(me->query_temp("do_attack") ) return;
		message_vision(HIR "$N�⤤���F�ӡu��N����v��L�A�n�ɧ�ռ@�W�I�I\n" NOR,me);
		me->set_temp("do_attack",1);	// mark �קK�h������
		me->add_temp("apply/damage",50);
		me->add_temp("apply/hit",300);
			me->attack();
			me->attack();
		me->add_temp("apply/hit",-300);
		me->add_temp("apply/damage",-50);
		me->set_temp("do_attack",0);
	}

}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

		if(random(100)<30)
		{
			damage/=2;
			message_vision(HIY "$N���p��ꪺ�@������ƸѤF�j�b�ˮ`�C\n" NOR,this_object());

		}

		if(objectp(who) )
			::receive_damage(type,damage,who);
		else
			::receive_damage(type,damage,who);
		return damage;
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
        int j,lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(this_player()->query("class2") != "�ⶳ�x")
               return notify_fail("�A�ä��O�ⶳ�x���M�|�C\n");
        if(arg=="buddha-skill")
                lv=me->query_skill("buddha-skill");

        if(arg=="buddha-skill")
        {
	        cost=me->query_skill(arg,1);
		    if( cost<30 )   cost=1;
			else    if(cost<60) cost=2;
			else    if(cost<90) cost=3;
			else    cost=4;
	        if(lv==100)
		            return notify_fail("�A�w�g��F�n�p�y�����ҬɤF�C\n");
			if( j < cost)
				    return notify_fail("�ݨӧ����ä��Q���ɧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");
			if( me->query("evil") > - 400)	 //�@�������}
				    return notify_fail("�ѩ�A���ʤ����A�����ä��Q���ɧA��`�@�h�C\n");
        }
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        if(!arg) return 0;
		message_vision("$N�Q�[�J"+arg	+"�C\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("�A�w�O��L�������{�̤F�C\n");break;
               case -2: notify_fail("�A�w�O��L�������{�̤F�C\n");break;
               case -8: notify_fail("���ɦ��ɨèS���o�Ӫ����C\n");break;
	    }
        if(arg!="�ⶳ�x" )
				notify_fail("���ɦ��ɨèS���o�Ӫ����C\n");
        if(me->query("class2")=="�ⶳ�x")
                return notify_fail("�A�w�O�ⶳ�x���M�|�F�C\n");
        if( me->query("class1")=="�ⶳ�x" 
			&& me->query("level")==25 
			&& me->query("adv_class")==1 )
             {
                command("say �A�׬��`�p�A�ѯǴN���ɧA��`����ǧa�C\n");
				ob->command("pat "+me->query("id") );
				message("world:world1:vision",
				HIY "\n\t�i���D�����j�G�@�N�����u�����v���F"+me->name(1)+HIY
				"���ⶳ�x�ĥ|�N�̤l�C\n"NOR
				,users() );
		        me->command("kneel bonze");
				me->set("class2","�ⶳ�x");
				me->create_family("�ⶳ�x",4,"�̤l");
				me->set("adv_class",2);
        		return 1;
		}
        else return notify_fail("�ݰ_�ӧ��������ä��Q���A���{�C\n");

        return 1;
}


int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(j < 3 ) 
			return notify_fail("�A���n�椣���C\n");
        if(me->query("class2") != "�ⶳ�x") 
                return notify_fail("�A�ä��O�ⶳ�x���M�|�C�C\n");
        //�s�ץ��Aadv level ���n�� (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");
        else return GUILDMASTER->do_advance(ob,me,arg);
}

string guild_rank(object me)
{
        string rank;
        int lv;

        
		return "�ⶳ�x�ĥ|�N�̤l";

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

		tell_room( environment(),
			 HIG "\n���������y�S�L���A�o�w�A�S�����R�C\n"
			+HIY "\t�u�����������C�պ��C��i���I�I\n"
			+HIC "\t���ɧT���o�D�A����������I�i�ơA���ߤۤƭi������....\n"
			+HIM "\t�ڭ��|���A�������x�L���a����n�W��ѷ���. \n\n" NOR		);

		message("world:world1:vision",
HIG"\t�Z�L�ֳ��G"HIW"��������u�����v���b"+ob->name(1)+"���⤤�F�I�I�I\n"+NOR
        ,users());

        ob->add("popularity",5);
        ::die();

        return;
}
