#include <ansi.h>
#include <npc.h>

void create()
{
        set_name(HIY"�۫Ǧu�@��"NOR , ({ "gold guard monster","monster" }) );
        set("long",@long
    �۫Ǧu�@�̬��w�����������j�j�����~�A����´�D�`�����ߡA�z�i
�H���Y�樣�e�b�H���y���A�W�Y���w�۴c�䪺�y�C�A�`��⪺���y�n����
�����۱z�C
long
);
        set("title","�w����");
        set_race("strength");
        set("age", 80);
        set_skill("parry",120);
        set_skill("dodge",120);
        set_skill("unarmed",150);
        set_skill("psychical",100);
        set_skill("twohanded blunt",150);
        set("attitude", "aggressive");
        set("froce_ratio",10);        
        set("bounty",([
                  "reputation": 15, 
        ]) );
        
	set_temp("apply/armor" , 40 );
        setup();
        set_level(30);
        set_attr("strength",100);
        carry_money("gold", 2);
        carry_object(__DIR__"obj/boots")->wear();
        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/ring")->wear();
        carry_object("/d/obj/big-blunt.c")->wield();
}

void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}
int intercept(string arg)
{
        
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�@���x��A�פF�U�ӡC\n");
    return 1;
}

int intercept2()
{
        
    if( !this_player()->visible(this_object()) ) return 0;
    write( name() + "�@���x��A�פF�U�ӡC\n");
    return 1;
}

