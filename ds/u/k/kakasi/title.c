#include <ansi.h>  //�~���C����,�o�ˤ~����C��



inherit ITEM;



void create()

{

        set_name("�ȱi", ({"change title","title"}));

        if( !clonep() ) {

                set("long", "�o�O�@�ӧ�title���F��A�Q��²���A�@�L�S���a��C\n

");

                set("unit", "��");

        }

        setup();

}

void init()

{

        add_action("do_title","title");

}

int do_title(string arg)

{

        object me;



 me=this_player();

 

 me->set("guild_rank",HIC"�e��"HIW"�мv"HIB"�v��"HIC"���e"NOR);



        me=this_player();

        return 1;

}
