#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�F�ЩM�|", ({ "end-dust bonze", "bonze" }) );
        set("gender", "�k��");
        set("age",  70);
        set("level", 35);
        set("attitude", "peaceful");
         create_family("����x", 30, "���");
        set("evil",-50);
  set_skill("unarmed", 85);
  set_skill("dodge", 75);
  set_skill("parry", 75);
    set("no_kill",1); // �Ȯɤ����
// �Ȯɤ����
        setup();
  carry_object(__DIR__"eq/bonze_cloth")->wear();
}

