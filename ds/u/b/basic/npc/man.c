#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�\�w�Դ�" , ({ "catch man","man" }) );
        set("long",
                  "�L�ON.Y.T�������`���A\n"
                  "�]���Ȧ���ֺ��\��\n"

            );
        set("title",HIY"N.Y.T"HIW"�̰��`��"NOR );
        set("level",41);
        set("race","�H��");
        set("gender","�k��");
        set("age",51);
        set_skill("sword", 72);
        set_skill("parry", 77);
        set_skill("dodge", 71);
        set("chat_chance", 5);
        


        setup();
       carry_object("/u/b/basic/wp/sword1")->wield();
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
        {
message("world:world1:vision", HIW"\n ���ӮɪŶǨӪ��q�l�T���GN.Y.T"HIY"�̰��`��
"NOR"�\�w�Դ�

�ש�ѵ��F"HIR + ob->name(1) + " "NOR HIW"�C ] \n\n"NOR, users());
        ob->add("popularity", 1); //�n��
 tell_object(ob,HIW"(�]���A�����F�ѻ\�A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
}
        ::die();
        return;
}
