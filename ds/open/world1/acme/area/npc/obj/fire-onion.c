#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIG "��a�ٽ�" NOR, ({ "fire-devil onion", "onion", "_FIRE_ONION_" }) );
        set("long", "�o�O�@��q���٩Ǩ��W���o�������A����r�P�A�O�@�د��_���į�C");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "ap" : 1000,
         "hp" : 1000,
         "mp" : 1000,
        ]));
        set("value", 2500);
        setup();
}

