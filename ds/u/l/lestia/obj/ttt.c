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
me->set("long",
HIC"�~��      �~�w�w�w���~�w�w�w���~�w�w�w���~�w�w�w���~�w�w�w��\n"
NOR""CYN"�x�x      �x�~�w�w���x�~�w�w������  �~������  �~���x�~�w���x\n"
HIC"�x�x      �x���w��  �x���w�w��  �x  �x    �x  �x  �x�x  �x�x\n"
NOR""CYN"�x�x  �~���x�~�w��  ���w�w���x  �x  �x    �x  �x  �x���w���x\n"
HIC"�x���w���x�x���w�w���~�w�w���x  �x  �x  �~��  �����x�~�w���x\n"
NOR""CYN"���w�w�w�����w�w�w�����w�w�w��  ���w��  ���w�w�w������  ����\n"NOR);
       return 1;
}

