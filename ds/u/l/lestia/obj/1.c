#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�F��", ({"test"}));
    set("unit", "��");
    set("long",@LONG
    �ΨӪ����@�ӪF��
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_io","io");
    }
int do_io(string arg)
{
        object me = this_player();
         int i;
me->set("env/msg_clone",HIY"$N"HIY"��M�ۦb���䪺�𨤤U�A"NOR""YEL"�����i���˸̡A"HIY"�N$n"HIY"�ԤF�X�ӡC\n"NOR);
me->set("env/msg_mout",HIC"$N"HIC"�C�Y�����A����q���D�G�u"HIR"�ë����r"NOR""RED"��н礩�H�^"HIR"�A���l����"NOR""RED"�ʪ��O�q�a�I�v\n"NOR);        
me->set("env/msg_min",  HIM"�@�Dģ������"NOR""MAG"�~�q�ѤW����"HIM"�ӤU�A$N"HIM"�C�C���q��"NOR""MAG"�������F�X�ӡC\n"NOR);
me->set("env/msg_dest",       HIG"$N"HIG"���d����$n"HIG"�R�F�@�f��A���G$n"NOR""GRN"�Q$N"NOR""GRN"���𵹷��ƤF�C\n"NOR);
       return 1;
}


