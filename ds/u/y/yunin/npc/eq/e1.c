#include <ansi.h>

#include <armor.h>

inherit SHIELD;



void create()

{

        set_name(HIC"�B�Ѭ�"NOR,({"ice of sky","ice"}) );

        set("long",@LONG

��T�l��ʦ~�׬��гy�X�Ӫ��޵P�C

LONG

);

        set_weight(2000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("limit_str",21);

                set("unit", "��");

                set("value",5000);

                set("volume", 4);

                set("material", "cold");

        }

        set("armor_prop/armor",25);



 set("armor_prop/shield",17);

        setup();

}
