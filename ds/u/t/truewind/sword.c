#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( WHT"�Y�s�C"NOR, ({ "dragon sword","sword" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�C�������B�{�X�@���s���v���A��Ţ�n�ۤ@�h����������...�C");
                set("unit", "��");
                set("value",1);
        }
        set("weaopn_prop/hit", 10 );
        set("wield_msg","$N�ۧC���l�A�y��@�X�A�ޥX�C�T����$n�C\n");
        set("weaopn_prop/dex", 1 );
        init_sword(60);
        setup();
}
int query_autoload() { return 1; }


