#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"�ڬO����"NOR, ({ "super bonze","bonze" }) );
        set("level",30);
        set("race","�H��");
        set("gender","�k��");
        set("age",15);
        set("title",HIY"�s�ڰ���"NOR);
        set("long","�L�O�ۺٰ��⪺����\n");
        set("chat_chance", 3 );

        setup();
carry_object("open/world1/acme/bonze/npc/wp/staff2")->wield();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

        if( (arg!= "enter") || !this_player()->visible(this_object()) ) retur
n 0;
        write( name() + "�N�A�ɤF�U�ӡC\n");

           say("�ڬO���⻡�G"HIC"�o�O�ⶳ�T�a�ֵ��ںu\n"NOR);
        return 1;
}
