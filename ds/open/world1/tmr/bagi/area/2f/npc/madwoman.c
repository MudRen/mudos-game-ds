#include <path.h>
inherit NPC;

void create()
{
        set_name("�ƱC�l",({"madwoman","woman"}));
        set("long" ,@long
    �@�Ӧ��Y�������ƱC�l�A���W����A�}�ꤣ���A�٦��G�䪺�Ĩ��ǥX
�A�����h�[�S�~���A���o�ٯ�Ԩ��U�h�C�A���@�o���y�A��O�H�Ͱ����A
�٦����w���ˤf�A�w�g�L�k�M�����Ѧo�쥻�����ؤF�C
long
);
        set("attitude", "friendly"); 
        set("age", 35);
        set("gender","�k��");
          set("level", 35);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                  (:command("exert masen_whip"):), 
        }) );
        set_skill("whip",90);
        set_skill("masen_whip",90);
          set_skill("force",50);
        set_skill("run_cloud",75);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"wp/whip3")->wield();
          carry_object(TMR_PAST"bagi/npc/obj/left-arm");
}
