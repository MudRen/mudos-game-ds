#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;

void create()
{
        set_name(HIB "�]�P�ۼv��" NOR,({ "devil-armor","armor" }) );
        set("long",
"�o�O�@���z�����ԥҡA�ڻ��O���l�ӥH�e�X�h���ԮɩҬ諸�ԥҡA\n"
"ť�����@�دS�O���\�ΡA���O�@�����O���K�A�èS���h�֤H���D�A\n"
"�b�ԥҪ��|�P�٦��@�������շϡA�����D������ΡC\n"
);
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",1600);
        set("replica_ob",__DIR__"devil-armor2");
        set("armor_prop/armor",10);
        set("armor_prop/dex", -6);
        set("armor_prop/con", -10);
        }
        setup();
}
