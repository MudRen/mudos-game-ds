#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�s�G" , ({ "gwong leung bonze","gwong","bonze" }) );
        set("level",30);
         set("title","�ⶳ�x �ʦx");
        set("race","�H��");
        set("gender","�k��");
        set("age",50);
        set_skill("wuchen-staff",80);
        set_spell("recite-sutra",80);
        set("long","�L�O�ⶳ�x���ʦx�A�y�ͪ��եժΪΪ��A���o�Q���Mħ�C\n");
        set("chat_chance", 3 );
        set("chat_msg",({
          (: random_move :),
                (:command("exert wuchen-staff"):),
        }) );
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (:command("cast recite-sutra"):),
        }) );
        setup();
          carry_object(__DIR__"wp/staff3")->wield();
}
