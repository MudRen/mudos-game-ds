#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIY"����"NOR, ({ "ju ball","ball" }));
        set("long",
        "�@���֦��d�~�\\�O�����Y�A�㦳�Q�����_�����ġA�@�M�@���K���A\n"
        "�X�١i�����K���j�C\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�Y�U�@���B�N�N���ĤY�C");
                set("eff_msg",HIG "�A��ı�o���ѧN��C���b�����G�ߤ����A���W���ˤf���G�]���������F�C" NOR );
        }
        set("value", 3000);
        set("heal",([
                "ap": 500,
                "hp": 450,
                "mp": 450,
        ]));
        setup();
}

