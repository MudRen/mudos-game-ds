#include <armor.h>
#include <ansi.h>

inherit F_ARMOR;

void create()
{
        set_name(HIW "�������Z" NOR, ({ "gold-snow armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 15000);
                set("long",@long
    �o�O�@��Q�����Ū����Z�A�Ѹ̨�~�A�������O�ѯª����y�A�A�V�X
�¥ջ��л\�䤤�A��´���K���z���������m���Z�C
long
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor":30,
                        "con": 1,
                        "str": 1,
                ]));
        }
        setup();
}
