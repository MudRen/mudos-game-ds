/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit SHIELD;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"�}����"NOR ,({ "po god shield", "shield" }) );
            set("long","�@��Ӧ۰��ɪ��ޡA�Ǧ⪺�����t�ơC\n");
            set_weight(9000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+15);
            break;
        case 21..45:
            set_name(HBK"�x�߬�"NOR ,({ "heart shield", "shield" }) );
            set("long","�@��������x���ޡC\n");
            set_weight(8000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+10);
            break;
        case 46..70:
            set_name(HBK"�k���"NOR ,({ "west shield", "shield" }) );
            set("long","�@��Ωǲ�����s��������ޡC\n");
            set_weight(4000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+5);
            break;
        default:
            set_name(HBK"�Ի��"NOR ,({ "ghost shield", "shield" }) );
            set("long","�@��Ӧۧ��ɪ��ޡA���G�s�۳\\�h���F�C\n");
            set_weight(6000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+5);
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
