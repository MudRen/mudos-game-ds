#include <ansi.h>
inherit NPC;
void create()
{
        set_name( MAG"�չC�k"HIW"�H"NOR, ({ "trip girl ","girl" }) );
        set("level",40);
        set("combat_exp",6000);
        set("exp",3124);
        set("evil",200);
        set("long","�L�O�E�ת��Q�����@\n"
                   "���H�E�פw�g�D�`�[�F\n"
                   "�����ƯB���w,�O���⪺�p��C\n"
            );
        set("age",16081);
        set("attitude","killer");
        set("gender","�k��");
        set("title",YEL"�Q���� "NOR);
        set_skill("unarmed",100);
        set_skill("dodge",160);
        set_skill("parry",80);
        set_skill("combat",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
(:command("help!"):),
(:command("hehe"):), 
  }) );
       setup();
       carry_object("/u/t/tako/cloth.c")->wear();
}




