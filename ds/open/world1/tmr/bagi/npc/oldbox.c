#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(YEL"���ª��첰"NOR,({"old box","box"}));
     set_weight(1); 
     set("long",HIC"�@�Ӧ��¤������첰�l�A���L���w�W��A�_�ͤ����D�h���F(toopen)�C\n"NOR);
     set("no_sell",1); 
     set("no_give",1); 
     setup();
}
void init()
{ 
     add_action("do_open","toopen");
}
int do_open(string arg)
{ 
    object me=this_player(),key;    
    if(arg == "box")   
    {    if(!objectp(key=present("wood key",me) ) ) return notify_fail("�A�S���_�ͭn���}�r?\n"); 

      switch(random(3))
      {
       case 0:
              message_vision(YEL"$N�N��s�_�ʹ��J�ꤺ��F�@�U�A���O�]����ӹL���¡A�������_���F�I�H\n"NOR,me);
              destruct(key);
              return 1;
       case 1:
              message_vision(HIY"$N�N��s�_�ʹ��J�ꤺ��F�@�U�A��M�����@�{�I$N�~���t�I�Ⲱ�l���b�F�a�W\n"NOR,me);  
              tell_object(me,"�@�ӭӬ����u�H�����Z�̡A�⤤�����ۤ@����Y�A�ɱ����R�C\n");   
              tell_object(me,"�j�j���g�����O�ﭱ�ӨӡI�����D���������L�ӡI\n"); 
              call_out("do_eee",2,this_object());  
              me->start_busy(8);
              destruct(key); 
              return 1;
      }  
    }
} 

int do_eee(object me, string arg)
{ 
        me=this_player();
        switch(random(3))
        {
                
         case 0:        message_vision("$N���Y��M���F�@�U...\n",me);  
                        destruct(this_object());
                        return 1;
         
         case 1:        message_vision("$N�ĤF�f��A���F���B�Y�����C\n",me);  
                        tell_object(me,HIY"�s�ޯ�Ǳo�y �s�� �z\n"NOR);
                        me->set_skill("lan_pu",1+random(9)); 
                        destruct(this_object());
                        return 1; 
         default:       return 1;
        }
}

