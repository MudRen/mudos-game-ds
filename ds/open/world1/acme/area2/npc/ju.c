#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�p��", ({ "siu ju","siu","ju" }) );
        set("level",10);
       set("combat_exp",1000);
        set("long" ,
                 "�o�O�Ѵݨ��Ъ��]�k�A�o�b���⪱�ۤѴݨ��ЩҦ��ê��é_�_��\n"
                 "���۱o��֡C�o���o�ܲM�بq�A��������Q�ҧ��Ҫ��e���A��\n"
                 "�b�O�H�����۫H�o�|�O�_��L�񪺤Ѵݨ��Ъ��]�k�C\n",
           );
        set("age",14);
        set("gender","�k��");
        set("evil",-30);
//          set_skill("darkdagger",20);
           set_skill("dagger",20);
           set_skill("dodge",20);
           set_skill("parry",20);
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
           (:command("exert darkdagger"):),
           (:command("say �ݷݱϩR�r�I�I���H�n�����ڡI�I"):),
           (:command("cry"):),
        }) );

        setup();
        carry_object(__DIR__"wp/dagger.c")->wield();
}
