#include <ansi.h>

inherit ITEM;
void create()
{
    set_name(HIW"�Ѧa����"NOR,({"sky-ming tree","tree"}));
        set("unit", "��");
        set("long",@LONG
���o�ۯ��t�ե������A�۶Ƿ�~���ФΤѦa�|���e���̫K�O
�b����U���嬰���p���m�~�ġA���^�����X���ɥN�A���A��
�ѱo�߯��Q���A�Q����N(touch)��¤�����H�C
LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        
        if(arg!="sky-ming tree" && arg!="tree" )
        {
                notify_fail("�A�n�N����?\n");
                return 0;
        }

        message_vision(HIW"$N�����N�F$n�@�U�C\n"NOR,me, this_object());
        write(this_object()->name()+""HIC"���G�{�ʤF�@�U�A�H�Y�S�^�_�F�쪬�C\n"NOR);
        return 1;
}
