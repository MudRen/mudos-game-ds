#include <ansi.h>
inherit NPC;
void create()
{
        set_name("了塵和尚", ({ "end-dust bonze", "bonze" }) );
        set("gender", "男性");
        set("age",  70);
        set("level", 35);
        set("attitude", "peaceful");
         create_family("普渡寺", 30, "住持");
        set("evil",-50);
  set_skill("unarmed", 85);
  set_skill("dodge", 75);
  set_skill("parry", 75);
    set("no_kill",1); // 暫時不能殺
// 暫時不能殺
        setup();
  carry_object(__DIR__"eq/bonze_cloth")->wear();
}

