#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIG"�C�D��"NOR, ({ "green snake woman","woman" }) );
        set("level",37);
        set("combat_exp",6520);
set("exp",4411);
        set("evil",200);
        set("long","�L�O�E�ת��Q�����@\n"
                   "���H�E�פw�g�D�`�[�F\n"
                   "��⪺�D�@,�i�q���B�N\n"
                   "�i�H��n���F�讳���F�C\n"
            );
        set("age",32468);
        set("attitude","killer");
        set("gender","�k��");
        set("title",YEL"�Q���� "NOR);
        set_skill("unarmed",80);
        set_skill("dodge",75);
        set_skill("parry",80);
        set_skill("whip",150);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
"�C�D�ϻ�:�ڬ�������..!! ��������... �C\n\n"                    
   }) );
       setup();
       carry_object("/u/t/tako/whip.c")->wield();  
       carry_object("/u/t/tako/surcoat.c")->wear();
}





