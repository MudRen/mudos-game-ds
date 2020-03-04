#include <ansi.h>
inherit __DIR__"zombiekill";
inherit NPC;

void create()
{
        set_name("�ѵ�" ,({"zombie le-jit","jit"}) );
        set("long",@LONG
�ѵ��O���ܫܤ[���L�ͤ��A�ѩ�w�g�l���\�h����A�S�O�a���ɩѤ���C
�ͫe��O�Z�L���D�H�h�A�u�i���]���t�ަӦ��A���M�l������ӫ��ܡA��
���F�L�ͤ��A�åB�٦b�ø������Ϫ���L������ܡA�Ӿ֦��\�h����U�A
�Q�X�~�e�o�{�ʨ���񦳵ۤj�q���ߡA�]���Ө즹�a�W�j��O�q....
LONG
);
        set("age",223);
        set("race","�H��");
        set("title","�L�ͤ�");
        set("level",50);
        set("attitude", "aggressive");
        set("gender", "�k��" );
        set("Merits/bio",8);
        set("Merits/wit",3);
        set("Merits/bar",9);
        set("exp",40000+random(5000));
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("chat_chance",8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (: zombie_kill,this_object() :),
                (: zombie_heal,this_object() :),         }) );
        setup();
        set_living_name("zombie-war-mob");
         carry_object(__DIR__"../eq/silver-cloth")->wear();
         carry_object(__DIR__"../wp/corpse_fist")->wield();
         set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return s_action[random(sizeof(s_action))];
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
 message("world:world1:vision",HIW"\n    �ѵ�"+WHT+"���e�j�q�J"HIR"�����ѵ�"+ob->name(1)+"���ơA�ڥ��|�[���^��\n\n"NOR,users());       ob->add("popularity",4); //�n��
         tell_object(ob,HIG"�A�o��|�I�n��F�C"NOR);
                     ::die();
                     return;
}










