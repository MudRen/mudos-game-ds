#include <ansi.h>
inherit NPC;

void create()
{
       set_name("��l��",({"tsai tsi lain","tsai","lain"}));
       set("long",@LONG
    ��l���A��l�¥S�f�Ҭ��K�������Ѥ媺�o�N�̤l�C�䤤��l��
�Ѹ��o�o�A���q�F���A���M��J�v�����Z�\�P��S�u�b�B�򤧶��C��
��������c�e�A�ҥH���֦b���򤤦樫�A�h�b�ݩ�v�����ǡA�]�]
���o����Ѥ媺�u�ǡC�ѩ��S�󦿴򤤦h�~�X�d�A���G�o��v¡��
�̯e���u���A�G���v����C���p�����G�¯e�_�o�A���ʵۤ@���K�j�j
�j���ߡA�����n���Q���h�W�C
LONG);
       set("gender","�k��");
       set("age", 23);
       set("level", 27);
       create_family("�K���� ",7,"�̤l");


       set("int", 90);
       set("dex", 70);
       set("guild_gifts",({10,7,0,3}));


      set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("fork",90);
        set_skill("bagi_fist",99);
        set_skill("da-fork",90);
        set_skill("horse-steps",99);



       set("chat_chance", 20);
       set("chat_msg", ({
            "��l�²`��Z�ܡA���r��B�A���G�Q���h�W���ˤl�C\n",
            "�u����l�������@�n�A�^�F�U�h�A�ݤF�X�f���S�ߵ��K�j���F�_�ӡC\n",
            (:command("exert da-fork"):), 
            (:command("exert bagi_fist"):),
             }));


        set("chat_chance_combat",60);
        set("chat_msg_combat", ({

                (:command("exert bagi_fist"):),
                (:command("exert da-fork"):),

        }) );
   
        setup(); 
        carry_object(__DIR__"wp/b_s_pike")->wield();
}
