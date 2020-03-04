#include <ansi.h> 
inherit NPC;   
void flee();  
void FG();
void create()
{
  set_name(HIY"���s"NOR, ({"turn dragon","dragon"}) );
  set("long","�t�������u�@�~�A���j�²r�A���Ӥ���H���C�A�����O�j�j�C\n");
  set("race", "beast"); 
  set("title",HIG"�a"NOR);
  set("unit","��");
  set("age",80);
  set("level",70+random(this_player()->query("level")/5)); 
  set("max_hp",40000);
  set_skill("dodge",150);
  set_skill("unarmed",150);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) ); 
        set("chat_chance_combat",3);
        set("chat_msg_combat",({ 
      (: FG :),
      (: random_move() :), 
      (:command("follow "+this_player()->query("id")+""):), 
      (: flee :), 
}));  
  setup(); 
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIY"\n\n$N"+HIW"�L�̫C�����{�I\n"
                    +HIG"���j��q��M�Q�X�I..\n"
                    +HIR"$n�Y��T�S�b���j��q�̡I\n\n"+NOR,me,target);  
     target->receive_damage("hp",700+random(200), this_object());
      return 1; 
    }
}   

void flee()
{
     object me=this_player(),ob=this_object(); 
     if (ob->is_busy() ) return;
     //if(ob->query("hp") < ob->query("max_hp")/10)
     switch(random(6))
     {       case 0:
             message_vision(HIY"���s"+HIW"���V���䪺���߸̡A�����F�I�H\n"+NOR,me);
             destruct(ob);
             break;
             case 1:
             message_vision(HIY"���s"+HIW"�Q���V���䪺���߸̡A���O�Q"+me->query("name")+"�פF�^�ӡI\n"+NOR,me);
             me->start_busy(2); // ���s�ҥH busy 
             break;
      }
      return;
}   
void FG()
{
     object me=this_player(),a,b,c;
     if(this_object()->is_busy()) return;
     else{ message_vision(HIY"���s"HIR"�j�q�@�n�I�@�ιΪ���l�I�������E�I\n"NOR,me);
           a=new(__DIR__"red-ball");
           b=new(__DIR__"blue-ball");
           c=new(__DIR__"green-ball");
           a->move(environment(me));
           b->move(environment(me));
           c->move(environment(me));
           a->kill_object(me);
           b->kill_object(me);
           c->kill_object(me); 
         }
      return;
}/*
int S_ATTACK(string arg)
{
    object me=this_player(),ob=this_object(); 
    if(ob->is_busy() ) return;
    if(!me->query("class1")=="�e����")  
    {
    switch(random(6))    {     case 0:
          message_vision(HIY"$N"+HIW"�@�ӥϧ��A���n�����F"+me->query("name")+"��$l�I"+NOR,me);          me->receive_damage("hp",500,this_object());
          break;
          case 1:
          message_vision(HIY"$N"+HIW"�ĤO�@��I�쪺"+me->query("name")+"�O�M����ˡE�E\n"+NOR,me);
          me->receive_damage("hp",400,this_object());
          break;
          case 2:
          message_vision(HIY"$N"+HIW"�V$n�g�b�ӥh�I����"+me->query("name")+"���F�Q�l�ػ��I\n"+NOR,me);
          me->receive_damage("hp",600,this_object());
          break;
    } 
    return 1; 
    }
} 
*/
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
                        message_vision("$N�j�q�@�n�I�˸ѤF�ĤH����աI\n" NOR,this_object());

                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}

void die()
{
   object ob,eqp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", 
    HIR"\t�i�t  ��  ���j"+HIG"�a  "+HIY"���s  "+HIW"�Q"+ob->name(1)+"�����F�C\n\n"+NOR,users());
        if( random(17) ) 
                eqp=new(__DIR__"obj/dragon-ring");
        else  if( random(3) )
                eqp=new(__DIR__"obj/dragon-sword");
        eqp->move(this_object());
        ::die();
        return;
}

