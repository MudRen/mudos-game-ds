#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�ȫ�", ({ "traveller",}));
set("long",
"�o�O�@�Ӧb�Q�U�j�s�C��, �ثe�ݦb���𮧪��ȫ�.\n",
);

        set("level",9);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 33);
        set("evil",-20);
   set("attitude", "peaceful");
  set("chat_chance", 3 );                     
set("chat_msg", 
({
(:command("smile"):),
}) );
      setup();
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/longsword")->wield();
      carry_object(__DIR__"eq/fur_waist")->wear();
      carry_object(__DIR__"eq/cloth")->wear();

}                 

