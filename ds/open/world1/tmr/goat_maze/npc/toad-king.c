#include <ansi.h>
inherit NPC;


mapping *combat_action = ({
        ([      "action":       "$N�i�j�L�ڴµ�$n��$l�@�}�r�r",
                "attact_type":  "bar", 
                "damage_type":  "�r��",
        ]),
        ([      "action": "$N��M��$n����V���F�L�h",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([      "action": "$N�@�i�L���X����w�p�K�����Y�A��V$n��$l",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
        ([      "action": "$N���$n��$l�R�X�@�b�S�¤S�䪺�@�r�f��",
                "attact_type":  "wit",
                "damage_type":  "����",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void create()
{
  set_name( HIR "�����" NOR, ({"toad king", "toad", "king" }) );
  set("long",@LONG
�o�O�@��������A�U�١u������v�A�j��������իᦳ�r���A���c�r�ʤ�
�c���C�o����������F�T�ʤ���A�j���n�n�X�ӤH�~��򪺦�L�A�e����
�G���A�A����������A�ݰ_�ӬO���n�S���Ǫ��C
LONG
);
        set("age", 200 + random(50) );
        set("title", "�B�L��}");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "�I��","�y��","����","�e�L","��L","����",
        }) );

        set("gender", "����" );
        set("race","beast");
        set("level", 50);
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        if( random(100) < 90 )
                carry_object(__DIR__"obj/toad-leggings")->wear();
        else
                carry_object(__DIR__"obj/toad-leggings2")->wear();
           carry_object(__DIR__"obj/toad-wart");
           carry_object(__DIR__"obj/pan_eye");
        set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
}

int special_attack(object me, object target, int hitchance)
{
  int dmg;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if( random(9) ) return 0;

    dmg = query_damage()/2 + random(query_damage());
    dmg = COMBAT_D->Merits_damage(me, target, dmg, "wit");
    if(dmg < 1 ) dmg = 100 + random(50);
    message_vision( "$N�I�W�r���u�R�v�a�Q�X�@�D�_�r�L��"HIR"����ĲG"NOR"�A��������$n�y�W("+dmg+")�I\n"NOR, me, target);
    target->receive_damage("hp", dmg, me );
    target->apply_condition("poison", 3 + random(5) );
    target->add_busy(1);
    return 1;
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
    message("world:world1:vision",
                HIR"\n\t���`�B�L�Ѥ쪺�ʦ~�r���u������v�ש�Q"+ob->name(1)+HIR"�����F�I�I\n\n"+NOR
            ,users());
      ob->add("popularity", 3);   //�n��
        tell_object(ob, "�A��o3�I�n��C\n");
    ::die();
    return;
}

