#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("ù�~�@��" ,({ "luo-han wrists","wrists" }) );
        set("long",@LONG
�@���P���n���@��A�W�Y�Τp���g���p�r�A�A�J�Ӫ��ݡA�~�o�{�W
�Y�g���O�@�g�g��A�AŪ��Ū�ۡA�߱����G���R���֤F�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(1000);
                set("material", "linen");
                set("unit", "��");
                set("value",1200);
                set("volume",3);
        }
                set("armor_prop/armor", 10);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
        setup();
}

