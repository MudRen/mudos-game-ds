/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit HEAD;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"�}���Y��"NOR ,({ "po god helmet", "helmet" }) );
            set("long","�@��Ӧ۰��ɪ��Y���A�Ǧ⪺�����t�ơC\n");
            set_weight(6000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+8);
            break;
        case 21..45:
            set_name(HBK"�x���Y��"NOR ,({ "heart helmet", "helmet" }) );
            set("long","�@��������Y�����Y���C\n");
            set_weight(5000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+6);
            break;
        case 46..70:
            set_name(HBK"�k���Y��"NOR ,({ "west helmet", "helmet" }) );
            set("long","�@��Ωǲ�����s���������Y���C\n");
            set_weight(2000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+4);
            break;
        default:
            set_name(HBK"�Ի��Y��"NOR ,({ "ghost helmet", "helmet" }) );
            set("long","�@��Ӧۧ��ɪ��Y���A���G�s�۳\\�h���F�C\n");
            set_weight(3000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+2);
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
