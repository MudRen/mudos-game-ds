#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("�����p��", ({ "DeadGod","ring" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@���{�{���p�ۧ٫�,�O�Ҧ��֤k�o�ڳ��Q�۪��p��,\n");
                set("unit", "��");
                set("material", "carbon");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",55000);
                set("armor_prop/sou",1);
                set("armor_prop/int",3);
                set("armor_prop/armor", 3);
                set("wear_msg","$N��o$n���W,�y�W�S�X���c�����e!");
                set("remove_msg","$N���U�F$n,�Q��Ӧa�覬��..");
        }
        setup();
}
int query_autoload() { return 1; }
