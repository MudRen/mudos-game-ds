#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
          set_name("��ù�~�u" ,({ "a-luo-han boots","boots" }) );
        set("long",@LONG
�o�O�@���W�Y�α��r�g���F����g�媺�u�u�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(850);
                  set("unit", "��");
                set("value",800);
                set("volume",3);
        }
                set("armor_prop/armor", 10);
                set("limit_con",10);
                set("armor_prop/dex", 2);
        setup();
}

