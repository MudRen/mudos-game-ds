#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�վB���������u��", ({ "gate guard of ugelan","guard" }) );
        set("long","���۵�����A�A���𪺯��b�D����Ǧu�õ۪��վB���u�áA���L�A
��@�ǥ��ƪZ�˪��������ȸT�íx��_�ӡA�L�Pı�W�O�i�ܥΪ�...\n");
        set("level",18+random(5));
        set("age",20+random(3));

        set("combat_exp", 30000);
        set("chat_chance", 7);
        set("chat_msg", ({
  "�u�ìn���Y, �W�U���q�F�A�@���C\n",
}));
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
  HIW"�u�äj�ۡGDIE!!Scum!!\n"NOR,
  HIW"�u�äj�ۡGYou are not welcome in ugelan.\n"NOR
}));
        set_skill("sword", 50);
        set_skill("parry", 20);
        set_skill("unarmed", 50);
        set_skill("dodge", 55);
        setup();
        carry_object(__DIR__"wp/silverlsword")->wield();
        carry_object(__DIR__"eq/gcap")->wear();
        carry_object(__DIR__"eq/gpant")->wear();
        carry_object(__DIR__"eq/guniform")->wear();
        carry_object(__DIR__"eq/ridingboots")->wear();
        carry_object(__DIR__"eq/waist")->wear();
}


