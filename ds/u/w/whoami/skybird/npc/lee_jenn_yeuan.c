#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("����",({"lee jenn yeuan","lee","jenn","yeuan"}));
 set("long",@LONG
�L�������C�ءA���Y���վv���n��L�ֽ��K�ª�����Φ��j�P��
���A�ӥL�������٤��ɰ{�X����A���H���P�����L�������A�L
���ധ�R�����j����I�i�j�j�Z�����ޡA��O���H�j���_��E
LONG);
 set("title",HIC"�ѱ��t�u�@�ê�"NOR);
 set("attitude","peaceful"); 
 set("age",38);
 set("gender","�k��");
 set("level",46+random(5));  
 set("max_hp",11000+random(3000)); 
 set("max_ap",8000+random(5000)); 
 set("str",85+random(30)); 
 set("dex",75+random(30));  
 set("Merits/bar",4+random(3));  
 set("Merits/wit",3+random(3)); 
 set_temp("apply/damage",135+random(30)); 
 set_temp("apply/hit",155+random(30));
 set_skill("bagi_fist",100); 
 set_skill("horse-steps",100);
 set_skill("unarmed",100);
 set_skill("da-fork",100); 
 set_skill("jingang-plan",100);
 set_skill("fork",100); 
 set_skill("dodge",70);
 set_skill("parry",70);
 map_skill("fork","da-fork");
 map_skill("unarmed","bagi_fist");
 set("chat_chance_combat",300);
 set("chat_msg_combat",({
                         (:command,"say �j�x�p��I�䦺�H�I":),
                         (: combat_ai :),
 })); 
 set_temp("TEAM_NPC",1);
 setup();
 carry_object(__DIR__"eq/steel_pike");
 carry_object(__DIR__"eq/sun_longpike")->wield(); 
 carry_object("/open/world1/wilfred/sand/npc/eq/eq24")->wear();
 carry_object(__DIR__"eq/flying_shoes")->wear();
 set_living_name("TEAM_NPC");
} 

void init()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  ::init();
  if( me->query_temp("TEAM_NPC") ){
    me->add_team_member(find_living("TEAM_NPC")); 
    ob->add_team_member(find_living("TEAM_NPC"));
    }
  if( me->query_temp("SkyBird/enemy") ) {
    ob->kill_ob(me);
    me->kill_ob(ob);
    }
}
void die()
{
        int i;
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",3); 
        ob->add_temp("SkyBird/enemy",1);
      
        message("world:world1:vision",
     HIY"\t�ѱ��t�u�@�ê��y�����z�A�ľԨ�̫�@��A���M����"+ob->query("name")+"�A���ѱo�ѤU�}�ӡK�K\n"NOR
        ,users() );
        tell_object(ob,HIW"\n(�]���A�����F�����A�ҥH�o��F 3 �I�n��C)\n"NOR); 
      
        ::die();
        return;
}

void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield pike"); 
                command("wield pike 2");

        /* ���ˮɷ|�ۧ�����  */
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* �ĤH->attack */
        command("team form jingang-plan");        command("exert da-fork"); 
        command("exert bagi_fist");
        this_object()->add_busy(-2);

        return;
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N�q�h���ǥX�@�~�p�~�l�A�N�~���G���٦b�ˤf�B�A�ˤf�K���_��¡�X�F�E\n"NOR, me);              
    me->receive_heal("hp",random(800));
    me->receive_heal("mp",random(800));
    me->receive_heal("ap",random(800));
    return;
}
 
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<65)
                {
                   damage/=100;
                   message_vision(HIR"$N�@��½���A��b���l�����L�o���������E\n" NOR,this_object(),who);
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

