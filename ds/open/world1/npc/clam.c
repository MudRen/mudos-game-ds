#include <ansi.h>
inherit NPC;
void create()
{
      int x;
      x = random(10);
        set_name("�F",({ "clam" }) );
         set("level",20);
        set("race", "���~");
        set("age", 3);
        set("long", "�o�O������ɷ|���쪺����, ���ɸ̭��|���ï]�C\n");
        set("limbs", ({ "��", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
    carry_object(__DIR__"../obj/clam_shell");
     if (x == 1 || x == 2 || x == 3)
	{
      carry_object(__DIR__"../obj/pearl");
	}
    if (x == 5)
	{
    carry_object(__DIR__"../obj/black_pearl");
	}

}