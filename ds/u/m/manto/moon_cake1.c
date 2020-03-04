inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL"�Ե���"NOR, ({ "spinage moon cake", "spinage", "cake" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);  
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object env,me;
        string type,msg;
        me = this_player();
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if(this_player()->query_temp("do_eat_strmooncake") )
                return notify_fail("�A�w�g�Y�L�Ե���F�C\n");
        message_vision("$N�j�f�j�f���Y�U�@�ӵԵ���F�C\n",this_player() );
        switch(random(2)){
              case 0: 
              message_vision("$N������n���]���Ե��沣�ͤF�@���ܤ�...\n",this_player() );
              this_player()->add_temp("apply/str",20);
              this_player()->add_temp("do_eat_strmooncake",1);
              call_out("delay",3600,this_player() );
              destruct(this_object());
              break;  
              default: 
              message_vision(HIW"$N�j�f�j�f���Y�U�@�ӵԵ���A��M���n���Y��ԣ�F��...\n"NOR);
               new(__DIR__"ticket")->move(this_player());
              destruct(this_object());
              break;    
        }
return 1;
}

void delay(object me)
{
        if(!me) return;
        tell_object(me,"�Ե���a�Ӫ��ĪG�n���q�A���W�����F�C\n" );
        me->add_temp("apply/str",-20);
       me->delete_temp("do_eat_strmooncake");
        destruct(this_object() );
}
