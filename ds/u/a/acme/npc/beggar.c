#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�Ѥ^��", ({ "old beggar","beggar" }) );
        set("level",45);
        set("gender","�k��");
        set("combat_exp",4500);
        set("long" ,"�L�O�վw�ܯݥB�~�Ƥw�����Ѥ^���A��mİ�����Z���b�a�W�C\n");
        set("age",80);
        set("evil",-40);
        set_skill("unarmed",100);
     set_skill("sword",100);
     set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance", 15);
        set("chat_msg", ({
        }) );
        set("inquiry/�C", "�x�I�H�פѤU���C�G\n"
                          "            �ĤC���B�Ĥ��ѻ�B\n"
                          "            �Ĥ��p���B�ĥ|���СB\n"
                          "            �ĤT�F���B�ĤG�L�W�C\n"
                          "�Ѥ^�����D�G�o�ǼC�i�O�Z�L���⤬�۪��ܡA���D���i�o�����L�Q���r�C\n",
           );
        set("inquiry/�Ĥ@", "�o�K�o�K�K�I�K�I\n");
        set("inquiry/�Ĥ@�C","�o�K�o�K�K�I�K�I\n");
        setup();
}
