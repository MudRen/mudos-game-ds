#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�u���u��", ({ "gate guard","guard" }) );
        set("long","�@�ӥ��`�b�j�������ˬd�q�U�a�ӨӪ��H���W�O�_�a���M�I���㪺�H�C\n");
        set("level",1);
        set("age",40+random(3));

        set("combat_exp", 1);
        set("chat_chance", 4);
        set("chat_msg", ({
  "�u�û��G�S�ƪ��N�֧֨��C\n",
}));
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
  HIW"�u�û��G�ϤF�ϤF�A���ѤƤ餧�U�����s�����[\n"NOR,
  "�u�û��G�S�̡̭A��L���F\n"NOR
}));
        set_skill("sword", 1);
        set_skill("parry", 1);
        set_skill("unarmed", 1);
        set_skill("dodge", 1);
        setup();
        carry_object("/u/l/lary/weapon/sword")->wield();
        }

