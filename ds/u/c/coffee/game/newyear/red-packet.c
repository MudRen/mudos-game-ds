#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"���]"NOR, ({ "red packet","packet" }));
        if( clonep() )
                set_default_object(__FILE__);
        else

                set("long","�ݰ_�ӫܤj�]�����]�A�֥��}(open)�ݬݧa�I\n");
        
        set("no_auc",1);
        set("no_put",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("unit", "��");
        setup();
}

void init()
{
  add_action("do_open","open");
}

int do_open(string str)
{
        int amount;
        object obj,me;        
        obj = this_object();
        me = this_player();
                
        if(!str || str != "packet")
           return notify_fail("�A�n�}����H\n");
        if(me->query("red-packet2"))
           return notify_fail("�A���w�g�}�L�F�@...\n");

        switch(random(1000))
        {
                case 0..400:
                        new(__DIR__"cookie")->move(me);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A�̭����M�O�@���j��I\n"NOR,me,obj); 
                        break;
                case 401..700:
                        amount = random(50000)+1;
                        me->add("bank/past", amount);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A�̭��~�M�� "+amount+" �������I\n"NOR,me,obj);
                        break;
                case 701..850:
                        amount = random(100000)+1;
                        me->add("exp", random(100000)+1);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A���G��o "+amount+" �I�g��ȡI\n"NOR,me,obj);
                        break;
                case 851..990:
                        amount = random(20)+1;
                        me->add("popularity", amount);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A���G��o "+amount+" �I�n��I\n"NOR,me,obj);
                        break;
                case 991..999:
                        new(__DIR__"light-hands")->move(me);//�ȥ��@�N
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"�ɡA���~�|�g�I"HIY"���ߡI"HIC"�̭��O SAVE EQ �I\n"NOR,me,obj);
                        break;
           
            }
  destruct(obj);
  return 1;
}


