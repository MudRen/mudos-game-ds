#include <ansi.h>
inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);
 void create() {
  set_name(HIR"�d"NOR"�j�u"HIM"�b"NOR, ({"the aeonian of year beast","beast"}) );
  set("long",@LONG
�ʦL����]�x�w�g���Ƥd�~�����~�A�b�d�~���e�A�ڻ��Ʀ�k�O���W���k�v
�ϥδ����ѼƫʦL�~��u�b�ʦL�b�����]�x���C�����~���ʥ��r�A�̦n�ַS
�L�����C
LONG
);   set("gender", "����");  
  set("race", "beast");
  set("unit","��");
  set("age",2312+random(10));
  set("level",51+random(10));
  set("attitude", "aggressive");
  set("title",HIC"<��>"NOR); 
  set("limbs", ({ "�Y��", "����","�ݳ�","����","�e��","���",}) );
  set("verbs", ({ "bite","crash","claw" }) ); 
  set("chat_msg_combat", ({
                        (:do_heal:), 
                        (:do_heal:), 
                }) );        
  set("Merits/bar",12);
  set("Merits/bio",10);
  add("addition_armor",99+random(12));
  set("chat_chance", 15);
  setup();
  }

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
    if(!random(3) )
    {
      message_vision(NOR"�u"HIM"�b"HIG"�@�ʨe�����ڱ��F�@�j�}���A��$N�L�k�ϤO!!\n"NOR,this_player() );
      this_player()->add_busy(random(1)+1);
    }
} 

// �԰�������
void do_heal()
{
        object me=this_object();
        if(me->query("hp") < me->query("max_hp")/2)
        {
                message_vision("$N"HIY"�ϥX�u�j�ͪ��A���v�����^�_�F���֪���O�C\n" NOR,me);
                me->heal("hp",110);
                me->add_busy(1);
        } else {
                if(me->is_busy() ) return;
                if(me->query_temp("do_attack") ) return;
                message_vision("$N"HIG"�����D�ʡA�����O�q�K�ɼW�ƭ�!!\n" NOR,me);
                me->set_temp("do_attack",1);    // mark �קK�h������
                me->add_temp("apply/damage",45);
                me->add_temp("apply/hit",250);
                        me->attack();
                        me->attack();
                me->add_temp("apply/hit",-250);
                me->add_temp("apply/damage",-45);
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
                        message_vision("$N"HIR"�����������d�z�F�A�즳�������I�I\n" NOR,this_object());

                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}
 int special_attack(object me,object target,int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))

    {
      message_vision(NOR"�u"HIM"�b"HIR"��M�P�F�a�A���֪��t�ױq�A�I��ϥX���r���Q���A�ΤO�@��I�I\n"NOR,target);
                      if(random(target->query_dex()) >35){
                      damage=400-target->query_armor()+random(100);
                      target->receive_damage("hp",damage,target); 
message_vision("\n"HIR"���fŧ���@�y��$N"NOR""+damage+"�I���ˮ`�C\n",target);
} 
else
    {
    message_vision(HIG"\n$N�F�ӫ׶W�G�`�H�A�w�O���ͥ��׶}�F���f�����I�I\n"NOR,target);
    return 1;
    }
        return 1;
  }
  return 0;
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
        HIC"\n\t<�Ӧ۪F�誺����> �G"+HIC"<��> "HIR"�d�~"HIG"�u"HIM"�b"HIW"�ש�b�d�~����Q���i��"+ob->name(1)+"���`�F!!\n\n"+NOR
        ,users());
        ob->add("popularity",10);      
        tell_object(ob,HIG"�A��o[10]�I�n��@�����y�C"NOR);
        if( random(100) )
                eqp=new(__DIR__"eq/god-neck");
        else
                eqp=new(__DIR__"eq/aeonian-ring");
        eqp->move(this_object());
        ::die();
        return;
}





