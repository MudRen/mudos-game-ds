#include <ansi.h>
 
inherit EQUIP;
 
void create()
 
{
 
        seteuid(getuid());
 
        set_name("�m��Y�l",({"pill"}));
 
        set("long","�m��p�Y�l\n");

        set("unit","��");

        setup();

}



void init()

{

        add_action("change","change");

}



int change(float value)

{

        object ob;

        int damage;

        ob = this_player();

this_player()-> set("name",HIM"���"HIC"�B�N�O"NOR);  return 1;

}

