#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("��ù�~�T" ,({ "a-luo-han cloth","cloth" }) );
        set("long",@LONG
�o�O�@����������T�A�W�Y�α��r�g���F����g��A���G����
���h�]���\��C��b���W���Pı���G�]�������K�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(850);
                set("unit", "��");
                set("value",800);
                set("volume",3);
        }
        setup();
                set("armor_prop/armor", 10);
}

