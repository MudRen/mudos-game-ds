#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name("���r���C" ,({ "hao chi sword","sword" }) );
        set("long","�o�O�@�өx�L�`�t�����������C�C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","iron");
        }
        set("unit", "��" );
         set("limit_str",10);
       set("value",1500);
set("volume",2);
//        setup();  �a~~ ���Ƕé�..
//init_sword(25);
	init_sword(25);
	setup();
}
