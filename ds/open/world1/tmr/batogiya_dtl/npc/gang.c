#include <npc.h>

inherit F_FIGHTER;

void create()
{
        set_name("���ԭ�", ({ "ha la gang", "gang" }) );
        set("long", "���������Z�h���@�A�j�a���٥L���u�����v�A���G�ܼF�`���ˤl�C\n");
        set_race("human");
        set("age", 24);

        set_attr("str",25);

        setup();

        advance_stat("gin",100);
        advance_stat("hp",100);

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/sword")->wield();

        carry_money("gold", 1);
        set_level(15);
}
