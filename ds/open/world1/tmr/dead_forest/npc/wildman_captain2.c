#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "���H�j�Y��", ({ "redhair captain","captain","wildman","man"}) );
        set("long",@long
    ���H�j�Y�ت����D�`�����j�A���Y�����v���õL���A���ɦa�����A�o
���ӡA���G�H�ɳ��|�����A�����A�@�L���������I�έD�A�����䥦���v
�ڤH�먺��i���C
long
);
        set_race("human");
        set("title","���v");
        set("age", 42 );
        set_attr( "dex" , 30 );
        set_skill("whip" , 140);                  // �@�k
        set_skill("parry", 100 );
        set_skill("dodge", 100);
        setup();
        set_level(20);
        advance_stat("hp" , 500);
        advance_stat("nina" , 300);
        do_heal();
        carry_object(__DIR__"obj/creeper-whip")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
		carry_object(__DIR__"obj/bone-earring")->wear();
}

void init()
{
    ::init();
/*
    add_action("intercept", "go");
    add_action("intercept2", "north");
*/
}

int intercept(string arg)
{
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    do_chat((: command, "say �A�o�~�H�h�h�h�A���n�ӧڭ̳o��x�ơC":) );
    return 1;
}

int intercept2()
{
    if(!this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    do_chat((: command, "say �A�o�~�H�h�h�h�A���n�ӧڭ̳o��x�ơC":) );
    return 1;
}

