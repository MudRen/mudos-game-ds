#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(BLU"�`���"NOR, ({ "ice stone","stone" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�Ӵ��o�۩_�H���p�ۤl\n");
                set("unit", "�u");
        set("value",10000);
        set_weight(600);
         set("material","jade");
         set("armor_prop/int",1);
        }
        set("wear_msg",HIW"$N���M�Q�`��۩�X���H��]��I"NOR);
        set("remove_msg", "$N�`��۪��H�𺥺����h�F...�C");
        setup();
}
