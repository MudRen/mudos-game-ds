
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL"���֤��׺�"NOR, ({ "str zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);  
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;
        if( !this_object() ) return 0;
        if(! env = environment(this_object())) return 0;
        if( this_player()->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if(this_player()->query("eat_strzong") )
                return notify_fail("�A�w�g�Y�L���֤��׺�F�C\n");

        message_vision("$N�j�f�j�f���Y�U�@�����֤��׺�C\n",this_player() );
        switch(random(2)){
             case 0:        
              message_vision("$N������n���]�����֤��׺겣�ͤF�@���ܤ�...\n",this_player() );
              this_player()->add_temp("apply/str",5);
              this_player()->add_temp("eat_strzong",1);
              call_out("delay",1800,this_player() );     
              break;       
              default: 
              message_vision("$N�j�f�j�f���Y�U�@�����֤��׺�A��M���n���Qԣ�F��O��...\n",this_player() );    
               new(__DIR__"ticket")->move(this_player());
              destruct(this_object());
              break;
}

return 1;
}

void delay(object me)
{
        if(!me) return;
        tell_object(me,"���֤��׺�a�Ӫ��ĪG�n���q�A���W�����F�C\n" );
        me->add_temp("apply/str",-5);
        me->delete_temp("eat_strzong");
        destruct(this_object() );
}
