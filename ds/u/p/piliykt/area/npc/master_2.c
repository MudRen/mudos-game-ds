#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":               "$N�Υ����Q�L��$n��$l�@�}�r�r",
                "attact_type":  "bar",  
                "damage_type":  "�r��",
        ]),
        ([      "action":               "$N��M�i�}�ͻH�V$n����V���F�L�h",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N���$n��$l�r�M�R�X�@�D���K",
                "attact_type":  "bio",
                "damage_type":  "�N��",
        ]),
    ([  "action":       "$N�ƨg���R�ʧQ���g��$n��$l",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
});
void do_clean();

void create()
{
       set_name( HIR"�����"NOR ,({ "fire phoenix","phoenix","fire" }) );
       set("title",HIC "����" NOR);
         set("long",@LONG
����ĬO�@���ǻ������ͪ�, �Ⲵ�o��, ���������F���Ф�, �ͻH�i
�}�i�F���ت�, ���w�������a��, �ӥB�����ٷ|�o�X���K, ���a��e
������@��, ���N�����u.
LONG    
);
         set("race", "���~");    
         set("attitude", "aggressive");
         set("gender", "�e");
         set("age",35);
         set("level",60);
         add("addition_armor",90);
         add("addition_damage",60);
        set("chat_chance", 13);
        set("chat_msg",({ 
        "����Ĩ��W�o�X�������P���C\n",
        "���񩿵M���@�}�������H�ݤ��L��ӡC\n",
        "���񩿵M���@�}�������H�ݤ��L��ӡC\n", 
        "����ĵo�X�}�}����q�n�C\n",
         }));      
setup();
carry_object(__DIR__"eq/cloth_2.c")->wear();
       
set("actions", (: call_other, __FILE__, "query_action" :));
 }
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob ) 
         {
                 ::die();
                 return;
         }
         message("world:world1:vision",
HIY"\n�i�Z�L�����j"+HIW "�ǻ����� " HIR"���� "HIR"����� "NOR"���b "+ob->name(1)+" ���⤤�C\n\n"+NOR
        ,users());

            ob->add("popularity",2); //�n��
         ::die();
         return;
}

