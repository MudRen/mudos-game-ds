#include <ansi.h>
inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void special();
void create()
{
        set_name(HIW"�Ѥs��"NOR,({"master tain","tain","master"}));
        set("long" ,
"���������ĤG�N���D�A�䤧�_������[�����@�k]�w�A�Z�L���ƦW�e�Q�A���@\n"
"���鵹Ž�ܡA�����������ʭӡA�L�׬O�Z�\\�άO���z�A���w�F�ܤƹҡA�O�@\n"
"�W�`���i�����k�@��C\n");
        set("nickname", HIR"�������D"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","�k��");
        set("combat_exp", 100000);
        set("level", 50);
        set("title","�m�������n�ĤG�N���D" );
        set("max_ap",3000);
        set("MKS",150);
        set("class1","������");
        create_family("������",15,"�ĤG�N���D");
        set_temp("apply/armor",30);
        set_skill("seven-love",100);
        set_skill("masen_whip",80);
        set_skill("force",100);
        set_skill("run_cloud",75);
        map_skill("whip","masen_whip");
        map_skill("dodge","run_cloud");
        set("guild_gifts",({ 4,6,4,6 }));
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "whip" : ({ 110,3,80 }),
  "parry":({ 130,2,60 }),
 "masen_whip" : ({ 150,3,80 }),
  "force" : ({ 135,3,85 }),
  "unarmed" : ({ 100,3,80 }),
"run_cloud" : ({ 140,3,80 }),
]));
        set("no_check_class",1);
        set("adv_class",1);
        set("chat_chance",8);
        set("chat_msg", ({
  "�Ѥs����۵��~�A���G�b����۬Y�H�C\n",
  (:command("sigh"):),
	(:command("wield whip") :),
  
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
                          (:special:), 
  (:command("exert masen_whip"):),
        (:command("wield whip") :),
        (:command("wield whip") :),
  (:command("exert masen_whip"):),
}));
        set("inquiry/�Y�H","�ڥ��b����ڮv��(���k�P�L)�A�A���ݨ�o�ܡH\n");
        set("inquiry/���k�P�L","�o�ѤH�a�n���@�����b�o�������Y�@�B�a�H\n");
        setup();
  carry_object("/open/world1/kkeenn/love/npc/obj/blood_whip")->wield();
  carry_object("/open/world1/kkeenn/love/npc/obj/ten_pearl")->wear();
  add_money("coin",3000);
        }

void init()
{
        object me=this_player();
        object ob=this_object();
   object npc,room;
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
        room=load_object(environment(this_object())->query("exits/up"));
 if( room && objectp(npc = present("sen",room)))
    {
tell_object(me,HIG"�ӤW�b�ܤ@�n�A�@�D��t�L�񪺶¼v�V�A�ĨӡI\n"NOR);     
tell_object(me,npc->name()+HIG"���D�G�s���A����I���v�ӧU�A�@�u���O�I\n"NOR);     
tell_object(me,npc->name()+HIG"�j�n�ܹD�G�c��I���ӧa�I\n"NOR);     
   npc->set("auto",1);
	npc->move(environment(this_object()));
    }
                        return;
        }
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
//        add_action("do_guard","go");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
        object ob=this_object() , me=this_player();
        string gender;

        if( !arg && !me->query_temp("join_l") )
                return notify_fail("�A�Q�n�[�J��������r�H(join ������)\n");
        if( me->query("gender") == "�k��" )
                return notify_fail("�Ѥs����: �ܬO��p�A�����O�������k�ʪ��C\n");

        if( me->query_temp("join_l") && !arg ) arg = "������";
        if( strsrch(arg, "������") == -1 || strsrch(arg, "��") > -1)
                return notify_fail("�A�Q�n�[�J��������r�H(join ������)�)\n");
        if( me->query("gender") == "�k��" ) gender="�h�Q";
        else gender = "�S��";
    message_vision("$N�Q�[�J�u"+ HIM"" + arg + ""NOR+ "�v�C\n",me); 

        if( me->query("class1") )
                return notify_fail("�A�w�O"+me->query("class1")+"���̤l�F�C\n");
        if( me->query("family/family_name")=="������" )
                return notify_fail("�A�w�O�Ѥs�����{�̤F�C\n");
        if( !me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say �o��"+gender+"�i�_���ڧ����@��ơH");
                tell_object(me, ob->name()+HIG"�b�A���仡�D�G"+gender+"�i�_�������گd�N�@�U�ͮv���̪񪺪��p�H\n"NOR);
                tell_object(me, ob->name()+HIG"�b�A���仡�D�G�u�n��o�ѤH�a���@�n[�z�̪�n��?]�A�o�˧ڴN�����F�C\n"NOR);
                me->set_temp("ljoin",1);
                return 1;
        }
        else if( me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say "+gender+"����ڮv���F�ܡH");
                return 1;
        }
        else {
                command("bow "+me->query("id"));
                me->set("guild_rank","���������J���Ǯ{");
message("world:world1:vision",
HIM"\n\t�m���������n�G"HIR"�������D "HIW"�Ѥs��"HIM" ���F"+me->name(1)+HIM"���������J�ǧ̤l�C\n"NOR,users() );

                message_vision("$N�������������̤l�C\n",me);
                me->set("class1","������");
                me->create_family("������",3,"�̤l");
                me->set("adv_class",1);
                return 1;
        }
//      return 1;
}

int do_advance(string arg)
{
//        if (this_player()->query("family/family_name")=="������") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        if (this_player()->query("class1")=="������" && !this_player()->query("class2") ) return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        else return notify_fail(this_object()->query("name")+"�èS���z�|�A�C\n");
}

int accept_object(object me, object ob)
{
        object tob, herb,a;
        tob = this_object();
        if( ob->query("id")!="ron letter" ) return 0;
        if( me->query("gender")!="�k��" ) 
               return notify_fail("�Ѥs����: �ܬO��p�A�����O�������k�ʪ��C\n");
        else {
                command("thank "+me->query("id"));
command("say "+RANK_D->query_respect(me)+"�J�U�s�������ôb�A�N���s����"+RANK_D->query_respect(me)+"���{�a�I\n");
                message_vision("$N�N$n�b�x�ߤ��@�|�A$n�N�Ƭ��������Ƚ������h�A�٬O�n�ݡC\n", this_object(), ob);
                tell_object(me,HIR"�Цb���@��("HIY"Join ������"HIR")�H�K�s�����A���{�C\n"NOR);
                me->delete_temp("ljoin");
                me->set_temp("join_l",1);
                destruct(ob);
        }
        return 1;
}

string guild_rank(object me)
{
        string rank;
        int lv,steps,whip;
        steps = me->query_skill("dodge");
        whip = me->query_skill("whip");
        lv = me->query("level");
        lv = lv/6; 
        if ( whip > 35 && whip > steps - lv*4 )
        {
                if ( whip > 99 ) rank = HIM"���������@�k�P�l"NOR;
                else if ( whip > 70 ) rank = HIW"���������@�k�нm"NOR;
                else if ( whip > 35 ) rank = HIC"���������@�k�Ǯ{"NOR;
        }
        else if ( steps > 40 )
        {
                if ( steps > 99 ) rank = HIC"���U���l���y�B"NOR;
                else if ( steps > 75 ) rank = HIW"���������d������"NOR;
                else if ( steps > 40 ) rank = HIM"���������B�k�Ǯ{"NOR;
        }
        else
        {       switch( lv )
                {
                        case 0: rank = HIR"������������̤l"NOR; break;
                        case 1: rank = HIB"���������Ŧ�̤l"NOR; break;
                        case 2: rank = HIW"���������զ�̤l"NOR; break;
                        case 3: rank = HIY"������������̤l"NOR; break;
                        case 4: rank = MAG"������������̤l"NOR; break;
                        default: rank = HIC"�������U���K�P�l"NOR;
                }
        }
        return rank;
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

	if( this_object()->query_temp("flee") )
	{
		this_object()->set("hp", this_object()->query("max_hp") );
		call_out( (:destruct(this_object()) :), 1);
			return;
	}

        if( !ob ) 
        {
                ::die();
                return;
        }
        if( ob->query_temp("kill_love") ) 
        {
        if( ob->query("class1") == "������" ) 
        {
message("world:world1:vision",
HIY"\n\n�m�j�񲧱m�n"HIM":\n\n\t�������̤l "+ob->name()+HIM"�q�L���������j����I\n\n"+NOR
        ,users());
     ob->add("quest/win",1);
if ( ob->query("quest/win") < 10 )
      {  
          ob->set("title","���������X�v�̤l"); 
      } 
if ( ob->query("quest/win") > 10 )
      {  
          ob->set("title","�������ĥ|�N�P�l");
      }
if ( ob->query("quest/win") > 20 )
      {  
          ob->set("title","�������ĥ|�N����");
      }
 if ( ob->query("quest/win") > 50 )
      {  
          ob->set("title","�������ĥ|�N�@�k");
      }
 if ( ob->query("quest/win") > 100 )
      {  
          ob->set("title","�m�������n�ƫ��D");
      }
 if ( ob->query("quest/win") > 500 )
      {  
          ob->set("title","�������ĥ|�N���D");
      }  
if ( ob->query("quest/win") > 1000 )
      {  
          ob->set("title","����������~����");
      } 
        ob->delete_temp("kill_love");
	ob->add("popularity", 7); 
        ob->set("guild_rank",HIW"�i"HIR"��ⱡ"HIC"�B�߫�"HIW"�j"NOR);
        message_vision(HIW"$N�]���q�L������������A�ҥH��o7�I�n��\n"NOR,ob);
                ::die();
                return;
        }
message("world:world1:vision",
HIR"\n  �m�Z�L�����n"HIM":\n\n\t�������@���Q"+ob->name()+HIM"���ѡA�b����W�Q���W�F�I\n\n"+NOR
        ,users());
	ob->add("popularity", 7); 
        ob->delete_temp("kill_love");
        ob->set("guild_rank",HIW" �i"HIC"�{��"HIR"��"HIM"����"HIW"�j "NOR);
        message_vision(HIW"$N�]�����F�������@���A�ҥH��o7�I�n��\n"NOR,ob);
                ::die();
                return;
        }

        message("world:world1:vision",
HIR"\n  �m�����G�@�n:\n\n\t"HIM"�������ĤG�N���D "HIW"�Ѥs��"HIM"�G�D"+ob->name(1)+"���]���I\n\n"+NOR
        ,users());
        ob->add("popularity", 3); 
        ::die();
        return;
}
int do_guard(string arg)
{
        if( this_player()->query("class2") == "������") return 0;
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("sorry");
           say(HIW"�Ѥs��"NOR"���D�G"HIG"�藍�_�A�W���O���������a�C\n"NOR);
        return 1;
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;
       object targets;
        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(150)<30)
                {
                        damage/=2;
                        message_vision(HIM "\n$N�N�⤤�@�l��X�E�E�K�Q�@�Ӱ�l�A�ƥh�F�j�j����աC\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
 if(query("hp")<query("max_hp")/8 && !is_busy() && !this_object()->query_temp("flee") && random(100) > 80 ) 
           {
	object *go;
//        if( !go = query_temp("last_damage_from") )
//        go = this_player(1);
	go = this_object()->query_enemy();
                this_object()->remove_all_killer();
           command("hehe");
           this_object()->set_temp("flee", 1);
           command("bye");
  message("world:world1:vision",HIM "\n�Ѥs���M���@�n�A�^�����W��ò���D�G\n\n\t\t\t�������ѡA�U���w�O���A�̪��R�ɡA���s�y��...�A�|��~~��~~��~~�C\n" NOR,users());
        if(go) 
	{
		foreach(object each in go)
	{
		if( !query_temp("added") )
		{
                each->add("popularity" ,1);
		each->delete_temp("kill_love");
		this_object()->set_temp("added", 1);
		}
	}
	}
     this_object()->move(__DIR__"../room30");  
	this_object()->set("hp", this_object()->query("max_hp") );
                call_out( (:destruct($1):),1,this_object() );
           }

                return damage;
}

void special()
{
        object me=this_object();
        object* target; 
        int dam = 400 + random(me->query_skill("unarmed"));   
        if(me->is_busy() ) return;
        target=query_enemy();
      message_vision(HIW"\n$N�N�⤤���@�l��ܥ���A�B�_�۳еۯ�������\n\t\t�i"HIR"�������D"HIW"�j�I�I\n�@�Ѥ����j�j�S�ݦ��L��d�˪��u��ﭱ�V$n�u���ӥh�A$n�b���⤣�Ϊ����p���U\n���ѯu�𪽱��R��$n���ݵġA$n��M�ܪ����աA���G�O����Q���Y�������ˡI",me,target);
        target->receive_damage("hp",dam,me);
        message_vision("�y��$N" +dam+ "�I���ˮ`�C\n",target);
    return;
}
