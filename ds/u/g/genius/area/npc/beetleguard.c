#include <ansi.h>
inherit NPC;
//�ק�Х��ӦۧN��
mapping *combat_action = ({
        ([      "action":               "$N�i�}�b�H���L�ڴµ�$n��$l�����r�h",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "�r��",
        ]),
        ([      "action":               HIW"�u��$N"HIW"��ĲŽ���@�l�@��A�V��$n"HIW"��$l���_�⥴"NOR,
                "attact_type":  "bio",
                "damage_type":  "���",
        ]),
        ([  "action":                   "$N�|�_�e�ϡA�ΤO�a��V$n��$l",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
       ([  "action":                   "$N���I�ҩ��M���j�A��$n��$l���F�L�h"NOR,
                "attact_type":  "mit",
                "damage_type":  "����",
        ]),

});
void do_clean();

void create()
{
        set_name(HIG"�����Φu��"NOR,({"Guard of armor beetle","guard","beetle"}) );
        set("long",@LONG
�o�O�@�إi�Ȫ��Ϋ��Ǫ��A���W�ܵۤ@�h�w�i�������ݪ��ߡC
�A���e���o�@����O�o�����������Ԥh�A�Pı�W��@�몺�j��
�����٭n�j���\�h�A�O�H�J���N���H�ӷX�C
LONG
);
        set("limbs", ({
                "�Y��", "�V��", "�ݤf","�I��","�y��","����","�e�}","��}",
        }) );
        set("title",HIW"����");
        set("age",16);
        set("level",50);
        set("gender","����");
        set("race","monster");
        set("attitude", "killer");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "�����Φu�ê�ĲŽ���_�a���ʵۡA�@��ĵ�١C\n",
        "�����Φu�ê�ĲŽ���_�a���ʵۡA�@��ĵ�١C\n",
        "�����Φu�ê�ĲŽ���_�a���ʵۡA�@��ĵ�١C\n",
        "�����Φu�ê��I�Ҿ_�ʵۡA�o�X�b�H���n�T�C\n",
        "�����Φu�è������]�l���M���A����V�@���A�n���o�{�F����C\n",
        }));
        set_skill("mob_bite", 85);
        set("addition_armor",100);
        set("addition_damage",50);
        add("apply/hit",50);

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
