#include <ansi.h>
inherit NPC;

varargs int do_remove(object me, object ob,int silent);
mapping *combat_action = ({
        ([  "action":       "$N�������n��$n�������A�N�b$n�鯫���ڡA$N��Ĳ��w���V$n�Y���C",
                "attact_type":  "sou",
                "damage_type":  "���F�ˮ`",
        ]),
        ([  "action":       "$N�k���Ť@���A�@���C��⪺�����̪ŧ�V$n��$l�C",
                "attact_type":  "wit",
                "damage_type":  "�ж�",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW""BLK"�ܤ��]"NOR, ({"mind flayer","flayer"}) );
  set("long",@LONG
�ܤ��]�O�ө_�����ͪ��A��������p��֯릳�u�ʦӧe�H����A�ê�
���|�ϥ����B�D�H�G�A�ܤ��]���Y�ݰ_�ӹ��O�@�Ӧ��|��Ĳ�⪺����
�A���@���s�~�զⲴ���|�Ҧ��H�P��򰩮��M�A������l���y����
���ī�A���p�K�������L�ڷ|�����w���o�����H�G�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",250);
  set("gender", "����" );
  set("level",46);
  set("attitude", "aggressive");
  set("evil",20);
  set("title",GRN"  ���~ "NOR);
  set("limbs", ({ "�Y��", "����","�Y�W��Ĳ��","�ⳡ","�}��" }) );
  set("verbs", ({ "bite" }) );
  set("Merits/sou",6);
  set("Merits/wit",5);
  set("chat_chance", 15);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
//  carry_object(__DIR__"eq/black-magic-robe")->wear();
}

void init()
{        
  ::init();
  if( random(this_player()->query_int()) < 30 && userp(this_player()) )
  {
    message_vision(HIM"$N��$n�o�X�j�P���i�A$n�@�ɶ��Y�w�دt�L�k��ʡI\n"NOR,this_object(),this_player() );
    this_player()->add_busy(random(2)+2);
  }
} 

int special_attack(object me, object target, int hitchance)
{
  object *inv;
  int damage,i;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( random(target->query_int()) < 5 )
  {
    damage=300-(target->query_shield())+random(50);
    message_vision("$N"HIW"���Y���@�}�@�P��ʤ���A���$n�ϥX"HIM"�i���F�z�}�j"NOR"�A\n"
                  +HIW"$nı�o�L�Ʊj�P������b����½�u�A�h�W����I("+damage+")\n"NOR, me, target);
    target->receive_damage("hp",damage,me);
    target->receive_damage("mp",damage/10,me);
    return 1;
  }
  else if( random(target->query_dex()) < 5 )
  {
    damage=200-(target->query_shield())+random(30);
    if(damage < 0) damage=0;
    message_vision("$N"HIR"�����ά�M�Ƭ��@�D�¼v�A���Y�Ө�$n������A����$n�oı�ɤw�QĲ��\n"
                  +"����l�A$n�Pı���G���ֳt�a�Q�l���I("+damage+")\n"NOR, me, target);
    target->receive_damage("hp",damage,me);
    if( me->query("hp")+200 < me->query("max_hp") )
      me->receive_heal("hp", damage);
    return 1;
  }
  else if( random(target->query_sou()) < 1 && !random(2) ) 
  {
    message_vision("$N"HIM"�������p�P�`�����x���A$n���ѱo�Q�ʯv�F�ߴ��I\n"NOR, me, target);
    switch( random(6) )
    {
      case  0: 
            message_vision(YEL"$N�i�R�����G�y�ڬO����P�l�I�z\n"NOR,target);
            target->add_busy(random(2));
            break;
      case  1:
            message_vision(YEL"$Nı�o�@�ɯu�O���n,�C�˪F�賣�ȱo�A�֩�C\n"NOR,target);
            target->add_busy(random(2));
            break;
      case  2:      
            message_vision(YEL"$N�S�X���շ��몺���e... :D~\n"NOR,target);  
            target->add_busy(random(2));
            break;
      case  3: 
            message_vision(YEL"$N���������_�F�x�����C\n"NOR,target); 
            target->add_busy(random(2));
            break;
      case  4: 
            message_vision(YEL"$N�������@�˧ּ֪���Ӵ�h�C\n"NOR,target); 
            target->add_busy(random(2));
            break;
      case  5:
            inv = all_inventory(target);
            for(i=0; i<sizeof(inv); i++)
              do_remove(target, inv[i]);
            write("Ok.\n");
            break;
    }
    return 1;
  }
  return 0;
}

// copy ��/cmds/std/remove.c
varargs int do_remove(object me, object ob,int silent)
{
        string str,gender;

        if( (string)ob->query("equipped")!="worn" )
                return notify_fail("�A�èS���˳�"+ob->name()+"��@����C\n");

        if( ob->unequip() )
        {
                if(!silent)
                {
                        if( !stringp(str = ob->query("unequip_msg")) )
                                switch(ob->query("armor_type")) {
                                        case "cloth":
                                        case "armor":
                                        case "surcoat":
                                        case "boots":
                                        case "pants":
                                        case "legging":
                                        case "mask":
                                        case "hands":
                                        case "neck":
                                        case "finger":
                                                str = YEL "$N��U�@"+ob->query("unit")+"$n�C\n" NOR;
                                                break;
                                        case "bandage":
                                                str = YEL "$N�N$n�q�ˤf�B��F�U�ӡC\n" NOR;
                                                break;
                                        default:
                                                str = YEL "$N���U�@"+ob->query("unit")+"$n�C\n" NOR;
                                }
                        if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
                        else
                        {       
                                if(me->query("gender")=="�k��") gender="�p";
                                else gender="�A";
                                str=replace_string( str, "$N", gender);
                                str=replace_string( str, "$n", ob->name());
                                tell_object(me,str);
                        }
                }
        if(me->is_fighting()) me->add_block(1);
                return 1;
        } else
                return 0;
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
  ob->add("popularity",2);
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);      
  switch( random(100) )
  {
    case  0..5: new(__DIR__"eq/brambly-crown")->move(this_object());
          break;
  }
  ::die();
  return;
}
