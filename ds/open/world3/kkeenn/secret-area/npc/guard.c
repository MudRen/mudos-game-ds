#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIW"���ö���"NOR,({"defend guard","guard"}) );
        set("long",@LONG
�a�U�����u�áC
LONG
);
        set("title","�y�����۽ö��z");
         set("age",35);
         set("level",50);
         set("gender","�k��");
         set("race","human");
         set("attitude", "aggressive");
         set("chat_chance", 13);
         set("chat_msg",({ 
               (: random_move :),
        "���ö�����: �����D�������I�I\n",
              }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}

