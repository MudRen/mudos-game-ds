#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
        set_name(HIY"��"HIG"��"HIW"��"HIR"��"NOR, ({"king mask" ,"mask" }));
        set_weight(500);
        set("long", @long
�o�i���㴲�o�X�@�Ѥ��̪��O�q,���A���T���o�X�@�}Ÿ��,�־֦��F�o�i����,�L�ê��L�@�w�i
�H�W�B����.
long);
        set("unit", "�i");
        set("value", 0);
        set("armor_prop/armor", 50);
        set("armor_prop/con", 10);
        set("armor_prop/str", 10);
        set("armor_prop/int", 10);
        set("armor_prop/dex", 10);
        set("armor_type", "mask");
        set("wear_msg",
HIW"$N���W$n"HIC"���ᴲ�o�X"HIY"���̭��d"HIR"�A�|�P���Ů��ܪ��Y��\n"NOR);
        set("unequip_msg", HIC"$N���U$n"HIC"��A�|�P���Ů��_�C\n"NOR);
       
setup();
}
int query_autoload() { return 1; }

