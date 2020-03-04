#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("�D����",({"wen tzyy ian","wen","tzyy","ian"}));
 set("long","\n");
 set("title",YEL"�Q�U�s�s��"NOR);
 set("age",38);
 set("gender","�k��");
 set("level",65);
 set("max_hp",14000+random(3000)); 
 set("max_ap",8000+random(5000)); 
 set("Merits/bar",8+random(5));  
 set("Merits/wit",3+random(3));  
 set("Merits/tec",3+random(3));  
 set_temp("apply/str",15+random(30));  
 set_temp("apply/dex",15+random(30));  
 set_temp("apply/damage",45+random(30));  
 set_temp("apply/armor",35+random(30)); 
 set_temp("apply/hit",155+random(30));
 set_skill("whip",100);  
 set_skill("masen_whip",100); 
 set_skill("force",100); 
 set_skill("seven-love",100); 
 set_skill("dodge",100); 
 set_skill("run_cloud",100); 
 map_skill("dodge","run_cloud");
 map_skill("whip","masen_whip"); 
 set("MKS",10000); set("chat_chance_combat",300);
 set("chat_msg_combat",({
                         (: combat_ai :),
 })); 
 set_temp("pill",6);
 setup();
 set_living_name("Wen_Tzyy_Ian"); 
 carry_object(__DIR__"eq/snake-bone_blade")->wield();
} 

void init()
{ 
  object me=this_player(),ob=this_object();
  ::init();
  if ( !me->query("class1") ) return; 
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);
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
        if( !ob->query("quest/SkyBird") && ob->query_temp("assassinate") ){
        message("world:world1:vision",
HIG"\t�y�F�_�����z\n" 
CYN"\n\t\t�s����Y�@���V�áI�s��|�B�b���I�I\n"HIW+BLK"\n\t\t\t�Q�U�j�s���@�c�h�ݪ��Y�Y�D���ϳQ"+ob->query("name")+"���t���F�E\n"NOR         
        ,users() ); 
        ob->delete_temp("assassinate"); 

/* �}�F�A��        ob->set("quest/SkyBird",1); */        } else {
        message("world:world1:vision",
HIG"\t�y�F�_�����z\n" 
CYN"\n\t\t�s����Y�@���V�áI�s��|�B�b���I�I\n"CYN"\n\t\t\t�Q�U�j�s���@�c�h�ݪ��Y�Y�D���ϲש�Q"+ob->query("name")+"����F�E\n"NOR         
        ,users() );
environment(this_object())->door_open(1);
        }
        tell_object(ob,HIW"\n(�]���A�����F�D���ϡA�ҥH�o��F 5 �I�n��C)\n"NOR); 
        ob->add("popularity",5); 
        new(__DIR__"obj/head")->move(this_object());

        ::die();
        return;
}

void combat_ai()
{
        int i,x;
        object *target,npc;

        target = all_inventory(environment(this_object()));
        x = sizeof(target);

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield blade"); 

        /* ���ˮɷ|�ۧ�����  */
        if( this_object()->query("hp") < this_object()->query("max_hp")/3 ) 
        this_object()->add_busy(-2);
        heal();

        return;
}

void heal()
{
    object me=this_object(); 
    if( !me->query_temp("pill") ) return;
    if( me->query("hp") > me->query("max_hp")/3 ) return;

    message_vision("$N�q�h���ǥX�@��"HIY"�����ĤY"NOR"�A�H�Y�]�F�U�h�E\n", me);              
    me->receive_heal("hp",me->query("max_hp"));
    me->receive_heal("mp",me->query("max_mp"));
    me->receive_heal("ap",me->query("max_ap"));
    me->add_temp("pill",-1);
    return;
}
 
varargs int receive_damage(string type, int damage, object who)
{
        int val,time;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(10)<4)
                {
                   message_vision(HIR"$N���U���W�˶աA���צ�$n�������A�H�Y�V�e��$n�o�ʧ����I\n"NOR,this_object(),who);
                   for (time=0;time<1+random(2);time++) 
                   { 
                   this_object()->add_busy(-2);
                   COMBAT_D->do_attack(this_object(),who,this_object()->query_temp("weapon"),4);
                   COMBAT_D->report_statue(who); 
                   }
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}


