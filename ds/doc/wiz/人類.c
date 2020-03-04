// �� �@��H��NPC 

#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ȫ�", ({ "passenger","�ȫ�","passenger",}));
        set("long", "�@�Ӻ��y��ת��ȫȡM���b�Q�w��ĵ�ýL�ݵۡC\n"
        );
        set("level",20);
        set("title","[1;33m�~�a�H[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",31);			//�]�w�ݩ�(�i�K)
        set("dex",21);			//�]�i�H�u�]�w level
        set("con",33);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",18);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",20);			//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================�A�����O=================================
//   set("attitude", "friendly");   //�͵��� NPC�C
   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C


//=============================�۰ʰʧ@=================================
  set("chat_chance", 0 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�ȫȥΤO����F����@�}!! ���G�D�`�ͮ�..\n",
(:command("say �z�a!! �o�O����A�ȺA�׹�!!!"):),
(:command("say �쩳�n�ڻ��X����~~ �o��}�s�M�O�ڭ��ߨ쪺.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m�ڥs�����L...�A�ݳo�ӷF����?? �L��!![m
LONG );

//set("talk_reply","�A�ֺ޶���....");
//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�ȫȯ}�f�j�| : �u�i�c���å��T�ڥ����A�T�v\n"NOR,
     }) );

        setup();

//==========================�˳ƹD��=============================
      add_money("coin", 200);		//�a����
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m�w��ĵ�ð��W���X�ӹ�$N[1;37m��: �Ф��n�ʤ�, �浹�ڭ̳B�z�N�n�F�C[m\n",this_player());
 return 1;
 }
return 0;
}

//======================�ʧ@����======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M�����!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M��������!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say �u���@�I!!�O�Ч�!!");
                break;
        }
}

//======================��������======================================
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

        return 1; //��retrun 1 �~�|���U�F��.
}

void reset()
{
        // delete("memory");
}

// ���� ���S��NPC(1) �ޯড�S��
// �������� ¾�~�u�|�ɮv
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�y�L��" , ({ "invisible liu","liu" }) );
        create_family( HIC "�i���Z�Уi" NOR ,2,"�ХD");
        set("level",50);
        set("race","�H��");
        set("age",65);
         set("adv_class",1);
         set("class1","���Z��");
        set("gender","�k��");
        set("int",100);
        // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
        // �ӥB�|�����`�M�n��n���� 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "sword" : ({160,2,60}),
               "godsword" : ({140,2,70}),
               "meditate" : ({160,2,20}),
               "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-fire" : ({170,2,60}),
                "god-benison" : ({170,2,50}),
        ]) );
        set_spell("god-fire",80);
        set_spell("god-benison",70);
        set_skill("force", 100);
        set_skill("mirage-steps",100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set("long",@long
�L�O�i���Z�Уi���ХD�A���Ѱ򥻪��ޥ��V�m�C�A�i�H
�ϥ�list�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i
�H��advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ�
level ���O�Ӭd�\�һݭn���g��ȡC
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
                  (:command("cast god-benison"):),
        }) );
        setup();
             carry_object("/open/world1/acme/area/npc/wp/godsword.c")->wield();
}

int accept_object(object who,object ob)
{
        object plate;
        object me;
      me = this_player();

        if(ob->name()!="���Z�O�P")
                return 0;
        else {
                command("say �x�I�I�o���O�v�����O�P�ܡI�I");
                command("say ��Ӯv���w�n�A�ݨӧڬO�h��ߤF�C");
                command("smile");
                command("say �o��" +  RANK_D->query_respect(ob) + "�h�������C\n");
if(me->query("class1")  ) 
{
  notify_fail("�A�w�O"+me->query("class1")+"���̤l�F�A�ѤҴN���¹L�F�C\n");
}
else {
            command("say �A�Y��ߤW�i�A�ѤҴN���A���{�a�I\n");
            command("say �J�ڱз��L�M�q�A���j�ٮz�I\n");
            who->set("adv_class",1);
            who->set("class1","���Z��");
            who->create_family("���Z��",3,"�Ю{");
           who->set("guild_rank",HIC"���Z�С�"HIG"�}�s���v"NOR);
return 1;
}
       }
  return 1;     
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_force","force");
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //�Ȯ�
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="���Z��") return notify_fail("�A�w�O���Z�Ч̤l�F�C\n");
         if(arg!="���Z��") return notify_fail("�A�n���J���@�Ӫ���?\n");
     say("�y�L�Υ��۵o�T�A�èS���o�{�A�n�[�J�C\n");
     say("�y�L�γ��ۻy���D�G�v���L�ѤH�a�����w�n�A�w�Q�~�K�����q�����C\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="���Z��") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O���Z�Ю{�C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�H��> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}

// ������ ���S��NPC(2) �S���O��

#include <ansi.h>
inherit NPC;
void make_mark();

void create()
{
	set_name("���G",({"yin-bian","bian"}) );
	set("long","�L�O���Z�}���̦��W���צ�̡Ať���L�֦��W��O�C\n");
	set("age",30);
	set("level",40);
	set("race","�H��");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say �o�O�y���R�������A�Ф��n���X�H�k���Ʊ���I"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڨ������x�A�@�w�n�N�@�ê̴N�a���k�I�I"):),
		(: make_mark :),
//		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
//	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();

	add_money("dollar",200);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say �A�o�ӧ@�ê̡A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}


void make_mark()
{
	object *enemy, ob;
	command("think");
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say ��!�L�k�L�Ѫ�"+ob->query("name")+", �ڵo�}�n�N�A�v�X���Z�}���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

int special_attack(object me,object victim,int hitrole)
{
	int damage,c;

	if(!victim) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",20);
	command("say "+victim->query("name")+"�A���A�ݬݧڶW��O���Q�`�C");


	tell_room(environment(me),"\n"+me->query("name")+"��M���l����h�F�@�B\n");
	tell_room(environment(me),"\n�A�ݨ�L������۵M�����U�A�����ܱo���`�������C\n");

	if( victim->query_int() < random(150) )
	{
	    victim->add_busy(2);
	    message_vision(HIR"\n$N��M��P�D�����ҥR���ۮ��ߡA$N����ʦn���Q�����F�C\n",victim);
	    damage = random(300)+query_int()*5;
	    damage = damage/2+random(damage/2);
	    c=victim->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,victim,damage,"sou");
	    victim->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n$N��M�Q���W���O�q�ҥ����A�f�R�A��A��ӤH�Q���b����W�ʼu���o�C\n"NOR,victim);
	    else
		message_vision(HIW"\n�ѩ�$N���F�O�ӹL "+me->query("name")+" �@�w�A���ͥͦa���U�F�o�Ѳ��W���O�C\n"NOR,victim);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
	        tell_object(victim,HIR"("+damage+")"NOR+" ("+victim->query("hp")+"/"+victim->query("max_hp")+")");
	    message_vision("\n",victim);
	    if(wizardp(victim) && victim->query("env/debug"))
	        tell_object(victim,"  �y��"+damage+"�I�ˮ`!!\n"); 
	    COMBAT_D->report_status(victim);	

	}
	else message_vision("\n���W���O������V$N�A���G�Q$N���F���ƸѤF�C\n",victim);

 	me->start_busy(1);

}


// �������� �����ʧ@��NPC




// ���������� ���[�\�धNPC (�ðѨ���L�d��)

#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���|�Ϫ�", ({ "club messager","messager"}));
        set("long", "�@�Ӷ¦�H�C\n�A�p�G�򥢤F���|�H��, �i�H��(checkclub)�V�L�ӽФ@�ӷs���H���C\n"
        );
        set("level",1);
        set("title","[1;33m�q�u[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 1);
        set("exp",10);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",1);			//�]�w�ݩ�(�i�K)
        set("dex",1);			//�]�i�H�u�]�w level
        set("con",1);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",1);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",1);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",-20);			//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================�A�����O=================================
//   set("attitude", "friendly");   //�͵��� NPC�C
   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C


//=============================�۰ʰʧ@=================================
  set("chat_chance", 0 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
�A�ݳo�ӷF����?? �L��!!
LONG );


//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�ȫȯ}�f�j�| : �u�i�c���å��T�ڥ����A�T�v\n"NOR,
     }) );

        setup();

//==========================�˳ƹD��=============================
//      add_money("coin", 200);		//�a����
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("say �A�p�G���F���|�H���N�ӧ�ڥӽ�(checkclub)�a!");
 return 1;
}

void init()
{
	::init();
add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,ob,mark;
	string clubname;
	me=this_player();
	if(mark=present("club_mark",me)) return notify_fail("�A�w�g�����|�H���F�C\n");
	
	if(!clubname=me->query("club/name")) return notify_fail("�A�èS���ѥ[���|�������C\n");
	switch(clubname)
	{
		case "�g�s��":
				ob=new(DRAGON_M);
				ob->move(me);
				message_vision("$N���F�@"+ob->query("unit")+ob->name()+"��$n�C\n",this_object(),me);
				me->save();
				return 1;
		default:
			return notify_fail("�Ϫ��٨S������o�������H���C\n");
	}

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�L���Q���A���F��C\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "�Ϫ̻��D�R�h�³o��" + RANK_D->query_respect(who)
                + "�M�����@�w�|�O���A���C\n");

        return 1;
}
