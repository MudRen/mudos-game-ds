#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIC"�i"HIW"�����K����"HIC"�j"NOR, ({ "love god pill","pill" }));
        set("long",
        "�������������˦��_�A�O�ѱ������K��P�l�⤤���K�������A�Q��\n"
        "�öQ�A�����ĥi�H��_�����Ӫ����p�C\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�Y�U�@������|�����ĤY�C");
                set("eff_msg",HIG "�A��ı�o���ѷx��C��������޹D�����A���骺���p�]�_��F�C" NOR );
        }
        set("value", 10000);
        set("heal",([
                "ap": 2000,
                "hp": 2000,
                "mp": 2000,
        ]));
        set("cure",([
                "head": 100,
                "left_arm": 100,
                "right_hand": 100,
                "left_leg": 100,
                "right_arm": 100,
                "body": 100,
        ]));
        setup();
}
