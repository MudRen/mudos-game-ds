#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"�p���F"NOR,({"wind robot","robot"}) );
        set("long",@LONG
���Щǳ̩��ꪺ��U�C
LONG
);
        set("title","�y�U�����h�z");
         set("age",90);
         set("level",55);
         set("gender","����");
         set("max_hp",10000);
         set("hp",10000);
         set("race","robot");
         set("attitude", "aggressive");
         set("chat_chance", 13);
         set("chat_msg",({ 
               (: random_move :),
        "�p���F���|�P���_�F�������s�����H\n",
        "�p���F���Ѩg��~~�C\n",
        "�p���F�w�w���|�_��A���j�����F�@�U�C\n",
        "�p���F���W������C�C�����o�X�ӡC\n",
        }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}

