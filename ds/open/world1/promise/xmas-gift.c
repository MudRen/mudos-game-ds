#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�t��"HIM"�p§��"NOR, ({ "xmas present","present" }));
        if( clonep() )
                set_default_object(__FILE__);
        else
                set("long","�t�ϸ`§���A���饴�}�Ӭݬ�(open)�C\n");
        
        set("no_auc",1);
        set("no_put",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        setup();
}

void init()
{
  add_action("do_open","open");
}
int do_open(string str,object obj,object me)
{
        int i;
        
        obj = this_object();
        me = this_player();
                
        if(!str || str != "present" || me->query("xmas-gift2")) return 0;
                i = random(1000);
        switch(i)
        {
                case 0..500:
                        me->add("exp", 1000000); 
                        message_vision(HIG"$N���}�F"HIR"�t�Ϥp§��"HIG"��A�t�ϦѤ������A�g��Ȥ@�ʸU�����y�I\n"NOR,me,obj); 
                        me->set("xmas-gift2",1);
                        break;
                case 501..980:
                        me->add("popularity", 200);
                        message_vision(HIG"$N���}�F"HIR"�t��§��"HIG"����A�t�ϦѤ������A�n�����I�����y�I\n"NOR,me,obj);
                        me->query("xmas-gift2",1);
                        break;
                case 981..999:
                        new(__DIR__"red_sock")->move(me);
                        message_vision(HIG"$N���}�F"HIR"�t��§��"HIG"����A�o��W�Ťj���u�t�Ϫw�w���v��@���y�I\n"NOR,me,obj);
                        me->query("xmas-gift2",1);
                        break;
           
            }
  destruct(obj);
  return 1;
}

