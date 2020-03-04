#include <weapon.h>

inherit WHIP;

void update_viper();

void create()
{
      set_name("���ճD",({"viper"}) );
      set("long","�@���ʬ��p�����p�D�C\n");
      set_weight(100);
      if (clonep() )
             set_default_object(__FILE__);
     else {
        set("unit","��");
        set("volume",1);
        set("material","iron");
        }
        init_whip(12);
        setup();
}
void update_viper()
{
   int i,j;
        i=this_object()->query("viper_power");
        j= i / 5;
        set("long","�@���ʬ��p�����p�D�C"+(j==0 ? "\n":"���W��"+(string)j+"�ӵ���Z�I\n" ) );
        return;
}
void init()
{
        add_action("do_name","name");
        add_action("do_feed","feed");
}

int do_feed(string arg)
{
        object ob,me;
        me=this_player();
        ob=this_object();
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S�Ť��C\n");
        if(me->is_fighting() )
                return notify_fail("�A�����ۡA�S�Ť��C\n");

        if(!arg || !ob->id(arg) )
                return notify_fail("�A�n�������D?");
        message_vision("$N���X�F�}�k�Y��$n�r��A�j�j�a�l�F�@�f��C\n",me,ob);
        ob->add("viper_power",1);
        update_viper();
        me->start_busy(1);
        me->receive_damage("hp",10);
        return 1;       
}

