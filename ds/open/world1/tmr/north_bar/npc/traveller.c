#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ȤH",({ "traveller" }) );
        set("long","�o�O�@��q�~�a�Ӫ��ȤH�A���й������A�����ٺ��������A���ȭ��H�C\n");
        set("race","�H��");
        set("age", 30);
        set("level",10);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
                (:command("stare"):),
                (:command("sweat"):),
        }) );
        setup();
        carry_object("/open/world1/obj/ts_bag");
}

