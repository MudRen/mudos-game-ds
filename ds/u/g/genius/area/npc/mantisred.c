//mantisred
#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":"$N���U�Q���M�W�u���ӨӡA�����a�V$n���W���h�C",
                "attact_type":  "bar",
                "damage_type":  "�ٶ�",
        ]),
});
void do_clean();

void create()
{
        set_name(RED"��������"NOR,({"red mantis","red","mantis"}) );
        set("long",@LONG
���e�O�@���t���⪺�W�j�������A���j�����ߥO�H�򰩮��M�C
LONG
);
        set("limbs", ({
                "�Y��","�ݤf","�I��","����","�e�}","��}",
        }) );
        set("age",3);
        set("level",25);
        set("gender","����");
        set("race","monster");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
"���⪺�j�������ʧQ�b�A��F�����������C\n",
"����j�����C�U�Y���A�ΤO�a�n�ʵۡC\n",
        }));
        set_skill("mob_bite", 85);
        set("addition_armor",40);
        set("addition_damage",40);

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
