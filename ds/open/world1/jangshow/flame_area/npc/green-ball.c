#include <ansi.h> 
inherit NPC;    
mapping *combat_action = ({
        ([      "action":       "$N�H���֪��t�׼��V$n��$l�I",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "����",
        ]), 
});  
void create()
{
  set_name(HIW"���s�y��"NOR, ({"turn dragon-ball-green","ball","green"}) );
  set("long","���s�H���O�X�ʮ�l�Ҳ��ͪ��y��C\n");
  set("title",HIG"��"NOR);
  set("unit","��");
  set("level",40); 
  set("max_hp",10000);
  set_skill("dodge",100);
  set_skill("unarmed",100);
        set("chat_chance_combat",9);
        set("chat_msg_combat",({
           (:command("follow "+this_player()->query("id")+""):),
}));   
        set("default_actions", (: call_other, __FILE__, "query_action" :));
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
      message_vision(HIW"\n\n$N�e�t���ļ�$n������I\n"
                    +HIR"$n�Q�������F�Q�l�ػ��I\n\n"+NOR,me,target);  
     target->receive_damage("hp",200, this_object());
      return 1; 
    }
}    
/*
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
*/
