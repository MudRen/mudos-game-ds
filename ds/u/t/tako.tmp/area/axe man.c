#include <ansi.h>
inherit NPC;
void create()
{
        set_name( MAG"���]"HIW"�H"NOR, ({ "big-devil man ","man" }) );
        set("level",35);
        set("combat_exp",5000);
        set("exp",2000);
        set("evil",200);
        set("long","�L�O�E�ת��Q�����@\n"
                   "���H�E�פw�g�D�`�[�F\n"
                   "��������H��,�¤O��H�C\n"
            );
        set("age",13098);
        set("attitude","killer");
        set("gender","�k��");
        set("title",YEL"�Q���� "NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("axe",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
(:command("hehe"):),
(:command("grin"):),   }) );
       setup();
       carry_object("/u/t/tako/axe.c")->wield();
}



