/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit BOOTS;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"�}���u"NOR ,({ "po god boots", "boots" }) );
            set("long","�@��Ӧ۰��ɪ����u�A�Ǧ⪺�����t�ơC\n");
            set_weight(5000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+10);
            break;
        case 21..45:
            set_name(HBK"�x�߹u"NOR ,({ "heart boots", "boots" }) );
            set("long","�@�������H�}�����u�C\n");
            set_weight(4000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+8);
            break;
        case 46..70:
            set_name(HBK"�k��u"NOR ,({ "west boots", "boots" }) );
            set("long","�@��Ωǲ�����s����������u�C\n");
            set_weight(1000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+6);
            break;
        default:
            set_name(HBK"�Ի�u"NOR ,({ "ghost boots", "boots" }) );
            set("long","�@��Ӧۧ��ɪ����u�A���G�s�۳\\�h���F�C\n");
            set_weight(2000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+3);
            break;
    }

    switch( random(100) ) {
        case 0..19: set("armor_prop/str",1); break;
        case 20..39: set("armor_prop/con",1); break;
        case 40..59: set("armor_prop/int",1); break;
        case 60..79: set("armor_prop/dex",1); break;
        case 99:
            set("armor_prop/str", 1);
            set("armor_prop/con", 1);
            set("armor_prop/int", 1);
            set("armor_prop/dex", 1);
            break;
    }

    if ( clonep() )
        set_default_object(__FILE__);
    else {
        set("material", "iron");
        set("unit", "��" );
    }

    setup();
}
